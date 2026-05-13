#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1674 lang=cpp
 *
 * [1674] 使数组互补的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size()/2; i++)
        {
            int sum = nums[i] + nums[nums.size() - 1 - i];
            count[sum]++;
        }
        
    }
};
// @lc code=end

