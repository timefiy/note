---
title: "利用后序位置解题 II"
source: "https://labuladong.online/zh/algo/problem-set/binary-tree-post-order-ii/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文汇总了 力扣/LeetCode 上所有利用二叉树后序位置求解的经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。"
tags:
  - "clippings"
---
像求和、求高度这种基本的二叉树函数很容易写，有时候只要在它们的后序位置添加一点代码，就能得到我们想要的答案。

### 687\. 最长同值路径

**687\. 最长同值路径** | [力扣](https://leetcode.cn/problems/longest-univalue-path/) | [LeetCode](https://leetcode.com/problems/longest-univalue-path/)

给定一个二叉树的 `root` ，返回 *最长的路径的长度* ，这个路径中的 *每个节点具有相同值* 。 这条路径可以经过也可以不经过根节点。

**两个节点之间的路径长度** 由它们之间的边数表示。

**示例 1:**

![](https://labuladong.online/images/lc/uploads/2020/10/13/ex1.jpg)

```
输入：root = [5,4,5,1,1,5]
输出：2
```

**示例 2:**

![](https://labuladong.online/images/lc/uploads/2020/10/13/ex2.jpg)

```
输入：root = [1,4,5,4,4,5]
输出：2
```

**提示:**

- 树的节点数的范围是 `[0, 10<sup>4</sup>]`
- `-1000 <= Node.val <= 1000`
- 树的深度将不超过 `1000`

题目来源： [力扣 687. 最长同值路径](https://leetcode.cn/problems/longest-univalue-path/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维，而且这类题目需要利用二叉树的后序遍历。

做这题之前，我建议你先做 [543\. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/description/) 题并进行对比，把那道题的最大深度函数 `maxDepth` 的定义带入到这道题中， `maxLen` 相当于求值为 `parentVal` 的节点的最大深度。配合代码注释就立马明白了。

#### 解法代码

```
class Solution {

    int res = 0;

public:

    int longestUnivaluePath(TreeNode* root) {

        if (root == nullptr) {

            return 0;

        }

        // 在后序遍历的位置更新 res

        maxLen(root, root->val);

        return res;

    }

private:

    // 定义：计算以 root 为根的这棵二叉树中，从 root 开始值为 parentVal 的最长树枝长度

    int maxLen(TreeNode* root, int parentVal) {

        if (root == nullptr) {

            return 0;

        }

        // 利用函数定义，计算左右子树值为 root.val 的最长树枝长度

        int leftLen = maxLen(root->left, root->val);

        int rightLen = maxLen(root->right, root->val);

        // 后序遍历位置顺便更新全局变量

        // 同值路径就是左右同值树枝长度之和

        res = max(res, leftLen + rightLen);

        // 如果 root 本身和上级值不同，那么整棵子树都不可能有同值树枝

        if (root->val != parentVal) {

            return 0;

        }

        // 实现函数的定义：

        // 以 root 为根的二叉树从 root 开始值为 parentVal 的最长树枝长度

        // 等于左右子树的最长树枝长度的最大值加上 root 节点本身

        return 1 + max(leftLen, rightLen);

    }

};
```

#### 算法可视化

算法可视化

### 865\. 具有所有最深节点的最小子树

**865\. 具有所有最深节点的最小子树** | [力扣](https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/) | [LeetCode](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/)

给定一个根为 `root` 的二叉树，每个节点的深度是 **该节点到根的最短距离** 。

返回包含原始树中所有 **最深节点** 的 *最小子树* 。

如果一个节点在 **整个树** 的任意节点之间具有最大的深度，则该节点是 **最深的** 。

一个节点的 **子树** 是该节点加上它的所有后代的集合。

**示例 1：**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4]
输出：[2,7,4]
解释：
我们返回值为 2 的节点，在图中用黄色标记。
在图中用蓝色标记的是树的最深的节点。
注意，节点 5、3 和 2 包含树中最深的节点，但节点 2 的子树最小，因此我们返回它。
```

**示例 2：**

```
输入：root = [1]
输出：[1]
解释：根节点是树中最深的节点。
```

**示例 3：**

```
输入：root = [0,1,3,null,2]
输出：[2]
解释：树中最深的节点为 2 ，有效子树为节点 2、1 和 0 的子树，但节点 2 的子树最小。
```

**提示：**

- 树中节点的数量在 `[1, 500]` 范围内。
- `0 <= Node.val <= 500`
- 每个节点的值都是 **独一无二** 的。

**注意：** 本题与力扣 1123 重复： [https://leetcode-cn.com/problems/lowest-common-ancestor-of-deepest-leaves](https://leetcode-cn.com/problems/lowest-common-ancestor-of-deepest-leaves/)

题目来源： [力扣 865. 具有所有最深节点的最小子树](https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维，而且涉及处理子树，需要用后序遍历。

说到底，这道题就是让你求那些「最深」的叶子节点的最近公共祖先，可以看下前文 [二叉树最近公共祖先](https://labuladong.online/zh/algo/practice-in-action/lowest-common-ancestor-summary/) 。

你想想，一个节点需要知道哪些信息，才能确定自己是最深叶子节点的最近公共祖先？

它需要知道自己的左右子树的最大深度：如果左右子树一样深，那么当前节点就是最近公共祖先；如果左右子树不一样深，那么最深叶子节点的最近公共祖先肯定在左右子树上。

所以我们新建一个 `Result` 类，存放左右子树的最大深度及叶子节点的最近公共祖先节点，其余逻辑类似 [104\. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/) 。

#### 解法代码

```
class Solution {

    struct Result {

        TreeNode* node;

        int depth;

        Result(TreeNode* node, int depth) {

            // 记录最近公共祖先节点 node

            this->node = node;

            // 记录以 node 为根的二叉树最大深度

            this->depth = depth;

        }

    };

public:

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        Result res = maxDepth(root);

        return res.node;

    }

private:

    // 定义：输入一棵二叉树，返回该二叉树的最大深度以及最深叶子节点的最近公共祖先节点

    Result maxDepth(TreeNode* root) {

        if (root == nullptr) {

            return Result(nullptr, 0);

        }

        Result left = maxDepth(root->left);

        Result right = maxDepth(root->right);

        if (left.depth == right.depth) {

            // 当左右子树的最大深度相同时，这个根节点是新的最近公共祖先

            // 以当前 root 节点为根的子树深度是子树深度 + 1

            return Result(root, left.depth + 1);

        }

        // 左右子树的深度不同，则最近公共祖先在 depth 较大的一边

        Result res = left.depth > right.depth ? left : right;

        // 正确维护二叉树的最大深度

        res.depth++;

        return res;

    }

};
```

#### 算法可视化

算法可视化

### 1026\. 节点与其祖先之间的最大差值

**1026\. 节点与其祖先之间的最大差值** | [力扣](https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/) | [LeetCode](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)

给定二叉树的根节点 `root` ，找出存在于 **不同** 节点 `A` 和  `B`  之间的最大值 `V` ，其中  `V = |A.val - B.val|` ，且 `A`  是  `B` 的祖先。

（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/11/09/tmp-tree.jpg)

```
输入：root = [8,3,10,1,6,null,14,null,null,4,7,13]
输出：7
解释： 
我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/11/09/tmp-tree-1.jpg)
```
输入：root = [1,null,2,null,0,3]
输出：3
```

**提示：**

- 树中的节点数在 `2`  到  `5000` 之间。
- `0 <= Node.val <= 10<sup>5</sup>`

题目来源： [力扣 1026. 节点与其祖先之间的最大差值](https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/) 。

#### 基本思路

这题要用到 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 中强调的二叉树后序位置的特殊性。

站在某个节点，你如何判断以这个节点为根的二叉树中的最大差值？换句话说，你需要知道哪些信息，才能算出来这个最大差值？

思考这个问题很有必要，你必须先知道怎么算，才能写递归函数去实现你的思路。

这个问题的答案是，每个节点需要知道左右子树的最小值和最大值，然后就能算出「以自己为祖先」的最大差值。

每个节点都知道以自己为祖先的最大差值，那么所有这些差值中最大的那个就是整棵树的最大差值，这个取最大值的过程需要在后序遍历的位置进行，直接看解法代码理解吧。

#### 解法代码

```
class Solution {

public:

    int maxAncestorDiff(TreeNode* root) {

        getMinMax(root);

        return res;

    }

private:

    int res = 0;

    // 定义：输入一棵二叉树，返回该二叉树中节点的最小值和最大值，

    // 第一个元素是最小值，第二个值是最大值

    vector<int> getMinMax(TreeNode* root) {

        if (root == nullptr) {

            return {INT_MAX, INT_MIN};

        }

        vector<int> leftMinMax = getMinMax(root->left);

        vector<int> rightMinMax = getMinMax(root->right);

        // 以 root 为根的这棵树的最大值和最小值可以通过左右子树的最大最小值推导出来

        int rootMin = min({root->val, leftMinMax[0], rightMinMax[0]});

        int rootMax = max({root->val, leftMinMax[1], rightMinMax[1]});

        // 在后序位置顺便判断所有差值的最大值

        res = max({res, rootMax - root->val, root->val - rootMin});

        return {rootMin, rootMax};

    }

    int min(initializer_list<int> vals) {

        return *min_element(vals.begin(), vals.end());

    }

    int max(initializer_list<int> vals) {

        return *max_element(vals.begin(), vals.end());

    }

};
```

#### 算法可视化

算法可视化

### 1339\. 分裂二叉树的最大乘积

**1339\. 分裂二叉树的最大乘积** | [力扣](https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/) | [LeetCode](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/)

给你一棵二叉树，它的根为 `root` 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。

由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/02/02/sample_1_1699.png)**

