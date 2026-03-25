# include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3546 lang=cpp
 *
 * [3546] 等和矩阵分割 I
 */

// @lc code=start
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowSum(m), colSum(n);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        long long total = 0;
        for (int i = 0; i < m; i++)
        {
            total += rowSum[i];
        }
        if (total % 2 != 0)
        {
            return false;
        }
        
        long long a = total / 2;

        long long sum = 0;
        if(m!= 1){
            for (int i = 0; i < m; i++)
            {
                sum += rowSum[i];
                if (sum == a)
                {
                    return true;
                }
            }
        }
        

        sum = 0;
        if(n != 1){
            for (int j = 0; j < n; j++)
            {
                sum += colSum[j];
                if (sum == a)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
// @lc code=end

