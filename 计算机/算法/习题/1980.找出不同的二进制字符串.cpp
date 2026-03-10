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

        string result = " ";
        backtrack(result, s, n);

        return result;
    }

    bool backtrack(string& result, const unordered_set<string>& s, int n){

    }
};
// @lc code=end

