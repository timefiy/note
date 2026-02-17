---
title: AI 时代的前端开发入门教程
source: https://labuladong.online/zh/algo/computer-science/frontend-introduction/
author:
  - "[[../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上回溯算法算法的经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，教会读者如何套用回溯算法代码框架。支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
以我的实际经验来看，前端开发工作几乎都可以交给 AI 工具来完成。但是，前端的技术栈众多，新概念层出不穷，对于后端开发者来说，很容易迷惑，很难理解和调试 AI 编写的代码。

本文的重点不是深入讲解前端技术的原理和使用，而是理清前端开发中的一些关键概念。

了解这些概念后，就可以轻松地使用 AI 工具开发前端页面了，接下来边用边学，很快就能掌握前端开发的基本技能。

狭义上，前端指的是运行在浏览器中的 Web 页面，和后端系统组成经典的 C/S 架构（或者说 B/S 架构，Browser-Server）。

广义上，前端泛指一切与用户交互的界面，包括手机 App、PC 桌面软件、小程序等。不过本文主要讲 Web 前端。

本文将解答以下问题：

- HTML、CSS、JavaScript 是如何配合的？
- JavaScript 有什么特点？如何运行？
- Node.js 是什么？
- JavaScript 的模块系统（require、import/export）有什么区别？
- TypeScript 和 JavaScript 是什么关系？
- 为什么需要 React、Vue 这些框架？它们分别有什么特点？
- Next.js 是什么？它和 React 是什么关系？
- 什么是服务端渲染（SSR）？和客户端渲染（CSR）有什么区别？

## HTML、CSS、JavaScript 是如何配合的？

都说 HTML、CSS、JavaScript 是前端三剑客，它们各司其职：

HTML (HyperText Markup Language) 定义页面的结构和内容，比如这里有个标题、那里有个按钮。

CSS (Cascading Style Sheets) 定义页面的样式和布局，比如按钮是红色的、字体多大、元素怎么排列。

JavaScript 定义页面的行为和交互逻辑，比如点击按钮后发生什么、如何从后端获取数据并更新页面。

下面看一个简单的例子，演示这三者如何配合：

```
<!DOCTYPE html>

<html>

<head>

    <title>计数器示例</title>

    <style>

        /* CSS: 定义样式 */

        .container {

            text-align: center;

            margin-top: 50px;

        }

        .counter {

            font-size: 48px;

            color: #333;

            margin: 20px 0;

        }

        button {

            font-size: 16px;

            padding: 10px 20px;

            margin: 5px;

            cursor: pointer;

            background-color: #4CAF50;

            color: white;

            border: none;

            border-radius: 4px;

        }

        button:hover {

            background-color: #45a049;

        }

    </style>

</head>

<body>

    

    <div class="container">

        <h1>简单计数器</h1>

        <div class="counter" id="count">0</div>

        <button onclick="increment()">增加</button>

        <button onclick="decrement()">减少</button>

        <button onclick="reset()">重置</button>

    </div>

    <script>

        // JavaScript: 定义行为

        let count = 0;

        function increment() {

            count++;

            updateDisplay();

        }

        function decrement() {

            count--;

            updateDisplay();

        }

        function reset() {

            count = 0;

            updateDisplay();

        }

        function updateDisplay() {

            document.getElementById('count').textContent = count;

        }

    </script>

</body>

</html>
```

把这段代码保存为 `counter.html` ，用浏览器打开就能看到效果：一个显示数字的计数器，三个按钮可以增加、减少或重置数字。

这个例子展示了三者的协作：HTML 定义了页面包含哪些元素（标题、数字显示区、三个按钮），CSS 定义了这些元素的样式（居中、字体大小、按钮颜色），JavaScript 定义了点击按钮时的行为（修改计数器的值并更新页面显示）。

## JavaScript 简介

JavaScript 代码是解释型语言，不需要编译，解释器直接执行，这点和 Python 类似。最著名的 JavaScript 解释器是 Chrome 的 **V8 引擎** 。

另外，JavaScript 是单线程的，但通过事件循环和异步机制（回调、Promise、async/await）实现并发，这和传统的多线程并发模型不同。

在浏览器中运行 JavaScript 代码是最简单的：打开浏览器开发者工具（F12），切换到 Console 标签，直接输入 JavaScript 代码就能执行。

### 什么是 Node.js

很多人以为 JavaScript 只能写前端，其实不然。 **Node.js 让 JavaScript 可以在服务器端运行，成为一门全栈语言** 。

Node.js 不是一门新语言，而是一个 JavaScript 运行时环境（Runtime）。

它把 Chrome 的 V8 引擎搬到了服务器上，并提供了文件系统、网络、进程管理等服务器端能力，语法上保持了 JavaScript 的特性，同时提供了后端开发的能力。

