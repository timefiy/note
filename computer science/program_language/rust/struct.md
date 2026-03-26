---
tags:
  - rust
---

# Rust 结构体

## 结构体定义

- 使用struct关键字，并命名
- 在花括号内，为所有字段（FIeld）定义名称和类型

```rust
struct Site {
    domain: String,
    name: String,
    nation: String,
    found: u32,
}
```

要点：

- `struct` 用来定义类型，字段以逗号 `,` 分隔
- 定义块末尾不需要 `;`

## 结构体实例化

```rust
let site1 = Site {
    name: String::from("Example"),
    nation: String::from("China"),
    found: 2013,
};
```

**补充**：没有必要按照声明的顺序实例
字段名与变量名相同可以简写：

```rust
let domain = String::from("example.com");
let name = String::from("Example");

let site1 = Site {
    domain,
    name,
    nation: String::from("China"),
    found: 2013,
};
```

结构体更新语法（`..`）：

```rust
let mut site2 = site1;

let site2 = Site {
    domain: String::from("example.org"),
    name: String::from("Example 2"),
    ..site1
}; 
```

## 元组结构体

```rust
struct Color(u8, u8, u8);
struct Point(f64, f64);

let black = Color(0, 0, 0);
let origin = Point(0.0, 0.0);

println!("black = ({}, {}, {})", black.0, black.1, black.2);
println!("origin = ({}, {})", origin.0, origin.1);
```

## Debug 输出

```rust
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let rect1 = Rectangle { width: 30, height: 50 };
    println!("rect1 is {:?}", rect1);
}
```

## 结构体方法（Method）

```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn wider(&self, rect: &Rectangle) -> bool {
        self.width > rect.width
    }
}

fn main() {
    let rect1 = Rectangle { width: 30, height: 50 };
    let rect2 = Rectangle { width: 40, height: 20 };

    println!("rect1 area = {}", rect1.area());
    println!("rect1 wider than rect2 = {}", rect1.wider(&rect2));
}
```

方法调用时不需要手动传 `self`。

## 结构体关联函数（Associated Function）

```rust
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn create(width: u32, height: u32) -> Rectangle {
        Rectangle { width, height }
    }
}

fn main() {
    let rect = Rectangle::create(30, 50);
    println!("{:?}", rect);
}
```

关联函数在 `impl` 块中定义，但没有 `self` 参数。

## 单元结构体

```rust
struct UnitStruct;
```
