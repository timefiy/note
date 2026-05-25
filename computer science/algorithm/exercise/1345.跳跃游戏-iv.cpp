#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */

// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0; 

        unordered_map<int, vector<int>> idxMap;
        for (int i = 0; i < n; i++) {
            idxMap[arr[i]].push_back(i);
        }

        vector<int> step_count(n, -1);
        step_count[0] = 0; 

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n - 1) {
                return step_count[curr];
            }

            if (idxMap.count(arr[curr])) {
                for (int next : idxMap[arr[curr]]) {
                    if (step_count[next] == -1) {
                        step_count[next] = step_count[curr] + 1;
                        q.push(next);
                    }
                }
                idxMap.erase(arr[curr]);
            }

            int next_right = curr + 1;
            if (next_right < n && step_count[next_right] == -1) {
                step_count[next_right] = step_count[curr] + 1;
                q.push(next_right);
            }

            int next_left = curr - 1;
            if (next_left >= 0 && step_count[next_left] == -1) {
                step_count[next_left] = step_count[curr] + 1;
                q.push(next_left);
            }
        }

        return -1;
    }
};
// @lc code=end

