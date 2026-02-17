---
title: 运用层序遍历解题 II
source: https://labuladong.online/zh/algo/problem-set/binary-tree-level-ii/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上所有二叉树层序遍历的经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
前置知识

阅读本文前，你需要先学习：

- [二叉树的遍历基础](https://labuladong.online/zh/algo/data-structure-basic/binary-tree-traverse-basic/)
- [二叉树心法（纲领篇）](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/)

有些二叉树的特殊题型需要用层序遍历的方式来做，比如下面列举的几道题。这类问题你就当开阔眼界有个印象就行了，不会有太多变体。

### 919\. 完全二叉树插入器

**919\. 完全二叉树插入器** | [力扣](https://leetcode.cn/problems/complete-binary-tree-inserter/) | [LeetCode](https://leetcode.com/problems/complete-binary-tree-inserter/)

**完全二叉树** 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。

设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。

实现 `CBTInserter` 类:

- `CBTInserter(TreeNode root)` 使用头节点为 `root` 的给定树初始化该数据结构；
- `CBTInserter.insert(int v)` 向树中插入一个值为 `Node.val == val` 的新节点  `TreeNode` 。使树保持完全二叉树的状态， **并返回插入节点** `TreeNode` **的父节点的值** ；
- `CBTInserter.get_root()` 将返回树的头节点。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/08/03/lc-treeinsert.jpg)

```
输入
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
输出
[null, 1, 2, [1, 2, 3, 4]]

解释
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // 返回 1
cBTInserter.insert(4);  // 返回 2
cBTInserter.get_root(); // 返回 [1, 2, 3, 4]
```

**提示：**

- 树中节点数量范围为 `[1, 1000]`
- `0 <= Node.val <= 5000`
- `root` 是完全二叉树
- `0 <= val <= 5000`
- 每个测试用例最多调用 `insert`  和  `get_root`  操作  `10<sup>4</sup>` 次

题目来源： [力扣 919. 完全二叉树插入器](https://leetcode.cn/problems/complete-binary-tree-inserter/) 。

#### 基本思路

这道题考察二叉树的层序遍历，你需要先做 [102\. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/) 再做这道题，用队列维护底部可以进行插入的节点即可。

#### 解法代码

```
class CBTInserter {

    // 这个队列只记录完全二叉树底部可以进行插入的节点

    private:

        queue<TreeNode*> q;

        TreeNode* root;

    public:

        CBTInserter(TreeNode* root) {

            this->root = root;

            // 进行普通的 BFS，目的是找到底部可插入的节点

            queue<TreeNode*> temp;

            temp.push(root);

            while (!temp.empty()) {

                TreeNode* cur = temp.front(); temp.pop();

                if (cur->left != nullptr) {

                    temp.push(cur->left);

                }

                if (cur->right != nullptr) {

                    temp.push(cur->right);

                }

                if (cur->right == nullptr || cur->left == nullptr) {

                    // 找到完全二叉树底部可以进行插入的节点

                    q.push(cur);

                }

            }

        }

        int insert(int val) {

            TreeNode* node = new TreeNode(val);

            TreeNode* cur = q.front();

            // 进行插入

            if (cur->left == nullptr) {

                cur->left = node;

            } else if (cur->right == nullptr) {

                cur->right = node;

                q.pop();

            }

            // 新节点的左右节点也是可以插入的

            q.push(node);

            return cur->val;

        }

        TreeNode* get_root() {

            return root;

        }

};
```

#### 算法可视化

算法可视化

**872\. 叶子相似的树** | [力扣](https://leetcode.cn/problems/leaf-similar-trees/) | [LeetCode](https://leetcode.com/problems/leaf-similar-trees/)

请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 **叶值序列** 。

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png)

举个例子，如上图所示，给定一棵叶值序列为 `(6, 7, 4, 9, 8)` 的树。

如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 *叶相似* 的。

如果给定的两个根结点分别为 `root1` 和  `root2`  的树是叶相似的，则返回  `true` ；否则返回 `false` 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/09/03/leaf-similar-1.jpg)

```
输入：root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
输出：true
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/09/03/leaf-similar-2.jpg)

```
输入：root1 = [1,2,3], root2 = [1,3,2]
输出：false
```

**提示：**

- 给定的两棵树结点数在 `[1, 200]` 范围内
- 给定的两棵树上的值在 `[0, 200]` 范围内

题目来源： [力扣 872. 叶子相似的树](https://leetcode.cn/problems/leaf-similar-trees/) 。

#### 基本思路

最简单粗暴的方式就是遍历两个二叉树，把所有叶子节点都取出来，然后一个个对比。稍微有点技巧性的解法就是把递归改成栈迭代的形式。

你看这个 `next` 方法，它和二叉树的递归遍历框架很像，只不过把递归函数改成了栈操作；它和层序遍历的框架也很像，只不过把队列换成了栈，是不是挺有意思的？这个解法相当于就是用栈模拟了递归，对这棵二叉树进行前序遍历。

#### 解法代码

```
// 一个生成二叉树叶子节点的迭代器

class LeafIterator {

    // 模拟递归过程

    stack<TreeNode*> stk;

public:

    LeafIterator(TreeNode* root) {

        if (root != nullptr) {

            stk.push(root);

        }

    }

    bool hasNext() {

        return !stk.empty();

    }

    TreeNode* next() {

        while (!stk.empty()) {

            TreeNode* cur = stk.top();

            stk.pop();

            if (cur->left == nullptr && cur->right == nullptr) {

                // 发现一个叶子结点

                return cur;

            }

            // 先入栈 root.right

            if (cur->right != nullptr) {

                stk.push(cur->right);

            }

            if (cur->left != nullptr) {

                stk.push(cur->left);

            }

        }

        return nullptr;

    }

};

class Solution {

public:

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        LeafIterator it1(root1);

        LeafIterator it2(root2);

        // 逐一对比叶子节点

        while (it1.hasNext() && it2.hasNext()) {

            if (it1.next()->val != it2.next()->val) {

                return false;

            }

        }

        // 最后应该都完成遍历

        return !it1.hasNext() && !it2.hasNext();

    }

};
```

#### 算法可视化

Tip

如果让你从二叉树中的非根节点开始遍历，怎么做呢？其实可以用 map 记录子节点到父节点的映射，从而把二叉树转化成一幅图，然后再编写算法。

### 863\. 二叉树中所有距离为 K 的结点

**863\. 二叉树中所有距离为 K 的结点** | [力扣](https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/) | [LeetCode](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)

给定一个二叉树（具有根结点 `root` ）， 一个目标结点  `target`  ，和一个整数值 `k`  ，返回到目标结点 `target` 距离为 `k` 的所有结点的值的数组。

答案可以以 **任何顺序** 返回。

**示例 1：**

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
输出：[7,4,1]
解释：所求结点为与目标结点（值为 5）距离为 2 的结点，值分别为 7，4，以及 1
```

