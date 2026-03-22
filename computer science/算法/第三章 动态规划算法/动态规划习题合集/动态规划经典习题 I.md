---
title: 动态规划经典习题 I
source: https://labuladong.online/zh/algo/problem-set/dynamic-programming-i/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上回溯算法算法的经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，教会读者如何套用回溯算法代码框架。支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
前置知识

阅读本文前，你需要先学习：

- [动态规划核心框架](https://labuladong.online/zh/algo/essential-technique/dynamic-programming-framework/)

本章列举一些经典的动态规划习题，帮助大家加深理解前面文章中讲到的知识点。

### 343\. 整数拆分

**343\. 整数拆分** | [力扣](https://leetcode.cn/problems/integer-break/) | [LeetCode](https://leetcode.com/problems/integer-break/)

给定一个正整数 `n`  ，将其拆分为 `k` 个 **正整数** 的和（ `k >= 2` ），并使这些整数的乘积最大化。

返回 *你可以获得的最大乘积* 。

**示例 1:**

```
输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
```

**示例 2:**

```
输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
```

**提示:**

- `2 <= n <= 58`

题目来源： [力扣 343. 整数拆分](https://leetcode.cn/problems/integer-break/) 。

#### 基本思路

关于动态规划的解题步骤和思维方法见前文 [动态规划核心套路](https://labuladong.online/zh/algo/essential-technique/dynamic-programming-framework/) 和 [动态规划答疑篇](https://labuladong.online/zh/algo/dynamic-programming/faq-summary/) ，这里就不赘述了，直接给出最关键的状态转移方程。

明白动态规划本质上是穷举这道题就简单了，比方说 `n = 4` ，我们可以把 4 拆分成 `1 + 3, 2 + 2` ，对应的乘积就是 `1 * 3, 2 * 2` 。

但此时我们直接比较 `1 * 3, 2 * 2` 的大小还不够，因为 `3, 2` 它们可能还会被分解成 `1 * 2, 1 * 1` ，也就是说把 `n = 4` 进一步分解成 `1 * (1 * 2), 2 * (1 * 1)` ，这两种可能也要纳入考虑。

到底需不需要进一步分解呢？不知道，所以我们都穷举一遍取最大值就可以了。

```
integerBreak(4)

= max(1 * 3, 1 * integerBreak(3), 2 * 2, 2 * integerBreak(2))

= max(

    1 * max(3, integerBreak(3)),

    1 * max(2, integerBreak(2))

)
```

泛化一下，状态转移方程就出来了：

```
int res = Integer.MIN_VALUE;

for (int i = 1; i <= n; i++) {

    res = max(res, i * max(integerBreak(n - i), n - i));

}
```

加个备忘录就消掉了重叠子问题，整个复杂度只有 `O(N)` ，具体看代码吧。

#### 解法代码

```
class Solution {

    vector<int> memo;

public:

    int integerBreak(int n) {

        memo = vector<int>(n + 1, 0);

        return dp(n);

    }

    // 定义：拆分 n 获得的最大乘积为 dp(n)

    int dp(int n) {

        if (n == 0) {

            return 0;

        }

        if (n == 1) {

            return 1;

        }

        if (memo[n] > 0) {

            return memo[n];

        }

        // 状态转移方程

        int res = INT_MIN;

        for (int i = 1; i <= n; i++) {

            res = max(res, i * max(dp(n - i), n - i));

        }

        memo[n] = res;

        return res;

    }

};
```

#### 算法可视化

算法可视化

### 63\. 不同路径 II

一个机器人位于一个 `m x n` 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 `1` 和 `0` 来表示。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/11/04/robot1.jpg)
```
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/11/04/robot2.jpg)
```
输入：obstacleGrid = [[0,1],[0,0]]
输出：1
```

**提示：**

- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` 为 `0` 或 `1`

题目来源： [力扣 63. 不同路径 II](https://leetcode.cn/problems/unique-paths-ii/) 。

#### 基本思路

动态规划问题层层优化的通用步骤：

1、根据 [动态规划核心套路](https://labuladong.online/zh/algo/essential-technique/dynamic-programming-framework/) ，思考如何分解问题（状态转移方程），明确函数定义，写出暴力递归解；然后用 `memo` 备忘录消除重叠子问题，并根据 [这篇文章](https://labuladong.online/zh/algo/dynamic-programming/memo-fundamental/) 确定 base case 的初始值。

2、（可选）根据 [动态规划核心套路](https://labuladong.online/zh/algo/essential-technique/dynamic-programming-framework/) 将自顶向下的递归解法改为自底向上的迭代解法，根据 [这篇文章](https://labuladong.online/zh/algo/dynamic-programming/faq-summary/) 确定 `dp` 数组的迭代方向。

3、（可选）根据 [这篇文章](https://labuladong.online/zh/algo/dynamic-programming/space-optimization/) 尝试对多维 `dp` 数组进行降维打击，优化空间复杂度。

这道题分解问题规模的关键是：

到达 `(i, j)` 的路径条数等于到达 `(i-1, j)` 和到达 `(i, j-1)` 的路径条数之和。

那么 `dp` 函数的定义就是：

从 `grid[0][0]` 出发到达 `grid[i][j]` 的路径条数为 `dp(grid, i, j)` 。

然后走流程，一步步优化，我把所有步骤都写在解法代码中了。

#### 解法代码

```
// 第一步：自顶向下带备忘录的递归

class Solution {

public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();

        int n = obstacleGrid[0].size();

        memo = vector<vector<int>>(m, vector<int>(n, -1));

        return dp(obstacleGrid, m - 1, n - 1);

    }

private:

    // 备忘录

    vector<vector<int>> memo;

    // 定义：从 grid[0][0] 出发到达 grid[i][j] 的路径条数为 dp(grid, i, j)

    int dp(vector<vector<int>>& grid, int i, int j) {

        int m = grid.size(), n = grid[0].size();

        // base case

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {

            // 数组越界或者遇到阻碍

            return 0;

        }

        if (i == 0 && j == 0) {

            // 起点到起点的路径条数就是 1

            return 1;

        }

        if (memo[i][j] != -1) {

            // 避免冗余计算

            return memo[i][j];

        }

        // 状态转移方程：

        // 到达 grid[i][j] 的路径条数等于

        // 到达 grid[i-1][j] 的路径条数加上到达 grid[i][j-1] 的路径条数

        int left = dp(grid, i, j - 1);

        int upper = dp(grid, i - 1, j);

        int res = left + upper;

        // 存储备忘录

        memo[i][j] = res;

        return res;

    }

};

// 第二步：自底向上迭代的动态规划

class Solution2 {

public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();

        int n = obstacleGrid[0].size();

        // 数组索引偏移一位，dp[0][..] dp[..][0] 代表 obstacleGrid 之外

        // 定义：到达 obstacleGrid[i][j] 的路径条数为 dp[i-1][j-1]

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // base case：如果没有障碍物，起点到起点的路径条数就是 1

        dp[1][1] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for (int i = 1; i <= m; i++) {

            for (int j = 1; j <= n; j++) {

                if (i == 1 && j == 1) {

                    // 跳过 base case

                    continue;

                }

                if (obstacleGrid[i - 1][j - 1] == 1) {

                    // 跳过障碍物的格子

                    continue;

                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

            }

        }

        // 返回到达 obstacleGrid[m-1][n-1] 的路径数量

        return dp[m][n];

    }

};

// 第三步：优化二维 dp 数组为一维 dp 数组

class Solution3 {

public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();

        int n = obstacleGrid[0].size();

        // 根据二维 dp 数组优化为一维 dp 数组

        vector<int> dp(n + 1, 0);

        dp[1] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for (int i = 1; i <= m; i++) {

            for (int j = 1; j <= n; j++) {

                if (i == 1 && j == 1) {

                    // 跳过 base case

                    continue;

                }

                if (obstacleGrid[i - 1][j - 1] == 1) {

                    // 跳过障碍物的格子

                    dp[j] = 0;

                    continue;

                }

                dp[j] = dp[j] + dp[j - 1];

            }

        }

        // 返回到达 obstacleGrid[m-1][n-1] 的路径数量

        return dp[n];

    }

};
```

#### 算法可视化

算法可视化

### 1262\. 可被三整除的最大和

**1262\. 可被三整除的最大和** | [力扣](https://leetcode.cn/problems/greatest-sum-divisible-by-three/) | [LeetCode](https://leetcode.com/problems/greatest-sum-divisible-by-three/)

给你一个整数数组 `nums` ，请你找出并返回能被三整除的元素 **最大和** 。

**示例 1：**

```
输入：nums = [3,6,5,1,8]
输出：18
解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
```

**示例 2：**

```
输入：nums = [4]
输出：0
解释：4 不能被 3 整除，所以无法选出数字，返回 0。
```

**示例 3：**

```
输入：nums = [1,2,3,4,4]
输出：12
解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
```

**提示：**

- `1 <= nums.length <= 4 * 10<sup>4</sup>`
- `1 <= nums[i] <= 10<sup>4</sup>`

题目来源： [力扣 1262. 可被三整除的最大和](https://leetcode.cn/problems/greatest-sum-divisible-by-three/) 。

#### 基本思路

看一下这道题的数据规模在 `10^4` ，所以预估时间复杂度不能超过 `n^2` ，纯暴力的回溯算法肯定不行。

我的首先感觉这个题和 [0-1 背包问题](https://labuladong.online/zh/algo/dynamic-programming/knapsack1/) 的场景有点像，但仔细想一下还不太一样。

0-1 背包问题相当于在指定容量的限制下最大化物品价值之和，而本题是只要能被 3 整除就可以，比「指定容量」的限制更宽松，所以这个题不能套用 0-1 背包问题的思路和状态转移方程。

那么来思考一下这个题应该怎么解决，本质上还是穷举嘛，每个数字 `nums[i]` 都有两种选择：要么被加到元素和中，要么不加。我们肯定都要穷举一遍，最后才能得到最大的元素和。

而且注意，题目要求「能被 3 整除」的最大元素和，也就是说要考虑余数的情况。

我们可以尝试定义这样一个 `dp` 函数，题目要什么，我们就定义什么：

```
// 定义：dp[i] 表示 nums[0..i] 中，能被 3 整除的最大元素和

int[] dp = new int[nums.length];
```

来看看这个定义是否合适，能否通过规模较小的子问题（ `dp[i-1]` ）推导出规模较大的问题（ `dp[i]` ）的解。

我知道 `nums[0..i-1]` 中能被 3 整除的最大元素和（ `dp[i-1]` ），能否推导出 `nums[0..i]` 中能被 3 整除的最大元素和（ `dp[i]` ）？答案是不能。

因为 `nums[0..i]` 中能被 3 整除的最大元素和可能由 `nums[0..i-1]` 中余数为 1 的最大元素和加上余数为 2 的 `nums[i]` 组成。你的 `dp[i-1]` 只代表了余数为 0 的最大元素和，并没有记录余数为 1 和 2 的最大元素和。

所以我们需要修改 `dp` 函数的定义，把余数的情况也记录下来：

```
// 定义：dp[i][j] 表示 nums[0..i] 中，和 3 相除余数为 j 的最大元素和

int[][] dp = new int[nums.length][3];
```

这样一来， `dp[i][j]` 就可以通过 `dp[i-1][..]` 和 `nums[i]` 推导出来了，具体看代码注释吧。

#### 解法代码

```
class Solution {

public:

    int maxSumDivThree(vector<int>& nums) {

        // 定义：nums[0..i] 中，和 3 相除余数为 j 的最大和是 dp[i][j]

        // 3 is dp[i][j]

        vector<vector<int>> dp(nums.size() + 1, vector<int>(3, INT_MIN));

        // base case

        // 如果不用数字，最大元素和就是 0

        // 余数必然是 0，不可能出现余数为 1 或 2 的情况

        dp[0][0] = 0;

        dp[0][1] = INT_MIN;

        dp[0][2] = INT_MIN;

        // 状态转移方程

        // 我们可以根据第 i 个数字余数和前 i-1 个数字的余数情况

        // 来推导出前 i 个数字的余数情况

        for (int i = 1; i <= nums.size(); i++) {

            int curNum = nums[i - 1];

            if (curNum % 3 == 0) {

                // dp[i][0] = max(dp[i - 1][0] + curNum, dp[i - 1][0]);

                // dp[i][1] = max(dp[i - 1][1] + curNum, dp[i - 1][1]);

                // dp[i][2] = max(dp[i - 1][2] + curNum, dp[i - 1][2]);

                // 可化简：

                dp[i][0] = dp[i - 1][0] + curNum;

                dp[i][1] = dp[i - 1][1] + curNum;

                dp[i][2] = dp[i - 1][2] + curNum;

            } else if (curNum % 3 == 1) {

                dp[i][0] = max(dp[i - 1][2] + curNum, dp[i - 1][0]);

                dp[i][1] = max(dp[i - 1][0] + curNum, dp[i - 1][1]);

                dp[i][2] = max(dp[i - 1][1] + curNum, dp[i - 1][2]);

            } else {

                dp[i][0] = max(dp[i - 1][1] + curNum, dp[i - 1][0]);

                dp[i][1] = max(dp[i - 1][2] + curNum, dp[i - 1][1]);

                dp[i][2] = max(dp[i - 1][0] + curNum, dp[i - 1][2]);

            }

        }

        return dp[nums.size()][0];

    }

};
```

#### 算法可视化

算法可视化

### 120\. 三角形最小路径和

**120\. 三角形最小路径和** | [力扣](https://leetcode.cn/problems/triangle/) | [LeetCode](https://leetcode.com/problems/triangle/)

给定一个三角形 `triangle` ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。 **相邻的结点** 在这里指的是 **下标** 与 **上一层结点下标** 相同或者等于 **上一层结点下标 + 1** 的两个结点。也就是说，如果正位于当前行的下标 `i` ，那么下一步可以移动到下一行的下标 `i` 或 `i + 1` 。

**示例 1：**

```
输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
```

**示例 2：**

```
输入：triangle = [[-10]]
输出：-10
```

**提示：**

- `1 <= triangle.length <= 200`
- `triangle[0].length == 1`
- `triangle[i].length == triangle[i - 1].length + 1`
- `-10<sup>4</sup> <= triangle[i][j] <= 10<sup>4</sup>`

**进阶：**

- 你可以只使用 `O(n)` 的额外空间（ `n` 为三角形的总行数）来解决这个问题吗？

题目来源： [力扣 120. 三角形最小路径和](https://leetcode.cn/problems/triangle/) 。

#### 基本思路

第 `i` 行的第 `j` 个元素从哪里来？可以从第 `i - 1` 行第 `j` 或第 `j - 1` 个元素下落过来，这就是所谓的状态转移关系：

落到 `triangle[i][j]` 的最小路径和可以通过落到 `triangle[i-1][j]` 和 `triangle[i-1][j-1]` 的最小路径和推导出来。

所以我们造一个 `dp` 数组， `dp[i][j]` 表示从 `triangle[0][0]` 走到 `triangle[i][j]` 的最小路径和。

进一步，base case 就是 `dp[0][0] = triangle[0][0]` ，我们要找的答案就是 `dp[n-1][..]` 中的最大值。

状态转移方程：

```
dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]
```

#### 解法代码

```
#include <vector>

#include <algorithm>

#include <climits>

class Solution {

public:

    int minimumTotal(std::vector<std::vector<int>>& triangle) {

        int n = triangle.size();

        // 定义：走到第 i 行第 j 个元素的最小路径和是 dp[i][j]

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX));

        // 因为求最小值，所以全都初始化为极大值

        for (int i = 0; i < n; ++i) {

            std::fill(dp[i].begin(), dp[i].end(), INT_MAX);

        }

        // base case

        dp[0][0] = triangle[0][0];

        // 进行状态转移

        for (int i = 1; i < n; i++) {

            for (int j = 0; j < triangle[i].size(); j++) {

                // 状态转移方程

                if (j - 1 >= 0) {

                    dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];

                } else {

                    dp[i][j] = dp[i - 1][j] + triangle[i][j];

                }

            }

        }

        // 找出落到最后一层的最小路径和

        int res = INT_MAX;

        for (int j = 0; j < dp[n - 1].size(); j++) {

            res = std::min(res, dp[n - 1][j]);

        }

        return res;

    }

};
```

#### 算法可视化

算法可视化

### 368\. 最大整除子集

**368\. 最大整除子集** | [力扣](https://leetcode.cn/problems/largest-divisible-subset/) | [LeetCode](https://leetcode.com/problems/largest-divisible-subset/)

给你一个由 **无重复** 正整数组成的集合 `nums` ，请你找出并返回其中最大的整除子集 `answer` ，子集中每一元素对 `(answer[i], answer[j])` 都应当满足：
- `answer[i] % answer[j] == 0` ，或
- `answer[j] % answer[i] == 0`

如果存在多个有效解子集，返回其中任何一个均可。

**示例 1：**

```
输入：nums = [1,2,3]
输出：[1,2]
解释：[1,3] 也会被视为正确答案。
```

**示例 2：**

```
输入：nums = [1,2,4,8]
输出：[1,2,4,8]
```

**提示：**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 2 * 10<sup>9</sup>`
- `nums` 中的所有整数 **互不相同**

题目来源： [力扣 368. 最大整除子集](https://leetcode.cn/problems/largest-divisible-subset/) 。

#### 基本思路

看到这道题我的第一个思路是把 [Union-Find 算法](https://labuladong.online/zh/algo/data-structure/union-find/) 的代码复制过来，把所有可以互相整除的数字放进一个连通分量，最后看看哪个连通分量里面的元素最多。不过仔细想想，比如 `[1,2,3]` 这些数字都会放到同一个连通分量里，因为都可以整除 1，但实际上 2 和 3 不能互相整除，所以这个思路是错误的。

这道题说到底就是一个穷举问题，所以我的第二个思路是复用 [一文秒杀所有排列组合子集问题](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) 中讲过的元素可重不可复选的组合问题，只要把代码复制过来稍加修改判定逻辑即可完成这道题。不过看到数据规模比较大，阶乘级别的复杂度肯定扛不住，所以也只能作罢。

再想想，在数组中寻找一个符合特定条件的子集，其实就是找一个子序列，那么如果我把数组排序，这道题就变成了 [动态规划设计：最长递增子序列](https://labuladong.online/zh/algo/dynamic-programming/longest-increasing-subsequence/) 。

排序很重要，假设一个符合题目要求的子集 `[1,2,4]` ，那么由于我排了序，如果想扩充这个集合，接下来我只要到一个能够整除 4 的数就行了，比如 8。我不用考虑前面的数字了，因为只要能整除最大的 4 就一定能整除别的。

这样一来，题目就变成了： **寻找一个最长递增子序列，且要求每个元素都能够整除前面那个元素** 。

然后按照 [动态规划设计：最长递增子序列](https://labuladong.online/zh/algo/dynamic-programming/longest-increasing-subsequence/) 中定义 `dp` 数组的方式，用 `dp[i]` 记录以 `nums[i]` 结尾的最长递增子序列，就能解决这道题了。

#### 解法代码

```
#include <vector>

#include <algorithm>

using namespace std;

class Solution {

public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        // 定义：dp[i] 表示以 nums[i] 这个数结尾的最长符合要求子序列的长度

        vector<vector<int>> dp(n);

        

        // base case

        dp[0].push_back(nums[0]);

        for (int i = 1; i < n; i++) {

            int maxSubsetLen = 0, index = -1;

            // 在 nums[0..i-1] 中寻找那个 nums[i] 能接到结尾的最长子序列

            for (int j = 0; j < i; j++) {

                if (nums[i] % nums[j] == 0 && dp[j].size() > maxSubsetLen) {

                    maxSubsetLen = dp[j].size();

                    index = j;

                }

            }

            // nums[0..i-1] 中最长的那个子序列，再加上 nums[i]，

            // 就是 nums[0..i] 最长的子序列

            if (index != -1) {

                dp[i] = dp[index]; // Copy the longest valid subsequence found so far

                dp[i].push_back(nums[i]); // Append the current number to it

            } else {

                dp[i].clear(); // No valid subsequence was found, start a new one

                dp[i].push_back(nums[i]);

            }

        }

        // Find the longest subset

        vector<int> res;

        for (const auto& subset : dp) {

            if (subset.size() > res.size()) {

                res = subset;

            }

        }

        return res;

    }

};
```

#### 算法可视化

算法可视化

### 718\. 最长重复子数组

**718\. 最长重复子数组** | [力扣](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/) | [LeetCode](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

给两个整数数组 `nums1`  和  `nums2` ，返回 *两个数组中 **公共的** 、长度最长的子数组的长度* 。

**示例 1：**

```
输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。
```

**示例 2：**

```
输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
```

**提示：**

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 100`

题目来源： [力扣 718. 最长重复子数组](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/) 。

#### 基本思路

算法的本质是穷举，先写一个暴力解做到无遗漏地穷举，然后仔细观察，充分利用信息，就能消除冗余计算得到最优解。

这道题的解法比较多，我们就探讨最容易想到的解法。首先，肯定要写出暴力解：

```
// 暴力穷举

int findLength(int[] nums1, int[] nums2) {

    int maxLen = 0;

    for (int i = 0; i < nums1.length; i++) {

        for (int j = 0; j < nums2.length; j++) {

            // 以 nums1[i] 和 nums2[j] 为起点，计算最长重复子数组

            // 即计算 nums1[i..] 和 nums2[j..] 的最长公共前缀

            int len = 0;

            while (i + len < nums1.length && j + len < nums2.length 

                    && nums1[i + len] == nums2[j + len]) {

                len++;

            }

            maxLen = Math.max(maxLen, len);

        }

    }

    return maxLen;

}
```

时间复杂度是 `O(N^3)` ，空间复杂度是 `O(1)` 。

接下来看看如何优化。

**大家可以记住，只要遇到公共前缀/后缀这类问题，大概率有冗余计算，要往动态规划的思路上靠** 。

就比方这道题，我们抽出暴力解的关键代码：

```
for (int i = 0; i < nums1.length; i++) {

    for (int j = 0; j < nums2.length; j++) {

        // 计算 nums1[i..] 和 nums2[j..] 的最长公共前缀

        for (int len = 0; i + len < nums1.length && j + len < nums2.length 

                && nums1[i + len] == nums2[j + len]; len++) {

            

        }

    }

}
```

最内层的 for 循环可以用空间换时间的思路优化掉。比方说我创建一个 `dp` 数组：

```
// 定义：dp[i][j] 表示 nums1[i..] 和 nums2[j..] 的最长公共前缀

int[][] dp = new int[nums1.length][nums2.length];
```

按照定义，我就可以这样根据 `nums1[i+1..]` 和 `nums2[j+1..]` 的公共前缀推算 `nums1[i..]` 和 `nums2[j..]` 的最长公共前缀：

```
if (nums1[i] == nums2[j]) {

    dp[i][j] = dp[i+1][j+1] + 1;

} else {

    dp[i][j] = 0;

}
```

但是计算 `dp[i][j]` 需要确保 `dp[i+1][j+1]` 已经被计算出来，所以我们可以让 `i, j` 从后往前遍历。

这样就得到了这道题的动态规划递推解法，具体看代码吧。

#### 解法代码

```
class Solution {

public:

    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size(), n = nums2.size();

        // 定义：dp[i][j] 表示 nums1[i..] 和 nums2[j..] 的最长公共前缀

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base case

        // 因为我们是从下往上，从右往左遍历

        // 所以最后一行和最后一列的 base case 需要先算出来

        for (int j = 0; j < n; j++) {

            dp[m - 1][j] = nums1[m - 1] == nums2[j] ? 1 : 0;

        }

        for (int i = 0; i < m; i++) {

            dp[i][n - 1] = nums1[i] == nums2[n - 1] ? 1 : 0;

        }

        // 从后往前遍历

        for (int i = m - 2; i >= 0; i--) {

            for (int j = n - 2; j >= 0; j--) {

                if (nums1[i] == nums2[j]) {

                    dp[i][j] = dp[i+1][j+1] + 1;

                }

            }

        }

        // 找出 dp 数组中的最大值

        int maxLen = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                maxLen = max(maxLen, dp[i][j]);

            }

        }

        return maxLen;

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论(4)

Markdown

Ctrl+Enter 发表

![林鑫](https://thirdwx.qlogo.cn/mmopen/vi_32/rA0WhG4e8cyJ8pHnLpoxYq9rLRbcuwpKj0JfGlu5caIxXwZUcibqvJGlMrR5cR8UcoHMzdAwDGNDlcXSXCUTjIw/132)

林鑫 大约 1 个月前

343 可有这样的一个思路： 对于和固定的乘法，因数越接近积就越大。 矩形里，周长相同的情况下正方形面积最大， 立方体，边长和固定时，正立方体体积最大

```
class Solution {

public:

    int integerBreak(int n) {

        int maxVal = 0;

        for (int k = 2; k<=n;k++) {

            //算出平均值

            int avg = n/k;

            //算出多出了几个1

            int dif = n-avg*k;

            int sum = 1;

            for (int i = 1;i<=k;i++) {

                if (dif == 0) {

                    sum *= avg;

                } else {

                    //对于多出的1尽量平均的分配

                    sum *= avg+1;

                    dif --;

                }

            }

            maxVal = max(maxVal, sum);

        }

        return maxVal;

    }

};
```

![Nuclear](https://thirdwx.qlogo.cn/mmopen/vi_32/P5ykAXrq65ibziaOQz2uvKIopBPvzy7zsL0WGvpVq6FeMDIhqEHib4JymyB0h7vuwDV9SJkGx0ibXrTfo25DMCGBuA/132)

Nuclear 8 个月前

718 也可以定义从\[0..i\]和\[0..j\]的最长前缀

```
public int findLength(int[] nums1, int[] nums2) {

        int len1 = nums1.length;

        int len2 = nums2.length;

        int[][] dp = new int[len1+1][len2+1];

        int max = 0;

        for (int i=1; i<=len1; i++) {

            for (int j=1; j<=len2; j++) {

                if (nums1[i-1] == nums2[j-1]) {

                    dp[i][j] = dp[i-1][j-1] + 1;

                }

                max = Math.max(max, dp[i][j]);

            }

        }

        return max;

    }
```

![刍荛](https://thirdwx.qlogo.cn/mmopen/vi_32/DYAIOgq83erL9GjLfCmHsia6gD1oEhDwKdJMUJEz8C19EXWqWGPYvujRV7OfV2KCROCvTJJg3icFkWqugCfIDGSsUsdn6KL2V1RKgEx6zfYq48GeibMBA9ntg/132)

刍荛 7 个月前

120的从底向上解：

```
class Solution:

    def minimumTotal(self, triangle: List[List[int]]) -> int:

        m = len(triangle)

        n = len(triangle[-1])

        dp = [[0] * (n+1) for _ in range(m+1) ]

        # base case

        for i in range(n):

            dp[m-1][i] = triangle[m-1][i]

        # m-1 是limit

        for i in range( m-1 ,-1, -1):

            # 第i行有i+1个元素

            for j in range(i+1):

                dp[i][j] = min(dp[i+1][j] , dp[i+1][j+1]) + triangle[i][j]

        return dp[0][0]
```

![TP](https://thirdwx.qlogo.cn/mmopen/vi_32/PiajxSqBRaEKdg7srDC36Sw5S9VbdCuAySel10ISTQ6ZKmXiccJAOa4W90gXPb6Fqja7bJEXicL1piaicgLIcwOiaWehAVPSf6tc5ql5XWh6Nxmm3nmI3xUy0CMA/132)

TP 8 个月前

整数拆分 343. 时间复杂度 = n(n+1)/2 ≈ O(n²)