---
title: "Hierholzer 算法寻找欧拉路径"
source: "https://labuladong.online/zh/algo/data-structure/eulerian-graph-hierholzer/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文介绍 Hierholzer 算法、欧拉图的应用以及相关的算法题。"
tags:
  - "clippings"
---
前置知识

阅读本文前，你需要先学习：

- [图结构的通用实现](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/)
- [图结构的 DFS/BFS 遍历](https://labuladong.online/zh/algo/data-structure-basic/graph-traverse-basic/)
- [欧拉图及一笔画游戏](https://labuladong.online/zh/algo/data-structure-basic/eulerian-graph/)

一句话总结

Hierholzer 算法是用于计算欧拉路径/欧拉回路的算法，其本质就是 [遍历图结构 **所有边** 的 DFS 算法](https://labuladong.online/zh/algo/data-structure-basic/graph-traverse-basic/) 的 **逆后序** 遍历结果。

在 [欧拉图及一笔画游戏](https://labuladong.online/zh/algo/data-structure-basic/eulerian-graph/) 中，我们通过经典的一笔画游戏学习了欧拉图的基本概念，探讨了欧拉路径/欧拉回路的判定条件。

关键就是看节点的度数，这里简单总结一下。如果你忘记了其中的原理，请先回去复习。

对于无向图：

- 如果所有节点的度数都是偶数，那么起点和终点是同一个节点，存在欧拉回路。我们可以以任意一个节点作为起点，遍历所有边后，一定可以回到起点。
- 如果存在两个奇数度节点，那么起点和终点分别是这两个节点，存在欧拉路径。我们可以任选一个奇数度节点作为起点，遍历所有边后，一定可以到达另一个奇数度节点。

对于有向图：

- 如果所有节点的入度和出度都相等，那么起点和终点是同一个节点，存在欧拉回路。我们可以以任意一个节点作为起点，遍历所有边后，一定可以回到起点。
- 如果存在两个节点入度和出度不相等，那么起点和终点分别是这两个节点，存在欧拉路径。我们可以任选一个入度和出度不相等的节点作为起点，遍历所有边后，一定可以到达另一个入度和出度不相等的节点。

接下来看看 Hierholzer 算法的代码实现，在 $O(E)$ 时间复杂度内找到欧拉路径/欧拉回路。

## Hierholzer 算法

Hierholzer 算法非常简单，本质就是 DFS 算法的逆后序遍历结果，分为以下几步：

1、根据每个节点的度数，确定欧拉路径/欧拉回路的起点。

2、从起点开始执行 **遍历所有边的 DFS 算法，记录后序遍历结果** 。

3、最后， **将后序遍历结果反转** ，即可得到欧拉路径/欧拉回路。对于无向图，由于边没有方向的区别，所以即便不反转，结果也是对的。

我们可以直接复用 [图结构的 DFS/BFS 遍历](https://labuladong.online/zh/algo/data-structure-basic/graph-traverse-basic/) 中讲解的「遍历所有边的 DFS 算法」，在后序位置添加一行代码即可实现 Hierholzer 算法（伪码）：

```
// 记录后序遍历结果

List<Integer> postOrder = new ArrayList<>();

// 从起点 s 开始遍历图的所有边

void traverseEdges(Graph graph, int s, boolean[][] visited) {

    // base case

    if (s < 0 || s >= graph.size()) {

        return;

    }

    for (Edge e : graph.neighbors(s)) {

      if (visited[s][e.to]) {

        continue;

      }

      visited[s][e.to] = true;

      traverseEdges(graph, e.to, visited);

    }

    // [!code highlight:2]

    // 后序位置，将当前节点添加到路径中

    postOrder.add(s);

}

// 根据度数确定起点

int start = findStartNode(graph);

// 从起点开始执行 DFS 算法

traverseEdges(graph, start, visited);

// 将后序遍历结果反转，即可得到欧拉路径/回路

Collections.reverse(postOrder);
```

不过 [图结构的 DFS/BFS 遍历](https://labuladong.online/zh/algo/data-structure-basic/graph-traverse-basic/) 中也讨论过，用二维 `visited` 数组来记录走过的边不是很好，因为需要创建一个二维数组，空间复杂度是 $O(V^2)$ ，时间复杂度是 $O(E+V^2)$ ，效率比较差。

其实还有其他的问题，比如对于求解欧拉路径的场景，是可以存在 [多重边](https://labuladong.online/zh/algo/data-structure-basic/graph-terminology/) 的，也就是说两个相邻节点之间可以存在多条重复的边，而二维的 `visited` 数组不能处理这种情况。

所以我们需要更好的办法来处理已经遍历过的边避免重复遍历。

比方说可以给 `Edge` 类中添加一个 `bool visited` 字段来记录这条边是否被遍历过。这样不会引入新的空间复杂度，也能处理多重边的情况。

不过最常见的解法是： **直接删掉已经遍历过的边** ，这样也能解决问题。

虽然删除边的操作会修改图结构，但是一般的算法题中，图结构本身就是我们自己构建的，所以修改图结构不是什么大问题。

基于这个思路，可以得到最终的 Hierholzer 算法代码（伪码）：

```
// 记录后序遍历结果

List<Integer> postOrder = new ArrayList<>();

// 从起点 s 开始遍历图的所有边

void traverseEdges(Graph graph, int s) {

    // base case

    if (s < 0 || s >= graph.size()) {

        return;

    }

    

    while (!graph.neighbors(s).isEmpty()) {

        Edge e = graph.neighbors(s).get(0);

        // 直接删除这条边

        graph.removeEdge(s, e.to);

        traverseEdges(graph, e.to);

    }

    // [!code highlight:2]

    // 后序位置，将当前节点添加到路径中

    postOrder.add(s);

}

// 根据度数确定起点

int start = findStartNode(graph);

// 从起点开始执行 DFS 算法

traverseEdges(graph, start);

// 将后序遍历结果反转，即可得到欧拉路径/回路

Collections.reverse(postOrder);
```

接下来给出一个比较完整的算法实现，其中的 `Graph` 接口来自 [图结构的通用实现](https://labuladong.online/zh/algo/data-structure-basic/graph-basic/) ，给有向图、无向图提供了统一的 API，方便大家理解算法逻辑：

```
// Graph 类的通用实现参考

// https://labuladong.online/algo/data-structure-basic/graph-basic/

class HierholzerAlgorithm {

    // 计算欧拉路径/回路，不存在则返回 null

    public static List<Integer> findEulerianPath(Graph graph) {

        // 1. 根据度数确定起点

        int start = findStartNode(graph);

        if (start == -1) {

            // 不存在欧拉路径/回路

            return null;

        }

        

        // 2. 从起点开始执行 DFS 算法，记录后序遍历结果

        List<Integer> postOrder = new ArrayList<>();

        traverse(graph, start, postOrder);

        

        // 3. 反转后序遍历结果，即可得到欧拉路径/回路

        Collections.reverse(postOrder);

        return postOrder;

    }

    // 图结构的 DFS 遍历函数

    private static void traverse(Graph graph, int u, List<Integer> postOrder) {

        // base case

        if (u < 0 || u >= graph.size()) {

            return;

        }

        while (!graph.neighbors(u).isEmpty()) {

            Edge edge = graph.neighbors(u).get(0);

            int v = edge.to;

            // 直接删掉边，避免重复遍历

            graph.removeEdge(u, v);

            traverse(graph, v, postOrder);

        }

        // 后序位置，记录后序遍历结果

        postOrder.add(u);

    }

    // 根据度数确定起点，如果不存在欧拉路径，返回 -1

    // 有向图和无向图的代码实现不同

    private static int findStartNode(Graph graph) {

        // ...

    }

}
```

对于有向图和无向图中的 Hierholzer 算法，有两个地方不同：

1、删除边的逻辑不同。无向图本质上是双向图，所以删除边的时候需要删除两条边，而有向图只需要删除一条边。不过我们使用了统一的 `Graph` 接口，所以这个差异已经在 `removeEdge` 方法中处理了。

2、判断起点和终点的逻辑不同。所以我们需要对有向图和无向图分别实现 `findStartNode` 函数。

无向图的 `findStartNode` 函数实现如下：

```
// 无向图的 findStartNode 函数实现

private static int findStartNode(Graph graph) {

    int start = 0;

    // 记录奇数度节点的数量

    int oddDegreeCount = 0;

    for (int i = 0; i < graph.size(); i++) {

        if (graph.neighbors(i).size() % 2 == 1) {

            oddDegreeCount++;

            start = i;

        }

    }

    // 如果奇数度节点的数量不是 0 或 2，则不存在欧拉路径

    if (oddDegreeCount != 0 && oddDegreeCount != 2) {

        return -1;

    }

    // 如果奇数度节点的数量是 0，则任意节点都可以作为起点，此时 start=0

    // 如果奇数度节点的数量是 2，任意一个奇数度节点作为起点，此时 start 就是奇数度节点

    return start;

}
```

有向图的 `findStartNode` 函数实现如下：

```
// 有向图的 findStartNode 函数实现

private static int findStartNode(Graph graph) {

    // 记录每个节点的入度和出度

    int[] inDegree = new int[graph.size()];

    int[] outDegree = new int[graph.size()];

    for (int i = 0; i < graph.size(); i++) {

        for (Edge edge : graph.neighbors(i)) {

            inDegree[edge.to]++;

            outDegree[i]++;

        }

    }

    // 如果每个节点的入度出度都相同，则存在欧拉回路，任意节点都可以作为起点

    boolean allSame = true;

    for (int i = 0; i < graph.size(); i++) {

        if (inDegree[i] != outDegree[i]) {

            allSame = false;

            break;

        }

    }

    if (allSame) {

        // 任意节点都可以作为起点，就让我们以 0 作为起点吧

        return 0;

    }

    // 现在寻找是否存在节点 x 和 y 满足：

    // inDegree[x] - outDegree[x] = 1 && inDegree[y] - outDegree[y] = -1

    // 且其他节点的入度和出度都相等

    // 如果存在，则 x 是起点，y 是终点

    int x = -1, y = -1;

    for (int i = 0; i < graph.size(); i++) {

        int delta = inDegree[i] - outDegree[i];

        if (delta == 0) {

            continue;

        }

        if (delta != 1 && delta != -1) {

            // 不存在欧拉路径

            return -1;

        }

        if (delta == 1 && x == -1) {

            x = i;

        } else if (delta == -1 && y == -1) {

            y = i;

        } else {

            // 不存在欧拉路径

            return -1;

        }

    }

    if (x != -1 && y != -1) {

        // 存在欧拉路径，x 是起点

        return x;

    }

    return -1;

}
```

复杂度分析

Hierholzer 算法的时间复杂度主要来自 DFS 算法，为 $O(E + V)$ 。

空间复杂度主要来自图结构的存储，如果用邻接表存储图则为 $O(E + V)$ ，如果用邻接矩阵存储图则为 $O(V^2)$ 。

## 正确性分析（可选）

Hierholzer 算法本质就是 DFS 算法，所以很容易写对。

但为什么对 DFS 的后序遍历结果进行反转（逆后序遍历），就可以得到欧拉路径/回路呢？逆后序遍历结果和前序遍历结果是什么关系，直接用前序遍历结果行不行？

这个逆后序遍历的原理比较精妙，需要对递归遍历的顺序有较深的认识， **所以这部分内容是可选的，对于大部分读者来说，记住结论会写算法计算欧拉路径就可以了** 。

下面来分享一下我的理解，帮助大家尽可能直观地理解。 **我会结合可视化面板，从递归树的角度来直观地展示** 。

首先， [欧拉图及一笔画游戏](https://labuladong.online/zh/algo/data-structure-basic/eulerian-graph/) 中已经证明了解法的存在性：

我们可以通过节点的度数确定起点和终点，从起点出发必然存在一条路径可以到达终点，且恰好经过所有边一次。

现在我将证明，从起点开始进行 DFS 算法遍历图中的所有边，然后对后序遍历结果进行反转，得到的就是欧拉路径。

请想象从起点开始 DFS 遍历图结构所产生的递归树，欧拉路径既然是「一笔画」，理论上它的递归树应该就是一条类似单链表的形态，但实际上它可能有两种形态：

1、只有一条从根节点到叶子节点的路径，类似一条单链表。此时从根节点到叶子节点的递归路径就是欧拉路径。

2、有两条从根节点到叶子节点的路径。此时两个叶子节点之间的路径就是欧拉路径。

比方下面这幅无向图：

其中度数为奇数的节点为 `0` 和 `3` ，所以起点要么选择 `0` ，要么选择 `3` 。请你想象一下 DFS 算法遍历的过程：

如果以节点 `3` 为起点，那么算法会直接遍历完右侧的所有节点 `0,1,2` ，最后回退到起点 `3` ，完成遍历。

这个过程的递归树就是由一条从根节点到叶子节点的树枝构成，类似一条单链表，下面的可视化面板展示了这一点：

算法可视化

请注意递归树，从递归树的根节点到叶子节点的递归路径就是欧拉路径 `3->0->1->2->0` ，逆后序遍历结果确实和前序遍历结果相同。

如果你以节点 `0` 为起点，那么算法会先递归遍历左侧的节点（只有一个节点 `3` ），然后回退到 `0` ，去遍历右侧的节点（ `1` 和 `2` ），最后回到起点 `0` ，完成遍历。

这个过程的递归树就是由两条从根节点到叶子节点的树枝构成，下面的可视化面板展示了这一点：

算法可视化

这种情况下的欧拉路径是 `0->2->1->0->3` ，请注意递归树，可以发现以下的特点：

1、欧拉路径其实是从递归树的一个叶子节点（ `0` ）为起点，另一个叶子节点（ `3` ）为终点。

2、上面单链表形态的二叉树左旋一位，即可得到当前的递归树。

显然，这种情况下前序遍历结果不再能得到正确答案，而逆后序遍历结果依然是欧拉路径。

以上分析应该可以让你直观地理解逆后序遍历结果就是欧拉路径的原因了。

其实，从递归树的角度可以更深刻地理解欧拉路径，而且由于递归树形态比较简单，你会看到有些 Hierholzer 算法的实现是直接把递归算法改为基于栈的迭代算法。不过我还是建议用递归 DFS 算法，因为理解记忆的成本最低。

## 完成一笔画游戏

在 [欧拉图及一笔画游戏](https://labuladong.online/zh/algo/data-structure-basic/eulerian-graph/) 中展示了本站配套的一笔画游戏，现在你可以尝试用 Hierholzer 算法来辅助求解这个游戏了。

一笔画游戏

参考解法代码如下：

```
function solveOneStroke(graph) {

    // 根据度数确定起点（题目保证必然存在欧拉路径）

    let start = 0;

    for (let node in graph) {

        if (graph[node].length % 2 === 1) {

            start = node;

            break;

        }

    }

    // 从起点开始执行 DFS 算法，记录后序遍历结果

    let postOrder = [];

    traverse(graph, start, postOrder);

    // 反转后序遍历结果，即可得到欧拉路径

    console.log(postOrder.reverse());

}

function traverse(graph, s, postOrder) {

    while (graph[s].length > 0) {

        // 无向图，删除两条边

        let neighbor = graph[s].pop();

        graph[neighbor].splice(graph[neighbor].indexOf(s), 1);

        traverse(graph, neighbor, postOrder);

    }

    // 后序位置记录节点

    postOrder.push(s);

}
```

这段代码可以打印出欧拉路径，辅助你完成一笔画游戏。

到这里，Hierholzer 算法就讲完了，下一章我们来看一些实际的算法题目。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表