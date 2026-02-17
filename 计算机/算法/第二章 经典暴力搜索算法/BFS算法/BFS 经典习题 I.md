---
title: BFS 经典习题 I
source: https://labuladong.online/zh/algo/problem-set/bfs/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上所有 BFS（广度优先搜索）算法的经典习题（第一部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
## 从树结构的层序遍历开始

### 919\. 完全二叉树插入器

**919\. 完全二叉树插入器** | [力扣](https://leetcode.cn/problems/complete-binary-tree-inserter/) | [LeetCode](https://leetcode.com/problems/complete-binary-tree-inserter/)

**完全二叉树** 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。

设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。

实现 `CBTInserter` 类:

- `CBTInserter(TreeNode root)` 使用头节点为 `root` 的给定树初始化该数据结构；
- `CBTInserter.insert(int v)` 向树中插入一个值为 `Node.val == val` 的新节点  `TreeNode` 。使树保持完全二叉树的状态， **并返回插入节点** `TreeNode` **的父节点的值** ；
- `CBTInserter.get_root()` 将返回树的头节点。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/08/03/lc-treeinsert.jpg)

```
输入
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
输出
[null, 1, 2, [1, 2, 3, 4]]

解释
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // 返回 1
cBTInserter.insert(4);  // 返回 2
cBTInserter.get_root(); // 返回 [1, 2, 3, 4]
```

**提示：**

- 树中节点数量范围为 `[1, 1000]`
- `0 <= Node.val <= 5000`
- `root` 是完全二叉树
- `0 <= val <= 5000`
- 每个测试用例最多调用 `insert`  和  `get_root`  操作  `10<sup>4</sup>` 次

题目来源： [力扣 919. 完全二叉树插入器](https://leetcode.cn/problems/complete-binary-tree-inserter/) 。

#### 基本思路

这道题考察二叉树的层序遍历，你需要先做 [102\. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/) 再做这道题，用队列维护底部可以进行插入的节点即可。

#### 解法代码

#### 算法可视化

算法可视化

给定一个二叉树：

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 `NULL` 。

初始状态下，所有 next 指针都被设置为 `NULL` 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2019/02/15/117_sample.png)
```
输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。
```

**示例 2：**

```
输入：root = []
输出：[]
```

**提示：**

- 树中的节点数在范围 `[0, 6000]` 内
- `-100 <= Node.val <= 100`

**进阶：**

- 你只能使用常量级额外空间。
- 使用递归解题也符合要求，本题中递归程序的隐式栈空间不计入额外空间复杂度。

题目来源： [力扣 117. 填充每个节点的下一个右侧节点指针 II](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/) 。

#### 基本思路

