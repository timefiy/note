---
title: "VPS基本安全措施 - 开发调优"
source: "https://linux.do/t/topic/267502"
author:
  - "[[LINUX DO]]"
published: 2025-11-07
created: 2026-02-07
description: "前言当我们拿到 VPS 之后，我们都需要做些什么呢？ 如果选择将网站 / 服务放在知名厂商虚拟主机上，虚拟主机的厂商会负责基本的服务器安全措施。但如果放在 VPS 上，那么你就是服务器的安全负责人了。更多的权限代表着更多的义务，VP…"
tags:
  - "clippings"
---
# VPS基本安全措施 - 开发调优
## 由 Raven95676 发布于 2025 年 11月 7 日

[鸦羽](https://linux.do/u/raven95676) [Raven95676](https://linux.do/u/raven95676) 不二之选

[2025 年 11月](https://linux.do/t/topic/267502 "发布日期")

## 前言

当我们拿到 VPS 之后，我们都需要做些什么呢？

如果选择将网站 / 服务放在知名厂商虚拟主机上，虚拟主机的厂商会负责基本的服务器安全措施。但如果放在 VPS 上，那么你就是服务器的安全负责人了。更多的权限代表着更多的义务，VPS 在具有更高的自由度的情况下自然有更高的风险。 **而我们要做到的不是绝对安全，而是比大多数人安全。** 只要做到没那么容易被攻破那就是胜利。

本文使用的环境为 Ubuntu 24.04 LTS，其他发行版可大致参照思路。

在继续阅读本文之前，建议提前阅读由 [LUG@USTC](https://lug.ustc.edu.cn/) 编写的： [https://101.lug.ustc.edu.cn/](https://101.lug.ustc.edu.cn/)

> Note
> 
> 本文与 [GitHub - ustclug/Linux101-docs: Linux 101 学生课程教材与讲义](https://github.com/ustclug/Linux101-docs) 项目无关

佬友们可以看看本文有没有什么需要补充的（

## 安全管理系统

有些 VPS 厂商默认提供的是 root 账户。众所周知，root 账户拥有整个系统最高的权限，这么高的权限自然是不安全的。正确的做法是创建一个非 root 账户，在必须使用 root 权限时使用 sudo 提权。

### 创建非 root 账户

使用以下命令创建一个具有提权能力的账户：

```bash
useradd -m -G sudo -s /bin/bash 用户名
```

然后我们给这个用户设置一个至少为 16 位的随机大小写字母 + 数字的密码（个人建议的最低安全性需求）：

```bash
passwd 用户名
```

### 禁用 root SSH 密码登陆

先不提 root 登录本身就是危险的行为，root 账户的用户名固定为”root”，如果允许其通过密码登录，攻击者只需进行密码穷举即可尝试攻破系统。之前我们已经创建了非 root 账户，在这里我们只需要禁用 root 账户的 SSH 登录即可。

执行以下命令编辑 SSH 配置文件：

```bash
sudo vim /etc/ssh/sshd_config
```

进行如下设置：

之后重启 SSH 服务生效：

```bash
sudo systemctl restart ssh
```

为什么不设置成no：

### 修改 SSH 端口号

正常情况下，直接通过 `sudo vim /etc/ssh/sshd_config` 修改SSH端口，然后再使用 `sudo systemctl restart ssh.service` 重启SSH服务应用更改是可行的：

但是在 **Ubuntu 22.10 或更高版本** 中各位可能发现这是 **无效** 的，各位会发现SSH服务在重启后依然监听原端口。

因为在Ubuntu 22.10 或更高版本中，ssh 默认通过套接字激活。

在 Ubuntu 22.10、Ubuntu 23.04 和 Ubuntu 23.10 中进行修改的方法是：

```bash
sudo mkdir -p /etc/systemd/system/ssh.socket.d
sudo vim /etc/systemd/system/ssh.socket.d/listen.conf
sudo systemctl daemon-reload
sudo systemctl restart ssh.socket
sudo systemctl restart ssh.service
```

listen.conf的参考配置为：

```bash
[Socket]
ListenStream=
ListenStream=2233
```

在 Ubuntu 24.04 中进行修改的方法是：

```bash
sudo vim /etc/ssh/sshd_config
sudo systemctl daemon-reload
sudo systemctl restart ssh.service
```

如果不在乎通过套接字激活节省的内存，可以通过以下命令恢复到非套接字激活：

> Caution
> 
> **警告：** 务必确认配置文件正常。

```bash
sudo systemctl disable --now ssh.socket
sudo systemctl enable --now ssh.service
```

如有配置迁移（Ubuntu 22.10及以上，Ubuntu 24.04以下）：

```bash
sudo systemctl disable --now ssh.socket
rm -f /etc/systemd/system/ssh.service.d/00-socket.conf
rm -f /etc/systemd/system/ssh.socket.d/addresses.conf
sudo systemctl daemon-reload
sudo systemctl enable --now ssh.service
```

### Fail2ban 防暴力破解 SSH

执行以下命令安装 Fail2ban：

```bash
sudo apt install fail2ban
```

官方推荐的做法是利用 jail.local 来进行自定义设置：

```bash
sudo vim /etc/fail2ban/jail.local
```

可以参照以下配置文件来进行自己的配置（记得删注释）：

```bash
[sshd]
ignoreip = 127.0.0.1/8 # 白名单
enabled = true
filter = sshd
port = 22 # 端口，改了的话这里也要改
maxretry = 5 # 最大尝试次数
findtime = 300 # 多少秒以内最大尝试次数规则生效
bantime = 600 # 封禁多少秒，-1是永久封禁（不建议永久封禁）
action = %(action_)s[port="%(port)s", protocol="%(protocol)s", logpath="%(logpath)s", chain="%(chain)s"] # 不需要发邮件通知就这样设置
banaction = iptables-multiport # 禁用方式
logpath = /var/log/auth.log # SSH 登陆日志位置
```

### 通知服务器SSH登录

可以通过 PAM 模块在每次ssh登录时触发脚本来实现。

编辑 `/etc/pam.d/sshd` ，在文件末尾添加：

```cpp
session    optional    pam_exec.so 脚本路径
```

对于提到的用例，脚本大致如下：  
参照： [消息推送配置说明 - 文档 - 企业微信开发者中心](https://developer.work.weixin.qq.com/document/path/91770)

2024年11月26日注：修复了示例脚本的一些问题。

```bash
#!/bin/bash

if [ "$PAM_TYPE" != "open_session" ]; then
    exit 0
fi

ip=$PAM_RHOST
date=$(date +"%e %b %Y, %a %r")
name=$PAM_USER

webhook_url="https://qyapi.weixin.qq.com/cgi-bin/webhook/send?key=xxxxxxxxxxxxxxx"

curl -s -X POST "$webhook_url" \
    -H "Content-Type: application/json" \
    -d "{
    \"msgtype\": \"markdown\",
    \"markdown\": {
        \"content\": \"**登录提醒**\\n> 登录用户: $name\\n> 客户端IP: $ip\\n> 登录时间: $date\"
    }
}"
```

请根据自己的用例替换api及调用方式。

写完了脚本需要给脚本加上运行权限。

### 【严格】使用绝对路径运行命令

使用绝对路径可以精准指定要运行的程序或文件，可避免因环境变量被篡改等原因误执行潜在的恶意程序。

### 使用密钥登录

> Note
> 
> 如果 VPS 厂商提供了 SSH 密钥绑定功能，可以忽略本节内容并按照 VPS 厂商提供的方法绑定。

在 powershell 中运行：

```bash
ssh-keygen -t ed25519
```

直接使用默认的密钥路径即可。密码可以留空，也可以设置。

```php
Generating public/private ed25519 key pair.
Enter file in which to save the key (C:\Users\<user>/.ssh/id_ed25519): # 直接回车
Enter passphrase (empty for no passphrase): # 可以留空，也可以设置
Enter same passphrase again: # 和上一个一样
```

然后我们在 VPS 上编辑 SSH 授权密钥文件：

```bash
vim ~/.ssh/authorized_keys
```

之后打开 C:\\Users<user>/.ssh/id\_ed25519.pub，复制其内容并粘贴过去。

执行以下命令编辑 SSH 配置文件：

```bash
sudo vim /etc/ssh/sshd_config
```

进行如下设置：

```bash
PubkeyAuthentication yes
AuthorizedKeysFile .ssh/authorized_keys
PasswordAuthentication no
```

之后重启 SSH 服务生效：

```bash
sudo systemctl restart ssh
```

### 启用 UFW 防火墙

> Note
> 
> 如果 VPS 厂商提供了防火墙功能，且没有复杂的需求，可以忽略本节内容并使用 VPS 厂商提供的防火墙。

在正式启用 UFW 之前，我们需要先设置规则。我们首先来设置 UFW 的默认行为：

```bash
sudo ufw default allow outgoing # 默认允许所有数据出站
sudo ufw default deny incoming # 默认禁止所有数据入站
```

我们可以通过以下命令查看 UFW 当前生效的规则：

```bash
sudo ufw status
sudo ufw status numbered  # 加上数字编号
```

我们可以通过以下命令允许或拒绝某端口的传入 / 传出流量（部分以 22、80、443 端口为例）：

```bash
# 允许22端口的proto协议的流量入站
sudo ufw allow in 22/proto

#允许22端口的proto协议的流量出站
sudo ufw allow out 22/proto

# 在未指定in/out的情况下，默认为in
sudo ufw allow 22/proto

# 在未指定proto的情况下，默认为tcp和udp
sudo ufw allow 22

# 拒绝的话就把allow改成deny
sudo ufw deny 22

# 允许从start_port到end_port的端口
sudo ufw allow start_port:end_port

# 允许复数个端口，以英文逗号分隔
sudo ufw allow port1,port2

# 允许来自于特定ip或cidr段的流量
sudo ufw allow from ip/cidr

# 允许来自于特定ip或cidr段端口22的流量
sudo ufw allow from ip/cidr to any port 22

# 允许来自于特定ip或cidr段端口22的tcp协议的流量
sudo ufw allow from ip/cidr to any proto tcp port 22

# 如果指定复数个端口，则必须指定协议
sudo ufw allow from ip to any proto tcp port 80,443

# comment用于注释
sudo ufw allow from ip to any proto tcp port 80,443 comment "hello"
```

我们可以通过以下命令删除生效的规则：

```bash
sudo ufw delete allow 22 # 在规则前面加个delete
sudo ufw delete 1 # 按照numbered的编号删除也行
```

在确定所有规则均成功设置后，通过以下命令启动 \\ 关闭 \\ 重启 UFW

> Caution
> 
> 启动防火墙前务必保证 22 端口（或者其他 SSH 端口）被放行。

```bash
sudo ufw enable|disable|reload
```

如果需要重置规则，请使用：

> Caution
> 
> 重置规则前务必保证 UFW 处于关闭状态。

```bash
sudo ufw reset
```

本人建议仅放行正在使用的端口，比如22、80、443。

默认情况下，UFW仅记录不符合规则的被拒绝的数据包。如果需要记录与该服务相关的每个详细信息，可以在allow后加上log以进行记录。

### 禁止ping服务器

> 保守起见，与destination-unreachable、time-exceeded、parameter-problem相关的规则已移除。

如果需要设置ipv6的禁ping规则，可以修改 `/etc/ufw/before6.rules` ：

```bash
-A ufw6-before-output -p icmpv6 --icmpv6-type echo-request -j DROP
-A ufw6-before-output -p icmpv6 --icmpv6-type echo-reply -j DROP
```

注意： **其余icmpv6规则应保持不变** 。

### 限定SSH登录IP

如果拥有动态公网IP且厂商支持通过接口修改防火墙规则，可以直接使用厂商的接口。

也可以使用ufw进行设置。

还可以使用VPS厂商提供的防火墙（如果支持），如果出现连接问题更方便更改配置。

[orcaterm](https://orcaterm.cloud.tencent.com/) 添加其他厂商云服务器步骤：

[![image](https://linux.do/uploads/default/original/4X/4/8/0/480537e508156f410dc4623fc62898f5b80b9bb2.png)](https://linux.do/uploads/default/original/4X/4/8/0/480537e508156f410dc4623fc62898f5b80b9bb2.png "image")

[![image](https://linux.do/uploads/default/original/4X/4/9/3/4936704193e8061ce60a5676456df3c51c3b49c8.png)](https://linux.do/uploads/default/original/4X/4/9/3/4936704193e8061ce60a5676456df3c51c3b49c8.png "image")

[![image](https://linux.do/uploads/default/optimized/4X/3/b/6/3b657563e3191669683bfe208ff555b61a0a76a2_2_513x500.png)](https://linux.do/uploads/default/original/4X/3/b/6/3b657563e3191669683bfe208ff555b61a0a76a2.png "image")

## 保证软件更新

### 日常更新系统

个人建议定期登录 VPS 运行 `sudo apt update && sudo apt upgrade` 来保证 VPS 内所有软件包均为最新。

不过 Ubuntu 默认会每天自动安装系统的安全更新，所以说这个频率没必要太勤。

### 开启 Ubuntu Pro

> 同样出色的操作系统，更多的安全更新  
> 将平均 CVE（通用漏洞披露）暴露时间从 98 天减少到 1 天  
> 具备扩展的 CVE 补丁、十年的安全维护、可选的支持和对整个开源应用程序堆栈的维护。

上面是 Ubuntu 官方的广告词。到底多有用我不知道，有修复总比没修复好，而且个人免费 5 台机器，开了不亏。

我们先来创建一个 Ubuntu One 帐户： [https://ubuntu.com/login](https://ubuntu.com/login)

注册结束之后，转到 [https://ubuntu.com/pro/dashboard](https://ubuntu.com/pro/dashboard) 查看 Token。

[![](https://linux.do/uploads/default/optimized/4X/9/2/3/923241063ed05f65dcd54d7b49629b697fee9e9e_2_690x435.jpeg)](https://linux.do/uploads/default/original/4X/9/2/3/923241063ed05f65dcd54d7b49629b697fee9e9e.jpeg)

得到了Token之后，前往我们的VPS，运行 `sudo pro attach [YOUR_TOKEN]` 。等待一段时间，我们的VPS就成功开启Ubuntu Pro了。建议在开启之后再运行一次 `sudo apt update && sudo apt upgrade` 以确保系统安装了最新的安全更新。

## 隐藏公网 IP

### 防止 SSL 证书泄露 IP

> Note
> 
> 本节 “防止 SSL 证书泄露 IP” 引自 “如何避免证书泄露源站 IP”，作者为秋未萌，根据 CC BY-SA 4.0 授权协议发布。本文其他部分根据 CC BY-NC-SA 4.0 授权协议发布，但本节内容使用 CC BY-SA 4.0 授权协议。

#### 申请并下载证书

- 注册并且登录 [ZeroSSL](https://app.zerossl.com/login)
- 到 [Dashboard](https://app.zerossl.com/dashboard) 找到 Create SSL Certificate，点击 New Certificate 蓝色按钮
- 在 Enter Domains 处输入源站 IP
- 其实过期也无妨，总之不让 censys 扫描到真正的域名证书就可以。因此选择 90 天证书
- CSR & Contat 保持不变
- 验证域名的办法选择 HTTP File Upload
	- 使用 NGINX 的话，如果你保持原先设置不变，即 `/etc/nginx/sites-available/default` 不变就没问题。当然，如果你改变了，记得保留 `server {listen 80; root /var/www/html;}` 就可以
	- 然后下载 Auth File，并且把它上传到 `/var/www/html/.well-known/pki-validation` 。如果没有文件夹，就新建，记得让 NGINX 有权访问这些文件，否则还是会失败
	- 按照提示，点击一下`.txt` 文件是不是可以访问。成功的话，就验证好了

#### 配置证书并且设置禁止 IP 80/433 的 HTTP 访问

- 下载 `*.zip` 文件，解压它。解压好的文件夹里面有好申请到的证书
- 将 `ca_bundle.crt` 和 `certificate.crt` 合并，方法是用 notepad3 或者 vsode 等可靠的编辑器打开 `certificate.crt` 。然后把 `ca_bundle.crt` 内容复制进去。格式是：
```bash
-----BEGIN CERTIFICATE-----
certificate.crt内容
-----END CERTIFICATE-----
-----BEGIN CERTIFICATE-----
ca_bundle.crt内容
-----END CERTIFICATE-----
```
- 上传合并好的文件和 `private.key`
- 上传证书到一个 Nginx 有权限的文件夹，咱放在 `/etc/nginx/ip-certificate/`
- 设置 `/etc/nginx/sites-available/default` 文件。参考设置如下：
```perl
server {    
#HTTP Server Default Set    
    listen 80;
    listen 443 ssl http2 default_server;
    server_name ip;     

    #HTTP_TO_HTTPS_END    
    ssl_certificate /etc/nginx/ip-certificate/certificate.crt;
    ssl_certificate_key /etc/nginx/ip-certificate/private.key;
    ssl_protocols TLSv1.1 TLSv1.2 TLSv1.3;
    ssl_ciphers ECDHE-RSA-AES128-GCM-SHA256:HIGH:!aNULL:!MD5:!RC4:!DHE;
    ssl_prefer_server_ciphers on;
    ssl_session_cache shared:SSL:10m;
    ssl_session_timeout 10m;
    
    #Server ROOT
    index index.html;
    root /var/www/html/;
    index index.html;

    return 444; #NGINX HTPP Code 444

}
```

服务器后台输入 `nginx -t` 检查是否有误，正确即可 `sudo systemctl restart nginx` 重启。

直接输入 IP 作为网址检查是不是连接后立刻变成空白页

### Nginx 1.19.4 之后的新方法

如果各位的 Nginx 版本大于等于 1.19.4，可以直接使用 ssl\_reject\_handshake 配置项，通过简单的配置就能拒绝所有未匹配到域名的 TLS 握手：

```csharp
server {
    listen 443 ssl default_server;
    server_name _;
    ssl_reject_handshake on;
}
```

如果出现如 `nginx: [emerg] unknown directive “ssl_reject_handshake”` 的报错，首先请检查nginx版本是否大于等于1.19.4。 `ssl_reject_handshake on;` 在nginx 1.19.4 主线版加入。  
如果是通过源代码编译安装的，请确认ngx\_http\_ssl\_module模块是否启用。 该模块不是默认构建的，需要通过 `--with-http_ssl_module` 配置参数来启用。

### 真的安全了吗

前文中，我们只能确保攻击者无法通过直接访问 ip 获取默认证书来推断域名信息。然而又没有规定说攻击者只能用这种方式获取 IP 与域名的对应关系。可以看出，前文的规则依赖于 server\_name 的匹配。攻击者完全可以携带正确的 server\_name 握遍所有可能的非已知 CDN 的 IP 段，记录正确响应的目标。下面是判断（不包含遍历）的简单实现：

```python
# https://gist.github.com/Raven95676/39ffdba22144e39d7155ad9dc1bcca55
import ssl
import socket
def check(ip, domain):
    try:
        context = ssl.create_default_context()
         with socket.create_connection((ip, 443)) as sock:
            with context.wrap_socket(sock, server_hostname=domain) as ssl_sock:
                request = f"GET / HTTP/1.1\nHost: {domain}\nConnection: close\n\n"
                ssl_sock.sendall(request.encode())
                ssl_sock.recv(4096)
        return True
    except Exception:
        return False

print(check("192.168.0.256", "example.com"))
```

### 于是我们打个补丁

> 如果 VPS 厂商提供了防火墙功能，可以直接使用 VPS 厂商提供的防火墙。

~~各位可以直接用这个方法~~

我们可以仅允许 CDN 的 CIDR 段访问服务器的 80/443 端口。先来添加允许的规则：

```python
sudo ufw allow from "cidr段" to any proto tcp port 80,443 comment "CDN服务商"
```

comment 不是必须的，只是为了方便日后能认出来这规则是干什么的才加上的。

CDN 的 CIDR 段去找 cdn 服务商要，有的在官网也有公示。比如 Cloudflare 的CIDR 段可以从这个网页获取： [https://www.cloudflare.com/ips-v4](https://www.cloudflare.com/ips-v4)  
上面那个是 ipv4 的，ipv6 的可以从这个网页获取： [https://www.cloudflare.com/ips-v6](https://www.cloudflare.com/ips-v6)

对于 Cloudflare ，还有佬友编写的脚本可以在执行后更新 CF IP 到 ufw 443。

由于特殊情况的存在，本人建议在部署该脚本之前先执行以下命令查看是否正确输出。

```bash
for cfip in \`curl -sw '\n' https://www.cloudflare.com/ips-v{4,6}\`; do echo $cfip; done
```

如果输出正常（如下），则可以部署：

```ruby
173.245.48.0/20
103.21.244.0/22
…略
2400:cb00::/32
2606:4700::/32
…略
```

添加完了之后我们使用以下命令查看防火墙现有规则列表：

```bash
sudo ufw status numbered
```

使用以下命令删除之前可能存在的针对 80 和 443 端口允许所有流量的规则：

```bash
sudo ufw delete 序号
```

为什么不直接使用 Nginx 的 deny 配置项呢？因为 deny 会返回 403 Forbidden 状态码，而在此之前必须完成 TLS 握手。只有在 TLS 握手成功后，客户端才能发送 HTTP 请求并接收到响应。如果直接使用 deny，我们相当于在做无用功。

### 真的安全了……吗？

这其实算是 Cloudflare 特辑，不过如果使用其他 CDN 提供商，为了增强安全性也可以参考。众所周知，Cloudflare 不仅提供 CDN 服务，还有一系列其他产品，比如 Workers 和 WARP。而这些服务有一些需要注意的特点：

- 能对外发出请求
- 用的是 Cloudflare 的 IP 段

虽然 Cloudflare 对于滥用肯定是限制的，但是为了以防万一，我们还可以再做点安全措施 —— 经过身份验证的源服务器拉取。

> 必须确保SSL/TLS加密模式为完全或者完全（严格）

下载 [Cloudflare证书](https://developers.cloudflare.com/ssl/static/authenticated_origin_pull_ca.pem) 并进行配置即可。

```csharp
ssl_client_certificate 证书地址;
ssl_verify_client on;
```

然后在 SSL/TLS→源服务器这里开启经过身份验证的源服务器拉取。

**雷池WAF社区版目前暂时无法稳定使用此方法，除非乐意在雷池前面再叠一层反代。**

## 迈向全面容器化

> Note
> 
> 本节暂不涉及1panel等运维面板或portainer等docker面板。

### Docker基本使用

> Note
> 
> 发现成熟的文档，不再重复造轮子。  
> 本文与 [GitHub - yeasy/docker\_practice: Learn and understand Docker&Container technologies, with real DevOps practice!](https://github.com/yeasy/docker_practice) 项目无关  
> ~~小小的偷个懒~~

附注：如果 `docker-compose` 提示找不到命令，试试 `docker compose` 。docker compose现已弃用 `version` 字段，现有的compose配置文件中 `version` 字段将被忽略并显示一条警告。

更新：添加Docker官中文档。

[https://docs.docker.net.cn/manuals/](https://docs.docker.net.cn/manuals/)

### UFW管不了Docker的解决方案（推荐）

此外，如果需要阻止外部端口访问，除去仅在127.0.0.1监听外还可以：

### UFW管不了Docker的解决方案（不太推荐）

> 本节 “UFW管不了Docker的解决方案（不太推荐）” 引自项目 **[ufw-docker](https://github.com/chaifeng/ufw-docker)** 的README，作者为 [chaifeng](https://github.com/chaifeng) ，根据 GPL-3.0 license 授权协议发布。本文其他部分根据 CC BY-NC-SA 4.0 授权协议发布，但本节内容使用 GPL-3.0 license 授权协议。

目前新的解决方案只需要修改一个 UFW 配置文件即可，Docker 的所有配置和选项都保持默认。

修改 UFW 的配置文件 `/etc/ufw/after.rules` ，在最后添加上如下规则：

```bash
# BEGIN UFW AND DOCKER
*filter
:ufw-user-forward - [0:0]
:ufw-docker-logging-deny - [0:0]
:DOCKER-USER - [0:0]
-A DOCKER-USER -j ufw-user-forward

-A DOCKER-USER -j RETURN -s 10.0.0.0/8
-A DOCKER-USER -j RETURN -s 172.16.0.0/12
-A DOCKER-USER -j RETURN -s 192.168.0.0/16

-A DOCKER-USER -p udp -m udp --sport 53 --dport 1024:65535 -j RETURN

-A DOCKER-USER -j ufw-docker-logging-deny -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -d 192.168.0.0/16
-A DOCKER-USER -j ufw-docker-logging-deny -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -d 10.0.0.0/8
-A DOCKER-USER -j ufw-docker-logging-deny -p tcp -m tcp --tcp-flags FIN,SYN,RST,ACK SYN -d 172.16.0.0/12
-A DOCKER-USER -j ufw-docker-logging-deny -p udp -m udp --dport 0:32767 -d 192.168.0.0/16
-A DOCKER-USER -j ufw-docker-logging-deny -p udp -m udp --dport 0:32767 -d 10.0.0.0/8
-A DOCKER-USER -j ufw-docker-logging-deny -p udp -m udp --dport 0:32767 -d 172.16.0.0/12

-A DOCKER-USER -j RETURN

-A ufw-docker-logging-deny -m limit --limit 3/min --limit-burst 10 -j LOG --log-prefix "[UFW DOCKER BLOCK] "
-A ufw-docker-logging-deny -j DROP

COMMIT
# END UFW AND DOCKER
```

然后重启 UFW， `sudo systemctl restart ufw` 。现在外部就已经无法访问 Docker 发布出来的任何端口了，但是容器内部以及私有网络地址上可以正常互相访问，而且容器也可以正常访问外部的网络。 **可能由于某些未知原因，重启 UFW 之后规则也无法生效，请重启服务器。**

如果希望允许外部网络访问 Docker 容器提供的服务，比如有一个容器的服务端口是 `80` 。那就可以用以下命令来允许外部网络访问这个服务：

```python
ufw route allow proto tcp from any to any port 80
```

这个命令会允许外部网络访问所有用 Docker 发布出来的并且内部服务端口为 `80` 的所有服务。

请注意，这个端口 `80` 是容器的端口，而非使用 `-p 0.0.0.0:8080:80` 选项发布在服务器上的 `8080` 端口。

如果有多个容器的服务端口为 80，但只希望外部网络访问某个特定的容器。比如该容器的私有地址为 `172.17.0.2` ，就用类似下面的命令：

```bash
ufw route allow proto tcp from any to 172.17.0.2 port 80
```

如果一个容器的服务是 UDP 协议，假如是 DNS 服务，可以用下面的命令来允许外部网络访问所有发布出来的 DNS 服务：

```python
ufw route allow proto udp from any to any port 53
```

同样的，如果只针对一个特定的容器，比如 IP 地址为 `172.17.0.2` ：

```bash
ufw route allow proto udp from any to 172.17.0.2 port 53
```

## 长亭雷池WAF+Cloudflare单节点部署

~~思来想去没啥可写的~~

### 部署

有一键部署命令：

```bash
bash -c "$(curl -fsSLk https://waf-ce.chaitin.cn/release/latest/setup.sh)"
```

或部署LTS版本：

```bash
RELEASE=lts bash -c "$(curl -fsSLk https://waf-ce.chaitin.cn/release/latest/setup.sh)"
```

由于本用例在雷池WAF前套了一层Cloudflare，所以说需要将防护站点→全局配置→源 IP 获取方式设置为“取 X-Forwarded-For 中上一级代理的地址”

如果出现其他问题，可前往官方文档 [常见问题排查 | 雷池 SafeLine](https://docs.waf-ce.chaitin.cn/zh/%E5%B8%B8%E8%A7%81%E9%97%AE%E9%A2%98%E6%8E%92%E6%9F%A5) 查询。

### 使用域名访问雷池控制台的问题

~~最佳解决方案：不用域名~~

如果我们需要通过域名访问雷池控制台，会发现启用 Cloudflare 小黄云后，域名访问无法实现。这是因为 Cloudflare 的端口转发仅支持其指定的几个端口：

解决方案也很简单，打开 规则→Origin Rules，然后创建规则。传入请求匹配表达式大致如下：

```bash
(starts_with(http.request.full_uri, "https://域名"))
```

目标端口设置重写到9443即可

为了隐藏公网IP，请设定限定仅cloudflare cdn cidr段访问9443端口的防火墙规则。

### 重定向问题

如果重定向时 URL 中意外出现端口号，可通过防护站点→站点详情→自定义 NGINX 配置添加以下内容进行解决：

```perl
proxy_redirect https://$host:[port] https://$host;
```

### 使用 WireGuard 隐藏管理面板

## 引用

- [开始使用 Ubuntu Pro 来自 Ubuntu 官网](https://ubuntu.com/pro/tutorial)
- 如何避免证书泄露源站 IP 作者：秋未萌
- [Ufw 使用指南 来自 Ubuntu 中文](https://wiki.ubuntu.org.cn/Ufw%E4%BD%BF%E7%94%A8%E6%8C%87%E5%8D%97)
- [Key-based authentication in OpenSSH for Windows 来自 Microsoft Learn](https://learn.microsoft.com/en-us/windows-server/administration/openssh/openssh_keymanagement)
- [Install Docker Engine on Ubuntu 来自docker官网](https://docs.docker.com/engine/install/ubuntu)
- [VPS基本安全措施 - # 2，来自 edwardzcn](https://linux.do/t/topic/267502/2)
- [VPS基本安全措施 - # 3，来自 Oganneson](https://linux.do/t/topic/267502/3)
- [【已解决】部署在cloudflare的域名开启代理之后就无法连接到vps - # 11，来自 MatsuzakaSato](https://linux.do/t/topic/168843/11)
- [VPS基本安全措施 - # 18，来自 OICQ](https://linux.do/t/topic/267502/18)
- [GitHub - chaifeng/ufw-docker: To fix the Docker and UFW security flaw without disabling iptables](https://github.com/chaifeng/ufw-docker)
- [VPS基本安全措施 - # 23，来自 Oganneson](https://linux.do/t/topic/267502/23)
- [VPS基本安全措施 - # 42，来自 libook](https://linux.do/t/topic/267502/42)
- [VPS基本安全措施 - # 44，来自 Staleness](https://linux.do/t/topic/267502/44)
- [VPS基本安全措施 - # 20，来自 kendo](https://linux.do/t/topic/267502/20)
- [消息推送配置说明 - 文档 - 企业微信开发者中心](https://developer.work.weixin.qq.com/document/path/91770)
- [VPS基本安全措施 - # 21，来自 alertsc](https://linux.do/t/topic/267502/21)
- [VPS基本安全措施 - # 22，来自 OICQ](https://linux.do/t/topic/267502/22)
- [VPS基本安全措施 - # 57，来自 waqian](https://linux.do/t/topic/267502/57)
- [Bug #2069041 “Changing Port in sshd\_config requires calling syst...”: Bugs: openssh package: Ubuntu](https://bugs.launchpad.net/ubuntu/+source/openssh/+bug/2069041)
- [避免网站被攻击的低成本想法 - # 29，来自 Bee](https://linux.do/t/topic/242440/29)
- [VPS基本安全措施 - # 71，来自 pama](https://linux.do/t/topic/267502/71)
- [VPS基本安全措施 - # 87，来自 sevendays](https://linux.do/t/topic/267502/87)
- [VPS基本安全措施 - # 97，来自 wordpure](https://linux.do/t/topic/267502/97)
- [VPS基本安全措施 - # 99，来自 wordpure](https://linux.do/t/topic/267502/99)
- [VPS基本安全措施 - # 108，来自 pama](https://linux.do/t/topic/267502/108)
- [VPS基本安全措施 - # 121，来自 systemoutprintlnhell](https://linux.do/t/topic/267502/121)
- [VPS基本安全措施 - # 122，来自 steve5wutongyu6](https://linux.do/t/topic/267502/122)
- [VPS基本安全措施 - # 135，来自 seamee](https://linux.do/t/topic/267502/135)
- [VPS基本安全措施 - # 175，来自 Eternal](https://linux.do/t/topic/267502/175)

> 本文在本人博客首发，二次发布于LinuxDO，于IDCFlare第三次发布。  
> 除特别声明外均采用 [CC BY-NC-SA 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/deed.zh) 许可协议。  
> 此副本已去除所有可能涉及引流的站外链接。  
> 如需转载，请您在非商业使用的情况下标明转载自本帖并附上本贴链接。  
> 如本文采纳诸位佬友的意见，相关帖子链接将会放在引用部分(所有由本人亲自转载的平台同步更新)。

![Written-By-Human-Not-By-AI-Badge-white](https://linux.do/uploads/default/original/4X/5/1/3/5137ffe7c077cecc7d0f8bbe0978436bb463c52a.png)

- [【长期帖】来推荐你心目中的精华神帖吧](https://linux.do/t/topic/188854/117)
- [关于通过1panel部署lobechat遇到的问题分享](https://linux.do/t/topic/269991)
- [不是？我真服了CSDN了，光速搬我辛苦写的教程是吧....（吐槽一下）](https://linux.do/t/topic/317075/52)
- [小型网站/服务器安全措施求教](https://linux.do/t/topic/306690/4)
- [请教docker端口不受ufw限制怎样解决？](https://linux.do/t/topic/280504/7)