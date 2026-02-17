---
title: "Prim 最小生成树算法"
source: "https://labuladong.online/zh/algo/data-structure/prim/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文讲解 Prim 最小生成树算法，介绍切分定理，运用优先级队列实现贪心思想求解最小生成树，解决力扣/LeetCode 的相关例题，同时给出 Java/Python/Go/JavaScript/C++ 代码实现。"
tags:
  - "clippings"
---
读完本文，你不仅学会了算法套路，还可以顺便解决如下题目：

| LeetCode | 力扣 | 难度 |
| --- | --- | --- |
| [1135\. Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/) 🔒 | [1135\. 最低成本连通所有城市](https://leetcode.cn/problems/connecting-cities-with-minimum-cost/) 🔒 |  |
| [1584\. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) | [1584\. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points/) |  |

前置知识

阅读本文前，你需要先学习：

- [图结构基础及通用实现](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/)
- [Dijkstra 原理及实现](https://labuladong.online/zh/algo/data-structure/dijkstra/)

一句话总结

Prim 算法是求解无向图中最小生成树的经典算法。

只需要对 Dijkstra 算法稍作修改，即可得到 Prim 算法。

前文讲解的 [Kruskal 算法](https://labuladong.online/zh/algo/data-structure/kruskal/) 最小生成树算法的核心思路是：先排好序，然后借助 [并查集](https://labuladong.online/zh/algo/data-structure-basic/union-find-basic/) 组装最小生成树。

从思路上讲，Prim 算法的本质是 BFS + 贪心思想，一边排序一边组装最小生成树，相当于 Kruskal 算法先排序后组装的动态过程。

从代码的角度来看，Prim 算法和 Dijkstra 算法非常相似，只需修改几行代码，就可以把 Dijkstra 算法变成 Prim 算法。所以在学习 Prim 算法之前，需要你彻底理解 [Dijkstra 算法原理及实现](https://labuladong.online/zh/algo/data-structure/dijkstra/) 。

本文先展示 Prim 算法的代码实现，然后再讲解其原理，以及为什么可以直接从 Dijkstra 算法代码推导出 Prim 算法代码。

## Prim 算法代码

仅需修改 [Dijkstra 算法模板](https://labuladong.online/zh/algo/data-structure/dijkstra/) 中的几行代码即可得到 Prim 算法，修改部分已经高亮显示：

```
#include <vector>

#include <queue>

using namespace std;

class State {

    // 当前节点 ID

    int node;

    // 进入该节点的边的权重

    int weight;

public:

    State(int node, int weight) : node(node), weight(weight) {}

    int getNode() const { return node; }

    int getWeight() const { return weight; }

};

// Compare functor for priority queue

struct Compare {

    bool operator()(const State& a, const State& b) const {

        // smaller weight has higher priority

        return a.getWeight() > b.getWeight();

    }

};

// 输入加权无环图 graph（可包含负权重边）

// 返回最小生成树的权重和

int prim(Graph& graph) {

    // 记录最小生成树的权重和

    int weightSum = 0;

    // 记录每个节点是否被访问过，默认初始化为 false

    vector<bool> visited(graph.length);

    // 优先级队列，weight 较小的节点排在前面

    priority_queue<State, vector<State>, Compare> pq;

    // 可以从任意一个节点开始构建最小生成树

    pq.emplace(0, 0);

    while (!pq.empty()) {

        State state = pq.top();

        pq.pop();

        int curNode   = state.getNode();

        int curWeight = state.getWeight();

        if (visited[curNode]) {

            continue;

        }

        // curNode 节点第一次出队时，就找到了一条最小生成树的边

        // 更新最小生成树的权重和

        weightSum += curWeight;

        visited[curNode] = true;

        for (Edge e : graph.neighbors(curNode)) {

            int nextNode   = e.to;

            int nextWeight = e.weight;

            if (visited[nextNode]) {

                continue;

            }

            pq.emplace(nextNode, nextWeight);

        }

    }

    // 最后检查是否所有节点都被访问过

    // 如果存在未被访问的节点，说明图不是连通的，返回 -1

    for (int i = 0; i < (int)visited.size(); i++) {

        if (!visited[i]) {

            return -1;

        }

    }

    return weightSum;

}
```

你可以对比一下 Dijkstra 算法的代码，是不是非常相似？

```
// 记录队列中的状态

struct State {

    // 当前节点 ID

    int node;

    // 从起点 s 到当前 node 节点的最小路径权重和

    int distFromStart;

    State(int _node, int _distFromStart)

        : node(_node), distFromStart(_distFromStart) {}

};

// 自定义比较器，使得 distFromStart 较小的 State 先出队

struct Compare {

    bool operator()(const State& a, const State& b) const {

        return a.distFromStart > b.distFromStart;

    }

};

// 输入不包含负权重边的加权图 graph 和起点 src

// 返回从起点 src 到其他节点的最小路径权重和

std::vector<int> dijkstra(Graph& graph, int src) {

    // 记录从起点 src 到其他节点的最小路径权重和

    // distTo[i] 表示从起点 src 到节点 i 的最小路径权重和

    std::vector<int> distTo(graph.size(), INT_MAX);

    // 优先级队列，distFromStart 较小的节点排在前面

    std::priority_queue<State, std::vector<State>, Compare> pq;

    // 从起点 src 开始进行 BFS

    pq.emplace(src, 0);

    distTo[src] = 0;

    while (!pq.empty()) {

        State state = pq.top();

        pq.pop();

        int curNode = state.node;

        int curDistFromStart = state.distFromStart;

        if (distTo[curNode] < curDistFromStart) { // [!code highlight:5]

            // 在 Dijkstra 算法中，队列中可能存在重复的节点 state

            // 所以要在元素出队时进行判断，去除较差的重复节点

            continue;

        }

        for (const Edge& e : graph.neighbors(curNode)) {

            int nextNode = e.to;

            int nextDistFromStart = curDistFromStart + e.weight;

            if (distTo[nextNode] <= nextDistFromStart) {

                continue;

            }

            // [!code highlight:6]

            // 将 nextNode 节点加入优先级队列

            pq.emplace(nextNode, nextDistFromStart);

            // 记录 nextNode 节点到起点的最小路径权重和

            distTo[nextNode] = nextDistFromStart;

        }

    }

    return distTo;

}
```

最主要的改动是 `State` 中用 `weight` 字段存储进入该节点的那条边的权重，优先级队列会把 `weight` 较小的节点排在前面。

还有就是 Dijkstra 算法中用 `distTo` 数组记录起点到每个节点的最小路径权重和，在入队的时候更新 `distTo` 数组的值。

而 Prim 算法用一个 `visited` 数组记录哪些节点已访问（已经被加入最小生成树），仅在出队的时候标记为 true。

注意图的种类

虽然说只需要稍加修改 Dijkstra 算法即可得到 Prim 算法，但要注意两种算法对图的类型要求并不一样。

1、Dijkstra 算法可以同时适用于有向图和无向图，而 Prim 算法只能解决无向图中的最小生成树问题。

2、Dijkstra 算法要求图中不能存在负权重边，而 Prim 算法并没有这个限制。

稍后我们会讲解原因。

## 切分定理

为了论证上述代码是正确的，首先我们要了解「切分定理」。

所谓「切分」就是将一幅图分为两个 **不重叠且非空** 的节点集合：

![](https://labuladong.online/images/algo/prim/1.jpeg)

术语：切分和横切边

红色的这一刀把图中的节点分成了两个集合，就是一种「 **切分** 」，其中被红线切中的的边（标记为蓝色）叫做「 **横切边** 」。

记住这两个专业术语的意思，后面我们会频繁使用这两个词，别搞混了。

当然，一幅图肯定可以有若干种切分，因为根据切分的定义，只要你能一刀把节点分成两部分就行。接下来我们引入「切分定理」。

切分定理

**对于任意一种「切分」，其中权重最小的那条「横切边」一定是构成最小生成树的一条边** 。

这应该很容易证明，如果一幅加权无向图存在最小生成树，假设下图中用绿色标出来的边就是最小生成树：

![](https://labuladong.online/images/algo/prim/2.jpeg)

那么，你肯定可以找到若干「切分」方式，将这棵最小生成树切成两棵子树。比如下面这种切分：

![](https://labuladong.online/images/algo/prim/3.jpeg)

你会发现，任选一条蓝色的「横切边」都可以将这两棵子树连接起来，构成一棵生成树。

那么为了让最终这棵生成树的权重和最小，你说你要怎么选？

肯定选权重最小的那条「横切边」对吧，这就证明了切分定理。

关于切分定理，你也可以用反证法证明：

首先证明存在性，给定一幅图的最小生成树，那么随便给一种「切分」，一定至少有一条「横切边」属于最小生成树。

因为最小生成树要包含所有节点，一个切分会把节点切成两个集合，那么一定有一条边跨越这两个集合来组成最小生成树。

其次证明，一个「切分」中权重最小的那条「横切边」一定属于最小生成树。如果不是的话，说明你这个最小生成树的权重和不是最小的，与最小生成树的定义矛盾。

有了切分定理，就可以 **利用贪心思想，逐步确定哪些边属于最小生成树** 。

可以处理负权重边

Prim 算法可以由 Dijkstra 算法修改而来，Dijkstra 算法无法处理负权重边，而 Prim 算法可以处理负权重边。

现在应该能看出原因了，因为即便存在负权重边，切分定理依然是有效的。

## 算法的正确性

我们可以从任意一个节点开始执行 BFS 算法，就从节点 `0` 开始吧，和上述代码保持一致。

现在想象一下，我们此时站在起点 `0` 上，仅能通过图结构的 API 获取节点 `0` 的邻居节点以及边的权重，假设是这样，边 `0-4` 的权重为 2，边 `0-3` 的权重为 7：

![](https://labuladong.online/images/algo/prim/p1.jpg)

根据切分定理，我们可以判断 `0-4` 这条边是属于最小生成树的。

接下来，我们可以查看节点 `4` 的相邻节点及边的权重，假设是下图这样：

![](https://labuladong.online/images/algo/prim/p2.jpg)

根据切分定理，我可以判断 `4-9` 这条边属于最小生成树。

![](https://labuladong.online/images/algo/prim/p3.jpg)

因为我们可以创建一个穿过 `0-3, 4-9, 4-2` 这几条边的切分，其中 `4-9` 是权重最小的横切边，所以 `4-9` 一定属于最小生成树。

以此类推，继续查看节点 `9` 的相邻节点及边的权重，重复上述流程，直到所有节点都被访问过，最小生成树就构建完成了。

现在你再看代码实现，是不是就很清晰了？

`State` 中记录了每条边的权重，优先级队列让权重较小的边先出队，所以每次从队列中取出的边一定是最小的横切边，如果这个节点还未被访问，则将这条边加入最小生成树。

## 复杂度分析

Prim 算法代码是从 Dijkstra 算法修改而来的，所以复杂度和 Dijkstra 算法几乎完全相同的。

唯一的区别是 Prim 算法最后要检查 `visited` 数组，判断是否所有节点都被访问过，所以会多一个 $O(V)$ 的遍历时间。

所以本文实现的 Prim 算法的时间复杂度是 $O(ElogE + V)$ ，空间复杂度是 $O(V + E)$ 。

## 题目实践

第一题是力扣第 1135 题「 [最低成本联通所有城市](https://leetcode.cn/problems/connecting-cities-with-minimum-cost/) 」，这是一道标准的最小生成树问题：

给你输入数组 `conections` ，其中 `connections[i] = [xi, yi, costi]` 表示将城市 `xi` 和城市 `yi` 连接所要的 `costi` （连接是双向的），请你计算连接所有城市的最小成本。

函数签名如下：

```
int minimumCost(int n, vector<vector<int>>& connections);
```

每座城市相当于图中的节点，连通城市的成本相当于边的权重，连通所有城市的最小成本即是最小生成树的权重之和。

那么解法就很明显了，我们先把题目输入的 `connections` 转化成邻接表形式，然后输入给之前实现的 `prim` 算法即可：

```
class Solution {

    struct State {

        // 当前节点 ID

        int node;

        // 进入该节点的边的权重

        int weight;

        State(int node, int weight) : node(node), weight(weight) {}

        bool operator<(const State& other) const {

            return weight > other.weight;

        }

    };

    int prim(vector<vector<pair<int, int>>>& graph) {

        int weightSum = 0;

        vector<bool> visited(graph.size(), false);

        priority_queue<State> pq;

        pq.push(State(0, 0));

        while (!pq.empty()) {

            State state = pq.top();

            pq.pop();

            int curNode = state.node;

            int curWeight = state.weight;

            if (visited[curNode]) {

                continue;

            }

            weightSum += curWeight;

            visited[curNode] = true;

            for (auto& neighbor : graph[curNode]) {

                int nextNode = neighbor.first;

                int nextWeight = neighbor.second;

                if (visited[nextNode]) {

                    continue;

                }

                pq.push(State(nextNode, nextWeight));

            }

        }

        // 最后检查是否所有节点都被访问过

        // 如果存在未被访问的节点，说明图不是连通的，返回 -1

        for (int i = 0; i < visited.size(); i++) {

            if (!visited[i]) {

                return -1;

            }

        }

        return weightSum;

    }

    // 转化成无向图邻接表的形式

    vector<vector<pair<int, int>>> buildGraph(int n, vector<vector<int>>& connections) {

        // 图中共有 n 个节点

        vector<vector<pair<int, int>>> graph(n);

        for (const auto& conn : connections) {

            // 题目给的节点编号是从 1 开始的，

            // 但我们实现的 Prim 算法需要从 0 开始编号

            int u = conn[0] - 1;

            int v = conn[1] - 1;

            int weight = conn[2];

            // 「无向图」其实就是「双向图」

            graph[u].emplace_back(v, weight);

            graph[v].emplace_back(u, weight);

        }

        return graph;

    }

public:

    int minimumCost(int n, vector<vector<int>>& connections) {

        auto graph = buildGraph(n, connections);

        return prim(graph);

    }

};
```

关于 `buildGraph` 函数需要注意两点：

一是题目给的节点编号是从 1 开始的，所以我们做一下索引偏移，转化成从 0 开始以便复用算法模板。

二是如何用邻接表表示无向加权图，前文 [图论算法基础](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) 说过「无向图」其实就可以理解为「双向图」。

这样，我们转化出来的 `graph` 形式就和之前的 `prim` 算法对应了，可以直接复用代码计算最小生成树。

你可以点开下面的可视化面板，多次点击 `while (!this.pq.isEmpty())` 这一行代码即可看到 Prim 算法的计算过程，其中粉色的是横切边，绿色的是加入最小生成树的边，红色的是排除的边：

算法可视化

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

所以我们只要把 `points` 数组转化成邻接表的形式，即可复用之前实现的 `prim` 算法：

```
class Solution {

public:

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<vector<pair<int, int>>> graph = buildGraph(n, points);

        // 使用 Prim 算法计算最小生成树

        // https://labuladong.online/algo/data-structure/prim/

        return prim(graph);

    }

    struct State {

        // 当前节点 ID，本题中是 points 中的索引

        int node;

        // 进入该节点的边的权重

        int weight;

        State(int node, int weight) : node(node), weight(weight) {}

        // For priority_queue, smaller weight comes first

        bool operator>(const State& other) const {

            return weight > other.weight;

        }

    };

    int prim(vector<vector<pair<int, int>>>& graph) {

        int weightSum = 0;

        vector<bool> visited(graph.size(), false);

        // 优先级队列，weight 较小的节点排在前面

        priority_queue<State, vector<State>, greater<State>> pq;

        // 可以从任意一个节点开始构建最小生成树

        pq.push(State(0, 0));

        while (!pq.empty()) {

            State state = pq.top(); pq.pop();

            int curNode = state.node;

            int curWeight = state.weight;

            if (visited[curNode]) {

                continue;

            }

            weightSum += curWeight;

            visited[curNode] = true;

            for (const auto& neighbor : graph[curNode]) {

                int nextNode = neighbor.first;

                int nextWeight = neighbor.second;

                if (visited[nextNode]) {

                    continue;

                }

                pq.push(State(nextNode, nextWeight));

            }

        }

        for (int i = 0; i < visited.size(); i++) {

            if (!visited[i]) {

                return -1;

            }

        }

        return weightSum;

    }

    // 构造无向图邻接表

    vector<vector<pair<int, int>>> buildGraph(int n, vector<vector<int>>& points) {

        vector<vector<pair<int, int>>> graph(n);

        // 生成所有边及权重

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                int xi = points[i][0], yi = points[i][1];

                int xj = points[j][0], yj = points[j][1];

                int weight = abs(xi - xj) + abs(yi - yj);

                // 用 points 中的索引表示坐标点

                graph[i].push_back({j, weight});

                graph[j].push_back({i, weight});

            }

        }

        return graph;

    }

};
```

这道题做了一个小的变通：每个坐标点是一个二元组，那么按理说应该用五元组 `(x_i, y_i, x_j, y_j, weight)` 表示一条带权重的边，但这样的话不便执行 Prim 算法；所以我们用 `points` 数组中的索引代表每个坐标点，这样就可以直接复用之前的 `prim` 算法逻辑了。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表