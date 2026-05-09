# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2033 lang=cpp
 *
 * [2033] 获取单值网格的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> nums;
         
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                nums.push_back(grid[i][j]);
            }
        }
        
        int mod = nums[0] % x; 
        for (int val : nums) {
            if (val % x != mod) {
                return -1; 
            }
        }

        sort(nums.begin(), nums.end());
        int target = nums[nums.size() / 2];

        int ops = 0;
        for (int val : nums) {
            ops += abs(val - target) / x;
        }

        return ops;
    }
};
// @lc code=end

