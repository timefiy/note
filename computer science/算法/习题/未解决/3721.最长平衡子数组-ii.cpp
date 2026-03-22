#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=3721 lang=cpp
 *
 * [3721] 最长平衡子数组 II
 */

// @lc code=start
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        vector<int> tavernilo = nums; 
        int ans = 0;
        int n = tavernilo.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> evenSet;
            unordered_set<int> oddSet;

            for (int j = i; j < n; j++) {
                if (tavernilo[j] % 2 == 0) {
                    evenSet.insert(tavernilo[j]);
                } else {
                    oddSet.insert(tavernilo[j]);
                }

                if (evenSet.size() == oddSet.size()) {
                    if (evenSet.size() > 0) {
                        ans = max(ans, (int)(j - i + 1));
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

