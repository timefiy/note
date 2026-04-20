---
title: 一个方法团灭 LeetCode 股票买卖问题
source: https://labuladong.online/zh/algo/dynamic-programming/stock-problem-summary/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文由浅入深讲解 LeetCode/力扣 上所有股票买卖系列问题的动态规划解法，把所有问题归纳为同一种思维模式，最后给出一个通用解法。
tags:
  - clippings
---
读完本文，你不仅学会了算法套路，还可以顺便解决如下题目：

| LeetCode | 力扣 | 难度 |
| --- | --- | --- |
| [714\. Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) | [714\. 买卖股票的最佳时机含手续费](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) |  |
| [188\. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) | [188\. 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/) |  |
| [121\. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [121\. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) |  |
| [122\. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | [122\. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/) |  |
| [309\. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | [309\. 买卖股票的最佳时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/) |  |
| [123\. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | [123\. 买卖股票的最佳时机 III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/) |  |

前置知识

阅读本文前，你需要先学习：

- [动态规划核心框架](https://labuladong.online/zh/algo/essential-technique/dynamic-programming-framework/)

很多读者抱怨力扣上的股票系列问题的解法太多，如果面试真的遇到这类问题，基本不会想到那些巧妙的办法，怎么办？ **所以本文不讲那些过于巧妙的思路，而是稳扎稳打，只用一种通用方法解决所有问题，以不变应万变** 。

这篇文章参考 [高赞题解](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems) 的思路，用状态机的技巧来解决，可以全部提交通过。不要觉得这个名词高大上，文学词汇而已，实际上就是 DP table，看一眼就明白了。

先随便抽出一道题，看看别人的解法：

```
int maxProfit(int[] prices) {

    if(prices.empty()) return 0;

    int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;

    for(int i = 1; i < prices.size(); ++i) {            

        s1 = max(s1, -prices[i]);

        s2 = max(s2, s1 + prices[i]);

        s3 = max(s3, s2 - prices[i]);

        s4 = max(s4, s3 + prices[i]);

    }

    return max(0, s4);

}
```

能看懂吧？会做了吗？不可能的，你看不懂，这才正常。就算你勉强看懂了，下一个问题你还是做不出来。为什么别人能写出这么诡异却又高效的解法呢？因为这类问题是有框架的，但是人家不会告诉你的，因为一旦告诉你，你五分钟就学会了，该算法题就不再神秘，变得不堪一击了。

本文就来告诉你这个框架，然后带着你一道一道秒杀。这篇文章用状态机的技巧来解决，可以全部提交通过。不要觉得这个名词高大上，文学词汇而已，实际上就是 DP table，看一眼就明白了。

这 6 道题目是有共性的，我们只需要抽出来力扣第 188 题「 [买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/) 」进行研究，因为这道题是最泛化的形式，其他的问题都是这个形式的简化，看下题目：

给你一个整数数组 `prices` 和一个整数 `k` ，其中 `prices[i]` 是某支给定的股票在第 `i` 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 `k` 笔交易。也就是说，你最多可以买 `k` 次，卖 `k` 次。

**注意：** 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1：**

```
输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
```

**示例 2：**

```
输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
```

**提示：**

- `1 <= k <= 100`
- `1 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

题目来源： [力扣 188. 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/) 。

第一题是只进行一次交易，相当于 `k = 1` ；第二题是不限交易次数，相当于 `k = +infinity` （正无穷）；第三题是只进行 2 次交易，相当于 `k = 2` ；剩下两道也是不限次数，但是加了交易「冷冻期」和「手续费」的额外条件，其实就是第二题的变种，都很容易处理。

下面言归正传，开始解题。

## 穷举框架

首先，还是一样的思路：如何穷举？

[动态规划核心套路](https://labuladong.online/zh/algo/essential-technique/dynamic-programming-framework/) 说过，动态规划算法本质上就是穷举「状态」，然后在「选择」中选择最优解。

那么对于这道题，我们具体到每一天，看看总共有几种可能的「状态」，再找出每个「状态」对应的「选择」。我们要穷举所有「状态」，穷举的目的是根据对应的「选择」更新状态。听起来抽象，你只要记住「状态」和「选择」两个词就行，下面实操一下就很容易明白了。

```
for 状态1 in 状态1的所有取值：

    for 状态2 in 状态2的所有取值：

        for ...

            dp[状态1][状态2][...] = 择优(选择1，选择2...)
```

比如说这个问题， **每天都有三种「选择」** ：买入、卖出、无操作，我们用 `buy`, `sell`, `rest` 表示这三种选择。

但问题是，并不是每天都可以任意选择这三种选择的，因为 `sell` 必须在 `buy` 之后， `buy` 必须在 `sell` 之后。那么 `rest` 操作还应该分两种状态，一种是 `buy` 之后的 `rest` （持有了股票），一种是 `sell` 之后的 `rest` （没有持有股票）。而且别忘了，我们还有交易次数 `k` 的限制，就是说你 `buy` 还只能在 `k > 0` 的前提下操作。

Note

注意我在本文会频繁使用「交易」这个词， **我们把一次买入和一次卖出定义为一次「交易」** 。

很复杂对吧，不要怕，我们现在的目的只是穷举，你有再多的状态，老夫要做的就是一把梭全部列举出来。

**这个问题的「状态」有三个** ，第一个是天数，第二个是允许交易的最大次数，第三个是当前的持有状态（即之前说的 `rest` 的状态，我们不妨用 1 表示持有，0 表示没有持有）。然后我们用一个三维数组就可以装下这几种状态的全部组合：

```
dp[i][k][0 or 1]

0 <= i <= n - 1, 1 <= k <= K

n 为天数，大 K 为交易数的上限，0 和 1 代表是否持有股票。

此问题共 n × K × 2 种状态，全部穷举就能搞定。

for 0 <= i < n:

    for 1 <= k <= K:

        for s in {0, 1}:

            dp[i][k][s] = max(buy, sell, rest)
```

而且我们可以用自然语言描述出每一个状态的含义，比如说 `dp[3][2][1]` 的含义就是：今天是第三天，我现在手上持有着股票，至今最多进行 2 次交易。再比如 `dp[2][3][0]` 的含义：今天是第二天，我现在手上没有持有股票，至今最多进行 3 次交易。很容易理解，对吧？

我们想求的最终答案是 `dp[n - 1][K][0]` ，即最后一天，最多允许 `K` 次交易，最多获得多少利润。

读者可能问为什么不是 `dp[n - 1][K][1]` ？因为 `dp[n - 1][K][1]` 代表到最后一天手上还持有股票， `dp[n - 1][K][0]` 表示最后一天手上的股票已经卖出去了，很显然后者得到的利润一定大于前者。

记住如何解释「状态」，一旦你觉得哪里不好理解，把它翻译成自然语言就容易理解了。

## 状态转移框架

现在，我们完成了「状态」的穷举，我们开始思考每种「状态」有哪些「选择」，应该如何更新「状态」。

只看「持有状态」，可以画个状态转移图：

![](https://labuladong.online/images/algo/stock/1.png)

通过这个图可以很清楚地看到，每种状态（0 和 1）是如何转移而来的。根据这个图，我们来写一下状态转移方程：

```
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])

              max( 今天选择 rest,        今天选择 sell       )
```

解释：今天我没有持有股票，有两种可能，我从这两种可能中求最大利润：

1、我昨天就没有持有，且截至昨天最大交易次数限制为 `k` ；然后我今天选择 `rest` ，所以我今天还是没有持有，最大交易次数限制依然为 `k` 。

2、我昨天持有股票，且截至昨天最大交易次数限制为 `k` ；但是今天我 `sell` 了，所以我今天没有持有股票了，最大交易次数限制依然为 `k` 。

```
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

              max( 今天选择 rest,         今天选择 buy         )
```

解释：今天我持有着股票，最大交易次数限制为 `k` ，那么对于昨天来说，有两种可能，我从这两种可能中求最大利润：

1、我昨天就持有着股票，且截至昨天最大交易次数限制为 `k` ；然后今天选择 `rest` ，所以我今天还持有着股票，最大交易次数限制依然为 `k` 。

2、我昨天本没有持有，且截至昨天最大交易次数限制为 `k - 1` ；但今天我选择 `buy` ，所以今天我就持有股票了，最大交易次数限制为 `k` 。

Note

这里着重提醒一下， **时刻牢记「状态」的定义** ，状态 `k` 的定义并不是「已进行的交易次数」，而是「最大交易次数的上限限制」。如果确定今天进行一次交易，且要保证截至今天最大交易次数上限为 `k` ，那么昨天的最大交易次数上限必须是 `k - 1` 。举个具体的例子，比方说要求你的银行卡里今天至少有 100 块钱，且你确定你今天可以赚 10 块钱，那么你就要保证昨天的银行卡要至少剩下 90 块钱。

这个解释应该很清楚了，如果 `buy` ，就要从利润中减去 `prices[i]` ，如果 `sell` ，就要给利润增加 `prices[i]` 。今天的最大利润就是这两种可能选择中较大的那个。

注意 `k` 的限制，在选择 `buy` 的时候相当于开启了一次交易，那么对于昨天来说，交易次数的上限 `k` 应该减小 1。

Note

这里补充修正一点，以前我以为在 `sell` 的时候给 `k` 减小 1 和在 `buy` 的时候给 `k` 减小 1 是等效的，但细心的读者向我提出质疑，经过深入思考我发现前者确实是错误的，因为交易是从 `buy` 开始，如果 `buy` 的选择不改变交易次数 `k` 的话，会出现交易次数超出限制的的错误。

现在，我们已经完成了动态规划中最困难的一步：状态转移方程。 **如果之前的内容你都可以理解，那么你已经可以秒杀所有问题了，只要套这个框架就行了** 。不过还差最后一点点，就是定义 base case，即最简单的情况。

```
dp[-1][...][0] = 0

解释：因为 i 是从 0 开始的，所以 i = -1 意味着还没有开始，这时候的利润当然是 0。

dp[-1][...][1] = -infinity

解释：还没开始的时候，是不可能持有股票的。

因为我们的算法要求一个最大值，所以初始值设为一个最小值，方便取最大值。

dp[...][0][0] = 0

解释：因为 k 是从 1 开始的，所以 k = 0 意味着根本不允许交易，这时候利润当然是 0。

dp[...][0][1] = -infinity

解释：不允许交易的情况下，是不可能持有股票的。

因为我们的算法要求一个最大值，所以初始值设为一个最小值，方便取最大值。
```

把上面的状态转移方程总结一下：

```
base case：

dp[-1][...][0] = dp[...][0][0] = 0

dp[-1][...][1] = dp[...][0][1] = -infinity

状态转移方程：

dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
```

读者可能会问，这个数组索引是 -1 怎么编程表示出来呢，负无穷怎么表示呢？这都是细节问题，有很多方法实现， **最常用的技巧是「索引偏移」** ：我们把 `dp` 数组的大小从 `n` 扩展到 `n + 1` ，让 `dp[0]` 表示 base case（即原来的 `dp[-1]` ）， `dp[i]` 表示原来的第 `i - 1` 天的状态。这样就能避免在循环中处理边界情况了。现在完整的框架已经完成，下面开始具体化。

## 秒杀题目

### 121\. 买卖股票的最佳时机

**第一题，先说力扣第 121 题「 [买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) 」，相当于 `k = 1` 的情况** ：

**121\. 买卖股票的最佳时机** | [力扣](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) | [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

给定一个数组 `prices` ，它的第  `i` 个元素  `prices[i]` 表示一支给定股票第 `i` 天的价格。

你只能选择 **某一天** 买入这只股票，并选择在 **未来的某一个不同的日子** 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 `0` 。

**示例 1：**

```
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
```

**示例 2：**

```
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
```

**提示：**

- `1 <= prices.length <= 10<sup>5</sup>`
- `0 <= prices[i] <= 10<sup>4</sup>`

题目来源： [力扣 121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) 。

直接套状态转移方程，根据 base case，可以做一些化简：

```
dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])

dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]) 

            = max(dp[i-1][1][1], -prices[i])

