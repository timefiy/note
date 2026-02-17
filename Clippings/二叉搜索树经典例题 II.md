---
title: "二叉搜索树经典例题 II"
source: "https://labuladong.online/zh/algo/problem-set/bst2/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文汇总了 力扣/LeetCode 上所有二叉搜索树的经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。"
tags:
  - "clippings"
---
技巧一

二叉搜索树的构造问题，牢记中序遍历的规律（根节点在中心，左小右大）。

**108\. 将有序数组转换为二叉搜索树** | [力扣](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/) | [LeetCode](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

给你一个整数数组 `nums` ，其中元素已经按 **升序** 排列，请你将其转换为一棵 平衡 二叉搜索树。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/02/18/btree1.jpg)
```
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/02/18/btree.jpg)
```
输入：nums = [1,3]
输出：[3,1]
解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
```

**提示：**

- `1 <= nums.length <= 10<sup>4</sup>`
- `-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup>`
- `nums` 按 **严格递增** 顺序排列

题目来源： [力扣 108. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维模式。

二叉树的构建问题遵循固定的套路，构造整棵树可以分解成：先构造根节点，然后构建左右子树。

一个有序数组对于 BST 来说就是中序遍历结果，根节点在数组中心，数组左侧是左子树元素，右侧是右子树元素。

#### 解法代码

```
class Solution {

public:

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return build(nums, 0, nums.size() - 1);

    }

    // 将闭区间 [left, right] 中的元素转化成 BST，返回根节点

    TreeNode* build(vector<int>& nums, int left, int right) {

        if (left > right) {

            // 区间为空

            return nullptr;

        }

        // 构造根节点

        // BST 节点左小右大，中间的元素就是根节点

        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        // 递归构建左子树

        root->left = build(nums, left, mid - 1);

        // 递归构造右子树

        root->right = build(nums, mid + 1, right);

        return root;

    }

};
```

#### 算法可视化

**1382\. 将二叉搜索树变平衡** | [力扣](https://leetcode.cn/problems/balance-a-binary-search-tree/) | [LeetCode](https://leetcode.com/problems/balance-a-binary-search-tree/)

给你一棵二叉搜索树，请你返回一棵 **平衡后** 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。如果有多种构造方法，请你返回任意一种。

如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 `1` ，我们就称这棵二叉搜索树是 **平衡的** 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/08/10/balance1-tree.jpg)

```
输入：root = [1,null,2,null,3,null,4,null,null]
输出：[2,1,3,null,null,null,4]
解释：这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/08/10/balanced2-tree.jpg)

```
输入: root = [2,1,3]
输出: [2,1,3]
```

**提示：**

- 树节点的数目在 `[1, 10<sup>4</sup>]` 范围内。
- `1 <= Node.val <= 10<sup>5</sup>`

