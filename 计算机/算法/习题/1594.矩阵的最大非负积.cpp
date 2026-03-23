# include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1594 lang=cpp
 *
 * [1594] 矩阵的最大非负积
 */

// @lc code=start
class Solution {
    vector<vector<pair<int, int>>> memu;
    int m, n;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memu = vector<vector<pair<int, int>>>(m, vector<pair<int, int>>(n, {0, 0}));

        for(int i = 0; i < m; ++i){
            memu[i][0].first = memu[i][0].second = grid[i][0];
        }
        for (int j = 0; j < n; j++)
        {
            memu[0][j].first = memu[0][j].second = grid[0][j];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] >= 0){
                    memu[i][j].first = max(memu[i - 1][j].first * grid[i][j], memu[i][j - 1].first * grid[i][j]);
                    memu[i][j].second = min(memu[i - 1][j].second * grid[i][j], memu[i][j - 1].second * grid[i][j]);
                }
                else{
                    memu[i][j].first = max(memu[i - 1][j].second * grid[i][j], memu[i][j - 1].second * grid[i][j]);
                    memu[i][j].second = min(memu[i - 1][j].first * grid[i][j], memu[i][j - 1].first * grid[i][j]);
                }
            }
        }
        return memu[m - 1][n - 1].first % 100000007;
    }
};
// @lc code=end

