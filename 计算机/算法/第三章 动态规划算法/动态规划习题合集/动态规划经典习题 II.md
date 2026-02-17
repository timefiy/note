---
title: 动态规划经典习题 II
source: https://labuladong.online/zh/algo/problem-set/dynamic-programming-ii/
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

### 97\. 交错字符串

**97\. 交错字符串** | [力扣](https://leetcode.cn/problems/interleaving-string/) | [LeetCode](https://leetcode.com/problems/interleaving-string/)

给定三个字符串 `s1` 、 `s2` 、 `s3` ，请你帮忙验证  `s3`  是否是由  `s1`  和  `s2` **交错** 组成的。

两个字符串 `s` 和 `t` **交错** 的定义与过程如下，其中每个字符串都会被分割成若干 **非空** 子字符串 ：

- `s = s<sub>1</sub> + s<sub>2</sub> + ... + s<sub>n</sub>`
- `t = t<sub>1</sub> + t<sub>2</sub> + ... + t<sub>m</sub>`
- `|n - m| <= 1`
- **交错** 是 `s<sub>1</sub> + t<sub>1</sub> + s<sub>2</sub> + t<sub>2</sub> + s<sub>3</sub> + t<sub>3</sub> + ...` 或者 `t<sub>1</sub> + s<sub>1</sub> + t<sub>2</sub> + s<sub>2</sub> + t<sub>3</sub> + s<sub>3</sub> + ...`

**注意：** `a + b` 意味着字符串 `a` 和 `b` 连接。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/09/02/interleave.jpg)
```
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
```

**示例 2：**

```
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false
```

**示例 3：**

```
输入：s1 = "", s2 = "", s3 = ""
输出：true
```

**提示：**

- `0 <= s1.length, s2.length <= 100`
- `0 <= s3.length <= 200`
- `s1` 、 `s2` 、和 `s3` 都由小写英文字母组成

**进阶：** 您能否仅使用 `O(s2.length)` 额外的内存空间来解决它?

