# Docker Mailserver

## 环境变量
- **小贴士**：如果设置了名为 `<VAR>__FILE` 的环境变量，且其值为有效的文件路径，那么该文件的内容将自动成为 `<VAR>` 的实际值（前提是 `<VAR>` 本身没有被直接显式设置）。

### 常规设置 (General)

### 1. OVERRIDE_HOSTNAME

如果你无法在容器运行环境中将 DMS（文档管理系统） 的 FQDN（完全限定域名）直接设置为容器的主机名（例如在缺乏类似于 Docker `--hostname` 参数的运行时中），可以通过此变量指定。

- **留空 (empty)** => 内部会使用 `hostname --fqdn` 命令来获取分配给 DMS 容器的规范主机名。
- **指定 FQDN** => 指定一个 FQDN 来作为邮件服务的域名（DMS 正常运行所必需）。
- _注意_：此变量在启动初期就会被检查，并优先于容器本身的主机名配置。它是针对 Kubernetes 或使用 Docker `--network=host` 等环境的折中方案，Fetchmail 已知与此环境变量不兼容。

### 2. LOG_LEVEL

设置 DMS 的日志级别（主要影响容器启动脚本和变更检测事件的反馈）。

- 可选值（详细度递增）：`error`、`warn`、`info`、`debug`、`trace`。
- 默认值：**`info`**。

### 3. SUPERVISOR_LOGLEVEL

调整进程管理器 Supervisor 的日志级别。
- 可选值：`critical`（仅关键）、`error`（仅错误）、`warn`（警告）、**`info`**（普通信息）、`debug`（调试信息）。
- 日志系统会显示所设级别及以上的所有日志。

### 4. DMS_VMAIL_UID / DMS_VMAIL_GID

- 默认值：**`5000`** / **`5000`**
- 分配给静态 `vmail` 用户/组的 ID，用于管理 `/var/mail`（由 Dovecot 管理的邮件存储）。
- _注意_：不能设置为 `0` (root)。

### 5. ACCOUNT_PROVISIONER

配置用户账户（包括别名）的提供源，用于邮件服务的查询和身份验证。

- **`FILE`** => 使用本地文件。
    
- `LDAP` => 使用外部 LDAP 认证服务（例如 `bitnami/openldap`）。
    

### 6. PERMIT_DOCKER

设置 Postfix 的 `mynetworks`（信任网络）选项。

⚠️ **警告**：将 Docker 网络的网关添加到受信任主机列表可能会造成**开放转发（Open Relay）风险**（例如宿主机启用了 IPv6 但 Docker 中未启用的情况）。

- **`none`** => 显式强制身份验证。
    
- `container` => 仅限容器本身的 IP 地址。
    
- `host` => 添加 Docker 宿主机（仅限 IPv4）。
    
- `network` => 添加 Docker 默认网桥网络 (`172.16.0.0/12`)。如果使用 Docker Compose 自动生成了其他网段，请改用 `connected-networks`。
    
- `connected-networks` => 添加所有已连接的 Docker 网络（仅限 IPv4）。
    

### 7. TZ

设置时区。格式必须为 `区域/城市`（例如 `Europe/Berlin` 或 `Asia/Shanghai`）。如果留空，容器将尝试检测并使用 `/etc/localtime`。

### 8. 安全与服务开关

- **ENABLE_AMAVIS**：内容过滤器开关（用于 ClamAV 和 SpamAssassin）。默认 **`0`**（禁用），可设为 `1`（启用）。`AMAVIS_LOGLEVEL` 默认 **`0`**（警告）。
- **ENABLE_DNSBL**：Postscreen DNS 黑名单开关。默认 **`0`**（禁用）。_注意：使用公共 DNS 解析器（如 8.8.8.8）可能会导致黑名单失效，未通过检查的邮件会被直接拒绝。_
- **ENABLE_MTA_STS**：外发邮件的 MTA-STS 支持。默认 **`0`**（禁用）。
- **ENABLE_OPENDKIM / ENABLE_OPENDMARC**：OpenDKIM 和 OpenDMARC 服务开关。默认均位 **`1`**（启用）。
- **ENABLE_POLICYD_SPF**：Postfix 中的 SPF 策略检查。默认 **`0`**（禁用）。如果你使用了 Rspamd，建议将其保持为 0。
- **ENABLE_POP3 / ENABLE_IMAP**：邮件收取协议开关。POP3 默认 **`0`**（禁用），IMAP 默认 **`1`**（启用）。
- **ENABLE_CLAMAV**：ClamAV 杀毒引擎开关。默认 **`0`**（禁用）。
- **ENABLE_FAIL2BAN**：Fail2Ban 防暴力破解开关。默认 **`0`**（禁用）。_启用时必须在 Compose 文件中赋予 `cap_add: - NET_ADMIN` 权限。_
- **FAIL2BAN_BLOCKTYPE**：封禁动作。默认 **`drop`**（直接丢弃不回应），可选 `reject`（发送不达回应）。
- **SMTP_ONLY**：默认**留空**（启动所有服务），设为 `1` 则仅启动 Postfix SMTP 服务。

