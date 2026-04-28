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
        
        // 2. 余数校验（可行性判断）
        // 以第一个元素的余数为基准，检查所有元素
        int mod = nums[0] % x; 
        for (int val : nums) {
            if (val % x != mod) {
                // 如果有任何元素余数不同，则永远无法化为单值网格
                return -1; 
            }
        }

        // 3. 排序找目标值（中位数）
        sort(nums.begin(), nums.end());
        int target = nums[nums.size() / 2];

        // 4. 计算最小操作数
        int ops = 0;
        for (int val : nums) {
            ops += abs(val - target) / x;
        }

        return ops;
    }
};
// @lc code=end

