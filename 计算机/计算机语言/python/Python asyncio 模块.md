---
title: Python asyncio 模块 | 菜鸟教程
source: https://www.runoob.com/python3/python-asyncio.html
author:
  - 菜鸟教程，timefiy
published:
created: 2026-03-14
description: Python asyncio 模块  asyncio 是 Python 标准库中的一个模块，用于编写异步 I/O 操作的代码。asyncio 提供了一种高效的方式来处理并发任务，特别适用于 I/O 密集型操作，如网络请求、文件读写等。通过使用 asyncio，你可以在单线程中同时处理多个任务，而无需使用多线程或多进程。  为什么需要 asyncio？ 在传统的同步编程中，当一个任务需要等待 I/O 操作（如网络请求）完成时，程序会阻塞，..
tags:
  - async
  - 异步编程
  - clippings_update
---
# Python asyncio 模块

## Python asyncio 模块简介

`asyncio` 是 Python 标准库中的一个模块，用于编写异步 I/O 操作的代码。

asyncio 提供了一种高效的方式来处理并发任务，特别适用于 I/O 密集型操作，如网络请求、文件读写等。

通过使用 `asyncio` ，你可以在单线程中同时处理多个任务，而无需使用多线程或多进程。

### 为什么需要 asyncio？

在传统的同步编程中，当一个任务需要等待 I/O 操作（如网络请求）完成时，程序会阻塞，直到操作完成。这会导致程序的效率低下，尤其是在需要处理大量 I/O 操作时。

`asyncio` 通过引入异步编程模型，允许程序在等待 I/O 操作时继续执行其他任务，从而提高了程序的并发性和效率。

> 想象一下你正在经营一家餐厅：
> 
> - **同步模式（普通函数）：** 你只有一个厨师。客人 A 点了一份牛排，厨师开始煎牛排（这需要等待 5 分钟）。在煎牛排的这 5 分钟里，厨师完全被占用，不能做任何其他事，即使客人 B 只想点一杯水，也必须干等着。
> - **异步模式（asyncio）：** 你有多个厨师（实际上还是一个，但非常聪明）。厨师开始煎客人 A 的牛排后，发现需要等待，他立刻把这份牛排标记为等待中，然后转头去给客人 B 倒水。倒完水回来，看看牛排是不是快好了，如果还没好，又可以去处理客人 C 的订单。这样，在等待 I/O（如煎牛排、网络请求、读写文件）的时间里，厨师（CPU）一直在高效地工作。
> 
> asyncio 就是 Python 用来实现这种聪明工作模式的标准库，它允许你编写 单线程并发 的代码，特别适用于网络爬虫、Web 服务器、微服务等 I/O 密集型场景。

它的核心是 事件循环、协程 和 任务。

---

## asyncio 的核心概念

### 1\. 协程（Coroutine）

协程是 `asyncio` 的核心概念之一。它是一个特殊的函数，==可以在执行过程中暂停，并在稍后恢复执行==。协程通过 `async def` 关键字定义，并通过 `await` 关键字暂停执行，等待异步操作完成。

## 实例

```python
import asyncio  
  
async def say_hello():  
    print("Hello")  
    await asyncio.sleep(1)  # 协程
    print("World")  
```

### 2\. 事件循环（Event Loop）

事件循环是 `asyncio` 的核心组件，负责调度和执行协程。==它不断地检查是否有任务需要执行，并在任务完成后调用相应的回调函数==。

## 实例 - 事件循环

```python
async def main():  
    await say_hello()  
  
asyncio.run(main())  
```

### 3\. 任务（Task）

任务是对协程的封装，表示一个正在执行或将要执行的协程。你可以通过 `asyncio.create_task()` 函数创建任务，并将其添加到事件循环中。

## 实例

```python
async def main():  
    task = asyncio.create_task(say_hello())  
    await task  
```

### 4\. Future

`Future` 是一个表示异步操作结果的对象。它通常用于底层 API，表示一个尚未完成的操作。你可以通过 `await` 关键字等待 `Future` 完成。

## 实例

```python
async def main():  
    future = asyncio.Future()  
    await future  
```

### 基础用法与代码示例

让我们通过一个经典的并发访问多个网址的例子来理解上述概念。

假设我们需要获取三个不同网址的内容。使用同步方式会顺序执行，总耗时是三次请求耗时的总和。使用 `asyncio` ，我们可以让这三个请求同时发出，总耗时接近于最慢的那一次请求。

### 同步版本（作为对比）

## 实例

