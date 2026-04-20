---
title: BFS 经典习题 II
source: https://labuladong.online/zh/algo/problem-set/bfs-ii/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上所有 BFS（广度优先搜索）算法的经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
## BFS 在实际场景中的有趣应用

### 994\. 腐烂的橘子

**994\. 腐烂的橘子** | [力扣](https://leetcode.cn/problems/rotting-oranges/) | [LeetCode](https://leetcode.com/problems/rotting-oranges/)

在给定的 `m x n` 网格 `grid` 中，每个单元格可以有以下三个值之一：

- 值 `0` 代表空单元格；
- 值 `1` 代表新鲜橘子；
- 值 `2` 代表腐烂的橘子。

每分钟，腐烂的橘子 **周围 4 个方向上相邻** 的新鲜橘子都会腐烂。

返回 *直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 `-1`* 。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/02/16/oranges.png)**

```
输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
输出：4
```

**示例 2：**

```
输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
```

**示例 3：**

```
输入：grid = [[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
```

**提示：**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 10`
- `grid[i][j]` 仅为 `0` 、 `1`  或  `2`

题目来源： [力扣 994. 腐烂的橘子](https://leetcode.cn/problems/rotting-oranges/) 。

#### 基本思路

这就是标准的 BFS 算法，直接套 [BFS 算法框架](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 即可，没啥可说的，具体看代码和注释吧。

#### 解法代码

```
#include <queue>

#include <vector>

class Solution {

public:

    int orangesRotting(std::vector<std::vector<int>>& grid) {

        std::queue<std::vector<int>> queue;

        int m = grid.size(), n = grid[0].size();

        // 把所有腐烂的橘子加入队列，作为 BFS 的起点

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {

                    queue.push({i, j});

                }

            }

        }

        // 方向数组，方便计算上下左右的坐标

        std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // BFS 算法框架

        int step = 0;

        while (!queue.empty()) {

            int sz = queue.size();

            // 取出当前层所有节点，往四周扩散一层

            for (int i = 0; i < sz; i++) {

                std::vector<int> point = queue.front();

                queue.pop();

                for (const auto& dir : dirs) {

                    int x = point[0] + dir[0];

                    int y = point[1] + dir[1];

                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {

                        grid[x][y] = 2;

                        queue.push({x, y});

                    }

                }

            }

            // 扩散步数加一

            step++;

        }

        // 检查是否还有新鲜橘子

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // 有新鲜橘子，返回 -1

                if (grid[i][j] == 1) {

                    return -1;

                }

            }

        }

        // 注意，BFS 扩散的步数需要减一才是最终结果

        // 你可以用最简单的情况，比方说只有一个腐烂橘子的情况验证一下

        return step == 0 ? 0 : step - 1;

    }

};
```

#### 算法可视化

算法可视化

### 924\. 尽量减少恶意软件的传播

**924\. 尽量减少恶意软件的传播** | [力扣](https://leetcode.cn/problems/minimize-malware-spread/) | [LeetCode](https://leetcode.com/problems/minimize-malware-spread/)

给出了一个由 `n` 个节点组成的网络，用 `n × n` 个邻接矩阵图 `graph`  表示。在节点网络中，当 `graph[i][j] = 1`  时，表示节点  `i`  能够直接连接到另一个节点 `j` 。

一些节点 `initial` 最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。

假设 `M(initial)` 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。

如果从 `initial` 中 **移除某一节点** 能够最小化 `M(initial)` ， 返回该节点。如果有多个节点满足条件，就返回 **索引最小** 的节点。

请注意，如果某个节点已从受感染节点的列表 `initial` 中删除，它以后仍有可能因恶意软件传播而受到感染。

**示例 1：**

```
输入：graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
输出：0
```

**示例 2：**

```
输入：graph = [[1,0,0],[0,1,0],[0,0,1]], initial = [0,2]
输出：0
```

**示例 3：**

```
输入：graph = [[1,1,1],[1,1,1],[1,1,1]], initial = [1,2]
输出：1
```

**提示：**

- `n == graph.length`
- `n == graph[i].length`
- `2 <= n <= 300`
- `graph[i][j] == 0`  或  `1`.
- `graph[i][j] == graph[j][i]`
- `graph[i][i] == 1`
- `1 <= initial.length <= n`
- `0 <= initial[i] <= n - 1`
- `initial` 中所有整数均 **不重复**

题目来源： [力扣 924. 尽量减少恶意软件的传播](https://leetcode.cn/problems/minimize-malware-spread/) 。

#### 基本思路

看到这个题，我感觉这个题考察的肯定是图的连通性问题。

按照题目的描述，在同一个连通分量中，只要有一个节点被感染，那么整个连通分量中的所有节点最终都会被感染。

题目让我们删除一个初始感染节点，使得最终感染的节点数最小， **其实就是让我们找一个只有一个节点被感染的连通分量，且这个连通分量中的节点数最多** 。

只要把这个连通分量中的那个感染节点删掉，就可以减少最多的感染节点数，也就是题目说的最小化 `M(initial)` 。

对于连通性问题，我首先想到的是 [Union Find 并查集算法](https://labuladong.online/zh/algo/data-structure/union-find/) 。但仔细想想，这题好像没必要上并查集算法，普通的 DFS/BFS 算法也可以遍历连通分量，而且更简单。

所以这个题可以类比成经典的 [岛屿系列题目](https://labuladong.online/zh/algo/frequency-interview/island-dfs-summary/) ，如果看过这篇文章，肯定就会用 DFS 的解法来做这个题了。

DFS 的解法留给你参照岛屿题目实现吧，我这里就用 BFS 算法来做这个题。注意题目输入的图是 [邻接矩阵形式](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) ，你要知道怎么寻找邻居节点。

#### 解法代码

```
class Solution {

public:

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {

        int n = graph.size();

        unordered_set<int> initialSet(initial.begin(), initial.end());

        vector<bool> visited(n, false);

        // 因为题目要返回最小的节点编号，所以这里排个序，第一个找到的就是编号最小的

        sort(initial.begin(), initial.end());

        // 至少可以删掉一个节点，所以初始值为 initial[0]

        int targetNode = initial[0];

        int reduceCount = 0;

        for (int badNode : initial) {

            if (visited[badNode]) {

                continue;

            }

            // 进行 BFS 遍历，找到所有被感染的节点

            vector<int> count = bfs(graph, badNode, visited, initialSet);

            if (count[1] == 1) {

                // 如果这个连通分量中只有一个感染节点，那么这个节点就是可以删除的初始节点

                if (count[0] > reduceCount) {

                    reduceCount = count[0];

                    targetNode = badNode;

                }

            }

        }

        return targetNode;

    }

