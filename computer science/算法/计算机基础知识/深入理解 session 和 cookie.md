---
title: 深入理解 session 和 cookie
source: https://labuladong.online/zh/algo/other-skills/session-and-cookie/
author:
  - "[[../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上回溯算法算法的经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，教会读者如何套用回溯算法代码框架。支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
cookie 大家应该都熟悉，比如说登录某些网站一段时间后，就要求你重新登录；再比如玩过爬虫技术的读者会发现，有些网站就是可以拦截住你的爬虫，这些都和 cookie 有关。

如果你明白了服务器后端对于 cookie 和 session 的处理逻辑，就可以解释这些现象，甚至钻一些网站的空子，待我慢慢道来。

## session 和 cookie 简介

cookie 的出现是因为 HTTP 是无状态的一种协议，换句话说，服务器记不住你，可能你每刷新一次网页，就要重新输入一次账号密码进行登录。这显然是让人无法接受的，cookie 的作用就好比服务器给你贴个标签，然后你每次向服务器再发请求时，服务器就能够通过 cookie 认出你。

抽象地概括一下： **一个 cookie 可以认为是一个「变量」，形如 `name=value` ，存储在浏览器；一个 session 可以理解为一个 json 对象，存储在服务器（一般是类似 Redis 这样的缓存数据库）中** 。

注意，我说的是「一个」cookie 可以认为是一个变量，但是服务器可以一次设置多个 cookie，所以有时候说 cookie 是「一组」键值对儿，这也可以说得通。

cookie 可以在服务器端通过 HTTP 的 SetCookie 字段设置 cookie，比如下面这个简单的 Servlet 示例：

当浏览器访问对应网址时，通过浏览器的开发者工具查看此次 HTTP 通信的细节，可以看见服务器的回应发出了两次 `SetCookie` 命令：

![](https://labuladong.online/images/algo/session/1.png)

在这之后，浏览器的请求中的 `Cookie` 字段就带上了这两个 cookie：

![](https://labuladong.online/images/algo/session/2.png)

**cookie 的作用其实就是这么简单，无非就是服务器给每个客户端（浏览器）打的标签** ，方便服务器辨认而已。当然，HTTP 还有很多参数可以设置 cookie，比如过期时间，或者让某个 cookie 只有某个特定路径才能使用等等。

但问题是，cookie 的容量有限，而且存储在 HTTP header 中，每次请求都要传输，会消耗带宽。更重要的是，有些信息不适合放在客户端，比如用户的登录状态。

**session 就是用来配合 cookie 解决这个问题的** ，最典型的例子就是用户登录。

当你输入账号密码登录成功后，服务器会创建一个 session，里面存储你的登录信息，形如：

然后服务器生成一个随机的 session ID（比如 `abcd1234` ），通过 cookie 发给你的浏览器： `sessionID=abcd1234` 。

之后你访问网站的任何页面，浏览器都会带上这个 cookie，服务器通过这个 ID 就能找到对应的 session，知道你的用户 ID，而且是 admin 权限，不需要每次都输入密码验证。

session 通常存储在服务器的内存数据库（比如 Redis）中，访问速度快，但肯定不会永久保存，一般都有过期时间，比如 三天不活动就自动删除。这就是为什么你登录某些网站后，过一段时间不操作就需要重新登录。

顺带一提，理解 cookie 的原理后，你会发现有些 **不需要登录的网站** 提供的服务有免费试用次数的限制。我们想想它是怎么做到的？

其实就是通过 cookie 给你的浏览器设置了一个 Session ID，如果你删除浏览器的 cookie 就能绕过使用限制。当然，不鼓励高频使用，毕竟人家网站也要赚钱。

以上就是关于 cookie 和 session 的简单介绍，cookie 是 HTTP 协议的一部分，不算复杂，而 session 是可以定制的，所以下面详细看一下实现 session 管理的代码架构吧。

## session 的实现

session 的原理不难，但具体实现很有技巧，一般需要三个组件配合完成： `Manager` 、 `Provider` 和 `Session` 。

![](https://labuladong.online/images/algo/session/4.jpg)

我们用登录后访问个人中心的场景来理解这个流程：

1、用户（已登录）访问 `/profile` 个人中心页面，Handler 函数接收请求，从 HTTP header 中的 cookie 解析出 sessionID（比如 `abcd1234` ），然后把这个 ID 交给 `Manager` 。

2、 `Manager` 是 session 管理器，存储了全局配置（比如 session 过期时间、cookie 名字等）。它把 sessionID 传给内部的 `Provider` ，让它去查找对应的 session。

3、 `Provider` 是一个容器，内部用哈希表存储了多个用户的 session（张三的 session、李四的 session...）。它根据 sessionID 找到对应的 `Session` 对象并返回。

4、 `Session` 对象中存储着该用户的登录信息（user\_id、username、role 等）。Handler 函数拿到这些信息后，就能生成该用户的个性化页面（比如"欢迎回来，张三！"），返回给客户端。

你可能会问：为什么搞这么复杂？直接在 Handler 里用一个哈希表存 `sessionID → 登录信息` 不就行了？

下面解释为什么要分成三层。

### 为什么需要 Session 层？

虽然 session 本质上是存储键值对（user\_id、username 等），但不能直接用哈希表，原因有两个：

**1\. 需要存储辅助数据** ：除了登录信息，还要存储 sessionID、最后访问时间、过期时间等，方便实现过期清理（类似 LRU 算法）。

**2\. 支持多种存储方式** ：如果用内存中的哈希表，程序重启后所有用户都要重新登录，而且用户量大时会占用大量内存。实际应用中，session 可以存在 Redis、MySQL 等不同地方。

`Session` 接口提供统一的操作方式，屏蔽底层存储差异：

```
interface Session {

    // 设置键值对

    void set(String key, Object value);

    // 获取 key 对应的值

    Object get(String key);

    // 删除键 key

    void delete(String key);

}
```

### 为什么需要 Provider 层？

`Provider` 负责管理所有在线用户的 session。虽然简单场景下可以用一个哈希表（sessionID → Session），但实际应用更复杂：

**需要自动清理过期 session** ：假设网站有 10000 个在线用户，不可能手动删除过期的 session。可以用 LRU 算法自动淘汰，这就需要哈希链表这种数据结构。

Tip

关于 LRU 算法的奥妙，参见前文 [LRU 算法详解](https://labuladong.online/zh/algo/data-structure/lru-cache/) 。

`Provider` 封装这些复杂的管理逻辑，只暴露简单的增删查改接口：

```
interface Provider {

    // 新增并返回一个 session

    Session sessionCreate(String sid);

    // 删除一个 session

    void sessionDestroy(String sid);

    // 查找一个 session

    Session sessionRead(String sid);

    // 修改一个 session

    void sessionUpdate(String sid);

    // 通过类似 LRU 的算法回收过期的 session

    void sessionGC(long maxLifeTime);

}
```

### 为什么需要 Manager 层？

`Manager` 负责全局配置，比如：

- Session 过期时间（30 分钟？2 小时？）
- Cookie 的名字（叫 `sessionID` 还是 `sid` ？）
- Session 的存储方式（内存？Redis？MySQL？）

具体的增删查改工作都交给 `Provider` 和 `Session` 了， `Manager` 只负责配置。这样可以灵活切换不同的实现，比如开发环境用内存存储，生产环境用 Redis。

三层架构的核心就是解耦：Session 层处理单个用户的数据，Provider 层管理所有用户，Manager 层负责全局配置。每一层都可以独立替换实现，互不影响。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表

暂无评论，来发表第一条评论吧