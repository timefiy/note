#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1391 lang=cpp
 *
 * [1391] 检查网格中是否存在有效路径
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> pipe = {
        {},             // 0: 占位符
        {1, 3},         // 1: 左右 -> 可向右(1)，向左(3)
        {0, 2},         // 2: 上下 -> 可向上(0)，向下(2)
        {2, 3},         // 3: 左下 -> 可向下(2)，向左(3)
        {1, 2},         // 4: 右下 -> 可向右(1)，向下(2)
        {0, 3},         // 5: 左上 -> 可向上(0)，向左(3)
        {0, 1}          // 6: 右上 -> 可向上(0)，向右(1)
    };
    int m, n;

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        return dfs(grid, 0, 0, visited);
    }

    bool dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
        m = grid.size();
        n = grid[0].size();
        
        if (x == m - 1 && y == n - 1) {
            return true;
        }

        visited[x][y] = true;
        int currentType = grid[x][y];

        for (int dir : pipe[currentType]) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
                continue;
            }

            // 获取下一个管道的类型
            int nextType = grid[nx][ny];
            
            // 获取反方向
            int oppositeDir = (dir + 2) % 4; 
            
            bool isConnected = false;
            for (int nextDir : pipe[nextType]) {
                if (nextDir == oppositeDir) {
                    isConnected = true;
                    break;
                }
            }
            if (isConnected) {
                if (dfs(grid, nx, ny, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
// @lc code=end