    // 执行 BFS 算法，返回两个值，第一个是这个 badNode 节点感染的节点总数（连通分量节点总数）

    // 和遍历过程中遇到的已经存在 initial 中的节点数（连通分量中的初始感染节点数）

    vector<int> bfs(vector<vector<int>>& graph, int badNode, vector<bool>& visited, unordered_set<int>& initialSet) {

        int n = graph.size();

        visited[badNode] = true;

        // 记录此次 BFS 扩散过程中遇到的已经存在 initial 中的节点

        int nodeCount = 0;

        int badCount = 0;

        // BFS 算法框架

        queue<int> q;

        q.push(badNode);

        while (!q.empty()) {

            int node = q.front();

            q.pop();

            nodeCount++;

            if (initialSet.count(node)) {

                badCount++;

            }

            // 邻接表形式的图，病毒向所有邻居节点扩散

            for (int neighborNode = 0; neighborNode < n; neighborNode++) {

                if (graph[node][neighborNode] == 1 && !visited[neighborNode]) {

                    q.push(neighborNode);

                    visited[neighborNode] = true;

                }

            }

        }

        return {nodeCount, badCount};

    }

};
```

#### 算法可视化

算法可视化

### 2101\. 引爆最多的炸弹

**2101\. 引爆最多的炸弹** | [力扣](https://leetcode.cn/problems/detonate-the-maximum-bombs/) | [LeetCode](https://leetcode.com/problems/detonate-the-maximum-bombs/)

给你一个炸弹列表。一个炸弹的 **爆炸范围** 定义为以炸弹为圆心的一个圆。

炸弹用一个下标从 **0**  开始的二维整数数组  `bombs`  表示，其中  `bombs[i] = [x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub>]` 。 `x<sub>i</sub>` 和  `y<sub>i</sub>`  表示第 `i`  个炸弹的 X 和 Y 坐标， `r<sub>i</sub>` 表示爆炸范围的 **半径** 。

你需要选择引爆 **一个** 炸弹。当这个炸弹被引爆时， **所有** 在它爆炸范围内的炸弹都会被引爆，这些炸弹会进一步将它们爆炸范围内的其他炸弹引爆。

给你数组 `bombs` ，请你返回在引爆 **一个** 炸弹的前提下， **最多** 能引爆的炸弹数目。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/11/06/desmos-eg-3.png)

```
输入：bombs = [[2,1,3],[6,1,4]]
输出：2
解释：
上图展示了 2 个炸弹的位置和爆炸范围。
如果我们引爆左边的炸弹，右边的炸弹不会被影响。
但如果我们引爆右边的炸弹，两个炸弹都会爆炸。
所以最多能引爆的炸弹数目是 max(1, 2) = 2 。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/11/06/desmos-eg-2.png)

```
输入：bombs = [[1,1,5],[10,10,5]]
输出：1
解释：
引爆任意一个炸弹都不会引爆另一个炸弹。所以最多能引爆的炸弹数目为 1 。
```

**示例 3：**

