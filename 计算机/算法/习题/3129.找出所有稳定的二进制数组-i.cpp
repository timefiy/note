# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3129 lang=cpp
 *
 * [3129] 找出所有稳定的二进制数组 I
 */

// @lc code=start
class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> memo;

    int numberOfStableArrays(int zero, int one, int limit) {
        memo = vector<vector<int>>(zero + 1, vector<int>(one + 1, -1));
        return dp(zero, one, -1, limit);
    }

    int dp(int zero, int one, int end, int& limit) {
        if (zero == 0)
        {
            return (end == 0 && one <= limit) ? 1 : 0;
        }
        if (one == 0)
        {
            return (end == 1 && zero <= limit) ? 1 : 0;
        }
        
        
        if(zero == 0 && one == 0){

        }
    }
};
// @lc code=end

