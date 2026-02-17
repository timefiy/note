---
title: "二叉搜索树经典例题 I"
source: "https://labuladong.online/zh/algo/problem-set/bst1/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文汇总了 力扣/LeetCode 上所有二叉搜索树的经典习题（第一部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。"
tags:
  - "clippings"
---
下面列出的 BST 题目主要考察 BST 左小右大、中序遍历有序的特点。

**99\. 恢复二叉搜索树** | [力扣](https://leetcode.cn/problems/recover-binary-search-tree/) | [LeetCode](https://leetcode.com/problems/recover-binary-search-tree/)

给你二叉搜索树的根节点 `root` ，该树中的 **恰好** 两个节点的值被错误地交换。 *请在不改变其结构的情况下，恢复这棵树* 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/10/28/recover1.jpg)
```
输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 的左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/10/28/recover2.jpg)
```
输入：root = [3,1,4,null,null,2]
输出：[2,1,4,null,null,3]
解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
```

**提示：**

- 树上节点的数目在范围 `[2, 1000]` 内
- `-2<sup>31</sup> <= Node.val <= 2<sup>31</sup> - 1`

**进阶：** 使用 `O(n)` 空间复杂度的解法很容易实现。你能想出一个只使用 `O(1)` 空间的解决方案吗？

题目来源： [力扣 99. 恢复二叉搜索树](https://leetcode.cn/problems/recover-binary-search-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维模式。

得益于二叉搜索树左小右大的特性，一个重要性质是：二叉搜索树的中序遍历结果有序。

题目说有两个节点的值反了，也就是说中序遍历结果不再是有序的，有两个元素的位置反了。

那么我们在中序遍历的时候找到破坏有序性的这两个元素，交换它们即可。

![](https://labuladong.online/images/algo/brief-extra/1.jpg)

#### 解法代码

```
#include <climits>

class Solution {

public:

    // 分别记录这两个被交换的节点

    TreeNode* first = nullptr;

    TreeNode* second = nullptr;

    // 判断中序遍历的有序性

    TreeNode* prev = new TreeNode(INT_MIN);

    void recoverTree(TreeNode* root) {

        inorderTraverse(root);

        int temp = first->val;

        first->val = second->val;

        second->val = temp;

    }

private:

    void inorderTraverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        inorderTraverse(root->left);

        // 中序代码位置，找出那两个节点

        if (root->val < prev->val) {

            // root 不符合有序性

            if (first == nullptr) {

                // 第一个错位节点是 prev

                first = prev;

            }

            // 第二个错位节点是 root

            second = root;

        }

        prev = root;

        inorderTraverse(root->right);

    }

};
```

#### 算法可视化

**669\. 修剪二叉搜索树** | [力扣](https://leetcode.cn/problems/trim-a-binary-search-tree/) | [LeetCode](https://leetcode.com/problems/trim-a-binary-search-tree/)

给你二叉搜索树的根节点 `root` ，同时给定最小边界 `low` 和最大边界 `high` 。通过修剪二叉搜索树，使得所有节点的值在 `[low, high]` 中。修剪树 **不应该** 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 **唯一的答案** 。

所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/09/09/trim1.jpg)
```
输入：root = [1,0,2], low = 1, high = 2
输出：[1,null,2]
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/09/09/trim2.jpg)
```
输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
输出：[3,2,null,1]
```

**提示：**

- 树中节点数在范围 `[1, 10<sup>4</sup>]` 内
- `0 <= Node.val <= 10<sup>4</sup>`
- 树中每个节点的值都是 **唯一** 的
- 题目数据保证输入是一棵有效的二叉搜索树
- `0 <= low <= high <= 10<sup>4</sup>`

