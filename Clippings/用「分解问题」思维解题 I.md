---
title: "用「分解问题」思维解题 I"
source: "https://labuladong.online/zh/algo/problem-set/binary-tree-divide-i/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文汇总了 力扣/LeetCode 上所有用分解问题思维求解的二叉树经典习题（第一部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。"
tags:
  - "clippings"
---
最常见的，二叉树的构造问题一般都会用到分解问题的思维模式。

### 105\. 从前序与中序遍历序列构造二叉树

**105\. 从前序与中序遍历序列构造二叉树** | [力扣](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | [LeetCode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

给定两个整数数组 `preorder` 和 `inorder`  ，其中  `preorder` 是二叉树的 **先序遍历** ， `inorder` 是同一棵树的 **中序遍历** ，请构造二叉树并返回其根节点。

**示例 1:**

![](https://labuladong.online/images/lc/uploads/2021/02/19/tree.jpg)
```
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
```

**示例 2:**

```
输入: preorder = [-1], inorder = [-1]
输出: [-1]
```

**提示:**

- `1 <= preorder.length <= 3000`
- `inorder.length == preorder.length`
- `-3000 <= preorder[i], inorder[i] <= 3000`
- `preorder`  和  `inorder` 均 **无重复** 元素
- `inorder`  均出现在  `preorder`
- `preorder` **保证** 为二叉树的前序遍历序列
- `inorder` **保证** 为二叉树的中序遍历序列

题目来源： [力扣 105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) 。

#### 基本思路

**构造二叉树，第一件事一定是找根节点，然后想办法构造左右子树** 。

二叉树的前序和中序遍历结果的特点如下：

![](https://labuladong.online/images/algo/binary-tree-ii/1.jpeg)

前序遍历结果第一个就是根节点的值，然后再根据中序遍历结果确定左右子树的节点。

![](https://labuladong.online/images/algo/binary-tree-ii/4.jpeg)

结合这个图看代码辅助理解。

#### 解法代码

```
class Solution {

public:

    // 存储 inorder 中值到索引的映射

    unordered_map<int, int> valToIndex;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {

            valToIndex[inorder[i]] = i;

        }

        return build(preorder, 0, preorder.size() - 1,

                    inorder, 0, inorder.size() - 1);

    }

    // build 函数的定义：

    // 若前序遍历数组为 preorder[preStart..preEnd]，

    // 中序遍历数组为 inorder[inStart..inEnd]，

    // 构造二叉树，返回该二叉树的根节点

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 

                    vector<int>& inorder, int inStart, int inEnd) {

        if (preStart > preEnd) {

            return NULL;

        }

        // root 节点对应的值就是前序遍历数组的第一个元素

        int rootVal = preorder[preStart];

        // rootVal 在中序遍历数组中的索引

        int index = valToIndex[rootVal];

        int leftSize = index - inStart;

        // 先构造出当前根节点

        TreeNode* root = new TreeNode(rootVal);

        // 递归构造左右子树

        root->left = build(preorder, preStart + 1, preStart + leftSize,

                        inorder, inStart, index - 1);

        root->right = build(preorder, preStart + leftSize + 1, preEnd,

                        inorder, index + 1, inEnd);

        return root;

    }

};
```

#### 算法可视化

算法可视化

**详细题解**:

- [二叉树心法（构造篇）](https://labuladong.online/zh/algo/data-structure/binary-tree-part2/)

### 106\. 从中序与后序遍历序列构造二叉树

**106\. 从中序与后序遍历序列构造二叉树** | [力扣](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | [LeetCode](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

给定两个整数数组 `inorder` 和 `postorder` ，其中 `inorder` 是二叉树的中序遍历， `postorder` 是同一棵树的后序遍历，请你构造并返回这颗 *二叉树* 。

**示例 1:**

![](https://labuladong.online/images/lc/uploads/2021/02/19/tree.jpg)
```
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]
```

**示例 2:**

```
输入：inorder = [-1], postorder = [-1]
输出：[-1]
```

**提示:**

- `1 <= inorder.length <= 3000`
- `postorder.length == inorder.length`
- `-3000 <= inorder[i], postorder[i] <= 3000`
- `inorder`  和  `postorder` 都由 **不同** 的值组成
- `postorder`  中每一个值都在  `inorder` 中
- `inorder` **保证** 是树的中序遍历
- `postorder` **保证** 是树的后序遍历

题目来源： [力扣 106. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) 。

#### 基本思路

**构造二叉树，第一件事一定是找根节点，然后想办法构造左右子树** 。

二叉树的后序和中序遍历结果的特点如下：

![](https://labuladong.online/images/algo/binary-tree-ii/5.jpeg)

后序遍历结果最后一个就是根节点的值，然后再根据中序遍历结果确定左右子树的节点。

![](https://labuladong.online/images/algo/binary-tree-ii/6.jpeg)

结合这个图看代码辅助理解。

#### 解法代码

```
class Solution {

    // 存储 inorder 中值到索引的映射

    unordered_map<int, int> valToIndex;

public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++) {

            valToIndex[inorder[i]] = i;

        }

        return build(inorder, 0, inorder.size() - 1,

                     postorder, 0, postorder.size() - 1);

    }

    // 定义：中序遍历数组为 inorder[inStart..inEnd]，

    // 后序遍历数组为 postorder[postStart..postEnd]，

    // build 函数构造这个二叉树并返回该二叉树的根节点

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,

                    vector<int>& postorder, int postStart, int postEnd) {

        if (inStart > inEnd) {

            return nullptr;

        }

        // root 节点对应的值就是后序遍历数组的最后一个元素

        int rootVal = postorder[postEnd];

        // rootVal 在中序遍历数组中的索引

        int index = valToIndex[rootVal];

        // 左子树的节点个数

        int leftSize = index - inStart;

        TreeNode* root = new TreeNode(rootVal);

        // 递归构造左右子树

        root->left = build(inorder, inStart, index - 1,

                           postorder, postStart, postStart + leftSize - 1);

        

        root->right = build(inorder, index + 1, inEnd,

                            postorder, postStart + leftSize, postEnd - 1);

        return root;

    }

};
```

#### 算法可视化

算法可视化

**详细题解**:

- [二叉树心法（构造篇）](https://labuladong.online/zh/algo/data-structure/binary-tree-part2/)

### 889\. 根据前序和后序遍历构造二叉树

**889\. 根据前序和后序遍历构造二叉树** | [力扣](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) | [LeetCode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

给定两个整数数组， `preorder`  和 `postorder` ，其中 `preorder` 是一个具有 **无重复** 值的二叉树的前序遍历， `postorder` 是同一棵树的后序遍历，重构并返回二叉树。

如果存在多个答案，您可以返回其中 **任何** 一个。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/07/24/lc-prepost.jpg)

```
输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
输出：[1,2,3,4,5,6,7]
```

**示例 2:**

```
输入: preorder = [1], postorder = [1]
输出: [1]
```

**提示：**

- `1 <= preorder.length <= 30`
- `1 <= preorder[i] <= preorder.length`
- `preorder` 中所有值都 **不同**
- `postorder.length == preorder.length`
- `1 <= postorder[i] <= postorder.length`
- `postorder` 中所有值都 **不同**
- 保证 `preorder`  和 `postorder` 是同一棵二叉树的前序遍历和后序遍历

题目来源： [力扣 889. 根据前序和后序遍历构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/) 。

#### 基本思路

做这道题之前，建议你先看一下 [二叉树心法（构造篇）](https://labuladong.online/zh/algo/data-structure/binary-tree-part2/) ，做一下 [105\. 从前序与中序遍历序列构造二叉树（中等）](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/) 和 [106\. 从中序与后序遍历序列构造二叉树（中等）](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/) 这两道题。

这道题让用后序遍历和前序遍历结果还原二叉树，和前两道题有一个本质的区别：

**通过前序中序，或者后序中序遍历结果可以确定一棵原始二叉树，但是通过前序后序遍历结果无法确定原始二叉树** 。题目也说了，如果有多种结果，你可以返回任意一种。

为什么呢？我们说过，构建二叉树的套路很简单，先找到根节点，然后找到并递归构造左右子树即可。

前两道题，可以通过前序或者后序遍历结果找到根节点，然后根据中序遍历结果确定左右子树。

这道题，你可以确定根节点，但是无法确切的知道左右子树有哪些节点。

举个例子，下面这两棵树结构不同，但是它们的前序遍历和后序遍历结果是相同的：

![](https://labuladong.online/images/algo/binary-tree-ii/7.png)

不过话说回来，用后序遍历和前序遍历结果还原二叉树，解法逻辑上和前两道题差别不大，也是通过控制左右子树的索引来构建：

**1、首先把前序遍历结果的第一个元素或者后序遍历结果的最后一个元素确定为根节点的值** 。

**2、然后把前序遍历结果的第二个元素作为左子树的根节点的值** 。

**3、在后序遍历结果中寻找左子树根节点的值，从而确定了左子树的索引边界，进而确定右子树的索引边界，递归构造左右子树即可** 。

![](https://labuladong.online/images/algo/binary-tree-ii/8.jpeg)

#### 解法代码

```
class Solution {

    // 存储 postorder 中值到索引的映射

    unordered_map<int, int> valToIndex;

public:

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        for (int i = 0; i < postorder.size(); i++) {

            valToIndex[postorder[i]] = i;

        }

        return build(preorder, 0, preorder.size() - 1,

                    postorder, 0, postorder.size() - 1);

    }

    // 定义：根据 preorder[preStart..preEnd] 和 postorder[postStart..postEnd]

    // 构建二叉树，并返回根节点。

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,

                   vector<int>& postorder, int postStart, int postEnd) {

        if (preStart > preEnd) {

            return nullptr;

        }

        if (preStart == preEnd) {

            return new TreeNode(preorder[preStart]);

        }

        // root 节点对应的值就是前序遍历数组的第一个元素

        int rootVal = preorder[preStart];

        // root.left 的值是前序遍历第二个元素

        // 通过前序和后序遍历构造二叉树的关键在于通过左子树的根节点

        // 确定 preorder 和 postorder 中左右子树的元素区间

        int leftRootVal = preorder[preStart + 1];

        // leftRootVal 在后序遍历数组中的索引

        int index = valToIndex[leftRootVal];

        // 左子树的元素个数

        int leftSize = index - postStart + 1;

        // 先构造出当前根节点

        TreeNode* root = new TreeNode(rootVal);

        // 递归构造左右子树

        // 根据左子树的根节点索引和元素个数推导左右子树的索引边界

        root->left = build(preorder, preStart + 1, preStart + leftSize,

                postorder, postStart, index);

        root->right = build(preorder, preStart + leftSize + 1, preEnd,

                postorder, index + 1, postEnd - 1);

        return root;

    }

};
```

#### 算法可视化

算法可视化

**详细题解**:

- [二叉树心法（构造篇）](https://labuladong.online/zh/algo/data-structure/binary-tree-part2/)

### 331\. 验证二叉树的前序序列化

**331\. 验证二叉树的前序序列化** | [力扣](https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/) | [LeetCode](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/)

序列化二叉树的一种方法是使用 **前序遍历** 。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 `#` 。

![](https://labuladong.online/images/lc/uploads/2021/03/12/pre-tree.jpg)

例如，上面的二叉树可以被序列化为字符串 `"9,3,4,#,#,1,#,#,2,#,6,#,#"` ，其中 `#` 代表一个空节点。

给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。

**保证** 每个以逗号分隔的字符或为一个整数或为一个表示 `null` 指针的 `'#'` 。

你可以认为输入格式总是有效的

- 例如它永远不会包含两个连续的逗号，比如 `"1,,3"` 。

**注意：** 不允许重建树。

**示例 1:**

```
输入: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
输出: true
```

**示例 2:**

```
输入: preorder = "1,#"
输出: false
```

**示例 3:**

```
输入: preorder = "9,#,#,1"
输出: false
```

**提示:**

- `1 <= preorder.length <= 10<sup>4</sup>`
- `preorder` 由以逗号 `“，”` 分隔的 `[0,100]` 范围内的整数和 `“#”` 组成

题目来源： [力扣 331. 验证二叉树的前序序列化](https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/) 。

#### 基本思路

首先，如果看过前文 [手把手带你刷二叉树（序列化篇）](https://labuladong.online/zh/algo/data-structure/serialize-and-deserialize-binary-tree/) 理解了前序遍历序列化和反序列化的原理，肯定可以通过改造反序列化函数 `deserialize` 来判断序列化的合法性。

另外还有一种更巧妙的解法，就是利用二叉树节点和边的关系。

每个非空的二叉树节点都会产生两条边，并消耗一条边；而每个空节点只会消耗一条边：

![](https://labuladong.online/images/algo/brief-extra/331.jpeg)

#### 解法代码

```
class Solution {

public:

    bool isValidSerialization(string preorder) {

        // 一条指向根节点的虚拟边

        int edge = 1;

        stringstream ss(preorder);

        string node;

        while (getline(ss, node, ',')) {

            // 任何时候，边数都不能小于 0

            if (node == "#") {

                // 空指针消耗一条空闲边

                edge -= 1;

                if (edge < 0) {

                    return false;

                }

            } else {

                // 非空节点消耗一条空闲边，增加两条空闲边

                edge -= 1;

                if (edge < 0) {

                    return false;

                }

                edge += 2;

            }

        }

        // 最后不应该存在空闲边

        return edge == 0;

    }

};

class Solution2 {

public:

    bool isValidSerialization(string preorder) {

        // 将字符串转化成列表

        list<string> nodes;

        stringstream ss(preorder);

        string s;

        while (getline(ss, s, ',')) {

            nodes.push_back(s);

        }

        return deserialize(nodes) && nodes.empty();

    }

    // 改造后的前序遍历反序列化函数

    // 详细解析：https://labuladong.online/algo/data-structure/serialize-and-deserialize-binary-tree/

    bool deserialize(list<string>& nodes) {

        if (nodes.empty()) {

            return false;

        }

        // ***** 前序遍历位置 *****

        // 列表最左侧就是根节点

        string first = nodes.front();

        nodes.pop_front();

        if (first == "#") return true;

        // *********************

        return deserialize(nodes) && deserialize(nodes);

    }

};
```

#### 算法可视化

算法可视化

### 894\. 所有可能的真二叉树

**894\. 所有可能的真二叉树** | [力扣](https://leetcode.cn/problems/all-possible-full-binary-trees/) | [LeetCode](https://leetcode.com/problems/all-possible-full-binary-trees/)

给你一个整数 `n` ，请你找出所有可能含 `n` 个节点的 **真二叉树** ，并以列表形式返回。答案中每棵树的每个节点都必须符合 `Node.val == 0` 。

答案的每个元素都是一棵真二叉树的根节点。你可以按 **任意顺序** 返回最终的真二叉树列表 **。**

**真二叉树** 是一类二叉树，树中每个节点恰好有 `0` 或 `2` 个子节点。

**示例 1：**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/22/fivetrees.png)
```
输入：n = 7
输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
```

**示例 2：**

```
输入：n = 3
输出：[[0,0,0]]
```

**提示：**

- `1 <= n <= 20`

题目来源： [力扣 894. 所有可能的真二叉树](https://leetcode.cn/problems/all-possible-full-binary-trees/) 。

#### 基本思路

注意：国外和国内关于完全二叉树、满二叉树的定义有区别，我在 [二叉树基础知识](https://labuladong.online/zh/algo/data-structure-basic/binary-tree-basic/) 有介绍。不过这些文学词汇并不重要，重要的是算法思维，所以我们按照题目说的来就好。

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维。

如果你想生成一棵 `n` 个节点的满二叉树，首先要固定根节点，然后组装左右子树，根节点加上左右子树节点之和应该等于 `n` 。

我们定义 `helper` 能够生成节点数为 `n` 的所有可能的二叉树，然后利用这个定义生成左右子树，然后通过子树组装出结果即可。

#### 解法代码

```
#include <vector>

#include <list>

class Solution {

    // 备忘录，记录 n 个节点能够组合成的所有可能二叉树

    vector<list<TreeNode*>> memo;

public:

    vector<TreeNode*> allPossibleFBT(int n) {

        if (n % 2 == 0) {

            // 题目描述的满二叉树不可能是偶数个节点

            return vector<TreeNode*>();

        }

        memo.resize(n + 1);

        return build(n);

    }

private:

    // 定义：输入一个 n，生成节点树为 n 的所有可能的满二叉树

    vector<TreeNode*> build(int n) {

        vector<TreeNode*> res;

        // base case

        if (n == 1) {

            res.push_back(new TreeNode(0));

            return res;

        }

        if (!memo[n].empty()) {

            // 避免冗余计算

            return vector<TreeNode*>(memo[n].begin(), memo[n].end());

        }

        // 递归生成所有符合条件的左右子树

        for (int i = 1; i < n; i += 2) {

            int j = n - i - 1;

            // 利用函数定义，生成左右子树

            vector<TreeNode*> leftSubTrees = build(i);

            vector<TreeNode*> rightSubTrees = build(j);

            // 左右子树的不同排列也能构成不同的二叉树

            for (TreeNode* left : leftSubTrees) {

                for (TreeNode* right : rightSubTrees) {

                    // 生成根节点

                    TreeNode* root = new TreeNode(0);

                    // 组装出一种可能的二叉树形状

                    root->left = left;

                    root->right = right;

                    // 加入结果列表

                    res.push_back(root);

                }

            }

        }

        // 存入备忘录

        memo[n] = list<TreeNode*>(res.begin(), res.end());

        return res;

    }

};
```

#### 算法可视化

算法可视化

### 998\. 最大二叉树 II

**最大树** 定义：一棵树，并满足：其中每个节点的值都大于其子树中的任何其他值。

给你最大树的根节点 `root` 和一个整数 `val` 。

就像 [之前的问题](https://leetcode.cn/problems/maximum-binary-tree/) 那样，给定的树是利用 `Construct(a)` 例程从列表 `a` （ `root = Construct(a)` ）递归地构建的：

- 如果 `a` 为空，返回  `null` 。
- 否则，令 `a[i]` 作为 `a` 的最大元素。创建一个值为  `a[i]` 的根节点 `root` 。
- `root`  的左子树将被构建为  `Construct([a[0], a[1], ..., a[i - 1]])` 。
- `root`  的右子树将被构建为  `Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]])` 。
- 返回 `root` 。

请注意，题目没有直接给出 `a` ，只是给出一个根节点  `root = Construct(a)` 。

假设 `b` 是 `a` 的副本，并在末尾附加值 `val` 。题目数据保证 `b` 中的值互不相同。

返回 `Construct(b)` 。

**示例 1：**

 **![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/23/maximum-binary-tree-1-1.png) ![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/23/maximum-binary-tree-1-2.png)**

```
输入：root = [4,1,3,null,null,2], val = 5
输出：[5,4,null,1,3,null,null,2]
解释：a = [1,4,2,3], b = [1,4,2,3,5]
```

**示例 2：  
![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/23/maximum-binary-tree-2-1.png) ![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/23/maximum-binary-tree-2-2.png)** 

```
输入：root = [5,2,4,null,1], val = 3
输出：[5,2,4,null,1,null,3]
解释：a = [2,1,5,4], b = [2,1,5,4,3]
```

**示例 3：  
![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/23/maximum-binary-tree-3-1.png) ![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/23/maximum-binary-tree-3-2.png)** 

```
输入：root = [5,2,3,null,1], val = 4
输出：[5,2,4,null,1,3]
解释：a = [2,1,5,3], b = [2,1,5,3,4]
```

**提示：**

- 树中节点数目在范围 `[1, 100]` 内
- `1 <= Node.val <= 100`
- 树中的所有值 **互不相同**
- `1 <= val <= 100`

题目来源： [力扣 998. 最大二叉树 II](https://leetcode.cn/problems/maximum-binary-tree-ii/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维。

做这道题之前，你一定要去做一下 [654\. 最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/description/) 这道题，知道了构建最大二叉树的逻辑就很容易解决这道题了。

新增的 `val` 是添加在原始数组的最后的，根据构建最大二叉树的逻辑，正常来说最后的这个值一定是在右子树的，可以对右子树递归调用 `insertIntoMaxTree` 插入进去。

但是一种特殊情况是 `val` 比原始数组中的所有元素都大，那么根据构建最大二叉树的逻辑，原来的这棵树应该成为 `val` 节点的左子树。

#### 解法代码

```
class Solution {

public:

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {

        if (root == nullptr) {

            return new TreeNode(val);

        }

        if (root->val < val) {

            // 如果 val 是整棵树最大的，那么原来的这棵树应该是 val 节点的左子树，

            // 因为 val 节点是接在原始数组 a 的最后一个元素

            TreeNode* temp = root;

            root = new TreeNode(val);

            root->left = temp;

        } else {

            // 如果 val 不是最大的，那么就应该在右子树上，

            // 因为 val 节点是接在原始数组 a 的最后一个元素

            root->right = insertIntoMaxTree(root->right, val);

        }

        return root;

    }

};
```

#### 算法可视化

算法可视化

### 1110\. 删点成林

**1110\. 删点成林** | [力扣](https://leetcode.cn/problems/delete-nodes-and-return-forest/) | [LeetCode](https://leetcode.com/problems/delete-nodes-and-return-forest/)

给出二叉树的根节点 `root` ，树上每个节点都有一个不同的值。

如果节点值在 `to_delete` 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。

返回森林中的每棵树。你可以按任意顺序组织答案。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/07/05/screen-shot-2019-07-01-at-53836-pm.png)**

```
输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
输出：[[1,2,null,4],[6],[7]]
```

**示例 2：**

```
输入：root = [1,2,4,null,3], to_delete = [3]
输出：[[1,2,4]]
```

**提示：**

- 树中的节点数最大为 `1000` 。
- 每个节点都有一个介于 `1` 到  `1000` 之间的值，且各不相同。
- `to_delete.length <= 1000`
- `to_delete` 包含一些从  `1` 到  `1000` 、各不相同的值。

题目来源： [力扣 1110. 删点成林](https://leetcode.cn/problems/delete-nodes-and-return-forest/) 。

#### 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「分解问题」的思维。

首先，如果在递归过程中修改二叉树结构，必须要让父节点接收递归函数的返回值，因为子树不管删成啥样，都要接到父节点上。

而且， [手把手刷二叉树总结篇](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 说了可以通过函数参数传递父节点传递的数据，所以可以在前序位置判断是否得到了一个新的根节点。

#### 解法代码

```
#include <vector>

#include <unordered_set>

using namespace std;

class Solution {

public:

    unordered_set<int> delSet;

    // 记录森林的根节点

    vector<TreeNode*> res;

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        for (int d : to_delete) {

            delSet.insert(d);

        }

        doDelete(root, false);

        return res;

    }

private:

    // 定义：输入一棵二叉树，删除 delSet 中的节点，返回删除完成后的根节点

    TreeNode* doDelete(TreeNode* root, bool hasParent) {

        if (root == nullptr) {

            return nullptr;

        }

        // 判断是否需要被删除

        bool deleted = delSet.count(root->val);

        if (!deleted && !hasParent) {

            // 没有父节点且不需要被删除，就是一个新的根节点

            res.push_back(root);

        }

        // 去左右子树进行删除

        root->left = doDelete(root->left, !deleted);

        root->right = doDelete(root->right, !deleted);

        // 如果需要被删除，返回 null 给父节点

        return deleted ? nullptr : root;

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表