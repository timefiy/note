#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2540 lang=cpp
 *
 * [2540] 最小公共值
 */

// @lc code=start
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] > nums2[j])
            {
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                return nums1[i];
            }
        }
        
        return -1;
    }
};
// @lc code=end

