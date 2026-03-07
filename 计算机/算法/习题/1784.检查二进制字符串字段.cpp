# include <bits/stdc++.h>
using namespace std; 

/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s) {
        int flag = 0;
        for(char c : s){
            if(c == '1' && flag == 0) flag = 1;
            else if(flag ==1 && c == '0') flag = 2;
            else if(flag == 2 && c == '1') return false;
        }
        return true;
    }
};
// @lc code=end