题目来源： [力扣 97. 交错字符串](https://leetcode.cn/problems/interleaving-string/) 。

#### 基本思路

如果你看过前文 [单链表六大解题套路](https://labuladong.online/zh/algo/essential-technique/linked-list-skills-summary/) 中讲解的 [21\. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/description/) 就会发现，题目巴拉巴拉说了一大堆， **实则就是一个使用双指针技巧合并两个字符串的过程** 。

双指针的大致逻辑如下：

```
int i = 0, j = 0;

for (int k = 0; k < s3.length; k++) {

    if (s1[i] == s3[k]) {

        i++;

    } else if (s2[j] == s3[k]) {

        j++;

    }

}

assert i == s1.length() && j == s2.length();
```

但本题跟普通的数组/链表双指针技巧不同的是，这里需要穷举所有情况。比如 `s1[i], s2[j]` 都能匹配 `s3[k]` 的时候，到底应该让谁来匹配，才能完全合并出 `s3` 呢？

回答这个问题很简单，我不知道让谁来，那就都来试一遍好了，前文 [经典动态规划：最长公共子序列](https://labuladong.online/zh/algo/dynamic-programming/longest-common-subsequence/) 和 [经典动态规划：编辑距离](https://labuladong.online/zh/algo/dynamic-programming/edit-distance/) 都处理过类似的情况。

所以本题肯定需要一个递归函数来穷举双指针的匹配过程，然后用一个备忘录消除递归过程中的重叠子问题，也就能写出自顶向下的递归的动态规划解法了。

#### 解法代码

```
class Solution {

public:

    bool isInterleave(string s1, string s2, string s3) {

        int m = s1.length(), n = s2.length();

        // 如果长度对不上，必然不可能

        if (m + n != s3.length()) {

            return false;

        }

        // 备忘录，其中 -1 代表未计算，0 代表 false，1 代表 true

        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));

        return dp(s1, 0, s2, 0, s3);

    }

private:

    vector<vector<int>> memo;

    // 定义：计算 s1[i..] 和 s2[j..] 是否能组合出 s3[i+j..]

    bool dp(const string& s1, int i, const string& s2, int j, const string& s3) {

        int k = i + j;

        // base case，s3 构造完成

        if (k == s3.length()) {

            return true;

        }

        // 查备忘录，如果已经计算过，直接返回

        if (memo[i][j] != -1) {

            return memo[i][j] == 1;

        }

        bool res = false;

        // 如果，s1[i] 可以匹配 s3[k]，那么填入 s1[i] 试一下

        if (i < s1.length() && s1[i] == s3[k]) {

            res = dp(s1, i + 1, s2, j, s3);

        }

        // 如果，s1[i] 匹配不了，s2[j] 可以匹配，那么填入 s2[j] 试一下

        if (j < s2.length() && s2[j] == s3[k]) {

            res = res || dp(s1, i, s2, j + 1, s3);

        }

        // 如果 s1[i] 和 s2[j] 都匹配不了，则返回 false

        // 将结果存入备忘录

        memo[i][j] = res ? 1 : 0;

        return res;

    }

};
```

#### 算法可视化

算法可视化

### 152\. 乘积最大子数组

**152\. 乘积最大子数组** | [力扣](https://leetcode.cn/problems/maximum-product-subarray/) | [LeetCode](https://leetcode.com/problems/maximum-product-subarray/)

给你一个整数数组 `nums` ，请你找出数组中乘积最大的非空连续 子数组 （该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 **32-位** 整数。

**示例 1:**

```
输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
```

**示例 2:**

```
输入: nums = [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
```

**提示:**

- `1 <= nums.length <= 2 * 10<sup>4</sup>`
- `-10 <= nums[i] <= 10`
- `nums` 的任何前缀或后缀的乘积都 **保证** 是一个 **32-位** 整数

题目来源： [力扣 152. 乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray/) 。

#### 基本思路

这道题和 [53\. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/description/) 有点像，那道题定义的 `dp` 数组是： `dp[i]` 记录以 `nums[i]` 为结尾的「最大子数组和」，从而写出状态转移方程。

这道题可以采用类似的思路，但需要注意的是，在 53 题中， **子数组 `nums[0..i]` 的最大元素和是由 `nums[0..i-1]` 的最大元素和推导出的** ，但本题变成子数组的乘积则不一定。

比如 `nums[i] = -1` ， `nums[0..i-1]` 子数组的 **最大** 元素乘积为 10，那么我能不能说 `nums[0..i]` 的最大元素乘积为 `max(-1, -1 * 10) = -1` 呢？

其实不行，因为可能 `nums[0..i-1]` 子数组的 **最小** 元素乘积为 -6，那么 `nums[0..i]` 的最大元素乘积应该为 max(-1, -1 \* 10, -1 \* -6) = 6\`。

所以这道题和 53 题的最大区别在于，要同时维护「以 `nums[i]` 结尾的最大子数组」和「以 `nums[i]` 结尾的最小子数组」，以便适配 `nums[i]` 可能为负的情况。

#### 解法代码

```
class Solution {

public:

    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        // 定义：以 nums[i] 结尾的子数组，乘积最小为 dp1[i]

        vector<int> dp1(n);

        // 定义：以 nums[i] 结尾的子数组，乘积最大为 dp2[i]

        vector<int> dp2(n);

        // base case

        dp1[0] = nums[0];

        dp2[0] = nums[0];

        // 状态转移方程

        for (int i = 1; i < n; i++) {

            dp1[i] = min(dp1[i - 1] * nums[i], dp2[i - 1] * nums[i], nums[i]);

            dp2[i] = max(dp1[i - 1] * nums[i], dp2[i - 1] * nums[i], nums[i]);

        }

        // 遍历所有子数组的最大乘积，求最大值

        int res = INT_MIN;

        for (int i = 0; i < n; i++) {

            res = std::max(res, dp2[i]);

        }

        return res;

    }

    int min(int a, int b, int c) {

        return std::min(std::min(a, b), c);

    }

    int max(int a, int b, int c) {

        return std::max(std::max(a, b), c);

    }

};
```

#### 算法可视化

算法可视化

### 221\. 最大正方形

**221\. 最大正方形** | [力扣](https://leetcode.cn/problems/maximal-square/) | [LeetCode](https://leetcode.com/problems/maximal-square/)

在一个由 `'0'` 和 `'1'` 组成的二维矩阵内，找到只包含 `'1'` 的最大正方形，并返回其面积。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/11/26/max1grid.jpg)
```
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：4
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/11/26/max2grid.jpg)
```
输入：matrix = [["0","1"],["1","0"]]
输出：1
```

**示例 3：**

```
输入：matrix = [["0"]]
输出：0
```

**提示：**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 300`
- `matrix[i][j]` 为 `'0'` 或 `'1'`

题目来源： [力扣 221. 最大正方形](https://leetcode.cn/problems/maximal-square/) 。

#### 基本思路

关于动态规划的解题步骤和思维方法见前文 [动态规划核心套路](https://labuladong.online/zh/algo/essential-technique/dynamic-programming-framework/) 和 [动态规划答疑篇](https://labuladong.online/zh/algo/dynamic-programming/faq-summary/) ，这里就不赘述了，直接给出最关键的状态转移方程。

这道题不难，关键是你要观察出一个全是 1 的正方形有什么特点，如何根据小的正方形推导出大的正方形（状态转移方程）。

当 `matrix[i][j]` 为 1，且它的左边、上边、左上边都存在正方形时， `matrix[i][j]` 才能够作为一个更大的正方形的右下角：

![](https://labuladong.online/images/algo/brief-extra/221.jpg)

PS：这个图是我基于测试用例修改的，你明白我的意思就行。

所以我们可以定义这样一个二维 `dp` 数组：

以 `matrix[i][j]` 为右下角元素的最大的全为 1 正方形矩阵的边长为 `dp[i][j]` 。

有了这个定义，状态转移方程就是：

```
if (matrix[i][j] == 1)

    // 类似「水桶效应」，最大边长取决于边长最短的那个正方形

    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;

else

    dp[i][j] = 0;
```

题目最终想要的答案就是最大边长 `max(dp[..][..])` 的平方。

#### 解法代码

```
class Solution {

public:

    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();

        // 定义：以 matrix[i][j] 为右下角元素的全为 1 正方形矩阵的最大边长为 dp[i][j]。

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base case，第一行和第一列的正方形边长

        for (int i = 0; i < m; i++) {

            dp[i][0] = matrix[i][0] - '0';

        }

        for (int j = 0; j < n; j++) {

            dp[0][j] = matrix[0][j] - '0';

        }

        // 进行状态转移

        for (int i = 1; i < m; i++) {

            for (int j = 1; j < n; j++) {

                if (matrix[i][j] == '0') {

                    // 值为 0 不可能是正方形的右下角

                    continue;

                }

                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;

            }

        }

        int len = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                len = max(len, dp[i][j]);

            }

        }

        return len * len;

    }

};
```

#### 算法可视化

算法可视化

### 329\. 矩阵中的最长递增路径

**329\. 矩阵中的最长递增路径** | [力扣](https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/) | [LeetCode](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)

给定一个 `m x n` 整数矩阵  `matrix` ，找出其中 **最长递增路径** 的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你 **不能** 在 **对角线** 方向上移动或移动到 **边界外** （即不允许环绕）。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2021/01/05/grid1.jpg)
```
输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
输出：4 
解释：最长递增路径为 [1, 2, 6, 9]。
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2021/01/27/tmp-grid.jpg)
```
输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
输出：4 
解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
```