解释：k = 0 的 base case，所以 dp[i-1][0][0] = 0。

现在发现 k 都是 1，不会改变，即 k 对状态转移已经没有影响了。

可以进行进一步化简去掉所有 k：

dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])

dp[i][1] = max(dp[i-1][1], -prices[i])
```

直接写出代码：

```
int n = prices.length;

int[][] dp = new int[n][2];

for (int i = 0; i < n; i++) {

    dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i]);

    dp[i][1] = Math.max(dp[i-1][1], -prices[i]);

}

return dp[n - 1][0];
```

显然 `i = 0` 时 `dp[i-1]` 是不合法的索引，这是因为我们没有对 base case 进行处理。正确的做法是使用「索引偏移」技巧，让 `dp[0]` 表示还没开始时的 base case， `dp[i]` 表示第 `i - 1` 天的状态：

```
int n = prices.length;

// dp[0] 表示 base case，dp[i] 表示第 i-1 天

int[][] dp = new int[n + 1][2];

// base case: dp[0][0] = 0, dp[0][1] = -infinity

dp[0][0] = 0;

dp[0][1] = Integer.MIN_VALUE;

for (int i = 1; i <= n; i++) {

    // prices[i-1] 是第 i-1 天的股价

    dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i-1]);

    dp[i][1] = Math.max(dp[i-1][1], -prices[i-1]);

}

