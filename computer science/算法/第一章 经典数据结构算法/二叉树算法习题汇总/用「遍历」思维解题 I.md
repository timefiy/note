---
title: 用「遍历」思维解题 I
source: https://labuladong.online/zh/algo/problem-set/binary-tree-traverse-i/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上所有用遍历思维求解的二叉树经典习题（第一部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
一般来说，如果让你在二叉树的「树枝」上做文章，那么用遍历的思维模式解题是比较自然的想法。

### 257\. 二叉树的所有路径

**257\. 二叉树的所有路径** | [力扣](https://leetcode.cn/problems/binary-tree-paths/) | [LeetCode](https://leetcode.com/problems/binary-tree-paths/)

给你一个二叉树的根节点 `root` ，按 **任意顺序** ，返回所有从根节点到叶子节点的路径。

**叶子节点** 是指没有子节点的节点。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/03/12/paths-tree.jpg)
```
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]
```

**示例 2：**

```
输入：root = [1]
输出：["1"]
```

**提示：**

- 树中节点的数目在范围 `[1, 100]` 内
- `-100 <= Node.val <= 100`

题目来源： [力扣 257. 二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

你让我求所有根节点到叶子节点的路径，那我遍历一遍二叉树肯定可以搞定，遍历到叶子节点的时候想办法把路径生成出来就行了。

#### 解法代码

```
#include <vector>

#include <string>

#include <sstream>

using namespace std;

class Solution {

public:

    vector<string> binaryTreePaths(TreeNode* root) {

        // 遍历一遍二叉树就能出结果了

        traverse(root);

        return res;

    }

private:

    // 记录 traverse 函数递归时的路径

    vector<string> path;

    // 记录所有从根节点到叶子节点的路径

    vector<string> res;

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        // root 是叶子节点

        if (root->left == nullptr && root->right == nullptr) {

            path.push_back(to_string(root->val));

            // 将这条路径装入 res

            res.push_back(joinPath(path));

            path.pop_back();

            return;

        }

        // 前序遍历位置

        path.push_back(to_string(root->val));

        // 递归遍历左右子树

        traverse(root->left);

        traverse(root->right);

        // 后序遍历位置

        path.pop_back();

    }

    string joinPath(const vector<string>& path) {

        stringstream ss;

        for (size_t i = 0; i < path.size(); ++i) {

            ss << path[i];

            if (i < path.size() - 1) ss << "->";

        }

        return ss.str();

    }

};
```

#### 算法可视化

算法可视化

### 129\. 求根节点到叶节点数字之和

**129\. 求根节点到叶节点数字之和** | [力扣](https://leetcode.cn/problems/sum-root-to-leaf-numbers/) | [LeetCode](https://leetcode.com/problems/sum-root-to-leaf-numbers/)

给你一个二叉树的根节点 `root` ，树中每个节点都存放有一个 `0` 到 `9` 之间的数字。

每条从根节点到叶节点的路径都代表一个数字：

- 例如，从根节点到叶节点的路径 `1 -> 2 -> 3` 表示数字 `123` 。

计算从根节点到叶节点生成的 **所有数字之和** 。

**叶节点** 是指没有子节点的节点。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/02/19/num1tree.jpg)
```
输入：root = [1,2,3]
输出：25
解释：
从根到叶子节点路径 1->2 代表数字 12
从根到叶子节点路径 1->3 代表数字 13
因此，数字总和 = 12 + 13 = 25
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/02/19/num2tree.jpg)
```
输入：root = [4,9,0,5,1]
输出：1026
解释：
从根到叶子节点路径 4->9->5 代表数字 495
从根到叶子节点路径 4->9->1 代表数字 491
从根到叶子节点路径 4->0 代表数字 40
因此，数字总和 = 495 + 491 + 40 = 1026
```

**提示：**

- 树中节点的数目在范围 `[1, 1000]` 内
- `0 <= Node.val <= 9`
- 树的深度不超过 `10`

题目来源： [力扣 129. 求根节点到叶节点数字之和](https://leetcode.cn/problems/sum-root-to-leaf-numbers/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

你想，让我获取所有路径数字之和，那我递归遍历一遍二叉树，沿路记录下来路径上的数字，到叶子节点的时候求和，不就完事了？

#### 解法代码

```
class Solution {

public:

    int sumNumbers(TreeNode* root) {

        // 遍历一遍二叉树就能出结果

        string path = "";

        int res = 0;

        traverse(root, path, res);

        return res;

    }

    // 二叉树遍历函数

    void traverse(TreeNode* root, string& path, int& res) {

        if (root == nullptr) {

            return;

        }

        // 前序遍历位置，记录节点值

        path += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {

            // 到达叶子节点，累加路径和

            res += stoi(path);

        }

        // 二叉树递归框架，遍历左右子树

        traverse(root->left, path, res);

        traverse(root->right, path, res);

        // 后续遍历位置，撤销节点值

        path.erase(path.length() - 1, 1);

    }

};
```

#### 算法可视化

算法可视化

### 199\. 二叉树的右视图

**199\. 二叉树的右视图** | [力扣](https://leetcode.cn/problems/binary-tree-right-side-view/) | [LeetCode](https://leetcode.com/problems/binary-tree-right-side-view/)

给定一个二叉树的 **根节点** `root` ，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

**示例 1:**

![](https://labuladong.online/images/lc/uploads/2021/02/14/tree.jpg)

```
输入: [1,2,3,null,5,null,4]
输出: [1,3,4]
```

**示例 2:**

```
输入: [1,null,3]
输出: [1,3]
```

**示例 3:**

```
输入: []
输出: []
```

**提示:**

- 二叉树的节点个数的范围是 `[0,100]`
- `-100 <= Node.val <= 100`

题目来源： [力扣 199. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/) 。

#### 基本思路

这题有两个思路：

1、用 BFS 层序遍历算法，每一层的最后一个节点就是二叉树的右侧视图。我们可以把 BFS 反过来，从右往左遍历每一行，进一步提升效率。

2、用 DFS 递归遍历算法，同样需要反过来，先递归 `root.right` 再递归 `root.left` ，同时用 `res` 记录每一层的最右侧节点作为右侧视图。

#### 解法代码

```
#include <vector>

#include <queue>

using namespace std;

class Solution {

public:

    // BFS 层序遍历解法

    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;

        if (root == nullptr) {

            return res;

        }

        // BFS 层序遍历，计算右侧视图

        queue<TreeNode*> q;

        q.push(root);

        // while 循环控制从上向下一层层遍历

        while (!q.empty()) {

            int sz = q.size();

            // 每一层头部就是最右侧的元素

            TreeNode* last = q.front();

            for (int i = 0; i < sz; i++) {

                TreeNode* cur = q.front();

                q.pop();

                // 控制每一层从右向左遍历

                if (cur->right != nullptr) {

                    q.push(cur->right);

                }

                if (cur->left != nullptr) {

                    q.push(cur->left);

                }

            }

            // 每一层的最后一个节点就是二叉树的右侧视图

            res.push_back(last->val);

        }

        return res;

    }

    // DFS 递归遍历解法

    vector<int> rightSideView_DFS(TreeNode* root) {

        res.clear();

        depth = 0;

        traverse(root);

        return res;

    }

private:

    vector<int> res;

    // 记录递归的层数

    int depth = 0;

    // 二叉树遍历函数

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        // 前序遍历位置

        depth++;

        if (res.size() < depth) {

            // 这一层还没有记录值

            // 说明 root 就是右侧视图的第一个节点

            res.push_back(root->val);

        }

        // 注意，这里反过来，先遍历右子树再遍历左子树

        // 这样首先遍历的一定是右侧节点

        traverse(root->right);

        traverse(root->left);

        // 后序遍历位置

        depth--;

    }

};
```

#### 算法可视化

算法可视化

### 988\. 从叶结点开始的最小字符串

**988\. 从叶结点开始的最小字符串** | [力扣](https://leetcode.cn/problems/smallest-string-starting-from-leaf/) | [LeetCode](https://leetcode.com/problems/smallest-string-starting-from-leaf/)

给定一颗根结点为 `root` 的二叉树，树中的每一个结点都有一个 `[0, 25]` 范围内的值，分别代表字母 `'a'` 到 `'z'` 。

返回 ***按字典序最小** 的字符串，该字符串从这棵树的一个叶结点开始，到根结点结束* 。

> 注 **：** 字符串中任何较短的前缀在 **字典序上** 都是 **较小** 的：
> 
> - 例如，在字典序上 `"ab"` 比 `"aba"` 要小。叶结点是指没有子结点的结点。

节点的叶节点是没有子节点的节点。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/02/tree1.png)**

```
输入：root = [0,1,2,3,4,3,4]
输出："dba"
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2019/01/30/tree2.png)

