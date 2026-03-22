# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1878 lang=cpp
 *
 * [1878] 矩阵中最大的三个菱形和
 */

// @lc code=start
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int Edge = (min(n, m) + 1) / 2;
        set<int> s;

        for (int edge = 1; edge <= Edge; edge++)
        {
            // 偏移量
            int l = edge - 1;
            for (int i = l; i < n - l; i++)
            {
                for (int j = l; j < m - l; j++)
                {
                    // [i][j] 为菱形中心
                    int sum = 0;
                    if(l == 0) sum = grid[i][j];
                    else {
                        // 1. 先单独加上四个角的顶点（避免重复）
                        sum += grid[i - l][j]; // 上顶点
                        sum += grid[i + l][j]; // 下顶点
                        sum += grid[i][j - l]; // 左顶点
                        sum += grid[i][j + l]; // 右顶点
                        
                        // 2. 遍历四条边中间的格子，k 从 1 开始，到 l-1 结束
                        for (int k = 1; k < l; k++)
                        {
                            sum += grid[i - l + k][j + k]; // 右上边
                            sum += grid[i + l - k][j + k]; // 右下边
                            sum += grid[i + l - k][j - k]; // 左下边
                            sum += grid[i - l + k][j - k]; // 左上边
                        }
                    }
                    s.insert(sum);
                    if (s.size() > 3)
                    {
                        s.erase(s.begin());
                    }
                }
            }
        }
        return vector<int>(s.rbegin(), s.rend());
    }
};
// @lc code=end

