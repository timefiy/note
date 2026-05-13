#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1674 lang=cpp
 *
 * [1674] 使数组互补的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // 创建差分数组。因为目标和 X 的最大值是 2 * limit，
        // 且差分数组经常需要操作右边界 + 1（即 2 * limit + 1），
        // 所以数组大小开到 2 * limit + 2 即可防止越界。
        vector<int> diff(2 * limit + 2, 0);
        
        // 遍历数组的前一半，每次取出一对对称的数字 A 和 B
        for (int i = 0; i < n / 2; ++i) {
            int A = nums[i];
            int B = nums[n - 1 - i];
            
            // 为了方便确定边界，先找出这对数字中的较小值和较大值
            int min_val = min(A, B);
            int max_val = max(A, B);
            
            // 1. 默认情况：所有合法的目标和 X (2 到 2 * limit) 都需要 2 次操作
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;
            
            // 2. 只需要 1 次操作的区间：[min_val + 1, max_val + limit]
            // 在这个区间内，操作次数比默认的 2 次少 1 次，所以减去 1
            diff[min_val + 1] -= 1;
            diff[max_val + limit + 1] += 1;
            
            // 3. 只需要 0 次操作的点：A + B
            // 在这个点上，操作次数比刚才的 1 次操作又少 1 次，所以再减去 1
            diff[A + B] -= 1;
            diff[A + B + 1] += 1;
        }
        
        int min_moves = n; // 记录最少需要的总操作次数，最大不可能超过 n 次
        int current_moves = 0; // 记录当前目标和 X 所需的总操作次数（即前缀和）
        
        // 遍历所有可能的目标和 X (从 2 到 2 * limit)
        for (int X = 2; X <= 2 * limit; ++X) {
            // 计算差分数组的前缀和，得到当前 X 对应的实际操作总数
            current_moves += diff[X];
            
            // 更新最小值
            min_moves = min(min_moves, current_moves);
        }
        
        return min_moves;
    }
};
// @lc code=end

