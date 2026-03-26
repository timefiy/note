---
tags:
  - rust
---

# fmt::Debug vs fmt::Display

`std::fmt` 负责 Rust 的格式化输出；`fmt::Debug` 和 `fmt::Display` 这两个 Trait 决定了你在 `println!` 等场景里使用不同占位符时，结构体/枚举等类型会以怎样的文本形式被打印出来。

## fmt::Debug

- 目标：给程序员看的调试信息
- 占位符：`{:?}` 或 `{:#?}`
- 实现方式：通常可以自动派生 `#[derive(Debug)]`

## fmt::Display

- 目标：给最终用户看的展示信息
- 占位符：`{}`
- 实现方式：需要手写实现 `impl fmt::Display for T`
- Rust 不提供 `#[derive(Display)]`

## 对比表

| Trait | 常用占位符 | 受众 | 输出风格 | 实现难度 |
|------|-------------|------|----------|----------|
| `fmt::Debug` | `{:?}` / `{:#?}` | 程序员 | 更接近内部结构，尽可能完整 | 低（常用 `derive`） |
| `fmt::Display` | `{}` | 最终用户 | 更“业务化”的排版 | 高（需要手写 `fmt`） |

## 示例

```rust
use std::fmt;

#[derive(Debug)]
struct Point {
    x: f64,
    y: f64,
}

impl fmt::Display for Point {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "({}, {})", self.x, self.y)
    }
}

fn main() {
    let p = Point { x: 3.14, y: 8.5 };
    println!("用户看到的: {}", p);
    println!("开发者看到的: {:?}", p);
}
```

## 什么时候用哪个

- 大多数日常开发：优先用 `#[derive(Debug)]` + `{:?}` 来做日志/排错
- 只有当你需要把数据当作“对外展示的文本”（例如面向非开发者的错误提示、界面输出、导出为字符串）时，再考虑实现 `fmt::Display`

