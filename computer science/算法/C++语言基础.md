# C++ 语言基础

## 标准输出

C++ 使用 `cout` 进行标准输出，用 `<<` 运算符传递内容，`endl` 是换行符。

```cpp
int a = 10;
cout << a << endl;                          // 输出：10
cout << "Hello" << ", " << "World!" << endl; // 输出：Hello, World!

string s = "abc";
cout << s << " " << a << endl;              // 输出：abc 10
```

## 控制语句

### 条件判断 if else

```cpp
int a = 10;

if (a > 5) {
    cout << "a > 5" << endl;
} else if (a == 5) {
    cout << "a == 5" << endl;
} else {
    cout << "a < 5" << endl;
}
```

### 循环 for/while

```cpp
// for 循环 - 已知循环次数
for (int i = 0; i < 5; i++) {
    cout << i << " ";  // 输出：0 1 2 3 4
}

// while 循环 - 未知循环次数
int num = 100;
while (num > 0) {
    cout << num << " ";  // 输出：100 50 25 12 6 3 1
    num /= 2;
}
```

## 基本数据结构

### 动态数组 vector

#### 初始化

```cpp
#include <vector>

vector<int> nums;                           // 空数组
vector<int> nums(n);                        // 大小为 n，值为 0
vector<int> nums{1, 3, 5};                  // 指定元素
vector<int> nums(n, 2);                     // 大小为 n，值为 2
vector<vector<int>> dp;                     // 二维数组
vector<vector<bool>> dp(m, vector<bool>(n, true)); // m×n 布尔数组
```

#### 常用操作

```cpp
vector<int> nums(10);

nums.empty();           // 检查是否为空
nums.size();            // 获取大小
nums.push_back(20);     // 尾部插入
nums.back();            // 获取最后元素
nums.pop_back();        // 删除最后元素
nums[0] = 11;           // 索引访问/修改
nums.insert(nums.begin() + 3, 99);  // 指定位置插入
nums.erase(nums.begin() + 2);       // 删除指定位置
swap(nums[0], nums[1]); // 交换元素
```

### 双链表 list

#### list 初始化

```cpp
#include <list>

list<int> lst;                  // 空链表
list<int> lst(n);               // 大小为 n，值为 0
list<int> lst{1, 3, 5};         // 指定元素
list<int> lst(n, 2);            // 大小为 n，值为 2
```

#### list 常用操作

```cpp
list<int> lst{1, 2, 3, 4, 5};

lst.empty();            // 检查是否为空
lst.size();             // 获取大小
lst.push_front(0);      // 头部插入
lst.push_back(6);       // 尾部插入
lst.front();            // 获取头部元素
lst.back();             // 获取尾部元素
lst.pop_front();        // 删除头部元素
lst.pop_back();         // 删除尾部元素

// 迭代器操作
auto it = lst.begin();
advance(it, 2);         // 移动到指定位置
lst.insert(it, 99);     // 插入元素
lst.erase(it);          // 删除元素
```

### 队列 queue

```cpp
#include <queue>

queue<int> q;

q.push(10);             // 队尾添加
q.empty();              // 检查是否为空
q.size();               // 获取大小
q.front();              // 获取队头元素
q.back();               // 获取队尾元素
q.pop();                // 删除队头元素
```

### 栈 stack

```cpp
#include <stack>

stack<int> s;

s.push(10);             // 栈顶添加
s.empty();              // 检查是否为空
s.size();               // 获取大小
s.top();                // 获取栈顶元素
s.pop();                // 删除栈顶元素
```

### 哈希表 unordered_map

#### unordered_map 初始化

```cpp
#include <unordered_map>

unordered_map<int, string> hashmap;
unordered_map<int, string> hashmap{{1, "one"}, {2, "two"}};
```

#### unordered_map 常用操作

```cpp
unordered_map<int, string> hashmap{{1, "one"}, {2, "two"}};

hashmap.empty();        // 检查是否为空
hashmap.size();         // 获取大小
hashmap.contains(2);    // 检查键是否存在（C++20）
hashmap[4] = "four";    // 插入/修改
hashmap.erase(3);       // 删除键值对

// 遍历
for (const auto &pair : hashmap) {
    cout << pair.first << " -> " << pair.second << endl;
}
```

**重要提醒**：访问不存在的键会自动创建该键，值为默认构造值。

### 哈希集合 unordered_set（无序）

#### unordered_set 初始化

插入重复的元素重复的元素会变为1个元素。

```cpp
#include <unordered_set>

unordered_set<int> uset;
unordered_set<int> uset{1, 2, 3, 4};
```

#### unordered_set 常用操作

```cpp
unordered_set<int> hashset{1, 2, 3, 4};

hashset.empty();        // 检查是否为空
hashset.size();         // 获取大小
hashset.contains(3);    // 检查元素是否存在
hashset.insert(5);      // 插入元素
hashset.erase(2);       // 删除元素

// 遍历
for (const auto &element : hashset) {
    cout << element << endl;
}
```

## 传值和传引用

### 传值（Pass by Value）

```cpp
void modifyValue(int x) {
    x = 10;  // 只修改副本
}

int main() {
    int num = 5;
    modifyValue(num);
    cout << num << endl;  // 输出：5
}
```

### 传引用（Pass by Reference）

引用不会创建一个新的参数，所以对于类似递归来说的算法，使用引用会减少空间复杂度。

```cpp
void modifyReference(int &x) {
    x = 10;  // 修改原始数据
}

int main() {
    int num = 5;
    modifyReference(num);
    cout << num << endl;  // 输出：10
}
```

### 算法题中的选择

- **基本类型**（int、bool）：传值，复制开销小
- **容器类型**（vector、unordered_map）：传引用，避免复制开销
- **递归函数**：容器参数必须传引用，否则每次递归都会复制数据
