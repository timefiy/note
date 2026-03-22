---
title: 用「遍历」思维解题 III
source: https://labuladong.online/zh/algo/problem-set/binary-tree-traverse-iii/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上所有用遍历思维求解的二叉树经典习题（第三部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
二叉树的题目还会夹杂着一些其他算法技巧一起考你，不过都离不开二叉树的遍历框架，看几道例题，体会一下。

### 437\. 路径总和 III

给定一个二叉树的根节点 `root`  ，和一个整数 `targetSum` ，求该二叉树里节点值之和等于 `targetSum` 的 **路径** 的数目。

**路径** 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/04/09/pathsum3-1-tree.jpg)

```
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
```

**示例 2：**

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
```

**提示:**

- 二叉树的节点个数的范围是 `[0,1000]`
- `-10<sup>9</sup> <= Node.val <= 10<sup>9</sup>`
- `-1000 <= targetSum <= 1000`

题目来源： [力扣 437. 路径总和 III](https://leetcode.cn/problems/path-sum-iii/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维模式。

这题的难度应该设置为困难，因为这题及要求你准确理解二叉树的前序后序遍历，还要熟悉前缀和技巧，把前缀和技巧用到二叉树上。

你可以先看前文 [前缀和技巧](https://labuladong.online/zh/algo/data-structure/prefix-sum/) ，然后做一下 [560\. 和为K的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/description/) ，应该能够理解这道题的思路了。

你把二叉树看做是数组，利用前后序遍历来维护前缀和，看下图就能理解解法中几个关键变量的关系了：

![](https://labuladong.online/images/algo/brief-extra/437.jpeg)

#### 解法代码

```
class Solution {

    // 记录前缀和

    // 定义：从二叉树的根节点开始，路径和为 pathSum 的路径有 preSumCount.get(pathSum) 个

    unordered_map<long long, int> preSumCount;

    long long currentPathSum, targetSum;

    int res = 0;

public:

    int pathSum(TreeNode* root, int targetSum) {

        if (root == nullptr) {

            return 0;

        }

        this->currentPathSum = 0;

        this->targetSum = targetSum;

        this->preSumCount[0] = 1;

        traverse(root);

        return res;

    }

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        // 前序遍历位置

        currentPathSum += root->val;

        // 从二叉树的根节点开始，路径和为 pathSum - targetSum 的路径条数

        // 就是路径和为 targetSum 的路径条数

        res += preSumCount[currentPathSum - targetSum];

        // 记录从二叉树的根节点开始，路径和为 pathSum 的路径条数

        preSumCount[currentPathSum] += 1;

        traverse(root->left);

        traverse(root->right);

        // 后序遍历位置

        preSumCount[currentPathSum] -= 1;

        currentPathSum -= root->val;

    }

};
```

#### 算法可视化

算法可视化

### 513\. 找树左下角的值

**513\. 找树左下角的值** | [力扣](https://leetcode.cn/problems/find-bottom-left-tree-value/) | [LeetCode](https://leetcode.com/problems/find-bottom-left-tree-value/)

给定一个二叉树的 **根节点** `root` ，请找出该二叉树的 **最底层 最左边** 节点的值。

假设二叉树中至少有一个节点。

**示例 1:**

![](https://labuladong.online/images/lc/uploads/2020/12/14/tree1.jpg)

```
输入: root = [2,1,3]
输出: 1
```

**示例 2:**

![](https://labuladong.online/images/lc/uploads/2020/12/14/tree2.jpg)

```
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
```

**提示:**

- 二叉树的节点个数的范围是 `[1,10<sup>4</sup>]`
- `-2<sup>31</sup> <= Node.val <= 2<sup>31</sup> - 1`

题目来源： [力扣 513. 找树左下角的值](https://leetcode.cn/problems/find-bottom-left-tree-value/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

二叉树递归框架代码是先递归左子树，后递归右子树，所以到最大深度时第一次遇到的节点就是左下角的节点。

当然，这题也可以用 BFS 层序遍历来做，留给你思考吧。

#### 解法代码

```
class Solution {

    // 记录二叉树的最大深度

    int maxDepth = 0;

    // 记录 traverse 递归遍历到的深度

