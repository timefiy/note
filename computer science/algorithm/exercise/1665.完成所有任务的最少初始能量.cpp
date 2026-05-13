#include <bits/stdc++.h>
using namespace std;


/*
 * @lc app=leetcode.cn id=1665 lang=cpp
 *
 * [1665] 完成所有任务的最少初始能量
 */

// @lc code=start
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // 自定义排序：按照 minimum - actual 的差值降序排序
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int res = 0;     // 需要的最少初始能量
        int current = 0; // 当前遍历过程中拥有的能量

        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            // 满足进入所需的能量
            if (current < minimum) {
                res += (minimum - current); // 需要增加的能量
                current = minimum;          // 补充后，当前能量刚好达到 minimum
            }
            
            // 消耗能量
            current -= actual;
        }

        return res;
    }
};
// @lc code=end

