# include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1594 lang=cpp
 *
 * [1594] 矩阵的最大非负积
 */

// @lc code=start
class Solution {
    vector<vector<int>> dp;
    int m, n;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 1;
        dp = vector<vector<int>>(m, vector<int>(n, 0));

        return res % 1e9 + 7;
    }

    void dp(int i, int j){
        if
    }
};
// @lc code=end