```
输入：root = [1,2,3,4,5,6]
输出：110
解释：删除红色的边，得到 2 棵子树，和分别为 11 和 10 。它们的乘积是 110 （11*10）
```

**示例 2：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/02/02/sample_2_1699.png)

```
输入：root = [1,null,2,3,4,null,null,5,6]
输出：90
解释：移除红色的边，得到 2 棵子树，和分别是 15 和 6 。它们的乘积为 90 （15*6）
```

**示例 3：**

```
输入：root = [2,3,9,10,7,8,6,5,4,11,1]
输出：1025
```

**示例 4：**

```
输入：root = [1,1]
输出：1
```

**提示：**

- 每棵树最多有 `50000`  个节点，且至少有  `2` 个节点。
- 每个节点的值在 `[1, 10000]` 之间。

题目来源： [力扣 1339. 分裂二叉树的最大乘积](https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/) 。

#### 基本思路

这里要用到前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过的后序位置的妙用。

题目说的比较繁琐，这道题说的简单些就是：

在二叉树中切出一个小二叉树（子树），计算这个子树节点之和与剩下的节点之和的乘积。

想求最大乘积，那就穷举，把所有可能的切法都穷举一遍，计算乘积。

任何子树的节点之和都可以在后序位置获得，而剩下的其他节点之和就是整棵二叉树的节点之和减去子树节点之和。

