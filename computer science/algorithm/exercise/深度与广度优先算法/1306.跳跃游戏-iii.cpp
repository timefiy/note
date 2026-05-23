#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 *
 * [1306] 跳跃游戏 III
 */

// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return jump(arr, start, visited);
    }

    bool jump(vector<int>& arr, int i, vector<bool>& visited) {
        if (i < 0 || i >= arr.size()) {
            return false;
        }
        
        if (visited[i]) {
            return false;
        }
        
        if (arr[i] == 0) {
            return true;
        }

        visited[i] = true;

        return jump(arr, i + arr[i], visited) || jump(arr, i - arr[i], visited);
    }
};
// @lc code=end