看个具体例子：

```
// 前端 JavaScript：操作 DOM

document.getElementById('btn').addEventListener('click', () => {

    console.log('按钮被点击了');

});

// 前端 JavaScript：发送 HTTP 请求

fetch('/api/users')

    .then(res => res.json())

    .then(data => console.log(data));
```

```
// 后端 JavaScript（Node.js）：创建 HTTP 服务器

const http = require('http');

const server = http.createServer((req, res) => {

    if (req.url === '/api/users') {

        res.writeHead(200, {'Content-Type': 'application/json'});

        res.end(JSON.stringify([

            {id: 1, name: '张三'},

            {id: 2, name: '李四'}

        ]));

    }

});

server.listen(3000, () => {

    console.log('服务器运行在 http://localhost:3000');

});
```

```
// 后端 JavaScript（Node.js）：读写文件

const fs = require('fs');

// 读取文件

fs.readFile('data.txt', 'utf8', (err, data) => {

    if (err) throw err;

    console.log(data);

});

// 写入文件

fs.writeFile('output.txt', 'Hello Node.js', (err) => {

    if (err) throw err;

    console.log('文件写入成功');

});
```

浏览器中的 JavaScript 相当于运行在一个沙盒中，只能访问浏览器提供的 API，如 `window` 、 `document` 对象。

而 Node.js 就和其他后端编程语言一样，可以使用操作系统接口、读写文件、访问数据库等。当然，浏览器的 `window` 、 `document` 对象在 Node.js 环境中也是不存在的。

安装 Node.js 后，使用 `node` 命令即可运行 JavaScript 代码：

```
node script.js
```

是不是和 python 比较像？因为它们都是解释型语言，直接通过解释器运行，不需要编译。

### JavaScript 的模块系统

写后端代码时，你肯定会把代码拆分成多个文件，然后通过 `import` 或 `require` 导入需要的模块。

JavaScript 当然也有模块系统，不过由于历史原因，JavaScript 有两套模块系统，初学者很容易迷惑。

第一套是 **CommonJS** ，这是 Node.js 最早采用的模块系统。你用 `require()` 导入模块，用 `module.exports` 或 `exports` 导出模块：

```
// math.js - 导出模块

function add(a, b) {

    return a + b;

}

function subtract(a, b) {

    return a - b;

}

// 导出多个对象

module.exports = {

    add,

    subtract

};
```

```
// main.js - 导入模块

const math = require('./math.js');

console.log(math.add(1, 2));  // 3
```

第二套是 **ES Modules** （也叫 ES6 模块），这是 JavaScript 官方的模块标准。你用 `import` 导入，用 `export` 导出：

```
// math.js - 导出模块

export function add(a, b) {

    return a + b;

}

export function subtract(a, b) {

    return a - b;

}
```

```
// main.js - 导入模块

import { add, subtract } from './math.js';  // 导入函数

console.log(add(1, 2));      // 3

console.log(subtract(2, 3)); // -1
```

这两套模块系统的主要区别：

CommonJS 的 `require()` 是 **同步加载** ，适合服务器端（文件都在本地磁盘，读取很快）。而且 `require()` 可以在代码的任何地方调用，甚至可以在条件语句里动态加载。

ES Modules 的 `import` 是 **异步加载** ，更适合浏览器（需要从网络下载文件）。 `import` 语句必须在文件顶部，不能在条件语句或函数里使用（但可以用动态 import，即 `import()` 函数）。

在 Node.js 中，默认使用 CommonJS。如果想使用 ES Modules，可以在 `package.json` 中添加 `"type": "module"` 字段。

在未来，ES Modules 将取代 CommonJS，成为 JavaScript 的官方模块标准。

### TypeScript vs JavaScript

TypeScript 是 JavaScript 的超集（Superset），给 JavaScript 加上了静态类型系统，方便在开发阶段发现类型错误，提高代码质量。

其实 TypeScript 最终也要转换成 JavaScript 才能运行，因为浏览器和 Node.js 只认识 JavaScript。

看个对比：

```
// JavaScript: 没有类型检查

function add(a, b) {

    return a + b;

}

add(1, 2);        // 3

add("1", "2");    // "12" (字符串拼接，可能不是你想要的)
```

```
// TypeScript: 有类型检查

function add(a: number, b: number): number {

    return a + b;

}

add(1, 2);        // 3

add("1", "2");    // 编译错误：类型不匹配
```

TypeScript 使用 `tsc` 命令（TypeScript Compiler）进行类型检查和转换：

```
# 安装 TypeScript

npm install -g typescript

# 编译 TypeScript 文件

tsc app.ts

# 这会生成 app.js 文件，类型信息被移除，只剩下纯 JavaScript
```