**示例 3：**

```
输入：matrix = [[1]]
输出：1
```

**提示：**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 200`
- `0 <= matrix[i][j] <= 2<sup>31</sup> - 1`

题目来源： [力扣 329. 矩阵中的最长递增路径](https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/) 。

#### 基本思路

最短路径你可以用 [BFS 算法](https://labuladong.online/zh/algo/essential-technique/bfs-framework/) ，再复杂一点可以用我们在图论讲的 [Dijkstra 算法](https://labuladong.online/zh/algo/data-structure/dijkstra/) （本质上是一种加强的 BFS 算法）。

但是最长路径和最短路径就是完全不同的两个问题。聪明的读者肯定想耍小聪明，把路径权重变成相反数，是不是就能用最短路径算法去求最长路径了？不能。

关键区别在于，最短路径是贪心，每次选择权重和最小的路径，第一个到终点的路径就是最短的。但你最长路径不一样，第一次到达终点时不一定是最长的，因为最长的那条路径可能还在兜圈子，还没走完呢。

所以对于这种最长路径问题，一般就是最简单直接的暴力穷举。以每个点为起点进行穷举，把所有符合条件的路径都穷举出来，最后找出最长的路径。

但是注意，穷举过程中可能出现重叠子问题，比如说我们已经算出来以 `(i, j)` 为起点的最长递增路径长度为 4，那么下次再以 `(i, j)` 为起点的时候，就不用再重复计算了，直接用 4 就行了。

综上，我们可以定义一个 `dp(i, j)` 函数，计算以 `matrix[i][j]` 为起点的最长递增路径长度，然后再加一个 `memo` 备忘录，构成动态规划解法。具体看代码吧

#### 解法代码

```
class Solution {

public:

    // 备忘录，避免重复计算，初始化为 0

    // 定义：memo[i][j] 表示从 (i, j) 出发的最长递增路径长度

    vector<vector<int>> memo;

    // 方向数组，方便遍历上下左右四个相邻格子

    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();

        memo = vector<vector<int>>(m, vector<int>(n, 0));

        int res = 0;

