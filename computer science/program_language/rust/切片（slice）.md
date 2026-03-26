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
    
    s.clear();
	# 即使s被清空，但是word的值任然为5
    println!("The first word is: {}", word);
}

fn first(s: &str) -> usize {
	# 将字符串转化为字节切片
    let bytes = s.as_bytes();
    
	# 遍历字节切片
	# iter：迭代器
	# enumerate：枚举
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
    // 因为 s.clear() 需要“可变借用”，而 println! 里的 word 还在持有“不可变借用”。
    // s.clear(); 

    println!("The first word is: {}", word);
}

// 修改返回值类型为 &str
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