编译后的 `app.js` 就是普通的 JavaScript 代码，可以在浏览器或 Node.js 中运行。

TypeScript 最大的好处是类型安全，能在编译时发现类型错误，而不是运行时崩溃。同时，类型信息让 IDE 的代码提示、自动补全更准确，在大型项目中类型信息也是很好的文档。因此近年来，越来越多的前端项目采用 TypeScript，尤其是企业级应用。

## React 和 Vue 框架是什么

既然 HTML、CSS、JavaScript 就能开发网页，为什么还会出现 React、Vue 这些框架？

### 原生 JavaScript 开发的痛点

用原生 JavaScript 开发复杂应用有几个问题：

首先是 **DOM 操作繁琐** ，每次更新页面都要手动操作 DOM：

```
// 更新一个用户列表的样式

function renderUsers(users) {

    const container = document.getElementById('user-list');

    container.innerHTML = ''; // 清空

    users.forEach(user => {

        const div = document.createElement('div');

        div.className = 'user-item';

        div.textContent = user.name;

        container.appendChild(div);

    });

}
```

这样写几个页面还行，但如果页面很复杂，代码很快变得难以维护。

其次是状态管理混乱，数据散落在各处，难以追踪数据变化：

```
let userList = [];

let currentPage = 1;

let isLoading = false;

// ... 还有更多全局变量

// 修改数据后要记得更新所有相关的 DOM

function addUser(user) {

    userList.push(user);

    renderUsers(userList);      // 更新用户列表

    updateUserCount(userList);  // 更新用户数量显示

    checkEmptyState(userList);  // 检查是否显示空状态

}
```

最后是代码复用困难。你需要同时编写 HTML、CSS、JavaScript 代码，很难把一个功能模块（比如一个搜索框）封装成可复用的组件。

可以想象，如果不通过模块化的方式管理，一个很复杂的页面代码会有多么混乱和难以维护。

React/Vue 框架就是为了解决这些问题而设计的：

**它们提供一套清晰的代码组织方式，易于组件化，易于管理状态，让开发者可以更轻松地开发复杂应用** 。

### React 框架

React 是由 Facebook（Meta）开发的前端库，它的核心设计理念是组件化和声明式编程。

React 的代码结构很简洁，一个典型的 React 组件是这样的：

```
import { useState } from 'react';

import './Counter.css'; // 引入 CSS 文件

// 一个计数器组件

function Counter() {

    // 使用 Hook 管理状态

    const [count, setCount] = useState(0);

    // 用 JSX 语法描述 HTML 结构

    return (

        <div className="counter">

            <p>当前计数: {count}</p>

            <button onClick={() => setCount(count + 1)}>增加</button>

            <button onClick={() => setCount(count - 1)}>减少</button>

        </div>

    );

}

export default Counter;
```

React 的特点是函数式编程风格，使用 JSX 语法在 JavaScript 代码文件中直接写 HTML。

这个 `Counter` 最后会通过 `React.render` 函数渲染成 HTML + CSS + JavaScript 代码，加载到页面中和用户进行交互。

这种代码开发方式，是不是比完全手写 HTML、CSS、JavaScript 更清晰、更易于维护？

### Vue 框架

Vue 是另一个流行的前端框架，它的设计理念是 **渐进式** 和 **响应式** 。

Vue 强调「响应式数据绑定」，当你修改数据时，Vue 会自动追踪依赖关系，更新所有使用该数据的地方。

Vue 也采用组件化，但代码组织方式和 React 不同。Vue 的代码结构采用 **单文件组件** （.vue 文件），把 HTML、CSS、JavaScript 写在一起，更方便维护：

```
<template>

  

  <div class="counter">

    <p>当前计数: {{ count }}</p>

    <button @click="increment">增加</button>

    <button @click="decrement">减少</button>

  </div>

</template>

<script>

// 代码部分：JavaScript

export default {

  // 数据部分

  data() {

    return {

      count: 0

    }

  },

  // 方法部分

  methods: {

    increment() {

      this.count++;

    },

    decrement() {

      this.count--;

    }

  }

}

</script>

<style scoped>

/* 样式部分：CSS（scoped 表示只作用于当前组件） */

.counter {

  text-align: center;

  padding: 20px;

}

</style>
```

Vue 把一个组件的 HTML、CSS、JavaScript 都写在同一个文件中，组件的组织方式更清晰。

两个框架解决的问题类似，选择哪个主要看个人习惯和项目需求。

## Next.js：React 全栈框架

如果说 React、Vue 是前端框架，那么 Next.js 算什么？它和 React 是什么关系？

**Next.js** 是一个 **全栈框架** ，建立在 React 之上。React 本身只负责构建 UI，但实际开发一个完整的应用，你还需要路由系统（页面跳转）、服务端渲染（SEO 优化）、API 路由（写后端接口）、代码分割（优化加载速度）、图片优化等功能。

