#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1536 lang=cpp
 *
 * [1536] 排布二进制网格的最少交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int swaps = 0;
        
        for(int i = 0; i < n; i++){
            if(!checkrow(grid[i], i)){
                int j = findrow(grid, i);
                if(j == -1) return -1;
                
                for(int k = j; k > i; k--){
                    swap(grid[k], grid[k-1]);
                    swaps++;
                }
            }
        }
        return swaps;
    }

    bool checkrow(vector<int>& row, int n){
        for (int i = n + 1; i < row.size(); i++)
        {
            if(row[i] == 1) return false;
        }
        return true;
    }

    int findrow(vector<vector<int>>& grid, int n){
        for (int i = n + 1; i < grid.size(); i++)
        {
            if(checkrow(grid[i], n)){
                return i; 
            }
        }
        return -1;
    }

};
// @lc code=end

int main(){
    vector<vector<int>> grid = {{0,0,1},{1,1,0},{1,0,0}};
    Solution s;
    cout << s.minSwaps(grid) << endl;
    return 0;
}