return dp[n][0];
```

这样 base case 在循环外一次性初始化，循环体内不需要任何条件判断，代码更加简洁清晰。注意一下状态转移方程，新状态只和相邻的一个状态有关，所以可以用前文 [动态规划的降维打击：空间压缩技巧](https://labuladong.online/zh/algo/dynamic-programming/space-optimization/) ，不需要用整个 `dp` 数组，只需要一个变量储存相邻的那个状态就足够了，这样可以把空间复杂度降到 O(1):

```
// 原始版本

int maxProfit_k_1(vector<int>& prices) {

    int n = prices.size();

    // dp[0] 表示 base case，dp[i] 表示第 i-1 天

    vector<vector<int>> dp(n + 1, vector<int>(2));

    dp[0][0] = 0;

    dp[0][1] = INT_MIN;

    for (int i = 1; i <= n; i++) {

        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);

        dp[i][1] = max(dp[i-1][1], -prices[i-1]);

    }

    return dp[n][0];

}

// 空间复杂度优化版本

int maxProfit_k_1(vector<int>& prices) {

    int n = prices.size();

    // base case: dp[-1][0] = 0, dp[-1][1] = -infinity

    int dp_i_0 = 0, dp_i_1 = INT_MIN;

    for (int i = 0; i < n; i++) {

        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])

        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);

        // dp[i][1] = max(dp[i-1][1], -prices[i])

        dp_i_1 = max(dp_i_1, -prices[i]);

    }

    return dp_i_0;

}
```

算法可视化

两种方式都是一样的，不过空间压缩的编程方法简洁很多。后续的题目，你可以对比一下如何把 `dp` 数组的空间优化掉。

### 122\. 买卖股票的最佳时机 II

**第二题，看一下力扣第 122 题「 [买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/) 」，也就是 `k` 为正无穷的情况** ：

给你一个整数数组 `prices` ，其中  `prices[i]` 表示某支股票第 `i` 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 **最多** 只能持有 **一股** 股票。你也可以先购买，然后在 **同一天** 出售。

返回 *你能获得的 **最大** 利润* 。

**示例 1：**

```
输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
最大总利润为 4 + 3 = 7 。
```

**示例 2：**

```
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
最大总利润为 4 。
```

**示例 3：**

```
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0。
```

**提示：**

- `1 <= prices.length <= 3 * 10<sup>4</sup>`
- `0 <= prices[i] <= 10<sup>4</sup>`

题目来源： [力扣 122. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/) 。

题目还专门强调可以在同一天出售，但我觉得这个条件纯属多余，如果当天买当天卖，那利润当然就是 0，这不是和没有进行交易是一样的吗？这道题的特点在于没有给出交易总数 `k` 的限制，也就相当于 `k` 为正无穷。

如果 `k` 为正无穷，那么就可以认为 `k` 和 `k - 1` 是一样的。可以这样改写框架：

```
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

            = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i])