    int depth = 0;

    TreeNode* res = nullptr;

public:

    int findBottomLeftValue(TreeNode* root) {

        traverse(root);

        return res->val;

    }

private:

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        // 前序遍历位置

        depth++;

        if (depth > maxDepth) {

            // 到最大深度时第一次遇到的节点就是左下角的节点

            maxDepth = depth;

            res = root;

        }

        traverse(root->left);

        traverse(root->right);

        // 后序遍历位置

        depth--;

    }

};
```

#### 算法可视化

算法可视化

### 1261\. 在受污染的二叉树中查找元素

**1261\. 在受污染的二叉树中查找元素** | [力扣](https://leetcode.cn/problems/find-elements-in-a-contaminated-binary-tree/) | [LeetCode](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/)

给出一个满足下述规则的二叉树：

1. `root.val == 0`
2. 如果 `treeNode.val == x` 且  `treeNode.left != null` ，那么  `treeNode.left.val == 2 * x + 1`
3. 如果 `treeNode.val == x` 且 `treeNode.right != null` ，那么  `treeNode.right.val == 2 * x + 2`

现在这个二叉树受到「污染」，所有的 `treeNode.val` 都变成了 `-1` 。

请你先还原二叉树，然后实现 `FindElements` 类：

- `FindElements(TreeNode* root)` 用受污染的二叉树初始化对象，你需要先把它还原。
- `bool find(int target)` 判断目标值 `target` 是否存在于还原后的二叉树中并返回结果。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/11/16/untitled-diagram-4-1.jpg)**

```
输入：
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
输出：
[null,false,true]
解释：
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/11/16/untitled-diagram-4.jpg)**

```
输入：
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
输出：
[null,true,true,false]
解释：
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
```

**示例 3：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/11/16/untitled-diagram-4-1-1.jpg)**

```
输入：
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
输出：
[null,true,false,false,true]
解释：
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
```

**提示：**

- `TreeNode.val == -1`
- 二叉树的高度不超过 `20`
- 节点的总数在 `[1, 10^4]` 之间
- 调用 `find()` 的总次数在 `[1, 10^4]` 之间
- `0 <= target <= 10^6`