所以我们写一个 `getSum` 函数，先执行一遍计算整棵树的节点之和，然后再调用一次利用它的后序位置计算乘积。

#### 解法代码

```
#include <algorithm>

using namespace std;

class Solution {

public:

    int maxProduct(TreeNode* root) {

        // 先利用求和函数得到整棵树的节点之和

        treeSum = getSum(root);

        // 再次调用，利用后序位置计算子树之积

        getSum(root);

        return (int)(res % static_cast<long>(1e9 + 7));

    }

private:

    long res = 0;

    int treeSum = 0;

    int getSum(TreeNode* root) {

        if (root == nullptr) {

            return 0;

        }

        int leftSum = getSum(root->left);

        int rightSum = getSum(root->right);

        int rootSum = leftSum + rightSum + root->val;

        // 后序位置计算乘积

        res = max(res, (long)rootSum * (treeSum - rootSum));

        return rootSum;

    }

};
```

#### 算法可视化

算法可视化

### 1372\. 二叉树中的最长交错路径

**1372\. 二叉树中的最长交错路径** | [力扣](https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree/) | [LeetCode](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/)

给你一棵以 `root` 为根的二叉树，二叉树中的交错路径定义如下：

- 选择二叉树中 **任意** 节点和一个方向（左或者右）。
- 如果前进方向为右，那么移动到当前节点的的右子节点，否则移动到它的左子节点。
- 改变前进方向：左变右或者右变左。
- 重复第二步和第三步，直到你在树中无法继续移动。

交错路径的长度定义为： **访问过的节点数目 - 1** （单个节点的路径长度为 0 ）。

请你返回给定树中最长 **交错路径** 的长度。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/03/07/sample_1_1702.png)**

