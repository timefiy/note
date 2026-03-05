#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3714 lang=cpp
 *
 * [3714] 最长的平衡子串 II
 */

// @lc code=start
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        int currentLen = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i-1]) currentLen++;
            else currentLen = 1;
            maxLen = max(maxLen, currentLen);
        }



        
        return maxLen;
    }
};
// @lc code=end

