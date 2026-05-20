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
            res[i] = res[i - 1];

            if(map[A[i]] == 2){
                res[i] = res[i] - 1;
            }
            if(map[B[i]] == 2){
                res[i] = res[i] - 1;
            }

            map[A[i]]++;
            map[B[i]]++;

            if(map[A[i]] == 2){
                res[i] = res[i] + 1;
            }
            if(map[B[i]] == 2){
                res[i] = res[i] + 1;
            }
        }
        
        return res;
    }
};
// @lc code=end

