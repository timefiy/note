---
title: "利用后序位置解题 I"
source: "https://labuladong.online/zh/algo/problem-set/binary-tree-post-order-i/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文汇总了 力扣/LeetCode 上所有利用二叉树后序位置求解的经典习题（第一部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。"
tags:
  - "clippings"
---
有些题目，你按照拍脑袋的方式去做，可能发现需要在递归代码中调用其他递归函数计算字数的信息。一般来说，出现这种情况时你可以考虑用后序遍历的思维方式来优化算法，利用后序遍历传递子树的信息，避免过高的时间复杂度。

### 110\. 平衡二叉树

**110\. 平衡二叉树** | [力扣](https://leetcode.cn/problems/balanced-binary-tree/) | [LeetCode](https://leetcode.com/problems/balanced-binary-tree/)

给定一个二叉树，判断它是否是 平衡二叉树

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/10/06/balance_1.jpg)
```
输入：root = [3,9,20,null,null,15,7]
输出：true
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/10/06/balance_2.jpg)
```
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
```

**示例 3：**

```
输入：root = []
输出：true
```

**提示：**

- 树中的节点数在范围 `[0, 5000]` 内
- `-10<sup>4</sup> <= Node.val <= 10<sup>4</sup>`

题目来源： [力扣 110. 平衡二叉树](https://leetcode.cn/problems/balanced-binary-tree/) 。

#### 基本思路

这里要用到前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过的后序位置的妙用。

一般的拍脑袋思路是，遍历二叉树，然后对每一个节点计算左右的最大高度。

但是计算一棵二叉树的最大深度也需要递归遍历这棵树的所有节点，如果对每个节点都算一遍最大深度，时间复杂度是比较高的。

所以最好的解法是反过来思考，只计算一次最大深度，计算的过程中在后序遍历位置顺便判断二叉树是否平衡：

对于每个节点，先算出来左右子树的最大高度，然后在后序遍历的位置根据左右子树的最大高度判断平衡性。

#### 解法代码

```
class Solution {

public:

    bool isBalanced(TreeNode* root) {

        checkBalanced(root);

        return balanced;

    }

private:

    // 记录二叉树是否平衡

    bool balanced = true;

    // 输入一个节点，返回以该节点为根的二叉树的最大深度

    int checkBalanced(TreeNode* root) {

        if (root == nullptr) {

            return 0;

        }

        

        // if (!balanced) {

        // 随便返回一个值即可，旨在结束递归

        //     return -666;

        // }

        int leftMaxDepth = checkBalanced(root->left);

        int rightMaxDepth = checkBalanced(root->right);

        // 后序遍历位置

        // 如果左右最大深度大于 1，就不是平衡二叉树

        if (abs(rightMaxDepth - leftMaxDepth) > 1) {

            balanced = false;

        }

        return 1 + max(leftMaxDepth, rightMaxDepth);

    }

};
```

#### 算法可视化

算法可视化

### 508\. 出现次数最多的子树元素和

**508\. 出现次数最多的子树元素和** | [力扣](https://leetcode.cn/problems/most-frequent-subtree-sum/) | [LeetCode](https://leetcode.com/problems/most-frequent-subtree-sum/)

给你一个二叉树的根结点 `root` ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。

一个结点的 **「子树元素和」** 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/04/24/freq1-tree.jpg)

```
输入: root = [5,2,-3]
输出: [2,-3,4]
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/04/24/freq2-tree.jpg)

```
输入: root = [5,2,-5]
输出: [2]
```

**提示:**

- 节点数在 `[1, 10<sup>4</sup>]` 范围内
- `-10<sup>5</sup> <= Node.val <= 10<sup>5</sup>`