题目来源： [力扣 669. 修剪二叉搜索树](https://leetcode.cn/problems/trim-a-binary-search-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维。

明确了递归函数的定义之后进行思考，如果一个节点的值没有落在 `[lo, hi]` 中，有两种情况：

1、 **`root.val < lo` ，这种情况下 `root` 节点本身和 `root` 的左子树全都是小于 `lo` 的，都需要被剪掉** 。

2、 **`root.val > hi` ，这种情况下 `root` 节点本身和 `root` 的右子树全都是大于 `hi` 的，都需要被剪掉** 。

#### 解法代码

```
class Solution {

public:

    // 定义：删除 BST 中小于 low 和大于 high 的所有节点，返回结果 BST

    TreeNode* trimBST(TreeNode* root, int low, int high) {

        if (root == nullptr) return nullptr;

        if (root->val < low) {

            // 直接返回 root.right

            // 等于删除 root 以及 root 的左子树

            return trimBST(root->right, low, high);

        }

        if (root->val > high) {

            // 直接返回 root.left

            // 等于删除 root 以及 root 的右子树

            return trimBST(root->left, low, high);

        }

        // 闭区间 [lo, hi] 内的节点什么都不做

        root->left = trimBST(root->left, low, high);

        root->right = trimBST(root->right, low, high);

        return root;

    }

};
```

#### 算法可视化

### 671\. 二叉树中第二小的节点

**671\. 二叉树中第二小的节点** | [力扣](https://leetcode.cn/problems/second-minimum-node-in-a-binary-tree/) | [LeetCode](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/)

给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 `2`  或  `0` 。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。

更正式地说，即 `root.val = min(root.left.val, root.right.val)` 总成立。

给出这样的一个二叉树，你需要输出所有节点中的 **第二小的值** 。

如果第二小的值不存在的话，输出 -1 **。**

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/10/15/smbt1.jpg)
```
输入：root = [2,2,5,null,null,5,7]
输出：5
解释：最小的值是 2 ，第二小的值是 5 。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/10/15/smbt2.jpg)
```
输入：root = [2,2,2]
输出：-1
解释：最小的值是 2, 但是不存在第二小的值。
```

**提示：**

- 树中节点数目在范围 `[1, 25]` 内
- `1 <= Node.val <= 2<sup>31</sup> - 1`
- 对于树中每个节点 `root.val == min(root.left.val, root.right.val)`

题目来源： [力扣 671. 二叉树中第二小的节点](https://leetcode.cn/problems/second-minimum-node-in-a-binary-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维。

这题很有意思，按照这棵二叉树的特性，根节点无疑是最小的那个元素，但问题是第二小的那个元素在哪里呢？

如果根节点的左右子节点的值不同，根节点的值就是较小的那个节点（假设是左子节点）的值，那么较大的那个节点（右子节点）的值是不是就一定是第二小的那个元素？

不一定，第二小的值也可能在左子树中，这个节点是左子树中第二小的节点：

![](https://labuladong.online/images/algo/brief-extra/671_1.png)

类似的道理，如果根节点的左右子节点相同，那么需要把左右子树的第二小元素计算出来，比较其中较小的元素，作为整棵树的第二小元素：

![](https://labuladong.online/images/algo/brief-extra/671_2.png)

如何计算子树中的第二小元素？函数 `findSecondMinimumValue` 就是干这个的，递归调用子树即可算出来。

#### 解法代码

```
class Solution {

public:

    // 定义：输入一棵二叉树，返回这棵二叉树中第二小的节点值

    int findSecondMinimumValue(TreeNode* root) {

        if (root->left == nullptr && root->right == nullptr) {

            return -1;

        }

        // 左右子节点中不同于 root.val 的那个值可能是第二小的值

        int left = root->left->val, right = root->right->val;

        // 如果左右子节点都等于 root.val，则去左右子树递归寻找第二小的值

        if (root->val == root->left->val) {

            left = findSecondMinimumValue(root->left);

        }

        if (root->val == root->right->val) {

            right = findSecondMinimumValue(root->right);

        }

        if (left == -1) {

            return right;

        }

        if (right == -1) {

            return left;

        }

        // 如果左右子树都找到一个第二小的值，更小的那个是整棵树的第二小元素

        return std::min(left, right);

    }

};
```

#### 算法可视化

算法可视化

**501\. 二叉搜索树中的众数** | [力扣](https://leetcode.cn/problems/find-mode-in-binary-search-tree/) | [LeetCode](https://leetcode.com/problems/find-mode-in-binary-search-tree/)

给你一个含重复值的二叉搜索树（BST）的根节点 `root` ，找出并返回 BST 中的所有 [众数](https://baike.baidu.com/item/%E4%BC%97%E6%95%B0/44796) （即，出现频率最高的元素）。

如果树中有不止一个众数，可以按 **任意顺序** 返回。

假定 BST 满足如下定义：

- 结点左子树中所含节点的值 **小于等于** 当前节点的值
- 结点右子树中所含节点的值 **大于等于** 当前节点的值
- 左子树和右子树都是二叉搜索树

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/03/11/mode-tree.jpg)
```
输入：root = [1,null,2,2]
输出：[2]
```

**示例 2：**

```
输入：root = [0]
输出：[0]
```

**提示：**

- 树中节点的数目在范围 `[1, 10<sup>4</sup>]` 内
- `-10<sup>5</sup> <= Node.val <= 10<sup>5</sup>`

**进阶：** 你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

题目来源： [力扣 501. 二叉搜索树中的众数](https://leetcode.cn/problems/find-mode-in-binary-search-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

BST 的中序遍历有序，在中序遍历的位置做一些判断逻辑和操作有序数组差不多，很容易找出众数。

#### 解法代码

```
#include <vector>

using namespace std;

class Solution {

public:

    vector<int> mode;

    TreeNode* prev = nullptr;

    // 当前元素的重复次数

    int curCount = 0;

    // 全局的最长相同序列长度

    int maxCount = 0;

    vector<int> findMode(TreeNode* root) {

        // 执行中序遍历

        traverse(root);

        vector<int> res(mode.begin(), mode.end());

        return res;

    }

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        traverse(root->left);

        // 中序遍历位置

        if (prev == nullptr) {

            // 初始化

            curCount = 1;

            maxCount = 1;

            mode.push_back(root->val);

        } else {

            if (root->val == prev->val) {

                // root.val 重复的情况

                curCount++;

                if (curCount == maxCount) {

                    // root.val 是众数

                    mode.push_back(root->val);

                } else if (curCount > maxCount) {

                    // 更新众数

                    mode.clear();

                    maxCount = curCount;

                    mode.push_back(root->val);

                }

            } else {

                // root.val 不重复的情况

                curCount = 1;

                if (curCount == maxCount) {

                    mode.push_back(root->val);

                }

            }

        }

        // 别忘了更新 prev

        prev = root;

        traverse(root->right);

    }

};
```

#### 算法可视化

### 530\. 二叉搜索树的最小绝对差

**530\. 二叉搜索树的最小绝对差** | [力扣](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/) | [LeetCode](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)

给你一个二叉搜索树的根节点 `root` ，返回 **树中任意两不同节点值之间的最小差值** 。

差值是一个正数，其数值等于两值之差的绝对值。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/02/05/bst1.jpg)
```
输入：root = [4,2,6,1,3]
输出：1
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/02/05/bst2.jpg)
```
输入：root = [1,0,48,null,null,12,49]
输出：1
```

