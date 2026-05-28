#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3121 lang=cpp
 *
 * [3121] 统计特殊字母的数量 II
 */

// @lc code=start
class Solution {
public:
    int numberOfSpecialChars(string word) {
        // status[i] 记录字母 i 的状态：0=未出现, 1=仅有小写, 2=已配对成功, -1=非法作废
        vector<int> status(26, 0);
        int ans = 0;

        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                int idx = c - 'a';
                if (status[idx] == 0) {
                    status[idx] = 1; 
                } else if (status[idx] == 2) {
                    status[idx] = -1; 
                    ans--;
                }
            } 
            else if (c >= 'A' && c <= 'Z') {
                int idx = c - 'A';
                if (status[idx] == 1) {
                    status[idx] = 2;
                    ans++;
                } else if (status[idx] == 0) {
                    status[idx] = -1;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

