# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1758 lang=cpp
 *
 * [1758] 生成交替二进制字符串的最少操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(string s) {
        
    }
    
    int string0(string s){
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '0' && i % 2 == 0 || s[i] != '1' && i % 2 == 1){
                count++;
            }
        }
    }

    int string1(){

    }
};
// @lc code=end

