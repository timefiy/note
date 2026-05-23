# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1752 lang=cpp
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());

        int x;
        int a = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == a)
            {
                x = i;
                break;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums2[i+x] != nums[(i) % nums.size()])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

