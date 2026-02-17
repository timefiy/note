---
title: "回溯算法经典习题 II"
source: "https://labuladong.online/zh/algo/problem-set/backtrack-ii/"
author:
  - "[[labuladong]]"
published:
created: 2026-02-17
description: "本文汇总了 力扣/LeetCode 上回溯算法算法的经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，教会读者如何套用回溯算法代码框架。支持 Java/C++/Python/Golang/JavaScript。"
tags:
  - "clippings"
---
### 1219\. 黄金矿工

**1219\. 黄金矿工** | [力扣](https://leetcode.cn/problems/path-with-maximum-gold/) | [LeetCode](https://leetcode.com/problems/path-with-maximum-gold/)

你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 `m * n` 的网格 `grid` 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 `0` 。

为了使收益最大化，矿工需要按以下规则来开采黄金：

- 每当矿工进入一个单元，就会收集该单元格中的所有黄金。
- 矿工每次可以从当前位置向上下左右四个方向走。
- 每个单元格只能被开采（进入）一次。
- **不得开采** （进入）黄金数目为 `0` 的单元格。
- 矿工可以从网格中 **任意一个** 有黄金的单元格出发或者是停止。

**示例 1：**

```
输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
输出：24
解释：
[[0,6,0],
 [5,8,7],
 [0,9,0]]
一种收集最多黄金的路线是：9 -> 8 -> 7。
```

**示例 2：**

```
输入：grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
输出：28
解释：
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。
```

**提示：**

- `1 <= grid.length, grid[i].length <= 15`
- `0 <= grid[i][j] <= 100`
- 最多 **25** 个单元格中有黄金。

题目来源： [力扣 1219. 黄金矿工](https://leetcode.cn/problems/path-with-maximum-gold/) 。

#### 基本思路

大家看到这种问题应该高兴，因为这种题基本不会有什么精妙的技巧，就是纯粹的暴力穷举。而且题目给的数据规模也比较小，从侧面说明这道题用暴力解是可行的。

这道题和 [一文秒杀所有岛屿题目](https://labuladong.online/zh/algo/frequency-interview/island-dfs-summary/) 中讲到的题目思路非常类似，用 DFS 遍历就行了，以 `grid` 中的每个位置为起点，尝试穷举所有路径并记录路径和，最后取最大值即可。

#### 解法代码

```
class Solution {

    // 存储最大分数

    int res = 0;

    // 记录访问过的位置，避免走回头路死循环

    vector<vector<bool>> onPath;

    vector<vector<int>> grid;

public:

    int getMaximumGold(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        this->onPath = vector<vector<bool>>(m, vector<bool>(n, false));

        this->grid = grid;

        // 以每个位置为起点，尝试穷举所有路径并记录路径和

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                dfs(i, j, 0);

            }

        }

        return res;

    }

private:

    // 方向数组，辅助遍历元素的四周

    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // 从 (i, j) 开始向四周穷举遍历所有路径，pathSum 为当前路径的和

    void dfs(int i, int j, int pathSum) {

        // 超界，直接返回

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {

            return;

        }

        // 题目说 0 不能走，直接返回

        if (grid[i][j] == 0) {

            return;

        }

        // 走了回头路，直接返回

        if (onPath[i][j]) {

            return;

        }

        // 回溯算法框架：进入 (i, j)，做选择

        onPath[i][j] = true;

        pathSum += grid[i][j];

        res = max(res, pathSum);

        // 从 (i, j) 开始向四周穷举遍历所有路径

        for (const auto& dir : dirs) {

            dfs(i + dir[0], j + dir[1], pathSum);

        }

        // 回溯算法框架：退出 (i, j)，撤销选择

        onPath[i][j] = false;

        pathSum -= grid[i][j];

    }

};
```

#### 算法可视化

算法可视化

### 1849\. 将字符串拆分为递减的连续值

**1849\. 将字符串拆分为递减的连续值** | [力扣](https://leetcode.cn/problems/splitting-a-string-into-descending-consecutive-values/) | [LeetCode](https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/)

给你一个仅由数字组成的字符串 `s` 。

请你判断能否将 `s` 拆分成两个或者多个 **非空子字符串** ，使子字符串的 **数值** 按 **降序** 排列，且每两个 **相邻子字符串** 的数值之 **差** 等于 `1` 。

- 例如，字符串 `s = "0090089"` 可以拆分成 `["0090", "089"]` ，数值为 `[90,89]` 。这些数值满足按降序排列，且相邻值相差 `1` ，这种拆分方法可行。
- 另一个例子中，字符串 `s = "001"` 可以拆分成 `["0", "01"]` 、 `["00", "1"]` 或 `["0", "0", "1"]` 。然而，所有这些拆分方法都不可行，因为对应数值分别是 `[0,1]` 、 `[0,1]` 和 `[0,0,1]` ，都不满足按降序排列的要求。

如果可以按要求拆分 `s` ，返回 `true` ；否则，返回 `false` 。

**子字符串** 是字符串中的一个连续字符序列。

**示例 1：**

```
输入：s = "1234"
输出：false
解释：不存在拆分 s 的可行方法。
```

**示例 2：**

```
输入：s = "050043"
输出：true
解释：s 可以拆分为 ["05", "004", "3"] ，对应数值为 [5,4,3] 。
满足按降序排列，且相邻值相差 1 。
```

**示例 3：**

```
输入：s = "9080701"
输出：false
解释：不存在拆分 s 的可行方法。
```

**示例 4：**

```
输入：s = "10009998"
输出：true
解释：s 可以拆分为 ["100", "099", "98"] ，对应数值为 [100,99,98] 。
满足按降序排列，且相邻值相差 1 。
```

**提示：**

- `1 <= s.length <= 20`
- `s` 仅由数字组成

题目来源： [力扣 1849. 将字符串拆分为递减的连续值](https://leetcode.cn/problems/splitting-a-string-into-descending-consecutive-values/) 。

#### 基本思路

这道题不难吧，标准的回溯算法。根据 [球盒模型：回溯算法的两种穷举视角](https://labuladong.online/zh/algo/practice-in-action/two-views-of-backtrack/) ，肯定有两种穷举视角来写回溯算法代码。

你可以站在每个子串的视角来选择字符，每个子串可以选择包含 `s[start]` 开头的任意个字符。

也可以站在每个字符的视角来穷举，对于 `s` 中每个字符间隙都有两种选择：「切割」或者「不切割」，如果切割，则产生一个新子串。

我把两种视角都写了，且都配备了可视化面板。如果你实在想不通两种视角的差异，可以把可视化面板拉到最后，鼠标移动到递归树上查看每个节点所做的选择，就可以直观理解这两种思维的差异了。

这题需要注意 `s` 长度可以达到 20，直接解析成 `long` 类型也会溢出的，所以我根据 `subStr` 的长度来剪枝，避免字符串数字转换为 `long` 类型时溢出。

#### 解法代码

```
// 站在字符的视角进行穷举

class Solution {

public:

    bool splitString(string s) {

        backtrack(s, 0, 0);

        return found;

    }

    list<string> track;

    bool found = false;

    void backtrack(string s, int start, int index) {

        if (found) {

            // 剪枝，找到一个答案后就不要再继续回溯了

            return;

        }

        if (index == s.length()) {

            if (track.size() >= 2 && accumulate(track.begin(), track.end(), string("")) == s) {

                found = true;

            }

            return;

        }

        // 选择一，s[index] 决定切割

        string subStr = s.substr(start, index - start + 1);

        int leadingZeroCount = 0;

        for (int j = 0; j < subStr.length(); j++) {

            if (subStr[j] == '0') {

                leadingZeroCount++;

            } else {

                break;

            }

        }

        if (subStr.length() - leadingZeroCount > (s.length() + 1) / 2) {

            // 剪枝逻辑，如果当前截取的子串长度大于 s 的一半，那么没必要继续截取了，肯定不可能只差一

            // 同时可以避免溢出 long 的最大值的问题

            return;

        }

        long curNum = stol(subStr);

        if (track.empty() || stol(track.back()) - curNum == 1) {

            // 符合题目的要求，当前数字比上一个数字小 1

            // 做选择，切割出一个子串

            track.push_back(subStr);

            backtrack(s, index + 1, index + 1);

            // 撤销选择

            track.pop_back();

        }

        // 选择二，s[index] 决定不切割

        backtrack(s, start, index + 1);

    }

};

// 站在子串的视角进行穷举

class Solution2 {

public:

    bool splitString(string s) {

        backtrack(s, 0);

        return found;

    }

    list<string> track;

    bool found = false;

    void backtrack(string s, int start) {

        if (found) {

            // 剪枝，找到一个答案后就不要再继续回溯了

            return;

        }

        if (start == s.length()) {

            if (track.size() >= 2 && accumulate(track.begin(), track.end(), string("")) == s) {

                found = true;

            }

            return;

        }

        for (int i = start; i < s.length(); i++) {

            string subStr = s.substr(start, i - start + 1);

            int leadingZeroCount = 0;

            for (int j = 0; j < subStr.length(); j++) {

                if (subStr[j] == '0') {

                    leadingZeroCount++;

                } else {

                    break;

                }

            }

            if (subStr.length() - leadingZeroCount > (s.length() + 1) / 2) {

                // 剪枝逻辑，如果当前截取的子串长度大于 s 的一半，那么没必要继续截取了，肯定不可能只差一

                // 同时可以避免溢出 long 的最大值的问题

                return;

            }

            long curNum = stol(subStr);

            if (track.empty() || stol(track.back()) - curNum == 1) {

                // 符合题目的要求，当前数字比上一个数字小 1

                // 做选择，切割出一个子串

                track.push_back(subStr);

                backtrack(s, i + 1);

                // 撤销选择

                track.pop_back();

            }

        }

    }

};
```

#### 算法可视化

算法可视化

### 1593\. 拆分字符串使唯一子字符串的数目最大

**1593\. 拆分字符串使唯一子字符串的数目最大** | [力扣](https://leetcode.cn/problems/split-a-string-into-the-max-number-of-unique-substrings/) | [LeetCode](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/)

给你一个字符串 `s` ，请你拆分该字符串，并返回拆分后唯一子字符串的最大数目。

字符串 `s` 拆分后可以得到若干 **非空子字符串** ，这些子字符串连接后应当能够还原为原字符串。但是拆分出来的每个子字符串都必须是 **唯一的** 。

注意： **子字符串** 是字符串中的一个连续字符序列。

**示例 1：**

```
输入：s = "ababccc"
输出：5
解释：一种最大拆分方法为 ['a', 'b', 'ab', 'c', 'cc'] 。像 ['a', 'b', 'a', 'b', 'c', 'cc'] 这样拆分不满足题目要求，因为其中的 'a' 和 'b' 都出现了不止一次。
```

**示例 2：**

```
输入：s = "aba"
输出：2
解释：一种最大拆分方法为 ['a', 'ba'] 。
```

**示例 3：**

```
输入：s = "aa"
输出：1
解释：无法进一步拆分字符串。
```

**提示：**

- `1 <= s.length <= 16`
- `s` 仅包含小写英文字母

题目来源： [力扣 1593. 拆分字符串使唯一子字符串的数目最大](https://leetcode.cn/problems/split-a-string-into-the-max-number-of-unique-substrings/) 。

#### 基本思路

这道题一看就是标准的回溯算法，求子序列、排列组合、字符串分割的问题，大概率都是回溯算法。不信你再看看这题给的数据规模， `s` 的长度最大为 16，这么小的规模，说明算法的复杂度比较高，降不下去，所以更加确定了要用回溯算法求解这道题。

只要你认真看过前文 [二叉树核心纲领](https://labuladong.online/zh/algo/essential-technique/binary-tree-summary/) 和 [回溯算法秒杀所有排列组合子集问题](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) ，那么看到这道题心中那棵递归树就应该画出来了。

如果你又看过前文 [球盒模型两种视角涵盖一切回溯穷举](https://labuladong.online/zh/algo/practice-in-action/two-views-of-backtrack/) ，那么你心中应该有两棵树，一棵多叉树，一棵二叉树。

上面提到的几篇文章，你认真读过，就能秒杀这道题，下面的分析你才能秒懂。如果没读过，先去读一读，回头再来看这道题。

第一种穷举视角是站在子串的视角（盒的视角），你切分的子串长度可以是 1，可以是 2，...，可以是 `s.length()` 。

脑海中有没有出现一棵多叉树？实在没有的话，我就帮你画出来：

算法可视化

第二种穷举视角是站在 `s` 的每个索引空隙之间进行选择（球的视角），你可以选择切，也可以选择不切。

如果选择切，就获得了一个子串，如果选择不切，就继续走到下一个索引空隙，然后继续进行选择。

都给你讲到这里了，看到二叉树没有？如果还没有看到，那我只能帮你把这棵二叉树画出来了：

算法可视化

其实他们本质上都差不多，我就选择第二种解法思路，直接翻译成其他语言就是解法了。

当然，我给出的解法还有一些小优化的点，比如我们不用真的调用 `substring` 方法，去切割子串，而是仅通过索引来控制，这样可以减少一些不必要的字符串拷贝操作，提高运行效率。

这些细节问题我就不处理了，你可以尝试自己优化一下，提高代码的运行速度。

#### 解法代码

```
#include <unordered_set>

#include <string>

#include <algorithm>

class Solution {

public:

    int maxUniqueSplit(std::string s) {

        backtrack(s, 0);

        return res;

    }

private:

    std::unordered_set<std::string> set;

    int res = 0;

    void backtrack(const std::string &s, int index) {

        if (index == s.length()) {

            res = std::max(res, static_cast<int>(set.size()));

            return;

        }

        // 选择不切，什么都不做，直接走到下一个索引空隙

        backtrack(s, index + 1);

        // 选择切，把 s[0..index] 切分出来作为一个子串

        std::string sub = s.substr(0, index + 1);

        // 按照题目要求，不能有重复的子串

        if (set.find(sub) == set.end()) {

            // 做选择

            set.insert(sub);

            // 剩下的字符继续穷举

            backtrack(s.substr(index + 1), 0);

            // 撤销选择

            set.erase(sub);

        }

    }

};
```

#### 算法可视化

算法可视化

### 1079\. 活字印刷

**1079\. 活字印刷** | [力扣](https://leetcode.cn/problems/letter-tile-possibilities/) | [LeetCode](https://leetcode.com/problems/letter-tile-possibilities/)

你有一套活字字模 `tiles` ，其中每个字模上都刻有一个字母  `tiles[i]` 。返回你可以印出的非空字母序列的数目。

**注意：** 本题中，每个活字字模只能使用一次。

**示例 1：**

```
输入："AAB"
输出：8
解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
```

**示例 2：**

```
输入："AAABBC"
输出：188
```

**示例 3：**

```
输入："V"
输出：1
```

**提示：**

- `1 <= tiles.length <= 7`
- `tiles` 由大写英文字母组成

题目来源： [力扣 1079. 活字印刷](https://leetcode.cn/problems/letter-tile-possibilities/) 。

#### 基本思路

这个题其实就是前文 [回溯算法秒杀所有排列组合子集问题](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) 中讲到的元素可重不可复选的排列问题。

只不过前文我讲的是全排列，而这道题问的不是全排列，而是普通排列。

全排列的意思是，比方说我输入 `AAB` ，那么输出的结果是 `AAB, ABA, BAA` ，即每个元素都要参与到排列中。

而普通排列的意思是，比方说我输入 `AAB` ，那么输出的结果是 `A, B, AA, AB, BA, BB, AAA, AAB, ABA, BAA` ，即并非每个元素都要参与到排列中。

所以关键的区别在哪里呢？就在于收集结果的时机。用 [回溯算法秒杀所有排列组合子集问题](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) 中全排列的递归树举例：

![](https://labuladong.online/images/algo/permutation/7.jpeg)

**我们计算全排列时，只收集最底层叶子节点上的值。而这道题，我们收集所有节点上的值** 。

所以你把前文解决的元素可重不可复选的全排列代码 copy 过来稍微改一下，在前序位置收集节点，就可以解决这道题了，具体看我的代码吧。

#### 解法代码

```
#include <vector>

#include <string>

#include <algorithm>

using namespace std;

class Solution {

public:

    int res = 0;

    vector<bool> used;

    int numTilePossibilities(string s) {

        vector<char> nums(s.begin(), s.end());

        // 先排序，让相同的元素靠在一起

        sort(nums.begin(), nums.end());

        used = vector<bool>(nums.size(), false);

        backtrack(nums);

        return res - 1;

    }

    void backtrack(vector<char>& nums) {

        res++;

        for (int i = 0; i < nums.size(); i++) {

            if (used[i]) {

                continue;

            }

            // 新添加的剪枝逻辑，固定相同的元素在排列中的相对位置

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {

                continue;

            }

            used[i] = true;

            backtrack(nums);

            used[i] = false;

        }

    }

};
```

#### 算法可视化

算法可视化

### 996\. 平方数组的数目

**996\. 平方数组的数目** | [力扣](https://leetcode.cn/problems/number-of-squareful-arrays/) | [LeetCode](https://leetcode.com/problems/number-of-squareful-arrays/)

如果一个数组的任意两个相邻元素之和都是 **完全平方数** ，则该数组称为 **平方数组** 。

给定一个整数数组 `nums` ，返回所有属于 **平方数组** 的 `nums` 的排列数量。

如果存在某个索引 `i` 使得 `perm1[i] != perm2[i]` ，则认为两个排列 `perm1` 和 `perm2` 不同。

**示例 1：**

```
输入：nums = [1,17,8]
输出：2
解释：[1,8,17] 和 [17,8,1] 是有效的排列。
```

**示例 2：**

```
输入：nums = [2,2,2]
输出：1
```

**提示：**

- `1 <= nums.length <= 12`
- `0 <= nums[i] <= 10<sup>9</sup>`

题目来源： [力扣 996. 平方数组的数目](https://leetcode.cn/problems/number-of-squareful-arrays/) 。

#### 基本思路

其实可以直接套框架秒掉对吧，其实就是考察前文 [回溯算法描述排列组合的 9 种变体](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) 中的「元素可重不可复选的排列」。

不过这里多了一个剪枝逻辑，即仅相邻元素之和为完全平方数时，才是本题的合法排列。

我们在回溯代码中加上两行代码添加这个剪枝逻辑即可，具体看代码吧，我把本题新增的代码用注释说明了，其他的都是前文的代码框架，不懂的话去看前文。

我觉得这道题唯一的难点是考察如何判断一个数字是完全平方数，一个比较容易想到的办法是用数学标准库的 `sqrt` 先开方，转化成整数再平方比较，这样就可以避开浮点数精度问题。

这道题还好意思说自己的难度是困难？就这？

#### 解法代码

```
#include <vector>

#include <algorithm>

#include <cmath>

using namespace std;

class Solution {

public:

    vector<int> track;

    vector<bool> used;

    int count = 0;

    int numSquarefulPerms(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        used = vector<bool>(nums.size(), false);

        backtrack(nums);

        return count;

    }

    void backtrack(vector<int>& nums) {

        if (track.size() == nums.size()) {

            // 本题求合法排列总数，直接累加即可

            count++;

            return;

        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i]) {

                continue;

            }

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {

                continue;

            }

            // 本题新增的剪枝逻辑，仅相邻元素之和为完全平方数时，才是本题的合法排列

            if (track.size() > 0 && !isSquareful(track.back(), nums[i])) {

                continue;

            }

            track.push_back(nums[i]);

            used[i] = true;

            backtrack(nums);

            track.pop_back();

            used[i] = false;

        }

    }

    // 判断两个数 a 和 b 的和是否是一个完全平方数

    bool isSquareful(int a, int b) {

        int c = sqrt(a + b);

        return c * c == a + b;

    }

};
```

#### 算法可视化

算法可视化

### 784\. 字母大小写全排列

**784\. 字母大小写全排列** | [力扣](https://leetcode.cn/problems/letter-case-permutation/) | [LeetCode](https://leetcode.com/problems/letter-case-permutation/)

给定一个字符串 `s`  ，通过将字符串  `s` 中的每个字母转变大小写，我们可以获得一个新的字符串。

返回 *所有可能得到的字符串集合* 。以 **任意顺序** 返回输出。

**示例 1：**

```
输入：s = "a1b2"
输出：["a1b2", "a1B2", "A1b2", "A1B2"]
```

**示例 2:**

```
输入: s = "3z4"
输出: ["3z4","3Z4"]
```

**提示:**

- `1 <= s.length <= 12`
- `s` 由小写英文字母、大写英文字母和数字组成

题目来源： [力扣 784. 字母大小写全排列](https://leetcode.cn/problems/letter-case-permutation/) 。

#### 基本思路

这是标准的回溯算法，可以通过前文讲的 [回溯算法框架](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) 求解。

如何穷举呢？对于每一个字符，有如下选择：

1、如果该字符是字母，则可以是大写，也可以是小写。

2、如果该字符是数字，则只能是它本身。

![](https://labuladong.online/images/algo/brief-extra/784.jpg)

有了这个思路，直接翻译成代码即可。

#### 解法代码

```
#include <vector>

#include <string>

#include <cctype>

using namespace std;

class Solution {

public:

    vector<string> letterCasePermutation(string s) {

        backtrack(s, 0);

        return res;

    }

private:

    string track;

    vector<string> res;

    void backtrack(const string& s, int index) {

        if (index == s.length()) {

            res.push_back(track);

            return;

        }

        if ('0' <= s[index] && s[index] <= '9') {

            // s[index] 是数字

            // 做选择

            track += s[index];

            backtrack(s, index + 1);

            // 撤销选择

            track.pop_back();

        } else {

            // s[index] 是字母

            

            // 小写字母，做选择

            track += tolower(s[index]);

            backtrack(s, index + 1);

            // 撤销选择

            track.pop_back();

            // 大写字母，做选择

            track += toupper(s[index]);

            backtrack(s, index + 1);

            // 撤销选择

            track.pop_back();

        }

    }

};
```

#### 算法可视化

算法可视化

### 638\. 大礼包

**638\. 大礼包** | [力扣](https://leetcode.cn/problems/shopping-offers/) | [LeetCode](https://leetcode.com/problems/shopping-offers/)

在 LeetCode 商店中， 有 `n` 件在售的物品。每件物品都有对应的价格。然而，也有一些大礼包，每个大礼包以优惠的价格捆绑销售一组物品。

给你一个整数数组 `price` 表示物品价格，其中 `price[i]` 是第 `i` 件物品的价格。另有一个整数数组 `needs` 表示购物清单，其中 `needs[i]` 是需要购买第 `i` 件物品的数量。

还有一个数组 `special` 表示大礼包， `special[i]` 的长度为 `n + 1` ，其中 `special[i][j]` 表示第 `i` 个大礼包中内含第 `j` 件物品的数量，且 `special[i][n]` （也就是数组中的最后一个整数）为第 `i` 个大礼包的价格。

返回 **确切** 满足购物清单所需花费的最低价格，你可以充分利用大礼包的优惠活动。你不能购买超出购物清单指定数量的物品，即使那样会降低整体价格。任意大礼包可无限次购买。

**示例 1：**

```
输入：price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
输出：14
解释：有 A 和 B 两种物品，价格分别为 ¥2 和 ¥5 。 
大礼包 1 ，你可以以 ¥5 的价格购买 3A 和 0B 。 
大礼包 2 ，你可以以 ¥10 的价格购买 1A 和 2B 。 
需要购买 3 个 A 和 2 个 B ， 所以付 ¥10 购买 1A 和 2B（大礼包 2），以及 ¥4 购买 2A 。
```

**示例 2：**

```
输入：price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
输出：11
解释：A ，B ，C 的价格分别为 ¥2 ，¥3 ，¥4 。
可以用 ¥4 购买 1A 和 1B ，也可以用 ¥9 购买 2A ，2B 和 1C 。 
需要买 1A ，2B 和 1C ，所以付 ¥4 买 1A 和 1B（大礼包 1），以及 ¥3 购买 1B ， ¥4 购买 1C 。 
不可以购买超出待购清单的物品，尽管购买大礼包 2 更加便宜。
```

**提示：**

- `n == price.length`
- `n == needs.length`
- `1 <= n <= 6`
- `0 <= price[i] <= 10`
- `0 <= needs[i] <= 10`
- `1 <= special.length <= 100`
- `special[i].length == n + 1`
- `0 <= special[i][j] <= 50`

题目来源： [力扣 638. 大礼包](https://leetcode.cn/problems/shopping-offers/) 。

#### 基本思路

我知道很多同学看到这种题就懵圈，我告诉大家，不要怕，只要你把最基本的 [回溯算法框架](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) 搞清楚，把 [回溯算法搞定排列/组合/子集问题](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) 吃透，其实就可以应对千变万化的题目了，因为排列组合就是所有回溯问题的基本模型，你看那题目千变万化，总是逃不出最基本的模型。

这道题，不就是排列组合吗？具体点说，这就是 [回溯算法搞定排列/组合/子集问题](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) 中讲的「元素无重可复选」的组合问题。

「元素无重可复选」的组合问题是给你一个 `nums` 数组，请你返回 `nums` 数组中和为 `target` 的所有组合； `nums` 中的元素无重复，可以选择任意次数。

回到这道题，你不就是让我选大礼包 `special` 凑出 `needs` 嘛？这就好比组合问题中，你让我在 `nums` 数组中选择若干元素凑出 `target` ，没什么太大的区别。

思路主要分两步：

1、保证所有的大礼包都是优惠的。因为我实际测下来发现大礼包并不是总是比单买更便宜，所以要先去除那些大礼包还不如单买更便宜的大礼包。

2、现在所有大礼包必然是优惠的，那么我们就可以使用一点贪心思想：能用大礼包优先买大礼包，直到最后不能再买大礼包了，再用单买的方式补齐。

我们使用回溯算法实际上在穷举大礼包的组合，无法再组合大礼包的时候，单买补齐剩余物品（其实就是 base case），直接套用组合问题的算法逻辑即可，具体看代码吧。

#### 解法代码

```
#include <vector>

#include <algorithm>

#include <climits>

using namespace std;

class Solution {

    vector<int> price;

    vector<vector<int>> specials;

    // 记录当前购买大礼包的花费

    int trackCost = 0;

    // 记录最小花费

    int minCost = INT_MAX;

public:

    int shoppingOffers(vector<int>& price, vector<vector<int>>& specials, vector<int>& needs) {

        // 去除那些大礼包还不如单买更便宜的情况

        vector<vector<int>> newSpecials;

        for (int i = 0; i < specials.size(); i++) {

            vector<int> special = specials[i];

            int cost = 0;

            for (int j = 0; j < special.size() - 1; j++) {

                cost += special[j] * price[j];

            }

            if (cost > special[special.size() - 1]) {

                newSpecials.push_back(special);

            }

        }

        this->price = price;

        this->specials = newSpecials;

        backtrack(needs, 0);

        return minCost;

    }

    // 回溯算法核心框架

    // 整体逻辑可以类比「元素无重可复选」的组合问题

    void backtrack(vector<int>& needs, int start) {

        if (trackCost >= minCost) {

            // 剪枝

            return;

        }

        bool haveUsedSpecial = false;

        // 组合问题需要从 start 开始遍历

        for (int i = start; i < specials.size(); i++) {

            vector<int> targetSpecial = specials[i];

            if (!canUseSpecial(targetSpecial, needs)) {

                continue;

            }

            haveUsedSpecial = true;

            // 可以买 specials[i] 这个大礼包

            // 做出购买的选择

            for (int j = 0; j < needs.size(); j++) {

                needs[j] -= targetSpecial[j];

            }

            trackCost += targetSpecial[targetSpecial.size() - 1];

            // 因为每个元素可以复选，所以下次回溯依然从 i 开始

            backtrack(needs, i);

            // 撤销购买的选择

            for (int j = 0; j < needs.size(); j++) {

                needs[j] += targetSpecial[j];

            }

            trackCost -= targetSpecial[targetSpecial.size() - 1];

        }

        if (!haveUsedSpecial) {

            // 无法使用大礼包，只能单买

            int sum = 0;

            for (int i = 0; i < needs.size(); i++) {

                sum += needs[i] * price[i];

            }

            // 单买的价格加上之前的大礼包的价格

            minCost = min(minCost, sum + trackCost);

        }

    }

    // 判断是否可以使用这个大礼包

    bool canUseSpecial(vector<int>& special, vector<int>& need) {

        for (int i = 0; i < need.size(); i++) {

            if (need[i] < special[i]) {

                return false;

            }

        }

        return true;

    }

};
```

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表