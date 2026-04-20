# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1888 lang=cpp
 *
 * [1888] 使二进制字符串字符交替的最少反转次数
 */

// @lc code=start
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string doubled_s = s + s;
        
        // 构造两种完美交替的靶子
        string target_A = "";
        string target_B = "";
        for (int i = 0; i < 2 * n; i++) {
            target_A += (i % 2 == 0) ? '0' : '1'; // 010101...
            target_B += (i % 2 == 0) ? '1' : '0'; // 101010...
        }
        
        int min_flips = INT_MAX;
        int diff_A = 0; // 记录当前窗口和 target_A 的差异数
        int diff_B = 0; // 记录当前窗口和 target_B 的差异数
        
        // 开始滑动窗口遍历
        for (int i = 0; i < 2 * n; i++) {
            // 1. 右侧新字符进入窗口：如果不匹配，增加差异计数
            if (doubled_s[i] != target_A[i]) diff_A++;
            if (doubled_s[i] != target_B[i]) diff_B++;
            
            // 2. 左侧老字符移出窗口：如果窗口长度超过了 n，左边的字符就要出局
            if (i >= n) {
                int left = i - n; // 被踢出窗口的字符的索引
                if (doubled_s[left] != target_A[left]) diff_A--;
                if (doubled_s[left] != target_B[left]) diff_B--;
            }
            
            // 3. 当窗口大小刚好达到 n 时，开始记录最小反转次数
            if (i >= n - 1) {
                min_flips = min({min_flips, diff_A, diff_B});
            }
        }
        
        return min_flips;
    }
};
// @lc code=end
    
