# latex文件

## 什么是latex文件

是一种基于TeX的排版系统，由美国计算机科学家莱斯利·兰伯特在20世纪80年代初期开发，利用这种格式系统的处理，即使用户没有排版和程序设计的知识也可以充分发挥由TeX所提供的强大功能，不必一一亲自去设计或校对，能在几天，甚至几小时内生成很多具有书籍质量的印刷品生成复杂表格和数学公式。  

作者使用章（chapter）、节（section）、表（table）、图（figure）等简单的概念指定文档的逻辑结构，并让LaTeX系统负责这些结构的格式和布局。因此，它鼓励从内容中分离布局，同时仍然允许在需要时进行手动排版调整。

## latex文件常用语法

### 基本公式

- 行内：`$E=mc^2$`
- 独立：

  ```latex
  $$
  E=mc^2
  $$
  ```

- 上下标：`x_i^2`

$$
E=mc^2
$$

### 常用符号

- 分式：`\frac{a}{b}`
- 开方：`\sqrt{2}`、`\sqrt[n]{x}`
- 希腊字母：`\alpha \beta \gamma`
- 求和积分：`\sum_{i=1}^n i`，`\int_a^b f(x)\,dx`
- 矩阵：

  ```latex
  \begin{bmatrix}
  a & b\\
  c & d
  \end{bmatrix}
  ```

$$
\begin{aligned}
\frac{a}{b} \\
\sqrt{2} \\
\sqrt[n]{x} \\
\ \alpha\  \beta\  \gamma\ \\
\sum_{i=1}^n i \\
\int_a^b f(x)\,dx
\end{aligned}
$$
$$
  \begin{bmatrix}
  a & b\\
  c & d
  \end{bmatrix}
$$

### 对齐与多行

```latex
\begin{align}   
E &= mc^2 \\
F &= ma
\end{align}
```

$$
\begin{align}   
E &= mc^2 \\
F &= ma
\end{align}
$$
### 空格与注释

- 空格：`\ `、`\quad`
- 注释：`%`


## latex(tex)文件

### 1. 文档基本结构

一个完整的 `.tex` 文件通常分为 **导言区 (Preamble)** 和 **正文区 (Body)**。

```latex
% !TEX program = xelatex           % 指定编译引擎（可选）
\documentclass[UTF8]{ctexart}      % 文档类声明（ctexart 支持中文）

% --- 导言区：加载宏包、设置格式 ---
\title{我的第一个 LaTeX 页面}
\author{作者名}
\date{\today}

\begin{document}                   % --- 正文区开始 ---
\maketitle                         % 生成标题

\section{一级标题}
你好，世界！

\subsection{二级标题}
正文内容...

\end{document}                     % --- 正文区结束 ---
```

### 2. 编译引擎与文件说明

#### 编译引擎选择
- **XeLaTeX**: **推荐选择**。对中文支持最好，支持直接调用系统字体。
- **pdfLaTeX**: 速度快，但处理中文较为繁琐。

#### 产生的文件类型
当你运行 `xelatex` 编译后，会生成以下文件：
- `.tex`: 源代码文件（你编写的文件）。
- **`.pdf`**: 最终生成的排版文档。
- `.aux`: 辅助文件（Auxiliary），记录交叉引用、目录、参考文献等信息。
- `.log`: 编译日志文件，记录编译过程和报错信息。
- `.synctex.gz`: 用于 PDF 阅读器与源码之间的“正反向搜索”定位。
- `.toc`: 目录文件（如果使用了 `\tableofcontents`）。

### 3. 进阶功能：图片与引用

#### 插入图片
需要引入 `graphicx` 宏包。

```latex
\usepackage{graphicx}

% 正文中插入
\begin{figure}[h]
  \centering
  \includegraphics[width=0.5\textwidth]{image_name.png}
  \caption{图片标题}
\end{figure}
```

#### 参考文献 (BibTeX)
通常使用专门的 `.bib` 文件管理引用。

```latex
% 导言区
\usepackage[backend=bibtex]{biblatex}
\addbibresource{references.bib}

% 正文引用
这是一句引用 \cite{key}。

% 生成参考文献列表
\printbibliography
```
