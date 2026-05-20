#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2657 lang=cpp
 *
 * [2657] 找到两个数组的前缀公共数组
 */

// @lc code=start
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> map;
        vector<int> res = vector<int>(A.size(), 0);

        for (int i = 0; i < A.size(); i++)
        {
            if

            map[A[i]]++;
            map[B[i]]++;

        }
        
        
        return res;
    }
};
// @lc code=end

