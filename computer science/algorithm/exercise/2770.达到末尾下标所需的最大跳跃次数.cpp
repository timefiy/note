#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2770 lang=cpp
 *
 * [2770] 达到末尾下标所需的最大跳跃次数
 */

// @lc code=start
class Solution {
public:
    vector<int> memo;
    int maximumJumps(vector<int>& nums, int target) {
        memo = vector<int>(nums.size(), -1000);
        return dp(nums, target, 0);
    }

    int dp(vector<int>& nums, int target, int index){
        if (index == nums.size() - 1) {
            return 0;
        }
        
        if (memo[index] != -1000) {
            return memo[index];
        }

        int maxJump = -1;

        for (int j = index + 1; j < nums.size(); j++)
        {
            if (abs(nums[index] - nums[j]) <= target) {
                int result = dp(nums, target, j);
                if (result != -1) {
                    maxJump = max(maxJump, result + 1);
                }
            }
        }
        
        memo[index] = maxJump;

        return maxJump;
    }
};
// @lc code=end