**提示：**

- 树中节点的数目范围是 `[2, 10<sup>4</sup>]`
- `0 <= Node.val <= 10<sup>5</sup>`

**注意：** 本题与 783 [https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/](https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/) 相同

题目来源： [力扣 530. 二叉搜索树的最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

记住，看到一棵 BST，你就把它理解是一个有序数组就行了，只是遍历方式不同罢了。所以这道题的思路就很简单，用中序遍历遍历一遍 BST 的所有节点得到有序结果，然后在遍历过程中计算最小差值即可。

#### 解法代码

```
class Solution {

public:

    int getMinimumDifference(TreeNode* root) {

        traverse(root);

        return res;

    }

    TreeNode* prev = nullptr;

    int res = INT_MAX;

    // 遍历函数

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        traverse(root->left);

        // 中序遍历位置

        if (prev != nullptr) {

            res = min(res, root->val - prev->val);

        }

        prev = root;

        traverse(root->right);

    }

};
```

#### 算法可视化

算法可视化

### 653\. 两数之和 IV - 输入二叉搜索树

**653\. 两数之和 IV - 输入二叉搜索树** | [力扣](https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/) | [LeetCode](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

给定一个二叉搜索树 `root` 和一个目标结果 `k` ，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 `true` 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/09/21/sum_tree_1.jpg)
```
输入: root = [5,3,6,2,4,null,7], k = 9
输出: true
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/09/21/sum_tree_2.jpg)
```
输入: root = [5,3,6,2,4,null,7], k = 28
输出: false
```

**提示:**

- 二叉树的节点个数的范围是 `[1, 10<sup>4</sup>]`.
- `-10<sup>4</sup> <= Node.val <= 10<sup>4</sup>`
- 题目数据保证，输入的 `root` 是一棵 **有效** 的二叉搜索树
- `-10<sup>5</sup> <= k <= 10<sup>5</sup>`

题目来源： [力扣 653. 两数之和 IV - 输入二叉搜索树](https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/) 。

#### 基本思路

这道题的思路蛮多的，我们就利用 BST 中序遍历有序这个性质外加 [一个函数秒杀 nSum 问题](https://labuladong.online/zh/algo/practice-in-action/nsum/) 中的双指针思路来解决吧。

#### 解法代码

```
class Solution {

public:

    bool findTarget(TreeNode* root, int k) {

        // 转化成有序数组

        vector<int> arr = traverse(root);

        // 有序数组中的左右双指针

        int i = 0, j = arr.size() - 1;

        while (i < j) {

            int sum = arr[i] + arr[j];

            if (sum < k) {

                // sum 调大一点

                i++;

            } else if (sum > k) {

                // sum 调小一点

                j--;

            } else {

                return true;

            }

        }

        return false;

    }

    // 返回中序遍历结果

    vector<int> traverse(TreeNode* root) {

        vector<int> res;

        if (root == nullptr) {

            return res;

        }

        vector<int> left = traverse(root->left);

        res.insert(res.end(), left.begin(), left.end());

        res.push_back(root->val);

        vector<int> right = traverse(root->right);

        res.insert(res.end(), right.begin(), right.end());

        return res;

    }

};
```

#### 算法可视化

算法可视化

**1008\. 前序遍历构造二叉搜索树** | [力扣](https://leetcode.cn/problems/construct-binary-search-tree-from-preorder-traversal/) | [LeetCode](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

给定一个整数数组，它表示BST(即 **二叉搜索树** )的 **先** **序遍历** ，构造树并返回其根。

**保证** 对于给定的测试用例，总是有可能找到具有给定需求的二叉搜索树。

**二叉搜索树** 是一棵二叉树，其中每个节点， `Node.left` 的任何后代的值 **严格小于** `Node.val`, `Node.right` 的任何后代的值 **严格大于** `Node.val` 。

二叉树的 **前序遍历** 首先显示节点的值，然后遍历 `Node.left` ，最后遍历 `Node.right` 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2019/03/06/1266.png)

```
输入：preorder = [8,5,1,7,10,12]
输出：[8,5,10,1,7,null,12]
```

**示例 2:**

```
输入: preorder = [1,3]
输出: [1,null,3]
```

**提示：**

- `1 <= preorder.length <= 100`
- `1 <= preorder[i] <= 10^8`
- `preorder` 中的值 **互不相同**

题目来源： [力扣 1008. 前序遍历构造二叉搜索树](https://leetcode.cn/problems/construct-binary-search-tree-from-preorder-traversal/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维。

前文 [二叉树的花式构造](https://labuladong.online/zh/algo/data-structure/binary-tree-part2/) 和 [二叉树的序列化和反序列化](https://labuladong.online/zh/algo/data-structure/serialize-and-deserialize-binary-tree/) 说过，生成二叉树的题目，无非就是先生成根节点，然后递归生成左右子树，最后把根节点和左右子树连接起来。 **具体区别在于你如何找到根节点，如何划分左右子树** 。

根据前序遍历的特点是，根节点在第一位，后面接着左子树和右子树；BST 的特点，左子树都比根节点的值小，右子树都比根节点的值大。

所以如何找到根节点？前序遍历的第一个就是根节点。

如何找到左右子树？比根节点小的就是左子树的节点，比根节点大的就是右子树的节点。

最后，确定清楚 `build` 函数的定义，利用这个函数递归生成 BST 即可。

#### 解法代码

```
#include <vector>

class Solution {

public:

    TreeNode* bstFromPreorder(std::vector<int>& preorder) {

        return build(preorder, 0, preorder.size() - 1);

    }

    // 定义：将 preorder[start..end] 区间内的元素生成 BST，并返回根节点

    TreeNode* build(std::vector<int>& preorder, int start, int end) {

        if (start > end) {

            return nullptr;

        }

        // 根据前序遍历的特点，根节点在第一位，后面接着左子树和右子树

        int rootVal = preorder[start];

        TreeNode* root = new TreeNode(rootVal);

        // 根据 BST 的特点，左子树都比根节点的值小，右子树都比根节点的值大

        // p 就是左右子树的分界点

        int p = start + 1;

        while (p <= end && preorder[p] < rootVal) {

            p++;

        }

        // [start+1, p-1] 区间内是左子树元素

        root->left = build(preorder, start + 1, p - 1);

        // [p, end] 区间内是右子树元素

        root->right = build(preorder, p, end);

        return root;

    }

};
```

#### 算法可视化

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表