**示例 2:**

```
输入: root = [1], target = 1, k = 3
输出: []
```

**提示:**

- 节点数在 `[1, 500]` 范围内
- `0 <= Node.val <= 500`
- `Node.val` 中所有值 **不同**
- 目标结点 `target` 是树上的结点。
- `0 <= k <= 1000`

题目来源： [力扣 863. 二叉树中所有距离为 K 的结点](https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/) 。

#### 基本思路

这道题常规的解法就是把二叉树变成一幅「图」，然后在图中用 BFS 算法求距离 `target` 节点 `k` 步的所有节点。

关于 BFS 算法的原理，见 [BFS 算法核心框架套路](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 。

#### 解法代码

```
class Solution {

    // 记录父节点：node.val -> parentNode

    // 题目说了树中所有节点值都是唯一的，所以可以用 node.val 代表 TreeNode

    unordered_map<int, TreeNode*> parent;

public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // 遍历所有节点，记录每个节点的父节点

        traverse(root, nullptr);

        // 开始从 target 节点施放 BFS 算法，找到距离为 k 的节点

        queue<TreeNode*> q;

        unordered_set<int> visited;

        q.push(target);

        visited.insert(target->val);

        // 记录离 target 的距离

        int dist = 0;

        vector<int> res;

        while (!q.empty()) {

            int sz = q.size();

            for (int i = 0; i < sz; i++) {

                TreeNode* cur = q.front();

                q.pop();

                if (dist == k) {

                    // 找到距离起点 target 距离为 k 的节点

                    res.push_back(cur->val);

                }

                // 向父节点、左右子节点扩散

                TreeNode* parentNode = parent[cur->val];

                if (parentNode != nullptr && visited.find(parentNode->val) == visited.end()) {

                    visited.insert(parentNode->val);

                    q.push(parentNode);

                }

                if (cur->left != nullptr && visited.find(cur->left->val) == visited.end()) {

                    visited.insert(cur->left->val);

                    q.push(cur->left);

                }

                if (cur->right != nullptr && visited.find(cur->right->val) == visited.end()) {

                    visited.insert(cur->right->val);

                    q.push(cur->right);

                }

            }

            // 向外扩展一圈

            dist++;

        }

        return res;

    }

private:

    void traverse(TreeNode* root, TreeNode* parentNode) {

        if (root == nullptr) {

            return;

        }

        parent[root->val] = parentNode;

        // 二叉树递归框架

        traverse(root->left, root);

        traverse(root->right, root);

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论(4)

Markdown

Ctrl+Enter 发表

![射杀百头](https://thirdwx.qlogo.cn/mmopen/vi_32/NDIMAvl5EiaR7e7B9UGMruL5LViaDUtFk2PnpIbQE50gxR0JCOvR7RiatVibEMZUrdVdyKmiavkXrDzCOYvnU4CyFWficBgyjpGicPtyXLBM2jZ78w/132)

射杀百头 大约 2 个月前

863每个结点值是唯一的，直接当成编号

```
class Solution {

        vector<int>gra[501];

        vector<int>ans;

public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        dfs(root,NULL);

        int dis=0;

        bitset<501>vis;

        queue<int>q;

        q.push(target->val);

        vis[target->val]=1;

        while(q.size()){

            int siz=q.size();

            for(int i=0;i<siz;++i){

                int cur=q.front();

                q.pop();

                if(dis==k)ans.push_back(cur);

                for(int x:gra[cur]){

                    if(!vis[x]){

                        vis[x]=1;

                        q.push(x);

                    }

                }

            }

            dis++;

        } 

        return ans;       

    }

    void dfs(TreeNode*c,TreeNode*p){

        if(c==NULL)return;

        if(p)gra[p->val].push_back(c->val),gra[c->val].push_back(p->val);

        dfs(c->left,c);

        dfs(c->right,c);

    }

};
```

![Yuuuuu](https://thirdwx.qlogo.cn/mmopen/vi_32/3eLEXowzDITh7HtkklXC0bkPsWcmxLhElR558AsW1mHb9ltBqYzRtbLzEzmEBfzWJt1S2viaW8J1ZP2sNslruTw/132)

Yuuuuu 12 个月前

第三题不看题解，打死我也写不出来👀

该评论已被折叠