我们发现数组中的 k 已经不会改变了，也就是说不需要记录 k 这个状态了：

dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])

dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
```

直接翻译成代码：

```
// 原始版本

int maxProfit_k_inf(vector<int>& prices) {

    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(2));

    dp[0][0] = 0;

    dp[0][1] = INT_MIN;

    for (int i = 1; i <= n; i++) {

        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);

        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1]);

    }

    return dp[n][0];

}

// 空间复杂度优化版本

int maxProfit_k_inf(vector<int>& prices) {

    int n = prices.size();

    int dp_i_0 = 0, dp_i_1 = INT_MIN;

    for (int i = 0; i < n; i++) {

        int temp = dp_i_0;

        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);

        dp_i_1 = max(dp_i_1, temp - prices[i]);

    }

    return dp_i_0;

}
```

算法可视化

### 309\. 最佳买卖股票时机含冷冻期

**第三题，看力扣第 309 题「 [最佳买卖股票时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/) 」，也就是 `k` 为正无穷，但含有交易冷冻期的情况** ：

**309\. 买卖股票的最佳时机含冷冻期** | [力扣](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

给定一个整数数组 `prices` ，其中第 `prices[i]` 表示第 `*i*` 天的股票价格 。

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

- 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

**注意：** 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1:**

```
输入: prices = [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
```

**示例 2:**

```
输入: prices = [1]
输出: 0
```

**提示：**

- `1 <= prices.length <= 5000`
- `0 <= prices[i] <= 1000`

题目来源： [力扣 309. 买卖股票的最佳时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/) 。

和上一道题一样的，只不过每次 `sell` 之后要等一天才能继续交易，只要把这个特点融入上一题的状态转移方程即可：

```
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])

dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])

解释：第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 。
```

由于状态转移需要 `dp[i-2][0]` ，我们需要偏移 2 个位置，让 `dp[0]` 和 `dp[1]` 都表示 base case， `dp[i]` 表示第 `i - 2` 天的状态：

```
// 原始版本

int maxProfit_with_cool(vector<int>& prices) {

    int n = prices.size();

    // dp[0], dp[1] 表示 base case，dp[i] 表示第 i-2 天

    vector<vector<int>> dp(n + 2, vector<int>(2));

    dp[0][0] = 0;

    dp[0][1] = INT_MIN;

    dp[1][0] = 0;

    dp[1][1] = INT_MIN;

    for (int i = 2; i <= n + 1; i++) {

        // prices[i-2] 是第 i-2 天的股价

        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-2]);

        dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i-2]);

    }

    return dp[n + 1][0];

}

// 空间复杂度优化版本

int maxProfit_with_cool(vector<int>& prices) {

    int n = prices.size();

    int dp_i_0 = 0, dp_i_1 = INT_MIN;

    // 代表 dp[i-2][0]

    int dp_pre_0 = 0;

    for (int i = 0; i < n; i++) {

        int temp = dp_i_0;

        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);

        dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);

        dp_pre_0 = temp;

    }

    return dp_i_0;

}
```

算法可视化

### 714\. 买卖股票的最佳时机含手续费

**第四题，看力扣第 714 题「 [买卖股票的最佳时机含手续费](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) 」，也就是 `k` 为正无穷且考虑交易手续费的情况** ：

**714\. 买卖股票的最佳时机含手续费** | [力扣](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) | [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

给定一个整数数组 `prices` ，其中 `prices[i]` 表示第 `i`  天的股票价格 ；整数  `fee` 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

**注意：** 这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

**示例 1：**

```
输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
```

**示例 2：**

```
输入：prices = [1,3,7,5,10,3], fee = 3
输出：6
```

**提示：**

- `1 <= prices.length <= 5 * 10<sup>4</sup>`
- `1 <= prices[i] < 5 * 10<sup>4</sup>`
- `0 <= fee < 5 * 10<sup>4</sup>`

题目来源： [力扣 714. 买卖股票的最佳时机含手续费](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) 。

每次交易要支付手续费，只要把手续费从利润中减去即可，改写方程：

```
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])

dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)

解释：相当于买入股票的价格升高了。

在第一个式子里减也是一样的，相当于卖出股票的价格减小了。
```

Note

如果直接把 `fee` 放在第一个式子里减，会有一些测试用例无法通过，错误原因是整型溢出而不是思路问题。一种解决方案是把代码中的 `int` 类型都改成 `long` 类型，避免 `int` 的整型溢出。

直接翻译成代码，注意状态转移方程改变后 base case 也要做出对应改变：

```
// 原始版本

