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
                if(check(cnt)){
                    ans = max(ans, i - j);
                }
            }
        } 
        return ans;
    }

    bool check(int cnt[]){
        int standard = -1; 
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 0) {
                if (standard == -1) {
                    standard = cnt[i]; 
                } else if (cnt[i] != standard) {
                    return false; 
                }
            }
        }
        return standard != -1;
    }
};
// @lc code=end

int main(){
    Solution s;
    string str = "aabbcc";
    cout << s.longestBalanced(str) << endl;
    return 0;
}