---
tags:
  - rust
---

# 切片（slice）

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
    
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }
    s.len()
}
```