        // 以每个点为起点进行搜索

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                res = max(res, dp(matrix, i, j));

            }

        }

        return res;

    }

    // 定义：函数返回以 matrix[i][j] 为起点的最长递增路径长度

    int dp(vector<vector<int>>& matrix, int i, int j) {

        if (memo[i][j] != 0) {

            // 如果已经计算过，直接返回

            return memo[i][j];

        }

        int m = matrix.size(), n = matrix[0].size();

        // 递增路径长度至少为 1，即自身

        int res = 1;

        for (auto& dir : dirs) {

            int x = i + dir[0], y = j + dir[1];

            // 如果越界，跳过

            if (x < 0 || x >= m || y < 0 || y >= n) {

                continue;

            }

            // 如果递增，继续穷举（状态转移）

            // 从 (i, j) 出发的最长递增路径 = max(从四个相邻位置出发的最长递增路径的最大值 + 1)

            if (matrix[x][y] > matrix[i][j]) {

                res = max(res, dp(matrix, x, y) + 1);

            }

        }

        // 记录备忘录

        memo[i][j] = res;

        return res;

    }

};
```

#### 算法可视化

算法可视化

### 1235\. 规划兼职工作

**1235\. 规划兼职工作** | [力扣](https://leetcode.cn/problems/maximum-profit-in-job-scheduling/) | [LeetCode](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)

你打算利用空闲时间来做兼职工作赚些零花钱。

这里有 `n`  份兼职工作，每份工作预计从  `startTime[i]` 开始到 `endTime[i]` 结束，报酬为 `profit[i]` 。

给你一份兼职工作表，包含开始时间 `startTime` ，结束时间  `endTime`  和预计报酬  `profit` 三个数组，请你计算并返回可以获得的最大报酬。

注意，时间上出现重叠的 2 份工作不能同时进行。

如果你选择的工作在时间 `X`  结束，那么你可以立刻进行在时间  `X` 开始的下一份工作。

**示例 1：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/10/19/sample1_1584.png)**

```
输入：startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
输出：120
解释：
我们选出第 1 份和第 4 份工作， 
时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。
```

**示例 2：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/10/19/sample22_1584.png)**

```
输入：startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
输出：150
解释：
我们选择第 1，4，5 份工作。 
共获得报酬 150 = 20 + 70 + 60。
```

**示例 3：**

**![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2019/10/19/sample3_1584.png)**

```
输入：startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
输出：6
```

**提示：**

- `1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4`
- `1 <= startTime[i] < endTime[i] <= 10^9`
- `1 <= profit[i] <= 10^4`

题目来源： [力扣 1235. 规划兼职工作](https://leetcode.cn/problems/maximum-profit-in-job-scheduling/) 。

#### 基本思路

这题的难度是 hard，但其实就是 [0-1 背包问题](https://labuladong.online/zh/algo/dynamic-programming/knapsack1/) 的变种，用 TreeMap 这种自动排序的数据结构来辅助一下，就能解决了。

对于区间问题，大部分情况都要排序，因为排序后方便你比较两个区间是否重叠。对起点或者终点排序都是一样的，我给出的解法是按照终点排序的，你非要对起点排序的话，把 `dp` 数组的定义也反过来就行了。

我按照终点排序之后，就可以套用背包问题的思路了。 `dp[i]` 的定义是：

在 `0` 到 `i` 这个时间区间内，最多能够获得的利润是 `dp[i]` 。

然后对于每个工作，他都有两个选择：选或者不选，和背包问题一样，这样状态转移就出来了。

具体的看代码吧，尤其注意 TreeMap 的使用，用来查询在某个时间点之前的最大利润。有些语言没有内置 TreeMap 这种类型，可以自己手搓 [二分查找](https://labuladong.online/zh/algo/essential-technique/binary-search-framework/) 来做，一样的。

#### 解法代码

```
class Solution {

public:

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = profit.size();

        vector<vector<int>> jobs(n, vector<int>(3));

        for (int i = 0; i < n; i++) {

            jobs[i] = {startTime[i], endTime[i], profit[i]};

        }

        // 按结束时间排序

        sort(jobs.begin(), jobs.end(),  {

            return a[1] < b[1];

        });

        // 下面的这个状态转移请参考背包问题讲解：

        // https://labuladong.online/algo/dynamic-programming/knapsack1/

        // 定义：在 0 到 i 这个时间区间内，最多能够获得的利润是 dp[i]

        map<int, int> dp;

        // base case，没有工作的时候利润为 0

        dp[0] = 0;

        // 基于 dp 的定义，进行状态转移

        for (const auto& job : jobs) {

            int begin = job[0];

            int end = job[1];

            int value = job[2];

            // 穷举所有可能的选择，求最大值

            dp[end] = max(

                // 选择这个 job，获得的利润是当前的利润加上在开始时间之前能获得的最大利润

                prev(dp.upper_bound(begin))->second + value,

                // 不选择，保持现有的最大利润

                dp.rbegin()->second

            );

        }

        return dp.rbegin()->second;

    }

};
```

#### 算法可视化

算法可视化

**详细题解**:

- [扫描线技巧：安排会议室](https://labuladong.online/zh/algo/frequency-interview/scan-line-technique/)

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表