---
title: "Kruskal 最小生成树算法"
source: "https://labuladong.online/zh/algo/data-structure/kruskal/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文由并查集算法拓展出 Kruskal 最小生成树算法，详细讲解实现原理，解决力扣/LeetCode 的相关例题，同时给出 Java/Python/Go/JavaScript/C++ 代码实现。"
tags:
  - "clippings"
---
读完本文，你不仅学会了算法套路，还可以顺便解决如下题目：

| LeetCode | 力扣 | 难度 |
| --- | --- | --- |
| [261\. Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/) 🔒 | [261\. 以图判树](https://leetcode.cn/problems/graph-valid-tree/) 🔒 |  |
| [1135\. Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/) 🔒 | [1135\. 最低成本连通所有城市](https://leetcode.cn/problems/connecting-cities-with-minimum-cost/) 🔒 |  |
| [1584\. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) | [1584\. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points/) |  |

前置知识

阅读本文前，你需要先学习：

- [Union-Find 并查集算法](https://labuladong.online/zh/algo/data-structure/union-find/)
- [最小生成树算法概览](https://labuladong.online/zh/algo/data-structure-basic/graph-minimum-spanning-tree/)

一句话总结

Kruskal 算法是求解无向图中最小生成树的经典算法。

其本质是贪心思想，先排序，再借助 [并查集](https://labuladong.online/zh/algo/data-structure-basic/union-find-basic/) 判断是否形成环。

[最小生成树算法概览](https://labuladong.online/zh/algo/data-structure-basic/graph-minimum-spanning-tree/) 讲解了最小生成树的定义及实际运用场景，没看过的话需要先看下。

最小生成树算法主要有 Prim 算法和 Kruskal 算法两种，这两种算法从原理上讲都是运用贪心思想，但从实现上来说差异还是蛮大的。

本文先来讲比较简单易懂的 Kruskal 算法，然后在下一篇文章中聊 Prim 算法。

Kruskal 算法其实很容易理解和记忆，其关键是要熟悉并查集算法，如果不熟悉，建议先看下前文 [Union-Find 并查集算法](https://labuladong.online/zh/algo/data-structure/union-find/) 。

在讲 Kruskal 算法之前，先回顾一下 Union-Find 并查集算法。

## Union-Find 并查集算法

刚才说了，图的生成树是含有其所有顶点的「无环连通子图」，最小生成树是权重和最小的生成树。

那么说到连通性，相信老读者应该可以想到 Union-Find 并查集算法，用来高效处理图中联通分量的问题。

前文 [Union-Find 并查集算法详解](https://labuladong.online/zh/algo/data-structure/union-find/) 详细介绍了 Union-Find 算法的实现原理和一些应用场景，主要运用路径压缩技巧提高连通分量的判断效率。

如果不了解 Union-Find 算法的读者可以去看前文，为了节约篇幅，本文直接给出 Union-Find 算法的实现：

```
class UF {

private:

    // 连通分量个数

    int _count;

    // 存储每个节点的父节点

    vector<int> parent;

public:

    // n 为图中节点的个数

    UF(int n) {

        this->_count = n;

        this->parent.resize(n);

        for (int i = 0; i < n; i++) {

            parent[i] = i;

        }

    }

    

    // 将节点 p 和节点 q 连通

    void union_(int p, int q) {

        int rootP = find(p);

        int rootQ = find(q);

        

        if (rootP == rootQ)

            return;

        

        parent[rootQ] = rootP;

        // 两个连通分量合并成一个连通分量

        _count--;

    }

    // 判断节点 p 和节点 q 是否连通

    bool connected(int p, int q) {

        int rootP = find(p);

        int rootQ = find(q);

        return rootP == rootQ;

    }

    int find(int x) {

        if (parent[x] != x) {

            parent[x] = find(parent[x]);

        }

        return parent[x];

    }

    // 返回图中的连通分量个数

    int count() {

        return _count;

    }

};
```

Kruskal 算法的一个难点是保证生成树的合法性，因为在构造生成树的过程中，你首先得保证生成的那玩意是棵树（不包含环）对吧，那么 Union-Find 算法就是帮你干这个事儿的。怎么做到的呢？先来看看力扣第 261 题「 [以图判树](https://leetcode.cn/problems/graph-valid-tree/) 」，我描述下题目：

给你输入编号从 `0` 到 `n - 1` 的 `n` 个结点，和一个无向边列表 `edges` （每条边用节点二元组表示），请你判断输入的这些边组成的结构是否是一棵树。

函数签名如下：

```
bool validTree(int n, vector<vector<int>>& edges);
```

比如输入如下：

```
n = 5

edges = [[0,1], [0,2], [0,3], [1,4]]
```

这些边构成的是一棵树，算法应该返回 true：

![](https://labuladong.online/images/algo/kruskal/2.png)

但如果输入：

```
n = 5

edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
```

形成的就不是树结构了，因为包含环：

![](https://labuladong.online/images/algo/kruskal/3.png)

**对于这道题，我们可以思考一下，什么情况下加入一条边会使得树变成图（出现环）** ？

显然，像下面这样添加边会出现环：

![](https://labuladong.online/images/algo/kruskal/4.png)

而这样添加边则不会出现环：

![](https://labuladong.online/images/algo/kruskal/5.png)

总结规律

对于添加的这条边，如果该边的两个节点本来就在同一连通分量里，那么添加这条边会产生环；反之，如果该边的两个节点不在同一连通分量里，则添加这条边不会产生环。

而判断两个节点是否连通（是否在同一个连通分量中）就是 Union-Find 算法的拿手绝活，所以这道题的解法代码如下：

```
class Solution {

public:

    bool validTree(int n, vector<vector<int>>& edges) {

        // 初始化 0...n-1 共 n 个节点

        UF uf(n);

        // 遍历所有边，将组成边的两个节点进行连接

        for (const auto& edge : edges) {

            int u = edge[0];

            int v = edge[1];

            // 若两个节点已经在同一连通分量中，会产生环

            if (uf.connected(u, v)) {

                return false;

            }

            // 这条边不会产生环，可以是树的一部分

            uf.unionNodes(u, v);

        }

        // 要保证最后只形成了一棵树，即只有一个连通分量

        return uf.getCount() == 1;

    }

private:

    class UF {

    public:

        // 连通分量个数

        int count;

        // 存储一棵树

        vector<int> parent;

        // 记录树的「重量」

        vector<int> size;

        // n 为图中节点的个数

        UF(int n) : count(n), parent(n), size(n, 1) {

            for (int i = 0; i < n; ++i) {

                parent[i] = i;

            }

        }

        // 将节点 p 和节点 q 连通

        void unionNodes(int p, int q) {

            int rootP = find(p);

            int rootQ = find(q);

            if (rootP == rootQ)

                return;

            // 小树接到大树下面，较平衡

            if (size[rootP] > size[rootQ]) {

                parent[rootQ] = rootP;

                size[rootP] += size[rootQ];

            } else {

                parent[rootP] = rootQ;

                size[rootQ] += size[rootP];

            }

            // 两个连通分量合并成一个连通分量

            --count;

        }

        // 判断节点 p 和节点 q 是否连通

        bool connected(int p, int q) {

            return find(p) == find(q);

        }

        // 返回图中的连通分量个数

        int getCount() const {

            return count;

        }

    private:

        // 返回节点 x 的连通分量根节点

        int find(int x) {

            while (parent[x] != x) {

                // 进行路径压缩

                parent[x] = parent[parent[x]];

                x = parent[x];

            }

            return x;

        }

    };

};
```

可视化面板支持展示图结构和并查集结构，你可以点开下面的面板查看算法的执行过程：

算法可视化

如果你能够看懂这道题的解法思路，那么掌握 Kruskal 算法就很简单了。

## Kruskal 算法

所谓最小生成树，就是图中若干边的集合（我们后文称这个集合为 `mst` ，最小生成树的英文缩写），你要保证这些边：

1、包含图中的所有节点。

2、形成的结构是树结构（即不存在环）。

3、权重和最小。

有之前题目的铺垫，前两条其实可以很容易地利用 Union-Find 算法做到，关键在于第 3 点，如何保证得到的这棵生成树是权重和最小的。

这里就用到了贪心思路：

**将所有边按照权重从小到大排序，从权重最小的边开始遍历，如果这条边和 `mst` 中的其它边不会形成环，则这条边是最小生成树的一部分，将它加入 `mst` 集合；否则，这条边不是最小生成树的一部分，不要把它加入 `mst` 集合** 。

这样，最后 `mst` 集合中的边就形成了最小生成树，下面我们看两道例题来运用一下 Kruskal 算法。

## 1135\. 最低成本联通所有城市

第一题是力扣第 1135 题「 [最低成本联通所有城市](https://leetcode.cn/problems/connecting-cities-with-minimum-cost/) 」，这是一道标准的最小生成树问题：

给你输入数组 `conections` ，其中 `connections[i] = [xi, yi, costi]` 表示将城市 `xi` 和城市 `yi` 连接所要的 `costi` （连接是双向的），请你计算连接所有城市的最小成本。

函数签名如下：

```
int minimumCost(int n, vector<vector<int>>& connections);
```

每座城市相当于图中的节点，连通城市的成本相当于边的权重，连通所有城市的最小成本即是最小生成树的权重之和。

```
class Solution {

public:

    int minimumCost(int n, vector<vector<int>>& connections) {

        // 城市编号为 1...n，所以初始化大小为 n + 1

        UF uf(n + 1);

        // 对所有边按照权重从小到大排序

        sort(connections.begin(), connections.end(),  {

            return a[2] < b[2];

        });

        // 记录最小生成树的权重之和

        int mst = 0;

        for (const auto& edge : connections) {

            int u = edge[0];

            int v = edge[1];

            int weight = edge[2];

            // 若这条边会产生环，则不能加入 mst

            if (uf.connected(u, v)) {

                continue;

            }

            // 若这条边不会产生环，则属于最小生成树

            mst += weight;

            uf.unionNodes(u, v);

        }

        // 保证所有节点都被连通

        // 按理说 uf.count() == 1 说明所有节点被连通

        // 但因为节点 0 没有被使用，所以 0 会额外占用一个连通分量

        return uf.getCount() == 2 ? mst : -1;

    }

private:

    class UF {

    public:

        // 连通分量个数

        int count;

        // 存储一棵树

        vector<int> parent;

        // 记录树的「重量」

        vector<int> size;

        // n 为图中节点的个数

        UF(int n) : count(n), parent(n), size(n, 1) {

            for (int i = 0; i < n; ++i) {

                parent[i] = i;

            }

        }

        // 将节点 p 和节点 q 连通

        void unionNodes(int p, int q) {

            int rootP = find(p);

            int rootQ = find(q);

            if (rootP == rootQ)

                return;

            // 小树接到大树下面，较平衡

            if (size[rootP] > size[rootQ]) {

                parent[rootQ] = rootP;

                size[rootP] += size[rootQ];

            } else {

                parent[rootP] = rootQ;

                size[rootQ] += size[rootP];

            }

            // 两个连通分量合并成一个连通分量

            count--;

        }

        // 判断节点 p 和节点 q 是否连通

        bool connected(int p, int q) {

            return find(p) == find(q);

        }

        // 返回节点 x 的连通分量根节点

        int find(int x) {

            while (parent[x] != x) {

                // 进行路径压缩

                parent[x] = parent[parent[x]];

                x = parent[x];

            }

            return x;

        }

        // 返回图中的连通分量个数

        int getCount() {

            return count;

        }

    };

};
```

算法可视化

这道题就解决了，整体思路和上一道题非常类似，你可以认为树的判定算法加上按权重排序的逻辑就变成了 Kruskal 算法。

## 1584\. 连接所有点的最小费用

再来看看力扣第 1584 题「 [连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points/) 」：

**1584\. 连接所有点的最小费用** | [力扣](https://leetcode.cn/problems/min-cost-to-connect-all-points/) | [LeetCode](https://leetcode.com/problems/min-cost-to-connect-all-points/)

给你一个 `points`  数组，表示 2D 平面上的一些点，其中  `points[i] = [x<sub>i</sub>, y<sub>i</sub>]` 。

连接点 `[x<sub>i</sub>, y<sub>i</sub>]` 和点 `[x<sub>j</sub>, y<sub>j</sub>]` 的费用为它们之间的 **曼哈顿距离** ： `|x<sub>i</sub> - x<sub>j</sub>| + |y<sub>i</sub> - y<sub>j</sub>|` ，其中 `|val|` 表示 `val` 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 **有且仅有** 一条简单路径时，才认为所有点都已连接。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/08/26/d.png)

```
输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
输出：20
解释：

我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
注意到任意两个点之间只有唯一一条路径互相到达。
```

**示例 2：**

```
输入：points = [[3,12],[-2,5],[-4,1]]
输出：18
```

**示例 3：**

```
输入：points = [[0,0],[1,1],[1,0],[-1,1]]
输出：4
```

**示例 4：**

```
输入：points = [[-1000000,-1000000],[1000000,1000000]]
输出：4000000
```

**示例 5：**

```
输入：points = [[0,0]]
输出：0
```

**提示：**

- `1 <= points.length <= 1000`
- `-10<sup>6</sup> <= x<sub>i</sub>, y<sub>i</sub> <= 10<sup>6</sup>`
- 所有点 `(x<sub>i</sub>, y<sub>i</sub>)` 两两不同。

题目来源： [力扣 1584. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points/) 。

```
// 函数签名如下

int minCostConnectPoints(vector<vector<int>>& points);
```

很显然这也是一个标准的最小生成树问题：每个点就是无向加权图中的节点，边的权重就是曼哈顿距离，连接所有点的最小费用就是最小生成树的权重和。

所以解法思路就是先生成所有的边以及权重，然后对这些边执行 Kruskal 算法即可：

```
class Solution {

public:

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // 生成所有边及权重

        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {

            for (int j = i + 1; j < n; ++j) {

                int xi = points[i][0], yi = points[i][1];

                int xj = points[j][0], yj = points[j][1];

                // 用坐标点在 points 中的索引表示坐标点

                edges.push_back({i, j, abs(xi - xj) + abs(yi - yj)});

            }

        }

        // 将边按照权重从小到大排序

        sort(edges.begin(), edges.end(),  {

            return a[2] < b[2];

        });

        // 执行 Kruskal 算法

        int mst = 0;

        UF uf(n);

        for (const auto& edge : edges) {

            int u = edge[0];

            int v = edge[1];

            int weight = edge[2];

            // 若这条边会产生环，则不能加入 mst

            if (uf.connected(u, v)) {

                continue;

            }

            // 若这条边不会产生环，则属于最小生成树

            mst += weight;

            uf.unionNodes(u, v);

        }

        return mst;

    }

private:

    class UF {

    public:

        // 连通分量个数

        int count;

        // 存储一棵树

        vector<int> parent;

        // 记录树的「重量」

        vector<int> size;

        // n 为图中节点的个数

        UF(int n) : count(n), parent(n), size(n, 1) {

            for (int i = 0; i < n; ++i) {

                parent[i] = i;

            }

        }

        // 将节点 p 和节点 q 连通

        void unionNodes(int p, int q) {

            int rootP = find(p);

            int rootQ = find(q);

            if (rootP == rootQ) return;

            // 小树接到大树下面，较平衡

            if (size[rootP] > size[rootQ]) {

                parent[rootQ] = rootP;

                size[rootP] += size[rootQ];

            } else {

                parent[rootP] = rootQ;

                size[rootQ] += size[rootP];

            }

            // 两个连通分量合并成一个连通分量

            --count;

        }

        // 判断节点 p 和节点 q 是否连通

        bool connected(int p, int q) {

            return find(p) == find(q);

        }

        // 返回节点 x 的连通分量根节点

        int find(int x) {

            while (parent[x] != x) {

                // 进行路径压缩

                parent[x] = parent[parent[x]];

                x = parent[x];

            }

            return x;

        }

        // 返回图中的连通分量个数

        int countComponents() {

            return count;

        }

    };

};
```

算法可视化

这道题做了一个小的变通：每个坐标点是一个二元组，那么按理说应该用五元组 `(x_i, y_i, x_j, y_j, weight)` 表示一条带权重的边，但这样的话不便执行 Union-Find 算法；所以我们用 `points` 数组中的索引代表每个坐标点，这样就可以直接复用之前的 Kruskal 算法逻辑了。

通过以上三道算法题，相信你已经掌握了 Kruskal 算法，主要的难点是利用 Union-Find 并查集算法向最小生成树中添加边，配合排序的贪心思路，从而得到一棵权重之和最小的生成树。

最后说下 Kruskal 算法的复杂度分析：

假设一幅图的节点个数为 `V` ，边的条数为 `E` ，首先需要 $O(E)$ 的空间装所有边，而且 Union-Find 算法也需要 $O(V)$ 的空间，所以 Kruskal 算法总的空间复杂度就是 $O(V + E)$ 。

时间复杂度主要耗费在排序，需要 $O(ElogE)$ 的时间，Union-Find 算法所有操作的复杂度都是 $O(1)$ ，套一个 for 循环也不过是 $O(E)$ ，所以总的时间复杂度为 $O(ElogE)$ 。

本文就到这里，关于 Prim 最小生成树算法，我们在 [Prim 算法模板](https://labuladong.online/zh/algo/data-structure/prim/) 中聊。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表