```python
import time  
import requests  
  
def fetch_url(url):  
    """模拟一个耗时的网络请求（同步版本）"""  
    print(f"开始获取: {url}")  
    time.sleep(2) # 模拟 2 秒网络延迟  
    print(f"完成获取: {url}")  
    return f"来自 {url} 的数据"  
  
def main_sync():  
    urls = ['https://example.com/1', 'https://example.com/2', 'https://example.com/3']  
    results = []  
    start = time.time()  
  
    for url in urls:  
        result = fetch_url(url) # 必须等上一个完成才能开始下一个  
        results.append(result)  
  
    end = time.time()  
    print(f"同步版本总耗时: {end - start:.2f} 秒")  
    print(f"结果: {results}")  
  
if __name__ == "__main__":  
    main_sync()  
```

**预期运行结果** ：

```
开始获取: https://example.com/1
完成获取: https://example.com/1
开始获取: https://example.com/2
完成获取: https://example.com/2
开始获取: https://example.com/3
完成获取: https://example.com/3
同步版本总耗时: 6.00 秒
结果: [‘来自 https://example.com/1 的数据‘, ‘来自 https://example.com/2 的数据‘, ‘来自 https://example.com/2 的数据‘]
```

总共花了约 6 秒。

### 异步版本（使用 asyncio）

我们需要用 `aiohttp` 库来替代 `requests` 进行异步 HTTP 请求。首先安装它： `pip install aiohttp` 。

## 实例 - 异步版本

```python
import asyncio  
import aiohttp  
import time  
  
async def fetch_url_async(session, url):  
    """模拟一个耗时的网络请求（异步版本）"""  
    print(f"开始异步获取: {url}")  
    # 注意：这里我们使用 aiohttp 的异步 get 方法，并用 await 等待  
    async with session.get(url) as response:  
        # 模拟处理响应也需要时间  
        await asyncio.sleep(2) # 使用 asyncio.sleep 模拟 I/O 等待，它不会阻塞线程  
        text = await response.text()  
        print(f"完成异步获取: {url}")  
        return f"来自 {url} 的数据 (长度: {len(text)})"  
  
async def main_async():  
    urls = ['https://httpbin.org/get', 'https://httpbin.org/delay/1', 'https://httpbin.org/headers']  
  
    async with aiohttp.ClientSession() as session: # 创建异步 HTTP 会话  
        # 为每个 URL 创建一个任务（Task）  
        tasks = []  
        for url in urls:  
            # create_task 会将协程加入事件循环，立即开始调度  
            task = asyncio.create_task(fetch_url_async(session, url))  
            tasks.append(task)  
  
        print("所有任务已创建，开始并发执行...")  
  
        # 使用 asyncio.gather 并发运行所有任务，并等待它们全部完成  
        # gather 返回一个结果列表，顺序与传入的任务顺序一致  
        results = await asyncio.gather(*tasks)  
  
        return results  
  
if __name__ == "__main__":  
    start = time.time()  
    # asyncio.run() 是启动事件循环并运行顶层协程的简便方法  
    final_results = asyncio.run(main_async())  
    end = time.time()  
  
    print(f"\n异步版本总耗时: {end - start:.2f} 秒")  
    for res in final_results:  
        print(res)  
```

**预期运行结果** ：

```
所有任务已创建，开始并发执行...
开始异步获取: https://httpbin.org/get
开始异步获取: https://httpbin.org/delay/1
开始异步获取: https://httpbin.org/headers
（大约 2 秒后，所有请求几乎同时完成）
完成异步获取: https://httpbin.org/headers
完成异步获取: https://httpbin.org/get
完成异步获取: https://httpbin.org/delay/1

异步版本总耗时: 2.10 秒  # 注意！总耗时远小于 6 秒
来自 https://httpbin.org/get 的数据 (长度: 274)
来自 https://httpbin.org/delay/1 的数据 (长度: 392)
来自 https://httpbin.org/headers 的数据 (长度: 177)
```

**代码解析** ：

- `async def` ：定义了协程函数 `fetch_url_async` 和 `main_async` 。
- `await` ：在 `fetch_url_async` 中，我们 `await session.get()` 和 `await response.text()` ，这告诉事件循环："这个网络请求需要时间，你先去执行其他就绪的任务吧"。
- `asyncio.create_task()` ：将 `fetch_url_async` 协程包装成 `Task` ，使其被事件循环调度，实现并发。
- `asyncio.gather(*tasks)` ：一个非常实用的函数，它并发运行所有传入的协程/任务，并等待它们全部完成，最后收集所有结果。
- `asyncio.run(main_async())` ：Python 3.7+ 推荐的方式，它负责创建事件循环、运行协程并关闭循环。

### 关键函数与参数说明

下面以表格形式列出 `asyncio` 中几个最常用的高级函数：

