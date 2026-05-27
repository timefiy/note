#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3120 lang=cpp
 *
 * [3120] 统计特殊字母的数量 I
 */

// @lc code=start
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;

        vector<int> count(26, 0);
        for (char c : word) {
            if (c >= 'a' && c <= 'z' && count[c - 'a'] < 2) {
                count[c - 'a'];
            }
        }
    }
};
// @lc code=end

