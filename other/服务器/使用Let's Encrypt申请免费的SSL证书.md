# 使用Let's Encrypt申请免费的SSL证书

## 什么是Let’s Encrypt

**Let’s Encrypt** 是一个免费的、自动化的、开放的证书颁发机构（CA），提供免费 SSL 证书。它的目标是让所有网站都能轻松实现 HTTPS 加密，保障用户数据的安全。

## 什么是 Certbot

**Certbot** 是一个命令行工具，用于自动化整个 SSL 证书的管理流程。它可以做以下几件事：

- **申请证书**：使用 ACME 协议从 Let’s Encrypt 获取证书。
- **验证域名所有权**：通过 HTTP-01 或 DNS-01 验证确保你拥有该域名。
- **安装证书**：将证书自动安装到你的 Web 服务器，并配置相关的加密参数。
- **续期证书**：定期自动续期证书，避免证书过期。

Certbot 的核心工作是通过 **ACME 协议**（自动证书管理环境）与 Let’s Encrypt 通信。ACME 是一套标准协议，用于自动化证书申请、验证和安装的过程。Certbot 使用 ACME 协议与 Let’s Encrypt 进行通信，确保你的网站能够通过安全的 HTTPS 连接。

## 使用Certbot申请SSL

### 下载Certbot

```bash
sudo snap install --classic certbot
```
### 确保80端口没有被占用

申请证书时需要临时占用 `80` 端口，所以如果服务器上 Nginx 已经占着 80，要先停 Nginx。

![](assets/使用Let's%20Encrypt申请免费的SSL证书/file-20260705165236059.png)

### 申请证书

#### 单域名证书的申请

```bash
sudo certbot certonly --standalone -d mail.example.xyz

#确认证书存在 
sudo ls /etc/letsencrypt/live/mail.zhuyuxi.xyz/
```


https://www.cnblogs.com/michaelshen/p/18538178