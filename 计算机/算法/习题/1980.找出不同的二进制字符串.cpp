# include <bits/stdc++.h>
using namespace std;


/*
 * @lc app=leetcode.cn id=1980 lang=cpp
 *
 * [1980] 找出不同的二进制字符串
 */

// @lc code=start
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(), nums.end());
        int n = nums.size();

        string result = "";
        string curr_str = "";
        backtrack(result, curr_str, s, n);

        return result;
    }

    bool backtrack(string& result, string curr_str,const unordered_set<string>& s, int n){
        if(curr_str.size() == n){
            if(s.find(curr_str) == s.end()){
                result = curr_str;
                return true;
            }
        return false;
        }

        curr_str.push_back('0');
        if(backtrack(result, curr_str, s, n)) return true;
        curr_str.pop_back();

        curr_str.push_back('1');
        if(backtrack(result, curr_str, s, n)) return true;
        curr_str.pop_back();

        return false;
    }
};
// @lc code=end