int maxProfit_with_fee(vector<int>& prices, int fee) {

    int n = prices.size();

    vector<vector<int>> dp(n + 1, vector<int>(2));

    dp[0][0] = 0;

    dp[0][1] = INT_MIN;

    for (int i = 1; i <= n; i++) {

        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);

        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1] - fee);

    }

    return dp[n][0];

}

// 空间复杂度优化版本

int maxProfit_with_fee(vector<int>& prices, int fee) {

    int n = prices.size();

    int dp_i_0 = 0, dp_i_1 = INT_MIN;

    for (int i = 0; i < n; i++) {

        int temp = dp_i_0;

        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);

        dp_i_1 = max(dp_i_1, temp - prices[i] - fee);

    }

    return dp_i_0;

}
```

算法可视化

### 123\. 买卖股票的最佳时机 III

**第五题，看力扣第 123 题「 [买卖股票的最佳时机 III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/) 」，也就是 `k = 2` 的情况** ：

给定一个数组，它的第 `i` 个元素是一支给定的股票在第 `i` 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 **两笔** 交易。

**注意：** 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1:**

```
输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
```

**示例 2：**

```
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
```

**示例 3：**

```
输入：prices = [7,6,4,3,1] 
输出：0 
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
```

**示例 4：**

```
输入：prices = [1]
输出：0
```

**提示：**

- `1 <= prices.length <= 10<sup>5</sup>`
- `0 <= prices[i] <= 10<sup>5</sup>`

题目来源： [力扣 123. 买卖股票的最佳时机 III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/) 。

`k = 2` 和前面题目的情况稍微不同，因为上面的情况都和 `k` 的关系不太大：要么 `k` 是正无穷，状态转移和 `k` 没关系了；要么 `k = 1` ，跟 `k = 0` 这个 base case 挨得近，最后也没有存在感。

这道题 `k = 2` 和后面要讲的 `k` 是任意正整数的情况中，对 `k` 的处理就凸显出来了，我们直接写代码，边写边分析原因。

```
原始的状态转移方程，没有可化简的地方

dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])

dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
```

按照之前的代码，我们可能想当然这样写代码（错误的）：

```
int k = 2;

int[][][] dp = new int[n][k + 1][2];

for (int i = 0; i < n; i++) {

    if (i - 1 == -1) {

        // 处理 base case

        dp[i][k][0] = 0;

        dp[i][k][1] = -prices[i];

        continue;

    }

    dp[i][k][0] = Math.max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);

    dp[i][k][1] = Math.max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);

}

return dp[n - 1][k][0];
```

为什么错误？我这不是照着状态转移方程写的吗？

还记得前面总结的「穷举框架」吗？就是说我们必须穷举所有状态。其实我们之前的解法，都在穷举所有状态，只是之前的题目中 `k` 都被化简掉了。

比如说第一题， `k = 1` 时的代码框架：

```
int n = prices.length;

int[][] dp = new int[n][2];

for (int i = 0; i < n; i++) {

    dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i]);

    dp[i][1] = Math.max(dp[i-1][1], -prices[i]);

}

return dp[n - 1][0];
```

但当 `k = 2` 时，由于没有消掉 `k` 的影响，所以必须要对 `k` 进行穷举：

```
// 原始版本

int maxProfit_k_2(vector<int>& prices) {

    int max_k = 2, n = prices.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(max_k + 1, vector<int>(2)));

    // base case

    for (int k = 0; k <= max_k; k++) {

        dp[0][k][0] = 0;

        dp[0][k][1] = INT_MIN;

    }

    for (int i = 1; i <= n; i++) {

        for (int k = max_k; k >= 1; k--) {

            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);

            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);

        }

    }

    // 穷举了 n × max_k × 2 个状态，正确

    return dp[n][max_k][0];

}

// 空间复杂度优化版本