| 函数 | 主要作用 | 常用参数说明 |
| --- | --- | --- |
| **`asyncio.run(coro, *, debug=False)`** | 运行一个顶层协程，管理事件循环的生命周期。是程序的主入口。 | `coro`: 要运行的协程对象。   `debug`: 设为 `True` 可启用事件循环的调试模式。 |
| **`asyncio.create_task(coro, *, name=None)`** | 将协程包装成一个 **Task** 对象，并排入事件循环等待调度。这是实现并发的主要方式。 | `coro`: 要包装的协程对象。   `name`: （Python 3.8+）为任务指定一个名称，便于调试。 |
| **`asyncio.gather(*aws, return_exceptions=False)`** | **并发运行** 多个异步任务（ `aws` 可接受协程、任务等），并等待所有完成，返回结果列表。 | `*aws`: 可变参数，传入多个异步对象。   `return_exceptions`: 默认为 `False` ，任何任务抛出异常都会立即传播给 `gather` 的调用者。设为 `True` 时，异常会作为结果的一部分返回。 |
| **`asyncio.sleep(delay, result=None)`** | **异步地** 休眠指定秒数。这是与 `time.sleep` （阻塞）的关键区别。 | `delay`: 休眠的秒数。   `result`: 休眠结束后返回的值。 |
| **`asyncio.wait(aws, *, timeout=None, return_when=ALL_COMPLETED)`** | 并发运行任务，并等待满足指定条件。返回两个集合 `(done, pending)` ，分别是已完成和未完成的任务。 | `aws`: 异步对象集合。   `timeout`: 超时时间（秒）。   `return_when`: 决定何时返回，可选： `FIRST_COMPLETED` （第一个完成）、 `FIRST_EXCEPTION` （第一个异常）、 `ALL_COMPLETED` （全部完成，默认）。 |
| **`asyncio.to_thread(func, /, *args, **kwargs)`** | （Python 3.9+）将一个普通的、可能阻塞的同步函数放到一个单独的线程中运行，并返回一个可 `await` 的协程。用于处理 CPU 密集型或阻塞式 I/O。 | `func`: 要在线程中运行的同步函数。   `*args, **kwargs`: 传递给函数的参数。 |

### 可视化理解：异步任务调度流程

