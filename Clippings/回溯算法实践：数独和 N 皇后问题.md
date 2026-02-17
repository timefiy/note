---
title: "回溯算法实践：数独和 N 皇后问题"
source: "https://labuladong.online/zh/algo/practice-in-action/sudoku-nqueue/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文讲解如何利用回溯算法解决数独问题和 N 皇后问题，解决力扣/LeetCode 上的 37,51,52 题，同时给出 Java/Python/Go/JavaScript/C++ 代码实现。"
tags:
  - "clippings"
---
读完本文，你不仅学会了算法套路，还可以顺便解决如下题目：

| LeetCode | 力扣 | 难度 |
| --- | --- | --- |
| [37\. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) | [37\. 解数独](https://leetcode.cn/problems/sudoku-solver/) |  |
| [51\. N-Queens](https://leetcode.com/problems/n-queens/) | [51\. N 皇后](https://leetcode.cn/problems/n-queens/) |  |
| [52\. N-Queens II](https://leetcode.com/problems/n-queens-ii/) | [52\. N 皇后 II](https://leetcode.cn/problems/n-queens-ii/) |  |

前置知识

阅读本文前，你需要先学习：

- [回溯算法核心框架](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/)

你已经学习过 [回溯算法核心框架](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) ，那么本文就来探讨两道经典算法题：数独游戏和 N 皇后问题。

选择这两个问题，主要是它们的解法思路非常相似，而且它们都是回溯算法在实际生活中的有趣应用。

## 游戏简介

### 数独游戏

大家应该都玩过数独游戏，就是给你一个 9x9 的棋盘，其中有一些格子预先填入了数字，让你在其余空的格子中填入数字 1~9，要求每行、每列和每个 3x3 的九宫格内数字都不能重复。

下面是一个数独游戏的例子（来源 [Wikipedia](https://en.wikipedia.org/wiki/Sudoku) ）：

![](https://labuladong.online/images/algo/sudoku/sudoku2.png)

我小的时候也尝试过玩数独游戏，但只要稍微有些难度，就搞不定了。后来我才知道做数独是有技巧的，有一些比较专业的数独游戏软件会教你玩数独的技巧，不过在我看来这些技巧都太复杂，根本就没有兴趣看下去。

现在学习了回溯算法，多困难的数独问题都拦不住我了。只要有规则，就一定可以暴力穷举出符合条件的答案来，不是吗？

下面是我用回溯算法完成数独的例子：

![](https://labuladong.online/images/algo/sudoku/sudoku_slove.gif)

稍后我会详细讲解这道题的解法。

### N 皇后问题

在国际象棋中，皇后可以攻击同一行、同一列和同一条对角线上的任意单位。N 皇后问题是指在一个 N×N 的棋盘上摆放 N 个皇后，要求任何两个皇后之间都不能互相攻击。

换句话说，就是让你在一个 N×N 的棋盘上放置 N 个皇后，使得每行、每列和每个对角线都只有一个皇后。

比如这是 8 皇后问题的一个解（来源 [Wikipedia](https://en.wikipedia.org/wiki/Eight_queens_puzzle) ）：

![](https://labuladong.online/images/algo/sudoku/8queue.jpg)

可以看到，对于任意一个皇后，它所在的行、列和对角线（左上、右上、左下、右下）都没有其他皇后，所以这就是一个符合规则的解。

在讲上述题目之前，我需要先讲一道比较简单的回溯算法问题，把这个问题作为铺垫，就能更容易理解数独游戏和 N 皇后问题的解法了。

## n 位二进制数的所有可能

我来给你编一道简单的题目，请你实现这样一个函数：

```
vector<string> generateBinaryNumber(int n);
```

函数的输入是一个正整数 `n` ，请你返回所有长度为 `n` 的二进制数（0、1 组成），你可以按任意顺序返回答案。

比如说 `n = 3` ，那么你需要以字符串形式返回如下 $2^3=8$ 种不同的二进制数：

```
000

001

010

011

100

101

110

111
```

这道题可以认为是数独游戏和 N 皇后问题的简化版：

这道题相当于让你对一个长度为 `n` 的一维数组中的每一个位置进行穷举，其中每个位置可以填 `0` 或 `1` 。

数独游戏相当于让你对一个 9x9 的二维数组中的每个位置进行穷举，其中每个位置可以是数字 `1~9` ，且同一行、同一列和同一个 3x3 的九宫格内数字不能重复。

N 皇后问题相当于让你对一个 `N x N` 的二维数组中的每个位置进行穷举，其中每个位置可以不放皇后或者放置皇后（相当于 `0` 或 `1` ），且不能存在多个皇后在同一行、同一列或同一对角线上。

所以，只要你把这道简化版的题目的穷举过程搞明白，其他问题都迎刃而解了，无非是规则多了一些而已。

### 思路分析

题目是对一个长度为 `n` 的数组进行穷举，每个位置可以填入 `0` 或 `1` ，让你返回所有可能的结果。

Important

**看到这种题目，脑海中应该立刻出现一棵递归树；有了这棵树，你就有办法使用 [回溯算法框架](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) 无遗漏地穷举所有可能的解；能无遗漏地穷举所有解，就一定能找到符合题目要求的答案** 。

具体来说，这道题的递归树应该是一棵 `n + 1` 层的二叉树。

就比如说 `n = 3` 的情况，算法返回如下 $2^3=8$ 种不同的二进制数：

```
000

001

010

011

100

101

110

111
```

这 8 种结果其实就是一棵高度为 4 的二叉树的叶子节点。你可以点开这个可视化面板，拉到最后一步，看看这棵递归树的样子：

算法可视化

深入理解递归树的含义

上面的可视化面板仅帮你画出了递归树，但是我希望你能够透彻地理解了这棵树的含义。

递归树的节点就是穷举过程中产生的状态，以不同的视角来看这些节点，会有不同的作用。

具体来说就是以下问题：

应该如何理解这棵树 **每一层的节点** ；应该如何理解这棵树 **每一列（每条树枝）的节点** ；应该如何理解 **每个节点本身** ？

你可以把鼠标移动到可视化面板生成的这棵递归树的每个节点上，会显示节点和树枝的信息。请你结合可视化面板的这些信息，听我来分析：

1、从层的角度来看，第 `i` 层的节点表示的就是长度为 `i` 的所有二进制数（ `i` 从 0 开始算），比如第 2 层的节点分别是 `00` 、 `01` 、 `10` 、 `11` ，这些就是长度为 2 的所有二进制数。

2、从列（树枝）的角度来看，每条树枝上的节点记录了状态转移的过程。比如你把鼠标移动到 `001` 这个节点上，树枝上会显示这个 `001` 是如何被穷举出来的，即首先选择 `0` ，然后选择 `0` ，最后选择 `1` 。

3、从节点的角度来看，每个节点都是一个状态，从该节点向下延伸的树枝，就是当前状态的所有可能的选择。比如第二层的节点 `01` ，它的前两位已经确定，现在要对第三位进行穷举。第三位可以是 `0` 或 `1` ，所以从 `01` 这个节点向下延伸的两个子节点就是 `010` 和 `011` 。

现在你应该彻底理解这棵递归树的含义了？接下来就可以根据 [回溯算法框架](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) 写出代码了：

```
class Solution {

public:

    vector<string> res;

    // 回溯路径

    string track;

    // 生成所有长度为 n 的二进制数

    vector<string> generateBinaryNumber(int n) {

        backtrack(n, 0);

        return res;

    }

    // 回溯算法核心框架

    void backtrack(int n, int i) {

        if (i == n) {

            // 当递归深度等于 n 时，说明找到一个长度为 n 的二进制数，结束递归

            // i 从 0 增加到 n，所以递归树的高度为 n + 1

            res.push_back(track);

            return;

        }

        // 选择有两种，0 或 1

        // 所以递归树是一棵二叉树

        for (int val : {0, 1}) {

            // 做选择

            track.push_back(val + '0');

            backtrack(n, i + 1);

            // 撤销选择

            track.pop_back();

        }

    }

};
```

## 数独游戏解法

来看力扣第 37 题「 [解数独](https://leetcode.cn/problems/sudoku-solver/) 」，让你寻找数独问题的 **一个可行解** ：

**37\. 解数独** | [力扣](https://leetcode.cn/problems/sudoku-solver/) | [LeetCode](https://leetcode.com/problems/sudoku-solver/)

编写一个程序，通过填充空格来解决数独问题。

数独的解法需 **遵循如下规则** ：

1. 数字 `1-9` 在每一行只能出现一次。
2. 数字 `1-9` 在每一列只能出现一次。
3. 数字 `1-9`  在每一个以粗实线分隔的  `3x3` 宫内只能出现一次。（请参考示例图）

数独部分空格内已填入了数字，空白格用 `'.'` 表示。

**示例 1：**

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2021/04/12/250px-sudoku-by-l2g-20050714svg.png)
```
输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
```

**提示：**

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` 是一位数字或者 `'.'`
- 题目数据 **保证** 输入数独仅有一个解

题目来源： [力扣 37. 解数独](https://leetcode.cn/problems/sudoku-solver/) 。

算法函数签名如下：

```
void solveSudoku(vector<vector<char>>& board);
```

先不管数独游戏的规则，反正现在就是有 9x9=81 个格子，每个格子都可以填入 1~9 对吧，那总共就有 $9^{81}$ 种填法，把这些解法都穷举一遍，一定可以找到符合规则的答案。

对于这个问题，你心里应该抽象出一棵九叉递归树，共有 81 层，只要心里有了这棵树，就可以参照前面实现的 `generateBinaryNumber` 函数写出求解数独游戏的代码了。

不过你可能会有以下疑惑：

1、前面 `generateBinaryNumber` 是针对一维数组的穷举，如何才能适配到数独游戏的二维数组呢？

2、 $9^{81}$ 是一个非常大的数字，穷举这么多递归树节点，即便写出回溯算法代码，也会超时吧？

3、 `generateBinaryNumber` 函数返回的是所有解，而数独题目只要求找到一个可行解，所以当我们找到一个可行解时就应该结束算法，这样可以减少时间复杂度。

我来一一解答。

**对于第一个问题** ，不熟悉递归的读者可能会有这个疑问，是不是在二维数组上递归就把你绕晕了？那么我们干脆玩个花样，直接绕过二维数组的问题，因为 **不管是几维的数组，都可以转化成一维数组** 。

说白了，就是设计一个编解码算法，能够把一个多维坐标（多元组）编码到一个一维坐标（数字），且可以反向解码回去。

对于一个 `MxN` 的二维数组，可以把二维坐标 `(i, j)` 映射到一维坐标 `index = i * N + j` ，反之可以通过 `i = index / N` 和 `j = index % N` 得到原来的二维坐标。

思考题

你能否设计一个编解码算法，把一个三维坐标 `(i, j, k)` 映射到一个一维坐标 `index` ，并且可以反向解码回去？

提示一下，可以结合面积、体积的计算公式来理解坐标的编解码算法。

有了这个编解码算法，数独游戏的 9x9 二维数组就可以在逻辑上看做一个长度为 81 的一维数组，然后按照一维数组的递归树来穷举即可。

**对于第二个问题** ， $9^{81}$ 只是一个非常粗略的估算，实际写代码时，要考虑数独的规则。

首先，初始棋盘会给你预先填充一些数字，这些数字是不能改变的，所以这些格子不用穷举，应该从 81 个格子去除。

另外，数独规则要求每行、每列和每个 3x3 的九宫格内数字都不能重复，所以实际上每个空格子可以填入的数字并不是真的有 9 种选择，而是要根据当前棋盘的状态，去除不合法的数字（剪枝）。

而且， $9^{81}$ 是穷举所有可行解的复杂度估算，实际上题目只要求我们寻找一个可行解，所以只要找到一个可行解就可以结束算法了，没必要穷举所有解。

那么这样算下来，穷举的实际复杂度取决于空格子的个数，远低于 $9^{81}$ ，所以不用担心超时问题。

讲到这里，我们应该可以发现一个有趣的现象：

按照人类的一般理解，规则越多，问题越难；但是对于计算机来说，规则越多，问题反而越简单。

因为它要穷举嘛，规则越多，越容易剪枝，搜索空间就越小，就越容易找到答案。反之，如果没有任何规则，那就是纯暴力穷举，效率会非常低。

我们对回溯算法的剪枝优化，本质上就是寻找规则，提前排除不合法的选择，从而提高穷举的效率。

**对于第三个问题** ，让算法在找到一个可行解时立即结束递归。这个问题有多种解决方案，我会建议使用一个全局变量来标记是否找到可行解（原因见 [解答回溯/DFS的若干问题](https://labuladong.online/zh/algo/essential-technique/backtrack-vs-dfs/) ），辅助递归算法提前终止。

解释清楚了这些问题，下面给出数独游戏的回溯算法代码实现：

```
class Solution {

    // 标记是否已经找到可行解

    bool found = false;

public:

    void solveSudoku(vector<vector<char>>& board) {

        backtrack(board, 0);

    }

private:

    // 路径：board 中小于 index 的位置所填的数字

    // 选择列表：数字 1~9

    // 结束条件：整个 board 都填满数字

    void backtrack(vector<vector<char>>& board, int index) {

        int m = 9, n = 9;

        int i = index / n, j = index % n;

        if (found) {

            // 已经找到一个可行解，立即结束

            return;

        }

        if (index == m * n) {

            // 找到一个可行解，触发 base case

            found = true;

            return;

        }

        if (board[i][j] != '.') {

            // 如果有预设数字，不用我们穷举

            backtrack(board, index + 1);

            return;

        }

        for (char ch = '1'; ch <= '9'; ch++) {

            // 剪枝：如果遇到不合法的数字，就跳过

            if (!isValid(board, i, j, ch))

                continue;

            // 做选择

            board[i][j] = ch;

            backtrack(board, index + 1);

            if (found) {

                // 如果找到一个可行解，立即结束

                // 不要撤销选择，否则 board[i][j] 会被重置为 '.'

                return;

            }

            // 撤销选择

            board[i][j] = '.';

        }

    }

    // 判断是否可以在 (r, c) 位置放置数字 num

    bool isValid(vector<vector<char>>& board, int r, int c, char num) {

        for (int i = 0; i < 9; i++) {

            // 判断行是否存在重复

            if (board[r][i] == num) return false;

            // 判断列是否存在重复

            if (board[i][c] == num) return false;

            // 判断 3 x 3 方框是否存在重复

            if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == num)

                return false;

        }

        return true;

    }

};
```

这个代码本来是可以通过力扣的所有用例的，但是现在可能因为力扣收紧了时间限制，导致 Python 语言的代码会超时。

兵来将挡，那我们就尝试优化一下这个解法。

回溯算法框架你肯定是改不了的，必须对每个格子穷举 1~9，才能穷举出正确答案。

但是注意这个 `isValid` 函数，它每次都要用 for 循环遍历行、列和九宫格。我们能不能想办法把这个 for 循环给它消掉呢？

其实是可以的。我们可以用空间换时间，额外使用 [哈希集合](https://labuladong.online/zh/algo/data-structure-basic/hash-set/) 存储每行、每列和每个九宫格中已经出现的元素，这样 `isValid` 函数只需要查询三次哈希集合，即可判断是否可以放置元素，理论时间复杂度是 $O(1)$ 。

不过请注意，根据我在力扣上的测试，这个思路仅对 Python 解法有优化效果，对其他语言反而会降低效率。

这里面的原因只能猜了，虽然 `isValid` 函数的理论时间复杂度优化到 $O(1)$ ，但由于算法逻辑和数据结构变得复杂，也许实际运行效率反而没有执行一个 1~9 的 for 循环快。

下面是用哈希集合来实现 `isValid` 的解法代码，供大家参考：

```
class Solution {

private:

    // 标记是否已经找到可行解

    bool found;

    // 记录每行已经出现的数字

    vector<unordered_set<char>> rows;

    // 记录每列已经出现的数字

    vector<unordered_set<char>> cols;

    // 记录每个九宫格已经出现的数字

    vector<unordered_set<char>> boxes;

public:

    Solution() : found(false), rows(9), cols(9), boxes(9) {}

    void solveSudoku(vector<vector<char>>& board) {

        // 将预设数字加入集合

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.') {

                    rows[i].insert(board[i][j]);

                    cols[j].insert(board[i][j]);

                    boxes[getBoxIndex(i, j)].insert(board[i][j]);

                }

            }

        }

        backtrack(board, 0);

    }

private:

    void backtrack(vector<vector<char>>& board, int index) {

        if (found) {

            // 已经找到一个可行解，立即结束

            return;

        }

        int m = 9, n = 9;

        int i = index / n, j = index % n;

        if (index == m * n) {

            // 找到一个可行解，触发 base case

            found = true;

            return;

        }

        if (board[i][j] != '.') {

            // 如果有预设数字，不用我们穷举

            backtrack(board, index + 1);

            return;

        }

        for (char ch = '1'; ch <= '9'; ch++) {

            // 剪枝：如果遇到不合法的数字，就跳过

            if (!isValid(i, j, ch)) continue;

            // 做选择，把 ch 填入 board[i][j]

            board[i][j] = ch;

            rows[i].insert(ch);

            cols[j].insert(ch);

            boxes[getBoxIndex(i, j)].insert(ch);

            backtrack(board, index + 1);

            if (found) {

                // 如果找到一个可行解，立即结束

                // 不要撤销选择，否则 board[i][j] 会被重置为 '.'

                return;

            }

            // 撤销选择，把 board[i][j] 重置为 '.'

            board[i][j] = '.';

            rows[i].erase(ch);

            cols[j].erase(ch);

            boxes[getBoxIndex(i, j)].erase(ch);

        }

    }

    // 获取 (r, c) 所在的九宫格索引

    int getBoxIndex(int r, int c) {

        return (r / 3) * 3 + (c / 3);

    }

    // 判断是否可以在 (r, c) 位置放置数字 num

    bool isValid(int r, int c, char num) {

        // 现在只需要查询三次哈希表即可

        if (rows[r].count(num)) return false;

        if (cols[c].count(num)) return false;

        if (boxes[getBoxIndex(r, c)].count(num)) return false;

        return true;

    }

};
```

## N 皇后问题解法

来看力扣第 51 题「 [N 皇后](https://leetcode.cn/problems/n-queens/) 」，让你寻找 N 皇后问题的 **所有解** ：

按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

**n 皇后问题** 研究的是如何将 `n`  个皇后放置在 `n×n` 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 `n` ，返回所有不同的  **n皇后问题** 的解决方案。

每一种解法包含一个不同的 **n 皇后问题** 的棋子放置方案，该方案中 `'Q'` 和 `'.'` 分别代表了皇后和空位。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/11/13/queens.jpg)
```
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。
```

**示例 2：**

```
输入：n = 1
输出：[["Q"]]
```

**提示：**

- `1 <= n <= 9`

题目来源： [力扣 51. N 皇后](https://leetcode.cn/problems/n-queens/) 。

算法函数签名如下：

```
vector<vector<string>> solveNQueens(int n);
```

其实 N 皇后问题和数独游戏的解法思路是一样的，具体有以下差别：

1、数独的规则和 N 皇后问题的规则不同，我们需要修改 `isValid` 函数，判断一个位置是否可以放置皇后。

2、题目要求找到 N 皇后问题所有解，而不是仅仅找到一个解。我们需要去除算法提前终止的逻辑，让算法穷举并记录所有的合法解。

这两个问题都比较容易解决，按理说可以直接参照数独游戏的代码实现 N 皇后问题。

但 N 皇后问题相对数独游戏还有一个优化： **我们可以以行为单位进行穷举，而不是像数独游戏那样以格子为单位穷举** 。

举个直观的例子，在数独游戏中，如果我们设置 `board[i][j] = 1` ，接下来呢，要去穷举 `board[i][j+1]` 了对吧？而对于 N 皇后问题，我们知道每行必然有且只有一个皇后，所以如果我们决定在 `board[i]` 这一行的某一列放置皇后，那么接下来就不用管 `board[i]` 这一行了，应该考虑 `board[i+1]` 这一行的皇后要放在哪里。

所以 N 皇后问题的穷举对象是棋盘中的行，每一行都持有一个皇后，可以选择把皇后放在该行的任意一列。

接下来直接看代码和注释吧：

```
#include <vector>

#include <string>

class Solution {

public:

    // 输入棋盘边长 n，返回所有合法的放置

    std::vector<std::vector<std::string>> solveNQueens(int n) {

        // '.' 表示空，'Q' 表示皇后，初始化空棋盘。

        std::vector<std::string> board(n, std::string(n, '.'));

        backtrack(board, 0);

        return res;

    }

private:

    std::vector<std::vector<std::string>> res;

    // 路径：board 中小于 row 的那些行都已经成功放置了皇后

    // 选择列表：第 row 行的所有列都是放置皇后的选择

    // 结束条件：row 超过 board 的最后一行

    void backtrack(std::vector<std::string>& board, int row) {

        // 触发结束条件

        if (row == board.size()) {

            res.push_back(board);

            return;

        }

        int n = board[row].size();

        for (int col = 0; col < n; col++) {

            // 排除不合法选择

            if (!isValid(board, row, col)) {

                continue;

            }

            // 做选择

            board[row][col] = 'Q';

            // 进入下一行决策

            backtrack(board, row + 1);

            // 撤销选择

            board[row][col] = '.';

        }

    }

    // 是否可以在 board[row][col] 放置皇后？

    bool isValid(const std::vector<std::string>& board, int row, int col) {

        int n = board.size();

        // 检查列是否有皇后互相冲突

        for (int i = 0; i < row; i++) {

            if (board[i][col] == 'Q')

                return false;

        }

        // 检查右上方是否有皇后互相冲突

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {

            if (board[i][j] == 'Q')

                return false;

        }

        // 检查左上方是否有皇后互相冲突

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {

            if (board[i][j] == 'Q')

                return false;

        }

        return true;

    }

};
```

再简单拓展一下，有可能题目不需要你计算出 N 皇后问题的所有具体结果，而仅仅问你共有几种解法，应该怎么做呢？

比如力扣第 52 题「 [N 皇后 II](https://leetcode.cn/problems/n-queens-ii/) 」：

**52\. N 皇后 II** | [力扣](https://leetcode.cn/problems/n-queens-ii/) | [LeetCode](https://leetcode.com/problems/n-queens-ii/)

**n 皇后问题** 研究的是如何将 `n`  个皇后放置在 `n × n` 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 `n` ，返回 **n 皇后问题** 不同的解决方案的数量。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/11/13/queens.jpg)
```
输入：n = 4
输出：2
解释：如上图所示，4 皇后问题存在两个不同的解法。
```

**示例 2：**

```
输入：n = 1
输出：1
```

**提示：**

- `1 <= n <= 9`

题目来源： [力扣 52. N 皇后 II](https://leetcode.cn/problems/n-queens-ii/) 。

算法函数签名如下：

```
int totalNQueens(int n);
```

其实你把我们上面写的代码 copy 过去也可以解决这个问题，因为我们计算出来的 `res` 就存储了所有合法的棋盘嘛，那么 `res` 中元素的个数不就是所有可行解法的总数吗？

是这样的，但要知道创建和存储这些具体的棋盘解法是要消耗空间和时间的，所以效率上会差一些。

更好的办法就是直接把 `res` 变量变成 int 类型，每次在 base case 找到一个合法答案的时候递增 `res` 变量即可：

```
class Solution {

    // 仅仅记录合法结果的数量

    int res = 0;

    void backtrack(vector<string>& board, int row) {

        if (row == board.size()) {

            // 找到一个合法结果

            res++;

            return;

        }

        // 其他都一样

    }

};
```

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表