```
输入：root = [25,1,3,1,3,0,2]
输出："adz"
```

**示例 3：**

![](https://labuladong.online/images/lc/uploads/2019/02/01/tree3.png)

```
输入：root = [2,2,1,null,1,0,null,0]
输出："abc"
```

**提示：**

- 给定树的结点数在 `[1, 8500]` 范围内
- `0 <= Node.val <= 25`

题目来源： [力扣 988. 从叶结点开始的最小字符串](https://leetcode.cn/problems/smallest-string-starting-from-leaf/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

代码看起来虽然多，但思路非常简单：用 `path` 维护递归遍历的路径，到达叶子节点的时候判断字典序最小的路径。

不要忘了在叶子节点的时候也要正确维护 `path` 变量，而且要把 StringBuilder 中的字符串反转才是题目想要的答案。

#### 解法代码

```
#include <string>

#include <algorithm>

using namespace std;

class Solution {

public:

    string smallestFromLeaf(TreeNode* root) {

        traverse(root);

        return res;

    }

    

    // 遍历过程中的路径

    string path;

    string res;

    // 二叉树遍历函数

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        if (root->left == nullptr && root->right == nullptr) {

            // 找到叶子结点，比较字典序最小的路径

            // 结果字符串是从叶子向根，所以需要反转

            path.push_back('a' + root->val);

            reverse(path.begin(), path.end());

            

            if (res.empty() || res > path) {

                // 如果字典序更小，则更新 res

                res = path;

            }

            

            // 恢复，正确维护 path 中的元素

            reverse(path.begin(), path.end());

            path.pop_back();

            return;

        }

        

        // 前序位置

        path.push_back('a' + root->val);

        

        traverse(root->left);

        traverse(root->right);

        

        // 后序位置

        path.pop_back();

    }

};
```

#### 算法可视化

算法可视化

### 1022\. 从根到叶的二进制数之和

**1022\. 从根到叶的二进制数之和** | [力扣](https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/) | [LeetCode](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)

给出一棵二叉树，其上每个结点的值都是 `0`  或  `1` 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。

- 例如，如果路径为 `0 -> 1 -> 1 -> 0 -> 1` ，那么它表示二进制数  `01101` ，也就是  `13` 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

返回这些数字之和。题目数据保证答案是一个 **32 位** 整数。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2019/04/04/sum-of-root-to-leaf-binary-numbers.png)
```
输入：root = [1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
```

**示例 2：**

```
输入：root = [0]
输出：0
```

**提示：**

- 树中的节点数在 `[1, 1000]` 范围内
- `Node.val`  仅为 `0` 或 `1`

题目来源： [力扣 1022. 从根到叶的二进制数之和](https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

用 `path` 变量维护每一条从根节点到叶子节点的路径形成的二进制数，到了叶子节点之后将这条路径的二进制数累加到 `res` 中即可。

#### 解法代码

```
class Solution {

public:

    int sumRootToLeaf(TreeNode* root) {

        traverse(root);

        return res;

    }

private:

    int path = 0;

    int res = 0;

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        if (root->left == nullptr && root->right == nullptr) {

            // 叶子节点

            res += path << 1 | root->val;

            return;

        }

        // 前序位置

        path = (path << 1) | root->val;

        traverse(root->left);

        traverse(root->right);

        // 后序位置

        path = path >> 1;

    }

};
```

#### 算法可视化

算法可视化

### 1457\. 二叉树中的伪回文路径

**1457\. 二叉树中的伪回文路径** | [力扣](https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/) | [LeetCode](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/)

给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「 **伪回文** 」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。

请你返回从根到叶子节点的所有路径中 **伪回文** 路径的数目。

**示例 1：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/05/23/palindromic_paths_1.png)

```
输入：root = [2,3,1,3,1,null,1]
输出：2 
解释：上图为给定的二叉树。总共有 3 条从根到叶子的路径：红色路径 [2,3,3] ，绿色路径 [2,1,1] 和路径 [2,3,1] 。
     在这些路径中，只有红色和绿色的路径是伪回文路径，因为红色路径 [2,3,3] 存在回文排列 [3,2,3] ，绿色路径 [2,1,1] 存在回文排列 [1,2,1] 。
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/05/23/palindromic_paths_2.png)**

```
输入：root = [2,1,1,1,3,null,null,null,null,null,1]
输出：1 
解释：上图为给定二叉树。总共有 3 条从根到叶子的路径：绿色路径 [2,1,1] ，路径 [2,1,3,1] 和路径 [2,1] 。
     这些路径中只有绿色路径是伪回文路径，因为 [2,1,1] 存在回文排列 [1,2,1] 。
```

**示例 3：**

```
输入：root = [9]
输出：1
```

**提示：**

- 给定二叉树的节点数目在范围 `[1, 10<sup>5</sup>]` 内
- `1 <= Node.val <= 9`

题目来源： [力扣 1457. 二叉树中的伪回文路径](https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

遍历一遍二叉树就能得到每条路径上的数字，但这题的考点在于，如何判断一组数字是否存在一个回文串组合？

稍加思考不难想到： **如果一组数字中，只有最多一个数字出现的次数为奇数，剩余数字的出现次数均为偶数，那么这组数字可以组成一个回文串** 。

题目说了 `1 <= root.val <= 9` ，所以我们可以用一个大小为 10 的 `count` 数组做计数器来记录每条路径上的元素出现次数，到达叶子节点之后根据元素出现的次数判断是否可以构成回文串。

当然，我们也可以用更巧妙的位运算来实现上述逻辑：

1、首先用到异或运算的特性，1 ^ 1 = 0, 0 ^ 0 = 0, 1 ^ 0 = 1。

2、其次用到 `n & (n - 1)` 去除二进制最后一个 1 的技巧，详见 [东哥教你几招常用的位运算技巧](https://labuladong.online/zh/algo/frequency-interview/bitwise-operation/) 。

我同时实现了这两种方法，供你参考。

#### 解法代码

```
class Solution {

public:

    int pseudoPalindromicPaths(TreeNode* root) {

        traverse(root);

        return res;

    }

    

    // 计数数组，题目说了 1 <= root.val <= 9

    int count[10] = {0};

    int res = 0;

    // 二叉树遍历函数

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        if (root->left == nullptr && root->right == nullptr) {

            // 遇到叶子节点，判断路径是否是伪回文串

            count[root->val]++;

            

            // 如果路径上出现奇数次的数字个数大于 1，

            // 则不可能组成回文串，反之则可以组成回文串

            int odd = 0;

            for (int n : count) {

                if (n % 2 == 1) {

                    odd++;

                }

            }

            if (odd <= 1) {

                res++;

            }

            count[root->val]--;

            return;

        }

        count[root->val]++;

        // 二叉树遍历框架

        traverse(root->left);

        traverse(root->right);

        count[root->val]--;

    }

};

