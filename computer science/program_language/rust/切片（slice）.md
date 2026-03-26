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
  // 编译错误！s 已被清空，不再有效
    println!("The first word is: {}", word);

}

  

fn first(s: &str) -> usize {

    let bytes = s.as_bytes();
    
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }
    s.len()
}
```