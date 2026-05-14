#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2784 lang=cpp
 *
 * [2784] 检查数组是否是好的
 */

// @lc code=start
class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> count(nums.size() , 0);
        for (int i : nums)
        {
            count[i]++;
        }

        int n = nums.size();
        if (count[n - 1] != 2)
        {
            return false;
        }
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (count[i] != 1)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