// 用位运算代替数组计数，进一步提升效率

class Solution2 {

public:

    int pseudoPalindromicPaths(TreeNode* root) {

        traverse(root);

        return res;

    }

    // 用位运算记录路径上的元素

    int count = 0;

    int res = 0;

    // 二叉树遍历函数

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        if (root->left == nullptr && root->right == nullptr) {

            // 遇到叶子节点，判断路径是否是伪回文串

            count = count ^ (1 << root->val);

            

            // 判断二进制中只有一位 1，原理见 https://labuladong.online/algo/frequency-interview/bitwise-operation/

            if ((count & (count - 1)) == 0) {

                res++;

            }

            count = count ^ (1 << root->val);

            return;

        }

        count = count ^ (1 << root->val);

        // 二叉树遍历框架

        traverse(root->left);

        traverse(root->right);

        count = count ^ (1 << root->val);

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论(22)

Markdown

Ctrl+Enter 发表

![苏沐秋](https://thirdwx.qlogo.cn/mmopen/vi_32/uWu9LAGcydVju1OvCzjybMnfRXx51KK5bibOzqiaYjVrFvV1ciabMJQSAEuZxTibWhAjBTTH7ZONyKTEiaHgUJgdlmQ/132)

苏沐秋 12 个月前

从回溯回来再看这篇，真的无敌了，感觉就是一个东西。二叉树心法里的遍历前序遍历和后续遍历的时间点该做什么，太无敌了

![蒋政](https://thirdwx.qlogo.cn/mmopen/vi_32/Q0j4TwGTfTJAEDER5XgbF6rgwzdu0O3pLmAdrQUHUWpWqmyFbiaWGNOZwnhQPWaRic2Pv98KF3UD9RyQlHJWMRiaA/132)

蒋政 超过 1 年前

`1740. 找到二叉树中的距离` 中，第49行算出答案也应该终止递归吧？

```
// 此时 left 和 right 有一个为 0，即只找到了一个节点

        // branch 就是到该节点的距离

        int branch = left == 0 ? right : left;

        if (root.val == p || root.val == q) {

            res = branch;

            // 终止递归

            found = true;

            return 789;

        }
```

![湮灭](https://thirdwx.qlogo.cn/mmopen/vi_32/Q0j4TwGTfTIcIiaFaIstAv1wjrsbWPxicow772OvAcuKtx8icDr8qHrE8ctjjPbicQ3rPKxC5dfLaZIjVfSqN7TGtQ/132)

湮灭 超过 1 年前

我也觉得 因为那个时候左边或者右边有值 自己又是个值 应该是找到了

![。](https://thirdwx.qlogo.cn/mmopen/vi_32/CbvwnnrzicDJdfVkicc9nJxqiaILVIRibm5n2ZWxUiaZDHnys1mThkkjFVFqNNrk48230CRl6vM33GMvDwIaUHdV2dA/132)

。 大约 1 年前

988题，可以直接往path头部插入和删除字符，就不用reverse了，类似这样： 选择： path.insert(0,(char)(97+root.val)); 撤销选择： path.delete(0,1);

![111](https://thirdwx.qlogo.cn/mmopen/vi_32/kWI6qt2ibeaQSribQexpKCQWuPAbQSkk5MhCFmWoeQ8pAIQ6ChmpXVGmJR1kGZ2ibgmEDBlHoMpd825ickmCFM2xJEvljEvAjHsMawCy5RSqH4g/132)

111 11 个月前

1022题我的解法（笨笨的解法）

```
class Solution {

public:

    int sumRootToLeaf(TreeNode* root) {

        traverse(root);

        return sum;

    }

    string res;

    long sum =0;

    void traverse(TreeNode*root){

        if(root == nullptr) return;

        res.push_back(root->val + '0'); // 将整型值转换为对应的字符

        if(root->left==nullptr&&root->right==nullptr){

          

            bitset<32> bits(res); // 可以修改数字以适应二进制字符串的位数

            sum += static_cast<long>(bits.to_ulong());

            res.pop_back();

            return;

        }

        

        traverse(root->left);

        traverse(root->right);

        res.pop_back();

    }

};
```

![阿飞](https://thirdwx.qlogo.cn/mmopen/vi_32/DYAIOgq83eobdib6tdOdf8NqV6Qo0EjMfMdp8uuKRd6Xoo06wH1Xe6myJleJQtHuLPVO9ZPFac74Ic7CHn1hLdg/132)

阿飞 大约 1 年前

找到二叉树中的距离这题，我有一个这样的思路：

```
package 数据结构与算法.tree;

import java.util.Iterator;

import java.util.LinkedList;

public class 找到二叉树中的距离1740 {

    /*

    1740. 找到二叉树中的距离 | 力扣 | LeetCode |

给定一棵二叉树的根节点 root 以及两个整数 p 和 q ，返回该二叉树中值为 p 的结点与值为 q 的结点间的 距离 。

两个结点间的 距离 就是从一个结点到另一个结点的路径上边的数目。

提示：

树中结点个数的范围在 [1, 104].

0 <= Node.val <= 109

树中所有结点的值都是唯一的.

p 和q 是树中结点的值.

     */

    public int findDistance(TreeNode root, int p, int q) {

        /*

        我先试一下我的思路：

            1. 先找到 root 到 p 和 q 的路径，记为 pL，qL

            2. 然后相当于找 p 和 q 链表的第一个公共节点一样了，找的同时记录结果

         */

        this.p = p;

        this.q = q;

        // 找 p 和 q 链表的第一个公共节点一样了，找的同时记录结果

        dfs(root);

        Iterator<TreeNode> pIterator = pL.iterator();

        Iterator<TreeNode> qIterator = qL.iterator();

        TreeNode pCur = pL.peekFirst(), qCur = qL.peekFirst();

        while (pCur!=qCur) {

            if (!pIterator.hasNext()) {

                pIterator = qL.iterator();

            }

            if (!qIterator.hasNext()) {

                qIterator = pL.iterator();

            }

            pCur = pIterator.next();

            qCur = qIterator.next();

        }

        return pL.indexOf(pCur) + qL.indexOf(qCur);

    }

    private int p,q;

    private LinkedList<TreeNode> pL;

    private LinkedList<TreeNode> qL;

    private final LinkedList<TreeNode> path = new LinkedList<>();

    private void dfs(TreeNode root) {

        if (root==null) {

            return;

        }

        path.addFirst(root);

        if (root.val==p) {

            pL = new LinkedList<>(path);

        }

        if (root.val==q) {

            qL = new LinkedList<>(path);

        }

        if (pL!=null && qL!=null) {

            return;

        }

        dfs(root.left);

        dfs(root.right);

        path.removeFirst();

    }

    public static void main(String[] args) {

        // 测试用例1: 简单二叉树

        TreeNode root1 = new TreeNode(1,

                new TreeNode(2,

                        new TreeNode(4),

                        new TreeNode(5)

                ),

                new TreeNode(3)

        );

        System.out.println("Test Case 1: " + new 找到二叉树中的距离1740().findDistance(root1, 4, 3)); // 应输出 3

        // 测试用例2: 更复杂的二叉树

        TreeNode root2 = new TreeNode(1,

                new TreeNode(2,

                        new TreeNode(4),

                        new TreeNode(5,

                                new TreeNode(7),

                                new TreeNode(8)

                        )

                ),

                new TreeNode(3,

                        new TreeNode(6),

                        null

                )

        );

        System.out.println("Test Case 2: " + new 找到二叉树中的距离1740().findDistance(root2, 4, 7)); // 应输出 3

        // 测试用例3

        TreeNode root3 = new TreeNode(1,

                new TreeNode(2,

                        new TreeNode(4),

                        new TreeNode(5)

                ),

                new TreeNode(3,

                        new TreeNode(6),

                        new TreeNode(7)

                )

        );

        System.out.println("Test Case 3: " + new 找到二叉树中的距离1740().findDistance(root3, 4, 5)); // 应输出 2

        // 测试用例4: 树中只有一个节点

        TreeNode root4 = new TreeNode(1);

        System.out.println("Test Case 4: " + new 找到二叉树中的距离1740().findDistance(root4, 1, 1)); // 应输出 0

        // 测试用例5: 树中 p 和 q 在同一子树中

        TreeNode root5 = new TreeNode(1,

                new TreeNode(2,

                        new TreeNode(4),

                        new TreeNode(5)

                ),

                new TreeNode(3)

        );

        System.out.println("Test Case 5: " + new 找到二叉树中的距离1740().findDistance(root5, 4, 5)); // 应输出 2

    }

}
```

![0鹰之翱翔0](https://thirdwx.qlogo.cn/mmopen/vi_32/Q0j4TwGTfTICIpmHtSPPmribkza2nfxrUOoogLZ7RbCvRK35q77ams7EBibyfX4WNBDcibl264Hkic0Yv6TjMibYgZg/132)

0鹰之翱翔0 4 个月前

1. 从叶结点开始的最小字符串 代码应该可以更简洁些

```
class Solution:

    def __init__(self):

        self.path = ""

        self.res = None

    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:

        self.traverse(root)

        return self.res

    

    def traverse(self, root):

        if root is None:

            return None

        self.path = chr(ord('a') + root.val) + self.path

        if root.left is None and root.right is None:

            if self.res is None or self.res > self.path:

                self.res = self.path

            

        self.traverse(root.left)

        self.traverse(root.right)

        self.path = self.path[1:]
```

![竹醉](https://thirdwx.qlogo.cn/mmopen/vi_32/LHEy7IyBlmD7bbL8CNrngd8FjzQyKGWlSLia4RyDRkaHSWpaZCuJ6bQqc5HaGv0iak4aOf99zDrI0xUbWoT3XiciaS0OC2Zxibc2QdTgXdJ3DfGI/132)

竹醉 11 个月前

1. 从叶结点开始的最小字符串

叶子节点的判断可以放在前序位置后面,还能少写点代码,源代码重复添加了两次

```
def traverse(self, root):

        if root is None:

            return

        # 前序位置

        self.path = chr(ord('a') + root.val) + self.path

        if root.left is None and root.right is None:

            # 直接使用已经添加过当前节点的path

            if self.res is None or self.path < self.res:

                self.res = self.path

            # 恢复路径

            self.path = self.path[1:]

            return

        self.traverse(root.left)

        self.traverse(root.right)

        # 后序位置

        self.path = self.path[1:]
```

![Bro.回、](https://thirdwx.qlogo.cn/mmopen/vi_32/ia0ovYibK7bUgK8MXRNAns4dmicoC4VwHBMibu73fJDlxTeYibFXwY6W21Z9Brq2tDLdhiajek4bU3uVmH7KyFZ3ww0Pl8QxAfYZZHhiaOF249SWtI/132)

Bro.回、 11 个月前

1. 二叉树中的伪回文路径，以下是我的代码

```
class Solution {

    LinkedList<Integer> path = new LinkedList<>();

    ArrayList<LinkedList<Integer>> list = new ArrayList<>();

    public int pseudoPalindromicPaths (TreeNode root) {

        traverse(root);

        int res = 0;

        for(LinkedList<Integer> l : list){

            HashSet<Integer> hashSet = new HashSet<>();

            for (int i = 0; i < l.size(); i++) {

                if(hashSet.contains(l.get(i))){

                    hashSet.remove(l.get(i));

                }

                else {

                    hashSet.add(l.get(i));

                }

            }

            if(hashSet.size() == 1 || hashSet.size() == 0){

                res++;

            }

        }

        return res;

    }

    void traverse(TreeNode root){

        if(root == null){

            return;

        }

        if(root.left == null && root.right == null){

           path.add(root.val);

           list.add(path);

           path.removeLast();

           return;

        }

        path.add(root.val);

        traverse(root.left);

        traverse(root.right);

        path.removeLast();

    }

}
```

主要思路是：通过path记录当前路径，并通过list记录每条根节点-叶子节点的路径。通过hashSet判断路径是否为伪回文路径（路径中每个元素成对出现or最多有一个单独的元素）。但提交不通过，不知道为什么？

![Yunzhan](https://thirdwx.qlogo.cn/mmopen/vi_32/Q0j4TwGTfTKqiaeiaxt91icGfxEQAxtwQslF7icxd49qaWiaB3Giaj223NvaxolMeVzss0R5hhPrXStq6bxm01mUlREw/132)

Yunzhan 11 个月前

257题关于path的更新时点有一点小的优化建议，个人觉得这样理解可能会更系统化：其实我们只会在进入节点时将root.val加入path，离开时移除。题解中19&22行与26&31行有重复代码，可以优化为下面的写法，即先加入path再判断叶子节点，然后在traverse完左右子树后移除。

```
class Solution {

    List<String> res = new LinkedList<>();

    List<String> path = new LinkedList<>();

    public List<String> binaryTreePaths(TreeNode root) {

        traverse(root);

        return res;

    }

    public void traverse(TreeNode root) {

        if (root == null) {

            return;

        }

        

        path.add(root.val + "");

        if (root.left == null && root.right == null) {

            res.add(String.join("->", path));

        }

        traverse(root.left);

        traverse(root.right);

        path.removeLast();

    }

}
```

Y

Yu Li 8 个月前

我刚刚也在想这个问题。129是先将值加入到path中，再判断是否为叶子节点，这样就不用在if判断中加入val到path中。257是先判断if，再将val加入到 path中，所以需要在if中加入值再移除值。 但是 你上面这个代码，在if判断中加入一个 return就会出现错误：

```
class Solution {

    public List<String> binaryTreePaths(TreeNode root) {

        // 遍历一遍二叉树就能出结果了

        traverse(root);

        return res;

    }

    // 记录 traverse 函数递归时的路径

    LinkedList<String> path = new LinkedList<>();

    // 记录所有从根节点到叶子节点的路径

    LinkedList<String> res = new LinkedList<>();

    void traverse(TreeNode root) {

        if (root == null) {

            return;

        }

        

        // 前序遍历位置

        path.addLast(root.val + "");

        // root 是叶子节点

        if (root.left == null && root.right == null) {

            // 将这条路径装入 res

            res.addLast(String.join("->", path));

            return;

        }

        // 递归遍历左右子树

        traverse(root.left);

        traverse(root.right);

        // 后序遍历位置

        path.removeLast();

    }

}
```

![Mr.Stranger](https://thirdwx.qlogo.cn/mmopen/vi_32/PiajxSqBRaEKvEqExiaIgSwicY6I0I7GmSzFoibm0wMQia4DgpTV02JbWPk3e5QVeNZZVsnWgetY6iaEr2icyBP0eCAjRWSArCzRl7nWGdLHfD6Ql6ycT5nIN0yVg/132)

Mr.Stranger

Mr.Stranger 12 个月前

1. 二叉树中的伪回文路径 count = count ^ (1 << root->val); 为什么要将所有路径值左移一位再异或起来？不能是count=count^(root-val);最后再判定count<=9就可以吗？

![Attention](https://thirdwx.qlogo.cn/mmopen/vi_32/uVCrBHjaSzJKric8xqgoTzOIOB5LnicmobFPs8qI7h5PoL0FamNEj6M8aCs2wKUuCKEK9licHmeHHnLX9TGxSjv0TjddRnHgCtWibiaxoAibY7cW4/132)

Attention 大约 1 年前

想问下各位大佬什么时候应该添加辅助函数，现在做题稍微多一点还是有些感觉，但是还是不能精准的判断什么时候使用辅助函数会更加方便一点？

![你爹](https://thirdwx.qlogo.cn/mmopen/vi_32/PiajxSqBRaEKjNicIDs4WP9hdtKibzSibBqcD5a1uozDiaCesAlqaD4TwPAciawib5pOXZ9Acz2XTcgTuAwFOHt2D02JD695Y2puM7Cb2sb4bvqhh9XmcU4lTqhkw/132)

你爹 9 个月前

至少按二叉树之前讲解的文章来说，分割类的就是不用辅助，因为原函数的返回和子问题的返回应当一致。遍历类的（比如这章习题），就用辅助，因为遍历不需要像分割类把答案往上传，而是有答案了，就更新下全局变量就行。那怎么知道有答案了呢？需要参数 (比如 dfs(root,PATH,LEVEL))。那原函数没有，所以就用到了辅助函数

![谦文](https://thirdwx.qlogo.cn/mmopen/vi_32/ibRY0iaCQdFBybZK0Cw3LW18J1xo05icqlYiclFH25ztBt6KeRasQuHMlss6eAlPTXnHptu6JIOqMmSiaMicEnLoKWqmr4k52iaxMRs0yKu39Ou8fo/132)

谦文 大约 1 年前

`199. 二叉树的右视图` 有个优雅的解法：先序遍历，把访问结果覆盖复制到结果列表中，最右边可见的结点就是列表中最后剩余的值。

```
class Solution {

private:

    vector<int> res;

    void traverse(TreeNode* root, int layer){

        if(!root) return;

        if(res.size()<layer) res.push_back(root->val);

        else res[layer-1] = root->val;

        traverse(root->left, layer+1);

        traverse(root->right, layer+1);

    }

public:

    vector<int> rightSideView(TreeNode* root) {

        traverse(root, 1);

        return res;

    }

};
```

![热爱可抵岁月漫长](https://thirdwx.qlogo.cn/mmopen/vi_32/ia9w3tFtngQJQOF4LFWJiaQxHIlLjbAZQv9k6bJKicaMh5NRiaGVuj1JiatamaLeN2wocWFLG6rg5pYhFzz2hUVDVKw7gW9f30zn4nxnClaMD9QM/132)

热爱可抵岁月漫长 大约 1 年前

**第 1740 题：找到二叉树中的距离** 的另一种思路：搜集 root 到 p 和 q 各自的节点值序列，然后基于两个序列的重合度计算距离

```
func findDistance(root *TreeNode, p int, q int) int {

    // 先搜集出 root 到 p 和 q 的路径上的节点值序列，基于两个序列计算 p 与 q 的距离

    // p 与 q 的在二叉树中的位置关系无外乎两种：在同一棵 root 子树中、不在同一棵 root 子树中

    // p 与 q 的节点序列重合度大于 1，说明不在同一棵子树中，基于该条件即可计算出 p 与 q 的距离

    var path, pathP, pathQ []int

    var dfs func(node *TreeNode)

    dfs = func(node *TreeNode) {

        if node == nil {

            return

        }

        path = append(path, node.Val)

        if node.Val == p {

            pathP = make([]int, len(path))

            copy(pathP, path)

        }

        if node.Val == q {

            pathQ = make([]int, len(path))

            copy(pathQ, path)

        }

        if len(pathP) > 0 && len(pathQ) > 0 {

            return

        }

        dfs(node.Left)

        dfs(node.Right)

        path = path[:len(path)-1]

    }

    dfs(root)

    var duplicatedNodes int

    for i1, i2 := 0, 0; i1 < len(pathP) && i2 < len(pathQ); i1, i2 = i1+1, i2+1 {

        if pathP[i1] != pathQ[i2] {

            break

        }

        duplicatedNodes++

    }

    // p 到 root 的边：len(pathP) - 1

    distP := len(pathP) - 1

    // q 到 root 的边：len(pathQ) - 1

    distQ := len(pathQ) - 1

    // p 与 q 重复的边：duplicatedNodes - 1

    dupDist := duplicatedNodes - 1

    // 仅有一个重复节点，说明 p 和 q 不在同一棵 root 子树中

    if duplicatedNodes == 1 {

        return distP + distQ

    } else {

        return distP + distQ - 2*dupDist

    }

}
```

![负一](https://thirdwx.qlogo.cn/mmopen/vi_32/PiajxSqBRaELK9iaEOaTaSK8YqcSHnC2SlbFRXSUgVEcsmZib1HaYpLSzkW38nic8MLeBIjuqp1zUbWCJRYGAbGpsEKdiaFI6bjKsqKEYz3xV7lHGesiaYYjU1uA/132)

负一 大约 1 年前

1740没会员，但是是不是能分别找到string形式的p和q路径，然后for循环找它们p和q的共同部分，最后（p-共同部分）+（q-共同部分）。就可以得出答案

![So，Ready](https://thirdwx.qlogo.cn/mmopen/vi_32/DYAIOgq83epwsQTwpjv4qsfYpukAibz5qn8BMHkIICFnxqRf0qeVLALqnoGfuHpB7kWjy1rljOqbVSaX1hE9AibThColyfW1rjBS0BaMwJyqsIkGuMuC6ztA/132)

So，Ready 超过 1 年前

LeetCode 988 我改进了一下，这样写会简单一些

```
class Solution {

    StringBuilder res;

    public String smallestFromLeaf(TreeNode root) {

        traverse(root, new StringBuilder());

        return res.toString();

    }

    private void traverse(TreeNode node, StringBuilder path) {

        if (node == null) {

            return;

        }

        path.append((char) (node.val + 'a'));

        // 当前是叶子节点时，再比较当前 path 生成的 string 是否更小

        if (node.left == null && node.right == null) {

            path.reverse();

            if ((res == null || res.compareTo(path) > 0)) {

                res = new StringBuilder(path);

            }

            path.reverse();

        }

        traverse(node.left, path);

        traverse(node.right, path);

        path.deleteCharAt(path.length() - 1);

    }

}
```

![iaqg](https://thirdwx.qlogo.cn/mmopen/vi_32/fQ3FN0SaKVbdxQe50ZZKDRr5ejgbYLRluC5kPPqQicXxuktC99DlCxODPufdlhvvqHPWwPuXIibpp1IsR8xrfBdBT3csMUfZ4CoxriascdVbSU/132)

iaqg 超过 1 年前

1. 二叉树中的伪回文路径 可以直接用异或来判断奇偶

```
self.count[root.val] = self.count[root.val] ^ 1

        if root.left is None and root.right is None:

            if sum(self.count) <=1:

                self.res += 1

            self.count[root.val] = self.count[root.val] ^ 1

            return
```

![Nightglow8088](https://avatars.githubusercontent.com/u/88631467?v=4)

Nightglow8088

Nightglow8088 超过 1 年前

关于1740我的想法

```
class Solution {

    ArrayList<Integer> arrayList = new ArrayList<>();

    

    public int findDistance(TreeNode root, int p, int q) {

        if(p==q){

            return 0;

        }

        TreeNode rootNode=root;

        TreeNode lcaNode= find(root, p, q,-1);

        // lca为root 垮了root的左右两个子树

        if(lcaNode.val==rootNode.val){

            return arrayList.get(0)+arrayList.get(1);

        }

        //p/q其中一个就是lca 直接减

        else if (lcaNode.val ==q || lcaNode.val==p){

            return Math.abs( arrayList.get(0)-arrayList.get(1) );

        }

        //同layer 并且在一个root的左右两边

        else if( (lcaNode.left.val==p && lcaNode.right.val==q) || (lcaNode.left.val==q && lcaNode.right.val==p) ){

            return 2;

        }

        // 在root的左或右同一侧 直接减

        return Math.abs( arrayList.get(0)-arrayList.get(1) );

        

    }

    public TreeNode find(TreeNode root, int p, int q,int layer) {

        if(root==null){

            return null;

        }

        layer++;

        TreeNode left = find(root.left,p,q,layer);

        TreeNode right = find(root.right,p,q,layer);

        //找到P或者q了

        if(root.val==p || root.val==q){

            arrayList.add(layer);

            return root;

        }

        //left和right都有值 那么当前就是lca

        if(left!=null && right!=null){

            return root;

        }

        //继续往上翻

        return left!=null?left:right;

        

    }

}
```

该评论已被折叠