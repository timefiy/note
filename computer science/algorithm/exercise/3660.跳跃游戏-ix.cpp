#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3660 lang=cpp
 *
 * [3660] 跳跃游戏 IX
 */

// @lc code=start
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        // 1. 计算前缀最大值
        vector<int> pref_max(n);
        pref_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref_max[i] = max(pref_max[i-1], nums[i]);
        }
        
        // 2. 计算后缀最小值
        vector<int> suff_min(n);
        suff_min[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suff_min[i] = min(suff_min[i+1], nums[i]);
        }
        
        vector<int> ans(n);
        int start = 0; // 记录当前区块的起点
        for (int i = 0; i < n; i++) {
            // 如果到达数组末尾，或者 "左侧最大值 <= 右侧最小值" 出现了断层
            if (i == n - 1 || pref_max[i] <= suff_min[i+1]) {
                
                // 找出当前独立区块 nums[start...i] 中的最大值
                int block_max = nums[start];
                for (int j = start + 1; j <= i; j++) {
                    block_max = max(block_max, nums[j]);
                }
                
                // 区块内的所有元素，都能到达该区块的最大值
                for (int j = start; j <= i; j++) {
                    ans[j] = block_max;
                }
                
                // 更新下一个区块的起点
                start = i + 1;
            }
        }
        
        return ans;
    }
};
// @lc code=end