前文 [我的算法学习经验](https://labuladong.online/zh/algo/essential-technique/algorithm-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式。

但这题和 [116\. 填充每个节点的下一个右侧节点指针](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/description/) 还不一样，输入的不是完全二叉树，所以不好直接用递归。

这题用 [BFS 算法](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 进行层序遍历比较直观，在 for 循环，无非就是想办法遍历所有节点，然后把这个节点和相邻节点连起来罢了。

当然，还有效率更高的方式，就是直接操作指针，不过略有些难懂，暂时不写。

#### 解法代码

#### 算法可视化

### 662\. 二叉树最大宽度

**662\. 二叉树最大宽度** | [力扣](https://leetcode.cn/problems/maximum-width-of-binary-tree/) | [LeetCode](https://leetcode.com/problems/maximum-width-of-binary-tree/)

给你一棵二叉树的根节点 `root` ，返回树的 **最大宽度** 。

树的 **最大宽度** 是所有层中最大的 **宽度** 。

每一层的 **宽度** 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的 `null` 节点，这些 `null` 节点也计入长度。

题目数据保证答案将会在 **32 位** 带符号整数范围内。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/05/03/width1-tree.jpg)
```
输入：root = [1,3,2,5,3,null,9]
输出：4
解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2022/03/14/maximum-width-of-binary-tree-v3.jpg)
```
输入：root = [1,3,2,5,null,null,9,6,null,7]
输出：7
解释：最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。
```

**示例 3：**

![](https://labuladong.online/images/lc/uploads/2021/05/03/width3-tree.jpg)
```
输入：root = [1,3,2,5]
输出：2
解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
```

**提示：**

- 树中节点的数目范围是 `[1, 3000]`
- `-100 <= Node.val <= 100`

题目来源： [力扣 662. 二叉树最大宽度](https://leetcode.cn/problems/maximum-width-of-binary-tree/) 。

#### 基本思路

**这道题的解题关键是要给二叉树节点按行进行编号** ，然后你就可以通过每一行的最左侧节点和最右侧节点的编号推算出这一行的宽度，进而算出最大宽度：

![](https://labuladong.online/images/algo/brief-extra/662.png)

而且，这样编号还可以通过父节点的编号计算得出左右子节点的编号：

假设父节点的编号是 `x` ，左子节点就是 `2 * x` ，右子节点就是 `2 * x + 1` 。

这个特性常见于完全二叉树的题目当中，你可以去看看前文 [图文详解二叉堆，实现优先级队列](https://labuladong.online/zh/algo/data-structure-basic/binary-heap-basic/) 或者去做一下 [1104\. 二叉树寻路](https://leetcode.cn/problems/path-in-zigzag-labelled-binary-tree/description/) 这道题。

明白了这个关键点，就可以通过 BFS 或者 DFS 实现解法了，我把两种解法都写出来供你参考。

其中 DFS 的递归解法需要你透彻理解二叉树的遍历顺序，你可以先做一下 [199\. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/description/) 这道题。

#### 解法代码

#### 算法可视化

算法可视化

### 863\. 二叉树中所有距离为 K 的结点

**863\. 二叉树中所有距离为 K 的结点** | [力扣](https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/) | [LeetCode](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

给定一个二叉树（具有根结点 `root` ）， 一个目标结点  `target`  ，和一个整数值 `k`  ，返回到目标结点 `target` 距离为 `k` 的所有结点的值的数组。

答案可以以 **任何顺序** 返回。

**示例 1：**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
输出：[7,4,1]
解释：所求结点为与目标结点（值为 5）距离为 2 的结点，值分别为 7，4，以及 1
```

**示例 2:**

```
输入: root = [1], target = 1, k = 3
输出: []
```

**提示:**

- 节点数在 `[1, 500]` 范围内
- `0 <= Node.val <= 500`
- `Node.val` 中所有值 **不同**
- 目标结点 `target` 是树上的结点。
- `0 <= k <= 1000`

题目来源： [力扣 863. 二叉树中所有距离为 K 的结点](https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/) 。

#### 基本思路

这道题常规的解法就是把二叉树变成一幅「图」，然后在图中用 BFS 算法求距离 `target` 节点 `k` 步的所有节点。

关于 BFS 算法的原理，见 [BFS 算法核心框架套路](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 。

#### 解法代码

#### 算法可视化

算法可视化

### 310\. 最小高度树

**310\. 最小高度树** | [力扣](https://leetcode.cn/problems/minimum-height-trees/) | [LeetCode](https://leetcode.com/problems/minimum-height-trees/)

树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，任何一个没有简单环路的连通图都是一棵树。

给你一棵包含 `n`  个节点的树，标记为  `0`  到  `n - 1` 。给定数字  `n`  和一个有 `n - 1` 条无向边的 `edges`  列表（每一个边都是一对标签），其中 `edges[i] = [a<sub>i</sub>, b<sub>i</sub>]` 表示树中节点 `a<sub>i</sub>` 和 `b<sub>i</sub>` 之间存在一条无向边。

可选择树中任何一个节点作为根。当选择节点 `x` 作为根节点时，设结果树的高度为 `h` 。在所有可能的树中，具有最小高度的树（即， `min(h)` ）被称为 **最小高度树** 。

请你找到所有的 **最小高度树** 并按 **任意顺序** 返回它们的根节点标签列表。

树的 **高度** 是指根节点和叶子节点之间最长向下路径上边的数量。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/09/01/e1.jpg)
```
输入：n = 4, edges = [[1,0],[1,2],[1,3]]
输出：[1]
解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/09/01/e2.jpg)
```
输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
输出：[3,4]
```

**提示：**

- `1 <= n <= 2 * 10<sup>4</sup>`
- `edges.length == n - 1`
- `0 <= a<sub>i</sub>, b<sub>i</sub> < n`
- `a<sub>i</sub> != b<sub>i</sub>`
- 所有 `(a<sub>i</sub>, b<sub>i</sub>)` 互不相同
- 给定的输入 **保证** 是一棵树，并且 **不会有重复的边**

题目来源： [力扣 310. 最小高度树](https://leetcode.cn/problems/minimum-height-trees/) 。

#### 基本思路

我认为这道题非常有意思。首先这题肯定要用到 [图论算法基础](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) 中讲的图的编程表示（邻接表/邻接矩阵），感觉和 [拓扑排序算法](https://labuladong.online/zh/algo/data-structure/topological-sort/) 和 [Kruskal 最小生成树算法](https://labuladong.online/zh/algo/data-structure/kruskal/) 又有点关系。

实际上这道题用标准的 [BFS 算法框架](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 就可以解决，只是需要一些改变。我直接说解题思路，很容易理解：

1、首先，我们按照 [图论算法基础](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) 中所讲的，把题目输入的 `edges` 转换成邻接表。

2、然后，我们从叶子节点开始，一层一层地删除叶子节点（每删除一层叶子节点，就会产生新的叶子节点），直到剩下的节点数小于等于 2 个为止。之所以是 2 个而不是 1 个，是因为如果输入的这幅图两边完全对称，可能出现两个节点都可以作为根节点的情况。

![](https://labuladong.online/images/algo/brief-extra/310.jpg)

3、最后剩下的这些节点，就是我们要找的最小高度树的根节点。

如何一层一层删除所有叶子节点呢？只要用 [BFS 算法](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) ，借助一个队列就可以了，具体实现看代码吧。

肯定有读者会问，这种题怎么能想出来呢？这需要你熟悉 BFS 算法的执行过程。

我们常见的 BFS 是把树的根节点初始化到队列里，这样可以找到距离根节点最近的叶子节点。那么如果反过来，把所有叶子节点作为起点，一层一层向上进行层序遍历，那么就可以保证这棵树的宽度尽可能「均匀」，即不会出现左子树为空，右子树却很深的情况。这样一来，最终反向搜索到的根节点就是能够让树高最小的根节点。

#### 解法代码

#### 算法可视化

算法可视化

## 较为简单的 BFS 算法

### 841\. 钥匙和房间

**841\. 钥匙和房间** | [力扣](https://leetcode.cn/problems/keys-and-rooms/) | [LeetCode](https://leetcode.com/problems/keys-and-rooms/)

有 `n` 个房间，房间按从 `0` 到 `n - 1` 编号。最初，除 `0` 号房间外的其余所有房间都被锁住。你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候进入锁住的房间。

当你进入一个房间，你可能会在里面找到一套不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。你可以拿上所有钥匙去解锁其他房间。

给你一个数组 `rooms` 其中 `rooms[i]` 是你进入 `i` 号房间可以获得的钥匙集合。如果能进入 **所有** 房间返回 `true` ，否则返回 `false` 。

**示例 1：**

```
输入：rooms = [[1],[2],[3],[]]
输出：true
解释：
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。
```

**示例 2：**

```
输入：rooms = [[1,3],[3,0,1],[2],[0]]
输出：false
解释：我们不能进入 2 号房间。
```

**提示：**

- `n == rooms.length`
- `2 <= n <= 1000`
- `0 <= rooms[i].length <= 1000`
- `1 <= sum(rooms[i].length) <= 3000`
- `0 <= rooms[i][j] < n`
- 所有 `rooms[i]` 的值 **互不相同**

题目来源： [力扣 841. 钥匙和房间](https://leetcode.cn/problems/keys-and-rooms/) 。

#### 基本思路

其实题目输入的就是一个 [邻接表](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) 形式表示的图。

你心里那棵穷举树结构出来没有？如果没有的话，可以看一下可视化面板，BFS 和 DFS 的解法代码和可视化我都做了：

算法可视化

算法可视化

只要抽象出了穷举树，我们用 [DFS/BFS 算法](https://labuladong.online/zh/algo/data-structure-basic/graph-traverse-basic/) 从节点 `0` 开始遍历这幅图就行了，看看是否所有的节点都被访问到了。

对于这道题的 BFS 解法我多说两句，因为本题只是问是否可以遍历完所有图，并没有问最短距离之类的问题，所以我选择了 [DFS/BFS 算法](https://labuladong.online/zh/algo/data-structure-basic/graph-traverse-basic/) 中介绍的第一种最简单的 BFS 写法。

#### 解法代码

#### 算法可视化

算法可视化

### 1306\. 跳跃游戏 III

这里有一个非负整数数组 `arr` ，你最开始位于该数组的起始下标  `start`  处。当你位于下标  `i`  处时，你可以跳到  `i + arr[i]` 或者 `i - arr[i]` 。

请你判断自己是否能够跳到对应元素值为 0 的 **任一** 下标处。

注意，不管是什么情况下，你都无法跳到数组之外。

**示例 1：**

```
输入：arr = [4,2,3,0,3,1,2], start = 5
输出：true
解释：
到达值为 0 的下标 3 有以下可能方案： 
下标 5 -> 下标 4 -> 下标 1 -> 下标 3 
下标 5 -> 下标 6 -> 下标 4 -> 下标 1 -> 下标 3
```

**示例 2：**

```
输入：arr = [4,2,3,0,3,1,2], start = 0
输出：true 
解释：
到达值为 0 的下标 3 有以下可能方案： 
下标 0 -> 下标 4 -> 下标 1 -> 下标 3
```

**示例 3：**

```
输入：arr = [3,0,2,1,2], start = 2
输出：false
解释：无法到达值为 0 的下标 1 处。
```

**提示：**

- `1 <= arr.length <= 5 * 10^4`
- `0 <= arr[i] < arr.length`
- `0 <= start < arr.length`

题目来源： [力扣 1306. 跳跃游戏 III](https://leetcode.cn/problems/jump-game-iii/) 。

#### 基本思路

这种题就是穷举呗，心里那棵树出来没有？每个位置可以向左跳或者向右跳，这就是两种选择，都穷举一遍，就形成一棵二叉树：

算法可视化

注意需要用 `visited` 数组记录已经访问过的位置避免重复访问。我就用 BFS 来写这道题吧，有时间的话你也可以用 DFS 来练练手。

#### 解法代码

#### 算法可视化

算法可视化

### 433\. 最小基因变化

**433\. 最小基因变化** | [力扣](https://leetcode.cn/problems/minimum-genetic-mutation/) | [LeetCode](https://leetcode.com/problems/minimum-genetic-mutation/)

基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 `'A'` 、 `'C'` 、 `'G'` 和 `'T'` 之一。

假设我们需要调查从基因序列 `start` 变为 `end` 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

- 例如， `"AACCGGTT" --> "AACCGGTA"` 就是一次基因变化。

另有一个基因库 `bank` 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 `bank` 中）

给你两个基因序列 `start` 和 `end` ，以及一个基因库 `bank` ，请你找出并返回能够使  `start` 变化为 `end` 所需的最少变化次数。如果无法完成此基因变化，返回 `-1` 。

注意：起始基因序列 `start` 默认是有效的，但是它并不一定会出现在基因库中。

**示例 1：**

```
输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
输出：1
```

**示例 2：**

```
输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
输出：2
```

**示例 3：**

```
输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
输出：3
```

**提示：**

- `start.length == 8`
- `end.length == 8`
- `0 <= bank.length <= 10`
- `bank[i].length == 8`
- `start` 、 `end` 和 `bank[i]` 仅由字符 `['A', 'C', 'G', 'T']` 组成

题目来源： [力扣 433. 最小基因变化](https://leetcode.cn/problems/minimum-genetic-mutation/) 。

#### 基本思路

一个字符串的每一位都可以变化为 A/G/C/T，你的心里是否抽象出了一棵以 `start` 为根节点的多叉树？有了那棵多叉树，直接套用 [BFS 算法框架](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 就可以找到 `start` 到 `end` 的最短路径了。

#### 解法代码

#### 算法可视化

算法可视化

### 1926\. 迷宫中离入口最近的出口

**1926\. 迷宫中离入口最近的出口** | [力扣](https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/) | [LeetCode](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/)

给你一个 `m x n`  的迷宫矩阵  `maze` （ **下标从 0 开始** ），矩阵中有空格子（用 `'.'` 表示）和墙（用 `'+'` 表示）。同时给你迷宫的入口 `entrance`  ，用  `entrance = [entrance<sub>row</sub>, entrance<sub>col</sub>]` 表示你一开始所在格子的行和列。

每一步操作，你可以往 **上** ， **下** ， **左** 或者 **右** 移动一个格子。你不能进入墙所在的格子，你也不能离开迷宫。你的目标是找到离 `entrance` **最近** 的出口。 **出口** 的含义是 `maze` **边界** 上的 **空格子** 。 `entrance` 格子 **不算** 出口。

请你返回从 `entrance` 到最近出口的最短路径的 **步数** ，如果不存在这样的路径，请你返回 `-1` 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/06/04/nearest1-grid.jpg)
```
输入：maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
输出：1
解释：总共有 3 个出口，分别位于 (1,0)，(0,2) 和 (2,3) 。
一开始，你在入口格子 (1,2) 处。
- 你可以往左移动 2 步到达 (1,0) 。
- 你可以往上移动 1 步到达 (0,2) 。
从入口处没法到达 (2,3) 。
所以，最近的出口是 (0,2) ，距离为 1 步。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/06/04/nearesr2-grid.jpg)
```
输入：maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
输出：2
解释：迷宫中只有 1 个出口，在 (1,2) 处。
(1,0) 不算出口，因为它是入口格子。
初始时，你在入口与格子 (1,0) 处。
- 你可以往右移动 2 步到达 (1,2) 处。
所以，最近的出口为 (1,2) ，距离为 2 步。
```

**示例 3：**

![](https://labuladong.online/images/lc/uploads/2021/06/04/nearest3-grid.jpg)
```
输入：maze = [[".","+"]], entrance = [0,0]
输出：-1
解释：这个迷宫中没有出口。
```

**提示：**

- `maze.length == m`
- `maze[i].length == n`
- `1 <= m, n <= 100`
- `maze[i][j]` 要么是 `'.'` ，要么是 `'+'` 。
- `entrance.length == 2`
- `0 <= entrance<sub>row</sub> < m`
- `0 <= entrance<sub>col</sub> < n`
- `entrance` 一定是空格子。

题目来源： [力扣 1926. 迷宫中离入口最近的出口](https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/) 。

#### 基本思路

这道题非常简单，就是标准的 BFS 算法，只要套用 [BFS 算法模板框架](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 就可以了，直接看代码吧。另外我建议做一下 [286\. 墙与门](https://leetcode.cn/problems/walls-and-gates/description/) ，比这道题有意思一些。

#### 解法代码

#### 算法可视化

算法可视化

### 1091\. 二进制矩阵中的最短路径

**1091\. 二进制矩阵中的最短路径** | [力扣](https://leetcode.cn/problems/shortest-path-in-binary-matrix/) | [LeetCode](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

给你一个 `n x n` 的二进制矩阵 `grid` 中，返回矩阵中最短 **畅通路径** 的长度。如果不存在这样的路径，返回 `-1` 。

二进制矩阵中的 畅通路径 是一条从 **左上角** 单元格（即， `(0, 0)` ）到 右下角 单元格（即， `(n - 1, n - 1)` ）的路径，该路径同时满足下述要求：

- 路径途经的所有单元格的值都是 `0` 。
- 路径中所有相邻的单元格应当在 **8 个方向之一** 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。

**畅通路径的长度** 是该路径途经的单元格总数。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/02/18/example1_1.png)
```
输入：grid = [[0,1],[1,0]]
输出：2
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/02/18/example2_1.png)
```
输入：grid = [[0,0,0],[1,1,0],[1,1,0]]
输出：4
```

**示例 3：**

```
输入：grid = [[1,0,0],[1,1,0],[1,1,0]]
输出：-1
```

**提示：**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 100`
- `grid[i][j]` 为 `0` 或 `1`

题目来源： [力扣 1091. 二进制矩阵中的最短路径](https://leetcode.cn/problems/shortest-path-in-binary-matrix/) 。

#### 基本思路

这道题的思路应该很明显， [BFS 算法](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 肯定可以解决。

一般我们二维矩阵相关的题目只允许上下左右移动，这里还允许斜着移动，只要稍微改一改 [BFS 算法框架](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 中的方向数组 `dirs` 即可。

#### 解法代码

#### 算法可视化

算法可视化

**详细题解**:

- [A\* 算法核心原理及实现](https://labuladong.online/zh/algo/data-structure/a-star/)

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表