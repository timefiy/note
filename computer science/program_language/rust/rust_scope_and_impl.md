---
tags:
  - rust
---

# Rust 作用域与 impl 绑定

## 作用域（Scope）核心结论

- 顶层（模块级）定义的 `struct/enum/impl`，对同一模块中的其他函数可见。
- 在函数内部定义的 `struct`，只在该函数的作用域内可用，其他函数不可见。

## 标准做法：顶层定义 `struct` 与 `impl`

```rust
struct ServerConfig {
    domain: String,
    port: u16,
}

impl ServerConfig {
    fn new(domain: String, port: u16) -> Self {
        Self { domain, port }
    }

    fn summary(&self) -> String {
        format!("{}:{}", self.domain, self.port)
    }

    fn is_https(&self) -> bool {
        self.port == 443
    }
}

fn print_config(config: &ServerConfig) {
    println!("{}", config.summary());
}

fn main() {
    let cfg = ServerConfig::new(String::from("example.com"), 443);
    print_config(&cfg);
    println!("{}", cfg.is_https());
}
```

## 少见做法：在 `main` 内部定义局部 `struct`

```rust
fn main() {
    struct TempData {
        id: i32,
    }

    let data = TempData { id: 1 };
    println!("{}", data.id);
}
```

## 为什么 `impl` 需要单独写

- `impl TypeName { ... }` 把一组行为绑定到某个类型上。
- 方法（method）通常用 `&self` / `&mut self` 表示操作“当前实例”。
- 关联函数（associated function）不带 `self` 参数，通过 `TypeName::函数名(...)` 调用。

## 一个常见文件骨架

- `use ...;`
- `struct/enum` 定义
- `impl` 块（把行为绑定到类型）
- 其他独立函数
- `fn main()` 或测试模块

