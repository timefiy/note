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
        vector<int> res(A.size(), 0);

        for (int i = 0; i < A.size(); i++)
        {
            // 1. 继承前一个位置的公共元素数量
            if (i > 0) {
                res[i] = res[i - 1];
            }

            // 2. 处理 A[i]
            map[A[i]]++;
            if (map[A[i]] == 2) {
                res[i]++;
            }

            // 3. 处理 B[i] —— 独立处理，如果 A[i]==B[i]，此时 map 变 2 会在这里触发一次，绝不重复
            map[B[i]]++;
            if (map[B[i]] == 2) {
                res[i]++;
            }
        }
        
        return res;
    }
};
// @lc code=end

