---
title: "DFS 和 BFS 的适用场景"
source: "https://labuladong.online/zh/algo/data-structure-basic/use-case-of-dfs-bfs/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-06
description: "本文介绍为什么 DFS 常用来穷举所有路径，BFS 常用来寻找最短路径。"
tags:
  - "clippings"
---
前置知识

阅读本文前，你需要先学习：

- [二叉树的递归/层序遍历](https://labuladong.online/zh/algo/data-structure-basic/binary-tree-traverse-basic/)

在实际的算法问题中，DFS 算法常用来穷举所有路径，BFS 算法常用来寻找最短路径，这是什么原因呢？

因为二叉树的递归遍历和层序遍历就是最简单的 DFS 算法和 BFS 算法，所以本文就用一道简单的二叉树例题，说明其中的道理。

## 为什么 BFS 常用来寻找最短路径

用可视化面板结合一道例题，你立刻就能明白了。

来看力扣第 111 题「 [二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) 」：

**111\. 二叉树的最小深度** | [力扣](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) | [LeetCode](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

**说明：** 叶子节点是指没有子节点的节点。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/10/12/ex_depth.jpg)
```
输入：root = [3,9,20,null,null,15,7]
输出：2
```

**示例 2：**

```
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
```

**提示：**

- 树中节点数的范围在 `[0, 10<sup>5</sup>]` 内
- `-1000 <= Node.val <= 1000`

题目来源： [力扣 111. 二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) 。

二叉树的最小深度即「 **根节点到最近的叶子节点的距离** 」，所以这道题本质上就是让你求最短距离。

DFS 递归遍历和 BFS 层序遍历都可以解决这道题，先看 DFS 递归遍历的解法：

```
class Solution {

private:

    // 记录最小深度（根节点到最近的叶子节点的距离）

    int minDepthValue = INT_MAX;

    // 记录当前遍历到的节点深度

    int currentDepth = 0;

public:

    int minDepth(TreeNode* root) {

        if (root == nullptr) {

            return 0;

        }

        // 从根节点开始 DFS 遍历

        traverse(root);

        return minDepthValue;

    }

    void traverse(TreeNode* root) {

        if (root == nullptr) {

            return;

        }

        // 前序位置进入节点时增加当前深度

        currentDepth++;

        // 如果当前节点是叶子节点，更新最小深度

        if (root->left == nullptr && root->right == nullptr) {

            minDepthValue = min(minDepthValue, currentDepth);

        }

        traverse(root->left);

        traverse(root->right);

        // 后序位置离开节点时减少当前深度

        currentDepth--;

    }

};
```

你可以点开下面这个可视化面板，点击其中 `if (root === null)` 这一行代码，即可看到递归函数 `traverse` 遍历二叉树节点的顺序。形象地说，它是从左到右，一条树枝一条树枝进行遍历的：

算法可视化

每当遍历到一条树枝的叶子节点，就会更新最小深度， **当遍历完整棵树后** ，就能算出整棵树的最小深度。

你能不能在不遍历完整棵树的情况下，提前结束算法？不可以，因为你必须确切的知道每条树枝的深度（根节点到叶子节点的距离），才能找到最小的那个。

下面来看 BFS 层序遍历的解法。按照 BFS 从上到下逐层遍历二叉树的特点，当遍历到第一个叶子节点时，就能得到最小深度：

```
class Solution {

public:

    int minDepth(TreeNode* root) {

        if (root == nullptr) return 0;

        queue<TreeNode*> q;

        q.push(root);

        // root 本身就是一层，depth 初始化为 1

        int depth = 1;

        while (!q.empty()) {

            int sz = q.size();

            // 遍历当前层的节点

            for (int i = 0; i < sz; i++) {

                TreeNode* cur = q.front();

                q.pop();

                // 判断是否到达叶子结点

                if (cur->left == nullptr && cur->right == nullptr)

                    return depth;

                // 将下一层节点加入队列

                if (cur->left != nullptr)

                    q.push(cur->left);

                if (cur->right != nullptr)

                    q.push(cur->right);

            }

            // 这里增加步数

            depth++;

        }

        return depth;

    }

};
```

你可以点开下面这个可视化面板，多次点击 `if (cur.left === null &&...` 这一行代码，最后点击 `let result` 这行代码，即可看到 BFS 一层一层遍历二叉树节点：

算法可视化

当它遍历到第二行的时候，就遇到第一个叶子节点了，这个叶子节点就是距离根节点最近的叶子节点，所以此时算法就结束了。BFS 算法并没有遍历整棵树就找到了最小深度。

综上，你应该能理解为啥 BFS 算法经常用来寻找最短路径了：

**由于 BFS 逐层遍历的逻辑，第一次遇到目标节点时，所经过的路径就是最短路径，算法可能并不需要遍历完所有节点就能提前结束** 。

DFS 遍历当然也可以用来寻找最短路径，但必须遍历完所有节点才能得到最短路径。

从时间复杂度的角度来看，两种算法在最坏情况下都会遍历所有节点，时间复杂度都是 $O(N)$ ，但在一般情况下，显然 BFS 算法的实际效率会更高。所以在寻找最短路径的问题中，BFS 算法是首选。

## 为什么 DFS 常用来寻找所有路径

在寻找所有路径的问题中，你会发现 DFS 算法用的比较多，BFS 算法似乎用的不多。

理论上两种遍历算法都是可以的，只不过 BFS 算法寻找所有路径的代码比较复杂，DFS 算法代码比较简洁。

你想啊，就以二叉树为例，如果要用 BFS 算法来寻找所有路径（根节点到每个叶子节点都是一条路径），队列里面就不能只放节点了，而需要使用 [二叉树层序遍历的第三种写法](https://labuladong.online/zh/algo/data-structure-basic/binary-tree-traverse-basic/) ，新建一个 `State` 类，把当前节点以及到达当前节点的路径都存进去，这样才能正确维护每个节点的路径，最终计算出所有路径。

而使用 DFS 算法就简单了，它本就是一条树枝一条树枝从左往右遍历的，每条树枝就是一条路径，递归遍历到叶子节点的时候递归路径就是一条树枝，所以 DFS 算法天然适合寻找所有路径。

最后结合代码和可视化面板讲解一下，先看 DFS 算法的可视化面板，你可以多次点击 `if (root === null)` 这部分代码，观察 DFS 算法遍历所有节点并收集根节点到叶子节点的所有路径：

算法可视化

再看 BFS 算法的可视化面板，你可以多次点击 `if (node.left === null &&...` 这部分代码，即可观察 BFS 算法遍历所有节点并收集根节点到叶子节点的所有路径。鼠标移动到下方生成的 bfs 树节点上，可以看到每个 `State` 中存储的路径：

算法可视化

结合可视化面板中的 JavaScript 代码，可以明显感觉 BFS 算法代码要复杂。

综上，DFS 算法在寻找所有路径的问题中更常用，而 BFS 算法在寻找最短路径的问题中更常用。

更新时间：2026/02/05 12:53

## 评论(20)

Markdown

Ctrl+Enter 发表

H

Hikari 11 个月前

东哥，收下我的膝盖！！！

Y

Yunchen Liu 6 个月前

关于这部分 `你能不能在不遍历完整棵树的情况下，提前结束算法？不可以，因为你必须确切的知道每条树枝的深度（根节点到叶子节点的距离），才能找到最小的那个。` 我理解DFS的版本也可以剪枝从而不遍历完整棵树？

```
public class MinimumDepthofBinaryTreePruneDFS implements MinimumDepthofBinaryTree111{
    int minDepthRecord = Integer.MAX_VALUE;

    @Override
    public int minDepth(TreeNode root) {
        DFS(root, 0);
        return this.minDepthRecord != Integer.MAX_VALUE ? this.minDepthRecord : 0;
    }

    private void DFS(TreeNode root, int depth) {
        if (root == null) {
            return;
        }
        depth += 1;
        if (root.left == null && root.right == null) {
            this.minDepthRecord = Math.min(this.minDepthRecord, depth);
            return;
        }
        if (depth >= this.minDepthRecord) {
            return;
        }
        if (root.left != null) {
            DFS(root.left, depth);
        }
        if (root.right != null) {
            DFS(root.right, depth);
        }
    }
}
```

只不过即使剪枝的效果不如BFS的好？比如如果一个树最左侧的path特别长，其他的都是depth为2，这样DFS即使剪枝也会需要遍历左侧这个特别长的path，但BFS就没这个问题。不知道理解的对不对。

L

labuladong 东哥 5 个月前

嗯，这确实是个很好的优化~ 记录当前已访问过的最小深度，如果遇到更深的，就不用完全遍历，效率比全量遍历要好。不过大部分情况还是比不过层序，因为逐层的遍历方式就决定了它一点多余的遍历都没有，是寻找最短路径的最优方案。

欢

欢乐马 8 个月前

这下子把图算法和二叉树算法打通了。舒畅。谢谢大神

D

Daria 9 个月前

111 题 用dfs解决确实比较简单一些

```
class Solution {
    private int dfs(TreeNode root){
        if(root==null){
            return 0;
        }
        if(root.left==null){
            return 1+dfs(root.right);
        }else if(root.right==null){
            return 1+dfs(root.left);
        }

        //both children are not null, hence call for both children
        return 1+ Math.min(dfs(root.left),dfs(root.right));
    }
    public int minDepth(TreeNode root) {
        return dfs(root);
        
    }
}
```

L

labuladong 东哥 8 个月前

1. 你这个严格来讲不算是 DFS 遍历的思路，而是分解问题的思路，以往后学习会讲到这两种思维模式的差别。
2. 你这个算法虽然从代码上看比较简洁，但是必须要遍历所有节点，实际运行效率会比 BFS 差。「不需要遍历完所有节点就可能找到答案」是 BFS 的优势所在。

神

神经蛙 9 个月前

问一下大家哈，虽然我是能理解这个算法，但是为什么这边用的： DFS 递归遍历是前序遍历啊？判断minDepthValue的位置在traverse的前面 不是说这个位置信息最少吗？

L

labuladong 东哥 9 个月前

最少，但够用。你放到前中后序都是可以的，区别不大。

朱

朱帅 6 个月前

名字头像都一样，还以为我自己评论的

L

laaaaaaaaaag 10 个月前

这道题用BFS算法的时候，函数最后不用return depth好像也可以？

用

用户\_3133 9 个月前

试了一下确实可以不用,因为遇到叶子节点就直接return结果了,非空的树里面一定有叶子节点.

S

Swift 8 个月前

编译检查的时候 函数最后一定要有个return

L

labuladong 东哥 8 个月前

是的，必然会遇到 null return。但是有些编程语言要求函数必须有一个 return，即便永远不会执行。

龚

龚山 4 个月前

第二次买东哥的会员，必须给东哥点个赞，一如既往的给力

S

Self 4 个月前

文中好像没有提及定义,我是小白 我感觉没有定义的话 英文字母容易混淆

DFS即Depth First Search，深度优先搜索。简单地理解为一条路走到黑。 BFS即Breadth First Search，即广度优先搜索。如果说DFS是一条路走到黑的话，BFS就完全相反了。BFS会在每个岔路口都各向前走一步。

K

Kumonami云 8 个月前

看到这章举一反三下BFS算法在有权重的情况下的初级用法： 遍历某一层时，如果该层所有的节点权重和皆大于已知的上层已知最小叶子节点，则那个最小的上层叶子节点为加权后的最短路径，遍历结束。 如果该层有叶子节点小于同层其他节点和已知的上层最小叶子节点，则该叶子节点为最短路径。 如果该层的最小叶子节点仅仅小于上层的最小叶子节点，大于同层的某些非叶子节点（记为集合A），则更新上层最小的叶子节点，后续层序遍历只用遍历集合A下的子节点。 如果该层的最小叶子节点大于已知的上层最小叶子节点，则找出该层小于已知最小节点的所有节点（记为集合B），后续层序遍历只用遍历集合B下的子节点。

L

Luke J 5 个月前

谢谢分享

H

hao 5 个月前

要点记录：

1. 由于 BFS 逐层遍历的逻辑，第一次遇到目标节点时，所经过的路径就是最短路径，算法可能并不需要遍历完所有节点就能提前结束。DFS 遍历当然也可以用来寻找最短路径，但必须遍历完所有节点才能得到最短路径。DFS更适合寻找所有路径。

H

Hunter 6 个月前

day5打卡 DFS算法更适合寻找所有路径，BFS算法更适合寻找最短路径

B

Bryan Lin 6 个月前

打卡