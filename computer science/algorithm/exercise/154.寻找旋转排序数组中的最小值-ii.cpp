#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2; 

            if (nums[mid] > nums[mid + 1]) {
                left = mid + 1;
            } if (nums[mid] == nums[mid + 1]){
                for (int i = 0; i < nums.size()/2; i++)
                {
                    /* code */
                }
                
            } 
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};
// @lc code=end

