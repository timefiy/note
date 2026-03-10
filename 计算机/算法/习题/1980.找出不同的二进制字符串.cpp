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
        if(result.size() == n){
            if(s.find(result) == s.end()){
                result = curr_str;
                return true;
            }
        }

        
    }
};
// @lc code=end

