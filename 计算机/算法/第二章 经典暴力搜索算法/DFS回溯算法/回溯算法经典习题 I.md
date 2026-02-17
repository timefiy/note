---
title: 回溯算法经典习题 I
source: https://labuladong.online/zh/algo/problem-set/backtrack-i/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上回溯算法算法的经典习题（第一部分），包含 labuladong 思路讲解和算法可视化，教会读者如何套用回溯算法代码框架。支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
### 967\. 连续差相同的数字

**967\. 连续差相同的数字** | [力扣](https://leetcode.cn/problems/numbers-with-same-consecutive-differences/) | [LeetCode](https://leetcode.com/problems/numbers-with-same-consecutive-differences/)

返回所有长度为 `n` 且满足其每两个连续位上的数字之间的差的绝对值为 `k` 的 **非负整数** 。

请注意， **除了** 数字 `0` 本身之外，答案中的每个数字都 **不能** 有前导零。例如， `01` 有一个前导零，所以是无效的；但 `0` 是有效的。

你可以按 **任何顺序** 返回答案。

**示例 1：**

```
输入：n = 3, k = 7
输出：[181,292,707,818,929]
解释：注意，070 不是一个有效的数字，因为它有前导零。
```

**示例 2：**

```
输入：n = 2, k = 1
输出：[10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
```

**示例 3：**

```
输入：n = 2, k = 0
输出：[11,22,33,44,55,66,77,88,99]
```

**示例 4：**

```
输入：n = 2, k = 2
输出：[13,20,24,31,35,42,46,53,57,64,68,75,79,86,97]
```

**提示：**

- `2 <= n <= 9`
- `0 <= k <= 9`

题目来源： [力扣 967. 连续差相同的数字](https://leetcode.cn/problems/numbers-with-same-consecutive-differences/) 。

#### 基本思路

其实可以直接套框架秒掉对吧，其实就是考察前文 [回溯算法描述排列组合的 9 种变体](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) 中的「元素无重可复选的排列」。

看出来了么？相当于给你 `n` 个盒子，然后你有 0~9 种球（元素）可以放进盒子，每个盒子只能放一个球，但每种球的数量无限，可以使用无数次。

不过这道题比标准的「元素无重可复选的排列」多了两个剪枝逻辑：

1、第一个数字不能是 0，因为题目要求数字不能以 0 开头；

2、相邻两个数字的差的绝对值必须等于 `k` 。

你把前文「元素无重可复选的排列」的代码框架 copy 过来，把这两个剪枝逻辑加上就行了，两分钟搞定。

这道题还有一个变通之处可以注意一下，我这里把路径 `track` 定义为 int 类型了，需要一点点数学技巧处理尾部追加数字和撤销数字的操作，你可以看看代码。

当然，你说你不用这些数学技巧，其实也可以，直接把数字转化成字符串操作就行了。具体看代码注释吧。

#### 解法代码

#### 算法可视化

算法可视化

### 980\. 不同路径 III

在二维网格 `grid` 上，有 4 种类型的方格：

- `1` 表示起始方格。且只有一个起始方格。
- `2` 表示结束方格，且只有一个结束方格。
- `0` 表示我们可以走过的空方格。
- `-1` 表示我们无法跨越的障碍。

返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目 **。**

**每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格** 。

**示例 1：**

```
输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
输出：2
解释：我们有以下两条路径：
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
```

**示例 2：**

```
输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
输出：4
解释：我们有以下四条路径： 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
```

**示例 3：**

```
输入：[[0,1],[2,0]]
输出：0
解释：
没有一条路能完全穿过每一个空的方格一次。
请注意，起始和结束方格可以位于网格中的任意位置。
```

**提示：**

- `1 <= grid.length * grid[0].length <= 20`

题目来源： [力扣 980. 不同路径 III](https://leetcode.cn/problems/unique-paths-iii/) 。

#### 基本思路

这道题不难，一个标准的 DFS 遍历就出来了，真没啥可说的，我没太理解为啥这题难度是困难。

具体看代码吧，如果对 DFS 算法有疑问，可以参考 [解答回溯/DFS算法的若干疑问](https://labuladong.online/zh/algo/essential-technique/backtrack-vs-dfs/) 。

#### 解法代码

#### 算法可视化

算法可视化

### 526\. 优美的排列

**526\. 优美的排列** | [力扣](https://leetcode.cn/problems/beautiful-arrangement/) | [LeetCode](https://leetcode.com/problems/beautiful-arrangement/)

假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 `perm` （ **下标从 1 开始** ），只要满足下述条件 **之一** ，该数组就是一个 **优美的排列** ：

- `perm[i]` 能够被 `i` 整除
- `i` 能够被 `perm[i]` 整除

给你一个整数 `n` ，返回可以构造的 **优美排列** 的 **数量** 。

**示例 1：**

```
输入：n = 2
输出：2
解释：
第 1 个优美的排列是 [1,2]：
    - perm[1] = 1 能被 i = 1 整除
    - perm[2] = 2 能被 i = 2 整除
第 2 个优美的排列是 [2,1]:
    - perm[1] = 2 能被 i = 1 整除
    - i = 2 能被 perm[2] = 1 整除
```

**示例 2：**

```
输入：n = 1
输出：1
```

**提示：**

- `1 <= n <= 15`

题目来源： [力扣 526. 优美的排列](https://leetcode.cn/problems/beautiful-arrangement/) 。

#### 基本思路

这个题就是标准的回溯算法。按照 [球盒模型：回溯算法的两种穷举视角](https://labuladong.online/zh/algo/practice-in-action/two-views-of-backtrack/) 的思路，这题应该也有两种穷举视角：

要么站在索引的视角，让每个索引来选择元素；要么站在元素的视角，让每个元素来选择要去的索引。

不过考虑到本题中，元素和索引差不多，都是 `1~n` ，所以这两种视角没有太大区别，我就写一个索引视角的回溯算法吧。

#### 解法代码

#### 算法可视化

算法可视化

### 491\. 非递减子序列

**491\. 非递减子序列** | [力扣](https://leetcode.cn/problems/non-decreasing-subsequences/) | [LeetCode](https://leetcode.com/problems/non-decreasing-subsequences/)

给你一个整数数组 `nums` ，找出并返回所有该数组中不同的递增子序列，递增子序列中 **至少有两个元素** 。你可以按 **任意顺序** 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

**示例 1：**

```
输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
```

**示例 2：**

```
输入：nums = [4,4,3,2,1]
输出：[[4,4]]
```

**提示：**

- `1 <= nums.length <= 15`
- `-100 <= nums[i] <= 100`

题目来源： [力扣 491. 非递减子序列](https://leetcode.cn/problems/non-decreasing-subsequences/) 。

#### 基本思路

其实这道题就是前文 [一文秒杀所有排列组合子集问题](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) 中讲过的「元素可重不可复选」的组合问题。

只不过这里又有一个额外的条件：组合中所有元素都必须是递增顺序。我们只需要添加一个 `track.getLast() > nums[i]` 条件即可。

另外， [一文秒杀所有排列组合子集问题](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) 中是利用排序的方式防止重复使用相同元素的，但这道题不能改变 `nums` 的原始顺序，所以不能用排序的方式，而是用 `used` 集合来避免重复使用相同元素。

综上，只要把 [40\. 组合总和 II](https://leetcode.cn/problems/combination-sum-ii/description/) 的解法稍改一下即可完成这道题。

#### 解法代码

#### 算法可视化

算法可视化

### 131\. 分割回文串

**131\. 分割回文串** | [力扣](https://leetcode.cn/problems/palindrome-partitioning/) | [LeetCode](https://leetcode.com/problems/palindrome-partitioning/)

给你一个字符串 `s` ，请你将 `s` 分割成一些子串，使每个子串都是 **回文串** 。返回 `s` 所有可能的分割方案。

**示例 1：**

```
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
```

**示例 2：**

```
输入：s = "a"
输出：[["a"]]
```

**提示：**

- `1 <= s.length <= 16`
- `s` 仅由小写英文字母组成

题目来源： [力扣 131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning/) 。

#### 基本思路

这道题是经典的回溯算法，完全遵循 [回溯算法详解](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) 中讲到的算法框架，和 [一文秒杀所有排列组合子集问题](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) 有异曲同工之妙。

我们就按照最直接粗暴的方式思考就行了：

从 `s` 的头部开始暴力穷举，如果发现 `s[0..i]` 是一个回文子串，那么我们就可以把 `s` 切分为 `s[0..i]` 和 `s[i+1..]` ，然后我们去尝试把 `s[i+1..]` 去暴力切分成多个回文子串即可。

> PS: 至于如何判断一个字符串是否是回文串，我在 [数组双指针技巧汇总](https://labuladong.online/zh/algo/essential-technique/array-two-pointers-summary/) 中的左右指针部分有讲解，很简单。

**把这个思路抽象成回溯树，树枝上是每次从头部穷举切分出的子串，节点上是待切分的剩余字符串** ：

![](https://labuladong.online/images/algo/brief-extra/131.jpeg)

只有树枝上的子串是回文串时才能继续往下走，最后如果能够走到空串节点，就说明整个 `s` 完成了切分，也就是得到了一个合法的答案。

只要套用回溯算法框架，按照上述规则遍历整棵回溯树即可找到所有合法切分，直接看代码吧。

#### 解法代码

#### 算法可视化

算法可视化

### 93\. 复原 IP 地址

**93\. 复原 IP 地址** | [力扣](https://leetcode.cn/problems/restore-ip-addresses/) | [LeetCode](https://leetcode.com/problems/restore-ip-addresses/)

**有效 IP 地址** 正好由四个整数（每个整数位于 `0` 到 `255` 之间组成，且不能含有前导 `0` ），整数之间用 `'.'` 分隔。

- 例如： `"0.1.2.201"` 和 ` "192.168.1.1"` 是 **有效** IP 地址，但是 `"0.011.255.245"` 、 `"192.168.1.312"` 和 `"192.168@1.1"` 是 **无效** IP 地址。

给定一个只包含数字的字符串 `s` ，用以表示一个 IP 地址，返回所有可能的 **有效 IP 地址** ，这些地址可以通过在 `s` 中插入 `'.'` 来形成。你 **不能** 重新排序或删除 `s` 中的任何数字。你可以按 **任何** 顺序返回答案。

**示例 1：**

```
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
```

**示例 2：**

```
输入：s = "0000"
输出：["0.0.0.0"]
```

**示例 3：**

```
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

**提示：**

- `1 <= s.length <= 20`
- `s` 仅由数字组成

题目来源： [力扣 93. 复原 IP 地址](https://leetcode.cn/problems/restore-ip-addresses/) 。

#### 基本思路

这道题是经典的回溯算法，完全遵循 [回溯算法详解](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) 中讲到的算法框架。

不过呢，做这道题之前我建议你先做一下 [131\. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning/description/) ，因为稍微改改 131 题就可以解决这道题了。

131 题的要求是：让你把字符串 `s` 切分成 **若干个** 合法的 **回文串** ，返回所有的切分方法。

本题的要求是：让你把字符串 `s` 切分成 **4 个** 合法的 **IP 数字** ，返回所有的切分方法。

所以我们只要把 131 题的解法稍微改改，重写一个 `isValid` 函数判断合法的 IP 数字，并保证整棵回溯树只有 4 层（即 `track` 中只有 4 个子串）即可。

具体看代码吧，基本逻辑和 131 题一模一样。

#### 解法代码

#### 算法可视化

算法可视化

### 89\. 格雷编码

**89\. 格雷编码** | [力扣](https://leetcode.cn/problems/gray-code/) | [LeetCode](https://leetcode.com/problems/gray-code/)

**n 位格雷码序列** 是一个由 `2<sup>n</sup>` 个整数组成的序列，其中：
- 每个整数都在范围 `[0, 2<sup>n</sup> - 1]` 内（含 `0` 和 `2<sup>n</sup> - 1` ）
- 第一个整数是 `0`
- 一个整数在序列中出现 **不超过一次**
- 每对 **相邻** 整数的二进制表示 **恰好一位不同** ，且
- **第一个** 和 **最后一个** 整数的二进制表示 **恰好一位不同**

给你一个整数 `n` ，返回任一有效的 **n 位格雷码序列** 。

**示例 1：**

```
输入：n = 2
输出：[0,1,3,2]
解释：
[0,1,3,2] 的二进制表示是 [00,01,11,10] 。
- 00 和 01 有一位不同
- 01 和 11 有一位不同
- 11 和 10 有一位不同
- 10 和 00 有一位不同
[0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
- 00 和 10 有一位不同
- 10 和 11 有一位不同
- 11 和 01 有一位不同
- 01 和 00 有一位不同
```

**示例 2：**

```
输入：n = 1
输出：[0,1]
```

**提示：**

- `1 <= n <= 16`

题目来源： [力扣 89. 格雷编码](https://leetcode.cn/problems/gray-code/) 。

#### 基本思路

不说数学相关的技巧，我们就用 [回溯算法框架](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) 一把梭，直接秒杀这道题。

你心里那棵递归回溯树出来没有？没有的话，就去看 [一切回溯思维，皆从此法出](https://labuladong.online/zh/algo/practice-in-action/two-views-of-backtrack/) 。

我直接用可视化面板把这个树画出来了，你可以拖动到最后，看看递归树长什么样，你也可以把鼠标放到递归树的节点上，查看每个节点的值以及每条树枝上所做的选择：

算法可视化

心里有了这棵树，代码就直接写出来了，就是一个多叉树遍历的代码，没啥可说的了，直接看代码吧。

#### 解法代码

#### 算法可视化

算法可视化

### 17\. 电话号码的字母组合

**17\. 电话号码的字母组合** | [力扣](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/) | [LeetCode](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![](https://labuladong.online/images/lc/aliyun-lc-upload/uploads/2021/11/09/200px-telephone-keypad2svg.png)

**示例 1：**

```
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**示例 2：**

```
输入：digits = ""
输出：[]
```

**示例 3：**

```
输入：digits = "2"
输出：["a","b","c"]
```

**提示：**

- `0 <= digits.length <= 4`
- `digits[i]` 是范围 `['2', '9']` 的一个数字。

题目来源： [力扣 17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/) 。

#### 基本思路

你需要先看前文 [回溯算法详解](https://labuladong.online/zh/algo/essential-technique/backtrack-framework/) 和 [回溯算法团灭子集、排列、组合问题](https://labuladong.online/zh/algo/essential-technique/permutation-combination-subset-all-in-one/) ，然后看这道题就很简单了，无非是回溯算法的运用而已。

组合问题本质上就是遍历一棵回溯树，套用回溯算法代码框架即可。

#### 解法代码

#### 算法可视化

算法可视化

**79\. 单词搜索** | [力扣](https://leetcode.cn/problems/word-search/) | [LeetCode](https://leetcode.com/problems/word-search/)

给定一个 `m x n` 二维字符网格  `board` 和一个字符串单词  `word` 。如果  `word` 存在于网格中，返回 `true` ；否则，返回 `false` 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

**示例 1：**

![](https://labuladong.online/images/lc/uploads/2020/11/04/word2.jpg)
```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
```

**示例 2：**

![](https://labuladong.online/images/lc/uploads/2020/11/04/word-1.jpg)
```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true
```

**示例 3：**

![](https://labuladong.online/images/lc/uploads/2020/10/15/word3.jpg)
```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false
```

**提示：**

- `m == board.length`
- `n = board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` 和 `word` 仅由大小写英文字母组成

**进阶：** 你可以使用搜索剪枝的技术来优化解决方案，使其在 `board` 更大的情况下可以更快解决问题？

题目来源： [力扣 79. 单词搜索](https://leetcode.cn/problems/word-search/) 。

#### 基本思路

这道题和 [一文秒杀所有岛屿题目](https://labuladong.online/zh/algo/frequency-interview/island-dfs-summary/) 中讲到的题目非常类似，用 DFS 算法暴力搜索就行了。

注意我们要对已经匹配过的字符做标记，比如用一个额外的 `visited` 布尔数组，或者使用其他方法标记 `board` 中已经匹配过的字符。

如果不做标记的话会出现错误的结果，比如这个测试用例：

你如果在其中搜索 `"ABCB"` ，按道理不应该搜到，但如果你不对已经匹配过的字符做标记的话，算法可能匹配了第一行前三列的 `"ABC"` 之后又回头匹配了第二列的 `"B"` ，导致出现错误的结果。

我就用加负号的方式标记已经匹配过的字符，来避免走回头路，具体看代码吧。

#### 解法代码

#### 算法可视化

### 473\. 火柴拼正方形

**473\. 火柴拼正方形** | [力扣](https://leetcode.cn/problems/matchsticks-to-square/) | [LeetCode](https://leetcode.com/problems/matchsticks-to-square/)

你将得到一个整数数组 `matchsticks` ，其中 `matchsticks[i]` 是第 `i` 个火柴棒的长度。你要用 **所有的火柴棍** 拼成一个正方形。你 **不能折断** 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 **使用一次** 。

如果你能使这个正方形，则返回 `true` ，否则返回 `false` 。

**示例 1:**

![](https://labuladong.online/images/lc/uploads/2021/04/09/matchsticks1-grid.jpg)

```
输入: matchsticks = [1,1,2,2,2]
输出: true
解释: 能拼成一个边长为2的正方形，每边两根火柴。
```

**示例 2:**

```
输入: matchsticks = [3,3,3,3,4]
输出: false
解释: 不能用所有火柴拼成一个正方形。
```

**提示:**

- `1 <= matchsticks.length <= 15`
- `1 <= matchsticks[i] <= 10<sup>8</sup>`

题目来源： [力扣 473. 火柴拼正方形](https://leetcode.cn/problems/matchsticks-to-square/) 。

#### 基本思路

这道题，说到底就是问是否可以把数组 `matchsticks` 分成 `4` 个和相等的子集。

做这道题，需要你看懂前文 [球盒模型：回溯算法的两种视角](https://labuladong.online/zh/algo/practice-in-action/two-views-of-backtrack/) ，然后去看 [经典回溯算法：集合划分问题](https://labuladong.online/zh/algo/practice-in-action/partition-to-k-equal-sum-subsets/) 。

在集合划分问题中，我们实现了一个函数 `canPartitionKSubsets` ，它的作用是判断是否能将一个数组分割成 `k` 个和相等的子集。

那么这道题就可以直接秒了，我们调用 `canPartitionKSubsets(matchsticks, 4)` 即可计算本题的答案。

#### 解法代码

#### 算法可视化

算法可视化

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表