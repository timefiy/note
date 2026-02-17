---
title: 多源最短路径：Floyd 算法
source: https://labuladong.online/zh/algo/data-structure/floyd/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文讲解多源最短路径算法 Floyd 的核心原理，解决 力扣/LeetCode 上的相关题目，同时给出 Java/Python/Go/JavaScript/C++ 代码实现。
tags:
  - clippings
---
读完本文，你不仅学会了算法套路，还可以顺便解决如下题目：

| LeetCode | 力扣 | 难度 |
| --- | --- | --- |
| [1334\. Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) | [1334\. 阈值距离内邻居最少的城市](https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) |  |

前置知识

阅读本文前，你需要先学习：

- [图结构最短路径算法概览](https://labuladong.online/zh/algo/data-structure-basic/graph-shortest-path/)
- [动态规划算法核心套路](https://labuladong.online/zh/algo/essential-technique/dynamic-programming-framework/)

在 [图结构最短路径算法概览](https://labuladong.online/zh/algo/data-structure-basic/graph-shortest-path/) 中，我们详细介绍了图论中单源最短路径、多源最短路径、点对点最短路径几种场景，以及几种经典最短路径算法的区别与联系。

在 [最便宜的旅行路径](https://labuladong.online/zh/algo/dynamic-programming/cheap-travel/) 中，我们用动态规划求解过从 `src` 到 `dst` 的最短路径（点对点最短路径问题），而本文要解决的是多源最短路径问题，不能直接套用。

Floyd 算法基于动态规划思想，代码实现非常简单，但想要彻底理解其原理，需要费点功夫。下面先直接给出 Floyd 算法的代码以及例题，然后再详细讲解状态转移方程的推导过程。

## Floyd 算法代码

Floyd 算法的代码如下，其中 `Graph` 是 [图结构代码实现](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) 中的通用接口：

```
int[][] floyd(Graph graph) {

    int n = graph.nodeCount();

    // 定义：dp[i][j] 的值为节点 i 到节点 j 的最短路径权重

    int[][] dp = new int[n][n];

    // base case

    // 节点到其自身的路径权重为 0，所以 dp[i][i] 初始化为 0

    // 对于直接相邻的节点，dp[i][j] 初始化为边的权重

    // 对于不直接相邻的节点，dp[i][j] 初始化为 +inf

    for (int i = 0; i < n; i++) {

        Arrays.fill(dp[i], Integer.MAX_VALUE);

    }

    for (int i = 0; i < n; i++) {

        dp[i][i] = 0;

    }

    for (int i = 0; i < n; i++) {

        for (Edge edge : graph.neighbors(i)) {

            int j = edge.to;

            int weight = edge.weight;

            dp[i][j] = weight;

        }

    }

    // 状态转移

    for (int k = 0; k < n; k++) {

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                // 为了防止 dp[i][k] + dp[k][j] 导致 int 溢出，需要额外判断

                if (dp[i][k] != Integer.MAX_VALUE && dp[k][j] != Integer.MAX_VALUE) {

                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);

                }

            }

        }

    }

    return dp;

}

// 计算多源最短路径

// 其中 dist[i][j] 为节点 i 到节点 j 的最短路径权重

int[][] dist = floyd(graph);
```

可以看出上述代码就是一个标准的动态规划问题的解法代码，其中：

`dp` 数组的定义是 `dp[i][j]` 存储节点 `i` 到节点 `j` 的最短路径权重。

对于直接相邻的节点 `i, j` ， `dp[i][j]` 的值初始化为边的权重，不直接相邻的节点，初始化为 `+inf` ，这就是 base case。

状态转移方程就是三层嵌套 for 循环的部分，也是 Floyd 算法的核心：

```
// 状态转移

for (int k = 0; k < n; k++) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);

        }

    }

}
```

这样，Floyd 算法就完成了，时间复杂度是 $O(n^3)$ ，空间复杂度是 $O(n^2)$ ，其中 $n$ 是图的节点数。

## 理解代码的技巧

讲一个技巧来理解这个二维 `dp` 数组的状态转移过程，方便记忆。

**请注意，这里讲的是技巧，实际上并不严谨** 。Floyd 算法的严谨推理需要从三维 `dp` 开始，最后优化为二维 `dp` ，这部分放在最后讲解。

以这幅图为例：

节点 `1` 和节点 `2` 之间没有直接相连的边，所以它们的最短路径肯定是要经过 `3, 4, 5` 中的某个节点的。

假设经过的这个节点是 `k` ，那么就有 $minDist(1, 2) = minDist(1, k) + minDist(k, 2)$ 成立，原问题就分解成了两个结构相同、规模更小的子问题。

但这个经过的节点 `k` 到底是哪个呢？我们也不知道，所以需要穷举所有其他节点，看看哪个节点作为 `k` 时， `minDist(1, 2)` 的值最小：

```
minDist(1, 2) = min(

    minDist(1, 3) + minDist(3, 2),

    minDist(1, 4) + minDist(4, 2),

    minDist(1, 5) + minDist(5, 2)

)
```

一般地，想计算节点 `i` 到节点 `j` 的最短路径，也需要穷举所有其他节点 `k` ，即这部分代码：

```
for (int k = 0; k < n; k++) {

    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);

}
```

由于我们在计算多源最短路径，所以需要遍历所有不同的 `i, j` 组合，最终就得到了 Floyd 算法代码中的三层 for 循环：

```
// 状态转移

for (int k = 0; k < n; k++) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);

        }

    }

}
```

这样就能直观地理解 Floyd 算法了，是不是很容易记忆？

但为啥说这个理解方式不严谨呢？因为状态转移的一个关键是：当前计算的状态所依赖的状态必须是已经计算完成的。

在上述代码中，我们定义 `dp[i][j]` 为节点 `i` 到节点 `j` 的最短路径权重， `dp[i][j]` 的值依赖 `dp[i][k]` 和 `dp[k][j]` 的值。

问题在于，你如何证明计算 `dp[i][j]` 时 `dp[i][k]` 和 `dp[k][j]` 的值已经计算完成了呢？

如果仔细想想，就会发现很难梳理状态之间的依赖关系，无法完成这个证明。

不过这种理解方式确实符合直觉， **你只需要记住最外层 for 循环穷举 `k` ，里面两层穷举 `i, j` ， `dp[i][j]` 的值是 `dp[i][k] + dp[k][j]` 的最小值，就能写出 Floyd 算法了** 。

下面来用一道例题实践一下 Floyd 算法，最后再探讨 Floyd 算法的严谨推理过程。

## 例题实践

来看力扣第 1334 题「阈值距离内邻居最少的城市」：

**1334\. 阈值距离内邻居最少的城市** | [力扣](https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) | [LeetCode](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)

有 `n`  个城市，按从 `0` 到 `n-1`  编号。给你一个边数组  `edges` ，其中 `edges[i] = [from<sub>i</sub>, to<sub>i</sub>, weight<sub>i</sub>]` 代表 `from<sub>i</sub>`  和  `to<sub>i</sub>` 两个城市之间的双向加权边，距离阈值是一个整数 `distanceThreshold` 。

返回在路径距离限制为 `distanceThreshold` 以内可到达城市最少的城市。如果有多个这样的城市，则返回编号最大的城市。

注意，连接城市 ***i*** 和 ***j*** 的路径的距离等于沿该路径的所有边的权重之和。

**示例 1：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/01/26/find_the_city_01.png)

```
输入：n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
输出：3
解释：城市分布图如上。
每个城市阈值距离 distanceThreshold = 4 内的邻居城市分别是：
城市 0 -> [城市 1, 城市 2] 
城市 1 -> [城市 0, 城市 2, 城市 3] 
城市 2 -> [城市 0, 城市 1, 城市 3] 
城市 3 -> [城市 1, 城市 2] 
城市 0 和 3 在阈值距离 4 以内都有 2 个邻居城市，但是我们必须返回城市 3，因为它的编号最大。
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/01/26/find_the_city_02.png)**

```
输入：n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
输出：0
解释：城市分布图如上。 
每个城市阈值距离 distanceThreshold = 2 内的邻居城市分别是：
城市 0 -> [城市 1] 
城市 1 -> [城市 0, 城市 4] 
城市 2 -> [城市 3, 城市 4] 
城市 3 -> [城市 2, 城市 4]
城市 4 -> [城市 1, 城市 2, 城市 3] 
城市 0 在阈值距离 2 以内只有 1 个邻居城市。
```

**提示：**

- `2 <= n <= 100`
- `1 <= edges.length <= n * (n - 1) / 2`
- `edges[i].length == 3`
- `0 <= from<sub>i</sub> < to<sub>i</sub> < n`
- `1 <= weight<sub>i</sub>, distanceThreshold <= 10^4`
- 所有 `(from<sub>i</sub>, to<sub>i</sub>)` 都是不同的。

题目来源： [力扣 1334. 阈值距离内邻居最少的城市](https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) 。

我们把城市看做图结构中的节点，那么我们只需要计算出每个节点 $i$ 到所有其他节点的最短路径权重，然后统计最短路径权重小于 `distanceThreshold` 的节点个数 $i_{count}$ 即可。题目的答案就是 $i_{count}$ 最小的节点。

需要计算所有节点之间的最短路径，所以这是一道典型的多源最短路径问题，用 Floyd 算法可以解决，直接看解法代码：

```
class Solution {

public:

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // floyd 算法

        // 定义：dp[i][j] 表示节点 i 到节点 j 的最短路径权重

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        

        // 直接相邻的节点，dp[i][j] 初始化为边的权重

        for (auto& edge : edges) {

            int u = edge[0], v = edge[1], w = edge[2];

            dp[u][v] = w;

            dp[v][u] = w;

        }

        

        // 状态转移

        for (int k = 0; k < n; k++) {

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {

                    if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {

                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

                    }

                }

            }

        }

        int result = 0;

        int minCount = INT_MAX;

        for (int i = 0; i < n; i++) {

            // 统计节点 i 符合条件的邻居数

            int count = 0;

            for (int j = 0; j < n; j++) {

                if (i != j && dp[i][j] <= distanceThreshold) {

                    count++;

                }

            }

            // 如果有多个城市邻居数相同，返回编号较大的城市

            if (count <= minCount) {

                result = i;

                minCount = count;

            }

        }

        return result;

    }

};
```

## Floyd 算法原理

### 三维 dp 数组

之前已经分析过，二维 `dp` 数组虽然容易理解，但无法准确描述状态之间的依赖关系，不能严格地证明状态转移方程的正确性。

所以我们需要重新定义 `dp` 数组，并增加一个维度，来严格地描述状态转移过程：

```
int n = graph.nodeCount();

// 定义：仅经过前 k 个节点中的若干个节点（可以选择性经过，不必都经过），

// 节点 i 到节点 j 的最短路径权重为 dp[k][i][j]

int[][][] dp = new int[n + 1][n][n];

// base case

for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {

        dp[i][j] = Integer.MAX_VALUE;

    }

}

