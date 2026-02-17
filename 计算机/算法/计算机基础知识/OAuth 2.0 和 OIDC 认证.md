---
title: OAuth 2.0 和 OIDC 认证
source: https://labuladong.online/zh/algo/computer-science/oidc/
author:
  - "[[../../../author/labuladong]]"
published:
created: 2026-02-17
description: 本文汇总了 力扣/LeetCode 上回溯算法算法的经典习题（第二部分），包含 labuladong 思路讲解和算法可视化，教会读者如何套用回溯算法代码框架。支持 Java/C++/Python/Golang/JavaScript。
tags:
  - clippings
---
在 [深入理解 OAuth 2.0 授权框架](https://labuladong.online/zh/algo/computer-science/oauth2-explained/) 这篇文章中，我们讲到了一个关键问题： **标准的 OAuth 2.0 只能做授权，不能做认证** 。

具体来说，OAuth 2.0 可以让第三方应用（比如 ExampleNote）获得访问用户资源（比如 Google Drive）的权限，但无法安全地确认用户的身份，因为授权码可能被截获，导致黑客冒充用户登录。

那么，如何才能安全地实现「用 Google 账号登录」这种第三方登录功能呢？答案就是 **OpenID Connect (OIDC)** 。

不只是第三方登录

第三方登录是典型的跨组织认证的场景（ExampleNote 借用 Google 的认证服务来实现用户登录）。

那么同一个组织内部也可能用到 OIDC，比如 Google 内部有很多子系统，如 Gmail、Google Drive、Google Docs 等，它们也可以使用 Google 认证服务进行统一的登录认证。

这就是单点登录 (SSO) 的场景，为企业内部的众多服务提供安全灵活的统一登录服务。现代 SSO 也基于 OIDC， [深入理解单点登录 (SSO)](https://labuladong.online/zh/algo/computer-science/sso/) 这篇文章会详细介绍。

术语

在 OIDC 中，有以下几个术语：

- **OP** (OpenID Provider)：认证服务器，负责验证用户身份（相当于 OAuth 2.0 中的 Authorization Server）。
- **RP** (Relying Party)：依赖方，就是各个应用（相当于 OAuth 2.0 中的 Client）。
- **ID Token** ：存储用户身份信息的 JWT 令牌。

## OIDC 和 OAuth 2.0 的关系

OIDC 是构建在 OAuth 2.0 之上的 **认证协议层** ，它在 OAuth 2.0 的授权流程基础上，增加了身份认证的能力，解决了 OAuth 2.0 不能用于登录的问题。

首先，OIDC 复用了 OAuth 2.0 的授权码流程、Access Token 等核心概念，所以整体流程和 OAuth 2.0 是一样的。

区别在于，OIDC 在 OAuth 2.0 基础上增加了 nonce 参数和 ID Token，专门用来防止重放攻击和证明用户身份。

接下来是 OIDC 授权码流程的时序图：

<svg id="mermaid-7-1771335332110" width="100%" xmlns="http://www.w3.org/2000/svg" style="max-width: 1031px;" viewBox="-50 -10 1031 939.5" role="graphics-document document" aria-roledescription="sequence"><g><rect x="781" y="853.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="AuthServer" rx="3" ry="3" class="actor actor-bottom"></rect><text x="856" y="886" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="856" dy="-8">Google</tspan></text> <text x="856" y="886" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="856" dy="8">授权服务器</tspan></text></g> <g><rect x="454" y="853.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="Client" rx="3" ry="3" class="actor actor-bottom"></rect><text x="529" y="886" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="529" dy="-8">ExampleNote</tspan></text> <text x="529" y="886" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="529" dy="8">服务器</tspan></text></g> <g><rect x="0" y="853.5" fill="#eaeaea" stroke="#666" width="150" height="65" name="User" rx="3" ry="3" class="actor actor-bottom"></rect><text x="75" y="886" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="75" dy="0">用户浏览器</tspan></text></g> <g><line id="actor20" x1="856" y1="65" x2="856" y2="853.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="AuthServer"></line><g id="root-20"><rect x="781" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="AuthServer" rx="3" ry="3" class="actor actor-top"></rect><text x="856" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="856" dy="-8">Google</tspan></text> <text x="856" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="856" dy="8">授权服务器</tspan></text></g></g> <g><line id="actor19" x1="529" y1="65" x2="529" y2="853.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="Client"></line><g id="root-19"><rect x="454" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="Client" rx="3" ry="3" class="actor actor-top"></rect><text x="529" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="529" dy="-8">ExampleNote</tspan></text> <text x="529" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="529" dy="8">服务器</tspan></text></g></g> <g><line id="actor18" x1="75" y1="65" x2="75" y2="853.5" class="actor-line 200" stroke-width="0.5px" stroke="#999" name="User"></line><g id="root-18"><rect x="0" y="0" fill="#eaeaea" stroke="#666" width="150" height="65" name="User" rx="3" ry="3" class="actor actor-top"></rect><text x="75" y="32.5" dominant-baseline="central" alignment-baseline="central" class="actor actor-box" style="text-anchor: middle; font-size: 16px; font-weight: 400; font-family: ui-sans-serif, system-ui, sans-serif;"><tspan x="75" dy="0">用户浏览器</tspan></text></g></g> <g></g><defs><symbol id="computer" width="24" height="24"><path transform="scale(.5)" d="M2 2v13h20v-13h-20zm18 11h-16v-9h16v9zm-10.228 6l.466-1h3.524l.467 1h-4.457zm14.228 3h-24l2-6h2.104l-1.33 4h18.45l-1.297-4h2.073l2 6zm-5-10h-14v-7h14v7z"></path></symbol></defs><defs><symbol id="database" fill-rule="evenodd" clip-rule="evenodd"><path transform="scale(.5)" d="M12.258.001l.256.004.255.005.253.008.251.01.249.012.247.015.246.016.242.019.241.02.239.023.236.024.233.027.231.028.229.031.225.032.223.034.22.036.217.038.214.04.211.041.208.043.205.045.201.046.198.048.194.05.191.051.187.053.183.054.18.056.175.057.172.059.168.06.163.061.16.063.155.064.15.066.074.033.073.033.071.034.07.034.069.035.068.035.067.035.066.035.064.036.064.036.062.036.06.036.06.037.058.037.058.037.055.038.055.038.053.038.052.038.051.039.05.039.048.039.047.039.045.04.044.04.043.04.041.04.04.041.039.041.037.041.036.041.034.041.033.042.032.042.03.042.029.042.027.042.026.043.024.043.023.043.021.043.02.043.018.044.017.043.015.044.013.044.012.044.011.045.009.044.007.045.006.045.004.045.002.045.001.045v17l-.001.045-.002.045-.004.045-.006.045-.007.045-.009.044-.011.045-.012.044-.013.044-.015.044-.017.043-.018.044-.02.043-.021.043-.023.043-.024.043-.026.043-.027.042-.029.042-.03.042-.032.042-.033.042-.034.041-.036.041-.037.041-.039.041-.04.041-.041.04-.043.04-.044.04-.045.04-.047.039-.048.039-.05.039-.051.039-.052.038-.053.038-.055.038-.055.038-.058.037-.058.037-.06.037-.06.036-.062.036-.064.036-.064.036-.066.035-.067.035-.068.035-.069.035-.07.034-.071.034-.073.033-.074.033-.15.066-.155.064-.16.063-.163.061-.168.06-.172.059-.175.057-.18.056-.183.054-.187.053-.191.051-.194.05-.198.048-.201.046-.205.045-.208.043-.211.041-.214.04-.217.038-.22.036-.223.034-.225.032-.229.031-.231.028-.233.027-.236.024-.239.023-.241.02-.242.019-.246.016-.247.015-.249.012-.251.01-.253.008-.255.005-.256.004-.258.001-.258-.001-.256-.004-.255-.005-.253-.008-.251-.01-.249-.012-.247-.015-.245-.016-.243-.019-.241-.02-.238-.023-.236-.024-.234-.027-.231-.028-.228-.031-.226-.032-.223-.034-.22-.036-.217-.038-.214-.04-.211-.041-.208-.043-.204-.045-.201-.046-.198-.048-.195-.05-.19-.051-.187-.053-.184-.054-.179-.056-.176-.057-.172-.059-.167-.06-.164-.061-.159-.063-.155-.064-.151-.066-.074-.033-.072-.033-.072-.034-.07-.034-.069-.035-.068-.035-.067-.035-.066-.035-.064-.036-.063-.036-.062-.036-.061-.036-.06-.037-.058-.037-.057-.037-.056-.038-.055-.038-.053-.038-.052-.038-.051-.039-.049-.039-.049-.039-.046-.039-.046-.04-.044-.04-.043-.04-.041-.04-.04-.041-.039-.041-.037-.041-.036-.041-.034-.041-.033-.042-.032-.042-.03-.042-.029-.042-.027-.042-.026-.043-.024-.043-.023-.043-.021-.043-.02-.043-.018-.044-.017-.043-.015-.044-.013-.044-.012-.044-.011-.045-.009-.044-.007-.045-.006-.045-.004-.045-.002-.045-.001-.045v-17l.001-.045.002-.045.004-.045.006-.045.007-.045.009-.044.011-.045.012-.044.013-.044.015-.044.017-.043.018-.044.02-.043.021-.043.023-.043.024-.043.026-.043.027-.042.029-.042.03-.042.032-.042.033-.042.034-.041.036-.041.037-.041.039-.041.04-.041.041-.04.043-.04.044-.04.046-.04.046-.039.049-.039.049-.039.051-.039.052-.038.053-.038.055-.038.056-.038.057-.037.058-.037.06-.037.061-.036.062-.036.063-.036.064-.036.066-.035.067-.035.068-.035.069-.035.07-.034.072-.034.072-.033.074-.033.151-.066.155-.064.159-.063.164-.061.167-.06.172-.059.176-.057.179-.056.184-.054.187-.053.19-.051.195-.05.198-.048.201-.046.204-.045.208-.043.211-.041.214-.04.217-.038.22-.036.223-.034.226-.032.228-.031.231-.028.234-.027.236-.024.238-.023.241-.02.243-.019.245-.016.247-.015.249-.012.251-.01.253-.008.255-.005.256-.004.258-.001.258.001zm-9.258 20.499v.01l.001.021.003.021.004.022.005.021.006.022.007.022.009.023.01.022.011.023.012.023.013.023.015.023.016.024.017.023.018.024.019.024.021.024.022.025.023.024.024.025.052.049.056.05.061.051.066.051.07.051.075.051.079.052.084.052.088.052.092.052.097.052.102.051.105.052.11.052.114.051.119.051.123.051.127.05.131.05.135.05.139.048.144.049.147.047.152.047.155.047.16.045.163.045.167.043.171.043.176.041.178.041.183.039.187.039.19.037.194.035.197.035.202.033.204.031.209.03.212.029.216.027.219.025.222.024.226.021.23.02.233.018.236.016.24.015.243.012.246.01.249.008.253.005.256.004.259.001.26-.001.257-.004.254-.005.25-.008.247-.011.244-.012.241-.014.237-.016.233-.018.231-.021.226-.021.224-.024.22-.026.216-.027.212-.028.21-.031.205-.031.202-.034.198-.034.194-.036.191-.037.187-.039.183-.04.179-.04.175-.042.172-.043.168-.044.163-.045.16-.046.155-.046.152-.047.148-.048.143-.049.139-.049.136-.05.131-.05.126-.05.123-.051.118-.052.114-.051.11-.052.106-.052.101-.052.096-.052.092-.052.088-.053.083-.051.079-.052.074-.052.07-.051.065-.051.06-.051.056-.05.051-.05.023-.024.023-.025.021-.024.02-.024.019-.024.018-.024.017-.024.015-.023.014-.024.013-.023.012-.023.01-.023.01-.022.008-.022.006-.022.006-.022.004-.022.004-.021.001-.021.001-.021v-4.127l-.077.055-.08.053-.083.054-.085.053-.087.052-.09.052-.093.051-.095.05-.097.05-.1.049-.102.049-.105.048-.106.047-.109.047-.111.046-.114.045-.115.045-.118.044-.12.043-.122.042-.124.042-.126.041-.128.04-.13.04-.132.038-.134.038-.135.037-.138.037-.139.035-.142.035-.143.034-.144.033-.147.032-.148.031-.15.03-.151.03-.153.029-.154.027-.156.027-.158.026-.159.025-.161.024-.162.023-.163.022-.165.021-.166.02-.167.019-.169.018-.169.017-.171.016-.173.015-.173.014-.175.013-.175.012-.177.011-.178.01-.179.008-.179.008-.181.006-.182.005-.182.004-.184.003-.184.002h-.37l-.184-.002-.184-.003-.182-.004-.182-.005-.181-.006-.179-.008-.179-.008-.178-.01-.176-.011-.176-.012-.175-.013-.173-.014-.172-.015-.171-.016-.17-.017-.169-.018-.167-.019-.166-.02-.165-.021-.163-.022-.162-.023-.161-.024-.159-.025-.157-.026-.156-.027-.155-.027-.153-.029-.151-.03-.15-.03-.148-.031-.146-.032-.145-.033-.143-.034-.141-.035-.14-.035-.137-.037-.136-.037-.134-.038-.132-.038-.13-.04-.128-.04-.126-.041-.124-.042-.122-.042-.12-.044-.117-.043-.116-.045-.113-.045-.112-.046-.109-.047-.106-.047-.105-.048-.102-.049-.1-.049-.097-.05-.095-.05-.093-.052-.09-.051-.087-.052-.085-.053-.083-.054-.08-.054-.077-.054v4.127zm0-5.654v.011l.001.021.003.021.004.021.005.022.006.022.007.022.009.022.01.022.011.023.012.023.013.023.015.024.016.023.017.024.018.024.019.024.021.024.022.024.023.025.024.024.052.05.056.05.061.05.066.051.07.051.075.052.079.051.084.052.088.052.092.052.097.052.102.052.105.052.11.051.114.051.119.052.123.05.127.051.131.05.135.049.139.049.144.048.147.048.152.047.155.046.16.045.163.045.167.044.171.042.176.042.178.04.183.04.187.038.19.037.194.036.197.034.202.033.204.032.209.03.212.028.216.027.219.025.222.024.226.022.23.02.233.018.236.016.24.014.243.012.246.01.249.008.253.006.256.003.259.001.26-.001.257-.003.254-.006.25-.008.247-.01.244-.012.241-.015.237-.016.233-.018.231-.02.226-.022.224-.024.22-.025.216-.027.212-.029.21-.03.205-.032.202-.033.198-.035.194-.036.191-.037.187-.039.183-.039.179-.041.175-.042.172-.043.168-.044.163-.045.16-.045.155-.047.152-.047.148-.048.143-.048.139-.05.136-.049.131-.05.126-.051.123-.051.118-.051.114-.052.11-.052.106-.052.101-.052.096-.052.092-.052.088-.052.083-.052.079-.052.074-.051.07-.052.065-.051.06-.05.056-.051.051-.049.023-.025.023-.024.021-.025.02-.024.019-.024.018-.024.017-.024.015-.023.014-.023.013-.024.012-.022.01-.023.01-.023.008-.022.006-.022.006-.022.004-.021.004-.022.001-.021.001-.021v-4.139l-.077.054-.08.054-.083.054-.085.052-.087.053-.09.051-.093.051-.095.051-.097.05-.1.049-.102.049-.105.048-.106.047-.109.047-.111.046-.114.045-.115.044-.118.044-.12.044-.122.042-.124.042-.126.041-.128.04-.13.039-.132.039-.134.038-.135.037-.138.036-.139.036-.142.035-.143.033-.144.033-.147.033-.148.031-.15.03-.151.03-.153.028-.154.028-.156.027-.158.026-.159.025-.161.024-.162.023-.163.022-.165.021-.166.02-.167.019-.169.018-.169.017-.171.016-.173.015-.173.014-.175.013-.175.012-.177.011-.178.009-.179.009-.179.007-.181.007-.182.005-.182.004-.184.003-.184.002h-.37l-.184-.002-.184-.003-.182-.004-.182-.005-.181-.007-.179-.007-.179-.009-.178-.009-.176-.011-.176-.012-.175-.013-.173-.014-.172-.015-.171-.016-.17-.017-.169-.018-.167-.019-.166-.02-.165-.021-.163-.022-.162-.023-.161-.024-.159-.025-.157-.026-.156-.027-.155-.028-.153-.028-.151-.03-.15-.03-.148-.031-.146-.033-.145-.033-.143-.033-.141-.035-.14-.036-.137-.036-.136-.037-.134-.038-.132-.039-.13-.039-.128-.04-.126-.041-.124-.042-.122-.043-.12-.043-.117-.044-.116-.044-.113-.046-.112-.046-.109-.046-.106-.047-.105-.048-.102-.049-.1-.049-.097-.05-.095-.051-.093-.051-.09-.051-.087-.053-.085-.052-.083-.054-.08-.054-.077-.054v4.139zm0-5.666v.011l.001.02.003.022.004.021.005.022.006.021.007.022.009.023.01.022.011.023.012.023.013.023.015.023.016.024.017.024.018.023.019.024.021.025.022.024.023.024.024.025.052.05.056.05.061.05.066.051.07.051.075.052.079.051.084.052.088.052.092.052.097.052.102.052.105.051.11.052.114.051.119.051.123.051.127.05.131.05.135.05.139.049.144.048.147.048.152.047.155.046.16.045.163.045.167.043.171.043.176.042.178.04.183.04.187.038.19.037.194.036.197.034.202.033.204.032.209.03.212.028.216.027.219.025.222.024.226.021.23.02.233.018.236.017.24.014.243.012.246.01.249.008.253.006.256.003.259.001.26-.001.257-.003.254-.006.25-.008.247-.01.244-.013.241-.014.237-.016.233-.018.231-.02.226-.022.224-.024.22-.025.216-.027.212-.029.21-.03.205-.032.202-.033.198-.035.194-.036.191-.037.187-.039.183-.039.179-.041.175-.042.172-.043.168-.044.163-.045.16-.045.155-.047.152-.047.148-.048.143-.049.139-.049.136-.049.131-.051.126-.05.123-.051.118-.052.114-.051.11-.052.106-.052.101-.052.096-.052.092-.052.088-.052.083-.052.079-.052.074-.052.07-.051.065-.051.06-.051.056-.05.051-.049.023-.025.023-.025.021-.024.02-.024.019-.024.018-.024.017-.024.015-.023.014-.024.013-.023.012-.023.01-.022.01-.023.008-.022.006-.022.006-.022.004-.022.004-.021.001-.021.001-.021v-4.153l-.077.054-.08.054-.083.053-.085.053-.087.053-.09.051-.093.051-.095.051-.097.05-.1.049-.102.048-.105.048-.106.048-.109.046-.111.046-.114.046-.115.044-.118.044-.12.043-.122.043-.124.042-.126.041-.128.04-.13.039-.132.039-.134.038-.135.037-.138.036-.139.036-.142.034-.143.034-.144.033-.147.032-.148.032-.15.03-.151.03-.153.028-.154.028-.156.027-.158.026-.159.024-.161.024-.162.023-.163.023-.165.021-.166.02-.167.019-.169.018-.169.017-.171.016-.173.015-.173.014-.175.013-.175.012-.177.01-.178.01-.179.009-.179.007-.181.006-.182.006-.182.004-.184.003-.184.001-.185.001-.185-.001-.184-.001-.184-.003-.182-.004-.182-.006-.181-.006-.179-.007-.179-.009-.178-.01-.176-.01-.176-.012-.175-.013-.173-.014-.172-.015-.171-.016-.17-.017-.169-.018-.167-.019-.166-.02-.165-.021-.163-.023-.162-.023-.161-.024-.159-.024-.157-.026-.156-.027-.155-.028-.153-.028-.151-.03-.15-.03-.148-.032-.146-.032-.145-.033-.143-.034-.141-.034-.14-.036-.137-.036-.136-.037-.134-.038-.132-.039-.13-.039-.128-.041-.126-.041-.124-.041-.122-.043-.12-.043-.117-.044-.116-.044-.113-.046-.112-.046-.109-.046-.106-.048-.105-.048-.102-.048-.1-.05-.097-.049-.095-.051-.093-.051-.09-.052-.087-.052-.085-.053-.083-.053-.08-.054-.077-.054v4.153zm8.74-8.179l-.257.004-.254.005-.25.008-.247.011-.244.012-.241.014-.237.016-.233.018-.231.021-.226.022-.224.023-.22.026-.216.027-.212.028-.21.031-.205.032-.202.033-.198.034-.194.036-.191.038-.187.038-.183.04-.179.041-.175.042-.172.043-.168.043-.163.045-.16.046-.155.046-.152.048-.148.048-.143.048-.139.049-.136.05-.131.05-.126.051-.123.051-.118.051-.114.052-.11.052-.106.052-.101.052-.096.052-.092.052-.088.052-.083.052-.079.052-.074.051-.07.052-.065.051-.06.05-.056.05-.051.05-.023.025-.023.024-.021.024-.02.025-.019.024-.018.024-.017.023-.015.024-.014.023-.013.023-.012.023-.01.023-.01.022-.008.022-.006.023-.006.021-.004.022-.004.021-.001.021-.001.021.001.021.001.021.004.021.004.022.006.021.006.023.008.022.01.022.01.023.012.023.013.023.014.023.015.024.017.023.018.024.019.024.02.025.021.024.023.024.023.025.051.05.056.05.06.05.065.051.07.052.074.051.079.052.083.052.088.052.092.052.096.052.101.052.106.052.11.052.114.052.118.051.123.051.126.051.131.05.136.05.139.049.143.048.148.048.152.048.155.046.16.046.163.045.168.043.172.043.175.042.179.041.183.04.187.038.191.038.194.036.198.034.202.033.205.032.21.031.212.028.216.027.22.026.224.023.226.022.231.021.233.018.237.016.241.014.244.012.247.011.25.008.254.005.257.004.26.001.26-.001.257-.004.254-.005.25-.008.247-.011.244-.012.241-.014.237-.016.233-.018.231-.021.226-.022.224-.023.22-.026.216-.027.212-.028.21-.031.205-.032.202-.033.198-.034.194-.036.191-.038.187-.038.183-.04.179-.041.175-.042.172-.043.168-.043.163-.045.16-.046.155-.046.152-.048.148-.048.143-.048.139-.049.136-.05.131-.05.126-.051.123-.051.118-.051.114-.052.11-.052.106-.052.101-.052.096-.052.092-.052.088-.052.083-.052.079-.052.074-.051.07-.052.065-.051.06-.05.056-.05.051-.05.023-.025.023-.024.021-.024.02-.025.019-.024.018-.024.017-.023.015-.024.014-.023.013-.023.012-.023.01-.023.01-.022.008-.022.006-.023.006-.021.004-.022.004-.021.001-.021.001-.021-.001-.021-.001-.021-.004-.021-.004-.022-.006-.021-.006-.023-.008-.022-.01-.022-.01-.023-.012-.023-.013-.023-.014-.023-.015-.024-.017-.023-.018-.024-.019-.024-.02-.025-.021-.024-.023-.024-.023-.025-.051-.05-.056-.05-.06-.05-.065-.051-.07-.052-.074-.051-.079-.052-.083-.052-.088-.052-.092-.052-.096-.052-.101-.052-.106-.052-.11-.052-.114-.052-.118-.051-.123-.051-.126-.051-.131-.05-.136-.05-.139-.049-.143-.048-.148-.048-.152-.048-.155-.046-.16-.046-.163-.045-.168-.043-.172-.043-.175-.042-.179-.041-.183-.04-.187-.038-.191-.038-.194-.036-.198-.034-.202-.033-.205-.032-.21-.031-.212-.028-.216-.027-.22-.026-.224-.023-.226-.022-.231-.021-.233-.018-.237-.016-.241-.014-.244-.012-.247-.011-.25-.008-.254-.005-.257-.004-.26-.001-.26.001z"></path></symbol></defs><defs><symbol id="clock" width="24" height="24"><path transform="scale(.5)" d="M12 2c5.514 0 10 4.486 10 10s-4.486 10-10 10-10-4.486-10-10 4.486-10 10-10zm0-2c-6.627 0-12 5.373-12 12s5.373 12 12 12 12-5.373 12-12-5.373-12-12-12zm5.848 12.459c.202.038.202.333.001.372-1.907.361-6.045 1.111-6.547 1.111-.719 0-1.301-.582-1.301-1.301 0-.512.77-5.447 1.125-7.445.034-.192.312-.181.343.014l.985 6.238 5.394 1.011z"></path></symbol></defs><defs><marker id="arrowhead" refX="7.9" refY="5" markerUnits="userSpaceOnUse" markerWidth="12" markerHeight="12" orient="auto-start-reverse"><path d="M -1 0 L 10 5 L 0 10 z"></path></marker></defs><defs><marker id="crosshead" markerWidth="15" markerHeight="8" orient="auto" refX="4" refY="4.5"><path fill="none" stroke="#000000" stroke-width="1pt" d="M 1,2 L 6,7 M 6,2 L 1,7" style="stroke-dasharray: 0, 0;"></path></marker></defs><defs><marker id="filled-head" refX="15.5" refY="7" markerWidth="20" markerHeight="28" orient="auto"><path d="M 18,7 L9,13 L14,7 L9,1 Z"></path></marker></defs><defs><marker id="sequencenumber" refX="15" refY="15" markerWidth="60" markerHeight="40" orient="auto"><circle cx="15" cy="15" r="6"></circle></marker></defs><text x="301" y="80" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">1. 点击"用 Google 登录"</text> <line x1="76" y1="117" x2="525" y2="117" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="530" y="132" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">2. 生成随机 nonce</text> <text x="530" y="152" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">保存到用户 Session</text> <path d="M 530,187 C 590,177 590,217 530,207" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></path><text x="304" y="232" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">3. 重定向到 Google 授权页面</text> <text x="304" y="253" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">URL 中包含 nonce 和 scope=openid,drive.readonly</text> <line x1="528" y1="290" x2="79" y2="290" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="464" y="305" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">4. 访问授权页面</text> <line x1="76" y1="340" x2="852" y2="340" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="467" y="355" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">5. 显示登录页面</text> <line x1="855" y1="390" x2="79" y2="390" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="464" y="405" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">6. 输入 Google 账号密码</text> <line x1="76" y1="442" x2="852" y2="442" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="467" y="457" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">7. 重定向回 ExampleNote</text> <text x="467" y="477" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">(带上授权码 code)</text> <line x1="855" y1="512" x2="79" y2="512" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="301" y="527" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">8. 浏览器访问回调地址</text> <text x="301" y="547" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">(URL 中包含 code)</text> <line x1="76" y1="582" x2="525" y2="582" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="691" y="597" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">9. 用 code + client_secret</text> <text x="691" y="618" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">换取 ID Token 和 Access Token</text> <line x1="530" y1="653.5" x2="852" y2="653.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="694" y="669" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">10. 返回 ID Token 和 Access Token</text> <line x1="855" y1="703.5" x2="533" y2="703.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line><text x="530" y="719" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">11. 验证 ID Token 签名和 nonce</text> <path d="M 530,753.5 C 590,743.5 590,783.5 530,773.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></path><text x="304" y="799" text-anchor="middle" dominant-baseline="middle" alignment-baseline="middle" class="messageText" dy="1em" style="font-family: ui-sans-serif, system-ui, sans-serif; font-size: 16px; font-weight: 400;">12. 用户登录成功</text><line x1="528" y1="833.5" x2="79" y2="833.5" class="messageLine0" stroke-width="2" stroke="none" marker-end="url(#arrowhead)" style="fill: none;"></line></svg>

具体到流程上，主要的区别在 [OAuth 2.0 授权流程](https://labuladong.online/zh/algo/computer-science/oauth2-explained/) 中重定向到 Google 授权页面时，URL 中的参数不同。

这是单纯的 OAuth 2.0 授权流程：

```
https://accounts.google.com/oauth/authorize?

  response_type=code&

  client_id=examplenote_client_id&

  redirect_uri=https://examplenote.com/callback&

  scope=drive.readonly
```

这是 OIDC 授权流程：

```
https://accounts.google.com/oauth/authorize?

  response_type=code&

  client_id=examplenote_client_id&

  redirect_uri=https://examplenote.com/callback&

  scope=openid,drive.readonly&

  nonce=nonce_abc123
```

有几处区别：

- 增加了 `nonce` 参数（一个随机字符串），用于防止重放攻击。
- scope 中增加了 `openid` ，表示这是一个 OIDC 请求，授权服务器不仅会返回 access token 用于授权，还会返回 ID Token 用于用户认证。

**URL 中可以同时包含多个 scope， `openid` 用来做认证， `drive.readonly` 用来做授权，这样只需用户的一次确认，即可同时完成认证和授权** 。

接下来我们还是以 ExampleNote 网站实现「用 Google 账号登录」的例子，演示完整的 OIDC 授权码流程。

## OIDC 如何解决认证问题

回顾 OAuth 2.0 文章末尾讨论的安全问题：

> 由于授权码明文暴露于 URL，黑客很容易截获授权码，在用户之前抢先访问回调地址，从而冒充用户身份登录应用。

OIDC 的 nonce 参数就是专门用来防止这种重放攻击的，使得黑客即使截获了授权码，也无法冒充用户身份登录。

### nonce 的作用

`nonce` （Number used ONCE，一次性数字）是一个由客户端生成的随机字符串，和用户的 Session 关联，有效防止重放攻击。

请注意，这个 `nonce` 随机字符串也会出现在 URL 参数中，也就是说黑客其实也能够截获到，那么它是如何发挥作用的呢？

这就需要你理解 [Session 和 Cookie 如何协同](https://labuladong.online/zh/algo/other-skills/session-and-cookie/) 。

当用户点击「用 Google 登录」按钮时，ExampleNote 的服务器首先会在内存（或缓存）中生成该用户专属的一个 Session，类似这样：

```
"user_session_xyz456": {

  "nonce": "nonce_abc123"

}
```

随机字符串 `user_session_xyz456` 就是该用户专属的一个 Session ID，存储着该用户的一些信息，包括 nonce 值。

服务器通过 `Set-cookie` 将这个 Session ID 发送给用户浏览器，之后用户每次访问 ExampleNote 网站时都会自动携带这个 Session ID，服务端通过这个 Session ID 确定用户身份。

我们切换到黑客的视角，当黑客尝试登录时，服务端会生成另一个 `nonce` 和另一个 Session ID，类似这样：

```
"user_session_aaaa": {

  "nonce": "nonce_bbbb"

}
```

黑客即便窃取了用户的 `nonce` 值 `nonce_abc123` 也无法使用。因为黑客的 Session ID `user_session_aaaa` 关联的是 `nonce_bbbb` ，服务端会直接拒绝登录请求。

## JWT 格式的 ID Token

ID Token 是一个 **JWT（JSON Web Token）格式的签名令牌** ，包含了用户的身份信息，主要用来认证。

ID Token 和 Access Token 的区别：

- **Access Token** ：用来访问资源（授权），ExampleNote 服务器不需要解析，直接使用它访问资源服务器即可。
- **ID Token** ：用来证明身份（认证），是 JWT 格式，ExampleNote 服务器需要解析和验证，通过验证后才能成功登录。

在 [深入理解 JWT](https://labuladong.online/zh/algo/computer-science/how-jwt-works/) 这篇文章中我们已经介绍了 JWT 的组成部分，并强调它的作用不是加密，而是 **确保数据的可信度** 。

当一个用户 Tom 在 Google 完成认证后，Google 服务器会给 ExampleNote 服务器返回一个 JWT 格式的 ID Token，其 payload 可能类似这样：

```
{

  "iss": "https://accounts.google.com",

  "sub": "tom_user_id",

  "aud": "examplenote_client_id",

  "exp": 1738278000,

  "iat": 1735686000,

  "nonce": "nonce_abc123",

  "email": "tom@gmail.com",

  "name": "Tom"

}
```

关键字段说明：

- **iss（Issuer）** ：颁发者（谁签发的），即 Google 的授权服务器地址。
- **sub（Subject）** ：主体（用户的唯一标识），即用户在 Google 系统中的 ID。
- **aud（Audience）** ：受众（给谁看的），即 ExampleNote 的 Client ID
- **exp（Expiration）** ：过期时间（这个 JWT 什么时候过期）。
- **iat（Issued At）** ：颁发时间（这个 JWT 是什么时候生成的）。
- **email, name, nonce** 等：可以自定义的其他字段。

其含义是：

- 我是 Google 服务器（ `iss=https://accounts.google.com` ）。
- 这是给 ExampleNote 服务器（ `aud=examplenote_client_id` ）颁发的 JWT。
- 刚刚有个用户（ `sub=tom_user_id` ）在我这里登录了，他的信息有 `email=tom@gmail.com,name=Tom` 等。
- 这个 JWT 在 2025-01-01 07:00:00（ `iat=1735689600` ）颁发，开始生效。
- 2025-01-31 07:00:00（ `exp=1738278000` ）后，这个 JWT 过期失效。
- 你可以用 Google 的公钥来验证这个 JWT，确保上述信息真实可靠。

ExampleNote 服务器在收到这个 ID Token 后，首先用 Google 的公钥进行确保内容没有被篡改，然后检查 `aud` 字段看这个 ID token 是否是发给自己的，检查 `iat, exp` 字段确保 JWT 没有过期，检查 `nonce` 字段确保没有重放攻击，最后提取出用户信息，此次第三方登录请求成功。

## OIDC 授权码流程

下面展示 ExampleNote 实现 Google 账号登录的全流程。

首先，和 OAuth 2.0 一样，ExampleNote 的开发者需要提前在 Google 的开发者平台注册，获得 Client ID 和 Client Secret。

### 生成 nonce 并发起授权请求

用户在 ExampleNote 上点击「用 Google 登录」按钮。

ExampleNote 的服务器生成一个随机 nonce（如 `nonce_abc123` ）保存到用户 Session，并将 Session ID 通过 `Set-cookie` 发送给用户浏览器。

然后，ExampleNote 将你的浏览器重定向到 Google 的授权页面，注意 URL 包含 `nonce` 参数，且 `scope` 字段包含 `openid` 开启 OIDC 认证，类似这样：

```
https://accounts.google.com/oauth/authorize?

  response_type=code&

  client_id=examplenote_client_id&

  redirect_uri=https://examplenote.com/callback&

  scope=openid,drive.readonly&

  nonce=nonce_abc123
```

### 用户在 Google 登录并授权

用户需要完成 Google 登录，并授权 Google Driver 的只读权限。

### Google 返回授权码

Google 将用户浏览器重定向回 ExampleNote 的回调地址，并在 URL 中带上授权码：

```
https://examplenote.com/callback?code=AUTH_CODE_12345
```

这一步和 OAuth 2.0 完全一样。

### 用授权码换取 ID Token

用户浏览器被重定向到 `https://examplenote.com/callback?code=AUTH_CODE_12345` ，ExampleNote 的服务器从 URL 中拿到授权码。

然后，ExampleNote 的服务器向 Google 的 Token 端点发起请求：

```
POST https://oauth2.googleapis.com/token

Content-Type: application/x-www-form-urlencoded

grant_type=authorization_code&

code=AUTH_CODE_12345&

redirect_uri=https://examplenote.com/callback&

client_id=examplenote_client_id&

client_secret=examplenote_secret
```

这一步也和 OAuth 2.0 一样。

### Google 返回 ID Token 和 Access Token

Google 验证授权码和 `client_secret` 后，返回一个 JSON：

```
{

  "access_token": "example.abcdefg...",

  "token_type": "Bearer",

  "expires_in": 3600,

  "id_token": "eyJhbG..."

}
```

和 OAuth 2.0 相比，OIDC 的响应多了一个 **`id_token`** 字段，这就是 JWT 格式的 ID Token。

### 验证 ID Token

ExampleNote 需要验证 ID Token 的合法性，并检查 `nonce` 字段和用户 Session 中的 nonce 值是否一致，确保没有重放攻击。

### 成功登录 ExampleNote

验证成功后，ExampleNote 可以更新用户信息，更新 Session 标记用户已登录，此次第三方登录请求成功。

同时，ExampleNote 也可以使用 Access Token 访问用户 Google Drive。

## OIDC vs OAuth 2.0

| 特性 | OAuth 2.0 | OIDC |
| --- | --- | --- |
| **用途** | 授权（你能做什么） | 认证 + 授权（你是谁 + 你能做什么） |
| **核心产物** | Access Token | ID Token + Access Token |
| **Token 格式** | 任意，客户端不需要解析 | JWT，客户端需要解析和验证 |
| **scope 参数** | 自定义（如 `drive.readonly` ） | 必须包含 `openid` |
| **nonce 参数** | 可选 | 必须（用于防重放攻击） |
| **典型场景** | 第三方应用访问用户资源 | 第三方登录、单点登录（SSO） |

总结一下：

- OIDC 是构建在 OAuth 2.0 之上的认证协议，它复用了 OAuth 2.0 的授权码流程，可以同时做授权（Access Token）和认证（ID Token）。
- OIDC 会额外获取一个 JWT 格式的 ID Token，用于证明用户刚刚完成了身份认证。
- nonce 参数防止重放攻击，将 nonce 和用户会话绑定，即使授权码被截获也无法冒充用户。

更新时间：2026/02/17 14:24

## 评论

Markdown

Ctrl+Enter 发表