题目来源： [力扣 1261. 在受污染的二叉树中查找元素](https://leetcode.cn/problems/find-elements-in-a-contaminated-binary-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

还原二叉树的时候只需要遍历所有节点，通过函数参数传递每个节点的值；由于节点的个数规模不算大，所以可以直接用一个 HashSet 缓存所有节点值，实现 `find` 函数的功能。

当然，题目给的这种二叉树节点的取值规律非常像用数组存储完全二叉树的场景，所以你应该可以通过 `target` 推算出来它在第几层的什么位置，不过我这里就不实现了，类似的题目你可以参考 [1104\. 二叉树寻路](https://leetcode.cn/problems/path-in-zigzag-labelled-binary-tree/description/) 和 [662\. 二叉树最大宽度](https://leetcode.cn/problems/maximum-width-of-binary-tree/description/) 。

#### 解法代码

```
#include <unordered_set>

// Make sure TreeNode is defined before including this code block.

class FindElements {

    // 帮助 find 函数快速判断

    std::unordered_set<int> values;

public:

    FindElements(TreeNode* root) {

        // 还原二叉树中的值

        traverse(root, 0);

    }

    // 二叉树遍历函数

    void traverse(TreeNode* root, int val) {

        if (root == nullptr) {

            return;

        }

        root->val = val;

        values.insert(val);

        traverse(root->left, 2 * val + 1);

        traverse(root->right, 2 * val + 2);

    }

    bool find(int target) {

        return values.count(target) > 0;

    }

};
```

#### 算法可视化

算法可视化

### 386\. 字典序排数

**386\. 字典序排数** | [力扣](https://leetcode.cn/problems/lexicographical-numbers/) | [LeetCode](https://leetcode.com/problems/lexicographical-numbers/)

给你一个整数 `n` ，按字典序返回范围 `[1, n]` 内所有整数。

你必须设计一个时间复杂度为 `O(n)` 且使用 `O(1)` 额外空间的算法。

**示例 1：**

```
输入：n = 13
输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
```

**示例 2：**

```
输入：n = 2
输出：[1,2]
```

**提示：**

- `1 <= n <= 5 * 10<sup>4</sup>`

题目来源： [力扣 386. 字典序排数](https://leetcode.cn/problems/lexicographical-numbers/) 。

#### 基本思路

这个题还挺有意思，要不是它把这道题放在 DFS 的题目分类里面，可能还不太好发现这是一个 DFS 的题目。

既然题目提示你这是个 DFS 的题目了，你心里那棵递归树出来没有？如果没有，建议去看看前文 [二叉树视角学习递归思维](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 。

它的递归树大概是这样生长的：

首先看 1 这个节点，1 可以生出二位数 10, 11, 12...

其中 10 又可以生出 100, 101, 102...，11 又可以生出 110, 111, 112...

这棵多叉树是不是就出来了？每个节点最多可以生出 10 个节点，这就是一个十叉树。

还是想不出来？看可视化面板。实际的解法代码需要以 1~9 分别作为根节点，画 9 棵多叉树， **这里仅仅以 1 为根节点画递归树，方便你理解** ：

算法可视化

我们只需要以前序顺序遍历这棵多叉树，收集所有小于 `n` 的节点，就可以得到题目想要的答案。

#### 解法代码

```
#include <vector>

class Solution {

    std::vector<int> res;

public:

    std::vector<int> lexicalOrder(int n) {

        // 总共有 9 棵多叉树，从 1 开始

        for (int i = 1; i < 10; i++) {

            traverse(i, n);

        }

        return res;

    }

    // 多叉树遍历框架，前序位置收集所有小于 n 的节点

    void traverse(int root, int n) {

        if (root > n) {

            return;

        }

        res.push_back(root);

        for (int child = root * 10; child < root * 10 + 10; child++) {

            traverse(child, n);

        }

    }

};
```

#### 算法可视化

算法可视化

### 1104\. 二叉树寻路

**1104\. 二叉树寻路** | [力扣](https://leetcode.cn/problems/path-in-zigzag-labelled-binary-tree/) | [LeetCode](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/)

在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 **逐行** 依次按 “之” 字形进行标记。

如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；

而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/06/28/tree.png)

给你树上某一个节点的标号 `label` ，请你返回从根节点到该标号为 `label` 节点的路径，该路径是由途经的节点标号所组成的。

**示例 1：**

```
输入：label = 14
输出：[1,3,4,14]
```

**示例 2：**

```
输入：label = 26
输出：[1,2,6,10,26]
```

**提示：**

- `1 <= label <= 10^6`

题目来源： [力扣 1104. 二叉树寻路](https://leetcode.cn/problems/path-in-zigzag-labelled-binary-tree/) 。

#### 基本思路

如果你看过前文 [二叉堆（优先级队列）原理及实现](https://labuladong.online/zh/algo/data-structure-basic/binary-heap-basic/) ，就知道这种完全二叉树可以通过索引来模拟左右指针以及父节点指针。

具体来说，先假设全都是从左到右排列，没有之字形排列的这个条件：

![](https://labuladong.online/images/algo/brief-extra/1104.png)

如果我想求到达某一个 `label` 节点的路径，那么我一直对 `label` 除以 2 就行了（忽略余数）。

你比如我想求到达 13 的路径，就是 13, 6, 3, 1，然后反转一下就行了。大致的代码逻辑如下：

```
ArrayList<Integer> path = new ArrayList<>();

while (label >= 1) {

    path.add(label);

    label = label / 2;

}

// 反转成从根节点到目标节点的路径

Collections.reverse(path);
```

现在虽然是之字形排列，但稍加修改就可以适应这个变化：

![](https://labuladong.online/images/algo/brief-extra/tree.png)

13 的父节点不是 6 了，而是 7 - (6 - 4) = 5。

这个 7 和 4 是哪里来的？就是 6 这一行的最小节点值和最大节点值，而对于完全二叉树，每一行的最大最小值可以通过计算 2 的指数算出来的。

理解了上述思路，就能看懂解法代码了。

#### 解法代码

```
class Solution {

public:

    vector<int> pathInZigZagTree(int label) {

        vector<int> path;

        while (label >= 1) {

            path.push_back(label);

            int depth = log2(label);

            vector<int> range = getLevelRange(depth);

            // 由于之字形分布，根据上层的节点取值范围，修正父节点

            label = range[1] - (label - range[0]);

            label /= 2;

        }

        // 反转成从根节点到目标节点的路径

        reverse(path.begin(), path.end());

        return path;

    }

private:

    // 获取第 n 层节点的取值范围

    vector<int> getLevelRange(int n) {

        int p = pow(2, n);

        return {p, 2 * p - 1};

    }

};
```

#### 算法可视化

算法可视化

### 1145\. 二叉树着色游戏

**1145\. 二叉树着色游戏** | [力扣](https://leetcode.cn/problems/binary-tree-coloring-game/) | [LeetCode](https://leetcode.com/problems/binary-tree-coloring-game/)

有两位极客玩家参与了一场「二叉树着色」的游戏。游戏中，给出二叉树的根节点 `root` ，树上总共有 `n` 个节点，且 `n` 为奇数，其中每个节点上的值从  `1` 到  `n` 各不相同。

最开始时：

- 「一号」玩家从 `[1, n]` 中取一个值 `x` （ `1 <= x <= n` ）；
- 「二号」玩家也从 `[1, n]` 中取一个值 `y` （ `1 <= y <= n` ）且  `y != x` 。

「一号」玩家给值为 `x`  的节点染上红色，而「二号」玩家给值为  `y` 的节点染上蓝色。

之后两位玩家轮流进行操作，「一号」玩家先手。每一回合，玩家选择一个被他染过色的节点，将所选节点一个 **未着色** 的邻节点（即左右子节点、或父节点）进行染色（「一号」玩家染红色，「二号」玩家染蓝色）。

如果（且仅在此种情况下）当前玩家无法找到这样的节点来染色时，其回合就会被跳过。

若两个玩家都没有可以染色的节点时，游戏结束。着色节点最多的那位玩家获得胜利 ✌️。

现在，假设你是「二号」玩家，根据所给出的输入，假如存在一个 `y`  值可以确保你赢得这场游戏，则返回  `true` ；若无法获胜，就请返回 `false` 。

**示例 1 ：**

![](https://labuladong.online/images/lc/uploads/2019/08/01/1480-binary-tree-coloring-game.png)
```
输入：root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
输出：true
解释：第二个玩家可以选择值为 2 的节点。
```

**示例 2 ：**

```
输入：root = [1,2,3], n = 3, x = 1
输出：false
```

**提示：**

- 树中节点数目为 `n`
- `1 <= x <= n <= 100`
- `n` 是奇数
- `1 <= Node.val <= n`
- 树中所有值 **互不相同**

题目来源： [力扣 1145. 二叉树着色游戏](https://leetcode.cn/problems/binary-tree-coloring-game/) 。

#### 基本思路

这道题的关键是要观察规律，根据游戏规则，对方先选一个节点之后，你的最优策略就是紧贴着对方的那个节点选择，也就是说你应该选择节点 `x` 的左右子节点或者父节点。

做出以上三种选择，你可以占据二叉树的不同部分，如下图：

![](https://labuladong.online/images/algo/brief-extra/1145.png)

你如果想赢，必须占据超过 `n / 2` 的节点，也就是说，如果这三个蓝色区域中节点数最多的那个区域中的节点个数大于 `n / 2` ，你能赢，否则你就输。

所以本题转化为计算二叉树节点个数的简单问题，具体看代码逻辑。

#### 解法代码

```
class Solution {

public:

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {

        TreeNode* node = find(root, x);

        int leftCount = count(node->left);

        int rightCount = count(node->right);

        int otherCount = n - 1 - leftCount - rightCount;

        return max(leftCount, max(rightCount, otherCount)) > n / 2;

    }

    // 定义：在以 root 为根的二叉树中搜索值为 x 的节点并返回

    TreeNode* find(TreeNode* root, int x) {

        if (root == nullptr) {

            return nullptr;

        }

        if (root->val == x) {

            return root;

        }

        // 去左子树找

        TreeNode* left = find(root->left, x);

        if (left != nullptr) {

            return left;

        }

        // 左子树找不到的话去右子树找

        return find(root->right, x);

    }

    // 定义：计算以 root 为根的二叉树的节点总数

    int count(TreeNode* root) {

        if (root == nullptr) {

            return 0;

        }

        return 1 + count(root->left) + count(root->right);

    }

};
```

#### 算法可视化

算法可视化

### 2096\. 从二叉树一个节点到另一个节点每一步的方向

**2096\. 从二叉树一个节点到另一个节点每一步的方向** | [力扣](https://leetcode.cn/problems/step-by-step-directions-from-a-binary-tree-node-to-another/) | [LeetCode](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)

给你一棵 **二叉树** 的根节点 `root`  ，这棵二叉树总共有  `n`  个节点。每个节点的值为  `1`  到  `n`  中的一个整数，且互不相同。给你一个整数  `startValue`  ，表示起点节点 `s`  的值，和另一个不同的整数  `destValue`  ，表示终点节点  `t` 的值。

请找到从节点 `s`  到节点 `t` 的 **最短路径** ，并以字符串的形式返回每一步的方向。每一步用 **大写** 字母 `'L'` ， `'R'` 和 `'U'` 分别表示一种方向：

- `'L'` 表示从一个节点前往它的 **左孩子** 节点。
- `'R'` 表示从一个节点前往它的 **右孩子** 节点。
- `'U'` 表示从一个节点前往它的 **父** 节点。

请你返回从 `s`  到 `t` **最短路径** 每一步的方向。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/11/15/eg1.png)

```
输入：root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
输出："UURL"
解释：最短路径为：3 → 1 → 5 → 2 → 6 。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/11/15/eg2.png)

```
输入：root = [2,1], startValue = 2, destValue = 1
输出："L"
解释：最短路径为：2 → 1 。
```

**提示：**

- 树中节点数目为 `n` 。
- `2 <= n <= 10<sup>5</sup>`
- `1 <= Node.val <= n`
- 树中所有节点的值 **互不相同** 。
- `1 <= startValue, destValue <= n`
- `startValue != destValue`

题目来源： [力扣 2096. 从二叉树一个节点到另一个节点每一步的方向](https://leetcode.cn/problems/step-by-step-directions-from-a-binary-tree-node-to-another/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维模式。

这题的思路比较巧妙，主要分三步：

1、分别记录从根节点到 `startValue` 和 `destValue` 的路径 `startPath` 和 `destPath` 。

2、然后去除 `startPath` 和 `destPath` 的公共前缀。

3、最后将 `startPath` 全部变成 `U` ，把 `startPath` 和 `destPath` 接在一起，就是题目要求的路径了。

#### 解法代码

```
#include <string>

using namespace std;

class Solution {

public:

    string getDirections(TreeNode* root, int startValue, int destValue) {

        this->startValue = startValue;

        this->destValue = destValue;

        // 寻找走到 startValue 和 destValue 的方向路径

        traverse(root);

        // 去除两个方向路径的公共前缀

        int p = 0, m = startPath.size(), n = destPath.size();

        while (p < m && p < n && startPath[p] == destPath[p]) {

            p++;

        }

        startPath = startPath.substr(p);

        destPath = destPath.substr(p);

        // 将走向 startValue 的方向路径全部变成 U

        startPath = string(startPath.size(), 'U');

        // 组合 startPath 和 destPath 就得到了答案

        return startPath + destPath;

    }

private:

    string path;

    string startPath, destPath;

    int startValue, destValue;

    // 二叉树遍历函数

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        if (root->val == startValue) {

            startPath = path;

        } else if (root->val == destValue) {

            destPath = path;

        }

        // 二叉树遍历框架

        path.push_back('L');

        traverse(root->left);

        path.pop_back();

        path.push_back('R');

        traverse(root->right);

        path.pop_back();

    }

};
```

#### 算法可视化

算法可视化

Tip

题目也可以让你在二叉树中寻找某棵子树，这种情况下会在递归函数中调用其他递归函数，时间复杂度会上升到平方级别，但也没有什么别的办法优化，只能通过遍历来对比子树。

### 572\. 另一棵树的子树

**572\. 另一棵树的子树** | [力扣](https://leetcode.cn/problems/subtree-of-another-tree/) | [LeetCode](https://leetcode.com/problems/subtree-of-another-tree/)

给你两棵二叉树 `root` 和 `subRoot` 。检验 `root` 中是否包含和 `subRoot` 具有相同结构和节点值的子树。如果存在，返回 `true` ；否则，返回 `false` 。

二叉树 `tree` 的一棵子树包括 `tree` 的某个节点和这个节点的所有后代节点。 `tree` 也可以看做它自身的一棵子树。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/04/28/subtree1-tree.jpg)
```
输入：root = [3,4,5,1,2], subRoot = [4,1,2]
输出：true
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/04/28/subtree2-tree.jpg)
```
输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
输出：false
```

**提示：**

- `root` 树上的节点数量范围是 `[1, 2000]`
- `subRoot` 树上的节点数量范围是 `[1, 1000]`
- `-10<sup>4</sup> <= root.val <= 10<sup>4</sup>`
- `-10<sup>4</sup> <= subRoot.val <= 10<sup>4</sup>`

题目来源： [力扣 572. 另一棵树的子树](https://leetcode.cn/problems/subtree-of-another-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

遍历以 `root` 为根的这棵二叉树的所有节点，用 [100\. 相同的树](https://leetcode.cn/problems/same-tree/description/) 中的 `isSame` 函数判断以该节点为根的子树是否和以 `subRoot` 为根的那棵树相同。

#### 解法代码

```
class Solution {

public:

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (root == nullptr) {

            return subRoot == nullptr;

        }

        // 判断以 root 为根的二叉树是否和 subRoot 相同

        if (isSameTree(root, subRoot)) {

            return true;

        }

        // 去左右子树中判断是否有和 subRoot 相同的子树

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // 判断一对节点是否相同

        if (p == nullptr && q == nullptr) {

            return true;

        }

        if (p == nullptr || q == nullptr) {

            return false;

        }

        if (p->val != q->val) {

            return false;

        }

        // 判断其他节点是否相同

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }

};
```

#### 算法可视化

算法可视化

### 1367\. 二叉树中的链表

**1367\. 二叉树中的链表** | [力扣](https://leetcode.cn/problems/linked-list-in-binary-tree/) | [LeetCode](https://leetcode.com/problems/linked-list-in-binary-tree/)

给你一棵以 `root`  为根的二叉树和一个  `head` 为第一个节点的链表。

如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 `head`  为首的链表中每个节点的值，那么请你返回 `True` ，否则返回 `False` 。

一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/02/29/sample_1_1720.png)**

```
输入：head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
输出：true
解释：树中蓝色的节点构成了与链表对应的子路径。
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/02/29/sample_2_1720.png)**

```
输入：head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
输出：true
```

**示例 3：**

```
输入：head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
输出：false
解释：二叉树中不存在一一对应链表的路径。
```

**提示：**

- 二叉树和链表中的每个节点的值都满足 `1 <= node.val <= 100` 。
- 链表包含的节点数目在 `1`  到  `100` 之间。
- 二叉树包含的节点数目在 `1`  到  `2500` 之间。

题目来源： [力扣 1367. 二叉树中的链表](https://leetcode.cn/problems/linked-list-in-binary-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

本质上， `isSubPath` 就是在遍历二叉树的所有节点，对每个节点用 `check` 函数判断是否能够将链表嵌进去。

#### 解法代码

```
class Solution {

public:

    bool isSubPath(ListNode* head, TreeNode* root) {

        // base case

        if (head == nullptr) return true;

        if (root == nullptr) return false;

        // 当找到一个二叉树节点的值等于链表头结点时

        if (head->val == root->val) {

            // 判断是否能把链表嵌进去

            if (check(head, root)) {

                return true;

            }

        }

        // 继续去遍历其他节点尝试嵌入链表

        return isSubPath(head, root->left) || isSubPath(head, root->right);

    }

    // 检查是否能够将链表嵌入二叉树

    bool check(ListNode* head, TreeNode* root) {

        if (head == nullptr) return true;

        if (root == nullptr) return false;

        if (head->val == root->val) {

            // 在子树上嵌入子链表

            return check(head->next, root->left) || check(head->next, root->right);

        }

        return false;

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表