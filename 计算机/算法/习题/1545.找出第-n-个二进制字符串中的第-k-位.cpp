# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1545 lang=cpp
 *
 * [1545] 找出第 N 个二进制字符串中的第 K 位
 */

// @lc code=start
class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        s = findKthString(n, s);
        return s[k - 1];
    }

    string findKthString(int n, string &s){
        if (n == 0) {
            return s;
        }

        s = s + "1" + reverse(invert(s));

        return findKthString(n - 1, s);
    }

    void invert(string &s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
    }
};
// @lc code=end