![](https://labuladong.online/images/lc/uploads/2021/11/07/desmos-eg1.png)

```
输入：bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
输出：5
解释：
最佳引爆炸弹为炸弹 0 ，因为：
- 炸弹 0 引爆炸弹 1 和 2 。红色圆表示炸弹 0 的爆炸范围。
- 炸弹 2 引爆炸弹 3 。蓝色圆表示炸弹 2 的爆炸范围。
- 炸弹 3 引爆炸弹 4 。绿色圆表示炸弹 3 的爆炸范围。
所以总共有 5 个炸弹被引爆。
```

**提示：**

- `1 <= bombs.length <= 100`
- `bombs[i].length == 3`
- `1 <= x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub> <= 10<sup>5</sup>`

题目来源： [力扣 2101. 引爆最多的炸弹](https://leetcode.cn/problems/detonate-the-maximum-bombs/) 。

#### 基本思路

这个题挺有意思的，其实题目输入的就是一幅 [有向无权图](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) ：在一个点的爆炸半径内部的其他点相当于是它可达的邻居节点，可以画一条有向边。

所以这个题相当于在问，给一幅有向图，你可以任选一个节点开始遍历，请问你最多能够遍历多少个节点？

那么解法也非常简单粗暴了，穷举嘛，尝试把每个点都作为起点进行 BFS/DFS 搜索，看看最多可以有多少个可达节点，也就是题目问的最多的引爆数量。

从一个起点遍历所有可达节点，这就是标准的 [图遍历算法](https://labuladong.online/zh/algo/data-structure-basic/graph-traverse-basic/) ，心里那棵树出来没有？我这里展示从一个节点开始 BFS 遍历的可视化面板：

算法可视化

如果你想用 DFS 算法也是一样的思路，可以自行实现。

#### 解法代码

```
#include <vector>

#include <list>

#include <queue>

#include <cmath>

#include <algorithm>

using namespace std;

class Solution {

public:

    int maximumDetonation(vector<vector<int>>& bombs) {

        // 邻接表存储图

        list<int> graph[bombs.size()];

        // 初始化邻接表

        for (int i = 0; i < bombs.size(); i++) {

            for (int j = 0; j < bombs.size(); j++) {

                if (i == j) {

                    continue;

                }

                if (pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2) <= pow(bombs[i][2], 2)) {

                    graph[i].push_back(j);

                }

            }

        }

        int max = 0;

        for (int i = 0; i < bombs.size(); i++) {

            // 以节点 i 进行 BFS 遍历，返回可达的节点数量

            max = std::max(max, bfs(graph, i, bombs.size()));

        }

        return max;

    }

    // BFS 算法框架

    int bfs(list<int> graph[], int start, int size) {

        int count = 0;

        queue<int> q;

        vector<bool> visited(size, false);

        q.push(start);

        visited[start] = true;

        while (!q.empty()) {

            int node = q.front();

            q.pop();

            count++;

            for (int neighbor : graph[node]) {

                if (!visited[neighbor]) {

                    q.push(neighbor);

                    visited[neighbor] = true;

                }

            }

        }

        return count;

    }

};
```

#### 算法可视化

算法可视化

### 542\. 01 矩阵

给定一个由 `0` 和 `1` 组成的矩阵 `mat`  ，请输出一个大小相同的矩阵，其中每一个格子是 `mat` 中对应位置元素到最近的 `0` 的距离。

两个相邻元素间的距离为 `1` 。

**示例 1：**

![](https://labuladong.online/images/lc/1626667201-NCWmuP-image.png)

```
输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
输出：[[0,0,0],[0,1,0],[0,0,0]]
```

**示例 2：**

![](https://labuladong.online/images/lc/1626667205-xFxIeK-image.png)

```
输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
输出：[[0,0,0],[0,1,0],[1,2,1]]
```

**提示：**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 10<sup>4</sup>`
- `1 <= m * n <= 10<sup>4</sup>`
- `mat[i][j] is either 0 or 1.`
- `mat` 中至少有一个 `0 `

题目来源： [力扣 542. 01 矩阵](https://leetcode.cn/problems/01-matrix/) 。

#### 基本思路

我在第一眼看到这个题目时有两个思路方向：一是 [动态规划](https://labuladong.online/zh/algo/essential-technique/dynamic-programming-framework/) ，二是 [BFS 算法](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 。

何以见得可以用动态规划思路解决呢？

首先这是个求最值的问题，而且我感觉 `mat[x][y]` 离 0 最近的距离肯定能根据它周围元素 `mat[x+1][y], mat[x][y+1], mat[x-1][y], mat[x][y-1]` 离 0 最近的距离推算出来。这就说明可以比较容易地得到状态转移方程，那么写出动态规划解法也就没什么困难了。

何以见得可以用 BFS 算法思路解决呢？

因为这题描述的场景让我想到 [111\. 二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/) 这类在二叉树中计算最小距离的题目，以及像 [1091\. 二进制矩阵中的最短路径](https://leetcode.cn/problems/shortest-path-in-binary-matrix/description/) 这种计算二维矩阵从左上角到右下角最短距离的题目。

再者，如果我把二维矩阵视为一幅 [「图」](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) ，那么最短距离肯定可以用图论中的最短距离算法计算出来。我在 [Dijkstra 最短路径算法](https://labuladong.online/zh/algo/data-structure/dijkstra/) 中就讲到了，Dijkstra 算法就是 BFS 算法在加权图中的升级版。所以这题肯定能用普通 BFS 算法解决。

我这里就使用 BFS 算法来求解吧，使用 [BFS 算法模板](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 中给出的框架改写一下就出来了，解法代码供参考。

#### 解法代码

```
#include <vector>

#include <queue>

using namespace std;

class Solution {

public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size();

        // 记录答案的结果数组

        vector<vector<int>> res(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        // 初始化全部填充特殊值 -1，代表未计算，

        // 待会可以用来判断坐标是否已经计算过，避免重复遍历

        

        // 初始化队列，把那些值为 0 的坐标放到队列里

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {

                    q.push({i, j});

                    res[i][j] = 0;

                }

            }

        }

        // 执行 BFS 算法框架，从值为 0 的坐标开始向四周扩散

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {

            auto [x, y] = q.front();

            q.pop();

            // 向四周扩散

            for (auto& dir : dirs) {

                int nextX = x + dir.first;

                int nextY = y + dir.second;

                // 确保相邻的这个坐标没有越界且之前未被计算过

                if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && res[nextX][nextY] == -1) {

                    q.push({nextX, nextY});

                    // 从 mat[x][y] 走到 mat[nextX][nextY] 需要一步

                    res[nextX][nextY] = res[x][y] + 1;

                }

            }

        }

        return res;

    }

};
```

#### 算法可视化

算法可视化

### 417\. 太平洋大西洋水流问题

**417\. 太平洋大西洋水流问题** | [力扣](https://leetcode.cn/problems/pacific-atlantic-water-flow/) | [LeetCode](https://leetcode.com/problems/pacific-atlantic-water-flow/)

有一个 `m × n` 的矩形岛屿，与 **太平洋** 和 **大西洋** 相邻。 **“太平洋”** 处于大陆的左边界和上边界，而 **“大西洋”** 处于大陆的右边界和下边界。

这个岛被分割成一个由若干方形单元格组成的网格。给定一个 `m x n` 的整数矩阵  `heights`  ，  `heights[r][c]` 表示坐标 `(r, c)` 上单元格 **高于海平面的高度** 。

岛上雨水较多，如果相邻单元格的高度 **小于或等于** 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

返回网格坐标 `result`  的 **2D 列表** ，其中 `result[i] = [r<sub>i</sub>, c<sub>i</sub>]` 表示雨水从单元格 `(ri, ci)` 流动 **既可流向太平洋也可流向大西洋** 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/06/08/waterflow-grid.jpg)

```
输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
```

**示例 2：**

```
输入: heights = [[2,1],[1,2]]
输出: [[0,0],[0,1],[1,0],[1,1]]
```

**提示：**

- `m == heights.length`
- `n == heights[r].length`
- `1 <= m, n <= 200`
- `0 <= heights[r][c] <= 10<sup>5</sup>`

题目来源： [力扣 417. 太平洋大西洋水流问题](https://leetcode.cn/problems/pacific-atlantic-water-flow/) 。

#### 基本思路

这个题我首先想到的就是纯暴力穷举：题目问哪些格子可以同时流入太平洋和大西洋，那么我就写一个嵌套 for 循环穷举每个格子，然后以每个格子为起点进行 BFS 或 DFS 暴力搜索，看看能否到达太平洋和大西洋。

这个解法虽然非常暴力，但也是可以优化的。比方说我如果确定 `(i, j)` 是可以同时到达太平洋和大西洋的格子，那么其他格子在暴力穷举时，如果能够走到 `(i, j)` ，那么它们也一定可以同时到达太平洋和大西洋。这就类似于备忘录剪枝，可以一定程度提高算法效率。

不过按照最坏时间复杂度来估算，上面这个想法复杂度是 `O(MN * MN)` ，其中 `M` 和 `N` 分别是矩阵的行数和列数。虽然题目给的数据规模不算大，但怎么看都觉得这个穷举过程有点太蠢了，可能会多次重复遍历同一个格子，所以我觉得肯定可以优化的。

**想要优化效率，思路也很简单，要么就是消除重复计算，要么就是充分利用信息** 。

对于这道题，显然最左侧、最上侧的格子一定可以流入太平洋，最右侧、最下侧的格子一定可以流入大西洋，这个信息可以充分利用起来。

比方说，我可以把以最左侧、最上侧的格子为起点向内陆进行反向搜索，就可以很容易地算出来哪些格子可以流入太平洋；同理，我也可以把以最右侧、最下侧的格子为起点向内陆进行反向搜索，就可以很容易地算出来哪些格子可以流入大西洋。

综合上面两个搜索结果，就可以筛选出来哪些格子可以同时流入太平洋和大西洋了。

这个思路进行两次时间复杂度是 `O(MN)` 的 BFS/DFS 搜索，所以总的时间复杂度还是 `O(MN)` ，比一开始的暴力穷举要高效。

我这里就用 BFS 来实现这个思路吧，DFS 也是一样的，你可以自己尝试一下。

#### 解法代码

```
#include <vector>

#include <queue>

using namespace std;

class Solution {

public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> res;

        int m = heights.size(), n = heights[0].size();

        // 第一列和第一行的格子一定可以流入太平洋

        // 加入队列，同时标记为已访问

        vector<vector<bool>> visitedP(m, vector<bool>(n, false));

        queue<pair<int, int>> queueP;

        for (int i = 0; i < m; i++) {

            queueP.push({i, 0});

            visitedP[i][0] = true;

        }

        for (int j = 1; j < n; j++) {

            queueP.push({0, j});

            visitedP[0][j] = true;

        }

        // 进行 BFS 搜索，找出所有可以流入太平洋的格子

        bfs(heights, queueP, visitedP);

        // 最后一列和最后一行的格子一定可以流入大西洋

        // 加入队列，同时标记为已访问

        vector<vector<bool>> visitedA(m, vector<bool>(n, false));

        queue<pair<int, int>> queueA;

        for (int i = 0; i < m; i++) {

            queueA.push({i, n - 1});

            visitedA[i][n - 1] = true;

        }

        for (int j = 0; j < n - 1; j++) {

            queueA.push({m - 1, j});

            visitedA[m - 1][j] = true;

        }

        // 进行 BFS 搜索，找出所有可以流入大西洋的格子

        bfs(heights, queueA, visitedA);

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (visitedP[i][j] && visitedA[i][j]) {

                    // 筛选出既可以流入太平洋又可以流入大西洋的格子

                    res.push_back({i, j});

                }

            }

        }

        return res;

    }

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& queue, vector<vector<bool>>& visited) {

        int m = heights.size(), n = heights[0].size();

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // BFS 算法框架

        while (!queue.empty()) {

            auto cur = queue.front();

            queue.pop();

            for (auto& dir : dirs) {

                int x = cur.first + dir.first, y = cur.second + dir.second;

                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || heights[x][y] < heights[cur.first][cur.second]) {

                    continue;

                }

                queue.push({x, y});

                visited[x][y] = true;

            }

        }

    }

};
```

#### 算法可视化

算法可视化

### 365\. 水壶问题

**365\. 水壶问题** | [力扣](https://leetcode.cn/problems/water-and-jug-problem/) | [LeetCode](https://leetcode.com/problems/water-and-jug-problem/)

有两个水壶，容量分别为 `x`  和 `y` 升。水的供应是无限的。确定是否有可能使用这两个壶准确得到  `target` 升。

你可以：

- 装满任意一个水壶
- 清空任意一个水壶
- 将水从一个水壶倒入另一个水壶，直到接水壶已满，或倒水壶已空。

**示例 1:**

```
输入: x = 3,y = 5,target = 4
输出: true
解释：
按照以下步骤操作，以达到总共 4 升水：
1. 装满 5 升的水壶(0, 5)。
2. 把 5 升的水壶倒进 3 升的水壶，留下 2 升(3, 2)。
3. 倒空 3 升的水壶(0, 2)。
4. 把 2 升水从 5 升的水壶转移到 3 升的水壶(2, 0)。
5. 再次加满 5 升的水壶(2, 5)。
6. 从 5 升的水壶向 3 升的水壶倒水直到 3 升的水壶倒满。5 升的水壶里留下了 4 升水(3, 4)。
7. 倒空 3 升的水壶。现在，5 升的水壶里正好有 4 升水(0, 4)。
参考：来自著名的 "Die Hard"
```

**示例 2:**

```
输入: x = 2, y = 6, target = 5
输出: false
```

**示例 3:**

```
输入: x = 1, y = 2, target = 3
输出: true
解释：同时倒满两个水壶。现在两个水壶中水的总量等于 3。
```

**提示:**

- `1 <= x, y, target <= 10<sup>3</sup>`

题目来源： [力扣 365. 水壶问题](https://leetcode.cn/problems/water-and-jug-problem/) 。

#### 基本思路

这道题非常经典，也非常有意思。我没记错的话，我小学就做过类似的数学题，不过那时候也没什么章法，反正不断地倒来倒去肯定能蒙出目标水量。

那么到了现在这个阶段，根据我之前介绍的 [算法学习心法](https://labuladong.online/zh/algo/essential-technique/algorithm-summary/) ，我们首先想的应该是把问题抽象成树结构，然后穷举所有的倒法，看看是否有可能凑出 `targetCapacity` 。

如果把两个桶中现有的水量作为「状态」，那么题目给出的几种倒水方法就是导致「状态」发生改变的「选择」，这样一来，你完全可以用 [动态规划详解进阶篇](https://labuladong.online/zh/algo/essential-technique/dynamic-programming-framework/) 里讲过的动态规划思路来做。

同时，你也可以用 [BFS 算法框架](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 来解决这道题。我这里就写 BFS 算法吧，具体细节看代码中的注释。

最后，这道题的最优解法是数学方法，你可以去了解一下「裴蜀定理」，也叫「贝祖定理」，有兴趣的读者可以自行搜索，我这里只给出最通用的计算机算法思路，不展开讲数学方法了。

#### 解法代码

```
class Solution {

public:

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {

        // BFS 算法的队列

        queue<pair<int, int>> q;

        // 用来记录已经遍历过的状态，把元组转化成数字方便存储哈希集合

        // 转化方式是 (x, y) -> (x * (jug2Capacity + 1) + y)，和二维数组坐标转一维坐标是一样的原理

        // 因为水桶 2 的取值是 [0, jug2Capacity]，所以需要额外加一，请类比二维数组坐标转一维坐标

        // 且考虑到题目输入的数据规模较大，相乘可能导致 int 溢出，所以使用 long 类型

        unordered_set<long long> visited;

        // 添加初始状态，两个桶都没有水

        q.push({0, 0});

        visited.insert(0 * (jug2Capacity + 1) + 0);

        while (!q.empty()) {

            auto curState = q.front();

            q.pop();

            if (curState.first == targetCapacity || curState.second == targetCapacity

                || curState.first + curState.second == targetCapacity) {

                // 如果任意一个桶的水量等于目标水量，就返回 true

                return true;

            }

            // 计算出所有可能的下一个状态

            vector<pair<int, int>> nextStates;

            // 把 1 桶灌满

            nextStates.push_back({jug1Capacity, curState.second});

            // 把 2 桶灌满

            nextStates.push_back({curState.first, jug2Capacity});

            // 把 1 桶倒空

            nextStates.push_back({0, curState.second});

            // 把 2 桶倒空

            nextStates.push_back({curState.first, 0});

            // 把 1 桶的水灌进 2 桶，直到 1 桶空了或者 2 桶满了

            nextStates.push_back({

                curState.first - min(curState.first, jug2Capacity - curState.second),

                curState.second + min(curState.first, jug2Capacity - curState.second)

            });

            // 把 2 桶的水灌进 1 桶，直到 2 桶空了或者 1 桶满了

            nextStates.push_back({

                curState.first + min(curState.second, jug1Capacity - curState.first),

                curState.second - min(curState.second, jug1Capacity - curState.first)

            });

            // 把所有可能的下一个状态都放进队列里

            for (auto& nextState : nextStates) {

                // 把二维坐标转化为数字，方便去重

                long long hash = (long long)nextState.first * (jug2Capacity + 1) + nextState.second;

                if (visited.count(hash) > 0) {

                    // 如果这个状态之前遍历过，就跳过，避免队列永远不空陷入死循环

                    continue;

                }

                q.push(nextState);

                visited.insert(hash);

            }

        }

        return false;

    }

};
```

#### 算法可视化

算法可视化

### 721\. 账户合并

**721\. 账户合并** | [力扣](https://leetcode.cn/problems/accounts-merge/) | [LeetCode](https://leetcode.com/problems/accounts-merge/)

给定一个列表 `accounts` ，每个元素 `accounts[i]` 是一个字符串列表，其中第一个元素 `accounts[i][0]` 是 *名称 (name)* ，其余元素是 ***emails*** 表示该账户的邮箱地址。

现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。

合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是 **按字符 ASCII 顺序排列** 的邮箱地址。账户本身可以以 **任意顺序** 返回。

**示例 1：**

```
输入：accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
输出：[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
解释：
第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。
```

**示例 2：**

```
输入：accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
输出：[["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
```

**提示：**

- `1 <= accounts.length <= 1000`
- `2 <= accounts[i].length <= 10`
- `1 <= accounts[i][j].length <= 30`
- `accounts[i][0]` 由英文字母组成
- `accounts[i][j] (for j > 0)` 是有效的邮箱地址

题目来源： [力扣 721. 账户合并](https://leetcode.cn/problems/accounts-merge/) 。

#### 基本思路

看完题目，我首先想到的是 [二分图](https://labuladong.online/zh/algo/data-structure/bipartite-graph/) 结构，即如果把用户名和邮箱看成两类节点存到同一幅图中，那么用户名节点的相邻节点就是邮箱，邮箱节点的相邻节点就是用户名。

但是又仔细想了下，二分图对这道题没啥实际作用，还不如用最简单的 HashMap 来存储用户和邮箱的关系。

因为人可能重名，但邮箱不会重复，所以我就想了一个简单的解法，把邮箱作为 key， `accounts` 的索引作为 value，这样就可以很方便地找到所有包含某个邮箱的账户。

然后我遍历这些账户，把所有的邮箱放到一个 HashSet 中去个重，最后排个序，不就得到合并后的账户了吗？题目又说同一个人不会有不同的名字，所以合并的这些邮箱对应的用户名肯定也都是一样的。

所以我就写出了下面这段代码：

```
List<List<String>> accountsMerge(List<List<String>> accounts) {

    // key: email, value: 出现该 email 的 account 的索引列表

    HashMap<String, List<Integer>> emailToIndexes = new HashMap<>();

    for (int i = 0; i < accounts.size(); i++) {

        List<String> account = accounts.get(i);

        for (int j = 1; j < account.size(); j++) {

            String email = account.get(j);

            List<Integer> indexes = emailToIndexes.getOrDefault(email, new ArrayList<>());

            indexes.add(i);

            emailToIndexes.put(email, indexes);

        }

    }

    // 计算合并后的账户

    List<List<String>> res = new ArrayList<>();

    HashSet<String> visitedEmails = new HashSet<>();

    for (String email : emailToIndexes.keySet()) {

        if (visitedEmails.contains(email)) {

            continue;

        }

        List<Integer> indexes = emailToIndexes.get(email);

        // 合并账户

        HashSet<String> mergedEmail = new HashSet<>();

        for (int index : indexes) {

            List<String> account = accounts.get(index);

            for (int j = 1; j < account.size(); j++) {

                mergedEmail.add(account.get(j));

                visitedEmails.add(account.get(j));

            }

        }

        // mergedEmail 是 userName 的所有邮箱

        String userName = accounts.get(indexes.get(0)).get(0);

        LinkedList<String> mergedAccount = new LinkedList<>(mergedEmail);

        Collections.sort(mergedAccount);

        mergedAccount.addFirst(userName);

        res.add(mergedAccount);

    }

    return res;

}
```

这段代码逻辑比较简单，但实际上是错的。错误地原因在于，只考虑了一层关联关系。

比方说， `email1` 和 `email1.1, email1.2, email1.3` 共同出现过，那么我可以确定 `email1, email1.1, email1.2, email1.3` 是同一个人的邮。

但如果 `email1.2` 又和 `email1.2.1, email1.2.2` 共同出现过，那么实际上这个人的邮箱应该是 `email1, email1.1, email1.2, email1.2.1, email1.2.2, email1.3` 。

而上述代码并没有考虑到这第二层关联关系。

所以看到没有，邮箱间的关联关系不是简单的线性结构，而是树结构，所以需要 DFS/BFS 算法来穷举。

具体来说，就是要把上述代码中的这个 for 循环：

```
// 合并账户

HashSet<String> mergedEmail = new HashSet<>();

for (int index : indexes) {

    List<String> account = accounts.get(index);

    for (int j = 1; j < account.size(); j++) {

        mergedEmail.add(account.get(j));

        visitedEmails.add(account.get(j));

    }

}
```

改为递归穷举函数，具体看代码，我这里就使用 BFS 算法吧，如果你想用 DFS 也是可以的。

#### 解法代码

```
class Solution {

public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // key: email, value: 出现该 email 的 account 的索引列表

        unordered_map<string, vector<int>> emailToIndexes;

        for (int i = 0; i < accounts.size(); i++) {

            vector<string>& account = accounts[i];

            for (int j = 1; j < account.size(); j++) {

                string email = account[j];

                emailToIndexes[email].push_back(i);

            }

        }

        // 计算合并后的账户

        vector<vector<string>> res;

        unordered_set<string> visitedEmails;

        for (const auto& [email, indexes] : emailToIndexes) {

            if (visitedEmails.count(email)) {

                continue;

            }

            // 合并账户，用 BFS 算法穷举所有和 email 相关联的邮箱

            deque<string> mergedEmail;

            queue<string> q;

            q.push(email);

            visitedEmails.insert(email);

            // BFS 算法框架

            while (!q.empty()) {

                string curEmail = q.front();

                q.pop();

                mergedEmail.push_back(curEmail);

                for (int index : emailToIndexes[curEmail]) {

                    vector<string>& account = accounts[index];

                    for (int j = 1; j < account.size(); j++) {

                        string nextEmail = account[j];

                        if (!visitedEmails.count(nextEmail)) {

                            q.push(nextEmail);

                            visitedEmails.insert(nextEmail);

                        }

                    }

                }

            }

            string userName = accounts[emailToIndexes[email][0]][0];

            // mergedEmail 是 userName 的所有邮箱

            sort(mergedEmail.begin(), mergedEmail.end());

            mergedEmail.push_front(userName);

            res.push_back(vector<string>(mergedEmail.begin(), mergedEmail.end()));

        }

        return res;

    }

};
```

#### 算法可视化

算法可视化

### 2850\. 将石头分散到网格图的最少移动次数

**2850\. 将石头分散到网格图的最少移动次数** | [力扣](https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/) | [LeetCode](https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid/)

给你一个大小为 `3 * 3`  ，下标从 **0**  开始的二维整数矩阵  `grid`  ，分别表示每一个格子里石头的数目。网格图中总共恰好有  `9` 个石头，一个格子里可能会有 **多个** 石头。

每一次操作中，你可以将一个石头从它当前所在格子移动到一个至少有一条公共边的相邻格子。

请你返回每个格子恰好有一个石头的 **最少移动次数** 。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2023/08/23/example1-3.svg)

```
输入：grid = [[1,1,0],[1,1,1],[1,2,1]]
输出：3
解释：让每个格子都有一个石头的一个操作序列为：
1 - 将一个石头从格子 (2,1) 移动到 (2,2) 。
2 - 将一个石头从格子 (2,2) 移动到 (1,2) 。
3 - 将一个石头从格子 (1,2) 移动到 (0,2) 。
总共需要 3 次操作让每个格子都有一个石头。
让每个格子都有一个石头的最少操作次数为 3 。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2023/08/23/example2-2.svg)

```
输入：grid = [[1,3,0],[1,0,0],[1,0,3]]
输出：4
解释：让每个格子都有一个石头的一个操作序列为：
1 - 将一个石头从格子 (0,1) 移动到 (0,2) 。
2 - 将一个石头从格子 (0,1) 移动到 (1,1) 。
3 - 将一个石头从格子 (2,2) 移动到 (1,2) 。
4 - 将一个石头从格子 (2,2) 移动到 (2,1) 。
总共需要 4 次操作让每个格子都有一个石头。
让每个格子都有一个石头的最少操作次数为 4 。
```

**提示：**

- `grid.length == grid[i].length == 3`
- `0 <= grid[i][j] <= 9`
- `grid`  中元素之和为  `9` 。

题目来源： [力扣 2850. 将石头分散到网格图的最少移动次数](https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/) 。

#### 基本思路

这个题挺有意思的，我一开始就想用 [BFS 算法框架](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 给它秒了，但试了下发现不行。普通 BFS 做不了这种资源分配型的问题，需要图论里面更复杂的网络流算法才能做。

后面我会在网站补充这些高级图算法，这里就先分享一下我的 BFS 算法吧，见代码中的 `FirstWrongBFSSolution` 类，虽然无法通过这道题，但是可能可以加深你对 BFS 算法框架的抽象运用能力。

注释写的比较清楚了，我的思路是队列中的节点记录自己的出发点，这样就能计算出已经移动的步数，并且知道是否还有多余的石子可以分配给空的格子。

这个解法看不出什么问题对吧？但这个测试用例就过不去了：

```
[[1,0,1],

 [1,2,0],

 [1,0,3]]

src: (1, 1), cur: (1, 1), next: (1, 2)

src: (2, 2), cur: (2, 2), next: (2, 1)

src: (2, 2), cur: (1, 1), next: (0, 1)
```

正确答案是 3，而我的算法返回了 5。看出来这个 5 是怎么来的了么？

我们预期 `(1, 1)` 去填补 `(0, 1)` ，但实际上它去填补了 `(1, 2)` ，这就使得 `(2, 2)` 需要去填补 `(0, 1)` ，所以多走了几步。

回想 BFS 算法的执行过程，在向四周扩散时得到的信息有限，并不能准确地控制 `(1, 1)` 去填补 `(0, 1)` ，所以朴素 BFS 无法解决这个问题。

我在 [BFS 算法框架](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 中说过，BFS 算法相对 DFS/回溯算法 的区别在于 BFS 里面有贪心思想。那么如果这道题没办法用 BFS，再加上数据规模较小，用回溯算法暴力穷举一定是可以做出来的。

回溯穷举的思路就是，比方说我把矩阵中的坐标分为 `A, B` 两个集合， `A` 集合是所有值大于 1 的坐标， `B` 集合是所有值等于 0 的坐标。

那么这就可以套用 [球盒模型：回溯算法的两种视角](https://labuladong.online/zh/algo/practice-in-action/two-views-of-backtrack/) 的穷举思路了：从 `A` 集合中每个坐标的视角来看，它可以在 `B` 集合中选择若干个坐标进行填充。

这样就可以直接写出回溯算法的代码了，具体看我的解法代码和注释吧。

#### 解法代码

```
// 尝试 BFS 框架失败，失败原因见我的思路分析

class FirstWrongBFSSolution {

    struct State {

        int srcX, srcY;

        int curX, curY;

        State(int sx, int sy, int cx, int cy) : srcX(sx), srcY(sy), curX(cx), curY(cy) {}

    };

public:

    int minimumMoves(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        queue<State> q;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] > 1) {

                    q.push(State(i, j, i, j));

                }

            }

        }

        int steps = 0;

        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {

            State cur = q.front();

            q.pop();

            int srcX = cur.srcX, srcY = cur.srcY;

            int curX = cur.curX, curY = cur.curY;

            for (auto dir : dirs) {

                int nextX = curX + dir[0], nextY = curY + dir[1];

                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {

                    continue;

                }

                if (grid[srcX][srcY] == 1) {

                    // 已经没有多余石子进行分配了，不必再入队了

                    break;

                }

                // 还有石子可以分配，看下当前这个格子是否需要分配

                if (grid[nextX][nextY] == 0) {

                    cout << "src: (" << srcX << ", " << srcY << "), cur: (" << curX << ", " << curY << "), next: (" << nextX << ", " << nextY << ")" << endl;

                    // 需要分配，就给当前格子分配一个

                    grid[nextX][nextY] = 1;

                    grid[srcX][srcY]--;

                    steps += abs(srcX - nextX) + abs(srcY - nextY);

                }

                // 继续往下一个格子走

                if (grid[srcX][srcY] > 1) {

                    // 还有石子可以分配，就继续入队

                    q.push(State(srcX, srcY, nextX, nextY));

                }

            }

        }

        return steps;

    }

};

// 用回溯算法框架暴力穷举

class Solution {

    // 记录最少的移动次数

    int minMove = INT_MAX;

    // 回溯过程中的移动次数

    int move = 0;

    // 记录空位的数量，以便知道什么时候填满了所有空格

    int emptyCount = 0;

public:

    int minimumMoves(vector<vector<int>>& grid) {

        // 记录可分配的坐标位置

        vector<pair<int, int>> redundant;

        // 记录待分配的坐标位置

        vector<pair<int, int>> empty;

        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] > 1) {

                    redundant.push_back({i, j});

                } else if (grid[i][j] == 0) {

                    empty.push_back({i, j});

                    emptyCount++;

                }

            }

        }

        backtrack(grid, redundant, empty);

        return minMove;

    }

private:

    void backtrack(vector<vector<int>>& grid, vector<pair<int, int>>& redundant, vector<pair<int, int>>& empty) {

        if (emptyCount == 0) {

            // 所有空位都填上了，更新最少的移动次数

            minMove = min(minMove, move);

            return;

        }

        // 从可分配的坐标的视角进行回溯穷举

        // 可以选择任意一个 empty 坐标进行填充

        for (auto r : redundant) {

            int srcX = r.first, srcY = r.second;

            if (grid[srcX][srcY] == 1) {

                // 这个坐标已经没有多余的石子可以分配了

                continue;

            }

            for (auto e : empty) {

                int destX = e.first, destY = e.second;

                if (grid[destX][destY] != 0) {

                    // 这个坐标已经被填充过了

                    continue;

                }

                // 计算填充的步数

                int step = abs(srcX - destX) + abs(srcY - destY);

                // 做选择，移动石子填充过来

                grid[destX][destY] = 1;

                grid[srcX][srcY]--;

                move += step;

                emptyCount--;

                // 递归

                backtrack(grid, redundant, empty);

                // 撤销选择

                grid[destX][destY] = 0;

                grid[srcX][srcY]++;

                move -= step;

                emptyCount++;

            }

        }

    }

};
```

#### 算法可视化

算法可视化

### 127\. 单词接龙

**127\. 单词接龙** | [力扣](https://leetcode.cn/problems/word-ladder/) | [LeetCode](https://leetcode.com/problems/word-ladder/)

字典 `wordList` 中从单词 `beginWord` 到 `endWord` 的 **转换序列** 是一个按下述规格形成的序列 `beginWord -> s<sub>1</sub> -> s<sub>2</sub> -> ... -> s<sub>k</sub>` ：

- 每一对相邻的单词只差一个字母。
- 对于 `1 <= i <= k` 时，每个 `s<sub>i</sub>` 都在 `wordList`  中。注意， `beginWord` 不需要在 `wordList` 中。
- `s<sub>k</sub> == endWord`

给你两个单词 `beginWord` 和 `endWord` 和一个字典 `wordList` ，返回 *从 `beginWord` 到  `endWord` 的 **最短转换序列** 中的 **单词数目*** 。如果不存在这样的转换序列，返回 `0` 。

**示例 1：**

```
输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
```

**示例 2：**

```
输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
输出：0
解释：endWord "cog" 不在字典中，所以无法进行转换。
```

**提示：**

- `1 <= beginWord.length <= 10`
- `endWord.length == beginWord.length`
- `1 <= wordList.length <= 5000`
- `wordList[i].length == beginWord.length`
- `beginWord` 、 `endWord` 和 `wordList[i]` 由小写英文字母组成
- `beginWord != endWord`
- `wordList` 中的所有字符串 **互不相同**

题目来源： [力扣 127. 单词接龙](https://leetcode.cn/problems/word-ladder/) 。

#### 基本思路

这种题没啥技巧，暴力穷举就行了。要穷举 `beginWord` 的所有转换序列，脑海的那棵多叉树出来没有？

`beginWord` 中的每个字符都有 26 种选择，所以那棵穷举树应该是一棵 N 叉树，其中 `N = 26 * beginWord.length()` 。

只要心里有了这棵树的抽象，题目相当于让我们计算从根节点 `beginWord` 到值为 `endWord` 的节点的最短路径。

回溯算法肯定是可以做的，因为回溯算法本来就是遍历多叉树嘛。但是在 [BFS 算法框架](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 中说过，这种求最短距离的问题，回溯算法的效率没有 BFS 高。

所以这道题用 BFS 算法，直接套用 [BFS 算法框架](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) 中讲到的框架就出来了，具体看代码和注释吧。

这里注意我们需要 `visited` 集合记录访问过的单词，避免重复访问。比方说 `aa` 可以变成 `ab` ，然后这个 `ab` 还可能变回 `aa` ，这样就陷入了重复的死循环。

当然你也可以不用一个新的 `visited` 集合，直接把访问过的单词从 `wordSet` 中移除，也是一样的效果。这种小优化可以自行使用，我还是使用最通用易懂的代码模板，方便大家理解。

#### 解法代码

```
class Solution {

public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // 将 wordList 转换为 HashSet，加速查找

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord)) {

            return 0;

        }

        wordSet.erase(beginWord);

        // 直接套用 BFS 算法框架

        queue<string> q;

        unordered_set<string> visited;

        visited.insert(beginWord);

        q.push(beginWord);

        int step = 1;

        while (!q.empty()) {

            int sz = q.size();

            for (int i = 0; i < sz; ++i) {

                // 穷举 curWord 修改一个字符能得到的单词

                // 即对每个字符，穷举 26 个字母

                string curWord = q.front();

                q.pop();

                // 开始穷举每一位字符 curWord[j]

                for (int j = 0; j < curWord.length(); ++j) {

                    char originChar = curWord[j];

                    // 对每一位穷举 26 个字母

                    for (char c = 'a'; c <= 'z'; ++c) {

                        if (c == originChar) continue;

                        curWord[j] = c;

                        // 如果构成的新单词在 wordSet 中，就是找到了一个可行的下一步

                        if (wordSet.count(curWord) && !visited.count(curWord)) {

                            if (curWord == endWord) {

                                return step + 1;

                            }

                            q.push(curWord);

                            visited.insert(curWord);

                        }

                    }

                    // 最后别忘了把 curWord[j] 恢复

                    curWord[j] = originChar;

                }

            }

            // 这里增加步数

            ++step;

        }

        return 0;

    }

};
```

#### 算法可视化

算法可视化

### 399\. 除法求值

**399\. 除法求值** | [力扣](https://leetcode.cn/problems/evaluate-division/) | [LeetCode](https://leetcode.com/problems/evaluate-division/)

给你一个变量对数组 `equations` 和一个实数值数组 `values` 作为已知条件，其中 `equations[i] = [A<sub>i</sub>, B<sub>i</sub>]` 和 `values[i]` 共同表示等式 `A<sub>i</sub> / B<sub>i</sub> = values[i]` 。每个 `A<sub>i</sub>` 或 `B<sub>i</sub>` 是一个表示单个变量的字符串。

另有一些以数组 `queries` 表示的问题，其中 `queries[j] = [C<sub>j</sub>, D<sub>j</sub>]` 表示第 `j` 个问题，请你根据已知条件找出 `C<sub>j</sub> / D<sub>j</sub> = ?` 的结果作为答案。

返回 **所有问题的答案** 。如果存在某个无法确定的答案，则用 `-1.0` 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 `-1.0` 替代这个答案。

**注意：** 输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。

**注意：** 未在等式列表中出现的变量是未定义的，因此无法确定它们的答案。

**示例 1：**

```
输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
解释：
条件：a / b = 2.0, b / c = 3.0
问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
注意：x 是未定义的 => -1.0
```

**示例 2：**

```
输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
输出：[3.75000,0.40000,5.00000,0.20000]
```

**示例 3：**

```
输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
输出：[0.50000,2.00000,-1.00000,-1.00000]
```

**提示：**

- `1 <= equations.length <= 20`
- `equations[i].length == 2`
- `1 <= A<sub>i</sub>.length, B<sub>i</sub>.length <= 5`
- `values.length == equations.length`
- `0.0 < values[i] <= 20.0`
- `1 <= queries.length <= 20`
- `queries[i].length == 2`
- `1 <= C<sub>j</sub>.length, D<sub>j</sub>.length <= 5`
- `A<sub>i</sub>, B<sub>i</sub>, C<sub>j</sub>, D<sub>j</sub>` 由小写英文字母与数字组成

题目来源： [力扣 399. 除法求值](https://leetcode.cn/problems/evaluate-division/) 。

#### 基本思路

这道题说白了就是考你 [有向加权图](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) 的遍历。

`a/b=2` 就相当于往图中添加了一条 `a->b` 权值为 2 的边，同时添加一条 `b->a` 权值为 1/2 的边。

`queries` 问你 `x/y` 的值，相当于就是图中是否存在一条从 `x` 到 `y` 的路径，如果有，那么路径上所有边的权值相乘就是 `x/y` 的值。

所以思路就很简单了，用邻接表建图，然后用 DFS 或者 BFS 遍历即可，我这里就用 BFS 吧。

#### 解法代码

```
class Solution {

    struct Edge {

        std::string node;

        double weight;

        Edge(std::string node, double weight) {

            this->node = node;

            this->weight = weight;

        }

    };

public:

    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values,

                                     std::vector<std::vector<std::string>>& queries) {

        // 把 equations 抽象成一幅图，邻接表存储

        std::unordered_map<std::string, std::vector<Edge>> graph;

        for (int i = 0; i < equations.size(); ++i) {

            std::vector<std::string>& equation = equations[i];

            std::string a = equation[0], b = equation[1];

            double w = values[i];

            // 构建双向图

            if (graph.find(a) == graph.end()) {

                graph[a] = std::vector<Edge>();

            }

            graph[a].emplace_back(b, w);

            if (graph.find(b) == graph.end()) {

                graph[b] = std::vector<Edge>();

            }

            graph[b].emplace_back(a, 1.0 / w);

        }

        std::vector<double> res(queries.size());

        for (int i = 0; i < queries.size(); ++i) {

            std::vector<std::string>& query = queries[i];

            std::string start = query[0], end = query[1];

            // BFS 遍历图，计算 start 到 end 的路径乘积

            res[i] = bfs(graph, start, end);

        }

        return res;

    }

private:

    double bfs(std::unordered_map<std::string, std::vector<Edge>>& graph, std::string start, std::string end) {

        if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {

            // 不存在的节点，肯定无法到达

            return -1.0;

        }

        if (start == end) {

            return 1.0;

        }

        // BFS 标准框架

        std::queue<std::string> queue;

        std::unordered_set<std::string> visited;

        queue.push(start);

        visited.insert(start);

        // key 为节点 ID（变量名），value 记录从 start 到该节点的路径乘积

        std::unordered_map<std::string, double> weight;

        weight[start] = 1.0;

        while (!queue.empty()) {

            std::string cur = queue.front();

            queue.pop();

            for (Edge& neighbor : graph[cur]) {

                if (visited.find(neighbor.node) != visited.end()) {

                    continue;

                }

                // 更新路径乘积

                weight[neighbor.node] = weight[cur] * neighbor.weight;

                if (neighbor.node == end) {

                    return weight[end];

                }

                // 记录 visited

                visited.insert(neighbor.node);

                // 新节点加入队列继续遍历

                queue.push(neighbor.node);

            }

        }

        return -1.0;

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论(6)

Markdown

Ctrl+Enter 发表

![richiefhf](https://thirdwx.qlogo.cn/mmopen/vi_32/Q3auHgzwzM4MV4l33ho93Vnnh3opbXsUjibRE4TJjrT6rGupnib6fG5iboTEJCkSfjhJHTZ6K7RwrWianY90VKZc7sbyE0YsFIbc/132)

richiefhf 9 个月前

721 用Union Find做会不会更合适？

![乐子人](https://thirdwx.qlogo.cn/mmopen/vi_32/8GABCepDybib74sx1cJozKbibESgFicib2wVnu0t4e9wT32U6WGAAoMdDzjb37r9JAbQXRiaJ19TY9jNnOH1H7U6DUvUSIpB5yXxxxibXTHw921eo/132)

乐子人 10 个月前

烂橘子为什么不用visited数组记录？

该评论已被折叠

该评论已被折叠