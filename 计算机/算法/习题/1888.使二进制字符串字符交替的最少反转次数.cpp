# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1888 lang=cpp
 *
 * [1888] 使二进制字符串字符交替的最少反转次数
 */

// @lc code=start
class Solution {
public:
    int minFlips(string s) {
        cout << reverse(s) << endl;
        cout << reverse(de_add(s)) << endl;
        return min(reverse(s), reverse(de_add(s))); 
    }
    
    string de_add(string s){
        if (s.empty()) return "";
        return s.substr(1) + s[0];
    }

    int reverse(string s){
        int flag = s[0];
        int count = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] != flag && i%2 == 0) count++;
            else if(s[i] == flag && i%2 == 1) count++; 
        }
        return count;
    }
};

int main(){
    Solution s;
    cout << s.minFlips("1110") << endl;
}
// @lc code=end
    