### 9. SSL 与加密

- **SSL_TYPE**：证书类型。
    - **留空 (empty)** => 禁用 SSL。
    - `letsencrypt` => 配合 Let's Encrypt 自动证书。
    - `manual` => 手动提供证书。需要设置 `SSL_CERT_PATH` 和 `SSL_KEY_PATH` 变量。
    - `self-signed` => 生成自签名证书，仅供本地测试，生产环境不推荐。
- **TLS_LEVEL**：TLS 安全等级。
    - **留空 (empty) / `modern`** => 现代安全模式（仅限安全的加密套件，最低要求 TLS v1.2）。
    - `intermediate` => 中等安全模式（增加老旧套件以获得更广泛的兼容性）。

### 10. 邮件限制与反欺诈

- **SPOOF_PROTECTION**：防止发件人地址伪造。
    
    - **`0`**（不推荐） => 允许伪造。任何登录用户都可以使用任意发件人地址发信。
        
    - `1` => 拒绝伪造。用户只能使用自己或属于自己的别名地址发信。
        
- **ENABLE_SRS**：发件人重写方案开关。当 DMS 作为邮件转发器时需要启用。默认 **`0`**（禁用）。
    
- **POSTFIX_MAILBOX_SIZE_LIMIT**：所有用户的邮箱总大小限制（字节）。默认 **留空 (0，不限制)**。
    
- **ENABLE_QUOTAS**：Dovecot 邮箱配额开关。默认 **`1`**（启用，仅在 `ACCOUNT_PROVISIONER=FILE` 时有效）。
    
- **POSTFIX_MESSAGE_SIZE_LIMIT**：单封邮件大小限制。默认 **留空 (10240000 字节，约 10MB)**。
    
- **DOVECOT_MAILBOX_FORMAT**：存储格式。默认 **`maildir`**（一封邮件一个文件），`sdbox` 和 `mdbox` 仍处于实验性阶段。
    

### 11. 垃圾邮件分类管理

- **MOVE_SPAM_TO_JUNK**：默认 **`0`**（垃圾邮件依然放进收件箱），设为 `1` 会自动将识别为垃圾的邮件移入客户端的“垃圾邮件 (Junk)”文件夹。
    
- **MARK_SPAM_AS_READ**：默认 **`0`**（不标记），设为 `1` 会自动将垃圾邮件标记为已读，避免客户端弹窗打扰。
    
- **SPAM_SUBJECT**：垃圾邮件的主题前缀。默认**留空**。若想添加形如 `[SPAM]` 的前缀，需要带引号包裹：`SPAM_SUBJECT='[SPAM] '`。
    
- **DMS_CONFIG_POLL**：DMS 检测配置卷和证书文件更改的轮询频率。默认 **`2`** 秒。
    

### 二、 Rspamd (现代垃圾邮件过滤系统)

- **ENABLE_RSPAMD**：默认 **`0`**（禁用），设为 `1` 启用 Rspamd 过滤。
    
- **ENABLE_RSPAMD_REDIS**：默认与 `ENABLE_RSPAMD` 保持一致。控制是否在容器内运行内置的 Redis。若想配合自己外部的 Redis 实例，可将其设为 `0` 并在 `/etc/rspamd/local.d/redis.conf` 中配置连接。
    
- **RSPAMD_CHECK_AUTHENTICATED**：是否检查已通过身份验证（通常是外发）的邮件。默认 **`0`**（不检查，但仍会进行 DKIM 签名）。
    
- **RSPAMD_GREYLISTING**：是否启用 Rspamd 灰名单模块。默认 **`0`**（禁用）。
    
- **RSPAMD_LEARN**：自动学习功能。默认 **`0`**（禁用）。开启后，用户将邮件拖入 Junk 或拉回收件箱时，系统会自动学习垃圾邮件/正常邮件特征。_注意：该数据库是全局的，需提防恶意训练。_
    
- **RSPAMD_HFILTER**：主机名过滤模块。默认 **`0`**（禁用）。开启后会提高对未知客户端主机名的惩罚权重。`RSPAMD_HFILTER_HOSTNAME_UNKNOWN_SCORE` 默认得分为 **`6`**（触发添加邮件头）。
    
- **RSPAMD_NEURAL**：实验性神经网络反垃圾邮件模块。默认 **`0`**（禁用）。
    

### 三、 日志摘要与报告设置 (Reports)