题目来源： [力扣 508. 出现次数最多的子树元素和](https://leetcode.cn/problems/most-frequent-subtree-sum/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维，同时要利用后序位置来计算答案。

`sum` 函数根据子树的元素和推导出原树的所有元素和，只不过在后序遍历位置添加一些统计工作，便于找出出现频率最高的子树和。

#### 解法代码

```
#include <vector>

#include <unordered_map>

using namespace std;

class Solution {

    // sum -> count

    unordered_map<int, int> sumToCount;

public:

    vector<int> findFrequentTreeSum(TreeNode* root) {

        // 遍历二叉树，记录所有子树和及出现频率

        sum(root);

        // 找到最大的出现频率

        int maxCount = 0;

        for (auto& count : sumToCount) {

            maxCount = max(maxCount, count.second);

        }

        // 找到最大出现频率对应的的子树和

        vector<int> res;

        for (auto& key : sumToCount) {

            if (key.second == maxCount) {

                res.push_back(key.first);

            }

        }

        // The following comment is from the original Java code and is included for consistency.

        // It does not apply to C++ code since we are using a vector instead of an array.

        // 转化为 Java 数组

        // Note: In C++, the vector 'res' is directly returned and does not require conversion.

        return res;

    }

    // 定义：输入一个节点，返回以该节点为根的二叉树所有节点之和

    int sum(TreeNode* root) {

        if (root == nullptr) {

            return 0;

        }

        int leftSum = sum(root->left);

        int rightSum = sum(root->right);

        int res = root->val + leftSum + rightSum;

        // 后序遍历位置，顺手记录子树和对应的频率

        sumToCount[res] = sumToCount.count(res) ? sumToCount[res] + 1 : 1;

        return res;

    }

};
```

#### 算法可视化

算法可视化

### 563\. 二叉树的坡度

**563\. 二叉树的坡度** | [力扣](https://leetcode.cn/problems/binary-tree-tilt/) | [LeetCode](https://leetcode.com/problems/binary-tree-tilt/)

给你一个二叉树的根节点 `root` ，计算并返回 **整个树** 的坡度 。

一个树的 **节点的坡度** 定义即为，该节点左子树的节点之和和右子树节点之和的 **差的绝对值** 。如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。空结点的坡度是 0 。

**整个树** 的坡度就是其所有节点的坡度之和。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/10/20/tilt1.jpg)
```
输入：root = [1,2,3]
输出：1
解释：
节点 2 的坡度：|0-0| = 0（没有子节点）
节点 3 的坡度：|0-0| = 0（没有子节点）
节点 1 的坡度：|2-3| = 1（左子树就是左子节点，所以和是 2 ；右子树就是右子节点，所以和是 3 ）
坡度总和：0 + 0 + 1 = 1
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/10/20/tilt2.jpg)
```
输入：root = [4,2,9,3,5,null,7]
输出：15
解释：
节点 3 的坡度：|0-0| = 0（没有子节点）
节点 5 的坡度：|0-0| = 0（没有子节点）
节点 7 的坡度：|0-0| = 0（没有子节点）
节点 2 的坡度：|3-5| = 2（左子树就是左子节点，所以和是 3 ；右子树就是右子节点，所以和是 5 ）
节点 9 的坡度：|0-7| = 7（没有左子树，所以和是 0 ；右子树正好是右子节点，所以和是 7 ）
节点 4 的坡度：|(3+5+2)-(9+7)| = |10-16| = 6（左子树值为 3、5 和 2 ，和是 10 ；右子树值为 9 和 7 ，和是 16 ）
坡度总和：0 + 0 + 0 + 2 + 7 + 6 = 15
```

**示例 3：**

![](https://labuladong.online/images/lc/uploads/2020/10/20/tilt3.jpg)
```
输入：root = [21,7,14,1,1,2,2,3,3]
输出：9
```

**提示：**

- 树中节点数目的范围在 `[0, 10<sup>4</sup>]` 内
- `-1000 <= Node.val <= 1000`

题目来源： [力扣 563. 二叉树的坡度](https://leetcode.cn/problems/binary-tree-tilt/) 。

#### 基本思路

这里要用到前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过的后序位置的妙用。

`sum` 函数记录二叉树的节点之和，在后序位置顺便计算二叉树的「坡度」即可。

#### 解法代码

```
class Solution {

public:

    int findTilt(TreeNode* root) {

        sum(root);

        return res;

    }

private:

    int res = 0;

    // 定义：输入一棵二叉树，返回这棵二叉树所有元素的和

    int sum(TreeNode* root) {

        if (root == nullptr) {

            return 0;

        }

        int leftSum = sum(root->left);

        int rightSum = sum(root->right);

        // 后序位置

        res += abs(leftSum - rightSum);

        return leftSum + rightSum + root->val;

    }

};
```

#### 算法可视化

算法可视化

### 814\. 二叉树剪枝

**814\. 二叉树剪枝** | [力扣](https://leetcode.cn/problems/binary-tree-pruning/) | [LeetCode](https://leetcode.com/problems/binary-tree-pruning/)

给你二叉树的根结点 `root`  ，此外树的每个结点的值要么是 `0` ，要么是 `1` 。

返回移除了所有不包含 `1` 的子树的原二叉树。

节点 `node` 的子树为 `node` 本身加上所有 `node` 的后代。

**示例 1：**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png)
```
输入：root = [1,null,0,0,1]
输出：[1,null,0,null,1]
解释：
只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
```

**示例 2：**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png)
```
输入：root = [1,0,1,0,0,0,1]
输出：[1,null,1,null,1]
```

**示例 3：**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png)
```
输入：root = [1,1,0,1,1,0,1,0]
输出：[1,1,0,1,1,null,1]
```

**提示：**

- 树中节点的数目在范围 `[1, 200]` 内
- `Node.val` 为 `0` 或 `1`

题目来源： [力扣 814. 二叉树剪枝](https://leetcode.cn/problems/binary-tree-pruning/) 。

#### 基本思路

建议先做一下 [543\. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/description/) 和 [687\. 最长同值路径](https://leetcode.cn/problems/longest-univalue-path/description/) ，理解后序遍历位置的特殊性。

这道题的难点在于要一直剪枝，直到没有值为 0 的叶子节点为止，只有从后序遍历位置自底向上处理才能获得最高的效率。

#### 解法代码

```
class Solution {

public:

    // 定义：输入一棵二叉树，返回的二叉树叶子节点都是 1

    TreeNode* pruneTree(TreeNode* root) {

        if (root == nullptr) {

            return nullptr;

        }

        // 二叉树递归框架

        root->left = pruneTree(root->left);

        root->right = pruneTree(root->right);

        // 后序遍历位置，判断自己是否是值为 0 的叶子节点

        if (root->val == 0 && root->left == nullptr && root->right == nullptr) {

            // 返回值会被父节点接收，相当于把自己删掉了

            return nullptr;

        }

        // 如果不是，正常返回

        return root;

    }

};
```

#### 算法可视化

算法可视化

### 1325\. 删除给定值的叶子节点

**1325\. 删除给定值的叶子节点** | [力扣](https://leetcode.cn/problems/delete-leaves-with-a-given-value/) | [LeetCode](https://leetcode.com/problems/delete-leaves-with-a-given-value/)

给你一棵以 `root`  为根的二叉树和一个整数  `target`  ，请你删除所有值为  `target` 的 **叶子节点** 。

注意，一旦删除值为 `target`  的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是  `target` ，那么这个节点也应该被删除。

也就是说，你需要重复此过程直到不能继续删除。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/01/16/sample_1_1684.png)**

```
输入：root = [1,2,3,2,null,2,4], target = 2
输出：[1,null,3,null,4]
解释：
上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/01/16/sample_2_1684.png)**