Next.js 把这些功能都集成好了，最重要的是，它让你可以用 JavaScript/TypeScript 代码同时开发前端和后端。

### Next.js 的目录结构

Next.js 使用基于文件系统的路由，目录结构即路由结构：

```
my-nextjs-app/

├── app/

│   ├── page.tsx           # 首页，对应路由 /

│   ├── about/

│   │   └── page.tsx       # 关于页，对应路由 /about

│   ├── blog/

│   │   ├── page.tsx       # 博客列表，对应路由 /blog

│   │   └── [id]/

│   │       └── page.tsx   # 博客详情，对应路由 /blog/:id

│   |

│   └── api/               # API 路由目录

│       ├── users/

│       │   └── route.ts   # API 接口 /api/users

│       └── posts/

│           └── route.ts   # API 接口 /api/posts

|   

├── public/                # 静态资源（图片、字体等）

├── package.json

└── next.config.js         # Next.js 配置文件
```

虽然在同一个项目中，但是 `app/api/` 目录下的代码是后端代码，运行在 Node.js 环境，可以访问数据库、文件系统等服务器端资源：

```
// app/api/users/route.ts - 后端 API 代码

import { NextResponse } from 'next/server';

// 这段代码运行在 Node.js 服务器上，不是浏览器

export async function GET() {

    // 可以访问数据库

    const users = await db.query('SELECT * FROM users');

    return NextResponse.json({ users });

}

export async function POST(request: Request) {

    const body = await request.json();

    // 可以读写文件

    await fs.writeFile('data.json', JSON.stringify(body));

    return NextResponse.json({ success: true });

}
```

而 `app/` 目录下的其他文件（如 `page.tsx` ）是页面组件，最终会被渲染成 HTML 文件，加载到浏览器中。

这样一来，作为后端开发者，你会发现 Next.js 项目的结构很熟悉： `api/` 目录就像是你的 Controller 层，只不过用的是 JavaScript/TypeScript 开发，运行在 Node.js 环境。

## 服务端渲染 vs 客户端渲染

Next.js 的一个重要特性是 **服务端渲染（Server-Side Rendering, SSR）** ，这和传统的 React/Vue 应用不同。

### 传统的客户端渲染（CSR）

传统的 React/Vue 应用是纯客户端渲染。服务器返回的 HTML 文件几乎是空的：

```
<!DOCTYPE html>

<html>

<head>

    <title>My React App</title>

</head>

<body>

    <div id="root"></div>  

    <script src="/bundle.js"></script>  

</body>

</html>
```

浏览器下载这个 HTML 后，再下载 `bundle.js` ，然后 JavaScript 代码执行，动态生成页面内容，最后渲染到 `#root` 元素里。

这种方式有两个问题：

第一，用户看到页面内容比较慢。需要等 JavaScript 下载、解析、执行完才能看到内容。

第二，对 SEO 不友好。搜索引擎爬虫抓取到的 HTML 是空的，看不到页面内容，不利于搜索引擎收录。

### 服务端渲染（SSR）

Next.js 支持服务端渲染。服务器在返回 HTML 之前，先在服务器上执行 React 组件代码，生成完整的 HTML：

```
<!DOCTYPE html>

<html>

<head>

    <title>My Next.js App</title>

</head>

<body>

    <div id="root">

        <h1>欢迎来到我的博客</h1>

        <ul>

            <li>文章1: Next.js 入门</li>

            <li>文章2: React Hooks 详解</li>

            <li>文章3: TypeScript 最佳实践</li>

        </ul>

    </div>

    <script src="/_next/static/chunks/main.js"></script>

</body>

</html>
```

浏览器收到的 HTML 已经包含了完整的页面内容，用户可以立即看到内容，搜索引擎也能抓取到完整的页面。

通过 `script` 标签加载的 JavaScript 代码在浏览器中执行，主要用来处理用户交互、显示动画效果、请求动态数据等。

## 总结

前端技术栈看起来复杂，但理清关系后并不难理解：

- HTML + CSS + JavaScript 是基础三件套，分别负责结构、样式、行为。
- JavaScript 是前端主要编程语言，TypeScript 是它的类型安全版本，提供更好的开发体验。
- Node.js 给 JavaScript 提供了服务器端运行环境，让 JavaScript 可以开发后端应用。
- React/Vue 是 UI 框架，解决组件化、状态管理等问题，让你可以更轻松地开发复杂应用。
- Next.js/Nuxt.js 等是全栈框架，在 React/Vue 基础上提供全栈开发能力，让你可以用 JavaScript 代码同时开发前端和后端。

作为后端开发者，了解这些前端开发中的概念，就可以借助 AI 工具轻松地开发前端页面了。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表