int maxProfit_k_2(vector<int>& prices) {

    // base case

    int dp_i10 = 0, dp_i11 = INT_MIN;

    int dp_i20 = 0, dp_i21 = INT_MIN;

    for (int price : prices) {

        dp_i20 = max(dp_i20, dp_i21 + price);

        dp_i21 = max(dp_i21, dp_i10 - price);

        dp_i10 = max(dp_i10, dp_i11 + price);

        dp_i11 = max(dp_i11, -price);

    }

    return dp_i20;

}
```

算法可视化

Note

**这里肯定会有读者疑惑， `k` 的 base case 是 0，按理说应该从 `k = 1, k++` 这样穷举状态 `k` 才对？而且如果你真的这样从小到大遍历 `k` ，提交发现也是可以的** 。

这个疑问很正确，因为我们前文 [动态规划答疑篇](https://labuladong.online/zh/algo/dynamic-programming/faq-summary/) 有介绍 `dp` 数组的遍历顺序是怎么确定的，主要是根据 base case，以 base case 为起点，逐步向结果靠近。

但为什么我从大到小遍历 `k` 也可以正确提交呢？因为你注意看， `dp[i][k][..]` 不会依赖 `dp[i][k - 1][..]` ，而是依赖 `dp[i - 1][k - 1][..]` ，而 `dp[i - 1][..][..]` ，都是已经计算出来的，所以不管你是 `k = max_k, k--` ，还是 `k = 1, k++` ，都是可以得出正确答案的。

那为什么我使用 `k = max_k, k--` 的方式呢？因为这样符合语义：

你买股票，初始的「状态」是什么？应该是从第 0 天开始，而且还没有进行过买卖，所以最大交易次数限制 `k` 应该是 `max_k` ；而随着「状态」的推移，你会进行交易，那么交易次数上限 `k` 应该不断减少，这样一想， `k = max_k, k--` 的方式是比较合乎实际场景的。

当然，这里 `k` 取值范围比较小，所以也可以不用 for 循环，直接把 k = 1 和 2 的情况全部列举出来也可以，上面代码的空间优化版本就是这样做的。有状态转移方程和含义明确的变量名指导，相信你很容易看懂。其实我们可以故弄玄虚，把上述四个变量换成 `a, b, c, d` 。这样当别人看到你的代码时就会大惊失色，对你肃然起敬。

### 188\. 买卖股票的最佳时机 IV

第六题，看力扣第 188 题「 [买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/) 」，即 `k` 可以是题目给定的任何数的情况：

给你一个整数数组 `prices` 和一个整数 `k` ，其中 `prices[i]` 是某支给定的股票在第 `i` 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 `k` 笔交易。也就是说，你最多可以买 `k` 次，卖 `k` 次。

**注意：** 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1：**

```
输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
```

**示例 2：**

```
输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
```

**提示：**

- `1 <= k <= 100`
- `1 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

题目来源： [力扣 188. 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/) 。

有了上一题 `k = 2` 的铺垫，这题应该和上一题的第一个解法没啥区别，你把上一题的 `k = 2` 换成题目输入的 `k` 就行了。

但试一下发现会出一个内存超限的错误，原来是传入的 `k` 值会非常大， `dp` 数组太大了。那么现在想想，交易次数 `k` 最多有多大呢？

一次交易由买入和卖出构成，至少需要两天。所以说有效的限制 `k` 应该不超过 `n/2` ，如果超过，就没有约束作用了，相当于 `k` 没有限制的情况，而这种情况是之前解决过的。

所以我们可以直接把之前的代码重用：

```
int maxProfit_k_any(int max_k, vector<int>& prices) {

    int n = prices.size();

    if (n <= 0) {

        return 0;

    }

    if (max_k > n / 2) {

        // 复用 maxProfit_k_inf 函数

        return maxProfit_k_inf(prices);

    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(max_k + 1, vector<int>(2)));

    // base case

    for (int k = 0; k <= max_k; k++) {

        dp[0][k][0] = 0;

        dp[0][k][1] = INT_MIN;

    }

    for (int i = 1; i <= n; i++) {

        for (int k = max_k; k >= 1; k--) {

            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);

            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);

        }

    }

    return dp[n][max_k][0];

}
```

算法可视化

至此，6 道题目通过一个状态转移方程全部解决。

## 万法归一

