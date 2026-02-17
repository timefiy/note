---
title: "利用后序位置解题 III"
source: "https://labuladong.online/zh/algo/problem-set/binary-tree-post-order-iii/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文汇总了 力扣/LeetCode 上所有利用二叉树后序位置求解的经典习题（第三部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。"
tags:
  - "clippings"
---
写在后序位置的代码是最潇洒的，上通父节点（可以通过函数参数获取父节点信息），下通子树（可以通过递归返回值收集子树信息），有少部分难度比较大的题目会同时用到这两个特性。

### 968\. 监控二叉树

**968\. 监控二叉树** | [力扣](https://leetcode.cn/problems/binary-tree-cameras/) | [LeetCode](https://leetcode.com/problems/binary-tree-cameras/)

给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视 **其父对象、自身及其直接子对象。**

计算监控树的所有节点所需的最小摄像头数量。

**示例 1：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2018/12/29/bst_cameras_01.png)

```
输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。
```

**示例 2：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2018/12/29/bst_cameras_02.png)

```
输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
```

  
**提示：**

1. 给定树的节点数的范围是 `[1, 1000]` 。
2. 每个节点的值都是 0。

题目来源： [力扣 968. 监控二叉树](https://leetcode.cn/problems/binary-tree-cameras/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过后序位置的特殊之处，后序位置可以接收到子树的信息，同时也可以通过函数参数接收到父节点传递的信息，这道题就可以比较完美地体现这一特点。

首先我们列举一下一个节点可能存在的几种状态：

该节点不在监控区域内，称为 uncover 状态；该节点在附近节点的监控范围内，称为 cover 状态；该节点自己装了摄像头，称为 set 状态。

如何保证安装的摄像头数量尽可能少呢？显然就是要尽可能分散，让每个摄像头物尽其用。

具体来说就是自底向上安装摄像头，在叶子节点的父节点上安装摄像头，然后每隔两层再安装（因为每个摄像头都可以管三层）。

那么一个节点在什么情况下需要被安装摄像头呢？显然是当这个节点的子节点处于 uncover 的状态的时候必须安装摄像头，以便覆盖子节点。

综上，我们需要利用后序位置自底向上遍历二叉树，同时要利用子节点的状态以及父节点的状态，判断当前节点是否需要安装摄像头。

解法中 `setCamera` 函数就负责按照最优方式给二叉树安装摄像头，同时返回节点的状态。

#### 解法代码

```
class Solution {

public:

    int minCameraCover(TreeNode* root) {

        setCamera(root, false);

        return res;

    }

private:

    int res = 0;

    // 定义：输入以 root 为根的二叉树，以最优策略在这棵二叉树上放置摄像头，

    // 然后返回 root 节点的情况：

    // 返回 -1 代表 root 为空，返回 0 代表 root 未被 cover，

    // 返回 1 代表 root 已经被 cover，返回 2 代表 root 上放置了摄像头。

    int setCamera(TreeNode* root, bool hasParent) {

        if (root == nullptr) {

            return -1;

        }

        // 获取左右子节点的情况

        int left = setCamera(root->left, true);

        int right = setCamera(root->right, true);

        // 根据左右子节点的情况和父节点的情况判断当前节点应该做的事情

        if (left == -1 && right == -1) {

            // 当前节点是叶子节点

            if (hasParent) {

                // 有父节点的话，让父节点来 cover 自己

                return 0;

            }

            // 没有父节点的话，自己 set 一个摄像头

            res++;

            return 2;

        }

        if (left == 0 || right == 0) {

            // 左右子树存在没有被 cover 的

            // 必须在当前节点 set 一个摄像头

            res += 1;

            return 2;

        }

        if (left == 2 || right == 2) {

            // 左右子树只要有一个 set 了摄像头

            // 当前节点就已经是 cover 状态了

            return 1;

        }

        // 剩下 left == 1 && right == 1 的情况

        // 即当前节点的左右子节点都被 cover

        if (hasParent) {

            // 如果有父节点的话，可以等父节点 cover 自己

            return 0;

        } else {

            // 没有父节点，只能自己 set 一个摄像头

            res++;

            return 2;

        }

    }

};
```

#### 算法可视化

算法可视化

### 979\. 在二叉树中分配硬币

**979\. 在二叉树中分配硬币** | [力扣](https://leetcode.cn/problems/distribute-coins-in-binary-tree/) | [LeetCode](https://leetcode.com/problems/distribute-coins-in-binary-tree/)

给你一个有 `n` 个结点的二叉树的根结点 `root` ，其中树中每个结点 `node` 都对应有 `node.val` 枚硬币。整棵树上一共有 `n` 枚硬币。

在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。移动可以是从父结点到子结点，或者从子结点移动到父结点。

返回使每个结点上 **只有** 一枚硬币所需的 **最少** 移动次数。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2019/01/18/tree1.png)
```
输入：root = [3,0,0]
输出：2
解释：一枚硬币从根结点移动到左子结点，一枚硬币从根结点移动到右子结点。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2019/01/18/tree2.png)
```
输入：root = [0,3,0]
输出：3
解释：将两枚硬币从根结点的左子结点移动到根结点（两次移动）。然后，将一枚硬币从根结点移动到右子结点。
```

**提示：**

- 树中节点的数目为 `n`
- `1 <= n <= 100`
- `0 <= Node.val <= n`
- 所有 `Node.val` 的值之和是 `n`

题目来源： [力扣 979. 在二叉树中分配硬币](https://leetcode.cn/problems/distribute-coins-in-binary-tree/) 。

#### 基本思路

做这道题之前，你应该先做一下 [543\. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/description/) ，并且认真理解 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 中说到的后序遍历的用法。

硬币的移动规则看似很复杂，因为一个节点可能需要移出硬币，也可能移入硬币，还要求移动次数最少，是不是感觉无从下手？

对于这种问题，我们首先要观察规律仔细思考，看看能否对题目进行简化，然后再求解。

首先题目说了整棵树上一共有 `n` 枚硬币，意思是通过移动，一定是可以做到每个节点有且仅有一枚硬币，不存在无解的情况。

现在的情况是，每个节点有 `node.val` 个硬币， `node.val >= 0` ，允许我们在相邻节点随意移动硬币，计算将所有节点配平（只有 1 个硬币）的最少移动次数。

**我们可以简单变换一下：允许每个节点的硬币个数为负数，且只允许子节点向父节点移动硬币** 。

比方说父节点想向子节点移动 1 个硬币，等价于子节点向父节点移动 -1 个硬币；如果一个节点的硬币个数为 -3，那么他就需要向父节点移动 -4 个硬币，才能让自己的硬币个数变成 1。

这样，我们就不用考虑移入和移出的区别了，想要把一个节点的硬币个数变成 1，就要向父节点移动 `node.val - 1` 个节点。

现在就可以开始二叉树的通用解题思路： **假想你现在站在根节点上，你如何知道把整棵树配平所需的最小移动次数** ？

左子树来跟你汇报，想给你移动 `left` 个节点；右子树来找你汇报，想给你移动 `right` 个节点，那么你所在节点向父节点移动的硬币个数就是：

```
left + right + (node.val - 1)
```

这个过程中移动次数是：

```
// 让当前这棵树平衡所需的移动次数

Math.abs(left) + Math.abs(right) + (node.val - 1);
```

现在你去看代码就能理解了。

#### 解法代码

```
class Solution {

public:

    int distributeCoins(TreeNode* root) {

        getRest(root);

        return res;

    }

private:

    int res = 0;

    // 定义：输入一棵二叉树，返回这棵二叉树中多出的硬币个数，返回负数代表缺少硬币

    int getRest(TreeNode* root) {

        if (root == nullptr) {

            return 0;

        }

        // 计算左右子树多出的硬币个数

        int left = getRest(root->left);

        int right = getRest(root->right);

        // 后序位置，计算当前这棵树配平所需的移动次数

        res += abs(left) + abs(right) + (root->val - 1);

        // 实现函数的定义

        return left + right + (root->val - 1);

    }

};
```

#### 算法可视化

算法可视化

### 1080\. 根到叶路径上的不足节点

**1080\. 根到叶路径上的不足节点** | [力扣](https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/) | [LeetCode](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/)

给你二叉树的根节点 `root` 和一个整数 `limit` ，请你同时删除树中所有 **不足节点** ，并返回最终二叉树的根节点。

假如通过节点 `node` 的每种可能的 “根-叶” 路径上值的总和全都小于给定的 `limit` ，则该节点被称之为 **不足节点** ，需要被删除。

**叶子节点** ，就是没有子节点的节点。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2019/06/05/insufficient-11.png)
```
输入：root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
输出：[1,2,3,4,null,null,7,8,9,null,14]
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2019/06/05/insufficient-3.png)
```
输入：root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
输出：[5,4,8,11,null,17,4,7,null,null,null,5]
```

