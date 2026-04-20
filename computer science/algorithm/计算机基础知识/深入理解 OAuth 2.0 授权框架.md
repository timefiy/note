---
title: 深入理解 OAuth 2.0 授权框架
source: https://labuladong.online/zh/algo/computer-science/oauth2-explained/
author:
  - "[[../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上回溯算法算法的经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，教会读者如何套用回溯算法代码框架。支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
前置知识

阅读本文前，你需要先学习：

OAuth 2.0 是一种行业标准的 **授权框架** （Authorization Framework）。

这里面有两个关键点：

- 基于前文讲过的 ，我们要知道 OAuth2.0 是专门处理 **授权** 的，授权是认证完成后的一个流程，为了确认「你能做什么」。
- OAuth 2.0 框架并不是具体的代码，而是一套广泛使用的协议规范，遵循这套规范编写代码，就可以接入支持 OAuth 2.0 的第三方服务。

再来纠正一个常见的误区： **很多人听到 OAuth 2.0 的第一反应是「第三方登录」，但实际上这么理解是不准确的** 。

因为登录这个行为是为了「认证」，而 OAuth 2.0 是专门处理「授权」的，如果用标准的 OAuth 2.0 流程来实现登录，是不标准、不安全的。

那为什么第三方登录的功能确实经常和 OAuth 2.0 一起出现呢？

这是因为第三方登录使用的是 OpenID Connect（OIDC）技术，而 OIDC 是构建在 OAuth 2.0 之上的 **认证协议** ，所以容易把 OAuth 2.0 和 OIDC 混为一谈。

