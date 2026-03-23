# include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1594 lang=cpp
 *
 * [1594] 矩阵的最大非负积
 */

// @lc code=start
class Solution {
    vector<vector<pair<long long, long long>>> memu;
    int m, n;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memu = vector<vector<pair<long long, long long>>>(m, vector<pair<long long, long long>>(n, {0, 0}));

        memu[0][0].first = memu[0][0].second = grid[0][0];
        for(int i = 1; i < m; ++i){
            memu[i][0].first = memu[i - 1][0].first * grid[i][0];
            memu[i][0].second = memu[i - 1][0].second * grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            memu[0][j].first = memu[0][j - 1].first * grid[0][j];
            memu[0][j].second = memu[0][j - 1].second * grid[0][j];
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

        if (memu[m - 1][n - 1].first < 0) return -1;

        return memu[m - 1][n - 1].first % 1000000007;
    }
};
// @lc code=end