for (int i = 0; i < n; i++) {

    dp[0][i][i] = 0;

}

for (int i = 0; i < n; i++) {

    for (Edge edge : graph.neighbors(i)) {

        int j = edge.to;

        int weight = edge.weight;

        dp[0][i][j] = weight;

    }

}

// 状态转移

for (int k = 1; k <= n; k++) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            dp[k][i][j] = Math.min(dp[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j]);

        }

    }

}

// 根据定义，任意节点 i 到节点 j 的最短路径权重为 dp[n][i][j]
```

这个定义方式和 [0-1 背包问题](https://labuladong.online/zh/algo/dynamic-programming/knapsack1/) 的定义方式有些类似：

背包问题中，我们定义 `dp[i][j]` 为仅使用前 `i` 个物品中的若干个（可以选择性使用，不必全部用完），背包容量为 `j` 时的最大价值。

在这里，我们定义 `dp[k][i][j]` 为仅经过前 `k` 个节点中的若干个（可以选择性经过，不必全部经过），节点 `i` 到节点 `j` 的最短路径权重。

按照这种定义方式，任意两个节点 `i` 和 `j` 之间的最短路径权重就是 `dp[n][i][j]` ，即允许经过任意节点从 `i` 到 `j` 的最短路径。

base case 就是 `dp[0][i][j]` 的值，即不经过任何节点，节点 `i` 到节点 `j` 的最短路径权重：

- 如果 `i == j` ，则 `dp[0][i][j] = 0` ，因为节点到自身的最短路径权重为 0，不需要经过任何其他节点。
- 如果 `i` 和 `j` 之间有边，则 `dp[0][i][j]` 的值就是边的权重，不需要经过任何其他节点。
- 如果 `i` 和 `j` 之间没有边，则 `dp[0][i][j]` 的值为 `+inf` ，表示不可达。因为节点 `i` 和节点 `j` 不直接相邻，如果不允许经过其他节点，则节点 `i` 和节点 `j` 不可达。

接下来就是最重要的部分，状态转移方程：

```
dp[k][i][j] = Math.min(dp[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j]);
```

`dp[k][i][j]` 的含义是：仅经过前 `k` 个节点中的若干个，节点 `i` 到节点 `j` 的最短路径权重。我们聚焦这第 `k` 个节点，只有两种可能：

- 节点 `i` 到节点 `j` 的最短路径不经过第 `k` 个节点。
- 节点 `i` 到节点 `j` 的最短路径经过第 `k` 个节点。

如果节点 `i` 到节点 `j` 的最短路径不经过第 `k` 个节点，那就是说最短路径仅经过前 `k-1` 个节点中的若干个，即 `dp[k][i][j] = dp[k-1][i][j]` 。

如果节点 `i` 到节点 `j` 的最短路径经过第 `k` 个节点，那么从 `i` 到 `j` 的最短路径就是从 `i` 到 `k` 的最短路径加上从 `k` 到 `j` 的最短路径，即 `dp[k][i][j] = dp[k-1][i][k] + dp[k-1][k][j]` 。

综上，这个状态转移方程的逻辑是正确的，我们来看状态转移方程的更新过程：

```
for (int k = 1; k <= n; k++) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            dp[k][i][j] = Math.min(dp[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j]);

        }

    }

}
```

`dp[k][..][..]` 的值依赖 `dp[k-1][..][..]` 的值，而枚举 `k` 的 for 循环在最外层，这就意味着计算 `dp[k][..][..]` 时， `dp[k-1][..][..]` 的值已经计算完成了。

或者我们可以直观地理解，这个三维 `dp` 数组就是边长为 `n` 的立方体（类似一个魔方），其中长的索引为 `i` ，宽的索引为 `j` ，高的索引为 `k` 。

base case 是 `dp[0][..][..]` 的值，即立方体最下面一层的值；三层嵌套 for 循环相当于从立方体底部开始，逐层向上计算；立方体顶层是 `dp[n][..][..]` 的值，即我们想要的任意两个节点 `i, j` 之间的最短路径。

综上，这个三层 for 循环更新 `dp` 数组的顺序是正确的，计算 `dp[k][..][..]` 时， `dp[k-1][..][..]` 的值已经计算完成了。

现在我们已经可以证明这个三维 `dp` 的解法是正确的，接下来，我们需要把三维 `dp` 数组优化为二维。

### 空间压缩

我们可以用 [动态规划空间压缩技巧](https://labuladong.online/zh/algo/dynamic-programming/space-optimization/) 来优化三维 `dp` 数组。

首先观察到，计算 `dp[k][..][..]` 时仅依赖 `dp[k-1][..][..]` 的值，至于 `dp[k-2][..][..], dp[k-3][..][..]` 的值都不会再使用了。

所以最直接的优化思路是滚动数组技巧，即使用两个二维数组分别存储 `dp[k][..][..]` 和 `dp[k-1][..][..]` 的值，交替更新，这样就可以将 $O(n^3)$ 的空间复杂度优化为 $O(n^2)$ 。

大致的代码如下：

```
// 存储正在计算的 dp[k][..][..]

