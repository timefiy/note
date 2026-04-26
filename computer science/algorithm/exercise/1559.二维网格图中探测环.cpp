#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1559 lang=cpp
 *
 * [1559] 二维网格图中探测环
 */

// @lc code=start
class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, visited, -1, -1)) {
                        return true; 
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited, int preX, int preY) {
        visited[x][y] = true;
        
        int m = grid.size(), n = grid[0].size();

        for (auto& d : dirs) {
            int nextX = x + d[0];
            int nextY = y + d[1];

            // 检查是否越界
            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                // 2. 核心逻辑：只走向那些字符与当前字符相同的格子
                if (grid[nextX][nextY] == grid[x][y]) {
                    
                    // 3. 找到了环的条件：相邻格子已被访问，且不是我们刚刚走过来的那个格子
                    if (visited[nextX][nextY]) {
                        if (nextX != preX || nextY != preY) {
                            return true; // 恭喜，发现了一个合法的环！
                        }
                    } 
                    // 4. 如果没访问过，就继续以它为起点深度优先搜索
                    else {
                        if (dfs(grid, nextX, nextY, visited, x, y)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

