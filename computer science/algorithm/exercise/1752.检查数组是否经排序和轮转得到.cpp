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
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // 用模运算模拟环形数组：当 i = n-1 时，(i + 1) % n 会自动回到 0
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            
            // 剪枝优化：如果在中途发现下降次数已经超过 1 次，直接断定不合法
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