那么本文就来用实际的例子讲解 OAuth 2.0 的授权流程，下个章节 [OIDC 认证](https://labuladong.online/zh/algo/computer-science/oidc/) 会讲解 OAuth 2.0 为什么不能用来做登录认证，以及 OIDC 是如何解决这个问题的。

## 为什么需要 OAuth 2.0

假设现在有一个笔记软件 `ExampleNote` ，它想要帮你把 Google Drive 里的文件导入到笔记软件中。

最直接的办法是什么？ `ExampleNote` 让你输入 Google 账号和密码，然后它用你的账号密码登录 Google，从你的 Google Drive 读取文件。

显然，这绝对是不安全的，用户当然不能轻易地把自己的账号密码交给第三方应用。

OAuth 2.0 就是为了解决这个问题：让第三方应用获得有限的访问权限，而不需要知道你的密码。

它的核心是： **用临时的、受限的凭证（Access Token）代替永久的、全能的凭证（密码）** 。

## OAuth 2.0 的四个角色

在正式讲解流程之前，先明确 OAuth 2.0 定义的四个角色（这些是 RFC 6749 标准中的规范术语）：

1. **Resource Owner（资源所有者）** ：通常就是你，用户。因为你拥有 Google Drive 里的文件。
2. **Resource Server（资源服务器）** ：存储受保护资源的服务器，比如 Google Drive 的服务器。
3. **Client（客户端）** ：想要访问资源的第三方应用，比如 ExampleNote。
4. **Authorization Server（授权服务器）** ：负责验证用户身份，并给 Client 颁发 Access Token 的服务器，比如 Google 的授权服务器。

关于这几个角色，有两个注意点：

- Resource Server 和 Authorization Server 通常是同一家公司（比如都是 Google），但在架构上是分开的两个服务。
- 我们容易习惯性地认为 Client 是指坐在电脑前的终端用户，而在 OAuth 2.0 中，Client 是指想要访问资源的第三方应用程序，而终端用户是 Resource Owner，即资源所有者。

## OAuth 2.0 授权码流程

OAuth 2.0 有多种授权方式，最常用、最安全的是 **授权码流程（Authorization Code Flow）** 。

我们用 ExampleNote 访问 Google Drive 的例子来演示完整流程。

首先，ExampleNote 的开发者想要通过 OAuth 2.0 流程访问用户的 Google Drive，需要提前在 Google 的开发者平台申请 Client ID 和 Client Secret，这是 ExampleNote 在 Google 系统中的唯一身份标识和访问凭证。

接下来是 OAuth 2.0 授权流程的时序图：

<svg id="mermaid-5-1771335326652" width="100%" xmlns="http://www.w3.org/2000/svg" style="max-width: 1020px;" viewBox="-50 -10 1020 856.5" role="graphics-document document" aria-roledescription="sequence"><g><rect x="770" y="770.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="ResourceServer" rx="3" ry="3" class="actor actor-bottom"></rect><text x="845" y="803" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="845" dy="-8">Google Drive</tspan></text> <text x="845" y="803" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="845" dy="8">资源服务器</tspan></text></g> <g><rect x="570" y="770.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="AuthServer" rx="3" ry="3" class="actor actor-bottom"></rect><text x="645" y="803" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="645" dy="-8">Google</tspan></text> <text x="645" y="803" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="645" dy="8">授权服务器</tspan></text></g> <g><rect x="308" y="770.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="Client" rx="3" ry="3" class="actor actor-bottom"></rect><text x="383" y="803" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="383" dy="-8">ExampleNote</tspan></text> <text x="383" y="803" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="383" dy="8">服务器</tspan></text></g> <g><rect x="0" y="770.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="User" rx="3" ry="3" class="actor actor-bottom"></rect><text x="75" y="803" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="75" dy="0">用户浏览器</tspan></text></g> <g><line id="actor13" x1="845" y1="65" x2="845" y2="770.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="ResourceServer"></line><g id="root-13"><rect x="770" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="ResourceServer" rx="3" ry="3" class="actor actor-top"></rect><text x="845" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="845" dy="-8">Google Drive</tspan></text> <text x="845" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="845" dy="8">资源服务器</tspan></text></g></g> <g><line id="actor12" x1="645" y1="65" x2="645" y2="770.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="AuthServer"></line><g id="root-12"><rect x="570" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="AuthServer" rx="3" ry="3" class="actor actor-top"></rect><text x="645" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="645" dy="-8">Google</tspan></text> <text x="645" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="645" dy="8">授权服务器</tspan></text></g></g> <g><line id="actor11" x1="383" y1="65" x2="383" y2="770.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="Client"></line><g id="root-11"><rect x="308" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="Client" rx="3" ry="3" class="actor actor-top"></rect><text x="383" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="383" dy="-8">ExampleNote</tspan></text> <text x="383" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="383" dy="8">服务器</tspan></text></g></g> <g><line id="actor10" x1="75" y1="65" x2="75" y2="770.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="User"></line><g id="root-10"><rect x="0" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="User" rx="3" ry="3" class="actor actor-top"></rect><text x="75" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="75" dy="0">用户浏览器</tspan></text></g></g> <g></g><defs><symbol id="computer" width="24" height="24"><path transform="scale(.5)" d="M2 2v13h20v-13h-20zm18 11h-16v-9h16v9zm-10.228 6l.466-1h3.524l.467 1h-4.457zm14.228 3h-24l2-6h2.104l-1.33 4h18.45l-1.297-4h2.073l2 6zm-5-10h-14v-7h14v7z"></path></symbol></defs><defs><symbol id="database" fill-rule="evenodd" clip-rule="evenodd"><path transform="scale(.5)" d="M12.258.001l.256.004.255.005.253.008.251.01.249.012.247.015.246.016.242.019.241.02.239.023.236.024.233.027.231.028.229.031.225.032.223.034.22.036.217.038.214.04.211.041.208.043.205.045.201.046.198.048.194.05.191.051.187.053.183.054.18.056.175.057.172.059.168.06.163.061.16.063.155.064.15.066.074.033.073.033.071.034.07.034.069.035.068.035.067.035.066.035.064.036.064.036.062.036.06.036.06.037.058.037.058.037.055.038.055.038.053.038.052.038.051.039.05.039.048.039.047.039.045.04.044.04.043.04.041.04.04.041.039.041.037.041.036.041.034.041.033.042.032.042.03.042.029.042.027.042.026.043.024.043.023.043.021.043.02.043.018.044.017.043.015.044.013.044.012.044.011.045.009.044.007.045.006.045.004.045.002.045.001.045v17l-.001.045-.002.045-.004.045-.006.045-.007.045-.009.044-.011.045-.012.044-.013.044-.015.044-.017.043-.018.044-.02.043-.021.043-.023.043-.024.043-.026.043-.027.042-.029.042-.03.042-.032.042-.033.042-.034.041-.036.041-.037.041-.039.041-.04.041-.041.04-.043.04-.044.04-.045.04-.047.039-.048.039-.05.039-.051.039-.052.038-.053.038-.055.038-.055.038-.058.037-.058.037-.06.037-.06.036-.062.036-.064.036-.064.036-.066.035-.067.035-.068.035-.069.035-.07.034-.071.034-.073.033-.074.033-.15.066-.155.064-.16.063-.163.061-.168.06-.172.059-.175.057-.18.056-.183.054-.187.053-.191.051-.194.05-.198.048-.201.046-.205.045-.208.043-.211.041-.214.04-.217.038-.22.036-.223.034-.225.032-.229.031-.231.028-.233.027-.236.024-.239.023-.241.02-.242.019-.246.016-.247.015-.249.012-.251.01-.253.008-.255.005-.256.004-.258.001-.258-.001-.256-.004-.255-.005-.253-.008-.251-.01-.249-.012-.247-.015-.245-.016-.243-.019-.241-.02-.238-.023-.236-.024-.234-.027-.231-.028-.228-.031-.226-.032-.223-.034-.22-.036-.217-.038-.214-.04-.211-.041-.208-.043-.204-.045-.201-.046-.198-.048-.195-.05-.19-.051-.187-.053-.184-.054-.179-.056-.176-.057-.172-.059-.167-.06-.164-.061-.159-.063-.155-.064-.151-.066-.074-.033-.072-.033-.072-.034-.07-.034-.069-.035-.068-.035-.067-.035-.066-.035-.064-.036-.063-.036-.062-.036-.061-.036-.06-.037-.058-.037-.057-.037-.056-.038-.055-.038-.053-.038-.052-.038-.051-.039-.049-.039-.049-.039-.046-.039-.046-.04-.044-.04-.043-.04-.041-.04-.04-.041-.039-.041-.037-.041-.036-.041-.034-.041-.033-.042-.032-.042-.03-.042-.029-.042-.027-.042-.026-.043-.024-.043-.023-.043-.021-.043-.02-.043-.018-.044-.017-.043-.015-.044-.013-.044-.012-.044-.011-.045-.009-.044-.007-.045-.006-.045-.004-.045-.002-.045-.001-.045v-17l.001-.045.002-.045.004-.045.006-.045.007-.045.009-.044.011-.045.012-.044.013-.044.015-.044.017-.043.018-.044.02-.043.021-.043.023-.043.024-.043.026-.043.027-.042.029-.042.03-.042.032-.042.033-.042.034-.041.036-.041.037-.041.039-.041.04-.041.041-.04.043-.04.044-.04.046-.04.046-.039.049-.039.049-.039.051-.039.052-.038.053-.038.055-.038.056-.038.057-.037.058-.037.06-.037.061-.036.062-.036.063-.036.064-.036.066-.035.067-.035.068-.035.069-.035.07-.034.072-.034.072-.033.074-.033.151-.066.155-.064.159-.063.164-.061.167-.06.172-.059.176-.057.179-.056.184-.054.187-.053.19-.051.195-.05.198-.048.201-.046.204-.045.208-.043.211-.041.214-.04.217-.038.22-.036.223-.034.226-.032.228-.031.231-.028.234-.027.236-.024.238-.023.241-.02.243-.019.245-.016.247-.015.249-.012.251-.01.253-.008.255-.005.256-.004.258-.001.258.001zm-9.258 20.499v.01l.001.021.003.021.004.022.005.021.006.022.007.022.009.023.01.022.011.023.012.023.013.023.015.023.016.024.017.023.018.024.019.024.021.024.022.025.023.024.024.025.052.049.056.05.061.051.066.051.07.051.075.051.079.052.084.052.088.052.092.052.097.052.102.051.105.052.11.052.114.051.119.051.123.051.127.05.131.05.135.05.139.048.144.049.147.047.152.047.155.047.16.045.163.045.167.043.171.043.176.041.178.041.183.039.187.039.19.037.194.035.197.035.202.033.204.031.209.03.212.029.216.027.219.025.222.024.226.021.23.02.233.018.236.016.24.015.243.012.246.01.249.008.253.005.256.004.259.001.26-.001.257-.004.254-.005.25-.008.247-.011.244-.012.241-.014.237-.016.233-.018.231-.021.226-.021.224-.024.22-.026.216-.027.212-.028.21-.031.205-.031.202-.034.198-.034.194-.036.191-.037.187-.039.183-.04.179-.04.175-.042.172-.043.168-.044.163-.045.16-.046.155-.046.152-.047.148-.048.143-.049.139-.049.136-.05.131-.05.126-.05.123-.051.118-.052.114-.051.11-.052.106-.052.101-.052.096-.052.092-.052.088-.053.083-.051.079-.052.074-.052.07-.051.065-.051.06-.051.056-.05.051-.05.023-.024.023-.025.021-.024.02-.024.019-.024.018-.024.017-.024.015-.023.014-.024.013-.023.012-.023.01-.023.01-.022.008-.022.006-.022.006-.022.004-.022.004-.021.001-.021.001-.021v-4.127l-.077.055-.08.053-.083.054-.085.053-.087.052-.09.052-.093.051-.095.05-.097.05-.1.049-.102.049-.105.048-.106.047-.109.047-.111.046-.114.045-.115.045-.118.044-.12.043-.122.042-.124.042-.126.041-.128.04-.13.04-.132.038-.134.038-.135.037-.138.037-.139.035-.142.035-.143.034-.144.033-.147.032-.148.031-.15.03-.151.03-.153.029-.154.027-.156.027-.158.026-.159.025-.161.024-.162.023-.163.022-.165.021-.166.02-.167.019-.169.018-.169.017-.171.016-.173.015-.173.014-.175.013-.175.012-.177.011-.178.01-.179.008-.179.008-.181.006-.182.005-.182.004-.184.003-.184.002h-.37l-.184-.002-.184-.003-.182-.004-.182-.005-.181-.006-.179-.008-.179-.008-.178-.01-.176-.011-.176-.012-.175-.013-.173-.014-.172-.015-.171-.016-.17-.017-.169-.018-.167-.019-.166-.02-.165-.021-.163-.022-.162-.023-.161-.024-.159-.025-.157-.026-.156-.027-.155-.027-.153-.029-.151-.03-.15-.03-.148-.031-.146-.032-.145-.033-.143-.034-.141-.035-.14-.035-.137-.037-.136-.037-.134-.038-.132-.038-.13-.04-.128-.04-.126-.041-.124-.042-.122-.042-.12-.044-.117-.043-.116-.045-.113-.045-.112-.046-.109-.047-.106-.047-.105-.048-.102-.049-.1-.049-.097-.05-.095-.05-.093-.052-.09-.051-.087-.052-.085-.053-.083-.054-.08-.054-.077-.054v4.127zm0-5.654v.011l.001.021.003.021.004.021.005.022.006.022.007.022.009.022.01.022.011.023.012.023.013.023.015.024.016.023.017.024.018.024.019.024.021.024.022.024.023.025.024.024.052.05.056.05.061.05.066.051.07.051.075.052.079.051.084.052.088.052.092.052.097.052.102.052.105.052.11.051.114.051.119.052.123.05.127.051.131.05.135.049.139.049.144.048.147.048.152.047.155.046.16.045.163.045.167.044.171.042.176.042.178.04.183.04.187.038.19.037.194.036.197.034.202.033.204.032.209.03.212.028.216.027.219.025.222.024.226.022.23.02.233.018.236.016.24.014.243.012.246.01.249.008.253.006.256.003.259.001.26-.001.257-.003.254-.006.25-.008.247-.01.244-.012.241-.015.237-.016.233-.018.231-.02.226-.022.224-.024.22-.025.216-.027.212-.029.21-.03.205-.032.202-.033.198-.035.194-.036.191-.037.187-.039.183-.039.179-.041.175-.042.172-.043.168-.044.163-.045.16-.045.155-.047.152-.047.148-.048.143-.048.139-.05.136-.049.131-.05.126-.051.123-.051.118-.051.114-.052.11-.052.106-.052.101-.052.096-.052.092-.052.088-.052.083-.052.079-.052.074-.051.07-.052.065-.051.06-.05.056-.051.051-.049.023-.025.023-.024.021-.025.02-.024.019-.024.018-.024.017-.024.015-.023.014-.023.013-.024.012-.022.01-.023.01-.023.008-.022.006-.022.006-.022.004-.021.004-.022.001-.021.001-.021v-4.139l-.077.054-.08.054-.083.054-.085.052-.087.053-.09.051-.093.051-.095.051-.097.05-.1.049-.102.049-.105.048-.106.047-.109.047-.111.046-.114.045-.115.044-.118.044-.12.044-.122.042-.124.042-.126.041-.128.04-.13.039-.132.039-.134.038-.135.037-.138.036-.139.036-.142.035-.143.033-.144.033-.147.033-.148.031-.15.03-.151.03-.153.028-.154.028-.156.027-.158.026-.159.025-.161.024-.162.023-.163.022-.165.021-.166.02-.167.019-.169.018-.169.017-.171.016-.173.015-.173.014-.175.013-.175.012-.177.011-.178.009-.179.009-.179.007-.181.007-.182.005-.182.004-.184.003-.184.002h-.37l-.184-.002-.184-.003-.182-.004-.182-.005-.181-.007-.179-.007-.179-.009-.178-.009-.176-.011-.176-.012-.175-.013-.173-.014-.172-.015-.171-.016-.17-.017-.169-.018-.167-.019-.166-.02-.165-.021-.163-.022-.162-.023-.161-.024-.159-.025-.157-.026-.156-.027-.155-.028-.153-.028-.151-.03-.15-.03-.148-.031-.146-.033-.145-.033-.143-.033-.141-.035-.14-.036-.137-.036-.136-.037-.134-.038-.132-.039-.13-.039-.128-.04-.126-.041-.124-.042-.122-.043-.12-.043-.117-.044-.116-.044-.113-.046-.112-.046-.109-.046-.106-.047-.105-.048-.102-.049-.1-.049-.097-.05-.095-.051-.093-.051-.09-.051-.087-.053-.085-.052-.083-.054-.08-.054-.077-.054v4.139zm0-5.666v.011l.001.02.003.022.004.021.005.022.006.021.007.022.009.023.01.022.011.023.012.023.013.023.015.023.016.024.017.024.018.023.019.024.021.025.022.024.023.024.024.025.052.05.056.05.061.05.066.051.07.051.075.052.079.051.084.052.088.052.092.052.097.052.102.052.105.051.11.052.114.051.119.051.123.051.127.05.131.05.135.05.139.049.144.048.147.048.152.047.155.046.16.045.163.045.167.043.171.043.176.042.178.04.183.04.187.038.19.037.194.036.197.034.202.033.204.032.209.03.212.028.216.027.219.025.222.024.226.021.23.02.233.018.236.017.24.014.243.012.246.01.249.008.253.006.256.003.259.001.26-.001.257-.003.254-.006.25-.008.247-.01.244-.013.241-.014.237-.016.233-.018.231-.02.226-.022.224-.024.22-.025.216-.027.212-.029.21-.03.205-.032.202-.033.198-.035.194-.036.191-.037.187-.039.183-.039.179-.041.175-.042.172-.043.168-.044.163-.045.16-.045.155-.047.152-.047.148-.048.143-.049.139-.049.136-.049.131-.051.126-.05.123-.051.118-.052.114-.051.11-.052.106-.052.101-.052.096-.052.092-.052.088-.052.083-.052.079-.052.074-.052.07-.051.065-.051.06-.051.056-.05.051-.049.023-.025.023-.025.021-.024.02-.024.019-.024.018-.024.017-.024.015-.023.014-.024.013-.023.012-.023.01-.022.01-.023.008-.022.006-.022.006-.022.004-.022.004-.021.001-.021.001-.021v-4.153l-.077.054-.08.054-.083.053-.085.053-.087.053-.09.051-.093.051-.095.051-.097.05-.1.049-.102.048-.105.048-.106.048-.109.046-.111.046-.114.046-.115.044-.118.044-.12.043-.122.043-.124.042-.126.041-.128.04-.13.039-.132.039-.134.038-.135.037-.138.036-.139.036-.142.034-.143.034-.144.033-.147.032-.148.032-.15.03-.151.03-.153.028-.154.028-.156.027-.158.026-.159.024-.161.024-.162.023-.163.023-.165.021-.166.02-.167.019-.169.018-.169.017-.171.016-.173.015-.173.014-.175.013-.175.012-.177.01-.178.01-.179.009-.179.007-.181.006-.182.006-.182.004-.184.003-.184.001-.185.001-.185-.001-.184-.001-.184-.003-.182-.004-.182-.006-.181-.006-.179-.007-.179-.009-.178-.01-.176-.01-.176-.012-.175-.013-.173-.014-.172-.015-.171-.016-.17-.017-.169-.018-.167-.019-.166-.02-.165-.021-.163-.023-.162-.023-.161-.024-.159-.024-.157-.026-.156-.027-.155-.028-.153-.028-.151-.03-.15-.03-.148-.032-.146-.032-.145-.033-.143-.034-.141-.034-.14-.036-.137-.036-.136-.037-.134-.038-.132-.039-.13-.039-.128-.041-.126-.041-.124-.041-.122-.043-.12-.043-.117-.044-.116-.044-.113-.046-.112-.046-.109-.046-.106-.048-.105-.048-.102-.048-.1-.05-.097-.049-.095-.051-.093-.051-.09-.052-.087-.052-.085-.053-.083-.053-.08-.054-.077-.054v4.153zm8.74-8.179l-.257.004-.254.005-.25.008-.247.011-.244.012-.241.014-.237.016-.233.018-.231.021-.226.022-.224.023-.22.026-.216.027-.212.028-.21.031-.205.032-.202.033-.198.034-.194.036-.191.038-.187.038-.183.04-.179.041-.175.042-.172.043-.168.043-.163.045-.16.046-.155.046-.152.048-.148.048-.143.048-.139.049-.136.05-.131.05-.126.051-.123.051-.118.051-.114.052-.11.052-.106.052-.101.052-.096.052-.092.052-.088.052-.083.052-.079.052-.074.051-.07.052-.065.051-.06.05-.056.05-.051.05-.023.025-.023.024-.021.024-.02.025-.019.024-.018.024-.017.023-.015.024-.014.023-.013.023-.012.023-.01.023-.01.022-.008.022-.006.023-.006.021-.004.022-.004.021-.001.021-.001.021.001.021.001.021.004.021.004.022.006.021.006.023.008.022.01.022.01.023.012.023.013.023.014.023.015.024.017.023.018.024.019.024.02.025.021.024.023.024.023.025.051.05.056.05.06.05.065.051.07.052.074.051.079.052.083.052.088.052.092.052.096.052.101.052.106.052.11.052.114.052.118.051.123.051.126.051.131.05.136.05.139.049.143.048.148.048.152.048.155.046.16.046.163.045.168.043.172.043.175.042.179.041.183.04.187.038.191.038.194.036.198.034.202.033.205.032.21.031.212.028.216.027.22.026.224.023.226.022.231.021.233.018.237.016.241.014.244.012.247.011.25.008.254.005.257.004.26.001.26-.001.257-.004.254-.005.25-.008.247-.011.244-.012.241-.014.237-.016.233-.018.231-.021.226-.022.224-.023.22-.026.216-.027.212-.028.21-.031.205-.032.202-.033.198-.034.194-.036.191-.038.187-.038.183-.04.179-.041.175-.042.172-.043.168-.043.163-.045.16-.046.155-.046.152-.048.148-.048.143-.048.139-.049.136-.05.131-.05.126-.051.123-.051.118-.051.114-.052.11-.052.106-.052.101-.052.096-.052.092-.052.088-.052.083-.052.079-.052.074-.051.07-.052.065-.051.06-.05.056-.05.051-.05.023-.025.023-.024.021-.024.02-.025.019-.024.018-.024.017-.023.015-.024.014-.023.013-.023.012-.023.01-.023.01-.022.008-.022.006-.023.006-.021.004-.022.004-.021.001-.021.001-.021-.001-.021-.001-.021-.004-.021-.004-.022-.006-.021-.006-.023-.008-.022-.01-.022-.01-.023-.012-.023-.013-.023-.014-.023-.015-.024-.017-.023-.018-.024-.019-.024-.02-.025-.021-.024-.023-.024-.023-.025-.051-.05-.056-.05-.06-.05-.065-.051-.07-.052-.074-.051-.079-.052-.083-.052-.088-.052-.092-.052-.096-.052-.101-.052-.106-.052-.11-.052-.114-.052-.118-.051-.123-.051-.126-.051-.131-.05-.136-.05-.139-.049-.143-.048-.148-.048-.152-.048-.155-.046-.16-.046-.163-.045-.168-.043-.172-.043-.175-.042-.179-.041-.183-.04-.187-.038-.191-.038-.194-.036-.198-.034-.202-.033-.205-.032-.21-.031-.212-.028-.216-.027-.22-.026-.224-.023-.226-.022-.231-.021-.233-.018-.237-.016-.241-.014-.244-.012-.247-.011-.25-.008-.254-.005-.257-.004-.26-.001-.26.001z"></path></symbol></defs><defs><symbol id="clock" width="24" height="24"><path transform="scale(.5)" d="M12 2c5.514 0 10 4.486 10 10s-4.486 10-10 10-10-4.486-10-10 4.486-10 10-10zm0-2c-6.627 0-12 5.373-12 12s5.373 12 12 12 12-5.373 12-12-5.373-12-12-12zm5.848 12.459c.202.038.202.333.001.372-1.907.361-6.045 1.111-6.547 1.111-.719 0-1.301-.582-1.301-1.301 0-.512.77-5.447 1.125-7.445.034-.192.312-.181.343.014l.985 6.238 5.394 1.011z"></path></symbol></defs><defs><marker id="arrowhead" refX="7.9" refY="5" markerUnits="userSpaceOnUse" markerWidth="12" markerHeight="12" orient="auto-start-reverse"><path d="M -1 0 L 10 5 L 0 10 z"></path></marker></defs><defs><marker id="crosshead" markerWidth="15" markerHeight="8" orient="auto" refX="4" refY="4.5"><path fill="none" stroke="#000000" stroke-width="1pt" d="M 1,2 L 6,7 M 6,2 L 1,7" style="stroke-dasharray: 0, 0;"></path></marker></defs><defs><marker id="filled-head" refX="15.5" refY="7" markerWidth="20" markerHeight="28" orient="auto"><path d="M 18,7 L9,13 L14,7 L9,1 Z"></path></marker></defs><defs><marker id="sequencenumber" refX="15" refY="15" markerWidth="60" markerHeight="40" orient="auto"><circle cx="15" cy="15" r="6"></circle></marker></defs><text x="228" y="80" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">1. 点击"导入 Google Drive 文件"</text> <line x1="76" y1="117" x2="379" y2="117" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="231" y="132" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">2. 重定向到 Google 授权页面</text> <line x1="382" y1="169" x2="79" y2="169" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="359" y="184" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">3. 访问授权页面</text> <line x1="76" y1="219" x2="641" y2="219" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="362" y="234" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">4. 显示授权确认页面</text> <line x1="644" y1="269" x2="79" y2="269" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="359" y="284" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">5. 用户点击"同意"</text> <line x1="76" y1="319" x2="641" y2="319" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="362" y="334" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">6. 重定向回 ExampleNote</text> <text x="362" y="354" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">(带上授权码 code)</text> <line x1="644" y1="389" x2="79" y2="389" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="228" y="404" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">7. 浏览器访问回调地址</text> <text x="228" y="424" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">(URL 中包含 code)</text> <line x1="76" y1="459" x2="379" y2="459" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="513" y="474" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">8. 用 code + client_secret</text> <text x="513" y="495" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">换取 Access Token</text> <line x1="384" y1="530.5" x2="641" y2="530.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="516" y="546" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">9. 返回 Access Token</text> <line x1="644" y1="580.5" x2="387" y2="580.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="613" y="596" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">10. 用 Access Token</text> <text x="613" y="616" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">请求用户的文件列表</text> <line x1="384" y1="650.5" x2="841" y2="650.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="616" y="666" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">11. 返回文件列表</text> <line x1="844" y1="700.5" x2="387" y2="700.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="231" y="716" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">12. 显示导入的文件</text><line x1="382" y1="750.5" x2="79" y2="750.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line></svg>

### 第 1 步：用户点击授权

你（用户）在 ExampleNote 上点击"导入 Google Drive 文件"按钮。

ExampleNote 将你的浏览器重定向到 Google 的授权页面，URL 类似这样：

```
https://accounts.google.com/oauth/authorize?

  response_type=code&

  client_id=examplenote_client_id&

  redirect_uri=https://examplenote.com/callback&

  scope=drive.readonly
```

参数说明：

- `response_type=code` ：告诉 Google 使用授权码流程。
- `client_id` ：ExampleNote 在 Google 那里的身份标识（ExampleNote 需要提前在 Google 那里注册）。
- `redirect_uri` ：授权完成后，Google 把用户重定向回哪个地址。
- `scope` ：ExampleNote 想要的权限范围，这里申请的是 Google Drive 文件的只读权限。

### 第 2 步：用户同意授权

Google 的授权页面会显示：

> ExampleNote 想要访问你的 Google Drive（只读权限），你同意吗？
> 
> \[ 同意 \] \[ 拒绝 \]

你点击"同意"。

### 第 3 步：Google 返回授权码

Google 将你的浏览器重定向回 ExampleNote 的回调地址，并在 URL 中带上一个 **授权码（Authorization Code）** ：

```
https://examplenote.com/callback?code=AUTH_CODE_12345
```

注意，这个授权码只是一个中间凭证，有效期很短（通常不到 30 秒），而且只能使用一次。

### 第 4 步：用授权码换 Access Token

你的浏览器被重定向到 `https://examplenote.com/callback?code=AUTH_CODE_12345` ，ExampleNote 的服务器可以从 URL 中拿到授权码。

然后， **ExampleNote 的服务器** （注意不是浏览器）向 Google 的 Token 端点发起请求：

```
POST https://oauth2.googleapis.com/token

Content-Type: application/x-www-form-urlencoded

grant_type=authorization_code&

code=AUTH_CODE_12345&

redirect_uri=https://examplenote.com/callback&

client_id=examplenote_client_id&

client_secret=examplenote_secret
```

关键参数：

- `code` ：刚才拿到的授权码。
- `client_secret` ：ExampleNote 的密钥，Google 会检测 `client_id` 和 `client_secret` 是否匹配。

### 第 5 步：Google 返回 Access Token

Google 验证授权码和 `client_secret` 后，会给 ExampleNote 的服务器返回一个 JSON：

```
{

  "access_token": "example.abcdefg...",

  "token_type": "Bearer",

  "expires_in": 3600,

  "scope": "drive.readonly"

}
```

- `access_token` ：这是一个临时的访问凭证，ExampleNote 可以用它访问你的 Google Drive。
- `expires_in` ：这个 access token 的有效期。
- `scope` ：这个 access token 的权限范围。

有些服务可能还会返回一个 `refresh_token` 字段，当 `access_token` 过期时，ExampleNote 可以用它获取新的 access token，而不用让用户重新授权。

### 第 6 步：访问受保护资源

ExampleNote 带着 `access_token` 去 Google Drive API 查询用户的文件列表：

```
GET https://www.googleapis.com/drive/v3/files

Authorization: Bearer example.abcdefg...
```

Google Drive 服务器验证这个 Token 有效，给 ExampleNote 的服务器返回用户的文件列表。

这就是 OAuth 2.0 授权流程的完整过程，既没有暴露用户的 Google 密码，又精确地授予了 ExampleNote 访问用户 Google Drive 的权限。

## 为什么要用授权码？

你可能会问：为什么第 3 步不直接返回 Access Token，而是要返回一个授权码，再让 ExampleNote 去换 Access Token？

这是为了 **安全** ，避免 Access Token 泄露。

因为第 3 步的授权码是通过回调 URL 的参数传递的，而 URL 是没有任何安全保障的，很容易被截获（比如 JavaScript 代码、浏览器插件等都可以读到 URL 参数）。

如果直接在 URL 里传递 Access Token 这种机密信息，一旦被窃取，黑客就能直接用它访问用户的 Google Drive，后果不堪设想。

但授权码只是一个中间凭证，黑客拿到授权码也没用，因为第 4 步换 Access Token 时， **必须提供 `client_secret`** ，而这个密钥只有 ExampleNote 的服务器知道，浏览器和黑客都不知道。

这种设计叫做 **后端通道（Back Channel）交换** ，保证了 Access Token 不会暴露在不安全的浏览器环境中。

## 为什么不能用来做第三方登录？

首先请确保你理解了 ，认证是为了证明「你是谁」，授权是为了确认「你能做什么」。

上述的流程是标准的 **授权** 流程，发生在 ExampleNote 服务器（Client）和 Google 授权服务器（Authorization Server）之间。

而对于「登录」这个操作，我们需要的是 **认证** 流程，即确定用户是谁，发生在用户和 ExampleNote 服务器之间。

以 Google 的第三方登录为例，认证流程的关键是，ExampleNote 要确保用户是这个 Google 账号的所有者，而不是黑客假冒的，然后才能允许用户登录。

也许你可以说：

如果 ExampleNote 应用能够成功获取到 access token，是不是就可以说明这个用户是该 Google 账号的所有者？毕竟需要用户本人登录他的 Google 账号，且点击同意授权，才可能获取到 access token。

答案是，能获取到 access token，并不一定能确信用户是该 Google 账号的所有者。 **其原因在于，授权码 Authorization Code 通过 URL 参数传递，很容易被窃取** 。

比方说上述的第 3 步中，有黑客从 URL 参数中截获了授权码，在用户访问之前抢先访问 `https://examplenote.com/callback?code=AUTH_CODE_12345` ，ExampleNote 的服务端用这个授权码成功换取到了 access token，错误地认为这个黑客就是用户本人， **于是黑客就成功地冒充用户身份登录了 ExampleNote 应用** 。

由于授权码是一次性使用的，真正的用户只会得到一个授权码已被使用的错误提示，登录失败。

所以说，标准的 OAuth 2.0 用来授权是没问题的，它能确保 Access Token 不会泄露到黑客手里。

但由于授权码的不安全性，我们不能确定给出正确授权码的人，就一定是该 Google 账号的所有者，所以标准的 OAuth 2.0 不能用来做第三方登录认证。

要解决这个问题，我们需要引入 OpenID Connect（OIDC）技术，它是在 OAuth 2.0 基础上构建的一个身份认证协议层，在下一篇文章 [OIDC 认证](https://labuladong.online/zh/algo/computer-science/oidc/) 中会详细讲解。

## 总结

- **OAuth 2.0 是一个授权框架** ，核心是让第三方应用获得有限的访问权限，而不需要用户的密码。
- **四个角色** ：Resource Owner（用户）、Resource Server（资源服务器）、Client（第三方应用）、Authorization Server（授权服务器）。
- **授权码流程** ：用户授权 → 返回授权码 → 后端用授权码换 Access Token → 用 Token 访问资源。
- **核心产物** ：Access Token，一个临时的、受限的访问凭证。
- **OAuth 2.0 只管授权，不管认证** 。如果你想实现安全的第三方登录，需要 OpenID Connect（OIDC）认证。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表