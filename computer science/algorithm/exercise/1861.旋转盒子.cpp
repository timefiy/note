# include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1861 lang=cpp
 *
 * [1861] 旋转盒子
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                res[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        // 一列一列处理，模拟重力
        for(int col = 0; col < m; ++col) {
            // empty_row 指向当前列可以放置石头的最底部空位
            int empty_row = n - 1; 
            
            // 自底向上遍历
            for(int row = n - 1; row >= 0; --row) {
                if(res[row][col] == '*') {
                    // 遇到障碍物，石头过不去，空位重置到障碍物上方
                    empty_row = row - 1;
                } else if(res[row][col] == '#') {
                    // 遇到石头，让它掉落到 empty_row 的位置
                    swap(res[row][col], res[empty_row][col]);
                    empty_row--; 
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

