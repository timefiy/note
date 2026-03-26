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
	```
		
	```

```rust
```