如果你能看到这里，已经可以给你鼓掌了，初次理解如此复杂的动态规划问题想必消耗了你不少的脑细胞，不过这是值得的，股票系列问题已经属于动态规划问题中较困难的了，如果这些题你都能搞懂，试问，其他那些虾兵蟹将又何足道哉？

**现在你已经过了九九八十一难中的前八十难，最后我还要再难为你一下，请你实现如下函数** ：

```
int maxProfit_all_in_one(int max_k, int[] prices, int cooldown, int fee);
```

输入股票价格数组 `prices` ，你最多进行 `max_k` 次交易，每次交易需要额外消耗 `fee` 的手续费，而且每次交易之后需要经过 `cooldown` 天的冷冻期才能进行下一次交易，请你计算并返回可以获得的最大利润。

怎么样，有没有被吓到？如果你直接给别人出一道这样的题目，估计对方要当场吐血，不过我们这样一步步做过来，你应该很容易发现这道题目就是之前我们探讨的几种情况的组合体嘛。

所以，我们只要把之前实现的几种代码掺和到一块， **在 base case 和状态转移方程中同时加上 `cooldown` 和 `fee` 的约束就行了** 。

由于状态转移需要 `dp[i-cooldown-1]` ，我们需要偏移 `cooldown + 1` 个位置：

```
// 同时考虑交易次数的限制、冷冻期和手续费

int maxProfit_all_in_one(int max_k, vector<int>& prices, int cooldown, int fee) {

    int n = prices.size();

    if (n <= 0) {

        return 0;

    }

    if (max_k > n / 2) {

        // 交易次数 k 没有限制的情况

        return maxProfit_k_inf(prices, cooldown, fee);

    }

    // 偏移量为 cooldown + 1，确保能访问到 dp[i - cooldown - 1]

    int offset = cooldown + 1;

    vector<vector<vector<int>>> dp(n + offset, vector<vector<int>>(max_k + 1, vector<int>(2)));

    // base case：前 offset 行都是 base case

    for (int i = 0; i < offset; i++) {

        for (int k = 0; k <= max_k; k++) {

            dp[i][k][0] = 0;

            dp[i][k][1] = INT_MIN;

        }

    }

    for (int i = offset; i < n + offset; i++) {

        for (int k = max_k; k >= 1; k--) {

            // prices[i - offset] 是第 i-offset 天的股价

            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i - offset]);

            // 同时考虑 cooldown 和 fee

            dp[i][k][1] = max(dp[i-1][k][1], dp[i - cooldown - 1][k-1][0] - prices[i - offset] - fee);

        }

    }

    return dp[n + offset - 1][max_k][0];

}

// k 无限制，包含手续费和冷冻期

int maxProfit_k_inf(vector<int>& prices, int cooldown, int fee) {

    int n = prices.size();

    int offset = cooldown + 1;

    vector<vector<int>> dp(n + offset, vector<int>(2));

    // base case：前 offset 行都是 base case

    for (int i = 0; i < offset; i++) {

        dp[i][0] = 0;

        dp[i][1] = INT_MIN;

    }

    for (int i = offset; i < n + offset; i++) {

        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i - offset]);

        // 同时考虑 cooldown 和 fee

        dp[i][1] = max(dp[i-1][1], dp[i - cooldown - 1][0] - prices[i - offset] - fee);

    }

    return dp[n + offset - 1][0];

}
```

你可以用这个 `maxProfit_all_in_one` 函数去完成之前讲的 6 道题目，因为我们无法对 `dp` 数组进行优化，所以执行效率上不是最优的，但正确性上肯定是没有问题的。

最后总结一下吧，本文给大家讲了如何通过状态转移的方法解决复杂的问题，用一个状态转移方程秒杀了 6 道股票买卖问题，现在回头去看，其实也不算那么可怕对吧？

关键就在于列举出所有可能的「状态」，然后想想怎么穷举更新这些「状态」。一般用一个多维 `dp` 数组储存这些状态，从 base case 开始向后推进，推进到最后的状态，就是我们想要的答案。想想这个过程，你是不是有点理解「动态规划」这个名词的意义了呢？

具体到股票买卖问题，我们发现了三个状态，使用了一个三维数组，无非还是穷举 + 更新，不过我们可以说的高大上一点，这叫「三维 DP」，听起来是不是很厉害？

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表