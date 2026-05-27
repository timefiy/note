#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1871 lang=cpp
 *
 * [1871] 跳跃游戏 VII
 */

// @lc code=start
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] != '0') return false; // 终点如果是 '1'，绝对无法到达

        // dp[i] 表示是否也可到达
        vector<bool> dp(n, false);
        dp[0] = true;

        // preCount 用于统计当前窗口 [i - maxJump, i - minJump] 内有多少个可达点
        int preCount = 0;

        for (int i = 1; i < n; i++) {
            // 将新进入窗口的合法点加进来
            if (i >= minJump && dp[i - minJump]) {
                preCount++;
            }
            //  将离开窗口的旧点移出去
            if (i > maxJump && dp[i - maxJump - 1]) {
                preCount--;
            }

            // 如果当前位置是 '0' 且窗口内有可达点，则当前位置可达
            if (s[i] == '0' && preCount > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};


// 错误思路
// 优势跳到最后一个在滑动窗口的“0”，这个“0”可能不满足但是前面的“0”满足

// class Solution {
// public:
//     bool canReach(string s, int minJump, int maxJump) {
//         int n = s.size();
//         if(n == 1) return true;
        
//         for(int i = 0; i < n;){
//             for(int j = min(i + maxJump, n - 1); j >= i + minJump; j--){
//                 if(s[j] == '0'&&s[i] == '0'){
//                     i = j;
//                     break;
//                 }

//                 if(i ==n - 1){
//                     return true;
//                 }

//                 return false;
//             }
//         }
//         return false;
//     }
// };
// @lc code=end

