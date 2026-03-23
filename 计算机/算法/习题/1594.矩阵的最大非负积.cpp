# include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

/*
 * @lc app=leetcode.cn id=1594 lang=cpp
 *
 * [1594] 矩阵的最大非负积
 */

// @lc code=start
class Solution {
    vector<vector<int>> memu;
    int m, n;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 1;
        dp = vector<vector<int>>(m, vector<int>(n, 0));

        return res % MOD;
    }

    void dp(int i, int j){
        if(i == m - 1 && j == n - 1){
            dp[i][j] = grid[i][j];
            return;
        }
    }
};
// @lc code=end

