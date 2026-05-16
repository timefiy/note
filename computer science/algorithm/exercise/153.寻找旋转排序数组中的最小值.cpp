#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // 当 left == right 时，区间缩小为一个点，这就是我们要找的最小值
        while (left < right) {
            int mid = left + (right - left) / 2; // 防止整数溢出

            if (nums[mid] > nums[right]) {
                // 最小值在 mid 的右侧
                left = mid + 1;
            } else {
                // 最小值在 mid 或 mid 的左侧
                right = mid;
            }
        }

        // 循环结束时 left == right，指向的就是最小值
        return nums[left];
    }
};
// @lc code=end

