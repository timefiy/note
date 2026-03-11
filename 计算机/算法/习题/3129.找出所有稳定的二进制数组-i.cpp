# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3129 lang=cpp
 *
 * [3129] 找出所有稳定的二进制数组 I
 */

// @lc code=start
class Solution {
    int memo[205][205][2];
    int MOD = 1e9 + 7;

public:
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(memo, -1, sizeof(memo));
        
        return (dp(zero, one, 0, limit) + dp(zero, one, 1, limit)) % MOD;
    }

    int dp(int zero, int one, int end, int& limit) {
        if (zero == 0) return (end == 1 && one <= limit) ? 1 : 0;
        if (one == 0) return (end == 0 && zero <= limit) ? 1 : 0;

        if (memo[zero][one][end] != -1) {
            return memo[zero][one][end];
        }

        long long res = 0;
        
        if (end == 0) {
            for (int k = 1; k <= min(zero, limit); ++k) {
                res = (res + dp(zero - k, one, 1, limit)) % MOD;
            }
        } else {
            for (int k = 1; k <= min(one, limit); ++k) {
                res = (res + dp(zero, one - k, 0, limit)) % MOD;
            }
        }

        return memo[zero][one][end] = res;
    }
};
// @lc code=end

