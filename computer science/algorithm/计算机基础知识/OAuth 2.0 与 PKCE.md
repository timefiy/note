---
title: OAuth 2.0 与 PKCE
source: https://labuladong.online/zh/algo/computer-science/pkce/
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

- [深入理解 OAuth 2.0 授权框架](https://labuladong.online/zh/algo/computer-science/oauth2-explained/)

在前面的 [OAuth 2.0](https://labuladong.online/zh/algo/computer-science/oauth2-explained/) 和 [OIDC](https://labuladong.online/zh/algo/computer-science/oidc/) 文章中，我们详细讲解了授权码流程，其中有一个关键步骤：

> ExampleNote 的服务器用授权码 + `client_secret` 换取 Access Token。

这个流程看起来很完美， **但它有一个隐含的前提：客户端能够安全地保管 `client_secret`** 。

对于服务器端 Web 应用来说，这个前提是成立的，因为 `client_secret` 存储在服务器上，用户和黑客都无法访问。

但对于移动应用（Android、iOS）、SPA 单页应用（只有前端，没有后端的 Web 应用）、桌面应用等，这个前提就不成立了。

比如你开发了一个 Android App，想要接入 Google 登录，按照标准的 OAuth 2.0 流程，你需要在代码里写入 `client_secret` 。

但 Android APK 可以被反编译，任何人都能从你的 App 中提取出这个 `client_secret` 。

这就引出了 OAuth 2.0 中的一个核心概念： **客户端类型（Client Types）** ，主要分为两类：

**可信客户端（Confidential Client）** ：能够安全保管 `client_secret` 的客户端。

典型例子是服务器端 Web 应用， `client_secret` 存储在服务器上，用户和黑客都无法访问。

**不可信客户端（Public Client）** ：无法安全保管 `client_secret` 的客户端，比如移动端、SPA 应用、桌面应用等。

## 不可信客户端的困境

不可信客户端面临两难：

**困境 1：带 `client_secret` 会泄露**

如果在 Android App 中硬编码 `client_secret` ，APK 被反编译后，黑客可以提取出密钥，冒充你的应用。

即便移动端应用有各种保护措施，比如代码混淆、加固等，也无非是增加了反编译的难度。把 `client_secret` 包含在客户端代码本身就是一个巨大的安全隐患，应该彻底避免。

**困境 2：不带 `client_secret` 不安全**

如果不用 `client_secret` ，直接用授权码换 Token，会面临 **授权码拦截攻击** ：黑客获取授权码后直接就可以换取 Access Token，从而获取用户的资源访问权限。

那么，带静态密钥会泄露，不带又不安全，怎么办？这就是专门为不可信客户端设计的安全方案： **PKCE（Proof Key for Code Exchange）** 。

下面是 PKCE 授权码流程的完整时序图：

<svg id="mermaid-9-1771335337583" width="100%" xmlns="http://www.w3.org/2000/svg" style="max-width: 1005px;" viewBox="-50 -10 1005 1045.5" role="graphics-document document" aria-roledescription="sequence"><g><rect x="755" y="959.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="ResourceServer" rx="3" ry="3" class="actor actor-bottom"></rect><text x="830" y="992" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="830" dy="-8">Google Drive</tspan></text> <text x="830" y="992" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="830" dy="8">资源服务器</tspan></text></g> <g><rect x="535" y="959.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="AuthServer" rx="3" ry="3" class="actor actor-bottom"></rect><text x="610" y="992" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="610" dy="-8">Google</tspan></text> <text x="610" y="992" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="610" dy="8">授权服务器</tspan></text></g> <g><rect x="287" y="959.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="App" rx="3" ry="3" class="actor actor-bottom"></rect><text x="362" y="992" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="362" dy="0">Android App</tspan></text></g> <g><rect x="0" y="959.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="User" rx="3" ry="3" class="actor actor-bottom"></rect><text x="75" y="992" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="75" dy="0">用户</tspan></text></g> <g><line id="actor27" x1="830" y1="65" x2="830" y2="959.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="ResourceServer"></line><g id="root-27"><rect x="755" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="ResourceServer" rx="3" ry="3" class="actor actor-top"></rect><text x="830" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="830" dy="-8">Google Drive</tspan></text> <text x="830" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="830" dy="8">资源服务器</tspan></text></g></g> <g><line id="actor26" x1="610" y1="65" x2="610" y2="959.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="AuthServer"></line><g id="root-26"><rect x="535" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="AuthServer" rx="3" ry="3" class="actor actor-top"></rect><text x="610" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="610" dy="-8">Google</tspan></text> <text x="610" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="610" dy="8">授权服务器</tspan></text></g></g> <g><line id="actor25" x1="362" y1="65" x2="362" y2="959.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="App"></line><g id="root-25"><rect x="287" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="App" rx="3" ry="3" class="actor actor-top"></rect><text x="362" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="362" dy="0">Android App</tspan></text></g></g> <g><line id="actor24" x1="75" y1="65" x2="75" y2="959.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="User"></line><g id="root-24"><rect x="0" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="User" rx="3" ry="3" class="actor actor-top"></rect><text x="75" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="75" dy="0">用户</tspan></text></g></g> <g></g><defs><symbol id="computer" width="24" height="24"><path transform="scale(.5)" d="M2 2v13h20v-13h-20zm18 11h-16v-9h16v9zm-10.228 6l.466-1h3.524l.467 1h-4.457zm14.228 3h-24l2-6h2.104l-1.33 4h18.45l-1.297-4h2.073l2 6zm-5-10h-14v-7h14v7z"></path></symbol></defs><defs><symbol id="database" fill-rule="evenodd" clip-rule="evenodd"><path transform="scale(.5)" d="M12.258.001l.256.004.255.005.253.008.251.01.249.012.247.015.246.016.242.019.241.02.239.023.236.024.233.027.231.028.229.031.225.032.223.034.22.036.217.038.214.04.211.041.208.043.205.045.201.046.198.048.194.05.191.051.187.053.183.054.18.056.175.057.172.059.168.06.163.061.16.063.155.064.15.066.074.033.073.033.071.034.07.034.069.035.068.035.067.035.066.035.064.036.064.036.062.036.06.036.06.037.058.037.058.037.055.038.055.038.053.038.052.038.051.039.05.039.048.039.047.039.045.04.044.04.043.04.041.04.04.041.039.041.037.041.036.041.034.041.033.042.032.042.03.042.029.042.027.042.026.043.024.043.023.043.021.043.02.043.018.044.017.043.015.044.013.044.012.044.011.045.009.044.007.045.006.045.004.045.002.045.001.045v17l-.001.045-.002.045-.004.045-.006.045-.007.045-.009.044-.011.045-.012.044-.013.044-.015.044-.017.043-.018.044-.02.043-.021.043-.023.043-.024.043-.026.043-.027.042-.029.042-.03.042-.032.042-.033.042-.034.041-.036.041-.037.041-.039.041-.04.041-.041.04-.043.04-.044.04-.045.04-.047.039-.048.039-.05.039-.051.039-.052.038-.053.038-.055.038-.055.038-.058.037-.058.037-.06.037-.06.036-.062.036-.064.036-.064.036-.066.035-.067.035-.068.035-.069.035-.07.034-.071.034-.073.033-.074.033-.15.066-.155.064-.16.063-.163.061-.168.06-.172.059-.175.057-.18.056-.183.054-.187.053-.191.051-.194.05-.198.048-.201.046-.205.045-.208.043-.211.041-.214.04-.217.038-.22.036-.223.034-.225.032-.229.031-.231.028-.233.027-.236.024-.239.023-.241.02-.242.019-.246.016-.247.015-.249.012-.251.01-.253.008-.255.005-.256.004-.258.001-.258-.001-.256-.004-.255-.005-.253-.008-.251-.01-.249-.012-.247-.015-.245-.016-.243-.019-.241-.02-.238-.023-.236-.024-.234-.027-.231-.028-.228-.031-.226-.032-.223-.034-.22-.036-.217-.038-.214-.04-.211-.041-.208-.043-.204-.045-.201-.046-.198-.048-.195-.05-.19-.051-.187-.053-.184-.054-.179-.056-.176-.057-.172-.059-.167-.06-.164-.061-.159-.063-.155-.064-.151-.066-.074-.033-.072-.033-.072-.034-.07-.034-.069-.035-.068-.035-.067-.035-.066-.035-.064-.036-.063-.036-.062-.036-.061-.036-.06-.037-.058-.037-.057-.037-.056-.038-.055-.038-.053-.038-.052-.038-.051-.039-.049-.039-.049-.039-.046-.039-.046-.04-.044-.04-.043-.04-.041-.04-.04-.041-.039-.041-.037-.041-.036-.041-.034-.041-.033-.042-.032-.042-.03-.042-.029-.042-.027-.042-.026-.043-.024-.043-.023-.043-.021-.043-.02-.043-.018-.044-.017-.043-.015-.044-.013-.044-.012-.044-.011-.045-.009-.044-.007-.045-.006-.045-.004-.045-.002-.045-.001-.045v-17l.001-.045.002-.045.004-.045.006-.045.007-.045.009-.044.011-.045.012-.044.013-.044.015-.044.017-.043.018-.044.02-.043.021-.043.023-.043.024-.043.026-.043.027-.042.029-.042.03-.042.032-.042.033-.042.034-.041.036-.041.037-.041.039-.041.04-.041.041-.04.043-.04.044-.04.046-.04.046-.039.049-.039.049-.039.051-.039.052-.038.053-.038.055-.038.056-.038.057-.037.058-.037.06-.037.061-.036.062-.036.063-.036.064-.036.066-.035.067-.035.068-.035.069-.035.07-.034.072-.034.072-.033.074-.033.151-.066.155-.064.159-.063.164-.061.167-.06.172-.059.176-.057.179-.056.184-.054.187-.053.19-.051.195-.05.198-.048.201-.046.204-.045.208-.043.211-.041.214-.04.217-.038.22-.036.223-.034.226-.032.228-.031.231-.028.234-.027.236-.024.238-.023.241-.02.243-.019.245-.016.247-.015.249-.012.251-.01.253-.008.255-.005.256-.004.258-.001.258.001zm-9.258 20.499v.01l.001.021.003.021.004.022.005.021.006.022.007.022.009.023.01.022.011.023.012.023.013.023.015.023.016.024.017.023.018.024.019.024.021.024.022.025.023.024.024.025.052.049.056.05.061.051.066.051.07.051.075.051.079.052.084.052.088.052.092.052.097.052.102.051.105.052.11.052.114.051.119.051.123.051.127.05.131.05.135.05.139.048.144.049.147.047.152.047.155.047.16.045.163.045.167.043.171.043.176.041.178.041.183.039.187.039.19.037.194.035.197.035.202.033.204.031.209.03.212.029.216.027.219.025.222.024.226.021.23.02.233.018.236.016.24.015.243.012.246.01.249.008.253.005.256.004.259.001.26-.001.257-.004.254-.005.25-.008.247-.011.244-.012.241-.014.237-.016.233-.018.231-.021.226-.021.224-.024.22-.026.216-.027.212-.028.21-.031.205-.031.202-.034.198-.034.194-.036.191-.037.187-.039.183-.04.179-.04.175-.042.172-.043.168-.044.163-.045.16-.046.155-.046.152-.047.148-.048.143-.049.139-.049.136-.05.131-.05.126-.05.123-.051.118-.052.114-.051.11-.052.106-.052.101-.052.096-.052.092-.052.088-.053.083-.051.079-.052.074-.052.07-.051.065-.051.06-.051.056-.05.051-.05.023-.024.023-.025.021-.024.02-.024.019-.024.018-.024.017-.024.015-.023.014-.024.013-.023.012-.023.01-.023.01-.022.008-.022.006-.022.006-.022.004-.022.004-.021.001-.021.001-.021v-4.127l-.077.055-.08.053-.083.054-.085.053-.087.052-.09.052-.093.051-.095.05-.097.05-.1.049-.102.049-.105.048-.106.047-.109.047-.111.046-.114.045-.115.045-.118.044-.12.043-.122.042-.124.042-.126.041-.128.04-.13.04-.132.038-.134.038-.135.037-.138.037-.139.035-.142.035-.143.034-.144.033-.147.032-.148.031-.15.03-.151.03-.153.029-.154.027-.156.027-.158.026-.159.025-.161.024-.162.023-.163.022-.165.021-.166.02-.167.019-.169.018-.169.017-.171.016-.173.015-.173.014-.175.013-.175.012-.177.011-.178.01-.179.008-.179.008-.181.006-.182.005-.182.004-.184.003-.184.002h-.37l-.184-.002-.184-.003-.182-.004-.182-.005-.181-.006-.179-.008-.179-.008-.178-.01-.176-.011-.176-.012-.175-.013-.173-.014-.172-.015-.171-.016-.17-.017-.169-.018-.167-.019-.166-.02-.165-.021-.163-.022-.162-.023-.161-.024-.159-.025-.157-.026-.156-.027-.155-.027-.153-.029-.151-.03-.15-.03-.148-.031-.146-.032-.145-.033-.143-.034-.141-.035-.14-.035-.137-.037-.136-.037-.134-.038-.132-.038-.13-.04-.128-.04-.126-.041-.124-.042-.122-.042-.12-.044-.117-.043-.116-.045-.113-.045-.112-.046-.109-.047-.106-.047-.105-.048-.102-.049-.1-.049-.097-.05-.095-.05-.093-.052-.09-.051-.087-.052-.085-.053-.083-.054-.08-.054-.077-.054v4.127zm0-5.654v.011l.001.021.003.021.004.021.005.022.006.022.007.022.009.022.01.022.011.023.012.023.013.023.015.024.016.023.017.024.018.024.019.024.021.024.022.024.023.025.024.024.052.05.056.05.061.05.066.051.07.051.075.052.079.051.084.052.088.052.092.052.097.052.102.052.105.052.11.051.114.051.119.052.123.05.127.051.131.05.135.049.139.049.144.048.147.048.152.047.155.046.16.045.163.045.167.044.171.042.176.042.178.04.183.04.187.038.19.037.194.036.197.034.202.033.204.032.209.03.212.028.216.027.219.025.222.024.226.022.23.02.233.018.236.016.24.014.243.012.246.01.249.008.253.006.256.003.259.001.26-.001.257-.003.254-.006.25-.008.247-.01.244-.012.241-.015.237-.016.233-.018.231-.02.226-.022.224-.024.22-.025.216-.027.212-.029.21-.03.205-.032.202-.033.198-.035.194-.036.191-.037.187-.039.183-.039.179-.041.175-.042.172-.043.168-.044.163-.045.16-.045.155-.047.152-.047.148-.048.143-.048.139-.05.136-.049.131-.05.126-.051.123-.051.118-.051.114-.052.11-.052.106-.052.101-.052.096-.052.092-.052.088-.052.083-.052.079-.052.074-.051.07-.052.065-.051.06-.05.056-.051.051-.049.023-.025.023-.024.021-.025.02-.024.019-.024.018-.024.017-.024.015-.023.014-.023.013-.024.012-.022.01-.023.01-.023.008-.022.006-.022.006-.022.004-.021.004-.022.001-.021.001-.021v-4.139l-.077.054-.08.054-.083.054-.085.052-.087.053-.09.051-.093.051-.095.051-.097.05-.1.049-.102.049-.105.048-.106.047-.109.047-.111.046-.114.045-.115.044-.118.044-.12.044-.122.042-.124.042-.126.041-.128.04-.13.039-.132.039-.134.038-.135.037-.138.036-.139.036-.142.035-.143.033-.144.033-.147.033-.148.031-.15.03-.151.03-.153.028-.154.028-.156.027-.158.026-.159.025-.161.024-.162.023-.163.022-.165.021-.166.02-.167.019-.169.018-.169.017-.171.016-.173.015-.173.014-.175.013-.175.012-.177.011-.178.009-.179.009-.179.007-.181.007-.182.005-.182.004-.184.003-.184.002h-.37l-.184-.002-.184-.003-.182-.004-.182-.005-.181-.007-.179-.007-.179-.009-.178-.009-.176-.011-.176-.012-.175-.013-.173-.014-.172-.015-.171-.016-.17-.017-.169-.018-.167-.019-.166-.02-.165-.021-.163-.022-.162-.023-.161-.024-.159-.025-.157-.026-.156-.027-.155-.028-.153-.028-.151-.03-.15-.03-.148-.031-.146-.033-.145-.033-.143-.033-.141-.035-.14-.036-.137-.036-.136-.037-.134-.038-.132-.039-.13-.039-.128-.04-.126-.041-.124-.042-.122-.043-.12-.043-.117-.044-.116-.044-.113-.046-.112-.046-.109-.046-.106-.047-.105-.048-.102-.049-.1-.049-.097-.05-.095-.051-.093-.051-.09-.051-.087-.053-.085-.052-.083-.054-.08-.054-.077-.054v4.139zm0-5.666v.011l.001.02.003.022.004.021.005.022.006.021.007.022.009.023.01.022.011.023.012.023.013.023.015.023.016.024.017.024.018.023.019.024.021.025.022.024.023.024.024.025.052.05.056.05.061.05.066.051.07.051.075.052.079.051.084.052.088.052.092.052.097.052.102.052.105.051.11.052.114.051.119.051.123.051.127.05.131.05.135.05.139.049.144.048.147.048.152.047.155.046.16.045.163.045.167.043.171.043.176.042.178.04.183.04.187.038.19.037.194.036.197.034.202.033.204.032.209.03.212.028.216.027.219.025.222.024.226.021.23.02.233.018.236.017.24.014.243.012.246.01.249.008.253.006.256.003.259.001.26-.001.257-.003.254-.006.25-.008.247-.01.244-.013.241-.014.237-.016.233-.018.231-.02.226-.022.224-.024.22-.025.216-.027.212-.029.21-.03.205-.032.202-.033.198-.035.194-.036.191-.037.187-.039.183-.039.179-.041.175-.042.172-.043.168-.044.163-.045.16-.045.155-.047.152-.047.148-.048.143-.049.139-.049.136-.049.131-.051.126-.05.123-.051.118-.052.114-.051.11-.052.106-.052.101-.052.096-.052.092-.052.088-.052.083-.052.079-.052.074-.052.07-.051.065-.051.06-.051.056-.05.051-.049.023-.025.023-.025.021-.024.02-.024.019-.024.018-.024.017-.024.015-.023.014-.024.013-.023.012-.023.01-.022.01-.023.008-.022.006-.022.006-.022.004-.022.004-.021.001-.021.001-.021v-4.153l-.077.054-.08.054-.083.053-.085.053-.087.053-.09.051-.093.051-.095.051-.097.05-.1.049-.102.048-.105.048-.106.048-.109.046-.111.046-.114.046-.115.044-.118.044-.12.043-.122.043-.124.042-.126.041-.128.04-.13.039-.132.039-.134.038-.135.037-.138.036-.139.036-.142.034-.143.034-.144.033-.147.032-.148.032-.15.03-.151.03-.153.028-.154.028-.156.027-.158.026-.159.024-.161.024-.162.023-.163.023-.165.021-.166.02-.167.019-.169.018-.169.017-.171.016-.173.015-.173.014-.175.013-.175.012-.177.01-.178.01-.179.009-.179.007-.181.006-.182.006-.182.004-.184.003-.184.001-.185.001-.185-.001-.184-.001-.184-.003-.182-.004-.182-.006-.181-.006-.179-.007-.179-.009-.178-.01-.176-.01-.176-.012-.175-.013-.173-.014-.172-.015-.171-.016-.17-.017-.169-.018-.167-.019-.166-.02-.165-.021-.163-.023-.162-.023-.161-.024-.159-.024-.157-.026-.156-.027-.155-.028-.153-.028-.151-.03-.15-.03-.148-.032-.146-.032-.145-.033-.143-.034-.141-.034-.14-.036-.137-.036-.136-.037-.134-.038-.132-.039-.13-.039-.128-.041-.126-.041-.124-.041-.122-.043-.12-.043-.117-.044-.116-.044-.113-.046-.112-.046-.109-.046-.106-.048-.105-.048-.102-.048-.1-.05-.097-.049-.095-.051-.093-.051-.09-.052-.087-.052-.085-.053-.083-.053-.08-.054-.077-.054v4.153zm8.74-8.179l-.257.004-.254.005-.25.008-.247.011-.244.012-.241.014-.237.016-.233.018-.231.021-.226.022-.224.023-.22.026-.216.027-.212.028-.21.031-.205.032-.202.033-.198.034-.194.036-.191.038-.187.038-.183.04-.179.041-.175.042-.172.043-.168.043-.163.045-.16.046-.155.046-.152.048-.148.048-.143.048-.139.049-.136.05-.131.05-.126.051-.123.051-.118.051-.114.052-.11.052-.106.052-.101.052-.096.052-.092.052-.088.052-.083.052-.079.052-.074.051-.07.052-.065.051-.06.05-.056.05-.051.05-.023.025-.023.024-.021.024-.02.025-.019.024-.018.024-.017.023-.015.024-.014.023-.013.023-.012.023-.01.023-.01.022-.008.022-.006.023-.006.021-.004.022-.004.021-.001.021-.001.021.001.021.001.021.004.021.004.022.006.021.006.023.008.022.01.022.01.023.012.023.013.023.014.023.015.024.017.023.018.024.019.024.02.025.021.024.023.024.023.025.051.05.056.05.06.05.065.051.07.052.074.051.079.052.083.052.088.052.092.052.096.052.101.052.106.052.11.052.114.052.118.051.123.051.126.051.131.05.136.05.139.049.143.048.148.048.152.048.155.046.16.046.163.045.168.043.172.043.175.042.179.041.183.04.187.038.191.038.194.036.198.034.202.033.205.032.21.031.212.028.216.027.22.026.224.023.226.022.231.021.233.018.237.016.241.014.244.012.247.011.25.008.254.005.257.004.26.001.26-.001.257-.004.254-.005.25-.008.247-.011.244-.012.241-.014.237-.016.233-.018.231-.021.226-.022.224-.023.22-.026.216-.027.212-.028.21-.031.205-.032.202-.033.198-.034.194-.036.191-.038.187-.038.183-.04.179-.041.175-.042.172-.043.168-.043.163-.045.16-.046.155-.046.152-.048.148-.048.143-.048.139-.049.136-.05.131-.05.126-.051.123-.051.118-.051.114-.052.11-.052.106-.052.101-.052.096-.052.092-.052.088-.052.083-.052.079-.052.074-.051.07-.052.065-.051.06-.05.056-.05.051-.05.023-.025.023-.024.021-.024.02-.025.019-.024.018-.024.017-.023.015-.024.014-.023.013-.023.012-.023.01-.023.01-.022.008-.022.006-.023.006-.021.004-.022.004-.021.001-.021.001-.021-.001-.021-.001-.021-.004-.021-.004-.022-.006-.021-.006-.023-.008-.022-.01-.022-.01-.023-.012-.023-.013-.023-.014-.023-.015-.024-.017-.023-.018-.024-.019-.024-.02-.025-.021-.024-.023-.024-.023-.025-.051-.05-.056-.05-.06-.05-.065-.051-.07-.052-.074-.051-.079-.052-.083-.052-.088-.052-.092-.052-.096-.052-.101-.052-.106-.052-.11-.052-.114-.052-.118-.051-.123-.051-.126-.051-.131-.05-.136-.05-.139-.049-.143-.048-.148-.048-.152-.048-.155-.046-.16-.046-.163-.045-.168-.043-.172-.043-.175-.042-.179-.041-.183-.04-.187-.038-.191-.038-.194-.036-.198-.034-.202-.033-.205-.032-.21-.031-.212-.028-.216-.027-.22-.026-.224-.023-.226-.022-.231-.021-.233-.018-.237-.016-.241-.014-.244-.012-.247-.011-.25-.008-.254-.005-.257-.004-.26-.001-.26.001z"></path></symbol></defs><defs><symbol id="clock" width="24" height="24"><path transform="scale(.5)" d="M12 2c5.514 0 10 4.486 10 10s-4.486 10-10 10-10-4.486-10-10 4.486-10 10-10zm0-2c-6.627 0-12 5.373-12 12s5.373 12 12 12 12-5.373 12-12-5.373-12-12-12zm5.848 12.459c.202.038.202.333.001.372-1.907.361-6.045 1.111-6.547 1.111-.719 0-1.301-.582-1.301-1.301 0-.512.77-5.447 1.125-7.445.034-.192.312-.181.343.014l.985 6.238 5.394 1.011z"></path></symbol></defs><defs><marker id="arrowhead" refX="7.9" refY="5" markerUnits="userSpaceOnUse" markerWidth="12" markerHeight="12" orient="auto-start-reverse"><path d="M -1 0 L 10 5 L 0 10 z"></path></marker></defs><defs><marker id="crosshead" markerWidth="15" markerHeight="8" orient="auto" refX="4" refY="4.5"><path fill="none" stroke="#000000" stroke-width="1pt" d="M 1,2 L 6,7 M 6,2 L 1,7" style="stroke-dasharray: 0, 0;"></path></marker></defs><defs><marker id="filled-head" refX="15.5" refY="7" markerWidth="20" markerHeight="28" orient="auto"><path d="M 18,7 L9,13 L14,7 L9,1 Z"></path></marker></defs><defs><marker id="sequencenumber" refX="15" refY="15" markerWidth="60" markerHeight="40" orient="auto"><circle cx="15" cy="15" r="6"></circle></marker></defs><text x="217" y="80" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">点击"连接 Google Drive"</text> <line x1="76" y1="117" x2="358" y2="117" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="363" y="132" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">生成随机 code_verifier</text> <text x="363" y="153" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">计算 code_challenge</text> <path d="M 363,190 C 423,180 423,220 363,210" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></path><text x="220" y="235" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">跳转到 Google 授权页面</text> <text x="220" y="256" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">(URL 中包含 code_challenge)</text> <line x1="361" y1="293" x2="79" y2="293" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="341" y="308" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">访问授权页面</text> <line x1="76" y1="343" x2="606" y2="343" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="611" y="358" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">记住 code_challenge</text> <path d="M 611,395 C 671,385 671,425 611,415" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></path><text x="341" y="440" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">登录并同意授权</text> <line x1="76" y1="475" x2="606" y2="475" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="344" y="490" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">重定向</text> <text x="344" y="510" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">URL 中包含授权码</text> <line x1="609" y1="545" x2="79" y2="545" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="217" y="560" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">带着授权码跳转到 App</text> <line x1="76" y1="595" x2="358" y2="595" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="485" y="610" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">用 code + code_verifier</text> <text x="485" y="631" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">换取 Access Token</text> <line x1="363" y1="666.5" x2="606" y2="666.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="611" y="682" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">验证</text> <text x="611" y="702" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">SHA256(code_verifier) == code_challenge</text> <path d="M 611,738 C 671,728 671,768 611,758" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></path><text x="488" y="783" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">返回 Access Token</text> <line x1="609" y1="818" x2="366" y2="818" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="595" y="833" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">用 Access Token</text> <text x="595" y="853" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">访问 Google Drive</text> <line x1="363" y1="889.5" x2="826" y2="889.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="598" y="905" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">返回文件列表</text><line x1="829" y1="939.5" x2="366" y2="939.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line></svg>

## PKCE：动态的「一次性密钥」

PKCE（Proof Key for Code Exchange）的核心思路是：

既然静态的 `client_secret` 会泄露，那就用动态生成的「一次性密钥」代替。

这个「一次性密钥」的特点：

- 动态生成：每次授权请求都不同，无法提前获取。
- 仅保存在 App 内存中：不会写入代码或配置文件。
- 基于哈希验证：利用单向哈希函数的不可逆来保证安全性。

### PKCE 工作原理

让我们用 Android App 申请访问 Google Drive 的例子，演示 PKCE 的完整流程。

首先，Android App 的开发者需要提前在 Google 的开发者平台申请创建 OAuth 应用，选择 Android：

![](https://labuladong.online/images/algo/oauth/android-oauth.jpg)

填写应用名称、包名、签名等信息之后，Google 会生成一个 Client ID `your_app_client_id` ，但是 **没有 Client Secret** ，因为 Android App 属于不可信客户端，无法安全保管 Client Secret。

当用户在 Android App 上点击「连接 Google Drive」按钮时，App 会开始 PKCE 授权流程。

**第 1 步：生成 code\_verifier**

App 首先会生成一个 43-128 位的随机字符串，作为 `code_verifier` ：

```
code_verifier = "random_code_verifier_string"
```

这个值只存在于 App 的内存中， **不会通过网络发送** ，可以认为是机密信息。

**第 2 步：计算 code\_challenge**

用 SHA256 哈希算法计算 `code_challenge` ：

```
code_challenge 

= SHA256(code_verifier)

= "code_challenge_sh256_string"
```

这个值会通过网络发送给 Google 授权服务器，属于公开信息，可能会被窃取。

关键在于 SHA256 是单向哈希函数，从 `code_challenge` **无法反推** 出 `code_verifier` ，这是 PKCE 安全性的基础。

**第 3 步：发起授权请求**

App 跳转到 Google 授权页面，URL 中包含还厚的 `code_challenge` ，类似这样：

```
https://accounts.google.com/oauth/authorize?

  response_type=code&

  client_id=your_app_client_id&

  redirect_uri=myapp://callback&

  scope=openid&

  code_challenge=code_challenge_sh256_string&

  code_challenge_method=S256
```

**第 4 步：用户授权**

用户在 Google 授权页面登录并同意授权。Google 服务器 **记住这次请求的 `code_challenge` 值，并和授权码绑定** ，后续换取 Token 时会用到。

**第 5 步：Google 返回授权码**

Google 将用户重定向回 App：

```
myapp://callback?code=AUTH_CODE_12345
```

这一步的授权码出现在 URL 中，可能会被黑客截获。

**第 6 步：用授权码 + code\_verifier 换 Token**

App 向 Google 发送请求， **带上 `code_verifier` 和授权码** ：

```
POST https://oauth2.googleapis.com/token

grant_type=authorization_code&

code=AUTH_CODE_12345&

client_id=your_app_client_id&

code_verifier=random_code_verifier_string
```

**第 7 步：Google 验证并返回 Token**

Google 做以下验证：

1. 计算 `SHA256(code_verifier)`
2. 和之前保存的 `code_challenge` 对比
3. 如果匹配，返回 Access Token 和 ID Token

**第 8 步：App 授权成功**

App 成功获取到 Access Token 后，可以调用 Google Drive API 访问用户的文件列表。

### 为什么 PKCE 安全？

PKCE 巧妙地利用哈希函数的 **不可逆性** ，将验证密钥分成两部分：

- `code_challenge` （哈希值）：可以在 URL 中传输，黑客看到也没用。
- `code_verifier` （原始值）：只存在于客户端内存，黑客无法获取。

实际上，在最新的 OAuth 2.1 规范中，PKCE 已成为所有客户端类型的强制要求，不再区分可信和不可信。

因为 PKCE 为授权码流程提供了额外的安全层，而且统一了可信客户端和不可信客户端的实现。

## 总结

OAuth 2.0 将客户端分为 **可信** （服务器端应用）和 **不可信** （移动/单页应用）两类，区别在于能否安全保管 `client_secret` 。

不可信客户端面临两难困境：带静态密钥会泄露，不带又不安全。

**PKCE 的解决方案** ：用动态生成的 `code_verifier` 替代静态的 `client_secret` ，利用哈希函数的 **不可逆性** 进行验证：

- 发送哈希后的 `code_challenge` 给授权服务器，可以被黑客截获。
- 换 Token 时发送原始的 `code_verifier` ，只存在于客户端内存，黑客无法获取。
- 授权服务器验证 `SHA256(code_verifier) == code_challenge` ，如果匹配，才会发放 Access Token。

黑客即使截获授权码和 `code_challenge` ，也无法反推出 `code_verifier` ，从而无法换取 Token。

在 OAuth 2.1 规范中，PKCE 已成为所有客户端的强制要求，不再区分可信和不可信。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表