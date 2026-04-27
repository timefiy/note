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
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,vector<int>>> dir = {{1,{0,1,0,1}},{2,{1,0,1,0}},{3,{0,1,1,0}},{4,{0,-1,1,0}},{5,{1,0,0,-1}},{6,{1,0,0,1}}};
    }
};
// @lc code=end