```
输入：root = [1,3,3,3,2], target = 3
输出：[1,3,null,null,2]
```

**示例 3：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/01/16/sample_3_1684.png)**

```
输入：root = [1,2,null,2,null,2], target = 2
输出：[1]
解释：每一步都删除一个绿色的叶子节点（值为 2）。
```

**提示：**

- 树中节点数量的范围是 `[1, 3000]` 。
- `1 <= Node.val, target <= 1000`

题目来源： [力扣 1325. 删除给定值的叶子节点](https://leetcode.cn/problems/delete-leaves-with-a-given-value/) 。

#### 基本思路

删除指定值的叶子节点，其实就是遍历所有的叶子节点，然后判断是否需要删除；删除叶子节点也很简单，return null 让父节点接收即可。

**难点在于他这个删除操作是循环的，一直删到叶子结点不存在 `target` 为止** 。这里要用到前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过的后序位置的妙用了：

一个节点要在后序位置接收左右子树的返回值，才能知道自己的叶子节点是否都被删掉了，以此判断自己是不是变成了叶子节点。

这个考点在 [814\. 二叉树剪枝](https://leetcode.cn/problems/binary-tree-pruning/description/) 中也有体现，没做过的读者建议去做一下，解法的关键点在于利用后序遍历特点，在后序遍历位置每个节点可以直到自己是否需要被删除。

#### 解法代码

```
class Solution {

public:

    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        if (root == nullptr) return nullptr;

        // 二叉树递归框架

        // 如果左右子节点需要被删除，先递归删除它们

        root->left = removeLeafNodes(root->left, target);

        root->right = removeLeafNodes(root->right, target);

        // 后序遍历位置，此时节点 root 直到自己是否需要被删除

        if (root->val == target && root->left == nullptr && root->right == nullptr) {

            return nullptr;

        }

        return root;

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论(3)

Markdown

Ctrl+Enter 发表

![Yuuuuu](https://thirdwx.qlogo.cn/mmopen/vi_32/3eLEXowzDITh7HtkklXC0bkPsWcmxLhElR558AsW1mHb9ltBqYzRtbLzEzmEBfzWJt1S2viaW8J1ZP2sNslruTw/132)

Yuuuuu 12 个月前

前面每篇练习一刷一两天， 越刷越快，到这里，这五题1个小时都做完了。 有点小爽

![小汉同学](https://thirdwx.qlogo.cn/mmopen/vi_32/DYAIOgq83eo9TjyI8CJdt1fSVLQIzXJhoGfgoPQjTORrp182qxJaCbxhHxzTGo0M74DUU0diaTyGnibrChQhpuFw/132)

小汉同学 12 个月前

打卡😀 中间两道题想了很久都没明白，就卡在后序如何拼接返回的左右子树（主要是我把最小问题看成了左中右三节点都存在，应该是只有一个节点，左右都为null）。看了解析，大约矫正了我的想法，最后一题就so easy。

N

Nightglow8088 超过 1 年前

250 java优化版本

```
class Solution {

    int result=0;

    public int countUnivalSubtrees(TreeNode root) {

        if(root == null){

            return 0;

        }

        sameNodeCalculate(root);

        return result;

    }

    public boolean sameNodeCalculate(TreeNode root) {

        if(root == null){

            return true;

        }

        boolean left = sameNodeCalculate(root.left);

        boolean right = sameNodeCalculate(root.right);

        if(!left || !right){

            return false;

        }

        // 检查左右子节点的值是否与当前节点相同

        if (root.left != null && root.left.val != root.val) {

            return false;

        }

        if (root.right != null && root.right.val != root.val) {

            return false;

        }

        result++;

        return true;

        

    }

}
```