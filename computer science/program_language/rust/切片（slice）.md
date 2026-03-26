---
tags:
  - rust
---

# 切片（slice）

## 引子

```rust
fn main() {
    let mut s = String::from("hello world");

    let word = first(&s);
    
	// 当 first 函数执行完毕并返回 5 时，那个传进去的不可变引用 &s 生命周期就结束了（读锁被释放了）
    s.clear();
	// 即使s被清空，但是word的值任然为5
    println!("The first word is: {}", word);
}

fn first(s: &str) -> usize {
	// 将字符串转化为字节切片
    let bytes = s.as_bytes();
    
	// 遍历字节切片
	// iter：迭代器
	// enumerate：枚举
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }
    s.len()
}
```

问题：如果被清空后。使用word作为索引，那么会发生什么？

答案：会发生编译错误，因为s已经被清空，不再有效。

## 字符串切片

- 定义：
	- 字符串切片是指指向字符串中一部分内容的引用
- 形式：
	```rust
	[start..end]
	[start..]
	[..end]
	[..]
	```

```rust
fn main() {
	let s = String::from("hello world");

	// hello
	let slice = &s[0..5];
	// let slice = &s[..5];

	// world
	let slice = &s[6..11];
	// let slice = &s[6..];

	// hello world
	let slice = &s[..];

	println!("slice: {}", slice);
}
```

*注意*：所以的必须发生在UTF8字符边界内。

```rust
let s = "你好"; // "你" 占 3 字节, "好" 占 3 字节，总共 6 字节
// &s[0..1]：崩溃！ 因为索引 1 处在“你”这个字的中间，破坏了 UTF-8结构
```

## 解决问题

```rust
fn main() {
    let mut s = String::from("hello world");

    // 现在 word 是一个 &str（字符串切片），它“借用”了 s 的一部分
    let word = first_word(&s);
    
    // 🚩 编译错误点！
    // 如果你取消下面这一行的注释，Rust 编译器会报错。
    // 返回的切片（返回值），和传进去的字符串（参数），拥有完全绑定在一起的同生共死的生命周期。
    // s.clear(); 

    println!("The first word is: {}", word);
}

// 修改返回值类型为 &str
// 注意：这里的参数也为切片类型
// String 类型在底层实现了一个特殊的特征（Trait），叫做 Deref。这个特征的作用就是告诉编译器：“如果你需要一个 &str，但我手里只有一个 &String，请自动帮我转换一下。”
fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();
    
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            // 发现空格，返回从开头到空格位置的切片
            return &s[0..i];
        }
    }

    // 没发现空格，返回整个字符串切片
    &s[..]
}
```

## 字符串补充

- 字符串字面值就是切片，被直接存储在二进制程序中
```rust
let s = "hello world";
// s的类型是&str，执向二进制程序特定位置的切片
```

| **特性**   | **字符串字面值 / 切片 (&str)**                    | **动态字符串 (String)**            |
| -------- | ----------------------------------------- | ----------------------------- |
| **底层比喻** | 印在书本上的字（不可篡改，永久存在）                        | 写在黑板上的字（随时擦除，可以续写）            |
| **内存位置** | 二进制程序的 **只读数据段 (`.rodata`)**              | 动态分配在 **堆内存 (Heap)** 上        |
| **空间大小** | 编译时死死固定                                   | 运行时可伸缩（自带 `capacity` 扩容机制）    |
| **所有权**  | **借用**（没有所有权，程序结束才由 OS 回收）（可以理解为所有者是程序本身） | **拥有**（一旦离开作用域 `{}`，自动触发释放操作） |
| **适用场景** | 固定的常量、错误提示语、静态配置名                         | 接收网络请求、处理可变的用户输入数据            |