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