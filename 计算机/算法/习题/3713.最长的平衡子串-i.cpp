# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3713 lang=cpp
 *
 * [3713] 最长的平衡子串 I
 */

// @lc code=start
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            
            for (int j = 0; j < i; j++)
            {   
                int cnt[26] = {0};
                for (int k = j; k < i; k++)
                {
                    cnt[s[k] - 'a']++;
                }

            }
            
        } 
    }

    bool check(int cnt[]){
        int flag = cnt[0];
        for (int i = 1; i < 26; i++)
        {
            if(cnt[i] != flag){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

