---
title: 【游戏】扫雷 II
source: https://labuladong.online/zh/algo/game/minesweeper-ii/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本页面介绍了扫雷游戏的基本玩法，并使用算法完成点击展开地图的功能。
tags:
  - clippings
---
前置知识

阅读本文前，你需要先学习：

- [一文秒杀所有岛屿题目](https://labuladong.online/zh/algo/frequency-interview/island-dfs-summary/)

扫雷游戏是一款经典的单机游戏，玩家需要在一个方块阵列中，根据已知信息判断未知的方块是否是地雷，并标记出地雷的位置。

在本次游戏挑战中，请你完成 `expandClick(board, i, j)` 函数，实现用户点击单元格展开地图的算法：

当点击一个单元格 `board[i][j]` 时，该单元格会显示周围 8 个单元格中的地雷数量；若该单元格就是雷，则直接返回；如果周围没有地雷（数字为 0），则继续自动展开周围的单元格，直到遇到有数字的单元格为止。

扫雷游戏地图展开算法

## 讲解

这个问题就是想考察 DFS 算法，比较简单。

首次思考这个问题时，可能会认为当周围没有雷时的展开逻辑比较复杂，但仔细想一想其实很简单，只需要以下几步：

1、计算 `board[i][j]` 周围地雷数量。

2、如果雷的数量大于 0，则让 `board[i][j]` 显示雷的数量。

3、如果雷的数量为 0，则展开 `board[i][j]` ，并对周围单元格递归调用 `expandClick` 函数。

你可以认为 `board` 中每个地雷就是一个 3x3 的障碍物（因为雷本身以及周围 8 个单元格都会阻止地图展开），从这个角度来看，这道题就是简单的 DFS 算法。

参考解法如下：

```
// 游戏面板仅支持提交 JavaScript 代码

// 其他语言代码的作用是帮助大家理解算法逻辑

#include <vector>

void expandClick(std::vector<std::vector<int>>& board, int i, int j) {

    int height = board.size();

    int width = board[0].size();

    

    if (i < 0 || i >= height || j < 0 || j >= width || 

        board[i][j] != -1 || board[i][j] == -4) {

        return;

    }

    

    // 计算周围地雷数量

    int mineCount = 0;

    for (int di = -1; di <= 1; di++) {

        for (int dj = -1; dj <= 1; dj++) {

            if (di == 0 && dj == 0) continue;

            

            int ni = i + di;

            int nj = j + dj;

            

            if (ni >= 0 && ni < height && nj >= 0 && nj < width && 

                board[ni][nj] == -4) {

                mineCount++;

            }

        }

    }

    

    // 更新当前单元格为其周围地雷数量

    board[i][j] = mineCount;

    

    // 如果周围有地雷，则直接返回

    if (mineCount > 0) {

        return;

    }

    

    // 如果周围没有地雷，则递归展开相邻单元格

    for (int di = -1; di <= 1; di++) {

        for (int dj = -1; dj <= 1; dj++) {

            if (di == 0 && dj == 0) continue;

            

            expandClick(board, i + di, j + dj);

        }

    }

}
```

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表