---
title: 用链表加强哈希表（LinkedHashMap）
source: https://labuladong.online/zh/algo/data-structure-basic/hashtable-with-linked-list/
author:
  - "[[../../../../author/labuladong]]"
published:
created: 2026-02-06
description: 本文将介绍哈希链表（LinkedHashMap）的原理、特性，支持哈希表的键按照插入顺序排序，并给出 Java/C++/Python/Golang/JavaScript 的代码实现。
tags:
  - clippings
---
前置知识

阅读本文前，你需要先学习：

- [哈希表核心原理](https://labuladong.online/zh/algo/data-structure-basic/hashmap-basic/)

前文 [哈希表原理](https://labuladong.online/zh/algo/data-structure-basic/hashmap-basic/) 从原理上分析了，不能依赖哈希表遍历 `key` 的顺序，即哈希表中的 `key` 是无序的。

但结合实际的编程经验，你可能会有些疑问。

比如熟悉 Java 的读者可能知道，Java 标准库提供的 `LinkedHashMap` 就可以 **按照键的插入顺序来遍历** 。例如下面这段简单的代码：

```
import java.util.LinkedHashMap;

public class Main {

    public static void main(String[] args) {

        LinkedHashMap<String, Integer> map = new LinkedHashMap<>();

        map.put("a", 1);

        map.put("b", 2);

        map.put("c", 3);

        System.out.println(map.keySet()); // [a, b, c]

        map.put("y", 4);

        System.out.println(map.keySet()); // [a, b, c, y]

        map.put("d", 5);

        System.out.println(map.keySet()); // [a, b, c, y, d]

    }

}
```

无论你插入多少键， `keySet` 方法返回的所有键都是按照插入顺序排列，感觉就好像在向数组尾部追加元素一样。这怎么可能呢？

如果你熟悉 Golang，你会发现一个更神奇的现象。比如下面这段测试代码：

```
package main

import (

    "fmt"

)

func main() {

    // 初始化 map

    myMap := map[string]int{

        "1":  1,

        "2": 2,

        "3":  3,

        "4": 4,

        "5":  5,

    }

    // 定义遍历 map 的函数

    printMapKeys := func(m map[string]int) {

        for key := range m {

            fmt.Print(key, " ")

        }

        fmt.Println()

    }

    // 多次遍历 map，观察键的顺序

    printMapKeys(myMap)

    printMapKeys(myMap)

    printMapKeys(myMap)

    printMapKeys(myMap)

}

// 我运行的结果如下：

// 1 2 3 4 5

// 5 1 2 3 4

// 2 3 4 5 1

// 1 2 3 4 5
```

也就是说，它每次遍历的顺序都是随机。但是按照前文 [哈希表原理](https://labuladong.online/zh/algo/data-structure-basic/hashmap-basic/) 所说，虽然哈希表的键是无序的，但是没有对哈希表做任何操作，遍历得到的结果应该不会变才对，Golang 的 map 每次遍历的顺序咋都不一样？这也太离谱了吧？

你可以先自己思考下原因，下面我给出答案。

点击查看答案

**先说 Golang 吧，每次遍历都乱序的原因就是，它故意的** 。

这个原因属实是让人有些哭笑不得，Golang 为了防止开发者依赖哈希表的遍历顺序，所以每次遍历都故意返回不同的顺序，可谓用心良苦。也可以从侧面看出，确实不少开发者没了解过哈希表的基本原理。

我们不妨进一步想想，它是怎么打乱顺序的呢？真是随机打乱吗？

其实不是，你仔细看看，它这个乱序是有规律的。有没有想起前面讲过的 [环形数组](https://labuladong.online/zh/algo/data-structure-basic/cycle-array/) ？

```
| 1 2 3 4 5

5 | 1 2 3 4

2 3 4 5 | 1

| 1 2 3 4 5
```

看出来没有？如果不触发扩缩容的话，实际上它的遍历顺序应该也是固定的，只不过它不是每次都从底层 `table` 数组的头部开始，而是从一个随机的位置开始，然后利用环形数组技巧遍历整个 `table` 数组，这样就能保证多次遍历的结果具有随机性，同时又不至于为了随机性而牺牲太多性能。

再说 Java 的 `LinkedHashMap` ， **它能让所有键按照插入顺序排列，是因为它把标准的哈希表和链表结合起来，组成了一种新的数据结构：哈希链表** 。

这种数据结构兼具了哈希表 $O(1)$ 的增删查改效率，同时又可以像数组链表一样保持键的插入顺序。

它是怎么做的呢？下面我会具体讲解。

## 哈希链表（LinkedHashMap）实现思路

我们先明确一下问题。

标准哈希表的键是无序存储在底层的 table 数组中的：

![](https://labuladong.online/images/algo/ds-basic/hash-collision-with-key.jpeg)

你光看这个图，看不出来这些键是按什么顺序插入的，且一旦触发扩缩容，这键的位置又会改变。

我们现在希望在不改变哈希表增删查改复杂度的前提下，能够按照插入顺序来访问所有键，且不受扩缩容影响。

那么一个最直接的思路就是，我想办法把这些键值对都用类似链表节点的结构串联起来，持有一个头尾结点 `head, tail` 的引用，每次把新的键插入 table 数组时，同时把这个键插入链表的尾部。

这样一来，只要我从头结点 `head` 开始遍历链表，就能按照插入顺序访问所有键了：

![](https://labuladong.online/images/algo/ds-basic/hash-with-link.jpg)

我们可以清楚地看出，键的插入顺序是 `k2, k4, k5, k3, k1` 。

发挥抽象思维，不要陷入细节

但肯定有读者会绕晕：之前 [拉链法实现哈希表](https://labuladong.online/zh/algo/data-structure-basic/hashtable-chaining/) 不就是用链表解决哈希冲突的吗？现在相当于在链表上再套一层链表？这咋实现啊？

所以我在本站的开篇就说，要有抽象能力。你看所有数据结构，本质上就是在数组、链表这两种基本结构上雕花，但即便如此，多套几层你也晕了。

如果产生这样的疑问，是因为你脑子里全是前两章讲的拉链法、线性探查法的底层实现原理，陷入细节无法自拔了，是不是这样？

请跳出细节，抽象来看，哈希表本质上就是一个键值映射，链表本质上就是一个顺序存储元素的容器。现在我就是想让这个键值映射中的键按照插入顺序排列，怎么把哈希表和链表结合起来？

答案是这样：

![](https://labuladong.online/images/algo/lru/4.jpg)

假设键和值都是字符串类型，标准的哈希表是这样：

```
HashMap<String, String> map = new HashMap<>();

// 插入键值对

String key = "k1";

String value = "v1";

map.put(key, value);
```

而我们现在给哈希表的值类型套了一层双链表结构：

```
// 双链表节点

class Node {

    String key;

    String value;

    Node prev;

    Node next;

    Node(String key, String value) {

        this.key = key;

        this.value = value;

    }

}

HashMap<String, Node> map = new HashMap<>();

// 插入键值对

String key = "k1";

String value = "v1";

map.put(key, new Node(key, value));

// 这里做了简化，实际实现中还要操作新的链表节点加入链表
```

这样一来，就实现了哈希链表结构：

- 我们还是可以在 $O(1)$ 的时间复杂度内通过键查找到对应的双链表节点，进而找到键对应的值。
- 我们可以在 $O(1)$ 的时间复杂度内插入新的键值对。因为哈希表本身的插入操作时间复杂度是 $O(1)$ ，且双链表头尾的插入操作时间复杂度也是 $O(1)$ 。
- 我们可以在 $O(1)$ 的时间复杂度内删除指定的键值对。因为哈希表本身的删除操作时间复杂度是 $O(1)$ ， **删除给定双链表节点的操作时间复杂度也是 $O(1)$** 。
- 由于链表节点的顺序是插入顺序，那么只要从头结点开始遍历这个链表，就能按照插入顺序访问所有键。

也就是说，我们在不改变标准哈希表的基本操作复杂度的前提下，实现了按照插入顺序访问所有键的需求。

链表的删除操作时间复杂度是 O(1)？

肯定有读者记得，前文 [链表原理](https://labuladong.online/zh/algo/data-structure-basic/linkedlist-basic/) 说过，链表的删除操作时间复杂度是 $O(n)$ 啊，怎么现在又说是 $O(1)$ 了？

实际上我说的已经很严谨了，我这里说的是 **删除给定双链表节点的操作是 $O(1)$** 。

前文我们动手实现链表的时候，我们是删除指定索引的链表节点，时间复杂度确实是 $O(n)$ ，因为要先遍历到这个索引，然后才能开始删除嘛。

但是这里并没有遍历的过程，我们是直接通过哈希表键值映射拿到的这个链表节点，时间复杂度是 $O(1)$ 。

且双链表节点只需进行简单的指针操作即可把自身从链表中删除，时间复杂度是 $O(1)$ ：

```
// 删除给定双链表节点

Node target;

// 在双链表中删除 target 节点

target.prev.next = target.next;

target.next.prev = target.prev;

target.prev = null;

target.next = null;
```

所以哈希链表删除操作的复杂度依然是 $O(1)$ 。

这里需要注意，双链表节点同时拥有前后驱指针，才可以做到 $O(1)$ 时间复杂度的删除操作。单链表节点只有后驱指针，但没有前驱指针，做不到 $O(1)$ 时间复杂度的删除操作。 **所以哈希链表的实现中，只能使用双链表** 。

## 代码实现

明白了哈希链表的原理，直接看代码实现吧，比较简单：

```
#include <iostream>

#include <unordered_map>

#include <vector>

using namespace std;

template <typename K, typename V>

struct Node {

    K key;

    V val;

    Node* next;

    Node* prev;

    Node(K key, V val) : key(key), val(val), next(nullptr), prev(nullptr) {}

};

template <typename K, typename V>

class MyLinkedHashMap {

public:

    MyLinkedHashMap() {

        head = new Node<K, V>(K(), V());

        tail = new Node<K, V>(K(), V());

        head->next = tail;

        tail->prev = head;

    }

    // 析构函数，释放所有节点内存

    ~MyLinkedHashMap() {

        // 释放所有数据节点

        Node<K, V>* current = head->next;

        while (current != tail) {

            Node<K, V>* next = current->next;

            delete current;

            current = next;

        }

        // 释放头尾节点

        delete head;

        delete tail;

    }

    // 禁用拷贝构造和赋值操作，避免浅拷贝问题

    MyLinkedHashMap(const MyLinkedHashMap&) = delete;

    MyLinkedHashMap& operator=(const MyLinkedHashMap&) = delete;

    V get(K key) {

        if (map.find(key) == map.end()) {

            return V();

        }

        return map[key]->val;

    }

    void put(K key, V val) {

        // 若为新插入的节点，则同时插入链表和 map

        if (map.find(key) == map.end()) {

            // 插入新的 Node

            Node<K, V>* node = new Node<K, V>(key, val);

            addLastNode(node);

            map[key] = node;

            return;

        }

        // 若存在，则替换之前的 val

        map[key]->val = val;

    }

    void remove(K key) {

        // 若 key 本不存在，直接返回

        if (map.find(key) == map.end()) {

            return;

        }

        // 若 key 存在，则需要同时在哈希表和链表中删除

        Node<K, V>* node = map[key];

        map.erase(key);

        removeNode(node);

        // 释放节点内存

        delete node;

    }

    bool containsKey(K key) {

        return map.find(key) != map.end();

    }

    vector<K> keys() {

        vector<K> keyList;

        for (Node<K, V>* p = head->next; p != tail; p = p->next) {

            keyList.push_back(p->key);

        }

        return keyList;

    }

    // 获取元素数量

    size_t size() {

        return map.size();

    }

    // 判断是否为空

    bool empty() {

        return map.empty();

    }

private:

    Node<K, V>* head;

    Node<K, V>* tail;

    unordered_map<K, Node<K, V>*> map;

    void addLastNode(Node<K, V>* x) {

        Node<K, V>* temp = tail->prev;

        // temp <-> tail

        x->next = tail;

        x->prev = temp;

        temp->next = x;

        tail->prev = x;

    }

    void removeNode(Node<K, V>* x) {

        Node<K, V>* prev = x->prev;

        Node<K, V>* next = x->next;

        // prev <-> x <-> next

        prev->next = next;

        next->prev = prev;

        x->next = x->prev = nullptr;

    }

};

int main() {

    MyLinkedHashMap<string, int> map;

    map.put("a", 1);

    map.put("b", 2);

    map.put("c", 3);

    map.put("d", 4);

    map.put("e", 5);

    // output: a b c d e

    for (const auto& key : map.keys()) {

        cout << key << " ";

    }

    cout << endl;

    map.remove("c");

    cout << map.containsKey("c") << endl;

    // output: a b d e

    for (const auto& key : map.keys()) {

        cout << key << " ";

    }

    cout << endl;

    return 0;

}
```

## LinkedHashSet 的实现

`LinkedHashSet` 就是一个可以保持插入顺序的哈希集合。

前文 [哈希集合的原理及实现](https://labuladong.online/zh/algo/data-structure-basic/hash-set/) 说过，哈希集合的代码实现其实就是包装了一下哈希表。

所以这里 `LinkedHashSet` 的实现也是直接包装一下 `MyLinkedHashMap` 即可，非常简单，我就不写代码了。

更新时间：2026/02/05 12:53

## 评论

Markdown

Ctrl+Enter 发表