题目来源： [力扣 1382. 将二叉搜索树变平衡](https://leetcode.cn/problems/balance-a-binary-search-tree/) 。

#### 基本思路

这题可难可简单，如果要难，就是红黑树左旋右旋那一套，不过真的没必要这么搞。

我们简单点，就是用中序遍历获取 BST 的有序结果，然后用 [108\. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/) 的解法代码，将这个有序数组转化成平衡 BST。

#### 解法代码

```
class Solution {

public:

    TreeNode* balanceBST(TreeNode* root) {

        // 中序遍历获取有序数组

        vector<int> nums = traverse(root);

        // 从有序数组构建 BST

        return build(nums, 0, nums.size() - 1);

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

    // BST 构造函数，见 108. 将有序数组转换为二叉搜索树

    TreeNode* build(vector<int>& nums, int lo, int hi) {

        if (lo > hi) return nullptr;

        int mid = lo + (hi - lo) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums, lo, mid - 1);

        root->right = build(nums, mid + 1, hi);

        return root;

    }

};
```

#### 算法可视化

### 449\. 序列化和反序列化二叉搜索树

**449\. 序列化和反序列化二叉搜索树** | [力扣](https://leetcode.cn/problems/serialize-and-deserialize-bst/) | [LeetCode](https://leetcode.com/problems/serialize-and-deserialize-bst/)

序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化 **二叉搜索树** 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

**编码的字符串应尽可能紧凑。**

**示例 1：**

```
输入：root = [2,1,3]
输出：[2,1,3]
```

**示例 2：**

```
输入：root = []
输出：[]
```

**提示：**

- 树中节点数范围是 `[0, 10<sup>4</sup>]`
- `0 <= Node.val <= 10<sup>4</sup>`
- 题目数据 **保证** 输入的树是一棵二叉搜索树。

题目来源： [力扣 449. 序列化和反序列化二叉搜索树](https://leetcode.cn/problems/serialize-and-deserialize-bst/) 。

#### 基本思路

在做本题之前，你需要先看前文 [二叉树的序列化和反序列化的不同方式](https://labuladong.online/zh/algo/data-structure/serialize-and-deserialize-binary-tree/) ，然后就可以很容易理解本题的思路了。

二叉树的构造算法通用思路很简单，无非就是构造根节点，然后递归构造左右子树，最后把它们接起来， **关键在于如何找到根节点和左右子树的节点，不同的序列化方法，找根节点的方式也不同** 。

本题当然可以直接复制 [297\. 二叉树的序列化和反序列化](https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/description/) 的代码过来，但是显然没有利用到 BST 左小右大的特性，复杂度会更高。

对比 297 题普通二叉树的序列化，利用 BST 左小右大的特性主要可以避免序列化空指针，利用 `min, max` 边界来划定一棵子树的边界，从而提升算法效率。

#### 解法代码

```
class Codec {

    // 分隔符，区分每个节点的值

    private:

        const static char SEP = ',';

    public:

        // Encodes a tree to a single string.

        string serialize(TreeNode* root) {

            stringstream ss;

            serialize(root, ss);

            return ss.str();

        }

    private:

        void serialize(TreeNode* root, stringstream& ss) {

            if (root == nullptr) {

                return;

            }

            // 前序遍历位置进行序列化

            ss << root->val << SEP;

            serialize(root->left, ss);

            serialize(root->right, ss);

        }

    public:

        // Decodes your encoded data to tree.

        TreeNode* deserialize(string data) {

            if (data.empty()) return nullptr;

            // 转化成前序遍历结果

            list<int> inorder;

            stringstream ss(data);

            string s;

            while (getline(ss, s, SEP)) {

                inorder.push_back(stoi(s));

            }

            return deserialize(inorder, INT_MIN, INT_MAX);

        }

    private:

        // 定义：将 nodes 中值在闭区间 [min, max] 的节点构造成一棵 BST

        TreeNode* deserialize(list<int>& nodes, int min, int max) {

            if (nodes.empty()) return nullptr;

            // 前序遍历位置进行反序列化

            // 前序遍历结果第一个节点是根节点

            int rootVal = nodes.front();

            if (rootVal > max || rootVal < min) {

                // 超过闭区间 [min, max]，则返回空指针

                return nullptr;

            }

            nodes.pop_front();

            // 生成 root 节点

            TreeNode* root = new TreeNode(rootVal);

            // 构建左右子树

            // BST 左子树都比根节点小，右子树都比根节点大

            root->left = deserialize(nodes, min, rootVal);

            root->right = deserialize(nodes, rootVal, max);

            return root;

        }

};
```

#### 算法可视化

算法可视化

技巧二

如果输入的不是有序数组，而是有序链表，应该怎么构造 BST 呢？

**109\. 有序链表转换二叉搜索树** | [力扣](https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/) | [LeetCode](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

给定一个单链表的头节点 `head` ，其中的元素 **按升序排序** ，将其转换为 平衡 二叉搜索树。

**示例 1:**

![](https://labuladong.online/images/lc/uploads/2020/08/17/linked.jpg)

```
输入: head = [-10,-3,0,5,9]
输出: [0,-3,9,-10,null,5]
解释: 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
```

**示例 2:**

```
输入: head = []
输出: []
```

**提示:**

- `head` 中的节点数在 `[0, 2 * 10<sup>4</sup>]` 范围内
- `-10<sup>5</sup> <= Node.val <= 10<sup>5</sup>`

题目来源： [力扣 109. 有序链表转换二叉搜索树](https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/) 。

#### 基本思路

链表和数组相比的一个关键差异是无法通过索引快速访问元素，所以这题有几个思路：

1、把链表转化成数组，然后直接复用 [108\. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/) 的解法。

2、稍微改写 [108\. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/) 的解法，用 [单链表的六大解题套路](https://labuladong.online/zh/algo/essential-technique/linked-list-skills-summary/) 说到的双指针方法获取链表的中点，时间复杂度略高一些。

3、如果深刻理解二叉树算法，可以利用中序遍历的特点写出最优化的解法。

我把第 2 和第 3 种解法写一下。

#### 解法代码

```
class Solution {

    ListNode* cur;

public:

    // 解法三、通过中序遍历特点写出的解法

    TreeNode* sortedListToBST(ListNode* head) {

        int len = 0;

        for (ListNode* p = head; p != nullptr; p = p->next) {

            len++;

        }

        cur = head;

        return inorderBuild(0, len - 1);

    }

    TreeNode* inorderBuild(int left, int right) {

        if (left > right) {

            return nullptr;

        }

        int mid = (left + right) / 2;

        // 构造左子树

        TreeNode* leftTree = inorderBuild(left, mid - 1);

        // 构造根节点

        TreeNode* root = new TreeNode(cur->val);

        cur = cur->next;

        // 构造右子树

        TreeNode* rightTree = inorderBuild(mid + 1, right);

        // 将左右子树接到根节点上

        root->left = leftTree;

        root->right = rightTree;

        return root;

    }

    // 解法二、通过找链表中点的方式写出的解法

    TreeNode* sortedListToBST_2(ListNode* head) {

        return build(head, nullptr);

    }

    // 把链表左闭右开区间 [begin, end) 的节点构造成 BST

    TreeNode* build(ListNode* begin, ListNode* end) {

        if (begin == end) {

            // 因为是左闭右开区间，所以现在已经成空集了

            return nullptr;

        }

        ListNode* mid = getMid(begin, end);

        TreeNode* root = new TreeNode(mid->val);

        root->left = build(begin, mid);

        root->right = build(mid->next, end);

        return root;

    }

    // 获取链表左闭右开区间 [begin, end) 的中心节点

    ListNode* getMid(ListNode* begin, ListNode* end) {

        ListNode* slow = begin;

        ListNode* fast = begin;

        while (fast != end && fast->next != end) {

            slow = slow->next;

            fast = fast->next->next;

        }

        return slow;

    }

};
```

#### 算法可视化

Tip

最后还有一些常考的套路题型，记住就好了。

**173\. 二叉搜索树迭代器** | [力扣](https://leetcode.cn/problems/binary-search-tree-iterator/) | [LeetCode](https://leetcode.com/problems/binary-search-tree-iterator/)

实现一个二叉搜索树迭代器类 `BSTIterator` ，表示一个按中序遍历二叉搜索树（BST）的迭代器：

- `BSTIterator(TreeNode root)` 初始化 `BSTIterator` 类的一个对象。BST 的根节点 `root` 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
- `boolean hasNext()` 如果向指针右侧遍历存在数字，则返回 `true` ；否则返回 `false` 。
- `int next()` 将指针向右移动，然后返回指针处的数字。

注意，指针初始化为一个不存在于 BST 中的数字，所以对 `next()` 的首次调用将返回 BST 中的最小元素。

你可以假设 `next()` 调用总是有效的，也就是说，当调用 `next()` 时，BST 的中序遍历中至少存在一个下一个数字。

**示例：**

![](https://labuladong.online/images/lc/uploads/2018/12/25/bst-tree.png)
```
输入
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
输出
[null, 3, 7, true, 9, true, 15, true, 20, false]

解释
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // 返回 3
bSTIterator.next();    // 返回 7
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 9
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 15
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 20
bSTIterator.hasNext(); // 返回 False
```

**提示：**

- 树中节点的数目在范围 `[1, 10<sup>5</sup>]` 内
- `0 <= Node.val <= 10<sup>6</sup>`
- 最多调用 `10<sup>5</sup>` 次 `hasNext` 和 `next` 操作

**进阶：**

- 你可以设计一个满足下述条件的解决方案吗？ `next()` 和 `hasNext()` 操作均摊时间复杂度为 `O(1)` ，并使用 `O(h)` 内存。其中 `h` 是树的高度。

题目来源： [力扣 173. 二叉搜索树迭代器](https://leetcode.cn/problems/binary-search-tree-iterator/) 。

#### 基本思路

利用栈模拟递归对 BST 进行中序遍历可以认为是一种套路题型，你记住就好了，关键在于理解 `pushLeftBranch` 函数，深刻理解二叉树递归遍历的过程：

![](https://labuladong.online/images/algo/iter-binary-tree/1.gif)

另外，我还总结了一套二叉树各种遍历顺序通用的递归转迭代代码框架，详见 [二叉树通用迭代框架](https://labuladong.online/zh/algo/data-structure/iterative-traversal-binary-tree/) 。

#### 解法代码

```
class BSTIterator {

    // 模拟递归栈

    private:

        stack<TreeNode*> stk;

        // 左侧树枝一撸到底

        void pushLeftBranch(TreeNode* p) {

            while (p != nullptr) {

                stk.push(p);

                p = p->left;

            }

        }

    public:

        BSTIterator(TreeNode* root) {

            pushLeftBranch(root);

        }

        int next() {

            TreeNode* p = stk.top();

            stk.pop();

            pushLeftBranch(p->right);

            return p->val;

        }

        bool hasNext() {

            return !stk.empty();

        }

};
```

#### 算法可视化

**1305\. 两棵二叉搜索树中的所有元素** | [力扣](https://leetcode.cn/problems/all-elements-in-two-binary-search-trees/) | [LeetCode](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)

给你 `root1` 和 `root2` 这两棵二叉搜索树。请你返回一个列表，其中包含 **两棵树** 中的所有整数并按 **升序** 排序。.

**示例 1：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/12/29/q2-e1.png)

```
输入：root1 = [2,1,4], root2 = [1,0,3]
输出：[0,1,1,2,3,4]
```

**示例 2：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/12/29/q2-e5-.png)

```
输入：root1 = [1,null,8], root2 = [8,1]
输出：[1,1,8,8]
```

**提示：**

- 每棵树的节点数在 `[0, 5000]` 范围内
- `-10<sup>5</sup> <= Node.val <= 10<sup>5</sup>`

题目来源： [力扣 1305. 两棵二叉搜索树中的所有元素](https://leetcode.cn/problems/all-elements-in-two-binary-search-trees/) 。

#### 基本思路

你可以直接中序遍历两个 BST 得到两个有序数组，然后把这两个有序数组合并，这个思路简单，但是空间复杂度会高一些。

比较好的办法是用 [173\. 二叉搜索树迭代器](https://leetcode.cn/problems/binary-search-tree-iterator/description/) 中实现的 BST 迭代器，然后类似我们解决 [21\. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/description/) 中的逻辑操作这两个迭代器，获得合并的有序结果。

#### 解法代码

```
#include <vector>

#include <stack>

// BST 有序迭代器

class BSTIterator {

public:

    stack<TreeNode*> stk;

    // 左侧树枝一撸到底

    void pushLeftBranch(TreeNode* p) {

        while (p != nullptr) {

            stk.push(p);

            p = p->left;

        }

    }

    BSTIterator(TreeNode* root) {

        pushLeftBranch(root);

    }

    int peek() {

        return stk.top()->val;

    }

    int next() {

        TreeNode* p = stk.top();

        stk.pop();

        pushLeftBranch(p->right);

        return p->val;

    }

    bool hasNext() {

        return !stk.empty();

    }

};

class Solution {

public:

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        // BST 有序迭代器

        BSTIterator t1(root1);

        BSTIterator t2(root2);

        vector<int> res;

        // 类似合并有序链表的算法逻辑

        while (t1.hasNext() && t2.hasNext()) {

            if (t1.peek() > t2.peek()) {

                res.push_back(t2.next());

            } else {

                res.push_back(t1.next());

            }

        }

        // 如果有一棵 BST 还剩元素，添加到最后

        while (t1.hasNext()) {

            res.push_back(t1.next());

        }

        while (t2.hasNext()) {

            res.push_back(t2.next());

        }

        return res;

    }

};
```

#### 算法可视化

更新时间：2026/02/17 14:24

## 评论(2)

Markdown

Ctrl+Enter 发表

![刍荛](https://thirdwx.qlogo.cn/mmopen/vi_32/DYAIOgq83erL9GjLfCmHsia6gD1oEhDwKdJMUJEz8C19EXWqWGPYvujRV7OfV2KCROCvTJJg3icFkWqugCfIDGSsUsdn6KL2V1RKgEx6zfYq48GeibMBA9ntg/132)

刍荛 7 个月前

173其实可以直接处理成 有序数组，感觉逻辑上会更简单点，通过index来进行next的处理的判定

```
def __init__(self, root: Optional[TreeNode]):

        self.ordered_nums = []

        self.traverse(root)

        # 位置指针，指向“当前”

        # 初始化的时候需要在 index == 0 的左边偏移一个，确保首次next()返回第0个index

        self.idx = -1  

    def traverse(self, root):

        if not root:

            return 

        self.traverse(root.left)

        # 中序位置进行记录

        self.ordered_nums.append(root.val)

        self.traverse(root.right)

    def hasNext(self):

        res = self.idx + 1 < len(self.ordered_nums)

        return res

    def next(self):

        self.idx += 1

        return self.ordered_nums[self.idx]
```

![Yuuuuu](https://thirdwx.qlogo.cn/mmopen/vi_32/3eLEXowzDITh7HtkklXC0bkPsWcmxLhElR558AsW1mHb9ltBqYzRtbLzEzmEBfzWJt1S2viaW8J1ZP2sNslruTw/132)

Yuuuuu 12 个月前

最后一题妙啊，把两个二叉树放进迭代器，相当于变成了两个链表，然后变成了合并链表

我还傻傻的把 traverse 函数，把一个 treenode，变成两个 treenode 入参 然后根据根据大小去调整下一轮递归的传参

但是没跑成功几个用例，只适合两个树的结构一模一样的情况