---
title: 运用层序遍历解题 I
source: https://labuladong.online/zh/algo/problem-set/binary-tree-level-i/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上所有二叉树层序遍历的经典习题（第一部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
前置知识

阅读本文前，你需要先学习：

- [二叉树的遍历基础](https://labuladong.online/zh/algo/data-structure-basic/binary-tree-traverse-basic/)
- [二叉树心法（纲领篇）](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/)

二叉树大部分题目都可以用递归的算法解决，但少部分题目用递归比较麻烦的话，我们可以考虑使用层序遍历的方式解决。

### 102\. 二叉树的层序遍历

**102\. 二叉树的层序遍历** | [力扣](https://leetcode.cn/problems/binary-tree-level-order-traversal/) | [LeetCode](https://leetcode.com/problems/binary-tree-level-order-traversal/)

给你二叉树的根节点 `root` ，返回其节点值的 **层序遍历** 。 （即逐层地，从左到右访问所有节点）。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/02/19/tree1.jpg)
```
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
```

**示例 2：**

```
输入：root = [1]
输出：[[1]]
```

**示例 3：**

```
输入：root = []
输出：[]
```

**提示：**

- 树中节点数目在范围 `[0, 2000]` 内
- `-1000 <= Node.val <= 1000`

题目来源： [力扣 102. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/) 。

#### 基本思路

这题没啥可说的， [二叉树的递归/层序遍历](https://labuladong.online/zh/algo/data-structure-basic/binary-tree-traverse-basic/) 遍历中介绍了三种层序（BFS）遍历的写法，任写一种都可以。

#### 解法代码

#### 算法可视化

算法可视化

### 107\. 二叉树的层序遍历 II

给你二叉树的根节点 `root` ，返回其节点值 **自底向上的层序遍历** 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/02/19/tree1.jpg)
```
输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]
```

**示例 2：**

```
输入：root = [1]
输出：[[1]]
```

**示例 3：**

```
输入：root = []
输出：[]
```

**提示：**

- 树中节点数目在范围 `[0, 2000]` 内
- `-1000 <= Node.val <= 1000`

题目来源： [力扣 107. 二叉树的层序遍历 II](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/) 。

#### 基本思路

这题和 [102\. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/) 几乎是一样的，自顶向下的层序遍历反过来就行了。

#### 解法代码

#### 算法可视化

算法可视化

### 103\. 二叉树的锯齿形层序遍历

**103\. 二叉树的锯齿形层序遍历** | [力扣](https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/) | [LeetCode](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

给你二叉树的根节点 `root` ，返回其节点值的 **锯齿形层序遍历** 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/02/19/tree1.jpg)
```
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[20,9],[15,7]]
```

**示例 2：**

```
输入：root = [1]
输出：[[1]]
```

**示例 3：**

```
输入：root = []
输出：[]
```

**提示：**

- 树中节点数目在范围 `[0, 2000]` 内
- `-100 <= Node.val <= 100`

题目来源： [力扣 103. 二叉树的锯齿形层序遍历](https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/) 。

#### 基本思路

这题和 [102\. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/) 几乎是一样的，只要用一个布尔变量 `flag` 控制遍历方向即可。

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

### 515\. 在每个树行中找最大值

**515\. 在每个树行中找最大值** | [力扣](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/) | [LeetCode](https://leetcode.com/problems/find-largest-value-in-each-tree-row/)

给定一棵二叉树的根节点 `root` ，请找出该二叉树中每一层的最大值。

**示例1：**

![](https://labuladong.online/images/lc/uploads/2020/08/21/largest_e1.jpg)

```
输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
```

**示例2：**

```
输入: root = [1,2,3]
输出: [1,3]
```

**提示：**

- 二叉树的节点个数的范围是 `[0,10<sup>4</sup>]`
- `-2<sup>31</sup> <= Node.val <= 2<sup>31</sup> - 1`

题目来源： [力扣 515. 在每个树行中找最大值](https://leetcode.cn/problems/find-largest-value-in-each-tree-row/) 。

#### 基本思路

首先，这题肯定可以用 BFS 算法解决，for 循环里面判断最大值就行了：

![](https://labuladong.online/images/algo/dijkstra/1.jpeg)

当然，这题也可以用 DFS 来做，前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

遍历的过程中记录对应深度的最大节点值即可。

#### 解法代码

#### 算法可视化

算法可视化

### 637\. 二叉树的层平均值

**637\. 二叉树的层平均值** | [力扣](https://leetcode.cn/problems/average-of-levels-in-binary-tree/) | [LeetCode](https://leetcode.com/problems/average-of-levels-in-binary-tree/)

给定一个非空二叉树的根节点 `root`, 以数组的形式返回每一层节点的平均值。与实际答案相差  `10<sup>-5</sup>` 以内的答案可以被接受。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/03/09/avg1-tree.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：[3.00000,14.50000,11.00000]
解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
因此返回 [3, 14.5, 11] 。
```

**示例 2:**

![](https://labuladong.online/images/lc/uploads/2021/03/09/avg2-tree.jpg)

```
输入：root = [3,9,20,15,7]
输出：[3.00000,14.50000,11.00000]
```

**提示：**

- 树中节点数量在 `[1, 10<sup>4</sup>]` 范围内
- `-2<sup>31</sup> <= Node.val <= 2<sup>31</sup> - 1`

题目来源： [力扣 637. 二叉树的层平均值](https://leetcode.cn/problems/average-of-levels-in-binary-tree/) 。

#### 基本思路

标准的二叉树层序遍历，把 [102\. 层序遍历二叉树](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/) 的代码稍微改一改就行了。

#### 解法代码

#### 算法可视化

算法可视化

### 958\. 二叉树的完全性检验

**958\. 二叉树的完全性检验** | [力扣](https://leetcode.cn/problems/check-completeness-of-a-binary-tree/) | [LeetCode](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)

给你一棵二叉树的根节点 `root` ，请你判断这棵树是否是一棵 **完全二叉树** 。

在一棵 **[完全二叉树](https://baike.baidu.com/item/%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91/7773232?fr=aladdin)** 中，除了最后一层外，所有层都被完全填满，并且最后一层中的所有节点都尽可能靠左。最后一层（第 `h` 层）中可以包含 `1` 到 `2<sup>h</sup>` 个节点。

**示例 1：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2018/12/15/complete-binary-tree-1.png)

```
输入：root = [1,2,3,4,5,6]
输出：true
解释：最后一层前的每一层都是满的（即，节点值为 {1} 和 {2,3} 的两层），且最后一层中的所有节点（{4,5,6}）尽可能靠左。
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2018/12/15/complete-binary-tree-2.png)**

```
输入：root = [1,2,3,4,5,null,7]
输出：false
解释：值为 7 的节点不满足条件「节点尽可能靠左」。
```

**提示：**

- 树中节点数目在范围 `[1, 100]` 内
- `1 <= Node.val <= 1000`

题目来源： [力扣 958. 二叉树的完全性检验](https://leetcode.cn/problems/check-completeness-of-a-binary-tree/) 。

#### 基本思路

这题的关键是对完全二叉树特性的理解， **如果按照 BFS 层序遍历的方式遍历完全二叉树，队列最后留下的应该都是空指针** ：

![](https://labuladong.online/images/algo/brief-extra/958.jpeg)

所以可以用 [102\. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/) 给出的层序遍历框架解决这题。

#### 解法代码

#### 算法可视化

算法可视化

### 1161\. 最大层内元素和

**1161\. 最大层内元素和** | [力扣](https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/) | [LeetCode](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

给你一个二叉树的根节点 `root` 。设根节点位于二叉树的第 `1` 层，而根节点的子节点位于第 `2` 层，依此类推。

请返回层内元素之和 **最大** 的那几层（可能只有一层）的层号，并返回其中 **最小** 的那个。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/08/17/capture.jpeg)**

```
输入：root = [1,7,0,7,-8,null,null]
输出：2
解释：
第 1 层各元素之和为 1，
第 2 层各元素之和为 7 + 0 = 7，
第 3 层各元素之和为 7 + -8 = -1，
所以我们返回第 2 层的层号，它的层内元素之和最大。
```

**示例 2：**

```
输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
输出：2
```

**提示：**

- 树中的节点数在 `[1, 10<sup>4</sup>]` 范围内
- `-10<sup>5</sup> <= Node.val <= 10<sup>5</sup>`

题目来源： [力扣 1161. 最大层内元素和](https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/) 。

#### 基本思路

把 [102\. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/) 给出的层序遍历框架稍微变通即可解决这题。

#### 解法代码

#### 算法可视化

算法可视化

### 1302\. 层数最深叶子节点的和

**1302\. 层数最深叶子节点的和** | [力扣](https://leetcode.cn/problems/deepest-leaves-sum/) | [LeetCode](https://leetcode.com/problems/deepest-leaves-sum/)

给你一棵二叉树的根节点 `root` ，请你返回 **层数最深的叶子节点的和** 。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/12/28/1483_ex1.png)**

```
输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
输出：15
```

**示例 2：**

```
输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
输出：19
```

**提示：**

- 树中节点数目在范围 `[1, 10<sup>4</sup>]` 之间。
- `1 <= Node.val <= 100`

题目来源： [力扣 1302. 层数最深叶子节点的和](https://leetcode.cn/problems/deepest-leaves-sum/) 。

#### 基本思路

这题用 DFS 或者 BFS 都可以，我就用 BFS 层序遍历算法吧，层序遍历算法参见 [102\. 层序遍历二叉树](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/) ，这题只要把最后一层的节点值累加起来就行了。

#### 解法代码

#### 算法可视化

算法可视化

### 1609\. 奇偶树

**1609\. 奇偶树** | [力扣](https://leetcode.cn/problems/even-odd-tree/) | [LeetCode](https://leetcode.com/problems/even-odd-tree/)

如果一棵二叉树满足下述几个条件，则可以称为 **奇偶树** ：

- 二叉树根节点所在层下标为 `0` ，根的子节点所在层下标为 `1` ，根的孙节点所在层下标为 `2` ，依此类推。
- **偶数下标** 层上的所有节点的值都是 **奇** 整数，从左到右按顺序 **严格递增**
- **奇数下标** 层上的所有节点的值都是 **偶** 整数，从左到右按顺序 **严格递减**

给你二叉树的根节点，如果二叉树为 **奇偶树** ，则返回 `true` ，否则返回 `false` 。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/10/04/sample_1_1966.png)**

```
输入：root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
输出：true
解释：每一层的节点值分别是：
0 层：[1]
1 层：[10,4]
2 层：[3,7,9]
3 层：[12,8,6,2]
由于 0 层和 2 层上的节点值都是奇数且严格递增，而 1 层和 3 层上的节点值都是偶数且严格递减，因此这是一棵奇偶树。
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/10/04/sample_2_1966.png)**

```
输入：root = [5,4,2,3,3,7]
输出：false
解释：每一层的节点值分别是：
0 层：[5]
1 层：[4,2]
2 层：[3,3,7]
2 层上的节点值不满足严格递增的条件，所以这不是一棵奇偶树。
```

**示例 3：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/10/04/sample_1_333_1966.png)

```
输入：root = [5,9,1,3,5,7]
输出：false
解释：1 层上的节点值应为偶数。
```

**示例 4：**

```
输入：root = [1]
输出：true
```

**示例 5：**

```
输入：root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
输出：true
```

**提示：**

- 树中节点数在范围 `[1, 10<sup>5</sup>]` 内
- `1 <= Node.val <= 10<sup>6</sup>`

题目来源： [力扣 1609. 奇偶树](https://leetcode.cn/problems/even-odd-tree/) 。

#### 基本思路

这道题主要考察二叉树的层序遍历，你可以先做一下 [102\. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/) 和 [103\. 二叉树的锯齿形层序遍历](https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/) 这两道题，然后再做这道题。具体思路可看解法代码的注释。

#### 解法代码

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表