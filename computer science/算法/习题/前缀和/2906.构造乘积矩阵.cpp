# include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2906 lang=cpp
 *
 * [2906] 构造乘积矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> p(m, vector<int>(n, 0));
        vector<vector<int>> pre(m, vector<int>(n, 1));
        vector<vector<int>> suf(m, vector<int>(n, 1));

        long long current_pre = 1; 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pre[i][j] = current_pre; 
                current_pre = (current_pre * grid[i][j]) % 12345; 
            }
        }

        long long current_suf = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                suf[i][j] = current_suf; 
                p[i][j] = (pre[i][j] * suf[i][j]) % 12345;
                current_suf = (current_suf * grid[i][j]) % 12345; 
            }
        }
        
        return p;
    }
};
// @lc code=end

