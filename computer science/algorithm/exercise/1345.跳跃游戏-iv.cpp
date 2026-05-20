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

        // 3. BFS 队列，现在只需要存储当前下标即可
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // 如果到达了终点，直接返回记录在数组中的最少步数
            if (curr == n - 1) {
                return step_count[curr];
            }

            // --- 寻找下一个可以跳跃的位置 ---

            // 情况一：跳到相同元素 j (arr[curr] == arr[j])
            if (idxMap.count(arr[curr])) {
                for (int next : idxMap[arr[curr]]) {
                    // 判断是否访问过的条件变成了：step_count 是否为 -1
                    if (step_count[next] == -1) {
                        step_count[next] = step_count[curr] + 1; // 步数 = 当前步数 + 1
                        q.push(next);
                    }
                }
                // 核心优化：跳跃过该等值群组后，将其从哈希表中删除，避免重复遍历防超时
                idxMap.erase(arr[curr]);
            }

            // 情况二：向后跳一步 (curr + 1)
            int next_right = curr + 1;
            if (next_right < n && step_count[next_right] == -1) {
                step_count[next_right] = step_count[curr] + 1;
                q.push(next_right);
            }

            // 情况三：向前跳一步 (curr - 1)
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

