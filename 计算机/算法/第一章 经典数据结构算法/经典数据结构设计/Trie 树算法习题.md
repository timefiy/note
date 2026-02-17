---
title: Trie 树算法习题
source: https://labuladong.online/zh/algo/problem-set/trie/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文讲解 力扣/LeetCode 上的前缀树算法经典习题，同时给出 Java/Python/Go/JavaScript/C++ 代码实现。
tags:
  - clippings
---
前置知识

阅读本文前，你需要先学习：

- [Trie 树原理](https://labuladong.online/zh/algo/data-structure-basic/trie-map-basic/)
- [TrieMap/TrieSet 代码实现](https://labuladong.online/zh/algo/data-structure/trie-implement/)

有了 `TrieMap` 和 `TrieSet` ，力扣上所有前缀树相关的题目都可以直接套用了，下面我举几个题目实践一下。

可以尝试优化

**首先，前文 [TrieMap/TrieSet 代码实现](https://labuladong.online/zh/algo/data-structure/trie-implement/) 给出的 `TrieMap/TrieSet` 执行效率在具体的题目里面肯定是有优化空间的** 。

比如力扣前缀树相关题目的输入都被限制在小写英文字母 `a-z` ，所以 `TrieNode` 其实不用维护一个大小为 256 的 `children` 数组，大小设置为 26 就够了，可以减小时间和空间上的复杂度。

另外，之前给出的 Java/cpp 代码带有泛型，在做算法题的时候其实不需要，去掉泛型也可以获得一定的效率提升。

### 208\. 实现 Trie (前缀树)

先看下力扣第 208 题「 [实现前缀树](https://leetcode.cn/problems/implement-trie-prefix-tree/) 」：

**208\. 实现 Trie (前缀树)** | [力扣](https://leetcode.cn/problems/implement-trie-prefix-tree/) | [LeetCode](https://leetcode.com/problems/implement-trie-prefix-tree/)

**[Trie](https://baike.baidu.com/item/%E5%AD%97%E5%85%B8%E6%A0%91/9825209?fr=aladdin)** （发音类似 "try"）或者说 **前缀树** 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

- `Trie()` 初始化前缀树对象。
- `void insert(String word)` 向前缀树中插入字符串 `word` 。
- `boolean search(String word)` 如果字符串 `word` 在前缀树中，返回 `true` （即，在检索之前已经插入）；否则，返回 `false` 。
- `boolean startsWith(String prefix)` 如果之前已经插入的字符串 `word` 的前缀之一为 `prefix` ，返回 `true` ；否则，返回 `false` 。

**示例：**

```
输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
```

**提示：**

- `1 <= word.length, prefix.length <= 2000`
- `word` 和 `prefix` 仅由小写英文字母组成
- `insert` 、 `search` 和 `startsWith` 调用次数 **总计** 不超过 `3 * 10<sup>4</sup>` 次

题目来源： [力扣 208. 实现 Trie (前缀树)](https://leetcode.cn/problems/implement-trie-prefix-tree/) 。

题目让我们实现的几个函数其实就是 `TrieSet` 的部分 API，所以直接封装一个 `TrieSet` 就能解决这道题了：

```
class Trie {

public:

    // 直接封装 TrieSet

    TrieSet set;

    

    // 插入一个元素

    void insert(string word) {

        set.add(word);

    }

    

    // 判断元素是否在集合中

    bool search(string word) {

        return set.contains(word);

    }

    

    // 判断集合中是否有前缀为 prefix 的元素

    bool startsWith(string prefix) {

        return set.hasKeyWithPrefix(prefix);

    }

};

// 见上文

class TrieSet {};
```

### 648\. 单词替换

接下来看下力扣第 648 题「 [单词替换](https://leetcode.cn/problems/replace-words/) 」：

**648\. 单词替换** | [力扣](https://leetcode.cn/problems/replace-words/) | [LeetCode](https://leetcode.com/problems/replace-words/)

在英语中，我们有一个叫做 **词根** (root) 的概念，可以词根 **后面** 添加其他一些词组成另一个较长的单词——我们称这个词为 **衍生词** (**derivative**)。例如，词根  `help` ，跟随着 **继承** 词 `"ful"` ，可以形成新的单词 `"helpful"` 。

现在，给定一个由许多 **词根** 组成的词典 `dictionary` 和一个用空格分隔单词形成的句子 `sentence` 。你需要将句子中的所有 **衍生词** 用 **词根** 替换掉。如果 **衍生词** 有许多可以形成它的 **词根** ，则用 **最短** 的 **词根** 替换它。

你需要输出替换之后的句子。

**示例 1：**

```
输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"
```

**示例 2：**

```
输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
输出："a a b c"
```

**提示：**

- `1 <= dictionary.length <= 1000`
- `1 <= dictionary[i].length <= 100`
- `dictionary[i]` 仅由小写字母组成。
- `1 <= sentence.length <= 10<sup>6</sup>`
- `sentence` 仅由小写字母和空格组成。
- `sentence` 中单词的总量在范围 `[1, 1000]` 内。
- `sentence` 中每个单词的长度在范围 `[1, 1000]` 内。
- `sentence` 中单词之间由一个空格隔开。
- `sentence` 没有前导或尾随空格。

题目来源： [力扣 648. 单词替换](https://leetcode.cn/problems/replace-words/) 。

现在你学过 Trie 树结构，应该可以看出来这题就在考察最短前缀问题。

所以可以把输入的词根列表 `dict` 存入 `TrieSet` ，然后直接复用我们实现的 `shortestPrefixOf` 函数就行了：

```
string replaceWords(vector<string>& dict, string sentence) {

    // 先将词根都存入 TrieSet

    TrieSet set;

    for (const string& key : dict) {

        set.add(key);

    }

    

    string result;

    string word;

    istringstream iss(sentence);

    bool first = true;

    

    // 处理句子中的单词

    while (iss >> word) {

        if (!first) {

            // 添加单词之间的空格

            result += ' ';

        }

        first = false;

        

        // 在 Trie 树中搜索最短词根（最短前缀）

        string prefix = set.shortestPrefixOf(word);

        if (!prefix.empty()) {

            // 如果搜索到了，改写为词根

            result += prefix;

        } else {

            // 否则，原样放回

            result += word;

        }

    }

    

    return result;

}

// 见上文

class TrieSet {};

// 见上文

class TrieMap {};
```

### 211\. 添加与搜索单词 - 数据结构设计

继续看力扣第 211 题「 [添加与搜索单词 - 数据结构设计](https://leetcode.cn/problems/design-add-and-search-words-data-structure/) 」：

**211\. 添加与搜索单词 - 数据结构设计** | [力扣](https://leetcode.cn/problems/design-add-and-search-words-data-structure/) | [LeetCode](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

实现词典类 `WordDictionary` ：

- `WordDictionary()` 初始化词典对象
- `void addWord(word)` 将 `word` 添加到数据结构中，之后可以对它进行匹配
- `bool search(word)` 如果数据结构中存在字符串与 `word` 匹配，则返回 `true` ；否则，返回  `false` 。 `word` 中可能包含一些 `'.'` ，每个 `.` 都可以表示任何一个字母。

**示例：**

```
输入：
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
输出：
[null,null,null,null,false,true,true,true]

解释：
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // 返回 False
wordDictionary.search("bad"); // 返回 True
wordDictionary.search(".ad"); // 返回 True
wordDictionary.search("b.."); // 返回 True
```

**提示：**

- `1 <= word.length <= 25`
- `addWord` 中的 `word` 由小写英文字母组成
- `search` 中的 `word` 由 '.' 或小写英文字母组成
- 最多调用 `10<sup>4</sup>` 次 `addWord` 和 `search`

题目来源： [力扣 211. 添加与搜索单词 - 数据结构设计](https://leetcode.cn/problems/design-add-and-search-words-data-structure/) 。

这道题的考点就在于这个 `search` 函数进行通配符匹配，其实就是我们给 `TrieSet` 实现的 `hasKeyWithPattern` 方法，直接套就行了：

```
class WordDictionary {

public:

    TrieSet set;

    

    // 在 TrieSet 中添加元素

    void addWord(string word) {

        set.add(word);

    }

    

    // 通配符匹配元素

    bool search(string word) {

        return set.hasKeyWithPattern(word);

    }

};

// 见上文

class TrieSet {};

// 见上文

class TrieMap {};
```

上面列举的这几道题用的都是 `TrieSet` ，下面来看看 `TrieMap` 的题目。

### 1804\. 实现一个 Trie (前缀树 II)

力扣第 1804 题「 [实现前缀树 II](https://leetcode.cn/problems/implement-trie-ii-prefix-tree/) 」可以直接用 `TrieMap` ，每个插入的 `word` 就是键，插入的次数就是对应的值，然后复用 `TrieMap` 的 API 就能实现题目要求的这些函数：

```
class Trie {

public:

    // 封装我们实现的 TrieMap

    TrieMap<int> map;

    

    // 插入 word 并记录插入次数

    void insert(string word) {

        if (!map.containsKey(word)) {

            map.put(word, 1);

        } else {

            map.put(word, map.get(word) + 1);

        }

    }

    

    // 查询 word 插入的次数

    int countWordsEqualTo(string word) {

        if (!map.containsKey(word)) {

            return 0;

        }

        return map.get(word);

    }

    

    // 累加前缀为 prefix 的键的插入次数总和

    int countWordsStartingWith(string prefix) {

        int res = 0;

        for (const string& key : map.keysWithPrefix(prefix)) {

            res += map.get(key);

        }

        return res;

    }

    

    // word 的插入次数减一

    void erase(string word) {

        int freq = map.get(word);

        if (freq - 1 == 0) {

            map.remove(word);

        } else {

            map.put(word, freq - 1);

        }

    }

};

// 见上文

template <typename V>

class TrieMap {};
```

### 677\. 键值映射

反正都是直接套模板，也没什么意思，再看最后一道题目吧，这是力扣第 677 题「 [键值映射](https://leetcode.cn/problems/map-sum-pairs/) 」：

**677\. 键值映射** | [力扣](https://leetcode.cn/problems/map-sum-pairs/) | [LeetCode](https://leetcode.com/problems/map-sum-pairs/)

设计一个 map ，满足以下几点:

- 字符串表示键，整数表示值
- 返回具有前缀等于给定字符串的键的值的总和

实现一个 `MapSum` 类：

- `MapSum()` 初始化 `MapSum` 对象
- `void insert(String key, int val)` 插入 `key-val` 键值对，字符串表示键 `key` ，整数表示值 `val` 。如果键 `key` 已经存在，那么原来的键值对  `key-value` 将被替代成新的键值对。
- `int sum(string prefix)` 返回所有以该前缀 `prefix` 开头的键 `key` 的值的总和。

**示例 1：**

```
输入：
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
输出：
[null, null, 3, null, 5]

解释：
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // 返回 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // 返回 5 (apple + app = 3 + 2 = 5)
```

**提示：**

- `1 <= key.length, prefix.length <= 50`
- `key` 和 `prefix` 仅由小写英文字母组成
- `1 <= val <= 1000`
- 最多调用 `50` 次 `insert` 和 `sum`

题目来源： [力扣 677. 键值映射](https://leetcode.cn/problems/map-sum-pairs/) 。

这道题还是标准的 `TrieMap` 的应用，直接看代码吧：

```
class MapSum {

public:

    // 封装我们实现的 TrieMap

    TrieMap<int> map;

    

    // 插入键值对

    void insert(string key, int val) {

        map.put(key, val);

    }

    

    // 累加所有前缀为 prefix 的键的值

    int sum(string prefix) {

        vector<string> keys = map.keysWithPrefix(prefix);

        int res = 0;

        for (const string& key : keys) {

            res += map.get(key);

        }

        return res;

    }

};

// 见上文

template <typename V>

class TrieMap {};
```

Trie 树这种数据结构的实现原理和题目实践就讲完了，如果你能够看到这里，真得给你鼓掌。纸上得来终觉浅，绝知此事要躬行，我建议最好亲手实现一遍上面的代码，去把题目刷一遍，才能对 Trie 树有更深入的理解。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表