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
	
    println!("The first word is: {}", word);

}

  

fn first(s: &str) -> usize {
	# 
    let bytes = s.as_bytes();
    
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }
    s.len()
}
```