```
输入：root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
输出：3
解释：蓝色节点为树中最长交错路径（右 -> 左 -> 右）。
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/03/07/sample_2_1702.png)**

```
输入：root = [1,1,1,null,1,null,null,1,1,null,1]
输出：4
解释：蓝色节点为树中最长交错路径（左 -> 右 -> 左 -> 右）。
```

**示例 3：**

```
输入：root = [1]
输出：0
```

**提示：**

- 每棵树最多有 `50000` 个节点。
- 每个节点的值在 `[1, 100]` 之间。

题目来源： [力扣 1372. 二叉树中的最长交错路径](https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维，而且要用到后序位置的妙用。

首先，我们先明确一下名词的含义，便于讲解：

如果一个从上到下的交错路径的开头是从右到左的，称之为「左交错路径」，反之成为「右交错路径」。

这样的话，一个节点 `x` 能够产生的交错路径就能分解到左右子树：

1、 `x` 的左子树的「右交错路径」+ 节点 `x` = `x` 的「左交错路径」

2、 `x` 的右子树的「左交错路径」+ 节点 `x` = `x` 的「右交错路径」

比较 `x` 的左右交错路径，即可算出以 `x` 开头的最长交错路径。

对二叉树上的所有节点计算交错路径长度，即可得到最长的交错路径长度。

所以我们定义一个 `getPathLen` 函数计算并返回一个节点的左右交错路径长度，然后在后序位置上更新全局最大值。

#### 解法代码

```
class Solution {

public:

    int longestZigZag(TreeNode* root) {

        getPathLen(root);

        return res;

    }

private:

    int res = 0;

    // 输入二叉树的根节点 root，返回两个值

    // 第一个是从 root 开始向左走的最长交错路径长度，

    // 第一个是从 root 开始向右走的最长交错路径长度

    vector<int> getPathLen(TreeNode* root) {

        if (root == nullptr) {

            return {-1, -1};

        }

        vector<int> left = getPathLen(root->left);

        vector<int> right = getPathLen(root->right);

        // 后序位置，根据左右子树的交错路径长度推算根节点的交错路径长度

        int rootPathLen1 = left[1] + 1;

        int rootPathLen2 = right[0] + 1;

        // 更新全局最大值

        res = max(res, max(rootPathLen1, rootPathLen2));

        return {rootPathLen1, rootPathLen2};

    }

};
```

#### 算法可视化

算法可视化

### 606\. 根据二叉树创建字符串

**606\. 根据二叉树创建字符串** | [力扣](https://leetcode.cn/problems/construct-string-from-binary-tree/) | [LeetCode](https://leetcode.com/problems/construct-string-from-binary-tree/)

给你二叉树的根节点 `root` ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。

空节点使用一对空括号对 `"()"` 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/05/03/cons1-tree.jpg)
```
输入：root = [1,2,3,4]
输出："1(2(4))(3)"
解释：初步转化后得到 "1(2(4)())(3()())" ，但省略所有不必要的空括号对后，字符串应该是"1(2(4))(3)" 。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/05/03/cons2-tree.jpg)
```
输入：root = [1,2,3,null,4]
输出："1(2()(4))(3)"
解释：和第一个示例类似，但是无法省略第一个空括号对，否则会破坏输入与输出一一映射的关系。
```

**提示：**

- 树中节点的数目范围是 `[1, 10<sup>4</sup>]`
- `-1000 <= Node.val <= 1000`

