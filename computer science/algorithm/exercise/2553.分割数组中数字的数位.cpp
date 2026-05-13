#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2553 lang=cpp
 *
 * [2553] 分割数组中数字的数位
 */

// @lc code=start
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            for (char c : to_string(nums[i]))
            {
                result.push_back(c - '0');
            }
        }
        return result;
    }
};
// @lc code=end