- **PFLOGSUMM_TRIGGER**：Postfix 日志摘要邮件触发器。**未设置**则不发送；可设为 `daily_cron`（发送前一天的每日报告）或 `logrotate`（在日志轮转时发送）。
    
- **PFLOGSUMM_RECIPIENT / SENDER**：报告的收件人和发件人地址。收件人未设置时默认发送给 `POSTMASTER_ADDRESS`。
    
- **LOGWATCH_INTERVAL**：Logwatch 报告时间间隔。默认 **`none`**（不生成），可选 `daily` 或 `weekly`。
    
- **LOGROTATE_INTERVAL**：内部日志文件的轮转周期。默认 **`weekly`**（每周）。_提示：为防止容器销毁（如 `down && up`）导致日志丢失，建议将宿主机目录挂载到容器的 `/var/log/mail/`_。
    

### 四、 SpamAssassin (传统垃圾邮件分析引擎)

- **ENABLE_SPAMASSASSIN**：默认 **`0`**（禁用）。分析入站邮件并计算垃圾邮件得分。
    
- **ENABLE_SPAMASSASSIN_KAM**：是否启用第三方 KAM 规则集。默认 **`0`**（禁用）。
    
- **SPAMASSASSIN_SPAM_TO_INBOX**：当邮件被判定为垃圾邮件时的底层动作。
    
    - **`0`** => 直接退信（Bounce）且不通知发件人（较为激进和危险）。
        
    - `1` => 允许投递到收件箱（通常配合上面的 `MOVE_SPAM_TO_JUNK=1` 组合使用）。
        
- **SA_TAG**：默认 **`2.0`**。得分等于或高于此值时，邮件会被添加诊断用的 `X-Spam` 响应头（但此时邮件还不会被认定为垃圾邮件）。
    
- **SA_TAG2**：默认 **`6.31`**。得分高于此级别时，正式将邮件打上“垃圾邮件”标签（修改响应头为 `X-Spam-Flag: YES`）。
    
- **SA_KILL**：默认 **`10.0`**。高危垃圾邮件阈值。达到此得分的邮件会被强制**隔离**（默认存储在 `/var/lib/amavis/virusmails/` 中）。
    

### 五、 邮件外部抓取 (Fetchmail & Getmail)

- **ENABLE_FETCHMAIL / FETCHMAIL_POLL**：从外部 POP3/IMAP 服务器抓取邮件的工具。默认 **`0`**（禁用），轮询时间默认 **`300`** 秒。
    
- **ENABLE_GETMAIL / GETMAIL_POLL**：另一种邮件抓取工具。默认 **`0`**（禁用），轮询时间默认 **`5`** 分钟。
    

### 六、 外部目录服务与认证 (LDAP / SASL / DOVECOT)

这一部分包含大量的变量（如 `LDAP_SERVER_HOST`, `LDAP_SEARCH_BASE`, `DOVECOT_USER_FILTER` 等），当你的 `ACCOUNT_PROVISIONER` 设置为 `LDAP` 时，这些变量用来建立与企业内部 LDAP/Active Directory 服务器的连接，重写 Dovecot 和 Postfix 的用户、别名、域名的查询过滤规则（Filter Maps）。

### 七、 邮件中继服务器设置 (Relay Host)

当你的服务器出网 **25 端口被云服务商封禁**，或者你想提高邮件的投递成功率时，需要配置第三方中继（如 SendGrid、Mailgun 等）。

> 💡 **官方建议**
> 
> 优先使用 `DEFAULT_RELAY_HOST`，而不是过时的 `RELAY_HOST` 变量。

- **DEFAULT_RELAY_HOST**：配置默认的外部中继服务器。
    
    - 语法示例：`[mail.example.com]:587`（带方括号可以跳过该域名的 MX 记录查询，直接请求其 A 记录）。
        
- **RELAY_PORT**：中继端口，默认 **`25`**（配合中继时通常会改为 587 或 465）。
    
- **RELAY_USER / RELAY_PASSWORD**：第三方中继服务的验证账号和密码。配置后 DMS 将强制采用安全加密连接向中继服务认证外发。

## 邮件知识

### 邮件协议

| 协议         | 默认端口 | 作用            | 是否需要加密      |
| ---------- | ---- | ------------- | ----------- |
| SMTP       | 25   | 邮件服务器之间发送邮件   | 支持 STARTTLS |
| SMTPS      | 465  | 邮件客户端发送邮件（加密） | 默认 TLS      |
| Submission | 587  | 邮件客户端发送邮件（推荐） | STARTTLS    |
| IMAP       | 143  | 接收邮件          | 支持 STARTTLS |
| IMAPS      | 993  | 接收邮件（加密）      | 默认 TLS      |
