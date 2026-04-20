---
title: Dijkstra 算法经典习题
source: https://labuladong.online/zh/algo/problem-set/dijkstra/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上所有 Dijkstra 算法的经典习题，包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
前置知识

阅读本文前，你需要先学习：

- [Dijkstra 算法核心原理及实现](https://labuladong.online/zh/algo/data-structure/dijkstra/)
- [Dijkstra 算法拓展](https://labuladong.online/zh/algo/data-structure/dijkstra-follow-up/)

前面的文章介绍了 Dijkstra 算法的代码实现，下面我们实践一下。

先解决几个标准的最短路径问题，然后再解决几个带限制条件的最短路径问题。

## 标准最短路径问题

### 743\. 网络延迟时间

第一题是力扣第 743 题「 [网络延迟时间](https://leetcode.cn/problems/network-delay-time/) 」，题目如下：

**743\. 网络延迟时间** | [力扣](https://leetcode.cn/problems/network-delay-time/) | [LeetCode](https://leetcode.com/problems/network-delay-time/)

有 `n` 个网络节点，标记为  `1`  到 `n` 。

给你一个列表 `times` ，表示信号经过 **有向** 边的传递时间。 `times[i] = (u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>)` ，其中 `u<sub>i</sub>`  是源节点， `v<sub>i</sub>`  是目标节点， `w<sub>i</sub>` 是一个信号从源节点传递到目标节点的时间。

现在，从某个节点 `K` 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 `-1` 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2019/05/23/931_example_1.png)

```
输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
输出：2
```

**示例 2：**

```
输入：times = [[1,2,1]], n = 2, k = 1
输出：1
```

**示例 3：**

```
输入：times = [[1,2,1]], n = 2, k = 2
输出：-1
```

**提示：**

- `1 <= k <= n <= 100`
- `1 <= times.length <= 6000`
- `times[i].length == 3`
- `1 <= u<sub>i</sub>, v<sub>i</sub> <= n`
- `u<sub>i</sub> != v<sub>i</sub>`
- `0 <= w<sub>i</sub> <= 100`
- 所有 `(u<sub>i</sub>, v<sub>i</sub>)` 对都 **互不相同** （即，不含重复边）

题目来源： [力扣 743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) 。

函数签名如下：

让你求所有节点都收到信号的时间，你把所谓的传递时间看做距离，实际上就是问你「从节点 `k` 到其他所有节点的最短路径中，最长的那条最短路径距离是多少」，说白了就是让你算从节点 `k` 出发到其他所有节点的最短路径，就是标准的 Dijkstra 算法。

在用 Dijkstra 之前，别忘了要满足一些条件，加权有向图，没有负权重边，OK，可以用 Dijkstra 算法计算最短路径，直接套用算法框架：

你对比之前说的代码框架，只要稍稍修改，就可以把这道题目解决了。

### 1631\. 最小体力消耗路径

感觉上一道题完全没有难度，下面我们再看一道题目，力扣第 1631 题「 [最小体力消耗路径](https://leetcode.cn/problems/path-with-minimum-effort/) 」：

**1631\. 最小体力消耗路径** | [力扣](https://leetcode.cn/problems/path-with-minimum-effort/) | [LeetCode](https://leetcode.com/problems/path-with-minimum-effort/)

你准备参加一场远足活动。给你一个二维 `rows x columns`  的地图  `heights`  ，其中  `heights[row][col]` 表示格子 `(row, col)` 的高度。一开始你在最左上角的格子 `(0, 0)` ，且你希望去最右下角的格子 `(rows-1, columns-1)` （注意下标从 **0** 开始编号）。你每次可以往 **上** ， **下** ， **左** ， **右** 四个方向之一移动，你想要找到耗费 **体力** 最小的一条路径。

一条路径耗费的 **体力值** 是路径上相邻格子之间 **高度差绝对值** 的 **最大值** 决定的。

请你返回从左上角走到右下角的最小 **体力消耗值** 。

**示例 1：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/10/25/ex1.png)

```
输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
输出：2
解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
```

**示例 2：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/10/25/ex2.png)

```
输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
输出：1
解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
```

**示例 3：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/10/25/ex3.png)
```
输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
输出：0
解释：上图所示路径不需要消耗任何体力。
```

**提示：**

- `rows == heights.length`
- `columns == heights[i].length`
- `1 <= rows, columns <= 100`
- `1 <= heights[i][j] <= 10<sup>6</sup>`

题目来源： [力扣 1631. 最小体力消耗路径](https://leetcode.cn/problems/path-with-minimum-effort/) 。

函数签名如下：

我们常见的二维矩阵题目，如果让你从左上角走到右下角，一般都会限制你只能向右或向下走，这种情况比较简单，因为不可能多次进入同一个格子。

但这道题可没有限制哦，你可以上下左右随便走，只要路径的「体力消耗」最小就行，所以这是一个标准的图论问题。

如果你把二维数组中每个 `(x, y)` 坐标看做一个节点，它的上下左右坐标就是相邻节点，它对应的值和相邻坐标对应的值之差的绝对值就是题目说的「体力消耗」，你就可以理解为边的权重。

这样一想，是不是就在让你以左上角坐标为起点，以右下角坐标为终点，计算起点到终点的最短路径？Dijkstra 算法是不是可以做到？

**只不过，这道题中评判一条路径是长还是短的标准不再是路径经过的权重总和，而是路径经过的权重最大值** 。

明白这一点，再想一下使用 Dijkstra 算法的前提，加权有向图，没有负权重边，求最短路径，OK，可以使用，咱们来套框架。

首先，二维矩阵抽象成图，我们可以单独实现一下 `adj` 方法，之后的主要逻辑会更清晰；另外，我们现在认为一个二维坐标 `(x, y)` 是图中的一个节点，所以 `State` 类也需要修改，记录二维坐标。

直接看代码吧，注释比较详细：

你看，稍微改一改代码模板，这道题就解决了。

### 1514\. 概率最大的路径

再来看力扣第 1514 题「 [概率最大的路径](https://leetcode.cn/problems/path-with-maximum-probability/) 」，题目如下：

**1514\. 概率最大的路径** | [力扣](https://leetcode.cn/problems/path-with-maximum-probability/) | [LeetCode](https://leetcode.com/problems/path-with-maximum-probability/)

给你一个由 `n` 个节点（下标从 0 开始）组成的无向加权图，该图由一个描述边的列表组成，其中 `edges[i] = [a, b]` 表示连接节点 a 和 b 的一条无向边，且该边遍历成功的概率为 `succProb[i]` 。

指定两个节点分别作为起点 `start` 和终点 `end` ，请你找出从起点到终点成功概率最大的路径，并返回其成功概率。

如果不存在从 `start` 到 `end` 的路径，请 **返回 0** 。只要答案与标准答案的误差不超过 **1e-5** ，就会被视作正确答案。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/07/12/1558_ex1.png)**

```
输入：n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
输出：0.25000
解释：从起点到终点有两条路径，其中一条的成功概率为 0.2 ，而另一条为 0.5 * 0.5 = 0.25
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/07/12/1558_ex2.png)**

```
输入：n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
输出：0.30000
```

**示例 3：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/07/12/1558_ex3.png)**

```
输入：n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
输出：0.00000
解释：节点 0 和 节点 2 之间不存在路径
```

**提示：**

- `2 <= n <= 10^4`
- `0 <= start, end < n`
- `start != end`
- `0 <= a, b < n`
- `a != b`
- `0 <= succProb.length == edges.length <= 2*10^4`
- `0 <= succProb[i] <= 1`
- 每两个节点之间最多有一条边

题目来源： [力扣 1514. 概率最大的路径](https://leetcode.cn/problems/path-with-maximum-probability/) 。

函数签名如下：

我说这题一看就是 Dijkstra 算法，但聪明的你肯定会反驳我：

**1、这题给的是无向图，也可以用 Dijkstra 算法吗** ？

**2、更重要的是，Dijkstra 算法计算的是最短路径，计算的是最小值，这题让你计算最大概率是一个最大值，怎么可能用 Dijkstra 算法呢** ？

问得好！

首先关于有向图和无向图，前文 [图算法基础](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) 说过，无向图本质上可以认为是「双向图」，从而转化成有向图。

重点说说最大值和最小值这个问题。 [Dijkstra 算法实现](https://labuladong.online/zh/algo/data-structure/dijkstra/) 中说过，Dijkstra 计算最短路径的正确性依赖一个前提：路径中每增加一条边，路径的总权重就会增加。

其实你把这个结论反过来也是 OK 的：

如果路径中每增加一条边，路径的总权重就会减少，那么可以用 Dijkstra 算法计算最长路径。

说白了，Dijkstra 算法计算的是「最优值」：

- 如果每新增一条边，路径的总权重就会减少，那么最优值问题就是计算最长路径；
- 如果每新增一条边，路径的总权重就会增加，那么最优值问题就是计算最短路径。

只要确保每条路径产生的效果相同（增加或减少路径权重），贪心思想就成立。如果说这条路径导致路径权重增加，那条路径导致路径权重减少，贪心思想就会失效，也就不能使用 Dijkstra 算法。

你看这道题，边和边之间是乘法关系，每条边的概率都是小于 1 的，所以每增加一条边，路径的总概率就会减少，题目让我们计算最大概率，所以可以用 Dijkstra 算法。

我们只需要把代码中的优先级队列的排序顺序和一些 if 判断条件反过来即可，直接看解法代码吧：

### 1368\. 使网格图至少有一条有效路径的最小代价

力扣第 1368 题「 [使网格图至少有一条有效路径的最小代价](https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/) 」：

**1368\. 使网格图至少有一条有效路径的最小代价** | [力扣](https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/) | [LeetCode](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/)

给你一个 m x n 的网格图 `grid`  。  `grid`  中每个格子都有一个数字，对应着从该格子出发下一步走的方向。  `grid[i][j]` 中的数字可能为以下几种情况：

- **1**  ，下一步往右走，也就是你会从 `grid[i][j]` 走到 `grid[i][j + 1]`
- **2**  ，下一步往左走，也就是你会从 `grid[i][j]` 走到 `grid[i][j - 1]`
- **3**  ，下一步往下走，也就是你会从 `grid[i][j]` 走到 `grid[i + 1][j]`
- **4**  ，下一步往上走，也就是你会从 `grid[i][j]` 走到 `grid[i - 1][j]`

注意网格图中可能会有 **无效数字** ，因为它们可能指向 `grid` 以外的区域。

一开始，你会从最左上角的格子 `(0,0)` 出发。我们定义一条 **有效路径** 为从格子 `(0,0)` 出发，每一步都顺着数字对应方向走，最终在最右下角的格子 `(m - 1, n - 1)` 结束的路径。有效路径 **不需要是最短路径** 。

你可以花费 `cost = 1` 的代价修改一个格子中的数字，但每个格子中的数字 **只能修改一次** 。

请你返回让网格图至少有一条有效路径的最小代价。

**示例 1：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/02/29/grid1.png)

```
输入：grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
输出：3
解释：你将从点 (0, 0) 出发。
到达 (3, 3) 的路径为： (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) 花费代价 cost = 1 使方向向下 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) 花费代价 cost = 1 使方向向下 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) 花费代价 cost = 1 使方向向下 --> (3, 3)
总花费为 cost = 3.
```

**示例 2：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/02/29/grid2.png)

```
输入：grid = [[1,1,3],[3,2,2],[1,1,4]]
输出：0
解释：不修改任何数字你就可以从 (0, 0) 到达 (2, 2) 。
```

**示例 3：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2020/02/29/grid3.png)

```
输入：grid = [[1,2],[4,3]]
输出：1
```

**示例 4：**

```
输入：grid = [[2,2,2],[2,2,2]]
输出：3
```

**示例 5：**

```
输入：grid = [[4]]
输出：0
```

**提示：**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 100`

题目来源： [力扣 1368. 使网格图至少有一条有效路径的最小代价](https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/) 。

这道题比较有意思，可以用 Dijkstra 算法解决。

题目相当于问 `(0, 0)` 到 `(m - 1, n - 1)` 的最短路径，只不过这个路径的权重和比较特殊：当 `grid[x][y] == directionId` 时，权重为 0，否则权重为 1。

直接看解法代码吧：

## 带限制条件的最短路径问题

### 787\. K 站中转内最便宜的航班

来看一下力扣第 787 题「 [K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 」：

有 `n` 个城市通过一些航班连接。给你一个数组  `flights` ，其中  `flights[i] = [from<sub>i</sub>, to<sub>i</sub>, price<sub>i</sub>]` ，表示该航班都从城市 `from<sub>i</sub>` 开始，以价格 `price<sub>i</sub>` 抵达 `to<sub>i</sub>` 。

现在给定所有的城市和航班，以及出发城市 `src` 和目的地 `dst` ，你的任务是找到出一条最多经过 `k`  站中转的路线，使得从 `src` 到 `dst` 的 **价格最便宜** ，并返回该价格。 如果不存在这样的路线，则输出 `-1` 。

**示例 1：**

```
输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
输出: 200
解释: 
城市航班图如下

从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。
```

**示例 2：**

```
输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
输出: 500
解释: 
城市航班图如下

从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
```

**提示：**

- `1 <= n <= 100`
- `0 <= flights.length <= (n * (n - 1) / 2)`
- `flights[i].length == 3`
- `0 <= from<sub>i</sub>, to<sub>i</sub> < n`
- `from<sub>i</sub> != to<sub>i</sub>`
- `1 <= price<sub>i</sub> <= 10<sup>4</sup>`
- 航班没有重复，且不存在自环
- `0 <= src, dst, k < n`
- `src != dst`

题目来源： [力扣 787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 。

这道题可以直接复用 [Dijkstra 拓展：带限制的最短路问题](https://labuladong.online/zh/algo/data-structure/dijkstra-follow-up/) 给出的 `dijkstra` 函数，不过需要注意，题目输入的 `K` 是允许经过的「节点」的限制，而不是「边」的限制。

允许经过最多 `K` 个节点，就相当于允许经过最多 `K + 1` 条边，所以在执行 `dijkstra` 函数之前，需要将 `K` 转换为 `K + 1` 。

最后还是那句话，做题在质不在量，希望大家能够透彻理解最基本的数据结构，以不变应万变。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表