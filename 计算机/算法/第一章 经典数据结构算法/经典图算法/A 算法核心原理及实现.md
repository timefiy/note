---
title: A* 算法核心原理及实现
source: https://labuladong.online/zh/algo/data-structure/a-star/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文讲解 A* 算法的实现原理和代码模板，它是 Dijkstra 算法的改进版，适用于能设计出启发函数的点对点最短路径问题（如二维网格寻路），通过启发函数提高搜索效率。
tags:
  - clippings
---
读完本文，你不仅学会了算法套路，还可以顺便解决如下题目：

| LeetCode | 力扣 | 难度 |
| --- | --- | --- |
| [1091\. Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/) | [1091\. 二进制矩阵中的最短路径](https://leetcode.cn/problems/shortest-path-in-binary-matrix/) |  |

前置知识

阅读本文前，你需要先学习：

- [图结构最短路径算法概览](https://labuladong.online/zh/algo/data-structure-basic/graph-shortest-path/)
- [Dijkstra 算法核心原理及实现](https://labuladong.online/zh/algo/data-structure/dijkstra/)

一句话总结

A\* 算法主要用于解决二维网格中的点对点最短路径问题，通过引入启发函数，让算法有方向性地向终点搜索，提高搜索效率。

[标准的 BFS 算法](https://labuladong.online/zh/algo/data-structure-basic/graph-traverse-basic/) 可以计算 **无权图** 的最短路径。

[Dijkstra 算法](https://labuladong.online/zh/algo/data-structure/dijkstra/) 借助优先级队列，可以高效计算不包含负权重的 **加权图** 的最短路径。

那你有没有思考过，对于无权图，如果我非要用 Dijkstra 算法，会发生什么？是否会有性能提升呢？

让我们探讨二维数组中的寻路问题，比如迷宫寻路，二维数组的左上角为起点，右下角为终点，计算最短路径。

这个场景中，可以把二维数组的每个位置看作一个节点，相邻位置之间有边相连，边的权重都是 1，也就是无权图。

一般的做法是用标准的 BFS 遍历算法，从起点开始，一层一层暴力搜索就行了，第一次到终点时就是最短路径。

如果我们用 Dijkstra 算法，不仅没有性能提升，反而比 BFS 算法更慢。

**原因很简单，边权重都是 1，那么早入队的节点权重小，晚入队的节点权重大，因此节点出队的顺序就是先进先出（和普通队列一样），效果等同于标准 BFS 算法** 。反而因为优先级队列产生额外的维护成本，导致时间复杂度比标准 BFS 更高（ $O(E \log E)$ vs $O(E)$ ）。

比如这个迷宫小游戏可以设置求解迷宫的算法，你可以分别设置 Dijkstra 算法和 BFS 算法求解迷宫，就能发现它们的搜索路径完全一致：

迷宫地图生成

那么，对于这个场景是否有优化呢？其实有一个思路：

既然终点在右下角，我们可以优先向右下角搜索，这样有更大概率更容易到达终点；反之，尽量不要往左上角走，因为那样大概率会南辕北辙绕远路。

**这就是 A\* 算法的核心思想：不仅仅考虑节点距起点的距离，也要考虑节点距终点的距离** 。

## A\* 算法的核心思想

具体地，对于任意节点 `x` ，我们定义三个量：

- `g(x)` 表示从起点 `src` 到节点 `x` **实际走过的路径长度** 。
- `h(x)` 是从节点 `x` 到终点 `dst` 的 **预估距离** （启发函数估算）。
- `f(x) = g(x) + h(x)` 作为优先级队列中节点的排序依据。

特别强调， `g(x)` 是 **实际走过的路径长度** ， `h(x)` 是距离终点的 **预估距离** ，这个一定不能理解错。

一张图看懂这里面的区别：

![](https://labuladong.online/images/algo/a-star/a-star.jpg)

红色实线是从起点走到节点 `x` 的实际路径长度 `g(x)` ，绿色实线是从节点 `x` 到终点的预估距离 `h(x)` 。

你知道为啥说 `h(x)` 是 **预估距离** ，为什么要叫 `h(x)` 为启发函数了把？

因为我们不可能准确计算 `x` 到终点的确切路径长度，只能根据数学公式计算一个估计值（图中用的欧几里得距离）。

如果不引入 `h(x)` 让 `f(x) = g(x)` 的话，那就是 Dijkstra 算法了对吧，在二维数组中的搜索效率还不如标准 BFS 算法，我们刚才分析过了。

但是引入这个 `h(x)` 后，让 `f(x) = g(x) + h(x)` 作为优先级队列的排序依据，搜索就一下具有了方向性：

- 无论是接近终点还是远离终点， `g(x)` 肯定是不断增大的。
- 但是接近终点时， `h(x)` 会逐渐减小；远离终点时， `h(x)` 会逐渐增大。

综上， **接近终点时 `f(x)` 的增速慢，节点排在优先级队列前面，更容易出队，算法也就会优先向终点的方向进行搜索；反之，远离终点时 `f(x)` 的增速快，搜索的优先级就会降低** 。

怎么样，A\* 算法的思路是不是非常巧妙？只需要简单地把 `f(x) = g(x)` 改为 `f(x) = g(x) + h(x)` 就能提高搜索效率。

具体的代码实现也很简单，只需要在 Dijkstra 算法的基础上稍作修改，即可得到 A\* 算法的代码。

## A\* 算法代码模板

对比 [Dijkstra 算法代码](https://labuladong.online/zh/algo/data-structure/dijkstra/) ，A\* 算法只需修改两处：

- `State` 类增加 `f` 字段，优先级队列按 `f` 排序。
- 入队时计算 `f = g + h` 。

直接看代码吧，不同之处用注释标注了：

```
struct State {

    int node;

    // g(x)，从起点到当前节点的实际距离

    int distFromStart;

    // f(x) = g(x) + h(x)，用于优先级队列排序

    int f;

    State(int node, int distFromStart, int f)

        : node(node), distFromStart(distFromStart), f(f) {}

};

// 启发函数，估算从 node 到 dst 的距离

// 具体实现取决于问题场景，后面会给出几种常用的启发函数

int heuristic(int node, int dst) {

    ...

}

// A* 算法，计算从 src 到 dst 的最短路径

// 大部分都和 Dijkstra 算法相同

int astar(vector<vector<int>>& graph, int src, int dst) {

    int n = graph.size();

    vector<int> distTo(n, INT_MAX);

    distTo[src] = 0;

    // 按 f(x) 从小到大排序

    auto cmp =  { return a.f > b.f; };

    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);

    // 起点入队，f = g + h = 0 + h(src)

    pq.push(State(src, 0, heuristic(src, dst)));

    while (!pq.empty()) {

        State state = pq.top();

        pq.pop();

        int curNode = state.node;

        int curDist = state.distFromStart;

        // 到达终点，直接返回

        if (curNode == dst) {

            return curDist;

        }

        if (distTo[curNode] < curDist) {

            continue;

        }

        for (auto& edge : getNeighbors(curNode)) {

            int nextNode = edge[0];

            int weight = edge[1];

            int nextDist = curDist + weight;

            if (nextDist < distTo[nextNode]) {

                distTo[nextNode] = nextDist;

                // 入队时计算 f = g + h

                int f = nextDist + heuristic(nextNode, dst);

                pq.push(State(nextNode, nextDist, f));

            }

        }

    }

    return -1;

}
```

如果 `h(x) = 0` ，A\* 算法就退化成了 Dijkstra 算法。所以这个算法最坏情况下的复杂度和 Dijkstra 算法相同，时间复杂度为 $O(ElogE)$ ，空间复杂度为 $O(E)$ 。

但是只要启发函数设计合理，能够大幅减少搜索的节点数，通常会比 Dijkstra 算法更高效。

## 启发函数的设计

启发函数 `h(x)` 是 A\* 算法的关键，它估算从节点 `x` 到终点的距离。

**启发函数必须满足可接受性（Admissibility）条件：对于所有节点 `x` ， `h(x)` 不能大于从 `x` 到终点的实际最短距离（高估）** 。

如果存在某个节点 `x` ， `h(x)` 被高估了， **就会影响正确性，找到错误的最短路径** 。

举个简单的例子，假设从起点 `src` 到终点 `dst` 的最短路径经过节点 `x` ，正确的最短路径权重和为 10。

此时如果 `h(x)` 恰好被高估了，比方说 `h(x)` 直接被估计为 20，那么 `f(x) = g(x) + h(x)` 是绝对大于 10 的，这就会导致真正的最短路径被跳过，得到错误的结果。

反过来，如果 `h(x)` 始终都小于从 `x` 到终点的实际最短距离，那么 `f(x) = g(x) + h(x)` 始终都小于真正的最短路径权重和，这就确保最短路径不会被跳过，最终能找到正确答案。

对于二维网格图，假设当前位置是 `(x1, y1)` ，终点是 `(x2, y2)` ，常用的启发函数有以下几种：

曼哈顿距离，适用于只能上下左右 4 个方向移动，每格的代价为 1 的场景：

```
int h = abs(x1 - x2) + abs(y1 - y2);
```

切比雪夫距离，适用于上、下、左、右、左上、右上、左下、右下 8 个方向移动，且每格移动的代价为 1 的场景：

```
int h = max(abs(x1 - x2), abs(y1 - y2));
```

欧几里得距离，适用于向任何角度、任何方向移动的场景：

```
double h = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
```

**在不高估的前提下，启发函数越接近真实距离，算法效率越高** 。

## 例题实践

看力扣第 1091 题： [二进制矩阵中的最短路径](https://leetcode.cn/problems/shortest-path-in-binary-matrix/) 。

**1091\. 二进制矩阵中的最短路径** | [力扣](https://leetcode.cn/problems/shortest-path-in-binary-matrix/) | [LeetCode](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

给你一个 `n x n` 的二进制矩阵 `grid` 中，返回矩阵中最短 **畅通路径** 的长度。如果不存在这样的路径，返回 `-1` 。

二进制矩阵中的 畅通路径 是一条从 **左上角** 单元格（即， `(0, 0)` ）到 右下角 单元格（即， `(n - 1, n - 1)` ）的路径，该路径同时满足下述要求：

- 路径途经的所有单元格的值都是 `0` 。
- 路径中所有相邻的单元格应当在 **8 个方向之一** 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。

**畅通路径的长度** 是该路径途经的单元格总数。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/02/18/example1_1.png)
```
输入：grid = [[0,1],[1,0]]
输出：2
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/02/18/example2_1.png)
```
输入：grid = [[0,0,0],[1,1,0],[1,1,0]]
输出：4
```

**示例 3：**

```
输入：grid = [[1,0,0],[1,1,0],[1,1,0]]
输出：-1
```

**提示：**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 100`
- `grid[i][j]` 为 `0` 或 `1`

题目来源： [力扣 1091. 二进制矩阵中的最短路径](https://leetcode.cn/problems/shortest-path-in-binary-matrix/) 。

这道题要求在二维网格中找从左上角到右下角的最短路径，可以向 8 个方向移动。

这是一个典型的点对点最短路径问题，起点 `(0, 0)` ，终点 `(n-1, n-1)` ，每条边的权重都是 1（移动一步），可以向 8 个方向移动。

由于可以斜向移动且代价为 1，我们用切比雪夫距离作为启发函数，完整代码如下：

```
class Solution {

public:

    // 8 个方向

    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // 起点或终点被堵住

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {

            return -1;

        }

        if (n == 1) {

            return 1;

        }

        // distTo[i][j] 记录从起点到 (i, j) 的最短距离

        vector<vector<int>> distTo(n, vector<int>(n, INT_MAX));

        distTo[0][0] = 1;

        // 优先级队列，按 f = g + h 排序

        // 数组含义：{x, y, g, f}

        auto cmp =  { return a[3] > b[3]; };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        pq.push({0, 0, 1, 1 + heuristic(0, 0, n)});

        while (!pq.empty()) {

            auto state = pq.top();

            pq.pop();

            int x = state[0], y = state[1], g = state[2];

            // 到达终点

            if (x == n - 1 && y == n - 1) {

                return g;

            }

            // 剪枝

            if (distTo[x][y] < g) {

                continue;

            }

            // 遍历 8 个方向

            for (auto& dir : dirs) {

                int nx = x + dir[0], ny = y + dir[1];

                // 边界检查和障碍物检查

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 1) {

                    continue;

                }

                int nextG = g + 1;

                if (nextG < distTo[nx][ny]) {

                    distTo[nx][ny] = nextG;

                    int f = nextG + heuristic(nx, ny, n);

                    pq.push({nx, ny, nextG, f});

                }

            }

        }

        return -1;

    }

    // 启发函数：切比雪夫距离

    int heuristic(int x, int y, int n) {

        return max(abs(x - (n - 1)), abs(y - (n - 1)));

    }

};
```

在 $M \times N$ 的网格中，以上述算法的最坏时间复杂度为 $O(MN \log MN)$ ，空间复杂度为 $O(MN)$ 。

## 总结

A\* 算法在 Dijkstra 的基础上引入了启发函数 `h(x)` ，通过 `f(x) = g(x) + h(x)` 让算法优先向终点方向搜索，减少不必要的探索。代码改动很小，只需在 Dijkstra 基础上增加启发函数计算即可。

什么时候用 Dijkstra 算法，什么时候用 A\* 算法？

首先，无论是 Dijkstra 算法还是 A\* 算法，都不能处理负权重边，因为贪心思想依赖边权重非负。

想用 A\* 算法，必须满足：点对点最短路径问题，且能够设计出启发函数估算任意节点到终点的距离。

只要启发函数设计合理（不高估），就能找到最短路径，通常比 Dijkstra 算法更高效。

如果无法设计启发函数估算到终点的距离，或者终点位置未知，或者要计算从起点到所有其他节点的最短路径，只能用 Dijkstra 算法。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表