int[][] dp_k = new int[n][n];

// 存储已经计算完成的 dp[k-1][..][..]

int[][] dp_k_1 = new int[n][n];

for (int i = 0; i < n; i++) {

    Arrays.fill(dp_k_1[i], Integer.MAX_VALUE);

    Arrays.fill(dp_k[i], Integer.MAX_VALUE);

}

// base case 初始化到 dp_k_1

for (int i = 0; i < n; i++) {

    dp_k_1[i][i] = 0;

}

for (int i = 0; i < n; i++) {

    for (Edge edge : graph.neighbors(i)) {

        int j = edge.to;

        int weight = edge.weight;

        dp_k_1[i][j] = weight;

    }

}

// 状态转移

for (int k = 1; k <= n; k++) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            dp_k[i][j] = Math.min(dp_k_1[i][j], dp_k_1[i][k] + dp_k_1[k][j]);

        }

    }

    // 这一轮循环的 dp[k][..][..] 作为下一轮的 dp[k-1][..][..]

    dp_k_1 = dp_k;

}
```

这段代码应该很容易理解吧，仅仅用一个 `dp_k_1` 来缓存 `dp[k-1][..][..]` 的值就够了， `dp[k-2][..][..], dp[k-3][..][..]` 的值都不需要保留。

**其实这个优化已经把算法的空间复杂度优化到 $O(n^2)$ ，从理论分析的角度来看，和本文开头给出的 Floyd 算法效率相同了** 。

下一步的优化就是把这个 `dp_k_1` 数组也去掉，直接在 `dp_k` 这一个数组上进行状态转移，这样就得到了最终的 Floyd 算法代码：

```
for (int k = 1; k <= n; k++) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);

        }

    }

}
```

这里的关键问题是：

当我们在 `k` 循环中计算 `dp[i][j]` 时，等号右边的 `dp[i][j], dp[i][k], dp[k][j]` 这些值是否还保留着上一轮循环计算出的值？

如果还保留着，那么就可以原地更新，不需要额外的数组记录上一轮循环的值了，否则就会导致状态更新出错。

答案是，只要 `k` 是最外层循环，就可以原地更新。 **接下来的推导过程有点烧脑，若是在难以理解可以跳过** 。

先看 `dp[i][j]` ，它肯定保留着上一轮循环计算出的值。

关键要证明 `dp[i][k]` 和 `dp[k][j]` 的值在内层 `i, j` 的循环中不会被修改，始终保留着上一轮循环计算出的值。

换句话说，就是 `dp[..][k]` 这一列和 `dp[k][..]` 这一行，在 `i, j` 的循环中不会被修改。

先来看 `dp[..][k]` 这一列，即 `j = k` 的情况，状态转移方程就变成了这样：

```
dp[i][k] = Math.min(dp[i][k], dp[i][k] + dp[k][k]);
```

其中 `dp[k][k] = 0` 为 base case，方程可以化简：

```
dp[i][k] = Math.min(dp[i][k], dp[i][k]) = dp[i][k]
```

所以 `dp[..][k]` 这一列的值不会被修改。

接下来看 `dp[k][..]` 这一行，即 `i = k` 的情况，状态转移方程就变成了这样：

```
dp[k][j] = Math.min(dp[k][j], dp[k][k] + dp[k][j]);
```

其中 `dp[k][k] = 0` 为 base case，方程可以化简：

```
dp[k][j] = Math.min(dp[k][j], dp[k][j]) = dp[k][j]
```

所以 `dp[k][..]` 这一列的值不会被修改。

综上，我们可以证明 `dp[i][k]` 和 `dp[k][j]` 的值在内层 `i, j` 的循环中不会被修改，始终保留着上一轮循环计算出的值。

所以仅使用一个二维 `dp` 数组，原地更新 `dp[i][j]` 的值，就可以得到正确的结果。

至此，我们已经证明了空间优化的正确性，从三维的 `dp` 解法优化到二维的 `dp` 解法，得到了最终的 Floyd 算法代码。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表