# include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 */

// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1){
                    if (check(mat, i, j))
                        ans++;
                }
            }
        }
        return ans;
    }

    bool check(vector<vector<int>>& mat, int x, int y){
        for (int i = 0; i < mat.size(); i++)
        {
            if (i != x && mat[i][y] == 1)
                return false;
        }
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (j != y && mat[x][j] == 1)
                return false;
        }
        return true;
    }
};
// @lc code=end

