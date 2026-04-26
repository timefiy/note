#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1559 lang=cpp
 *
 * [1559] 二维网格图中探测环
 */

// @lc code=start
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        visited[0][0] = true;
        return dfs(grid, 0, 0, visited, 1, 1 ,1);

    }
};

bool dfs(vector<vector<char>>& grid,int x,int y, vector<vector<bool>>& visited, int circle, int preX , int preY){
    if(){
        return true;
    }
    return false;
}
// @lc code=end

