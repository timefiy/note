---
title: 用「遍历」思维解题 II
source: https://labuladong.online/zh/algo/problem-set/binary-tree-traverse-ii/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上所有用遍历思维求解的二叉树经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
如果让你在二叉树中的某些节点上做文章，一般来说也可以直接用遍历的思维模式。

### 404\. 左叶子之和

**404\. 左叶子之和** | [力扣](https://leetcode.cn/problems/sum-of-left-leaves/) | [LeetCode](https://leetcode.com/problems/sum-of-left-leaves/)

给定二叉树的根节点 `root` ，返回所有左叶子之和。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/04/08/leftsum-tree.jpg)

```
输入: root = [3,9,20,null,null,15,7] 
输出: 24 
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
```

**示例 2:**

```
输入: root = [1]
输出: 0
```

**提示:**

- 节点数在 `[1, 1000]` 范围内
- `-1000 <= Node.val <= 1000`

题目来源： [力扣 404. 左叶子之和](https://leetcode.cn/problems/sum-of-left-leaves/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

无非就是遍历一遍二叉树，然后找到那些左叶子节点，累加它们的值罢了。

#### 解法代码

```
class Solution {

public:

    int sumOfLeftLeaves(TreeNode* root) {

        traverse(root);

        return sum;

    }

    // 记录左叶子之和

    int sum = 0;

    // 二叉树遍历函数

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        if (root->left != nullptr &&

            root->left->left == nullptr && root->left->right == nullptr) {

            // 找到左侧的叶子节点，记录累加值

            sum += root->left->val;

        }

        // 递归框架

        traverse(root->left);

        traverse(root->right);

    }

};
```

#### 算法可视化

算法可视化

### 623\. 在二叉树中增加一行

**623\. 在二叉树中增加一行** | [力扣](https://leetcode.cn/problems/add-one-row-to-tree/) | [LeetCode](https://leetcode.com/problems/add-one-row-to-tree/)

给定一个二叉树的根 `root`  和两个整数 `val` 和  `depth`  ，在给定的深度  `depth`  处添加一个值为 `val` 的节点行。

注意，根节点 `root`  位于深度  `1` 。

加法规则如下:

- 给定整数 `depth` ，对于深度为  `depth - 1` 的每个非空树节点 `cur` ，创建两个值为 `val` 的树节点作为 `cur` 的左子树根和右子树根。
- `cur` 原来的左子树应该是新的左子树根的左子树。
- `cur` 原来的右子树应该是新的右子树根的右子树。
- 如果 `depth == 1 ` 意味着 `depth - 1`  根本没有深度，那么创建一个树节点，值 `val ` 作为整个原始树的新根，而原始树就是新根的左子树。

**示例 1:**

![](https://labuladong.online/images/lc/uploads/2021/03/15/addrow-tree.jpg)

```
输入: root = [4,2,6,3,1,5], val = 1, depth = 2
输出: [4,1,1,2,null,null,6,3,1,5]
```

**示例 2:**

![](https://labuladong.online/images/lc/uploads/2021/03/11/add2-tree.jpg)

```
输入: root = [4,2,null,3,1], val = 1, depth = 3
输出:  [4,2,null,1,1,3,null,null,1]
```

**提示:**

- 节点数在 `[1, 10<sup>4</sup>]` 范围内
- 树的深度在 `[1, 10<sup>4</sup>]` 范围内
- `-100 <= Node.val <= 100`
- `-10<sup>5</sup> <= val <= 10<sup>5</sup>`
- `1 <= depth <= the depth of tree + 1`

题目来源： [力扣 623. 在二叉树中增加一行](https://leetcode.cn/problems/add-one-row-to-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

用 `traverse` 函数遍历到对应行，进行插入即可。

#### 解法代码

```
class Solution {

private:

    int targetVal, targetDepth;

public:

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        targetVal = val;

        targetDepth = depth;

        // 插入到第一行的话特殊对待一下

        if (targetDepth == 1) {

            TreeNode* newRoot = new TreeNode(targetVal);

            newRoot->left = root;

            return newRoot;

        }

        // 遍历二叉树，走到对应行进行插入

        traverse(root);

        return root;

    }

private:

    int curDepth = 0;

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        // 前序遍历

        curDepth++;

        if (curDepth == targetDepth - 1) {

            // 进行插入

            TreeNode* newLeft = new TreeNode(targetVal);

            TreeNode* newRight = new TreeNode(targetVal);

            newLeft->left = root->left;

            newRight->right = root->right;

            root->left = newLeft;

            root->right = newRight;

        }

        traverse(root->left);

        traverse(root->right);

        // 后序遍历

        curDepth--;

    }

};
```

#### 算法可视化

算法可视化

### 971\. 翻转二叉树以匹配先序遍历

**971\. 翻转二叉树以匹配先序遍历** | [力扣](https://leetcode.cn/problems/flip-binary-tree-to-match-preorder-traversal/) | [LeetCode](https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/)

给你一棵二叉树的根节点 `root` ，树中有 `n` 个节点，每个节点都有一个不同于其他节点且处于 `1` 到 `n` 之间的值。

另给你一个由 `n` 个值组成的行程序列 `voyage` ，表示 **预期** 的二叉树 [**先序遍历**](https://baike.baidu.com/item/%E5%85%88%E5%BA%8F%E9%81%8D%E5%8E%86/6442839?fr=aladdin) 结果。

通过交换节点的左右子树，可以 **翻转** 该二叉树中的任意节点。例，翻转节点 1 的效果如下：

![](https://labuladong.online/images/lc/uploads/2021/02/15/fliptree.jpg)

请翻转 **最少** 的树中节点，使二叉树的 **先序遍历** 与预期的遍历行程 `voyage` **相匹配** 。

如果可以，则返回 **翻转的** 所有节点的值的列表。你可以按任何顺序返回答案。如果不能，则返回列表 `[-1]` 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2019/01/02/1219-01.png)
```
输入：root = [1,2], voyage = [2,1]
输出：[-1]
解释：翻转节点无法令先序遍历匹配预期行程。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2019/01/02/1219-02.png)
```
输入：root = [1,2,3], voyage = [1,3,2]
输出：[1]
解释：交换节点 2 和 3 来翻转节点 1 ，先序遍历可以匹配预期行程。
```

**示例 3：**

![](https://labuladong.online/images/lc/uploads/2019/01/02/1219-02.png)
```
输入：root = [1,2,3], voyage = [1,2,3]
输出：[]
解释：先序遍历已经匹配预期行程，所以不需要翻转节点。
```

**提示：**

- 树中的节点数目为 `n`
- `n == voyage.length`
- `1 <= n <= 100`
- `1 <= Node.val, voyage[i] <= n`
- 树中的所有值 **互不相同**
- `voyage` 中的所有值 **互不相同**

题目来源： [力扣 971. 翻转二叉树以匹配先序遍历](https://leetcode.cn/problems/flip-binary-tree-to-match-preorder-traversal/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

用 `traverse` 函数遍历整棵二叉树，对比前序遍历结果，如果节点的值对不上，就无解；如果子树对不上 `voyage` ，就尝试翻转子树。

#### 解法代码

```
#include <vector>

#include <algorithm>

using namespace std;

class Solution {

public:

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {

        this->voyage = voyage;

        // 遍历的过程中尝试进行反转

        traverse(root);

        if (canFlip) {

            return res;

        }

        return {-1};

    }

private:

    vector<int> res;

    int i = 0;

    vector<int> voyage;

    bool canFlip = true;

    void traverse(TreeNode* root) {

        if (root == nullptr || !canFlip) {

            return;

        }

        if (root->val != voyage[i++]) {

            // 节点的 val 对不上，必然无解

            canFlip = false;

            return;

        }

        if (root->left != nullptr && root->left->val != voyage[i]) {

            // 前序遍历结果不对，尝试翻转左右子树

            TreeNode* temp = root->left;

            root->left = root->right;

            root->right = temp;

            // 记录翻转节点

            res.push_back(root->val);

        }

        traverse(root->left);

        traverse(root->right);

    }

};
```

#### 算法可视化

算法可视化

### 987\. 二叉树的垂序遍历

**987\. 二叉树的垂序遍历** | [力扣](https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/) | [LeetCode](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

给你二叉树的根结点 `root` ，请你设计算法计算二叉树的 **垂序遍历** 序列。

对位于 `(row, col)` 的每个结点而言，其左右子结点分别位于 `(row + 1, col - 1)` 和 `(row + 1, col + 1)` 。树的根结点位于 `(0, 0)` 。

二叉树的 **垂序遍历** 从最左边的列开始直到最右边的列结束，按列索引每一列上的所有结点，形成一个按出现位置从上到下排序的有序列表。如果同行同列上有多个结点，则按结点的值从小到大进行排序。

返回二叉树的 **垂序遍历** 序列。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/01/29/vtree1.jpg)
```
输入：root = [3,9,20,null,null,15,7]
输出：[[9],[3,15],[20],[7]]
解释：
列 -1 ：只有结点 9 在此列中。
列  0 ：只有结点 3 和 15 在此列中，按从上到下顺序。
列  1 ：只有结点 20 在此列中。
列  2 ：只有结点 7 在此列中。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/01/29/vtree2.jpg)
```
输入：root = [1,2,3,4,5,6,7]
输出：[[4],[2],[1,5,6],[3],[7]]
解释：
列 -2 ：只有结点 4 在此列中。
列 -1 ：只有结点 2 在此列中。
列  0 ：结点 1 、5 和 6 都在此列中。
          1 在上面，所以它出现在前面。
          5 和 6 位置都是 (2, 0) ，所以按值从小到大排序，5 在 6 的前面。
列  1 ：只有结点 3 在此列中。
列  2 ：只有结点 7 在此列中。
```

**示例 3：**

![](https://labuladong.online/images/lc/uploads/2021/01/29/vtree3.jpg)
```
输入：root = [1,2,3,4,6,5,7]
输出：[[4],[2],[1,5,6],[3],[7]]
解释：
这个示例实际上与示例 2 完全相同，只是结点 5 和 6 在树中的位置发生了交换。
因为 5 和 6 的位置仍然相同，所以答案保持不变，仍然按值从小到大排序。
```

**提示：**

- 树中结点数目总数在范围 `[1, 1000]` 内
- `0 <= Node.val <= 1000`

题目来源： [力扣 987. 二叉树的垂序遍历](https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

看这题的难度是困难，但你别被吓住了，我们从简单的开始，如果以整棵树的根节点为坐标 `(0, 0)` ，你如何打印出其他节点的坐标？

很简单，写出如下代码遍历一遍二叉树即可：

```
void traverse(TreeNode root, int row, int col) {

    if (root == null) {

        return;

    }

    print(row, col);

    traverse(root.left, row + 1, col - 1);

    traverse(root.right, row + 1, col + 1);

}
```

然后就简单了，把这些坐标收集起来，依据题目要求进行排序，组装成题目要求的返回数据格式即可。

#### 解法代码

```
class Solution {

    // 记录每个节点和对应的坐标 (row, col)

    struct Triple {

        int row, col;

        TreeNode* node;

        Triple(TreeNode* node, int row, int col) {

            this->node = node;

            this->row = row;

            this->col = col;

        }

    };

public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // 遍历二叉树，并且为所有节点生成对应的坐标

        traverse(root, 0, 0);

        // 根据题意，根据坐标值对所有节点进行排序：

        // 按照 col 从小到大排序，col 相同的话按 row 从小到大排序，

        // 如果 col 和 row 都相同，按照 node.val 从小到大排序。

        sort(nodes.begin(), nodes.end(),  {

            if (a.col == b.col && a.row == b.row) {

                return a.node->val < b.node->val;

            }

            if (a.col == b.col) {

                return a.row < b.row;

            }

            return a.col < b.col;

        });

        // 将排好序的节点组装成题目要求的返回格式

        vector<vector<int>> res;

        // 记录上一列编号，初始化一个特殊值

        int preCol = INT_MIN;

        for (int i = 0; i < nodes.size(); i++) {

            Triple cur = nodes[i];

            if (cur.col != preCol) {

                // 开始记录新的一列

                res.push_back(vector<int>());

                preCol = cur.col;

            }

            res.back().push_back(cur.node->val);

        }

        return res;

    }

private:

    vector<Triple> nodes;

    // 二叉树遍历函数，记录所有节点对应的坐标

    void traverse(TreeNode* root, int row, int col) {

        if (root == nullptr) {

            return;

        }

        // 记录坐标

        nodes.push_back(Triple(root, row, col));

        // 二叉树遍历框架

        traverse(root->left, row + 1, col - 1);

        traverse(root->right, row + 1, col + 1);

    }

};
```

#### 算法可视化

算法可视化

### 993\. 二叉树的堂兄弟节点

**993\. 二叉树的堂兄弟节点** | [力扣](https://leetcode.cn/problems/cousins-in-binary-tree/) | [LeetCode](https://leetcode.com/problems/cousins-in-binary-tree/)

在二叉树中，根节点位于深度 `0` 处，每个深度为 `k` 的节点的子节点位于深度 `k+1` 处。

如果二叉树的两个节点深度相同，但 **父节点不同** ，则它们是一对 *堂兄弟节点* 。

我们给出了具有唯一值的二叉树的根节点 `root` ，以及树中两个不同节点的值 `x` 和 `y` 。

只有与值 `x` 和 `y` 对应的节点是堂兄弟节点时，才返回 `true` 。否则，返回 `false` 。

**示例 1：  
![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/16/q1248-01.png)**

```
输入：root = [1,2,3,4], x = 4, y = 3
输出：false
```

**示例 2：  
![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/16/q1248-02.png)**

```
输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
输出：true
```

**示例 3：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/16/q1248-03.png)**

```
输入：root = [1,2,3,null,4], x = 2, y = 3
输出：false
```

**提示：**

- 二叉树的节点数介于 `2` 到  `100` 之间。
- 每个节点的值都是唯一的、范围为 `1` 到  `100` 的整数。

题目来源： [力扣 993. 二叉树的堂兄弟节点](https://leetcode.cn/problems/cousins-in-binary-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

遍历找到 x，y 的深度和父节点，对比即可。

#### 解法代码

```
class Solution {

public:

    TreeNode* parentX = nullptr;

    TreeNode* parentY = nullptr;

    int depthX = 0, depthY = 0;

    int x, y;

    bool isCousins(TreeNode* root, int x, int y) {

        this->x = x;

        this->y = y;

        traverse(root, 0, nullptr);

        if (depthX == depthY && parentX != parentY) {

            // 判断 x，y 是否是表兄弟节点

            return true;

        }

        return false;

    }

    void traverse(TreeNode* root, int depth, TreeNode* parent) {

        if (root == nullptr) {

            return;

        }

        if (root->val == x) {

            // 找到 x，记录它的深度和父节点

            parentX = parent;

            depthX = depth;

        }

        if (root->val == y) {

            // 找到 y，记录它的深度和父节点

            parentY = parent;

            depthY = depth;

        }

        traverse(root->left, depth + 1, root);

        traverse(root->right, depth + 1, root);

    }

};
```

#### 算法可视化

算法可视化

### 1315\. 祖父节点值为偶数的节点和

**1315\. 祖父节点值为偶数的节点和** | [力扣](https://leetcode.cn/problems/sum-of-nodes-with-even-valued-grandparent/) | [LeetCode](https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/)

给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：

- 该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）

如果不存在祖父节点值为偶数的节点，那么返回 `0` 。

**示例：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/01/10/1473_ex1.png)**

```
输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
输出：18
解释：图中红色节点的祖父节点的值为偶数，蓝色节点为这些红色节点的祖父节点。
```

**提示：**

- 树中节点的数目在 `1` 到  `10^4` 之间。
- 每个节点的值在 `1` 到  `100` 之间。

题目来源： [力扣 1315. 祖父节点值为偶数的节点和](https://leetcode.cn/problems/sum-of-nodes-with-even-valued-grandparent/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

很简单，遍历一遍二叉树，对于节点值为偶数的节点，累加它的孙子节点的值即可。

#### 解法代码

```
class Solution {

public:

    int sumEvenGrandparent(TreeNode* root) {

        traverse(root);

        return sum;

    }

    int sum = 0;

    // 二叉树的遍历函数

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        if (root->val % 2 == 0) {

            // 累加左子树孙子节点的值

            if (root->left != nullptr) {

                if (root->left->left != nullptr) {

                    sum += root->left->left->val;

                }

                if (root->left->right != nullptr) {

                    sum += root->left->right->val;

                }

            }

            // 累加右子树孙子节点的值

            if (root->right != nullptr) {

                if (root->right->left != nullptr) {

                    sum += root->right->left->val;

                }

                if (root->right->right != nullptr) {

                    sum += root->right->right->val;

                }

            }

        }

        // 二叉树的遍历框架

        traverse(root->left);

        traverse(root->right);

    }

};
```

#### 算法可视化

算法可视化

### 1448\. 统计二叉树中好节点的数目

**1448\. 统计二叉树中好节点的数目** | [力扣](https://leetcode.cn/problems/count-good-nodes-in-binary-tree/) | [LeetCode](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)

给你一棵根为 `root` 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/05/16/test_sample_1.png)**

```
输入：root = [3,1,4,3,null,1,5]
输出：4
解释：图中蓝色节点为好节点。
根节点 (3) 永远是个好节点。
节点 4 -> (3,4) 是路径中的最大值。
节点 5 -> (3,4,5) 是路径中的最大值。
节点 3 -> (3,1,3) 是路径中的最大值。
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/05/16/test_sample_2.png)**

```
输入：root = [3,3,null,4,2]
输出：3
解释：节点 2 -> (3, 3, 2) 不是好节点，因为 "3" 比它大。
```

**示例 3：**

```
输入：root = [1]
输出：1
解释：根节点是好节点。
```

**提示：**

- 二叉树中节点数目范围是 `[1, 10^5]` 。
- 每个节点权值的范围是 `[-10^4, 10^4]` 。

题目来源： [力扣 1448. 统计二叉树中好节点的数目](https://leetcode.cn/problems/count-good-nodes-in-binary-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维，利用函数参数给子树传递信息。

函数参数 `pathMax` 记录从根节点到当前节点路径中的最大值，通过比较 `root.val` 和 `pathMax` 比较就可判断 `root` 节点是不是「好节点」。然后再把 `pathMax` 传递到子树中继续判断其他节点。

#### 解法代码

```
class Solution {

public:

    int goodNodes(TreeNode* root) {

        traverse(root, root->val);

        return count;

    }

private:

    int count = 0;

    // 二叉树遍历函数，pathMax 参数记录从根节点到当前节点路径中的最大值

    void traverse(TreeNode* root, int pathMax) {

        if (root == nullptr) {

            return;

        }

        if (pathMax <= root->val) {

            // 找到一个「好节点」

            count++;

        }

        // 更新路径上的最大值

        pathMax = max(pathMax, root->val);

        traverse(root->left, pathMax);

        traverse(root->right, pathMax);

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表