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
            if (c >= 'a' && c <= 'z') {
                if(count[c - 'a'] == 2){
                    ans++;
                    count[c - 'a'] = 3;
                }

                if(count[c - 'a'] != 3){
                    count[c - 'a'] = 1;
                }
            }
            if (c >= 'A' && c <= 'Z') {
                if(count[c - 'A'] == 1){
                    ans++;
                    count[c - 'A'] = 3;
                }

                if(count[c - 'A'] != 3){
                    count[c - 'A'] = 2;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