**示例 3：**

![](https://labuladong.online/images/lc/uploads/2019/06/11/screen-shot-2019-06-11-at-83301-pm.png)
```
输入：root = [1,2,-3,-5,null,4,null], limit = -1
输出：[1,null,-3,4]
```

**提示：**

- 树中节点数目在范围 `[1, 5000]` 内
- `-10<sup>5</sup> <= Node.val <= 10<sup>5</sup>`
- `-10<sup>9</sup> <= limit <= 10<sup>9</sup>`

题目来源： [力扣 1080. 根到叶路径上的不足节点](https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/) 。

#### 基本思路

可以说这道题非常精妙，完美运用前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 中说到的前序位置和后序位置的特点：

前序位置可以通过函数参数获取父节点传递来的数据，后序位置可以额外获取子树传递回来的数据。

首先，对于一个叶子节点，它本身就是以自己为根的这棵二叉树的路径，那么这条路径是否小于 `limit` 的约束是很显然的，如果小于 `limit` ，说明它需要被删除。

然后，对于一个非叶子节点 `x` ，它是否是一个「不足节点」，或者说是否存在一条不满足 `limit` 约束的路径穿过这个节点，其实可以根据子树推导出来。

如果 `x` 的左右子节点都被删除，那么就说明 `x` 的左右子树上的路径都不满足 `limit` 的约束，也就是说所有穿过 `x` 的路径都不满足约束，即 `x` 也应该被删除。

根据上述思路实现代码，即可解决这道题。

#### 解法代码

```
class Solution {

public:

    // 定义：输入一个节点 root，和约束 limit，

    // 删除以 root 为根的二叉树中的「不足节点」，返回删除完成后的二叉树根节点

    TreeNode* sufficientSubset(TreeNode* root, int limit) {

        if (root == nullptr) {

            return nullptr;

        }

        // 前序位置，接收父节点传递的 limit 约束决定叶子结点是否需要被删除

        if (root->left == nullptr && root->right == nullptr) {

            if (root->val < limit) {

                // 对于叶子节点，如果低于 limit 说明需要被删除

                return nullptr;

            }

            return root;

        }

        // 先对左右子树进行删除，接收返回值

        root->left = sufficientSubset(root->left, limit - root->val); // Here we are calling the function correctly

        root->right = sufficientSubset(root->right, limit - root->val); // Same here

        // 后序位置，根据子树的删除情况决定自己是否需要被删除

        if (root->left == nullptr && root->right == nullptr) {

            // 如果左右子树不满足 limit - root->val 的约束，那么就存在经过 root

            // 节点的路径不满足约束，也就说明 root 节点是「不足节点」，需要被删掉

            // 如果左右子树不满足 limit - root.val 的约束，那么就存在经过 root

            return nullptr;

        }

        return root;

    }

};
```

#### 算法可视化

算法可视化

### 2049\. 统计最高分的节点数目

**2049\. 统计最高分的节点数目** | [力扣](https://leetcode.cn/problems/count-nodes-with-the-highest-score/) | [LeetCode](https://leetcode.com/problems/count-nodes-with-the-highest-score/)

给你一棵根节点为 `0` 的 **二叉树** ，它总共有 `n`  个节点，节点编号为  `0`  到  `n - 1`  。同时给你一个下标从  **0**  开始的整数数组  `parents`  表示这棵树，其中  `parents[i]` 是节点 `i`  的父节点。由于节点 `0`  是根，所以  `parents[0] == -1` 。

一个子树的 **大小** 为这个子树内节点的数目。每个节点都有一个与之关联的 **分数** 。求出某个节点分数的方法是，将这个节点和与它相连的边全部 **删除** ，剩余部分是若干个 **非空** 子树，这个节点的 **分数** 为所有这些子树 **大小的乘积** 。

请你返回有 **最高得分** 节点的 **数目** 。

**示例 1:**

![example-1](https://labuladong.online/images/lc/uploads/2021/10/03/example-1.png)

```
输入：parents = [-1,2,0,2,0]
输出：3
解释：
- 节点 0 的分数为：3 * 1 = 3
- 节点 1 的分数为：4 = 4
- 节点 2 的分数为：1 * 1 * 2 = 2
- 节点 3 的分数为：4 = 4
- 节点 4 的分数为：4 = 4
最高得分为 4 ，有三个节点得分为 4 （分别是节点 1，3 和 4 ）。
```

**示例 2：**

![example-2](https://labuladong.online/images/lc/uploads/2021/10/03/example-2.png)

```
输入：parents = [-1,2,0]
输出：2
解释：
- 节点 0 的分数为：2 = 2
- 节点 1 的分数为：2 = 2
- 节点 2 的分数为：1 * 1 = 1
最高分数为 2 ，有两个节点分数为 2 （分别为节点 0 和 1 ）。
```

**提示：**

- `n == parents.length`
- `2 <= n <= 10<sup>5</sup>`
- `parents[0] == -1`
- 对于 `i != 0`  ，有  `0 <= parents[i] <= n - 1`
- `parents` 表示一棵二叉树。

题目来源： [力扣 2049. 统计最高分的节点数目](https://leetcode.cn/problems/count-nodes-with-the-highest-score/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维，而且要用到后序位置的妙用。

在做这道题之前，建议你先去看下我给 [1339\. 分裂二叉树的最大乘积](https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/description/) 写的思路和解法代码，然后立马就知道这道题的思路了。

简单说，一个节点的 **分数 = 左子树节点个数 x 右子树节点个数 x 除自己外其他节点个数** 。

只要写个 `countNode` 函数，在后序位置可以得到左右子树的节点个数 `leftCount` 和 `rightCount` ，然后除自己外其他节点个数 `otherCount` 就等于总的节点个数 `n` 减掉左右子树的节点个数再减掉当前节点，最后求个乘积就能算出当前节点的「分数」了。

当然，这道题还有个难点就是：题目给的 `parents` 数组不是我们经常见到的二叉树形式。

但问题不大，我们可以把 `parents` 数组转化成类似 [图论基础](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) 中讲到的邻接表结构，然后就可以像操作常规二叉树一样写算法了。

#### 解法代码

```
class Solution {

    // 用邻接表表示的一棵二叉树

    vector<vector<int>> tree;

    unordered_map<long long, int> scoreToCount;

public:

    int countHighestScoreNodes(vector<int>& parents) {

        this->tree = buildTree(parents);

        countNode(0);

        // 计算最大分数出现的次数

        long long maxScore = 0;

        for (const auto& [score, count] : scoreToCount) {

            maxScore = max(maxScore, score);

        }

        return scoreToCount[maxScore];

    }

    // 计算二叉树中的节点个数

    int countNode(int root) {

        if (root == -1) {

            return 0;

        }

        // 二叉树中节点总数

        int n = tree.size();

        int leftCount = countNode(tree[root][0]);

        int rightCount = countNode(tree[root][1]);

        // 后序位置，计算每个节点的「分数」

        int otherCount = n - leftCount - rightCount - 1;

        // 注意，这里要把 int 转化成 long，否则会产生溢出！！！

        long long score = (long long)max(leftCount, 1)

                * max(rightCount, 1) * max(otherCount, 1);

        // 给分数 score 计数

        if (scoreToCount.find(score) != scoreToCount.end()) {

            scoreToCount[score]++;

        } else {

            scoreToCount[score] = 1;

        }

        return leftCount + rightCount + 1;

    }

    // 将 parents 数组转化成常规二叉树（邻接表形式）

    vector<vector<int>> buildTree(vector<int>& parents) {

        int n = parents.size();

        // 表节点 x 的左子节点为 tree[x][0]，节点 x 的右子节点为 tree[x][1]

        // 若 tree[x][0] 或 tree[x][1] 等于 -1 则代表空指针

        vector<vector<int>> tree(n, vector<int>(2, -1));

        for (int i = 0; i < n; i++) {

            // 先都初始化成空指针

            tree[i][0] = tree[i][1] = -1;

        }

        // 根据 parents 数组构建二叉树（跳过 parents[0] 根节点）

        for (int i = 1; i < n; i++) {

            int parent_i = parents[i];

            if (tree[parent_i][0] == -1) {

                tree[parent_i][0] = i;

            } else {

                tree[parent_i][1] = i;

            }

        }

        return tree;

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表