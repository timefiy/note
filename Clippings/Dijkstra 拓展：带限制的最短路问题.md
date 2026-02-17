---
title: "Dijkstra 拓展：带限制的最短路问题"
source: "https://labuladong.online/zh/algo/data-structure/dijkstra-follow-up/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文讲解 Dijkstra 单源最短路径的实现原理和通用代码模板，解决力扣/LeetCode 的相关例题，同时给出 Java/Python/Go/JavaScript/C++ 代码实现。"
tags:
  - "clippings"
---
前置知识

阅读本文前，你需要先学习：

- [图结构基础及通用实现](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/)
- [Dijkstra 算法核心原理及实现](https://labuladong.online/zh/algo/data-structure/dijkstra/)

上一篇文章 [Dijkstra 算法原理及实现](https://labuladong.online/zh/algo/data-structure/dijkstra/) 中，我们从标准的 BFS 算法推导出了 Dijkstra 算法，解决了标准的加权图最短路径问题。

本文将探讨更复杂的场景： **带限制的最短路径问题** 。

这类问题比标准的最短路径问题复杂，不过不用担心，只需稍微修改之前给出的 Dijkstra 模板就可以解决这类问题。所以请确保你已经完全掌握了上一章的内容。

## 带限制的最短路径问题

上一章给出的 Dijkstra 算法使用的是 [BFS 算法的三种写法](https://labuladong.online/zh/algo/data-structure-basic/graph-traverse-basic/) 的第三种，每个节点自己维护了一个 `State` 对象，所以我们可以很容易地扩展标准的 Dijkstra 算法，完成更复杂的任务。

举个简单的例子， **现在不仅让你求最短路径，还要求最短路径最多不能超过 `k` 条边** 。

这个场景下依然可以使用 Dijkstra 算法，但是需要修改 `distTo` 数组，且需要给 `State` 类增加额外的字段。

下面直接给出代码实现，给 `dijkstra` 函数增加一个 `k` 参数，其他不同的地方用高亮标记了：

```
struct State {

    int node;

    // 从起点到当前节点的路径权重和

    int distFromStart;

    // 从起点到当前节点经过的边的条数

    int edgesFromStart; // [!code highlight]

    State(int node, int distFromStart, int edgesFromStart)

        : node(node), distFromStart(distFromStart), edgesFromStart(edgesFromStart) {}

};

vector<vector<int>> dijkstra(vector<vector<vector<int>>>& graph, int src, int k) {

    int n = graph.size();

    // distTo[i][j] 的值就是起点 src 到达节点 i 的最短路径权重和，且恰好经过 j 条边

    vector<vector<int>> distTo(n, vector<int>(k + 1, INT_MAX)); // [!code highlight]

    auto cmp =  {

        return a.distFromStart > b.distFromStart;

    };

    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);

    pq.emplace(src, 0, 0);

    distTo[src][0] = 0;

    while (!pq.empty()) {

        State state = pq.top(); pq.pop();

        int curNode = state.node;

        int curDistFromStart = state.distFromStart;

        int curEdgesFromStart = state.edgesFromStart;

        if (distTo[curNode][curEdgesFromStart] < curDistFromStart) {

            continue;

        }

        for (const auto& e : graph[curNode]) {

            int nextNode = e[0];

            int nextDistFromStart = curDistFromStart + e[1];

            int nextEdgesFromStart = curEdgesFromStart + 1;

            // 若已超过 k 条边，或无法优化路径权重和，直接跳过

            if (nextEdgesFromStart > k || distTo[nextNode][nextEdgesFromStart] <= nextDistFromStart) { // [!code highlight]

                continue;

            }

            pq.emplace(nextNode, nextDistFromStart, nextEdgesFromStart);

            distTo[nextNode][nextEdgesFromStart] = nextDistFromStart;

        }

    }

    return distTo;

}
```

其中的关键修改有三个：

1、我们给 `State` 类增加一个 `edgesFromStart` 字段，用于记录从起点到当前节点经过的边的条数。

2、把一维的 `distTo` 数组改成二维的 `distTo` 数组，其定义为： **`distTo[i][j]` 表示起点 `src` 到达节点 `i` ，且恰好经过 `j` 条边的最短路径权重和** 。

3、修改节点出队和入队时的条件，添加了对 `k` 条边的判断。

其他都可以沿用标准的 Dijkstra 算法代码，不用做任何修改。

### 点对点最短路径的优化

有些场景并不需要求出起点 `src` 到所有其他节点的最短路径，而是只需要求出起点 `src` 到终点 `dst` 的最短路径，所以可以做一些优化，让算法提前结束。

对于这个算法，贪心思想依然有效，更新 `distTo[v]` 时就是 `src` 到节点 `v` 的最短路径。

所以优化思路和标准 Dijkstra 算法类似，在更新 `distTo[dst]` 时做一个判断提前结束算法即可：

```
// 计算 src 到 dst 的最短路径权重和

// 且最多允许经过 k 条边

int dijkstra(Graph graph, int src, int dst, int k) {

    ...

    while (!pq.isEmpty()) {

        State state = pq.poll();

        int curNode = state.node;

        int curDistFromStart = state.distFromStart;

        int curEdgesFromStart = state.edgesFromStart;

        if (distTo[curNode][curEdgesFromStart] < curDistFromStart) {

            continue;

        }

        // 节点出队时进行判断，遇到终点时直接返回

        if (curNode == dst) {

            return distTo[dst][curEdgesFromStart];

        }

        ...

    }

    return -1;

}
```

带限制条件的 Dijkstra 算法的状态空间从标准 Dijkstra 的 $V$ 个扩展到 $V \times k$ 个（同一节点可以以不同边数多次入队），所以时间复杂度为 $O(Ek \log(Ek))$ ，空间复杂度为 $O(Vk)$ ，其中 $E$ 是边数， $V$ 是节点数， $k$ 是边数限制。

接下来，我们会在 [Dijkstra 算法习题章节](https://labuladong.online/zh/algo/problem-set/dijkstra/) 中运用上述代码模板解决一些有趣的问题。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表