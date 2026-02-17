---
title: "Trie 树代码实现"
source: "https://labuladong.online/zh/algo/data-structure/trie-implement/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文结合算法可视化面板讲解 Trie/字典树/前缀树代码实现，运用多叉树结构实现基本的增删查改和前缀搜索，并给出 Java/Python/Go/JavaScript/C++ 代码实现。"
tags:
  - "clippings"
---
关于 Trie 树的原理，请参见基础知识章节的 [Trie 树原理](https://labuladong.online/zh/algo/data-structure-basic/trie-map-basic/) ，本文将直接给出 Trie 树的代码实现。

## TrieMap API 及实现

首先，我们看一下本文实现的 `TrieMap` 的 API，为了举例 API 的功能，假设 TrieMap 中已经存储了如下键值对：

![](https://labuladong.online/images/algo/trie/9.jpeg)

至于 `TrieSet` 的 API 大同小异，所以这里不重复列举，后文直接给出实现。

**接下来是重头戏，我们一个一个实现 `TrieMap` 的上述 API 函数** 。

首先， `TrieMap` 类中一定需要记录 Trie 的根节点 `root` ，以及 Trie 树中的所有节点数量用于实现 `size()` 方法：

另外，我们再实现一个工具函数 `getNode` ：

![](https://labuladong.online/images/algo/trie/11.jpeg)

有了这个 `getNode` 函数，就能实现 `containsKey` 方法和 `get` 方法了：

**这里需要注意，就算 `getNode(key)` 的返回值 `x` 非空，也只能说字符串 `key` 是一个「前缀」；除非 `x.val` 同时非空，才能判断键 `key` 存在** 。

不过，这个特性恰好能够帮我们实现 `hasKeyWithPrefix` 方法：

类似 `getNode` 方法的逻辑，我们可以实现 `shortestPrefixOf` 方法，只要在第一次遇到存有 `val` 的节点的时候返回就行了：

**这里需要注意的是 for 循环结束之后我们还需要额外检查一下** 。

因为之前说了 Trie 树中「树枝」存储字符串，「节点」存储字符串对应的值，for 循环相当于只遍历了「树枝」，但漏掉了最后一个「节点」，即 `query` 本身就是 `TrieMap` 中的一个键的情况。

如果你理解了 `shortestPrefixOf` 的实现，那么 `longestPrefixOf` 也是非常类似的：

每次遇到 `p.val` 非空的时候说明找到一个键，但是我们不急着返回，而是更新 `max_len` 变量，记录最长前缀的长度。

同样的，在 for 循环结束时还是要特殊判断一下，处理 `query` 本身就是键的情况。

接下来，我们来实现 `keysWithPrefix` 方法，得到所有前缀为 `prefix` 的键。

看过前文 [手把手刷二叉树（总结篇）](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 的读者应该可以想到，先利用 `getNode` 函数在 Trie 树中找到 `prefix` 对应的节点 `x` ，然施展多叉树的遍历算法，遍历以 `x` 为根的这棵 Trie 树，找到所有键值对：

![](https://labuladong.online/images/algo/trie/12.jpeg)

代码实现如下：

这段代码中 `traverse` 函数你可能看起来特别熟悉，就是 [回溯算法核心套路](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) 中讲的回溯算法代码框架。

我在 [关于回溯算法和 DFS 算法的若干问题](https://labuladong.online/zh/algo/essential-technique/backtrack-vs-dfs/) 中探讨过回溯算法框架和 DFS 算法框架的区别，关键在于遍历「节点」和遍历「树枝」的区别。由于 Trie 树将字符存储在「树枝」上， `traverse` 函数是在遍历树枝上的字符，所以采用的是回溯算法框架。

另外，再注意一下这段逻辑：

回顾一下我们 Trie 树的图：

![](https://labuladong.online/images/algo/trie/9.jpeg)

你是否会有疑问：代码中 for 循环会执行 256 次，但是图中的一个节点只有几个子节点，也就是说每个节点的 `children` 数组中大部分都是空指针，这不会有问题吗？

是不是应该把代码改成这样：

答案是，改不改都行，这两种写法从逻辑上讲完全相同，因为 `traverse` 函数开始的时候如果发现 `node == null` 也会直接返回。

我为了保持框架的一致性，就没有在 for 循环中判断子节点是否为空，而是依赖递归函数的 base case。当然你完全可以按照自己的喜好来实现。

下面来实现 `keysWithPattern` 方法，使用通配符来匹配多个键，其关键就在于通配符 `.` 可以匹配所有字符。

在代码实现上，用 `path` 变量记录匹配键的路径，遇到通配符时使用类似回溯算法的框架就行了：

下面这个 GIF 画了匹配 `"t.a."` 的过程，应该就容易理解上述代码的逻辑了：

![](https://labuladong.online/images/algo/trie/1.gif)

可以看到， `keysWithPattern` 和 `keysWithPrefix` 的实现是有些类似的，而且这两个函数还有一个潜在的特性： **它们返回的结果列表一定是符合「字典序」的** 。

原因应该不难理解，每一个节点的 `children` 数组都是从左到右进行遍历，即按照 ASCII 码从小到大的顺序递归遍历，得到的结果自然是符合字典序的。

好，现在我们实现了 `keysWithPattern` 方法得到模式串匹配的所有键，那你是否可以实现 `hasKeyWithPattern` 方法，仅仅判断是否存在键匹配模式串？

这是一个偷懒的实现，因为它的复杂度比较高。我们的目的仅仅是判断是否存在匹配模式串的键，你却把所有匹配的键都算出来了，这显然是没有必要的。

我们只需稍微改写一下 `keysWithPattern` 方法就可以高效实现 `hasKeyWithPattern` 方法：

有之前的铺垫，这个实现应该是不难理解的，类似于 [回溯算法解数独游戏](https://labuladong.online/zh/algo/practice-in-action/sudoku-nqueue/) 中找到一个可行解就提前结束递归的做法。

到这里， `TrieMap` 的所有和前缀相关的方法都实现完了，还剩下 `put` 和 `remove` 这两个基本方法了，其实它们的难度不大，就是递归修改数据结构的那一套，如果不熟悉的话可以参见 [二叉搜索树基本操作](https://labuladong.online/zh/algo/data-structure/bst-part2/) 。

先说 `put` 方法的实现吧，直接看代码：

因为是递归修改数据结构，所以我们必须额外创建一个返回类型为 `TrieNode` 的辅助函数，并且在递归调用的时候接收其返回值，拼接到父节点上。

**前文说了，Trie 树中的键就是「树枝」，值就是「节点」，所以插入的逻辑就是沿路新建「树枝」，把 `key` 的整条「树枝」构建出来之后，在树枝末端的「节点」中存储 `val`** ：

![](https://labuladong.online/images/algo/trie/2.gif)

最后，我们说一下 `remove` 函数，似乎所有数据结构的删除操作相对其他操作都会更复杂一些。

比如说下图这个场景，如果你想删除键 `"team"` ，那么需要删掉 `"eam"` 这条树枝才是符合逻辑的：

![](https://labuladong.online/images/algo/trie/13.jpeg)

删多了肯定不行，但删少了也不行，否则前文实现的 `hasKeyWithPrefix` 就会出错。

那么如何控制算法来正确地进行删除呢？

首先，递归修改数据结构的时候，如果一个节点想删掉自己，直接返回空指针就行了。

**其次，一个节点如何知道自己是否需要被删除呢？主要看自己的 `val` 字段是否为空以及自己的 `children` 数组是否全都是空指针** 。

这里就要利用前文 [手把手刷二叉树（总结篇）](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 中说到的后序位置的特点了：

一个节点要先递归处理子树，然后在后序位置检查自己的 `val` 字段和 `children` 列表，判断自己是否需要被删除。

如果自己的 `val` 字段为空，说明自己没有存储值，如果同时自己的 `children` 数组全是空指针，说明自己下面也没有接树枝，即不是任何一个键的前缀。这种情况下这个节点就没有存在的意义了，应该删掉自己。

直接看代码：

到这里， `TrieMap` 的所有 API 就实现完了，完整代码如下：

## TrieSet 的实现

接下来我们只要对 `TrieMap` 做简单的封装，即可实现 `TrieSet` ：

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表