题目来源： [力扣 606. 根据二叉树创建字符串](https://leetcode.cn/problems/construct-string-from-binary-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维。

我们先明确 `tree2str` 函数的定义，然后利用这个定义生成左右子树的字符串，然后结合 `root` 组装出最后结果。

注意，题目说按照前序遍历的方式组装字符串，但我们必须在后序遍历位置去组装，因为只有那里你才能拿到左右子树的字符串。

#### 解法代码

```
class Solution {

public:

    // 定义：输入以 root 的二叉树，返回描述该二叉树的字符串

    string tree2str(TreeNode* root) {

        // base case

        if (root == nullptr) return "";

        if (root->left == nullptr && root->right == nullptr) {

            return to_string(root->val);

        }

        // 递归生成左右子树的字符串

        string leftStr = tree2str(root->left);

        string rightStr = tree2str(root->right);

        // 后序代码位置

        // 根据左右子树字符串组装出前序遍历的顺序

        // 按题目要求处理 root 只有一边有子树的情况

        if (root->left != nullptr && root->right == nullptr) {

            // 省略空的右子树

            return to_string(root->val) + "(" + leftStr + ")";

        }

        if (root->left == nullptr && root->right != nullptr) {

            // 空的左子树不能省略

            return to_string(root->val) + "()" + "(" + rightStr + ")";

        }

        // 按题目要求处理 root 左右子树都不空的情况

        return to_string(root->val) + "(" + leftStr + ")" + "(" + rightStr + ")";

    }

};
```

#### 算法可视化

算法可视化

### 1443\. 收集树上所有苹果的最少时间

**1443\. 收集树上所有苹果的最少时间** | [力扣](https://leetcode.cn/problems/minimum-time-to-collect-all-apples-in-a-tree/) | [LeetCode](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/)

给你一棵有 `n`  个节点的无向树，节点编号为  `0`  到  `n-1` ，它们中有一些节点有苹果。通过树上的一条边，需要花费 1 秒钟。你从 **节点 0** 出发，请你返回最少需要多少秒，可以收集到所有苹果，并回到节点 0 。

无向树的边由 `edges`  给出，其中  `edges[i] = [from<sub>i</sub>, to<sub>i</sub>]` ，表示有一条边连接 `from`  和  `to<sub>i</sub>` 。除此以外，还有一个布尔数组  `hasApple` ，其中  `hasApple[i] = true`  代表节点  `i`  有一个苹果，否则，节点  `i` 没有苹果。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/05/10/min_time_collect_apple_1.png)**

```
输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
输出：8 
解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/05/10/min_time_collect_apple_2.png)**

```
输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
输出：6
解释：上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
```

**示例 3：**

```
输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
输出：0
```

**提示：**

- `1 <= n <= 10^5`
- `edges.length == n - 1`
- `edges[i].length == 2`
- `0 <= a<sub>i</sub> < b<sub>i</sub> <= n - 1`
- `hasApple.length == n`

题目来源： [力扣 1443. 收集树上所有苹果的最少时间](https://leetcode.cn/problems/minimum-time-to-collect-all-apples-in-a-tree/) 。

#### 基本思路

这里要用到前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过的后序位置的妙用。

题目输入的是若干条边的形式，我们首先需要用 [图论算法基础](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) 中讲到的表示无向图的邻接表来存储这棵多叉树。

构造出了多叉树，这道题显然要用分解问题的思维模式，并利用后序位置的妙用。

为什么？假设你站在这棵树中的某个节点上，你脚底下有多棵子树，你要去这些子树里面找苹果对不对？

你如果知道了在一棵子树中找苹果的最小步数，假设为 `x` ，那么算上你进出这棵子树的 2 步， `x + 2` 就是从你进入这棵子树找苹果的最小步数。

当然，你脚底下可能有多棵子树都有苹果，所以就会有 `x1 + 2, x2 + 2...` 这些结果加起来，不就是在以你这个节点为根的整棵树找苹果的最小步数了么？这分解问题的思路不就出来了么？

把上述思路翻译出来即可，注意递归函数 `collect` 的定义，我们需要对没有苹果的情况给个特殊值，具体看代码吧。

#### 解法代码

```
#include <unordered_map>

#include <unordered_set>

#include <vector>

#include <list>

using namespace std;

class Solution {

    // 邻接表形式，存储着一棵多叉树

    unordered_map<int, vector<int>> graph;

    unordered_set<int> visited;

    vector<bool> hasApple;

public:

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        // 构造多叉树结构

        for (int i = 0; i < n; i++) {

            graph[i] = vector<int>();

        }

        for (const auto& edge : edges) {

            int a = edge[0], b = edge[1];

            graph[a].push_back(b);

            graph[b].push_back(a);

        }

        this->hasApple = hasApple;

        // 根据 collect 函数的定义，返回题目想要的结果

        int res = collect(0);

        return res == -1 ? 0 : res;

    }

    // 定义：遍历以 root 为根的这棵多叉树，返回收集其中的所有苹果所需的最少步数（时间）

    // 如果返回的是 -1，说明以 root 为根的这棵多叉树中没有苹果

    int collect(int root) {

        if (visited.count(root)) {

            return -1;

        }

        visited.insert(root);

        // 去子树看看是否找到了苹果

        int sum = 0;

        for (int child : graph[root]) {

            int subTime = collect(child);

            if (subTime != -1) {

                // 这棵子树中有苹果，从 root 进入和离开这棵子树，需要额外的两步

                sum += subTime + 2;

            }

        }

        // 在后序位置对当前节点的情况和子树返回的信息进行处理：

        if (sum > 0) {

            // 子树中发现苹果，直接返回，sum 已经算上了本节点出入子树的步数

            return sum;

        }

        if (sum == 0 && hasApple[root]) {

            // 子树中没找到苹果，但 root 节点本身就是苹果，需要 0 步

            return 0;

        }

        // 以 root 为根的这棵多叉树中不存在苹果，按照定义返回 -1

        return -1;

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表