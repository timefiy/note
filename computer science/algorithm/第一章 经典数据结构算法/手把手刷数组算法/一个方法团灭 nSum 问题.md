---
title: 一个方法团灭 nSum 问题
source: https://labuladong.online/zh/algo/practice-in-action/nsum/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文讲解如何利用排序和双指针技巧归纳一套统一的代码框架，解决力扣/LeetCode 上的所有 nSum 问题，同时给出 Java/Python/Go/JavaScript/C++ 代码实现。
tags:
  - clippings
---
读完本文，你不仅学会了算法套路，还可以顺便解决如下题目：

| LeetCode | 力扣 | 难度 |
| --- | --- | --- |
| [1\. Two Sum](https://leetcode.com/problems/two-sum/) | [1\. 两数之和](https://leetcode.cn/problems/two-sum/) |  |
| [167\. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [167\. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/) |  |
| [15\. 3Sum](https://leetcode.com/problems/3sum/) | [15\. 三数之和](https://leetcode.cn/problems/3sum/) |  |
| [18\. 4Sum](https://leetcode.com/problems/4sum/) | [18\. 四数之和](https://leetcode.cn/problems/4sum/) |  |

前置知识

阅读本文前，你需要先学习：

- [数组双指针技巧汇总](https://labuladong.online/zh/algo/essential-technique/array-two-pointers-summary/)

经常刷力扣的读者肯定知道鼎鼎有名的 `twoSum` 问题，不过除了 `twoSum` 问题，力扣上面还有 `3Sum` ， `4Sum` 问题，以后如果想出个 `5Sum` ， `6Sum` 也不是不可以。

总结来说，这类 `nSum` 问题就是给你输入一个数组 `nums` 和一个目标和 `target` ，让你从 `nums` 选择 `n` 个数，使得这些数字之和为 `target` 。

那么，对于这种问题有没有什么好办法用套路解决呢？本文就由浅入深，层层推进，用一个函数来解决所有 `nSum` 类型的问题。

## 一、twoSum 问题

我先来编一道 twoSum 题目：

如果假设输入一个数组 `nums` 和一个目标和 `target` ， **请你返回 `nums` 中能够凑出 `target` 的两个元素的值** ，比如输入 `nums = [1,3,5,6], target = 9` ，那么算法返回两个元素 `[3,6]` 。可以假设只有且仅有一对儿元素可以凑出 `target` 。

我们可以先对 `nums` 排序，然后利用前文 [双指针技巧](https://labuladong.online/zh/algo/essential-technique/array-two-pointers-summary/) 写过的左右双指针技巧，从两端相向而行就行了：

```
std::vector<int> twoSum(std::vector<int>& nums, int target) {

    // 先对数组排序

    std::sort(nums.begin(), nums.end());

    // 左右指针

    int lo = 0, hi = nums.size() - 1;

    while (lo < hi) {

        int sum = nums[lo] + nums[hi];

        // 根据 sum 和 target 的比较，移动左右指针

        if (sum < target) {

            lo++;

        } else if (sum > target) {

            hi--;

        } else if (sum == target) {

            return {nums[lo], nums[hi]};

        }

    }

    return {};

}
```

这样就可以解决这个问题，力扣第 1 题「 [两数之和](https://leetcode.cn/problems/two-sum/) 」和力扣第 167 题「 [两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/) 」稍加修改就可以用类似的思路解决，我这里就不写了。

不过我要继续魔改题目，把这个题目变得更泛化，更困难一点：

**`nums` 中可能有多对儿元素之和都等于 `target` ，请你的算法返回所有和为 `target` 的元素对儿，其中不能出现重复** 。

函数签名如下：

```
vector<vector<int>> twoSumTarget(vector<int>& nums, int target);
```

比如说输入为 `nums = [1,3,1,2,2,3], target = 4` ，那么算法返回的结果就是： `[[1,3],[2,2]]` （注意，我要求返回元素，而不是索引）。

对于修改后的问题，关键难点是现在可能有多个和为 `target` 的数对儿，还不能重复，比如上述例子中 `[1,3]` 和 `[3,1]` 就算重复，只能算一次。

首先，基本思路肯定还是排序加双指针：

但是，这样实现会造成重复的结果，比如说 `nums = [1,1,1,2,2,3,3], target = 4` ，得到的结果中 `[1,3]` 肯定会重复。

出问题的地方在于 `sum == target` 条件的 if 分支，当给 `res` 加入一次结果后， `lo` 和 `hi` 不仅应该相向而行，而且应该跳过所有重复的元素：

![](https://labuladong.online/images/algo/nSum/1.jpeg)

所以，可以对双指针的 while 循环做出如下修改：

这样就可以保证一个答案只被添加一次，重复的结果都会被跳过，可以得到正确的答案。不过，受这个思路的启发，其实前两个 if 分支也是可以做一点效率优化，跳过相同的元素：

这样，一个通用化的 `twoSum` 函数就写出来了，请确保你理解了该算法的逻辑，我们后面解决 `3Sum` 和 `4Sum` 的时候会复用这个函数。

这个函数的时间复杂度非常容易看出来，双指针操作的部分虽然有那么多 while 循环，但是时间复杂度还是 $O(N)$ ，而排序的时间复杂度是 $O(NlogN)$ ，所以这个函数的时间复杂度是 $O(NlogN)$ 。

## 二、3Sum 问题

这是力扣第 15 题「 [三数之和](https://leetcode.cn/problems/3sum/) 」：

**15\. 三数之和** | [力扣](https://leetcode.cn/problems/3sum/) | [LeetCode](https://leetcode.com/problems/3sum/)

给你一个整数数组 `nums` ，判断是否存在三元组 `[nums[i], nums[j], nums[k]]` 满足 `i != j` 、 `i != k` 且 `j != k` ，同时还满足 `nums[i] + nums[j] + nums[k] == 0` 。请你返回所有和为 `0` 且不重复的三元组。

**注意：** 答案中不可以包含重复的三元组。

**示例 1：**

```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
```

**示例 2：**

```
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
```

**示例 3：**

```
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
```

**提示：**

- `3 <= nums.length <= 3000`
- `-10<sup>5</sup> <= nums[i] <= 10<sup>5</sup>`

题目来源： [力扣 15. 三数之和](https://leetcode.cn/problems/3sum/) 。

题目就是让我们找 `nums` 中和为 0 的三个元素，返回所有可能的三元组（triple），函数签名如下：

这样，我们再泛化一下题目，不要光和为 0 的三元组了，计算和为 `target` 的三元组吧，同上面的 `twoSum` 一样，也不允许重复的结果：

这个问题怎么解决呢？ **很简单，穷举呗** 。现在我们想找和为 `target` 的三个数字，那么对于第一个数字，可能是什么？ `nums` 中的每一个元素 `nums[i]` 都有可能！

那么，确定了第一个数字之后，剩下的两个数字可以是什么呢？其实就是和为 `target - nums[i]` 的两个数字呗，那不就是 `twoSum` 函数解决的问题么？

可以直接写代码了，需要把 `twoSum` 函数稍作修改即可复用：

需要注意的是，类似 `twoSum` ， `3Sum` 的结果也可能重复，比如输入是 `nums = [1,1,1,2,3], target = 6` ，结果就会重复，可能选出多个 `[1,2,3]` 。

**避免重复的关键点在于，不能让第一个数重复，至于后面的两个数，我们复用的 `twoSumTarget` 函数会保证它们不重复** 。所以代码中必须用一个 while 循环来保证 `3Sum` 中第一个元素不重复。

至此， `3Sum` 问题就解决了，时间复杂度不难算，排序的复杂度为 $O(NlogN)$ ， `twoSumTarget` 函数中的双指针操作为 $O(N)$ ， `threeSumTarget` 函数在 for 循环中调用 `twoSumTarget` 所以总的时间复杂度就是 $O(NlogN + N^2) = O(N^2)$ 。

## 三、4Sum 问题

这是力扣第 18 题「 [四数之和](https://leetcode.cn/problems/4sum/) 」：

**18\. 四数之和** | [力扣](https://leetcode.cn/problems/4sum/) | [LeetCode](https://leetcode.com/problems/4sum/)

给你一个由 `n` 个整数组成的数组  `nums` ，和一个目标值 `target` 。请你找出并返回满足下述全部条件且 **不重复** 的四元组 `[nums[a], nums[b], nums[c], nums[d]]` （若两个四元组元素一一对应，则认为两个四元组重复）：

- `0 <= a, b, c, d < n`
- `a` 、 `b` 、 `c` 和 `d` **互不相同**
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

你可以按 **任意顺序** 返回答案 。

**示例 1：**

```
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**示例 2：**

```
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
```

**提示：**

- `1 <= nums.length <= 200`
- `-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>`
- `-10<sup>9</sup> <= target <= 10<sup>9</sup>`

题目来源： [力扣 18. 四数之和](https://leetcode.cn/problems/4sum/) 。

函数签名如下：

都到这份上了， `4Sum` 完全就可以用相同的思路：穷举第一个数字，然后调用 `3Sum` 函数计算剩下三个数，最后组合出和为 `target` 的四元组。

这样，按照相同的套路， `4Sum` 问题就解决了，时间复杂度的分析和之前类似，for 循环中调用了 `threeSumTarget` 函数，所以总的时间复杂度就是 $O(N^3)$ 。

注意我们把 `threeSumTarget` 函数签名中的 `target` 变量设置为 `long` 类型，因为本题说了 `nums[i]` 和 `target` 的取值都是 `[-10^9, 10^9]` ， `int` 类型的话会造成溢出。

## 四、100Sum 问题？

在 LeetCode 上， `4Sum` 就到头了， **但是回想刚才写 `3Sum` 和 `4Sum` 的过程，实际上是遵循相同的模式的** 。我相信你只要稍微修改一下 `4Sum` 的函数就可以复用并解决 `5Sum` 问题，然后解决 `6Sum` 问题……

那么，如果我让你求 `100Sum` 问题，怎么办呢？其实我们可以观察上面这些解法，统一出一个 `nSum` 函数：

嗯，看起来很长，实际上就是把之前的题目解法合并起来了， `n == 2` 时是 `twoSum` 的双指针解法， `n > 2` 时就是穷举第一个数字，然后递归调用计算 `(n-1)Sum` ，组装答案。

根据之前几道题的时间复杂度可以推算，本函数的时间复杂度应该是 $O(N^(n-1))$ ， `N` 为数组的长度， `n` 为组成和的数字的个数。

**需要注意的是，调用这个 `nSumTarget` 函数之前一定要先给 `nums` 数组排序** ，因为 `nSumTarget` 是一个递归函数，如果在 `nSumTarget` 函数里调用排序函数，那么每次递归都会进行没有必要的排序，效率会非常低。

比如说现在我们写 LeetCode 上的 `4Sum` 问题：

算法可视化

再比如 LeetCode 的 `3Sum` 问题，找 `target == 0` 的三元组：

算法可视化

那么，如果让你计算 `100Sum` 问题，直接调用这个函数就完事儿了。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表