![](https://www.runoob.com/wp-content/uploads/2025/04/asyncio-python-runoob12-scaled.jpg)

**图解说明** ： 这个流程图展示了事件循环如何像调度员一样工作。它维护一个任务队列，当一个任务执行到 `await` （例如等待网络响应）时，它会被挂起，事件循环立即从队列中找出下一个可以运行（就绪）的任务来执行。当被挂起任务的 I/O 操作完成后，事件循环会收到通知，将该任务状态改回就绪，并在未来某个时刻继续执行它。通过这种方式，在 I/O 等待期间，CPU 被充分利用来执行其他任务，实现了单线程内的并发。

---

## asyncio 的基本用法

### 1\. 运行协程

要运行一个协程，你可以使用 `asyncio.run()` 函数。它会创建一个事件循环，并运行指定的协程。

## 实例

```python
import asyncio  
  
async def main():  
    print("Start")  
    await asyncio.sleep(1)  
    print("End")  
  
asyncio.run(main())  
```

### 2\. 并发执行多个任务

你可以使用 `asyncio.gather()` 函数并发执行多个协程，并等待它们全部完成。

## 实例

```python
import asyncio  
  
async def task1():  
    print("Task 1 started")  
    await asyncio.sleep(1)  
    print("Task 1 finished")  
  
async def task2():  
    print("Task 2 started")  
    await asyncio.sleep(2)  
    print("Task 2 finished")  
  
async def main():  
    await asyncio.gather(task1(), task2())  
  
asyncio.run(main())  
```

### 3\. 超时控制

你可以使用 `asyncio.wait_for()` 函数为协程设置超时时间。如果协程在指定时间内未完成，将引发 `asyncio.TimeoutError` 异常。

## 实例

```python
import asyncio  
  
async def long_task():  
    await asyncio.sleep(10)  
    print("Task finished")  
  
async def main():  
    try:  
        await asyncio.wait_for(long_task(), timeout=5)  
    except asyncio.TimeoutError:  
        print("Task timed out")  
  
asyncio.run(main())  
```

---

## asyncio 的应用场景

`asyncio` 特别适用于以下场景：

1. **网络请求** ：如 HTTP 请求、WebSocket 通信等。
2. **文件 I/O** ：如异步读写文件。
3. **数据库操作** ：如异步访问数据库。
4. **实时数据处理** ：如实时消息队列处理。

---

## 常用类、方法和函数

### 1\. 核心函数

| 方法/函数 | 说明 | 示例 |
| --- | --- | --- |
| **`asyncio.run(coro)`** | 运行异步主函数（Python 3.7+） | `asyncio.run(main())` |
| **`asyncio.create_task(coro)`** | 创建任务并加入事件循环 | `task = asyncio.create_task(fetch_data())` |
| **`asyncio.gather(*coros)`** | 并发运行多个协程 | `await asyncio.gather(task1, task2)` |
| **`asyncio.sleep(delay)`** | 异步等待（非阻塞） | `await asyncio.sleep(1)` |
| **`asyncio.wait(coros)`** | 控制任务完成方式 | `done, pending = await asyncio.wait([task1, task2])` |

### 2\. 事件循环（Event Loop）

| 方法 | 说明 | 示例 |
| --- | --- | --- |
| **`loop.run_until_complete(future)`** | 运行直到任务完成 | `loop.run_until_complete(main())` |
| **`loop.run_forever()`** | 永久运行事件循环 | `loop.run_forever()` |
| **`loop.stop()`** | 停止事件循环 | `loop.stop()` |
| **`loop.close()`** | 关闭事件循环 | `loop.close()` |
| **`loop.call_soon(callback)`** | 安排回调函数立即执行 | `loop.call_soon(print, "Hello")` |
| **`loop.call_later(delay, callback)`** | 延迟执行回调 | `loop.call_later(5, callback)` |

### 3\. 协程（Coroutine）与任务（Task）

| 方法/装饰器 | 说明 | 示例 |
| --- | --- | --- |
| **`@asyncio.coroutine`** | 协程装饰器（旧版，Python 3.4-3.7） | `@asyncio.coroutine`   `def old_coro():` |
| **`async def`** | 定义协程（Python 3.5+） | `async def fetch():` |
| **`task.cancel()`** | 取消任务 | `task.cancel()` |
| **`task.done()`** | 检查任务是否完成 | `if task.done():` |
| **`task.result()`** | 获取任务结果（需任务完成） | `data = task.result()` |

### 4\. 同步原语（类似threading）

| 类 | 说明 | 示例 |
| --- | --- | --- |
| **`asyncio.Lock()`** | 异步互斥锁 | `lock = asyncio.Lock()`   `async with lock:` |
| **`asyncio.Event()`** | 事件通知 | `event = asyncio.Event()`   `await event.wait()` |
| **`asyncio.Queue()`** | 异步队列 | `queue = asyncio.Queue()`   `await queue.put(item)` |
| **`asyncio.Semaphore()`** | 信号量 | `sem = asyncio.Semaphore(5)`   `async with sem:` |

### 5\. 网络与子进程

| 方法/类 | 说明 | 示例 |
| --- | --- | --- |
| **`asyncio.open_connection()`** | 建立TCP连接 | `reader, writer = await asyncio.open_connection('host', 80)` |
| **`asyncio.start_server()`** | 创建TCP服务器 | `server = await asyncio.start_server(handle, '0.0.0.0', 8888)` |
| **`asyncio.create_subprocess_exec()`** | 创建子进程 | `proc = await asyncio.create_subprocess_exec('ls')` |

### 6\. 实用工具

| 方法 | 说明 | 示例 |
| --- | --- | --- |
| **`asyncio.current_task()`** | 获取当前任务 | `task = asyncio.current_task()` |
| **`asyncio.all_tasks()`** | 获取所有任务 | `tasks = asyncio.all_tasks()` |
| **`asyncio.shield(coro)`** | 保护任务不被取消 | `await asyncio.shield(critical_task)` |
| **`asyncio.wait_for(coro, timeout)`** | 带超时的等待 | `try: await asyncio.wait_for(task, 5)` |

### 实例

1\. 基本协程示例

## 实例

```python
import asyncio  
  
async def hello():  
    print("Hello")  
    await asyncio.sleep(1)  
    print("World")  
  
asyncio.run(hello()) # Python 3.7+  
```

### 2\. 并发执行任务

## 实例

```python
async def fetch(url):  
    print(f"Fetching {url}")  
    await asyncio.sleep(2)  
    return f"Data from {url}"  
  
async def main():  
    results = await asyncio.gather(  
        fetch("url1.com"),  
        fetch("url2.com")  
    )  
    print(results)  
  
asyncio.run(main())  
```

### 3\. 使用异步队列

## 实例

```python
async def producer(queue):  
    for i in range(5):  
        await queue.put(i)  
        await asyncio.sleep(0.1)  
  
async def consumer(queue):  
    while True:  
        item = await queue.get()  
        print(f"Consumed {item}")  
        queue.task_done()  
  
async def main():  
    queue = asyncio.Queue()  
    await asyncio.gather(  
        producer(queue),  
        consumer(queue)  
    )  
```
---

### 注意事项

1. **Python版本** ：部分功能需Python 3.7+（如 `asyncio.run()` ）。
2. **阻塞操作** ：避免在协程中使用同步阻塞代码（如 `time.sleep()` ）。
3. **调试** ：设置 `PYTHONASYNCIODEBUG=1` 环境变量可启用调试模式。
4. **取消任务** ：被取消的任务会引发 `CancelledError` ，需妥善处理。