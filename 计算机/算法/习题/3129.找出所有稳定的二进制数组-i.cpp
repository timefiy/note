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

    // 递归函数
    // end 代表当前这段序列必须以 0 还是 1 结尾
    int dp(int zero, int one, int end, int& limit) {
        // 1. 基础情况：如果只剩下 1 种数字了
        // 如果没有 0 了，那全得排 1。只有当我们要排 1 (end == 1) 且数量不超过 limit 时才合法，有 1 种排法。
        if (zero == 0) return (end == 1 && one <= limit) ? 1 : 0;
        // 同理，如果没有 1 了，全得排 0。
        if (one == 0) return (end == 0 && zero <= limit) ? 1 : 0;

        // 2. 查表：如果这个状态已经算过了，直接返回，避免重复计算（解决超时的关键！）
        if (memo[zero][one][end] != -1) {
            return memo[zero][one][end];
        }

        // 3. 核心尝试逻辑（放块）
        long long res = 0;
        
        if (end == 0) {
            // 如果要求以 0 结尾，我们就尝试在末尾放 k 个 0 (k 从 1 到 limit)
            for (int k = 1; k <= min(zero, limit); ++k) {
                // 放了 k 个 0 后，剩下的部分必须以 1 结尾
                res = (res + dp(zero - k, one, 1, limit)) % MOD;
            }
        } else { // end == 1
            // 如果要求以 1 结尾，尝试在末尾放 k 个 1
            for (int k = 1; k <= min(one, limit); ++k) {
                // 放了 k 个 1 后，剩下的部分必须以 0 结尾
                res = (res + dp(zero, one - k, 0, limit)) % MOD;
            }
        }

        // 4. 将计算结果存入备忘录并返回
        return memo[zero][one][end] = res;
    }
};
// @lc code=end

