# JAVA
## 一. 配置项目所需环境

### jdk安装

#### 1.1 安装jdk

##### 1.1.1 找到安装包,双击打开

jdk: java development kit java开发工具包

17.0.13: 17版本

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763343254745-9ec07b28-e558-4c73-9a75-7370bb96477c.png)

##### 1.1.2 下一步

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763343353964-8a384b29-b128-4d4a-8ce2-ba191ca465a2.png)

##### 1.1.3 先新建一个文件夹命名Java

在其内新建两个文件夹 分别命名JDK,JRE

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783385513864-b4859a40-c54b-4d3f-8bac-8eda2db1d714.png)

##### 1.1.4 在安装程序中选择jdk路径

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763343385990-e5f6078d-57a6-42e2-be9d-3c4aa8016705.png)

##### 1.1.5 成功

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277312436-1cab3597-69ee-46bf-aa7e-581ca3a2570e.png)

#### 1.2配置java环境变量

此电脑 --> 右键 --> 属性 --> 高级系统设置 --> 环境变量

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277312404-accd6e97-2180-459a-9ce3-48cfe4e0bdff.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277312353-0cd9f3ae-4919-46d9-8e7f-0dc69001db71.png)

选择环境变量

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277314095-c31c62b5-4003-4243-a08f-dc01f7e83dd9.png)

在下方**[系统变量]**中进行配置

新建变量,变量名输入JAVA_HOME , 变量值是JDK的安装路径

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277314150-2a911a19-2adf-4c33-a4f3-e7d7b4fb759b.png)

新建变量,变量名输入JRE_HOME , 变量值是JRE的安装路径

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277314321-33bdf2f5-1c81-4174-b483-305d8e081b46.png)

找到path变量,双击打开,添加我们自己变量

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277314379-7dc84988-a73c-4205-9f5b-b939956c6b52.png)

点击右侧新建按钮进行输入

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277314546-09c0fae9-f8f7-451a-96fe-0bd53236a2f0.png)

#### 1.3 测试是否配置成功

win+r --> 弹窗输入cmd --> 回车

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277314722-e10afa81-a78a-4ceb-8f38-0ec50c0f694b.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763343454368-8d56bc5b-11d0-4a21-a1d9-4a35ae19dfee.png)

### 2 MySQL安装

首先卸载电脑上安装的mysql,(**如果本机电脑是mysql5版本需要卸载,如果原本安装的是mysql8.0则不用修改**),我们统一版本使用mysql8.0

查看本机mysql到底是什么版本的

win + r 输入以下指令

```
services.msc
```

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783494643280-5a62b8a9-1d5d-49b3-9592-1329335b7706.png)

找到控制面板

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277314966-431938ea-fc8c-4be3-a67e-374d82708352.png)

**将关于mysql相关软件全部卸载**

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277315057-7f6d922a-11d9-43f1-b8b1-cd5cf5b6e18c.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277315179-45f6c0c2-aafe-4f39-8da0-563b337b7821.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277315436-eae8e190-4372-478b-84ca-a0e492970e26.png)

**注意!!!!!!!!!!!!!!!!!!!**

需要把之前安装的mysql相关用户配置删除,否则会检验密码(如果有就删除,如果没有不用管)

找到C盘,显示隐藏文件

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277315818-27d06146-c645-4a8b-837f-01ed716000fb.png)

找到隐藏文件夹programData

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277315763-7becdb9a-facf-4e7f-b90b-d5a85adfe9d3.png)

删除MySQL文件夹

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277315822-768fad6e-0f53-4e12-ab51-c62138e04c30.png)

**mysql下载:**

官方网站：[https://www.mysql.com/](https://www.mysql.com/)

下载地址：[https://dev.mysql.com/downloads/mysql/](https://dev.mysql.com/downloads/mysql/)

目前安装的版本: 5.7+ , 8.0+(现在大多数公司用mysql8.0以上的居多)

**版本选择**

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277315881-7e3d0783-6315-47d6-909e-9b72be757388.png)

**下载页面**

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277315915-979a2900-2c57-4faf-9c24-d30b76efd9a8.png)

#### 2.1 安装

**安装之前确保电脑主机不能为中文**

**如果是中文的,需要改名并重启**

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783495067530-37e226d9-ea81-44d8-a03e-d724c0c919cd.png)

选择选项server only 只需要安装mysql server 8.0

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277316297-3b9fd1c0-86cf-4d11-8980-1db952da85b7.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277316501-31eb24f5-ae79-4680-8326-327b6215c483.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277316439-b4c860dd-4250-49e7-83a9-bb1be1b3882d.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277316504-7a73d386-d38e-4b0d-b2c5-b3657c1a37c1.png)

配置服务器参数

端口设置：保持默认3306

身份验证方式：选择推荐的Use Strong Password Encryption

Root账户密码（重要！）

学习环境：可设为简单密码（如root）

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277316703-a2d02040-4114-4ed2-b5d1-bda102ee3f37.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277316894-c1c9d19a-e18f-4744-a0ba-2a772fb10a41.png)

密码不要有特殊字符:如@,#等等

密码不要使用0开头

电脑主机不要使用中文

建议统一设置密码为:root或123456和生日

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277316919-588f3f03-c26d-4174-a27e-c434de382fc0.png)

保持默认服务名`MySQL80`，建议勾选`Start the MySQL Server at System Startup`（开机自启）：

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277316995-cc0dae99-0200-4f93-a025-723515be4e25.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277317026-7a6a22bb-abff-4b06-8ca5-866cea084e54.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277317343-8c05bff7-9e13-47e9-aa2f-44b7c2c90869.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277317374-d6138d95-f2c7-43e2-a1d8-44aa8904ac42.png)

#### 2.2配置环境变量

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277317397-381a947f-6846-470d-a841-1f24e5ae3262.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277317491-a2d9da3c-18e7-4ebf-a640-43a062f8f21d.png)

#### 2.3使用

win+r输入cmd

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277317626-e9b36add-5dfd-4a3b-87b8-f4f0b1700191.png)

- 登录mysql

mysql -uroot -pxxxxx

- 退出mysql

exit

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277317813-7c4fdde8-4002-424d-a402-0a89511d1c69.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277317896-a9a8a678-3cf0-44a5-ba9d-a4bf33357f90.png)

### 3 maven配置

#### 3.1 解压该文件到任意磁盘下

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783386689422-426db092-c211-431d-bb70-7be9cea6ef18.png)

#### 3.2 maven文件结构介绍

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277318738-34e35693-6b10-4ccb-8d08-d9e4790e2bc5.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277318540-382171bc-40c9-4403-a6c7-33e4722095d8.png)

记事本打开settings.xml文件

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783386595387-79021156-2456-4243-8906-411efe56d440.png)

配置中央仓库

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783386643264-6dcfff8a-7687-4601-9e04-05dda17e8a1e.png)

完整的文件如下

```xml
<?xml version="1.0" encoding="UTF-8"?>

<!--
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
-->

<!--
 | This is the configuration file for Maven. It can be specified at two levels:
 |
 |  1. User Level. This settings.xml file provides configuration for a single user,
 |                 and is normally provided in ${user.home}/.m2/settings.xml.
 |
 |                 NOTE: This location can be overridden with the CLI option:
 |
 |                 -s /path/to/user/settings.xml
 |
 |  2. Global Level. This settings.xml file provides configuration for all Maven
 |                 users on a machine (assuming they're all using the same Maven
 |                 installation). It's normally provided in
 |                 ${maven.conf}/settings.xml.
 |
 |                 NOTE: This location can be overridden with the CLI option:
 |
 |                 -gs /path/to/global/settings.xml
 |
 | The sections in this sample file are intended to give you a running start at
 | getting the most out of your Maven installation. Where appropriate, the default
 | values (values used when the setting is not specified) are provided.
 |
 |-->
<settings xmlns="http://maven.apache.org/SETTINGS/1.2.0"
          xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
          xsi:schemaLocation="http://maven.apache.org/SETTINGS/1.2.0 https://maven.apache.org/xsd/settings-1.2.0.xsd">
  <!-- localRepository
   | The path to the local repository maven will use to store artifacts.
   |
   | Default: ${user.home}/.m2/repository
  <localRepository>/path/to/local/repo</localRepository>
  -->
<localRepository>D:\Server\apache-maven-3.9.11\MavenRepositories</localRepository>
  <!-- interactiveMode
   | This will determine whether maven prompts you when it needs input. If set to false,
   | maven will use a sensible default value, perhaps based on some other setting, for
   | the parameter in question.
   |
   | Default: true
  <interactiveMode>true</interactiveMode>
  -->

  <!-- offline
   | Determines whether maven should attempt to connect to the network when executing a build.
   | This will have an effect on artifact downloads, artifact deployment, and others.
   |
   | Default: false
  <offline>false</offline>
  -->

  <!-- pluginGroups
   | This is a list of additional group identifiers that will be searched when resolving plugins by their prefix, i.e.
   | when invoking a command line like "mvn prefix:goal". Maven will automatically add the group identifiers
   | "org.apache.maven.plugins" and "org.codehaus.mojo" if these are not already contained in the list.
   |-->
  <pluginGroups>
    <!-- pluginGroup
     | Specifies a further group identifier to use for plugin lookup.
    <pluginGroup>com.your.plugins</pluginGroup>
    -->
  </pluginGroups>

  <!-- TODO Since when can proxies be selected as depicted? -->
  <!-- proxies
   | This is a list of proxies which can be used on this machine to connect to the network.
   | Unless otherwise specified (by system property or command-line switch), the first proxy
   | specification in this list marked as active will be used.
   |-->
  <proxies>
    <!-- proxy
     | Specification for one proxy, to be used in connecting to the network.
     |
    <proxy>
      <id>optional</id>
      <active>true</active>
      <protocol>http</protocol>
      <username>proxyuser</username>
      <password>proxypass</password>
      <host>proxy.host.net</host>
      <port>80</port>
      <nonProxyHosts>local.net|some.host.com</nonProxyHosts>
    </proxy>
    -->
  </proxies>

  <!-- servers
   | This is a list of authentication profiles, keyed by the server-id used within the system.
   | Authentication profiles can be used whenever maven must make a connection to a remote server.
   |-->
  <servers>
    <!-- server
     | Specifies the authentication information to use when connecting to a particular server, identified by
     | a unique name within the system (referred to by the 'id' attribute below).
     |
     | NOTE: You should either specify username/password OR privateKey/passphrase, since these pairings are
     |       used together.
     |
    <server>
      <id>deploymentRepo</id>
      <username>repouser</username>
      <password>repopwd</password>
    </server>
    -->

    <!-- Another sample, using keys to authenticate.
    <server>
      <id>siteServer</id>
      <privateKey>/path/to/private/key</privateKey>
      <passphrase>optional; leave empty if not used.</passphrase>
    </server>
    -->
  </servers>

  <!-- mirrors
   | This is a list of mirrors to be used in downloading artifacts from remote repositories.
   |
   | It works like this: a POM may declare a repository to use in resolving certain artifacts.
   | However, this repository may have problems with heavy traffic at times, so people have mirrored
   | it to several places.
   |
   | That repository definition will have a unique id, so we can create a mirror reference for that
   | repository, to be used as an alternate download site. The mirror site will be the preferred
   | server for that repository.
   |-->
 <mirrors>
	<!--  阿里镜像  -->
	<mirror>
		<id>aliyun</id>
		<mirrorOf>*</mirrorOf>
		<name>aliyun maven</name>
		<url>http://maven.aliyun.com/nexus/content/groups/public/</url>
	</mirror>
</mirrors>

  <!-- profiles
   | This is a list of profiles which can be activated in a variety of ways, and which can modify
   | the build process. Profiles provided in the settings.xml are intended to provide local machine-
   | specific paths and repository locations which allow the build to work in the local environment.
   |
   | For example, if you have an integration testing plugin - like cactus - that needs to know where
   | your Tomcat instance is installed, you can provide a variable here such that the variable is
   | dereferenced during the build process to configure the cactus plugin.
   |
   | As noted above, profiles can be activated in a variety of ways. One way - the activeProfiles
   | section of this document (settings.xml) - will be discussed later. Another way essentially
   | relies on the detection of a property, either matching a particular value for the property,
   | or merely testing its existence. Profiles can also be activated by JDK version prefix, where a
   | value of '1.4' might activate a profile when the build is executed on a JDK version of '1.4.2_07'.
   | Finally, the list of active profiles can be specified directly from the command line.
   |
   | NOTE: For profiles defined in the settings.xml, you are restricted to specifying only artifact
   |       repositories, plugin repositories, and free-form properties to be used as configuration
   |       variables for plugins in the POM.
   |
   |-->
  <profiles>
    <!-- profile
     | Specifies a set of introductions to the build process, to be activated using one or more of the
     | mechanisms described above. For inheritance purposes, and to activate profiles via <activatedProfiles/>
     | or the command line, profiles have to have an ID that is unique.
     |
     | An encouraged best practice for profile identification is to use a consistent naming convention
     | for profiles, such as 'env-dev', 'env-test', 'env-production', 'user-jdcasey', 'user-brett', etc.
     | This will make it more intuitive to understand what the set of introduced profiles is attempting
     | to accomplish, particularly when you only have a list of profile id's for debug.
     |
     | This profile example uses the JDK version to trigger activation, and provides a JDK-specific repo.
    <profile>
      <id>jdk-1.4</id>

      <activation>
        <jdk>1.4</jdk>
      </activation>

      <repositories>
        <repository>
          <id>jdk14</id>
          <name>Repository for JDK 1.4 builds</name>
          <url>http://www.myhost.com/maven/jdk14</url>
          <layout>default</layout>
          <snapshotPolicy>always</snapshotPolicy>
        </repository>
      </repositories>
    </profile>
    -->

    <!--
     | Here is another profile, activated by the property 'target-env' with a value of 'dev', which
     | provides a specific path to the Tomcat instance. To use this, your plugin configuration might
     | hypothetically look like:
     |
     | ...
     | <plugin>
     |   <groupId>org.myco.myplugins</groupId>
     |   <artifactId>myplugin</artifactId>
     |
     |   <configuration>
     |     <tomcatLocation>${tomcatPath}</tomcatLocation>
     |   </configuration>
     | </plugin>
     | ...
     |
     | NOTE: If you just wanted to inject this configuration whenever someone set 'target-env' to
     |       anything, you could just leave off the <value/> inside the activation-property.
     |
    <profile>
      <id>env-dev</id>

      <activation>
        <property>
          <name>target-env</name>
          <value>dev</value>
        </property>
      </activation>

      <properties>
        <tomcatPath>/path/to/tomcat/instance</tomcatPath>
      </properties>
    </profile>
    -->
  </profiles>

  <!-- activeProfiles
   | List of profiles that are active for all builds.
   |
  <activeProfiles>
    <activeProfile>alwaysActiveProfile</activeProfile>
    <activeProfile>anotherAlwaysActiveProfile</activeProfile>
  </activeProfiles>
  -->
</settings>
```

### 4 Navicat16安装教程

#### 4.1卸载电脑上已安装的navicat

打开控制面板

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1765105477667-da51b177-3857-40b7-b5c0-c949b1440d2d.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1765105497701-0162c165-6135-4ccc-b725-4e8ea3e4d0bb.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1765105511091-47c0ed6e-c89f-49c2-9a04-ff246074e75d.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1765105553753-590ea4e9-31b0-4127-a518-76a7e7e3efe2.png)

#### 4.2激活navicat

先打开Navicat16补丁文件夹

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1765105243228-6c9291f5-1cd9-44c3-aae9-ed129ee4f6f6.png)

运行无限试用Navicat.bat文件(自动删除原有注册表,等待执行成功)成功之后小黑窗口自动关闭

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1765105390195-b9469823-9e91-40dd-8974-18e46e745a6a.png)

#### 4.3安装navicat 16(傻瓜式安装)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1765105437538-4f5391a2-703c-454e-b019-59105492cfe9.png)

#### 4.4 navicat连接本地mysql数据库

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783501197638-79305c3b-d3c4-426a-9dfe-ac34726dd599.png)

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783501210153-d08c1bca-f8bd-4d69-a3fb-2bf37b7eeb45.png)

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783501296717-9f9a7420-6016-434c-8347-3645f0d7e51c.png)

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783501306707-37f33e16-9ef3-4b40-afaf-c73b85d25dc1.png)

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783501317786-bd454f20-559e-4293-9609-06cbc8ea34b1.png)

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783501328701-599cefec-1d5d-46e2-a15b-5afe560f39ac.png)

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783501427916-08dbd851-2cf6-4e64-82a4-779e64b9a018.png)

以上4个数据库,不要删除,也不要进行改动,这四个数据库是mysql自带的数据库跟你没关系

### 5 idea破解

以管理员身份打开powershell,执行以下命令

```
irm ckey.run|iex
```

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1778466746382-22702499-7c93-4b3b-b8bb-3e27a8331f7c.png?x-oss-process=image%2Fcrop%2Cx_0%2Cy_5%2Cw_391%2Ch_23)

回车会弹框,点击确认

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783049216040-5c3e8011-1507-4f3b-b275-046cd50c711c.png?x-oss-process=image%2Fcrop%2Cx_0%2Cy_0%2Cw_969%2Ch_266)

打开powershell之后,在连续三次回车破解即可

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783501853437-a6e9224a-e4da-4e67-a2f8-22dbc720678a.png)

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783501861724-a6dded46-bd16-44c1-b484-f306d20f96ad.png)

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783501823331-b78752d1-3456-47d6-b57d-4ae815670b4c.png)

## 二. 搭建简单快速的springboot工程

首先idea需要配置maven构建工具(全局配置)

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1779108131912-323eebad-7064-480c-87c7-93845f82abda.png)

按照步骤进行maven的配置

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783387164164-5fea952c-d457-4a9e-94df-7794aa7fb248.png)

创建springboot工程

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1779108397061-43be7b67-63de-4e1b-80a4-a5c77b8694a8.png)

没有springboot 老版本idea为**Spring Initializr**

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1779109007672-7f0d09ae-2bdc-427a-b9e6-f9ef89fb3f7e.png)

Spring Web组件是用于构建Java驱动的动态Web应用程序的框架模块，它包括支持传统[^1]Servlet架构的[^2]Spring Web MVC和响应式编程模型的Spring WebFlux，旨在提供灵活、高效的Web开发解决方案。(可以理解为前端发送请求,就需要用到这个组件)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277319236-2fc8d045-5def-4840-a275-6ccb1eb2390b.png)

如果下载下来的springboot工程文件结构如下图所示的话,那么大概率是网络问题,下载失败

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783561740691-d251ada5-7144-455a-b87e-83c140df1610.png)

### 1 创建好之后,包结构显示不太分明

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1779109465285-6821c5ca-b7ad-412c-b1a1-70c541d031cf.png)

取消压缩包结构

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1779109496934-92bd42e1-7f1f-4390-bc84-5b0717ba5bad.png)

### 2 准备工作无误之后测试运行

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277319351-900555a6-15de-42d5-a6f3-4eb960ae83e5.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277319728-c26757bc-07ae-46c3-9c04-a47bbe46c27f.png)springboot默认端口号为8080

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277320086-1f1b57e2-6a3b-40ea-b90d-aa79a96d61aa.png)

访问地址为`localhost:8080`他等价于`127.0.0.1:8080`

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1765205032076-96c536b0-f3c5-4c94-85e2-3f3e01d139c3.png)

### 3 项目文件结构解析

#### 3.1pom.xml文件

- 项目的元数据：包名，项目名，版本号。

```xml
<groupId>com.qf</groupId>
<artifactId>test_springboot01</artifactId>
<version>0.0.1-SNAPSHOT</version>
<name>TestSpringboot01</name>
```

- 指定了properties信息：指定了java的版本为1.8

```xml
<properties>
  <java.version>1.8</java.version>
</properties>
```

- 导入依赖：按需导入(web,mysql等等)
- 插件：spring-boot-maven-plugin (如果有报错,也可以不要)

```xml
<build>
  <plugins>
    <plugin>
      <groupId>org.springframework.boot</groupId>
      <artifactId>spring-boot-maven-plugin</artifactId>
      <version>2.7.2</version>
    </plugin>
  </plugins>
</build>
```

#### 3.2 .gitignore文件

默认帮我们忽略了一些文件和目录，避免提交到Git仓库中

#### 3.3 目录结构

```tree
-src
     -main
       -java
         -包名 
          -启动类.java           # 需要将controller类，放在启动类的子包中或者同级包下,否则需要使用@ComponentScan 注解,并指定扫描的包即可
       -resources  # resources下放除了java代码之外其他资源文件
         -static                 # 存放静态资源的,js,css,html
         -templates              # 存储模板页面的,Thymeleaf,jsp,freemarker
         application.properties  # SpringBoot提供的配置文件,后缀支持2种：1.properties 2.yml(推荐),用来修改默认配置
     -test                       # 只是为了测试用的
```

## 三. spring

spring的核心功能

- IOC,DI
- AOP(面向切面编程,在不影响现在代码逻辑的情况下添加功能)

### 1  介绍

IOC是Spring框架的核心功能之一,IOC(inversion of control)控制反转

控制: 控制创建对象的能力

反转: 原来创建对象是自己做,反转就是将创建对象的能力交给Spring

---

**IOC(控制反转): 将创建对象的能力反转给Spring,由Spring创建对象**

**DI(dependency injection) 依赖注入,即 属性赋值**

---

`创建对象`的注解

- **@Controller 在控制层代码上使用**
- **@Service 在业务层层代码上使用**
- **@Repository 在数据层代码上使用**
- **@Component 在其他代码上使用**

属性赋值(依赖注入的注解)

- **@Autowired(默认按照类型匹配)**
- **@Resource(默认按照名称)**

### 2  演示1

需求: 项目中控制层servlet需要使用到业务层对象来处理业务,例如AdminController中需要创建AdminService对象使用,使用IOC+DI完成

AdminService

```java
package com.qf.service;

//service包下面.全部放的都是接口interface
public interface AdminService {
    //创建一个无参,无返回值的方法
    //接口中只能放抽象方法,不能有方法体
    void login();
}
```

AdminServiceImpl

```java
package com.qf.service.impl;

import com.qf.service.AdminService;
import org.springframework.stereotype.Service;

//@Service表明这个类是服务层类
@Service
public class AdminServiceImpl implements AdminService {

    @Override
    public void login() {
        //打印一句话
        System.out.println("业务层执行");
    }
}
```

AdminController

```java
package com.qf.controller;

import com.qf.service.AdminService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

//@Controller表明此类时一个控制层类
@Controller
public class AdminController {

    //注入AdminService接口
    @Autowired
    private AdminService adminService;

    //@GetMapping 能接收前端发送的get请求,规定访问到我们后端的路径,
    //此时"/login"就规定为我们映射的url
    //localhost:8080/login
    @GetMapping("/login")
    public String login(){
        //调用AdminService里面的login()方法
        //在调用login抽象方法时,会在控制台打印"业务层执行"这句话
        adminService.login();
        //返回ok.html这个页面
        return "ok.html";
    }

}
```

### 3  演示2

**@Component注解创建对象**

假如有个类User,现在需要该类对象,就可以在该类上加上@Component注解,并在其他地方使用@Autowired注入

我们先在pom.xml导入起步依赖

```
<dependency>
  <groupId>org.projectlombok</groupId>
  <artifactId>lombok</artifactId>
</dependency>
```

粘贴位置注意别粘错了

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1766479346974-fa59e197-c43c-416c-9f72-d7bec502e50a.png)

User实体类:

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277320452-0c67759e-276d-45b0-a38c-202c11433827.png)

controller注入实体类进行使用

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277331124-95fff74b-13af-4f71-bd74-bafa7db66225.png)

## 四. Springmvc

其实是spring框架中关于web,webmvc开发的一个技术

spring核心ioc,aop,web开发

### 1  MVC

MVC架构: 根据不同的事情由不同的类去处理,内部单一职责

- **M**odel: 模型类,例如封装数据的实体类,业务模型(Service),数据层(Dao)
- **V**iew: 视图,展示数据的.HTML,JSP
- **C**ontroller: 控制器,控制整个流程走向. 决定是否能接收请求,调用哪个业务,跳转哪个页面,Servlet

---

MVC框架特点

- 封装了Servlet
- 接收请求方便(一个类中,不同的方法就可以接收不同的请求)
- 接收请求数据方便(自动封装)
- 响应数据方便(自动响应json)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754277332382-a088991a-6ee5-4714-8fc1-147c859c7b4a.png)

### 2  请求&响应【重点】

其实我们之前的那些案例中就已经使用了请求和响应

@GetMapping("/login")、@PostMapping("/ioc")等就是绑定映射路径和处理请求的方法的，返回值就是响应（跳转页面）

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1749387362263-0cab7140-a805-4a6b-a18a-a3632d99421e.png)

练习： 类中再定义其他方法和请求路径

@RequestMapping注解使用

### 3  参数绑定 【重点】

所谓参数绑定,就是前端发请求中的数据,可以直接在Controller的方法参数中接收.即前端请求数据和后端方法参数绑定.

#### 3.1 简单类型参数绑定[重点]

简单类型指,常用的几种类型: 基本类型+String+Date

前端页面

```
<head>
  <meta charset="UTF-8">
</head>
<h2>基本类型数据绑定</h2>
<a href="/base?id=1&username=张三&score=10.0&birthday=2020-01-01">请求携带数据-基本类型</a>
<hr>
<form action="/base" method="get">
  id<input type="text" name="id"><br>
  username<input type="text" name="username"><br>
  score<input type="text" name="score"><br>
  birthday<input type="date" name="birthday"><br>
  <input type="submit" value="基本类型">
</form>
```

后端接收

```
 /**
     * 使用基本数据类型接收参数
     * @param id
     * @param username
     * @param score
     * @param birthday
     * @return
     */

    @GetMapping("/base")
    //@DateTimeFormat(pattern = "yyyy-MM-dd")定义我们日期类型数据格式为年月日(我们只接收年月日格式的日期数据)
    public String base(int id, String username, double score,@DateTimeFormat(pattern = "yyyy-MM-dd") Date birthday){

        //打印数据
        System.out.println("id = " + id);
        System.out.println("username = " + username);
        System.out.println("score = " + score);
        System.out.println("birthday = " + birthday);
        //返回成功页面
        return "ok.html";
    }
```

#### 3.2 对象[重点]

场景: 注册/添加/更新

实体类

```
package com.qf.entity;

import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

@Data
public class Users {

    private int id;
    private String username;
    private String password;
    private double score;
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private Date birthday;
    // setget
}
```

前端

```
<h2>对象数据绑定</h2>
<form action="/obj" method="get">
  id<input type="text" name="id"><br>
  username<input type="text" name="username"><br>
  password<input type="text" name="password"><br>
  score<input type="text" name="score"><br>
  birthday<input type="date" name="birthday"><br>
  <input type="submit" value="对象类型">
</form>
```

后端

```
/**
     * 使用实体类来接受参数
     * @param users
     * @return
     */

    @GetMapping("/obj")
    public String obj(Users users){

        //打印Users类中的数据
        System.out.println("id = " + users.getId());
        System.out.println("username = " + users.getUsername());
        System.out.println("password = " + users.getPassword());
        System.out.println("score = " + users.getScore());
        System.out.println("birthday = " + users.getBirthday());

        //返回成功页面
        return "ok.html";
    }
```

#### 3.3 数组

场景: 批量删除需要同时接收多个id, (前端是复选框的)

delete from tb_user where id in (1,2,3,4)

前端

```
<head>
  <meta charset="UTF-8">
</head>
<h2>数组绑定</h2>
<form action="/array" method="get">
  <input type="checkbox" name="ids" value="1">1
  <input type="checkbox" name="ids" value="2">2
  <input type="checkbox" name="ids" value="3">3
  <input type="checkbox" name="ids" value="4">4
  <input type="submit" value="数组类型">
</form>
```

后端

```
/**
     * 使用数组接收参数
     * @param ids
     * @return
     */
    @GetMapping("/array")
    public String array(int[] ids){
        //打印数据
        //直接打印ids数组,打印出的结果是数组对应的地址值
        //要想看到数据,就需要将数组转换为字符串
        //Arrays是数组方法
        //toString是将数组转换为字符串
        System.out.println("ids = + " + Arrays.toString(ids));
        return "ok.html";
    }
```

#### 3.4 List集合

List集合使用场景与数组是一样的

前端

```
<head>
  <meta charset="UTF-8">
</head>
<h2>List绑定</h2>
<form action="/list" method="get">
  <input type="checkbox" name="skill" value="Java">Java
  <input type="checkbox" name="skill" value="HTML">HTML
  <input type="checkbox" name="skill" value="Linux">Linux
  <input type="submit" value="List类型">
</form>
```

SpringMVC默认是不支持直接封装List的,解决方案:

- 加注解@RequestParam

```
@GetMapping("/list")
public String list(@RequestParam List<String> skill){
    System.out.println("skill = " + skill);
    return "ok.html";
}
```

#### 3.5 Map集合

Map是键值对,键和值一一映射.

跟Java对象很类似,属性和属性值一一对应.

所以什么时候需要/可以使用Map类型来接收参数呢?

- 凡是可以用对象接收的都可以使用Map

---

SpringMVC默认不支持直接将参数封装进Map,需要使用@RequestParam

前端

```
<head>
  <meta charset="UTF-8">
</head>
<h2>Map绑定</h2>
<form action="/map" method="get">
  id<input type="text" name="id"><br>
  username<input type="text" name="username"><br>
  score<input type="text" name="score"><br>
  birthday<input type="date" name="birthday"><br>
  <input type="submit" value="Map类型">
</form>
name就是map的key
输入框的值就是map的value
```

后台

```
@GetMapping("/map")
public String map(@RequestParam Map<String,Object> map){
    System.out.println("map = " + map);
    return "ok.html";
}
```

#### 3.6 路径参数@PathVariable

参考这个路径

[https://blog.csdn.net/weixin_39641494/article/details/131625212](https://blog.csdn.net/weixin_39641494/article/details/131625212)

这个路径中weixin_39641494是用户编号,131625212是文章id

@GetMapping("/{userid}/article/details/{aid}")

前端

```
<head>
  <meta charset="UTF-8">
</head>
<h2>路径参数绑定</h2>
<a href="/user/101">路径参数101</a>
```

后端

```
@ResponseBody
@GetMapping("/user/{id}")
public String path(@PathVariable int id){
    System.out.println("id = " + id); // id=101
    return "ok.html";
}
```

ps: 能接收到请求中的id为101,但是响应回报错.因为使用@PathVariable要求返回的是json数据而不是页面,这个暂时先不管

### 4  页面跳转[熟悉]

我们可以手动显示的在Controller的方法的返回值中写forward:路径即可完成跳转

例如: forward:/ok.html forward:/test

```
注意: 跳转后的路径要写完整
/**
* 演示请求转发至其他页面
* @return
*/
@GetMapping("/forward")
public String forward(){
    System.out.println("执行请求转发" );
    return "forward:/ok.html";
}
```

**重定向**

在Controller的方法的返回值中写redirect:路径即可完成跳转

例如: redirect:/ok.html redirect:/test

```
注意: 跳转后的路径要写完整
/**
* 演示重定向至其他页面
* @return
*/
@GetMapping("/redirect")
public String redirect(){
    System.out.println("执行重定向" );
    return "redirect:/ok.html";
}
```

其他的请求转发和重定向的特点和之前学习的servlet是一样的,复习.

### 5  json处理【重点】

后续工作项目,都是前后端分离开发,前后端使用JSON数据交互

- 前端发送json,使用axios技术(类似于ajax),vue中就使用axios发送请求
- 后端接收json,然后响应给前端json

前端发送json等vue时候再演示

**现在演示响应JSON数据,**非常简单,方法加上**@ResponseBody**即可,就会将任何解析为json返回

格式一般如下

```
{
  code:20000,
  msg:"成功|失败",
  data:{}
}
```

- code是响应的状态码,自己公司定义

- 2000 成功
- 4000 失败
- 5000 连接超时
- 3000 未登录

- msg是响应的提示信息
- data是后端返回给前端的数据

前后端交互,定义的类,用于统一返回封装数据返回JSON

补充: 如果该类中所有方法都返回json,那就需要在每个方法上都要加@ResponseBody注解,有点麻烦,此时可以直接将@Controller换成@RestController, 以后方法默认返回json,就不需要加@ResponseBody

## 五. MyBatis Plus

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754405307945-e7b44874-5809-44da-a8d9-c76e90fae592.png)

官网：

[https://baomidou.com/](https://baomidou.com/)

MyBatis-Plus（简称 MP）是一个 MyBatis的增强工具，在 MyBatis 的基础上只做增强不做改变，为简化开发、提高效率而生。

接下来对数据库中的数据进行增删改查

### 1 新建springboot项目

### 2 导入Mybatis-plus起步依赖

完整pom.xml文件

```
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 https://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>
    <groupId>com.qf</groupId>
    <artifactId>zzqgy-springboot</artifactId>
    <version>0.0.1-SNAPSHOT</version>
    <name>zzqgy-springboot</name>
    <description>zzqgy-springboot</description>
    <properties>
        <java.version>17</java.version>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
        <project.reporting.outputEncoding>UTF-8</project.reporting.outputEncoding>
        <spring-boot.version>2.6.13</spring-boot.version>
    </properties>
    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>

        <!--  lombok插件 -->
        <dependency>
            <groupId>org.projectlombok</groupId>
            <artifactId>lombok</artifactId>
        </dependency>

        <dependency>
            <groupId>com.baomidou</groupId>
            <artifactId>mybatis-plus-boot-starter</artifactId>
            <version>3.5.2</version>
        </dependency>
        <!--        mysql-->
        <dependency>
            <groupId>mysql</groupId>
            <artifactId>mysql-connector-java</artifactId>
            <version>8.0.31</version>
        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-test</artifactId>
            <scope>test</scope>
        </dependency>
    </dependencies>
    <dependencyManagement>
        <dependencies>
            <dependency>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-dependencies</artifactId>
                <version>${spring-boot.version}</version>
                <type>pom</type>
                <scope>import</scope>
            </dependency>
        </dependencies>
    </dependencyManagement>

    <build>
        <plugins>
            <plugin>
                <groupId>org.apache.maven.plugins</groupId>
                <artifactId>maven-compiler-plugin</artifactId>
                <version>3.8.1</version>
                <configuration>
                    <source>1.8</source>
                    <target>1.8</target>
                    <encoding>UTF-8</encoding>
                </configuration>
            </plugin>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
                <version>${spring-boot.version}</version>
                <configuration>
                    <mainClass>com.qf.ZzqgySpringbootApplication</mainClass>
                    <skip>true</skip>
                </configuration>
                <executions>
                    <execution>
                        <id>repackage</id>
                        <goals>
                            <goal>repackage</goal>
                        </goals>
                    </execution>
                </executions>
            </plugin>
        </plugins>
    </build>

</project>
```

### 3  yml配置

```
server:
  port: 8080
spring:
  datasource:
    driver-class-name: com.mysql.cj.jdbc.Driver
    url: jdbc:mysql://localhost:3306/test?serverTimezone=Asia/Shanghai&useSSL=false&allowPublicKeyRetrieval=true
    username: root
    password: 19971221
mybatis-plus:
  configuration:
    log-impl: org.apache.ibatis.logging.stdout.StdOutImpl
    #
  mapper-locations: classpath:mapper/*.xml
```

引导类

扫描数据库访问层包(**要从com包逐层顺利找到dao包**)

@MapperScan("com.qf.dao")

```
package com.qf;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

//@SpringBootApplication这个注解就是声明此类是一个启动类
@SpringBootApplication

// 使用Mybatis-plus提供的注解扫描dao层
@MapperScan("com.qf.dao")
public class ZzqgySpringbootApplication {

    public static void main(String[] args) {
        SpringApplication.run(ZzqgySpringbootApplication.class, args);
    }

}
```

### 4 建库建表

创建test数据库并新建employee员工表

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783647049534-9ca2f64d-70e0-4ae4-81be-7d06a3a8702f.png)

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783647066245-7e2364c2-7072-4222-9422-d75d0671b441.png)

**注:id设置为自增**

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1749475256887-a3c61b59-ae42-43a0-a487-ede4fef8a1f9.png)

#### 4.1实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

//生成get,set方法的
@Data

// 是MP提供的注解,作用是找到数据库中的哪张表
@TableName("employee")
public class Employee {

    /*@TableId  修饰属性，指定主键对应的属性
           value 主键字段名，可以不写
           type 主键类型，IdType.AUTO 自增
                       IdType.ASSIGN_ID 雪花算法生成的值
                       IdType.ASSIGN_UUID  uuid*/
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;
    private String eName;
    private Integer eAge;

}
```

注意：当表名、字段名和实体类的类名、属性名不一致时，必须使用这些注解

|   |   |
|---|---|
|**@TableName**|**修饰实体类，指定的表实体类对象的表名**|
|@TableId|修饰属性，指定主键对应的属性value 主键字段名，可以不写type 主键类型，IdType.AUTO 自增IdType.ASSIGN_ID 雪花算法生成的值IdType.ASSIGN_UUID uuid|
|@TableField|修饰属性，针对非主键的属性|

#### 4.2Dao层接口

自定义接口需要实现BaseMapper接口

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.EmployeeEntity;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface EmployeeDao extends BaseMapper<Employee> {
}
```

测试

```
package com.qf;

import com.qf.dao.EmployeeDao;
import com.qf.entity.Employee;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import javax.annotation.Resource;

@SpringBootTest
class ZzqgySpringbootApplicationTests {


    //注入EmployeeDao
    @Autowired
    private EmployeeDao employeeDao;

    @Test
    void contextLoads() {

        //创建Employee对象进行赋值
        Employee employee = new Employee();
        //设置名字和年龄属性
        employee.setEName("狗蛋1");
        employee.setEAge(30);

        //调用对应的数据库访问层EmployeeDao进行插入数据
        int insert = employeeDao.insert(employee);
        System.out.println("影响了" + insert + "行数据");
        //插入成功之后可以获取插入后的数据对的id
        System.out.println("此次插入成功后数据库对应的id =" + employee.getId());


        //这是下一个知识点,通过id查询一条数据
        Employee employee1 = employeeDao.selectById(2);
        System.out.println(employee1);

    }

}
```

#### 4.3代码

EmployeeService接口

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.entity.EmployeeEntity;

public interface EmployeeService extends IService<Employee> {
}
```

EmployeeServiceImpl实现类

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.dao.EmployeeDao;
import com.qf.entity.EmployeeEntity;
import com.qf.service.EmployeeService;
import org.springframework.stereotype.Service;


//业务层的实现类，实现对应的接口（EmployeeService）还需要继承官方的SreviceImpl对应的Dao接口， 实体类>
@Service
public class EmployeeServiceImpl extends ServiceImpl<EmployeeDao, Employee> implements EmployeeService {
}
```

测试

```
package com.qf;

import com.qf.dao.EmployeeDao;
import com.qf.entity.Employee;
import com.qf.service.EmployeeService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import javax.annotation.Resource;

@SpringBootTest
class ZzqgySpringbootApplicationTests {


    //注入EmployeeDao
    @Autowired
    private EmployeeDao employeeDao;

    //注入EmployeeService
    @Autowired
    private EmployeeService employeeService;


    @Test
    void contextLoads() {

        //创建Employee对象进行赋值
        Employee employee = new Employee();
        //设置名字和年龄属性
        employee.setEName("狗蛋1");
        employee.setEAge(30);

        //调用对应的数据库访问层EmployeeDao进行插入数据
        int insert = employeeDao.insert(employee);
        System.out.println("影响了" + insert + "行数据");
        //插入成功之后可以获取插入后的数据对的id
        System.out.println("此次插入成功后数据库对应的id =" + employee.getId());


        //这是下一个知识点,通过id查询一条数据
        // select * from employee where id = 2
        Employee employee1 = employeeDao.selectById(2);
        System.out.println(employee1);

    }

    @Test
    void testService(){
        //对应的实体类属性赋值
        Employee employee = new Employee();
        employee.setEName("张三");
        employee.setEAge(25);
        //调用服务层EmployeeService进行插入数据
        boolean save = employeeService.save(employee);
        //判断数据是否保存成功
        if (save){
            System.out.println("保存成功");
        }else {
            System.out.println("保存失败");
        }
    }
}
```

#### 4.4条件构造器Wrapper

**主要方法**

|   |   |   |
|---|---|---|
|**eq(R column, Object val)**|**=**|**eq("name", "老王") ---> name = '老王'**|
|ne(R column, Object val);|<>(不等于)|ne("name", "老王") ---> name <> '老王'|
|gt(R column, Object val);|>|gt("name", "老王") ---> name > '老王'|
|ge(R column, Object val);|>=|ge("name", "老王") ---> name >= '老王'|
|lt(R column, Object val);|<|lt("name", "老王") ---> name < '老王'|
|le(R column, Object val);|<=|le("name", "老王") ---> name <= '老王'|
|between(R column, Object val1, Object val2)|between a and b|between("age", 18, 30) ---> age between 18 and 30|
|notBetween(R column, Object val1, Object val2);|not between a and b|notBetween("age", 18, 30) ---> age not between 18 and 30|
|in(R column, Object... values);|IN (v0, v1, ...)|in("age",{1,2,3}) ---> age in (1,2,3)|
|notIn(R column, Object... values);|NOT IN (v0, v1, ...)|notIn("age",{1,2,3}) ---> age not in (1,2,3)|
|inSql(R column, Object... values);|IN (sql 语句)|inSql("id", "select id from table where id < 3") ---> id in (select id from table where id < 3)|
|notInSql(R column, Object... values);|NOT IN (sql 语句)||
|like(R column, Object val);|LIKE '%值%'|like("name", "王") ---> name like '%王%'|
|notLike(R column, Object val)|NOT LIKE '%值%'|notLike("name", "王") ---> name not like '%王%'|
|likeLeft(R column, Object val)|LIKE '%值'|likeLeft("name", "王") ---> name like '%王'|
|likeRight(R column, Object val)|LIKE '值%'|likeRight("name", "王") ---> name like '王%'|
|isNull(R column)|IS NULL|isNull("name") ---> name is null|
|isNotNull(R column);|IS NOT NULL|isNotNull("name") ---> name is not null|
|groupBy(R... columns)|GROUP BY|groupBy("id", "name") ---> group by id,name|
|having(String sqlHaving, Object... params)|HAVING ( sql语句 )|having("sum(age) > {0}", 11) ---> having sum(age) > 11|
|orderByAsc(R... columns)|ORDER BY 字段, ... ASC|orderByAsc("id", "name") ---> order by id ASC,name ASC|
|orderByDesc(R... columns);|ORDER BY 字段, ... DESC|orderByDesc("id", "name") ---> order by id DESC,name DESC|
|or();|a or b|eq("id",1).or().eq("name","老王") ---> id = 1 or name = '老王'|
|or(Consumer<Param> consumer)|or嵌套|or(i -> i.eq("name", "李白").ne("status", "活着")) ---> or (name = '李白' and status <> '活着')|
|and(Consumer<Param> consumer)|and嵌套|and(i -> i.eq("name", "李白").ne("status", "活着")) ---> and (name = '李白' and status <> '活着')|
|nested(Consumer<Param> consumer);|普通嵌套|nested(i -> i.eq("name", "李白").ne("status", "活着")) ---> (name = '李白' and status <> '活着')|
|apply(String applySql, Object... params);|拼接sql|apply("date_format(dateColumn,'%Y-%m-%d') = {0}", "2008-08-08") ---> date_format(dateColumn,'%Y-%m-%d') = '2008-08-08'")|
|last(String lastSql)|无视优化规则直接拼接到 sql 的最后||
|exists(String existsSql)|拼接 exists 语句|exists("select id from table where age = 1") ---> exists (select id from table where age = 1)|
|QueryWrapper|||
|select(String... sqlSelect)|用于指定查询需要返回的字段|select("id", "name", "age") ---> select id, name, age|
|select(Predicate<TableFieldInfo> predicate);|通过Lambda 表达式，过滤需要的字段||
|lambda();|返回一个 LambdaQueryWrapper对象||
|UpdateWrapper|||
|set(String column, Object val);|set 字段值|set("name", null) ---> set name = null|
|setSql(String sql);||setSql("name = '老李头'") ---> set name = '老李头'|
|lambda();|返回一个 LambdaUpdateWrapper对象||

```
package com.qf;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.qf.dao.EmployeeDao;
import com.qf.entity.Department;
import com.qf.entity.Employee;
import com.qf.service.DepartmentService;
import com.qf.service.EmployeeService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import javax.annotation.Resource;
import java.util.List;

@SpringBootTest
class ZzqgySpringbootApplicationTests {


    //注入EmployeeDao
    @Autowired
    private EmployeeDao employeeDao;

    //注入EmployeeService
    @Autowired
    private EmployeeService employeeService;

    @Test
    void contextLoads() {

        //创建Employee对象进行赋值
        Employee employee = new Employee();
        //设置名字和年龄属性
        employee.setEName("狗蛋1");
        employee.setEAge(30);

        //调用对应的数据库访问层EmployeeDao进行插入数据
        int insert = employeeDao.insert(employee);
        System.out.println("影响了" + insert + "行数据");
        //插入成功之后可以获取插入后的数据对的id
        System.out.println("此次插入成功后数据库对应的id =" + employee.getId());


        //这是下一个知识点,通过id查询一条数据
        // select * from employee where id = 2
        Employee employee1 = employeeDao.selectById(2);
        System.out.println(employee1);

    }

    @Test
    void testService(){
        //对应的实体类属性赋值
        Employee employee = new Employee();
        employee.setEName("张三");
        employee.setEAge(25);
        //调用服务层EmployeeService进行插入数据
        boolean save = employeeService.save(employee);
        //判断数据是否保存成功
        if (save){
            System.out.println("保存成功");
        }else {
            System.out.println("保存失败");
        }
    }

    @Test
    void queryWrapper(){
        //需求1 : 查询数据库表中全部数据(列表数据)
        // select * from employee

//        // 调用EmployeeDao查询数据
//        // selectList参数列表可以为null,默认查询全部数据
//        List<Employee> employees = employeeDao.selectList(null);
//        // 打印列表数据
//        System.out.println("列表数据 :" + employees);
//

        // 需求2: 查询id < 3 的数据
        // select * from employee where id < 3

        // 现在有了过滤条件,这时候就需要使用到查询条件构造器
//        QueryWrapper<Employee> wrapper = new QueryWrapper<>();
//        // 构建小于条件
//        // 参数列表中,第一个参数必须是数据库表中的字段名,第二个参数是对应的值
//        wrapper.lt("id",3);
//
//        //调用EmployeeDao查询数据
//        List<Employee> list = employeeDao.selectList(wrapper);
//        // 打印查询到的数据
//        System.out.println("列表数据 :" + list);


        // 需求3 模糊查询
        // select * from employee where e_name like %狗%
        // 创建查询条件构造器
//        QueryWrapper<Employee> queryWrapper = new QueryWrapper<>();
//        // 构建模糊查询条件
//        queryWrapper.like("e_name","狗");
//        // 调用EmployeeDao查询数据
//        List<Employee> list = employeeDao.selectList(queryWrapper);
//        // 打印查询到的数据
//        System.out.println("列表数据 :" + list);


//        // 需求4 : 等值查询
//        // select * from employee where e_name = "狗蛋"
//        QueryWrapper<Employee> queryWrapper1 = new QueryWrapper<>();
//        // 构建等值查询条件
//        queryWrapper1.eq("e_name","狗蛋");
//        // 调用EmployeeDao查询数据
//        List<Employee> list = employeeDao.selectList(queryWrapper1);
//        // 打印查询到的数据
//        System.out.println("列表数据 :" + list);

        // 需求5:指定查询字段 只查询e_name 和 id 查询id < 4 and e_name like %狗%
        // select id,e_name from employee where id < 4 and e_name like %狗%
//        QueryWrapper<Employee> queryWrapper2 = new QueryWrapper<>();
//        // 构造查询条件
//        // select方法指定字段查询
//        queryWrapper2.select("id","e_name");
//        // 构建id < 4的条件
//        queryWrapper2.lt("id",4);
//        // 构建模糊查询条件
//        queryWrapper2.like("e_name","狗");
//        // 调用dao层查询列表数据
//        List<Employee> employees = employeeDao.selectList(queryWrapper2);
//        // 打印列表数据
//        System.out.println("列表数据 :" + employees);


        // 需求6:
        // delete employee where id between 1 and 3  (他会删除id为1,2,3这三条数据)
        employeeDao.delete(new QueryWrapper<Employee>()
                .between("id",1,3));


    }
}
```

### 5  多表查询

一个员工表

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1761784925585-231fc14f-6f95-426f-8c20-e655506f6955.png)

一个部门表

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1761784863056-ca0e7512-5357-4f11-913c-c993e99b4ab4.png)

需求: 通过部门查员工

1.实体类

部门类

```
package com.qf.entity;

import lombok.Data;

import java.util.List;

@Data
public class Department {

    private Integer id;
    private String dName;
    // 一个部门下有多个员工
    private List<Employee> employeeList;
}
```

员工类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

//生成get,set方法的
@Data

// 是MP提供的注解,作用是找到数据库中的哪张表
@TableName("employee")
public class Employee {

    /*@TableId  修饰属性，指定主键对应的属性
           value 主键字段名，可以不写
           type 主键类型，IdType.AUTO 自增
                       IdType.ASSIGN_ID 雪花算法生成的值
                       IdType.ASSIGN_UUID  uuid*/
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;
    private String eName;
    private Integer eAge;

}
```

1. service

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.entity.Department;

public interface DepartmentService extends IService<Department> {

    Department getDepartment(int id);

}
```

service实现层

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.dao.DepartmentDao;
import com.qf.entity.Department;
import com.qf.service.DepartmentService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service
public class DepartmentServiceImpl extends ServiceImpl<DepartmentDao, Department> implements DepartmentService {

    @Resource
    private DepartmentDao departmentDao;


    @Override
    public Department getDepartment(int id) {
        // 根据传参过来的id进行查询
        // 调用对应的dao层查询数据库
        return  departmentDao.selectByDid(id);
    }

}
```

DepartmentDao这个接口

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.Department;

public interface DepartmentDao extends BaseMapper<Department> {
    Department selectByDid(int id);
}
```

写sql语句在resources文件夹下新建mapper文件夹并创建DepartmentDao.xml文件

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1749475256981-7962328e-e331-453f-8855-c16e7341a9be.png)

```
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd" >

<mapper namespace="com.qf.dao.DepartmentDao" >

  <resultMap id="DepartmentMap" type="com.qf.entity.Department">
    <!--        property是DepartmentEntity的属性名，column是数据库表的字段名 -->
    <id property="id" column="id" />
    <result property="dName" column="d_name" />
    <!--        将employeeList作为一个集合，存到DepartmentEntity的employeeList属性中，ofType指定集合中元素的类型,javaType指定集合的类型-->
    <collection property="employeeList" ofType="com.qf.entity.EmployeeEntity" javaType="java.util.List">
      <id property="id" column="id" />
      <result property="eName" column="e_name" />
      <result property="eAge" column="e_age" />
    </collection>
  </resultMap>

  <select id="selectByDid"     resultMap="DepartmentMap">
    SELECT * FROM department d left join employee e on d.id = e.d_id WHERE d.id = #{id}
  </select>
</mapper>
```

在测试类中新建方法测试

```
package com.qf;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.qf.dao.EmployeeDao;
import com.qf.entity.Department;
import com.qf.entity.Employee;
import com.qf.service.DepartmentService;
import com.qf.service.EmployeeService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import javax.annotation.Resource;
import java.util.List;

@SpringBootTest
class ZzqgySpringbootApplicationTests {


    //注入EmployeeDao
    @Autowired
    private EmployeeDao employeeDao;

    //注入EmployeeService
    @Autowired
    private EmployeeService employeeService;


    //注入DepartmentService
    @Resource
    private DepartmentService departmentService;


    @Test
    void contextLoads() {

        //创建Employee对象进行赋值
        Employee employee = new Employee();
        //设置名字和年龄属性
        employee.setEName("狗蛋1");
        employee.setEAge(30);

        //调用对应的数据库访问层EmployeeDao进行插入数据
        int insert = employeeDao.insert(employee);
        System.out.println("影响了" + insert + "行数据");
        //插入成功之后可以获取插入后的数据对的id
        System.out.println("此次插入成功后数据库对应的id =" + employee.getId());


        //这是下一个知识点,通过id查询一条数据
        // select * from employee where id = 2
        Employee employee1 = employeeDao.selectById(2);
        System.out.println(employee1);

    }

    @Test
    void testService(){
        //对应的实体类属性赋值
        Employee employee = new Employee();
        employee.setEName("张三");
        employee.setEAge(25);
        //调用服务层EmployeeService进行插入数据
        boolean save = employeeService.save(employee);
        //判断数据是否保存成功
        if (save){
            System.out.println("保存成功");
        }else {
            System.out.println("保存失败");
        }
    }

    @Test
    void queryWrapper(){
        //需求1 : 查询数据库表中全部数据(列表数据)
        // select * from employee

//        // 调用EmployeeDao查询数据
//        // selectList参数列表可以为null,默认查询全部数据
//        List<Employee> employees = employeeDao.selectList(null);
//        // 打印列表数据
//        System.out.println("列表数据 :" + employees);
//

        // 需求2: 查询id < 3 的数据
        // select * from employee where id < 3

        // 现在有了过滤条件,这时候就需要使用到查询条件构造器
//        QueryWrapper<Employee> wrapper = new QueryWrapper<>();
//        // 构建小于条件
//        // 参数列表中,第一个参数必须是数据库表中的字段名,第二个参数是对应的值
//        wrapper.lt("id",3);
//
//        //调用EmployeeDao查询数据
//        List<Employee> list = employeeDao.selectList(wrapper);
//        // 打印查询到的数据
//        System.out.println("列表数据 :" + list);


        // 需求3 模糊查询
        // select * from employee where e_name like %狗%
        // 创建查询条件构造器
//        QueryWrapper<Employee> queryWrapper = new QueryWrapper<>();
//        // 构建模糊查询条件
//        queryWrapper.like("e_name","狗");
//        // 调用EmployeeDao查询数据
//        List<Employee> list = employeeDao.selectList(queryWrapper);
//        // 打印查询到的数据
//        System.out.println("列表数据 :" + list);


//        // 需求4 : 等值查询
//        // select * from employee where e_name = "狗蛋"
//        QueryWrapper<Employee> queryWrapper1 = new QueryWrapper<>();
//        // 构建等值查询条件
//        queryWrapper1.eq("e_name","狗蛋");
//        // 调用EmployeeDao查询数据
//        List<Employee> list = employeeDao.selectList(queryWrapper1);
//        // 打印查询到的数据
//        System.out.println("列表数据 :" + list);

        // 需求5:指定查询字段 只查询e_name 和 id 查询id < 4 and e_name like %狗%
        // select id,e_name from employee where id < 4 and e_name like %狗%
//        QueryWrapper<Employee> queryWrapper2 = new QueryWrapper<>();
//        // 构造查询条件
//        // select方法指定字段查询
//        queryWrapper2.select("id","e_name");
//        // 构建id < 4的条件
//        queryWrapper2.lt("id",4);
//        // 构建模糊查询条件
//        queryWrapper2.like("e_name","狗");
//        // 调用dao层查询列表数据
//        List<Employee> employees = employeeDao.selectList(queryWrapper2);
//        // 打印列表数据
//        System.out.println("列表数据 :" + employees);


        // 需求6:
        // delete employee where id between 1 and 3  (他会删除id为1,2,3这三条数据)
        employeeDao.delete(new QueryWrapper<Employee>()
                .between("id",1,3));


    }


    @Test
    void test1(){
        // 调用DepartmentService进行查询
        Department department = departmentService.getDepartment(1);
        System.out.println(department);
    }

}
```

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1754405307967-e9fb0ded-6416-4764-9510-e043fb14960b.png)

## 六. 实现智慧运动管理员端登陆功能

## 七. 搭建智慧AI宠物平台前端

前端解压:

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763347241250-dea206b6-ecfb-4ea2-9e01-8989febee2e9.png)

文件结构如下所示

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763347248816-367cfdeb-9777-47ba-8384-8d8236151c8b.png)

### 1 下载nvm工具

先卸载本地安装的node.js,再安装nvm工具

官网:[https://nvm.uihtm.com/doc/download-nvm.html](https://nvm.uihtm.com/doc/download-nvm.html)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763347446277-53a52155-4d8c-4952-94ce-5e8297d6007d.png)

下载好之后的压缩包:

直接解压双击傻瓜式安装即可

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763347475874-ab217ff5-2511-40db-98e6-251f524da410.png)

### 2 nvm使用

**nvm**（Node Version Manager）是一个用于管理多个 **Node.js** 版本的命令行工具。它允许你在同一台机器上轻松安装、切换和使用不同版本的 Node.js，非常适合开发中需要兼容不同项目所依赖的 Node.js 版本的场景。

#### 2.1node.js介绍

**Node.js** 是一个可以让 JavaScript 在电脑（服务器）上运行的环境，不只是在浏览器里。它适合做后端服务、API、工具等。

**npm**（Node Package Manager）是 Node.js 自带的包管理工具，用来安装、管理和共享代码库（比如别人写好的功能模块）。它是全球最大的开源软件注册表。

简单说：

- **Node.js**：运行 JS 的后端平台。

- **npm**：装 JS 第三方库的“应用商店”。

#### 2.2查看可下载的node.js版本

```
nvm list available
```

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763347695388-ecc1fcc8-eabd-4c71-9031-c7cc52ab16f0.png)

#### 2.3下载对应版本(例:这里下载node.js 16.20.0)

```
nvm install 16
```

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763347929479-76da382c-e991-455f-bba2-65ede8bb82e1.png)

#### 2.4查看已经下载的node.js版本

```
nvm list
```

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763347979275-81233136-28a0-4ce2-8bc0-061bb089f36a.png)

#### 2.5切换node.js版本

```
nvm use 16.20.0
```

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763348054197-381c0b7f-045e-45be-93e7-db0edc93e048.png)

此时再次查看node.js版本,这是使用版本前会有星号(*)提示

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763348093026-c24dd4cc-becc-4682-9ca1-51989c99be9e.png)

### 3前端运行

打开前端文件夹

#### 3.1先删除package-lock.json文件

右键删除就可以

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763348986652-d1710112-ac3f-4d23-9a36-f2d4593f5ffb.png)

#### 3.2打开终端输入

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1780910711630-780d8da5-c0b5-4f22-9419-6f8735390a58.png)

npm设置淘宝源镜像仓库

```
npm config set registry https://registry.npmmirror.com
```

下载依赖

```
npm install --legacy-peer-deps
```

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763349694680-d1d9034e-aad8-429e-bb8e-c0c2b5a31b56.png)

等待下载完成

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763349733447-7e3bcc7e-1b8b-43c7-aec2-f5f744d0acbb.png)

成功下载122个包

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763349751113-32877cdf-e94e-4c40-b10f-c78b5dd2c511.png)

此时会多出一个文件夹node_modules

`node_modules` 是 Node.js 项目中一个**自动生成的文件夹**，用来存放项目所依赖的所有第三方包（也就是通过 `npm install`安装的模块）。

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763361619876-337b6d19-8cb9-4528-aeab-54fe8c6b6824.png)

#### 3.3运行前端

```
npm run dev
```

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1780911142828-9504332e-3b7f-480e-aaef-64dfe2143aa9.png)

运行成功,访问路径为: [http://localhost:8080/](http://localhost:8080/)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763349991528-63d5d2e3-62df-4c63-a0e7-00842f03bbb8.png)

## 八. 智慧AI宠物管理平台后端

### 1 项目搭建

#### 1.1完整pom.xml文件

```
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 https://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <parent>
        <groupId>org.springframework.boot</groupId>

        <artifactId>spring-boot-starter-parent</artifactId>

        <version>3.2.8</version>

        <relativePath/> <!-- lookup parent from repository -->
    </parent>

    <groupId>com.qf</groupId>

    <artifactId>pet</artifactId>

    <version>0.0.1-SNAPSHOT</version>

    <name>pet</name>

    <description>pet</description>

    <url/>
    <licenses>
        <license/>
    </licenses>

    <developers>
        <developer/>
    </developers>

    <scm>
        <connection/>
        <developerConnection/>
        <tag/>
        <url/>
    </scm>

    <properties>
        <java.version>17</java.version>

    </properties>

    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>

            <artifactId>spring-boot-starter-web</artifactId>

        </dependency>

        <dependency>
            <groupId>org.mybatis.spring.boot</groupId>

            <artifactId>mybatis-spring-boot-starter</artifactId>

            <version>3.0.3</version>

        </dependency>

        <dependency>
            <groupId>com.mysql</groupId>

            <artifactId>mysql-connector-j</artifactId>

            <scope>runtime</scope>

        </dependency>

        <dependency>
            <groupId>org.projectlombok</groupId>

            <artifactId>lombok</artifactId>

            <optional>true</optional>

        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>

            <artifactId>spring-boot-starter-test</artifactId>

            <scope>test</scope>

        </dependency>

        <dependency>
            <groupId>org.mybatis.spring.boot</groupId>

            <artifactId>mybatis-spring-boot-starter-test</artifactId>

            <version>3.0.3</version>

            <scope>test</scope>

        </dependency>

        <dependency>
            <groupId>org.springframework.boot</groupId>

            <artifactId>spring-boot-starter-mail</artifactId>

            <version>3.3.0</version>

        </dependency>

        <dependency>
            <groupId>com.alipay.sdk</groupId>

            <artifactId>alipay-sdk-java</artifactId>

            <version>4.39.185.ALL</version>

        </dependency>

        <dependency>
            <groupId>com.github.xiaoymin</groupId>

            <artifactId>knife4j-openapi3-jakarta-spring-boot-starter</artifactId>

            <version>4.3.0</version>

        </dependency>


        <dependency>
            <groupId>jakarta.persistence</groupId>

            <artifactId>jakarta.persistence-api</artifactId>

            <version>3.2.0</version>

        </dependency>

        <dependency>
            <groupId>cn.hutool</groupId>

            <artifactId>hutool-all</artifactId>

            <version>5.8.25</version>

        </dependency>

        <dependency>
            <groupId>org.springdoc</groupId>

            <artifactId>springdoc-openapi-starter-webmvc-ui</artifactId>

            <version>2.5.0</version>

        </dependency>

        <dependency>
            <groupId>com.baomidou</groupId>

            <artifactId>mybatis-plus-spring-boot3-starter</artifactId>

            <version>3.5.5</version>

        </dependency>


        <!--JWTUtil-->
        <dependency>
            <groupId>junit</groupId>

            <artifactId>junit</artifactId>

            <version>4.11</version>

            <scope>test</scope>

        </dependency>

        <dependency>
            <groupId>io.jsonwebtoken</groupId>

            <artifactId>jjwt</artifactId>

            <version>0.9.1</version>

        </dependency>

        <dependency>
            <groupId>javax.xml.bind</groupId>

            <artifactId>jaxb-api</artifactId>

            <version>2.3.0</version>

        </dependency>

        <dependency>
            <groupId>com.sun.xml.bind</groupId>

            <artifactId>jaxb-impl</artifactId>

            <version>2.3.0</version>

        </dependency>

        <dependency>
            <groupId>com.sun.xml.bind</groupId>

            <artifactId>jaxb-core</artifactId>

            <version>2.3.0</version>

        </dependency>

        <dependency>
            <groupId>javax.activation</groupId>

            <artifactId>activation</artifactId>

            <version>1.1.1</version>

        </dependency>

        <dependency>
            <groupId>com.fasterxml.jackson.core</groupId>

            <artifactId>jackson-databind</artifactId>

            <version>2.15.2</version>

        </dependency>

        <!--   百度千帆     -->
        <dependency>
            <groupId>io.github.gemingjia</groupId>

            <artifactId>gear-wenxinworkshop-starter</artifactId>

            <version>0.0.6</version>

        </dependency>


    </dependencies>

    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>

                <artifactId>spring-boot-maven-plugin</artifactId>

                <configuration>
                    <excludes>
                        <exclude>
                            <groupId>org.projectlombok</groupId>

                            <artifactId>lombok</artifactId>

                        </exclude>

                    </excludes>

                </configuration>

            </plugin>

        </plugins>

    </build>

</project>
```

#### 1.2完整application.yml文件

```
# 服务器配置
server:
  port: 8889
  servlet:
    context-path: /
spring:
  # 应用配置
  application:
    name: petBack
  # 数据库配置
  datasource:
    driver-class-name: com.mysql.cj.jdbc.Driver
    url: jdbc:mysql://localhost:3306/pet?useUnicode=true&characterEncoding=utf-8&allowMultiQueries=true&useSSL=false&serverTimezone=GMT%2b8&allowPublicKeyRetrieval=true
    username: root
    password: 19971221
  # 安全配置
  security:
    user:
      name: admin
      password: admin
  # 文件上传配置
  servlet:
    multipart:
      max-file-size: 10MB
      max-request-size: 20MB
  # 静态资源配置
  mvc:
    static-path-pattern: /**
  web:
    resources:
      static-locations: classpath:/static/
  # 邮件配置
  mail:
    host: smtp.qq.com
    username: 1051605897@qq.com
    password: cfgwjfkyhfynbfjb
    default-encoding: utf-8
    port: 587
    properties:
      mail:
        debug: true
        smtp:
          auth: true
          ssl:
            enable: true
            protocols: TLSv1.2
          socketFactory:
            class: javax.net.ssl.SSLSocketFactory
            port: 465

# MyBatis 配置
mybatis:
  configuration:
    map-underscore-to-camel-case: true
    use-built-in-alias-types: true

# MyBatis-Plus 配置
mybatis-plus:
  mapper-locations: classpath:/mapper/*.xml
  global-config:
    db-config:
      id-type: auto
      use-id-generator: false
  configuration:
    log-impl: org.apache.ibatis.logging.stdout.StdOutImpl

# SpringDoc (Swagger) 配置
springdoc:
  enable-spring-security: false
  api-docs:
    path: /v3/api-docs
    enabled: true
  swagger-ui:
    path: /swagger-ui.html
    enabled: true
    tags-sorter: alpha
    operations-sorter: alpha
  paths-to-match: /**
  packages-to-scan: com.example.petback.controller

# Knife4j 配置
knife4j:
  enable: true
  setting:
    language: zh_cn

# 自定义配置
baseUrl: http://localhost:8889
user:
  defaultPassword: 123456
  fromEmail: 1051605897@qq.com

# 支付宝配置
alipay:
  app-id: 9021000140623471
  app-private-key: MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQCQpuLhEYrpuaAKHF5D4EZ2ObgVqy5PFaBCsH8Y8ep5JF2MDHn/rRG6YXaw23WncnUn/6yFlwdpwRAHojWUlK33XxLEFR9V4q5QfDh2URPp6JQEp8fuWroncUziHnPpV/heFN02NWcwr1j729NghwOuYeJAWg4WxJH5521WRyBPEPN/WErthFFUojLH3mkaJ19n7bR4ARnNLQ0AP7cYfh0x6apNwzPGj7GbVgaxW0mQMXl6PrvZ4twoBhZwaUQFAfhWqQtWV1VwLt+Of0n7SbuKj6ohLb8O50VBlYf+nTC2aSBtv3G1atigGUciAqiU19yH6VGrKJJ7zzDCmSwPxJYxAgMBAAECggEAPJSYGjiVm/Mw0ms1E2o/OE5OCU0q1NYyyxtN722JjHitcPTctzaNYShmZAVVTe6CoGDUqRIqeaDwjLHjjLmD7kD0BAjwmbCY3n5Xyz2DgIf2TcjS08FNiy1JTL4CP2ynSQel6YkOEXauZrSW3ytMYGEAN4E/u0tR83537RVWs6W5p7BU8Fsl+p7zVdEClfahgLjjidVVApVi5u/YXydHVyTDfQpc9XqA4oQt2hhC3uLwiFnbOZRp2spDrtcTvC5A4/kXdc1YJ7Rxpi7Swxwyt1S5UWOQcDQHyfVE5XeVn9Il6ucv7syQuYe4aqrlYO6OVW3w0j77bhvZxJpMoM+zvQKBgQDv3URjw/bxVoVlHZ/58VUyv8R0OgQ0ZLcShktoJHEMe7ggD9gfit3LkoNrY7eH4LLyZNS7C5GKJ/pqtSeRnovqKQeSSft+OxCzIyXsIzJCz53yteghcdt4e0hjd3tcH8AiKwqLB3Wjv2CdUuwLd4djqlWcmBdMdvoH/ALgxwxFpwKBgQCaYfRMCZZrSjQQxB+O0NY1bivN24q5lxxz5KPBycZS/saZaziiM7KCwcmCY1yB59mjzu0BeTFhYOy6gSt+O0blpmg4IgSdRG1k8eDXvXtgHHbC0zH5d/UR5cn6PcxbOI+86ieNCYa9wGrlDQRjYa6urs76fn03+xVP3t1kZDjwZwKBgGiRww3nUdHW0WLKroKNdoIgXin5XPnmanV1/IvTT0GM8jFwFt1xcc4c+pQnrcxb5keMM72zhmh/k0lP3oc6Ym7cIkPhYvWeFGK0UQUINxIvZwF30lI6S97TiDRs02fPI7kBoKAJyXxwo1MS4nsBShHmIVqaZ5XbTJeMg0ixHiWDAoGAJAXPNx7VlltOIstggbaBBR6b4gDkMcHsxa4H9+PY/uyr8ohuQorFkHUfS+lbYIR06CAUdU+OEibHlg0l1OKH/HYDw3VMllWtIOy/hheUfiymGXemJYu0B2US5+0bjf14rKAGcoZShlwrlR6gc4ALfn8TlKeHGFTh+C0Mg6xPDOkCgYEA6zuA5tCxp+/4vH6XZ+HX1FVCQClZqJo4Xd4NXrHaLPSc2D7x5vV31BqTRXDyhugzVLJs6lBsR+n42HCZCKcIKebNSmpAktgA4P0b8pk8YAqU9abv2PMdDwe//jV7aXI1m1pFnkMOV5qoB27bgdq1tQRd1INg8EnVfEU6taE0Xj8=
  alipay-public-key: MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAiMD4FvmHpaJFAYYb83fUY0kIZSWqARP9rKIYgkbQ7PYF5VsrmTwd8TftQxOVrz+YjR+md7neDmPCDsMNXVGQLXd5mUqVF5UC6+jVuNI3f8abJfG3FZd8BteKdOnCLoZj+D7ZZv6DFFNKAvCeXbXqhCuKpXA/+FdndLEGqcGWST/+dJJ8UxVACK3LOz6/HAIncMv1uoU7fpgqOpzMnVkAB9VGJqaTvG4QK6jy453/j0Z05HpR9MJGx2cfcLNmX5mQHEngmbPxk4ny51RthMkodAoFIKhfQFkZvNx9IJvsy8UveNT58wrNBv3fxsAXgiakNEYH//QtLRf6+D+hwFMI5QIDAQAB

# 百度文心一言配置
baidu:
  wenxin:
    api-key: jcw0bcntrrewf8oYt7fzM1EA
    secret-key: DG8J0LED1M2c2zsDQVljtEAitzMg2zRz

# 日志配置
logging:
  level:
    com.baomidou.mybatisplus.core.MybatisConfiguration: OFF

# Jackson 配置
spring.jackson:
  default-property-inclusion: non_empty

# Spark API Configuration
spark:
  app-id: 29b2d545
  api-key: 1adc0cf4a649e80a618a61242093a1c3
  api-secret: MGM0ZThmYTZiNGY3YjlkZWQxZmFjNWJl
  api-url: https://spark-api-open.xf-yun.com/v1/chat/completions  # 修改为v1端点
  model: lite  # 根据v1端点选择合适的模型
  api-password: XSrAcYcUqAMKkWlRnTHk:KxWYFDwzzcnzbiwhUrFe
```

#### 1.3创建mvc三层架构对应的包结构

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763363601421-96306764-12ac-4984-9926-a9deada182c7.png)

#### 1.4在启动类上添加mybatis-plus提供扫描dao层注解

```
package com.qf;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

// 扫描指定包下的MyBatis映射器接口
@MapperScan("com.qf.dao")
@SpringBootApplication
public class PetApplication {

    public static void main(String[] args) {
        SpringApplication.run(PetApplication.class, args);
    }

}
```

#### 1.5创建config在包下继续创建config包,并创建mybatisplus的分页插件配置类MybatisPlusConfig

```
package com.qf.config;

import com.baomidou.mybatisplus.annotation.DbType;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.core.config.GlobalConfig;
import com.baomidou.mybatisplus.core.config.GlobalConfig.DbConfig;
import com.baomidou.mybatisplus.extension.plugins.MybatisPlusInterceptor;
import com.baomidou.mybatisplus.extension.plugins.inner.PaginationInnerInterceptor;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class MybatisPlusConfig {

    /**
     * 分页插件
     */
    @Bean
    //MybatisPlusInterceptor是MybatisPlus提供的拦截器
    public MybatisPlusInterceptor mybatisPlusInterceptor() {
        // 创建MybatisPlusInterceptor实例
        MybatisPlusInterceptor interceptor = new MybatisPlusInterceptor();
        // 添加分页插件，指定数据库类型为MYSQL
        interceptor.addInnerInterceptor(new PaginationInnerInterceptor(DbType.MYSQL));
        // 返回配置好的拦截器
        return interceptor;
    }

    // 定义一个全局配置的Bean
    @Bean
    // 创建全局配置实例
    public GlobalConfig globalConfig() {
        // 实例化GlobalConfig对象(GlobalConfig是Mybatisplus提供的全局缓存配置类)
        GlobalConfig globalConfig = new GlobalConfig();

        // 创建并配置DbConfig(DbConfig用于存储和管理数据库配置的类)
        DbConfig dbConfig = new DbConfig();
        // 设置数据库主键生成策略为自增
        dbConfig.setIdType(IdType.AUTO);

        // 将DbConfig设置到GlobalConfig
        globalConfig.setDbConfig(dbConfig);

        // 返回全局配置实例
        return globalConfig;
    }
}
```

#### 1.6因为我们项目后端需返回JSON格式数据,所以需要用到Result工具类,在utils包下创建该类

```
package com.qf.utils;

import lombok.Data;

/**
 * 统一 API 响应包装类。
 * 所有 Controller 和 Service 层方法均返回此类型，
 * Jackson 序列化后生成 JSON 结构：{"code": "...", "msg": "...", "data": ...}
 * 使用示例：
 * // 成功（无数据）
 * return Result.success();
 * // 成功（带数据）
 * return Result.success(someObject);
 * // 失败
 * return Result.error("-1", "操作失败原因");
 */

@Data
public class Result {

    /** 状态码："0" 表示成功，其他值表示各种错误类型 */
    private String code;

    /** 提示消息，成功时为"成功"，失败时为具体错误描述 */
    private String msg;

    /** 响应数据载荷，可为任意类型对象 */
    private Object data;

    // ==================== 构造器 ====================

    public Result() {
    }

    public Result(Object data) {
        this.data = data;
    }

    /**
     * 创建成功响应（无数据载荷）。
     * @return code="0", msg="成功", data=null
     */
    public static Result success() {
        Result result = new Result();
        result.setCode("0");
        result.setMsg("成功");
        return result;
    }

    /**
     * 创建成功响应（携带数据载荷）。
     * @param data 要返回的数据对象，可为任意类型
     * @return code="0", msg="成功", data=传入的对象
     */
    public static Result success(Object data) {
        Result result = new Result(data);
        result.setCode("0");
        result.setMsg("成功");
        return result;
    }

    /**
     * 创建错误响应。
     * @param code 自定义错误码
     * @param msg  错误描述消息
     * @return code=自定义码, msg=错误描述, data=null
     */
    public static Result error(String code, String msg) {
        Result result = new Result();
        result.setCode(code);
        result.setMsg(msg);
        return result;
    }
}
```

## 九. 实现登陆注册和忘记密码功能

### 1 实现用户登录功能

创建对应实体类包entity包,并创建用户对应User实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import jakarta.validation.constraints.NotBlank;
import jakarta.validation.constraints.Pattern;
import jakarta.validation.constraints.Size;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

//lombok注解，生成构造方法、getter、setter方法、toString方法
@Data
//无参构造方法
@NoArgsConstructor
//有参构造方法
@AllArgsConstructor
//表名
@TableName("user")
public class User {

    @TableId(type = IdType.AUTO)
    private Integer id;

    @NotBlank(message = "用户名不能为空")
    @Size(min = 3, max = 50, message = "用户名长度必须在3到50个字符之间")
    private String username;

    @NotBlank(message = "密码不能为空")
    @Size(min = 6, max = 20, message = "密码长度必须在6到20个字符之间")
    private String password;

    private String name;

    private String avatar;

    private String role;

    private String sex;

    private String phone;

    // 该注解用于验证字符串是否符合指定的邮箱格式正则表达式
    @Pattern(regexp = "^[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)*@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$", message = "邮箱格式不正确")
    private String email;

    private String address;

    private Double account;

    // @TableField(exist = false) 是 MyBatis-Plus 框架中的一个注解，用于标识该字段在数据库表中不存在。这个字段通常是用于在对象中存储一些额外的信息，这些信息并不直接映射到数据库中的某个字段。
    @TableField(exist = false)
    // 声明一个私有的List类型变量menuList，用于保存Menu对象
    private List<Menu> menuList;
}
```

创建sys_menu表对应的实体类Menu

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.v3.oas.annotations.media.Schema;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;


@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("sys_menu")
public class Menu {

    @TableId(type = IdType.AUTO)
    private Integer id;

    private String name;

    private String path;

    private String icon;

    private String description;

    private Integer pid;

    private String pagePath;

    private Integer sortNum;

    @TableField(exist = false)
    private List<Menu> children;

    private Integer role;
}
```

在enums包下创建权限的UserRole枚举类

```
package com.qf.enums;

public enum UserRole {
    // 枚举常量：角色实例
    ADMIN(1, "ADMIN", "管理员"),        // 普通管理员
    USER(2, "USER", "用户"),            // 普通用户
    SUPER_ADMIN(3, "SUPER_ADMIN", "超级管理员");  // 超级管理员

    // 角色编码（数字标识）
    private final Integer id;
    // 角色英文标识
    private final String value;
    // 角色中文名称
    private final String name;

    /**
     * 枚举私有构造方法
     *
     * @param id    角色数字编码
     * @param value 角色英文标识
     * @param name  角色中文名称
     */
    UserRole(Integer id, String value, String name) {
        this.id = id;
        this.value = value;
        this.name = name;
    }

    // 可以添加getter方法来访问枚举的属性
    public Integer getId() {
        return id;
    }

    public String getValue() {
        return value;
    }

    public String getName() {
        return name;
    }
}
```

创建用户模块controller层UserController

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.User;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

//这里的RestController注解表示，该类下的所有方法都可以直接返回json数据(其实就是@Controller和@ResponseBody的组合)
@RestController
//这里的RequestMapping注解表示，该类下的所有方法都可以被映射到/user路径下
@RequestMapping("/user")
public class UserController {

    //注入UserService
    @Autowired
    private UserService userService;

    //这里的RequestMapping注解表示，该方法可以被映射到/login路径下
    @RequestMapping("/login")
    //@RequestBodys注解表示，该方法的入参是json格式的请求体
    public Result login(@RequestBody User user) {
        //调用service层处理登录逻辑
        Result login = userService.login(user);
        //返回结果
        return login;
    }
}
```

创建用户模块service层UserService

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.User;

public interface UserService extends IService<User> {

    Result login(User user);
}
```

创建用户模块service层对应实现类UserServiceImpl

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.MenuDao;
import com.qf.dao.UserDao;
import com.qf.entity.Menu;
import com.qf.entity.User;
import com.qf.enums.UserRole;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class UserServiceImpl extends ServiceImpl<UserDao, User> implements UserService {

    // 注入UserDao
    @Autowired
    private UserDao userDao;

    //注入MenuDao
    @Autowired
    private MenuDao menuDao;


    @Override
    public Result login(User user) {
        // 创建LambdaQueryWrapper对象，用于构建查询条件
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        // 设置查询条件，查询用户名等于传入用户对象的用户名

        //eq方法为"="方法的简化写法,User::getUsername为lambda表达式,作用是获取User表的字段名username
        queryWrapper.eq(User::getUsername, user.getUsername());
        // 根据查询条件从数据库中查询用户信息
        User loginUser = userDao.selectOne(queryWrapper);
        // 如果查询结果为空，返回错误信息，提示用户不存在
        if (loginUser == null) {
            return Result.error("-1", "登录失败，用户不存在！");
        }
        // 初始化UserRole对象，用于存储查询到的用户角色
        UserRole loginRole = null;
        // 获取用户的角色信息
        String role = loginUser.getRole();
        // 根据角色信息设置对应的UserRole对象
        if (role.equals(UserRole.USER.getValue())) {
            loginRole = UserRole.USER;
        } else if (role.equals(UserRole.ADMIN.getValue())) {
            loginRole = UserRole.ADMIN;
        } else if (role.equals(UserRole.SUPER_ADMIN.getValue())) {
            loginRole = UserRole.SUPER_ADMIN;
        } else {
            // 如果角色信息不匹配任何已知角色，返回错误信息，提示角色信息异常
            return Result.error("-1", "登陆失败，角色信息异常");
        }
        // 如果用户角色ID不等于3（3为SUPER_ADMIN）
        if (loginRole.getId() != 3) {
            // 根据角色ID和3查询菜单列表
            // 查询角色为 roleId 或3 的菜单列表
            List<Menu> roleMenuList = menuDao.selectList(
                    new LambdaQueryWrapper<Menu>()
                            //in 方法用于查询 Menu 表中 role 字段的值等于 loginRole.getId() 或者 3 的所有记录
                            .in(Menu::getRole, Arrays.asList(loginRole.getId(), 3))
            );
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            // 作用:筛选集合中父菜单 ID（pid）为空的菜单作为一级父菜单,并转换为集合
            //stream() 方法用于将集合转换为流，filter 方法用于过滤集合，toList() 方法用于将流转换为集合
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                //collect是收集器
                //Collectors.toList()是转换器
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        } else {
            // 如果用户角色ID等于3，查询所有菜单列表
            // 查询所有菜单列表
            List<Menu> roleMenuList = menuDao.selectList(null);
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        }

        // 验证用户密码是否匹配
        // 如果传入的用户密码与数据库中查询到的用户密码匹配
        if (user.getPassword().equals(loginUser.getPassword())) {
            // 返回成功信息，包含用户对象
            return Result.success(loginUser);
        } else {
            // 返回错误信息，提示用户名或密码错误
            return Result.error("-1", "登录失败，用户名或密码错误！");
        }
    }

}
```

创建对应dao层接口UserDao与MenuDao

UserDao:

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.User;

public interface UserDao extends BaseMapper<User> {

}
```

MenuDao:

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.Menu;

public interface MenuDao extends BaseMapper<Menu> {
}
```

注意查看登录请求成功之后返回的JSON数据

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763610909671-cc36610b-3bb2-46d2-9039-697bdf5cf1a0.png)

将图片文件夹拷贝进此项目根路径下

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783390934307-d59cb1bd-6938-4b2a-86d0-ed208aca9ecb.png)

**注意存放位置**

![](https://cdn.nlark.com/yuque/0/2026/png/40865112/1783390970397-07325cc8-b0af-4207-9a91-dabfbf3a03dd.png)

### 2 实现用户注册功能

#### 2.1用户需要绑定邮箱,我们先处理关于邮箱验证码校验功能

在controller包下创建关于邮箱功能模块EmailController控制类

```
package com.qf.controller;


import com.qf.utils.Result;
import com.qf.entity.User;
import com.qf.service.EmailService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

//RestController注解表示，该类下的所有方法都可以直接返回json数据(其实就是@Controller和@ResponseBody的组合)
@RestController
//CrossOrigin注解表示，允许跨域请求
@CrossOrigin
//RequestMapping注解表示，该类下的所有方法都可以被映射到/email路径下
@RequestMapping("/email")
public class EmailController {

    //注入UserEmailService
    @Autowired
    private EmailService emailService;

    /**
     * 发送注册验证码接口
     */
    @RequestMapping("/sendEmail")
    public Result emailRegister(@RequestBody User user) {
        // 核心业务逻辑委托给Service层处理
        return emailService.sendRegisterCodeEmail(user);
    }


}
```

创建对应service层接口EmailService,并sendRegisterCodeEmail抽象方法

```
package com.qf.service;

import com.qf.entity.User;
import com.qf.utils.Result;

/**
 * 邮箱相关业务接口（注册验证码发送）
 */
public interface EmailService {

    /**
     * 发送注册验证码邮件
     * @param user 包含注册邮箱的用户对象（核心参数：email）
     * @return 发送结果（成功返回验证码，失败返回错误信息）
     */
    Result sendRegisterCodeEmail(User user);
}
```

创建接口EmailService对应的实现类EmailServiceImpl,并重写sendRegisterCodeEmail抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.qf.utils.Result;
import com.qf.dao.UserDao;
import com.qf.entity.User;
import com.qf.service.EmailService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.stereotype.Service;

import java.util.Random;

@Service
public class EmailServiceImpl implements EmailService {

    //注入JavaMailSender处理邮件发送的接口
    @Autowired
    private JavaMailSender javaMailSender;


    //@Value注解用于注入配置文件中的属性值
    @Value("${user.fromEmail}")
    private String FROM_EMAIL;

    //注入userDao
    @Autowired
    private UserDao userDao;


    @Override
    public Result sendRegisterCodeEmail(User user) {
        // 查询数据库中是否存在相同邮箱的用户
        Long email = userDao.selectCount(new QueryWrapper<User>().eq("email", user.getEmail()));
        // 如果存在相同邮箱的用户，则返回错误信息，提示邮箱已存在
        if(email>0){
            Result.error("-1","邮箱已存在，请勿重复注册");
        }
        // 创建一个随机数生成器
        Random random = new Random();
        // 生成一个6位数的随机验证码，范围在100000到999999之间
        int code= random.nextInt(899999)+100000;
        // 创建一个SimpleMailMessage对象，用于发送邮件
        SimpleMailMessage simpleMailMessage = new SimpleMailMessage();
        // 设置发件人邮箱地址
        simpleMailMessage.setFrom(FROM_EMAIL);
        // 设置收件人邮箱地址，即用户提供的邮箱地址
        simpleMailMessage.setTo(user.getEmail());
        // 设置邮件主题
        simpleMailMessage.setSubject("管理系统验证码");
        // 设置邮件正文，包含生成的验证码，并提醒用户不要转发
        simpleMailMessage.setText("邮箱验证码为："+code+",请勿转发给他人");
        // 尝试发送邮件
        try{
            // 使用javaMailSender发送邮件
            javaMailSender.send(simpleMailMessage);
            // 如果邮件发送成功，则返回成功的结果，包含验证码
            return Result.success(code);
        // 捕获并处理邮件发送过程中可能出现的异常
        }catch (Exception e){
            // 如果邮件发送失败，则返回错误信息，提示验证码发送异常，并建议联系管理员
            return Result.error("-1","验证码发送异常，请联系管理员。");
        }
    }
}
```

因为我们直接调用的是UserDao接口,所以可以不用创建对应的EmailDao接口了

#### 2.2实现用户注册功能

在UserController中添加createUser方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.User;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

//这里的RestController注解表示，该类下的所有方法都可以直接返回json数据(其实就是@Controller和@ResponseBody的组合)
@RestController
//这里的RequestMapping注解表示，该类下的所有方法都可以被映射到/user路径下
@RequestMapping("/user")
public class UserController {

    //注入UserService
    @Autowired
    private UserService userService;

    //这里的RequestMapping注解表示，该方法可以被映射到/login路径下
    @RequestMapping("/login")
    //@RequestBodys注解表示，该方法的入参是json格式的请求体
    public Result login(@RequestBody User user) {
        //调用service层处理登录逻辑
        Result login = userService.login(user);
        //返回结果
        return login;
    }

    /**
     * 注册用户
     * @param user
     * @return
     */
    @RequestMapping("/register")
    public Result createUser(@RequestBody User user) {
        return userService.createUser(user);
    }
}
```

在UserService接口中创建createUser抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.User;

public interface UserService extends IService<User> {

    Result login(User user);

    Result createUser(User user);
}
```

在对应实现类UserServiceImpl中重写createUser抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.MenuDao;
import com.qf.dao.UserDao;
import com.qf.entity.Menu;
import com.qf.entity.User;
import com.qf.enums.UserRole;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class UserServiceImpl extends ServiceImpl<UserDao, User> implements UserService {

    // 注入UserDao
    @Autowired
    private UserDao userDao;

    //注入MenuDao
    @Autowired
    private MenuDao menuDao;

    @Value("${user.defaultPassword}")
    private  String DEFAULT_PWD ;


    @Override
    public Result login(User user) {
        // 创建LambdaQueryWrapper对象，用于构建查询条件
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        // 设置查询条件，查询用户名等于传入用户对象的用户名

        //eq方法为"="方法的简化写法,User::getUsername为lambda表达式,作用是获取User表的字段名username
        queryWrapper.eq(User::getUsername, user.getUsername());
        // 根据查询条件从数据库中查询用户信息
        User loginUser = userDao.selectOne(queryWrapper);
        // 如果查询结果为空，返回错误信息，提示用户不存在
        if (loginUser == null) {
            return Result.error("-1", "登录失败，用户不存在！");
        }
        // 初始化UserRole对象，用于存储查询到的用户角色
        UserRole loginRole = null;
        // 获取用户的角色信息
        String role = loginUser.getRole();
        // 根据角色信息设置对应的UserRole对象
        if (role.equals(UserRole.USER.getValue())) {
            loginRole = UserRole.USER;
        } else if (role.equals(UserRole.ADMIN.getValue())) {
            loginRole = UserRole.ADMIN;
        } else if (role.equals(UserRole.SUPER_ADMIN.getValue())) {
            loginRole = UserRole.SUPER_ADMIN;
        } else {
            // 如果角色信息不匹配任何已知角色，返回错误信息，提示角色信息异常
            return Result.error("-1", "登陆失败，角色信息异常");
        }
        // 如果用户角色ID不等于3（3为SUPER_ADMIN）
        if (loginRole.getId() != 3) {
            // 根据角色ID和3查询菜单列表
            // 查询角色为 roleId 或3 的菜单列表
            List<Menu> roleMenuList = menuDao.selectList(
                    new LambdaQueryWrapper<Menu>()
                            //in 方法用于查询 Menu 表中 role 字段的值等于 loginRole.getId() 或者 3 的所有记录
                            .in(Menu::getRole, Arrays.asList(loginRole.getId(), 3))
            );
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            // 作用:筛选集合中父菜单 ID（pid）为空的菜单作为一级父菜单,并转换为集合
            //stream() 方法用于将集合转换为流，filter 方法用于过滤集合，toList() 方法用于将流转换为集合
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                //collect是收集器
                //Collectors.toList()是转换器
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        } else {
            // 如果用户角色ID等于3，查询所有菜单列表
            // 查询所有菜单列表
            List<Menu> roleMenuList = menuDao.selectList(null);
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        }

        // 验证用户密码是否匹配
        // 如果传入的用户密码与数据库中查询到的用户密码匹配
        if (user.getPassword().equals(loginUser.getPassword())) {
            // 返回成功信息，包含用户对象
            return Result.success(loginUser);
        } else {
            // 返回错误信息，提示用户名或密码错误
            return Result.error("-1", "登录失败，用户名或密码错误！");
        }
    }

    @Override
    public Result createUser(User user) {
        // 检查用户名是否已存在
        Long checkUsername = userDao.selectCount(new LambdaQueryWrapper<User>().eq(User::getUsername, user.getUsername()));

        if (checkUsername >0) {
            // 如果用户名已存在，返回错误信息
            return Result.error("-1", "注册失败，用户名已存在");
        }
        Long checkEmail = userDao.selectCount(new LambdaQueryWrapper<User>().eq(User::getEmail, user.getEmail()));
        if (checkEmail>0) {
            // 如果邮箱已存在，返回错误信息
            return Result.error("-1", "注册失败，邮箱已存在");
        }
        // 检查用户密码是否为空或仅由空白字符组成，如果为空则设置默认密码
        if(!StringUtils.isNotBlank(user.getPassword())){
            user.setPassword(DEFAULT_PWD);
        }
        // 检查用户角色是否为空或仅由空白字符组成，如果为空则设置默认角色为普通用户
        if(!StringUtils.isNotBlank(user.getRole())){
            user.setRole(UserRole.USER.getValue());
        }else{
            // 如果用户角色不为空，检查角色是否为有效的预设角色（管理员、普通用户、超级管理员）
            if (!Arrays.asList(UserRole.ADMIN.getValue(), UserRole.USER.getValue(), UserRole.SUPER_ADMIN.getValue()).contains(user.getRole())) {
                // 如果角色无效，返回错误信息
                return Result.error("-1", "无效的角色");
            }
        }
        // 保存用户信息到数据库
        // insert方法用于插入一条记录，返回受影响的行数
        int res = userDao.insert(user);
        // 如果受影响的行数大于0，返回成功信息，包含用户对象
        if (res > 0) {
            return Result.success(user);
        } else {
            // 如果受影响的行数等于0，返回错误信息
            return Result.error("-1", "注册失败");
        }
    }
}
```

#### 2.3完善个人信息功能

##### 2.3.1实现图片上传功能

在config包下创建关于文件上传大小的配置类MultipartConfig

```
package com.qf.config;

import jakarta.servlet.MultipartConfigElement;
import org.springframework.boot.web.servlet.MultipartConfigFactory;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.util.unit.DataSize;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

// 定义配置类，实现WebMvcConfigurer接口，用于配置Web MVC相关的设置
@Configuration
public class MultipartConfig implements WebMvcConfigurer {
    // 定义一个Bean，返回类型为MultipartConfigElement，用于配置文件上传的设置
    @Bean
    public MultipartConfigElement multipartConfigElement() {
        // 创建MultipartConfigFactory实例，用于生成文件上传配置
        MultipartConfigFactory factory = new MultipartConfigFactory();
        // 设置上传单个文件的最大大小为10MB
        factory.setMaxFileSize(DataSize.parse("10MB")); // 文件大小限制
        // 设置上传请求的最大大小为20MB，包括文件和表单数据
        factory.setMaxRequestSize(DataSize.parse("20MB")); // 请求大小限制
        // 使用工厂生成并返回MultipartConfigElement配置实例
        return factory.createMultipartConfig();
    }
}
```

创建utils包,并导入工具类FileUtil

```
package com.qf.utils;

import cn.hutool.core.lang.UUID;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import org.springframework.core.io.Resource;
import org.springframework.core.io.support.PathMatchingResourcePatternResolver;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class FileUtil {
    // 定义文件存储的基础路径，基于用户当前工作目录下的files文件夹
    public final static String FILE_BASE_PATH = System.getProperty("user.dir") + "/files/";

    // 获取项目根目录路径的方法
    public static Path getProjectRootPath() throws IOException {
        // 使用PathMatchingResourcePatternResolver来解析资源路径
        PathMatchingResourcePatternResolver resolver = new PathMatchingResourcePatternResolver();
        // 获取所有匹配classpath*:.*的资源
        Resource[] resources = resolver.getResources("classpath*:.");
        // 如果没有找到任何资源，抛出IOException异常
        if (resources.length == 0) {
            throw new IOException("Cannot find project root path.");
        }
        // 假设第一个资源就是项目的根目录，将其转换为File对象
        File rootDir = resources[0].getFile();
        // 将File对象转换为Path对象并返回
        return rootDir.toPath();
    }

    // 定义一个静态方法，用于保存上传的图片文件到指定路径
public static String saveImage(MultipartFile file, String filePath) {
    // 获取上传文件的原始文件名
    String originalFilename = file.getOriginalFilename();
    // 断言文件名不为空，如果为空则程序会在此处抛出错误
    assert originalFilename != null;
    // 获取当前时间戳，用于生成唯一的文件名
    long timestamp = System.currentTimeMillis();
    // 生成一个随机的UUID，用于生成唯一的文件名
    UUID uuid = UUID.randomUUID();
    // 获取文件扩展名，从原始文件名中截取
    String extension = originalFilename.substring(originalFilename.lastIndexOf("."));
    // 构建新的文件名，包含时间戳、UUID和原始文件扩展名
    String dFileName = timestamp + "-" + uuid + extension;

    // 获取项目根目录路径，FILE_BASE_PATH需要在其他地方定义为项目的根路径
    Path projectRootPath = Paths.get(FILE_BASE_PATH);

    // 检查filePath是否为空或为空字符串，如果为空则使用项目根目录下的“img/”目录作为目标目录
    // 否则，使用项目根目录下的“img/”目录加上用户提供的filePath作为目标目录
    Path targetDirectory = (filePath == null || filePath.isEmpty()) ? projectRootPath.resolve("img/") : projectRootPath.resolve("img/"+filePath);

    try {
        // 检查目标目录是否存在，如果不存在则创建该目录及其所有必要的父目录
        if (!Files.exists(targetDirectory)) {
            Files.createDirectories(targetDirectory);
        }
        // 构建完整的上传文件路径，包含目标目录和新的文件名
        Path uploadFilePath = targetDirectory.resolve(dFileName);
        // 将Path对象转换为File对象，以便后续的文件操作
        File uploadFile = uploadFilePath.toFile();

        // 将上传的文件内容写入到指定的文件路径
        file.transferTo(uploadFile);
        // 打印文件保存的绝对路径到控制台
        System.out.println("File saved at: " + uploadFile.getAbsolutePath());
    } catch (IOException e) {
        // 打印异常堆栈信息到控制台，用于调试
        e.printStackTrace();
        // 如果发生IO异常，则返回null，表示文件保存失败
        return null;
    }

    // 返回文件保存的相对路径，以便在Web应用中可以通过该路径访问文件
    // 如果filePath为空或为空字符串，则返回“/img/”加上新的文件名作为相对路径
    // 否则，返回用户提供的filePath加上新的文件名作为相对路径
    return (filePath == null || filePath.isEmpty()) ? "/img/" + dFileName : filePath + "/" + dFileName;
}



    // 删除指定路径下的文件的方法
    public static boolean deleteFile(String relativeFilePath) {
        // 获取项目根目录路径
        Path projectRootPath = Paths.get(FILE_BASE_PATH);

        // 构造要删除文件的绝对路径
        Path absoluteFilePath = projectRootPath.resolve("img/" + relativeFilePath);

        try {
            // 删除指定路径下的文件
            Files.delete(absoluteFilePath);
            // 打印已删除文件的绝对路径
            System.out.println("File deleted: " + absoluteFilePath);
            // 如果文件成功删除，返回true
            return true;
        } catch (IOException e) {
            // 打印异常堆栈信息
            e.printStackTrace();
            // 如果发生IO异常，返回false
            return false;
        }
    }

    // 生成文件名的方法，基于上传的MultipartFile对象
    private static String generateFileName(MultipartFile file) {
        // 获取上传文件的原始文件名
        String originalFilename = file.getOriginalFilename();
        // 断言原始文件名不为空
        assert originalFilename != null;
        // 获取当前时间戳
        long timestamp = System.currentTimeMillis();
        // 生成一个随机的UUID
        UUID uuid = UUID.randomUUID();
        // 获取文件的扩展名
        String extension = originalFilename.substring(originalFilename.lastIndexOf("."));
        // 构造新的文件名，格式为“时间戳-UUID.扩展名”
        String dFileName = timestamp + "-" + uuid + extension;
        // 返回构造的新文件名
        return dFileName;
    }

    // 从URL中移除指定部分的方法
    public static String removePartFromUrlUsingJSON(String url, String part) {
        // 构造一个JSONObject对象，包含原始的URL
        JSONObject jsonObject = JSON.parseObject("{\"url\":\"" + url + "\"}");
        // 从JSONObject中获取URL字符串
        String modifiedUrl = jsonObject.getString("url");
        // 如果URL包含要移除的部分，则执行移除操作
        if (modifiedUrl.contains(part)) {
            // 移除URL中的指定部分
            modifiedUrl = modifiedUrl.substring(0, modifiedUrl.indexOf(part)) + modifiedUrl.substring(modifiedUrl.indexOf(part) + part.length());
            // 如果移除后URL以斜杠结尾，则移除最后一个斜杠
            modifiedUrl = modifiedUrl.endsWith("/") ? modifiedUrl.substring(0, modifiedUrl.length() - 1) : modifiedUrl;
            // 将修改后的URL放回JSONObject中
            jsonObject.put("url", modifiedUrl);
        }
        // 返回修改后的URL字符串
        return jsonObject.getString("url");
    }
}
```

在config包下创建MyInterceptorConfig自定义配置类

```
package com.qf.config;

import com.qf.utils.FileUtil;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

import java.nio.file.Path;

// 定义一个配置类，实现WebMvcConfigurer接口以便配置Spring MVC
@Configuration
public class MyInterceptorConfig implements WebMvcConfigurer {

    // 重写WebMvcConfigurer接口中的addResourceHandlers方法，用于配置静态资源处理
    @Override
    public void addResourceHandlers(ResourceHandlerRegistry registry) {
        // 定义一个Path对象，用于存储项目根路径
        Path projectRootPath = null;
        // 将项目根路径设置为指定的基础路径
        projectRootPath = Path.of(FileUtil.FILE_BASE_PATH);
        // 定义图片文件夹的路径，基于项目根路径并解析出"img"目录的绝对路径
        String imgFolderPath = projectRootPath.resolve("img").toAbsolutePath().toString();
        // 添加资源处理器，将"/img/**"路径映射到指定的文件夹位置，用于访问静态图片资源
        registry.addResourceHandler("/img/**").addResourceLocations("file:" + imgFolderPath + "/");
    }
}
```

创建FileController

```
package com.qf.controller;

import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.qf.utils.Result;
import com.qf.utils.FileUtil;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;


@RequestMapping("/file")
@RestController
public class FileController {

    /**
     * 上传文件接口
     * @param file
     * @return
     */
    // 映射处理文件上传的请求路径为"/upload"
    @RequestMapping("/upload")
    public Result upLoad(@RequestParam("file") MultipartFile file) {
        // 检查上传文件的原始文件名是否为空，如果为空则返回错误信息"文件不存在！"
        if (StringUtils.isEmpty(file.getOriginalFilename())) {
            // 返回错误信息，错误码为"-1"，提示信息为"文件不存在！"
            return Result.error("-1", "文件不存在！");
        }
        // 调用FileUtil类的saveImage方法保存上传的文件，并将返回的文件路径赋值给path变量
        // 这里传递了两个参数：上传的文件和null（此处null可能是作为某个参数的默认值或占位符）
        String path = FileUtil.saveImage(file, null);
        // 检查path是否为空，如果不为空则表示文件上传成功
        if (StringUtils.isNotBlank(path)) {
            // 返回成功信息，包含上传文件的路径path
            return Result.success(path);
        } else {
            // 如果path为空，表示文件上传失败，则返回错误信息"文件上传失败"
            return Result.error("-1", "文件上传失败");
        }
    }

}
```

##### 2.3.2实现提交信息功能

在UserController中添加updateUser方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.User;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

//这里的RestController注解表示，该类下的所有方法都可以直接返回json数据(其实就是@Controller和@ResponseBody的组合)
@RestController
//这里的RequestMapping注解表示，该类下的所有方法都可以被映射到/user路径下
@RequestMapping("/user")
public class UserController {

    //注入UserService
    @Autowired
    private UserService userService;

    //这里的RequestMapping注解表示，该方法可以被映射到/login路径下
    @RequestMapping("/login")
    //@RequestBodys注解表示，该方法的入参是json格式的请求体
    public Result login(@RequestBody User user) {
        //调用service层处理登录逻辑
        Result login = userService.login(user);
        //返回结果
        return login;
    }

    /**
     * 注册用户
     * @param user
     * @return
     */
    @RequestMapping("/register")
    public Result createUser(@RequestBody User user) {
        return userService.createUser(user);
    }

    /**
     * 根据用户id添加/更新个人信息
     * @param id
     * @param user
     * @return
     */
    @RequestMapping("/{id}")
    public Result updateUser(@PathVariable Integer id, @RequestBody User user) {
        return userService.updateUser(id, user);
    }
}
```

在UserService中添加updateUser抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.User;

public interface UserService extends IService<User> {

    Result login(User user);

    Result createUser(User user);

    Result updateUser(Integer id, User user);
}
```

在对应实现类UserServiceImpl中重写updateUser抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.MenuDao;
import com.qf.dao.UserDao;
import com.qf.entity.Menu;
import com.qf.entity.User;
import com.qf.enums.UserRole;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class UserServiceImpl extends ServiceImpl<UserDao, User> implements UserService {

    // 注入UserDao
    @Autowired
    private UserDao userDao;

    //注入MenuDao
    @Autowired
    private MenuDao menuDao;

    @Value("${user.defaultPassword}")
    private  String DEFAULT_PWD ;


    @Override
    public Result login(User user) {
        // 创建LambdaQueryWrapper对象，用于构建查询条件
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        // 设置查询条件，查询用户名等于传入用户对象的用户名

        //eq方法为"="方法的简化写法,User::getUsername为lambda表达式,作用是获取User表的字段名username
        queryWrapper.eq(User::getUsername, user.getUsername());
        // 根据查询条件从数据库中查询用户信息
        User loginUser = userDao.selectOne(queryWrapper);
        // 如果查询结果为空，返回错误信息，提示用户不存在
        if (loginUser == null) {
            return Result.error("-1", "登录失败，用户不存在！");
        }
        // 初始化UserRole对象，用于存储查询到的用户角色
        UserRole loginRole = null;
        // 获取用户的角色信息
        String role = loginUser.getRole();
        // 根据角色信息设置对应的UserRole对象
        if (role.equals(UserRole.USER.getValue())) {
            loginRole = UserRole.USER;
        } else if (role.equals(UserRole.ADMIN.getValue())) {
            loginRole = UserRole.ADMIN;
        } else if (role.equals(UserRole.SUPER_ADMIN.getValue())) {
            loginRole = UserRole.SUPER_ADMIN;
        } else {
            // 如果角色信息不匹配任何已知角色，返回错误信息，提示角色信息异常
            return Result.error("-1", "登陆失败，角色信息异常");
        }
        // 如果用户角色ID不等于3（3为SUPER_ADMIN）
        if (loginRole.getId() != 3) {
            // 根据角色ID和3查询菜单列表
            // 查询角色为 roleId 或3 的菜单列表
            List<Menu> roleMenuList = menuDao.selectList(
                    new LambdaQueryWrapper<Menu>()
                            //in 方法用于查询 Menu 表中 role 字段的值等于 loginRole.getId() 或者 3 的所有记录
                            .in(Menu::getRole, Arrays.asList(loginRole.getId(), 3))
            );
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            // 作用:筛选集合中父菜单 ID（pid）为空的菜单作为一级父菜单,并转换为集合
            //stream() 方法用于将集合转换为流，filter 方法用于过滤集合，toList() 方法用于将流转换为集合
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                //collect是收集器
                //Collectors.toList()是转换器
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        } else {
            // 如果用户角色ID等于3，查询所有菜单列表
            // 查询所有菜单列表
            List<Menu> roleMenuList = menuDao.selectList(null);
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        }

        // 验证用户密码是否匹配
        // 如果传入的用户密码与数据库中查询到的用户密码匹配
        if (user.getPassword().equals(loginUser.getPassword())) {
            // 返回成功信息，包含用户对象
            return Result.success(loginUser);
        } else {
            // 返回错误信息，提示用户名或密码错误
            return Result.error("-1", "登录失败，用户名或密码错误！");
        }
    }

    @Override
    public Result createUser(User user) {
        // 检查用户名是否已存在
        Long checkUsername = userDao.selectCount(new LambdaQueryWrapper<User>().eq(User::getUsername, user.getUsername()));

        if (checkUsername >0) {
            // 如果用户名已存在，返回错误信息
            return Result.error("-1", "注册失败，用户名已存在");
        }
        Long checkEmail = userDao.selectCount(new LambdaQueryWrapper<User>().eq(User::getEmail, user.getEmail()));
        if (checkEmail>0) {
            // 如果邮箱已存在，返回错误信息
            return Result.error("-1", "注册失败，邮箱已存在");
        }
        // 检查用户密码是否为空或仅由空白字符组成，如果为空则设置默认密码
        if(!StringUtils.isNotBlank(user.getPassword())){
            user.setPassword(DEFAULT_PWD);
        }
        // 检查用户角色是否为空或仅由空白字符组成，如果为空则设置默认角色为普通用户
        if(!StringUtils.isNotBlank(user.getRole())){
            user.setRole(UserRole.USER.getValue());
        }else{
            // 如果用户角色不为空，检查角色是否为有效的预设角色（管理员、普通用户、超级管理员）
            if (!Arrays.asList(UserRole.ADMIN.getValue(), UserRole.USER.getValue(), UserRole.SUPER_ADMIN.getValue()).contains(user.getRole())) {
                // 如果角色无效，返回错误信息
                return Result.error("-1", "无效的角色");
            }
        }
        // 保存用户信息到数据库
        // insert方法用于插入一条记录，返回受影响的行数
        int res = userDao.insert(user);
        // 如果受影响的行数大于0，返回成功信息，包含用户对象
        if (res > 0) {
            return Result.success(user);
        } else {
            // 如果受影响的行数等于0，返回错误信息
            return Result.error("-1", "注册失败");
        }
    }

    @Override
    public Result updateUser(Integer id, User user) {
        //设置id
        user.setId(id);
        //根据id更新用户信息
        int res = userDao.updateById(user);
        if (res > 0) {
            // 如果更新成功，返回成功信息，包含用户对象
            return Result.success(user);
        } else {
            // 如果更新失败，返回错误信息
            return Result.error("-1", "更新失败");
        }
    }
}
```

#### 2.4实现忘记密码功能

##### 2.4.1实现忘记密码邮件发送验证码验证功能

在EmailController中添加findByEmail方法

```
package com.qf.controller;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.qf.utils.Result;
import com.qf.entity.User;
import com.qf.service.EmailService;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.web.bind.annotation.*;

import java.util.Random;

//RestController注解表示，该类下的所有方法都可以直接返回json数据(其实就是@Controller和@ResponseBody的组合)
@RestController
//CrossOrigin注解表示，允许跨域请求
@CrossOrigin
//RequestMapping注解表示，该类下的所有方法都可以被映射到/email路径下
@RequestMapping("/email")
public class EmailController {

    //注入UserEmailService
    @Autowired
    private EmailService emailService;

    /**
     * 发送注册验证码接口
     */
    @RequestMapping("/sendEmail")
    public Result emailRegister(@RequestBody User user) {
        // 核心业务逻辑委托给Service层处理
        return emailService.sendRegisterCodeEmail(user);
    }

    /**
     * 发送找回密码验证码接口
     * @param email
     * @return
     */
    @RequestMapping("/findByEmail")
    public Result findByEmail(@RequestParam String email) {
        return emailService.sendPasswordResetCode(email);
    }
}
```

在EmailService接口中创建sendPasswordResetCode抽象方法

```
package com.qf.service;

import com.qf.entity.User;
import com.qf.utils.Result;

/**
 * 邮箱相关业务接口（注册验证码发送）
 */
public interface EmailService {

    /**
     * 发送注册验证码邮件
     * @param user 包含注册邮箱的用户对象（核心参数：email）
     * @return 发送结果（成功返回验证码，失败返回错误信息）
     */
    Result sendRegisterCodeEmail(User user);

    /**
     * 发送密码重置验证码邮件
     * @param email 邮箱地址
     * @return 发送结果（成功返回验证码，失败返回错误信息）
     */
    Result sendPasswordResetCode(String email);
}
```

在对应EmailServiceImpl实现类中重写sendPasswordResetCode抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.qf.utils.Result;
import com.qf.dao.UserDao;
import com.qf.entity.User;
import com.qf.service.EmailService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.stereotype.Service;

import java.util.Random;

@Service
public class EmailServiceImpl implements EmailService {

    //注入JavaMailSender处理邮件发送的接口
    @Autowired
    private JavaMailSender javaMailSender;


    //@Value注解用于注入配置文件中的属性值
    @Value("${user.fromEmail}")
    private String FROM_EMAIL;

    //注入userDao
    @Autowired
    private UserDao userDao;


    @Override
    public Result sendRegisterCodeEmail(User user) {
        // 查询数据库中是否存在相同邮箱的用户
        Long email = userDao.selectCount(new QueryWrapper<User>().eq("email", user.getEmail()));
        // 如果存在相同邮箱的用户，则返回错误信息，提示邮箱已存在
        if (email > 0) {
            Result.error("-1", "邮箱已存在，请勿重复注册");
        }
        // 创建一个随机数生成器
        Random random = new Random();
        // 生成一个6位数的随机验证码，范围在100000到999999之间
        int code = random.nextInt(899999) + 100000;
        // 创建一个SimpleMailMessage对象，用于发送邮件
        SimpleMailMessage simpleMailMessage = new SimpleMailMessage();
        // 设置发件人邮箱地址
        simpleMailMessage.setFrom(FROM_EMAIL);
        // 设置收件人邮箱地址，即用户提供的邮箱地址
        simpleMailMessage.setTo(user.getEmail());
        // 设置邮件主题
        simpleMailMessage.setSubject("管理系统验证码");
        // 设置邮件正文，包含生成的验证码，并提醒用户不要转发
        simpleMailMessage.setText("邮箱验证码为：" + code + ",请勿转发给他人");
        // 尝试发送邮件
        try {
            // 使用javaMailSender发送邮件
            javaMailSender.send(simpleMailMessage);
            // 如果邮件发送成功，则返回成功的结果，包含验证码
            return Result.success(code);
            // 捕获并处理邮件发送过程中可能出现的异常
        } catch (Exception e) {
            // 如果邮件发送失败，则返回错误信息，提示验证码发送异常，并建议联系管理员
            return Result.error("-1", "验证码发送异常，请联系管理员。");
        }
    }

    @Override
    public Result sendPasswordResetCode(String email) {
        // 创建一个User对象
        User userWithEmail = new User();
        // 设置User对象的邮箱属性
        userWithEmail.setEmail(email);
        // 检查邮箱是否存在，通过邮箱查询User对象
        User emailUser = userDao.selectOne(new QueryWrapper<User>().eq("email", userWithEmail.getEmail()));
        // 如果查询结果为空，则返回错误信息，提示邮箱不存在
        if (emailUser == null) {
            return Result.error("-1", "邮箱不存在，请检查邮箱地址是否正确");
        }

        // 生成一个随机数对象
        Random random = new Random();
        // 生成一个六位数的随机验证码
        int code = random.nextInt(899999) + 100000;

        // 创建一个SimpleMailMessage对象，用于构建邮件消息
        SimpleMailMessage simpleMailMessage = new SimpleMailMessage();
        // 设置邮件的发件人地址
        simpleMailMessage.setFrom(FROM_EMAIL);
        // 设置邮件的收件人地址，即用户输入的邮箱地址
        simpleMailMessage.setTo(userWithEmail.getEmail());
        // 设置邮件的主题
        simpleMailMessage.setSubject("找回密码验证码");
        // 设置邮件的正文内容，包含验证码信息
        simpleMailMessage.setText("您的找回密码验证码为：" + code + "，有效期为5分钟，请勿泄露给他人。");

        // 尝试发送邮件
        try {
            // 使用javaMailSender发送邮件
            javaMailSender.send(simpleMailMessage);
            // 邮件发送成功，返回成功信息及验证码
            return Result.success(code);
        } catch (Exception e) {
            // 邮件发送过程中出现异常，返回错误信息，并提示联系管理员
            return Result.error("-1", "邮件发送异常，请联系管理员。");
        }
    }
}
```

##### 2.4.2实现提交新密码功能

在UserController中添加forgetPassword方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.User;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

//这里的RestController注解表示，该类下的所有方法都可以直接返回json数据(其实就是@Controller和@ResponseBody的组合)
@RestController
//这里的RequestMapping注解表示，该类下的所有方法都可以被映射到/user路径下
@RequestMapping("/user")
public class UserController {

    //注入UserService
    @Autowired
    private UserService userService;

    //这里的RequestMapping注解表示，该方法可以被映射到/login路径下
    @RequestMapping("/login")
    //@RequestBodys注解表示，该方法的入参是json格式的请求体
    public Result login(@RequestBody User user) {
        //调用service层处理登录逻辑
        Result login = userService.login(user);
        //返回结果
        return login;
    }

    /**
     * 注册用户
     * @param user
     * @return
     */
    @RequestMapping("/register")
    public Result createUser(@RequestBody User user) {
        return userService.createUser(user);
    }

    /**
     * 根据用户id添加/更新个人信息
     * @param id
     * @param user
     * @return
     */
    @RequestMapping("/{id}")
    public Result updateUser(@PathVariable Integer id, @RequestBody User user) {
        return userService.updateUser(id, user);
    }


    /**
     * 忘记密码功能
     * @param email
     * @param newPassword
     * @return
     */
    @RequestMapping("/forget")
    public Result forgetPassword(
            @RequestParam(defaultValue = "") String email,
            @RequestParam(defaultValue = "") String newPassword) {
        return userService.forgetPassword(email, newPassword);
    }

}
```

在UserService中添加forgetPassword抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.User;

public interface UserService extends IService<User> {

    Result login(User user);

    Result createUser(User user);

    Result updateUser(Integer id, User user);

    Result forgetPassword(String email, String newPassword);
}
```

在对应UserServiceImpl实现类中重写forgetPassword抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.MenuDao;
import com.qf.dao.UserDao;
import com.qf.entity.Menu;
import com.qf.entity.User;
import com.qf.enums.UserRole;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class UserServiceImpl extends ServiceImpl<UserDao, User> implements UserService {

    // 注入UserDao
    @Autowired
    private UserDao userDao;

    //注入MenuDao
    @Autowired
    private MenuDao menuDao;

    @Value("${user.defaultPassword}")
    private  String DEFAULT_PWD ;


    @Override
    public Result login(User user) {
        // 创建LambdaQueryWrapper对象，用于构建查询条件
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        // 设置查询条件，查询用户名等于传入用户对象的用户名

        //eq方法为"="方法的简化写法,User::getUsername为lambda表达式,作用是获取User表的字段名username
        queryWrapper.eq(User::getUsername, user.getUsername());
        // 根据查询条件从数据库中查询用户信息
        User loginUser = userDao.selectOne(queryWrapper);
        // 如果查询结果为空，返回错误信息，提示用户不存在
        if (loginUser == null) {
            return Result.error("-1", "登录失败，用户不存在！");
        }
        // 初始化UserRole对象，用于存储查询到的用户角色
        UserRole loginRole = null;
        // 获取用户的角色信息
        String role = loginUser.getRole();
        // 根据角色信息设置对应的UserRole对象
        if (role.equals(UserRole.USER.getValue())) {
            loginRole = UserRole.USER;
        } else if (role.equals(UserRole.ADMIN.getValue())) {
            loginRole = UserRole.ADMIN;
        } else if (role.equals(UserRole.SUPER_ADMIN.getValue())) {
            loginRole = UserRole.SUPER_ADMIN;
        } else {
            // 如果角色信息不匹配任何已知角色，返回错误信息，提示角色信息异常
            return Result.error("-1", "登陆失败，角色信息异常");
        }
        // 如果用户角色ID不等于3（3为SUPER_ADMIN）
        if (loginRole.getId() != 3) {
            // 根据角色ID和3查询菜单列表
            // 查询角色为 roleId 或3 的菜单列表
            List<Menu> roleMenuList = menuDao.selectList(
                    new LambdaQueryWrapper<Menu>()
                            //in 方法用于查询 Menu 表中 role 字段的值等于 loginRole.getId() 或者 3 的所有记录
                            .in(Menu::getRole, Arrays.asList(loginRole.getId(), 3))
            );
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            // 作用:筛选集合中父菜单 ID（pid）为空的菜单作为一级父菜单,并转换为集合
            //stream() 方法用于将集合转换为流，filter 方法用于过滤集合，toList() 方法用于将流转换为集合
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                //collect是收集器
                //Collectors.toList()是转换器
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        } else {
            // 如果用户角色ID等于3，查询所有菜单列表
            // 查询所有菜单列表
            List<Menu> roleMenuList = menuDao.selectList(null);
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        }

        // 验证用户密码是否匹配
        // 如果传入的用户密码与数据库中查询到的用户密码匹配
        if (user.getPassword().equals(loginUser.getPassword())) {
            // 返回成功信息，包含用户对象
            return Result.success(loginUser);
        } else {
            // 返回错误信息，提示用户名或密码错误
            return Result.error("-1", "登录失败，用户名或密码错误！");
        }
    }

    @Override
    public Result createUser(User user) {
        // 检查用户名是否已存在
        Long checkUsername = userDao.selectCount(new LambdaQueryWrapper<User>().eq(User::getUsername, user.getUsername()));

        if (checkUsername >0) {
            // 如果用户名已存在，返回错误信息
            return Result.error("-1", "注册失败，用户名已存在");
        }
        Long checkEmail = userDao.selectCount(new LambdaQueryWrapper<User>().eq(User::getEmail, user.getEmail()));
        if (checkEmail>0) {
            // 如果邮箱已存在，返回错误信息
            return Result.error("-1", "注册失败，邮箱已存在");
        }
        // 检查用户密码是否为空或仅由空白字符组成，如果为空则设置默认密码
        if(!StringUtils.isNotBlank(user.getPassword())){
            user.setPassword(DEFAULT_PWD);
        }
        // 检查用户角色是否为空或仅由空白字符组成，如果为空则设置默认角色为普通用户
        if(!StringUtils.isNotBlank(user.getRole())){
            user.setRole(UserRole.USER.getValue());
        }else{
            // 如果用户角色不为空，检查角色是否为有效的预设角色（管理员、普通用户、超级管理员）
            if (!Arrays.asList(UserRole.ADMIN.getValue(), UserRole.USER.getValue(), UserRole.SUPER_ADMIN.getValue()).contains(user.getRole())) {
                // 如果角色无效，返回错误信息
                return Result.error("-1", "无效的角色");
            }
        }
        // 保存用户信息到数据库
        // insert方法用于插入一条记录，返回受影响的行数
        int res = userDao.insert(user);
        // 如果受影响的行数大于0，返回成功信息，包含用户对象
        if (res > 0) {
            return Result.success(user);
        } else {
            // 如果受影响的行数等于0，返回错误信息
            return Result.error("-1", "注册失败");
        }
    }

    @Override
    public Result updateUser(Integer id, User user) {

        //设置id
        user.setId(id);
        //根据id更新用户信息
        int res = userDao.updateById(user);
        if (res > 0) {
            //返回成功信息，包含用户对象
            return Result.success(user);
        } else {
            return Result.error("-1", "更新失败");
        }
    }

    @Override
    public Result forgetPassword(String email, String newPassword) {
        // 创建一个新的User对象
        User user = new User();
        // 如果邮箱不为空或不为null，则将邮箱设置到user对象中
        if(StringUtils.isNotBlank(email)) {
            user.setEmail(email);
        }
        // 根据邮箱查询用户列表
        List<User> userList = userDao.selectList(new QueryWrapper<User>().eq("email", user.getEmail()));
        // 如果用户列表为空或为null，返回错误信息，提示该邮箱不存在
        if(userList==null|| userList.isEmpty()){
            return Result.error("-1","该邮箱不存在");
        }else{
            // 获取用户列表中的第一个用户对象
            User oldUser =userList.get(0);
            // 如果新密码不为空或不为null，则将新密码设置到oldUser对象中
            if(StringUtils.isNotBlank(newPassword)) {
                oldUser.setPassword(newPassword);
                // 根据id更新用户信息
                int res = userDao.updateById(oldUser);
                // 如果更新成功，返回成功信息
                if (res > 0) {
                    return Result.success();
                } else {
                    // 如果更新失败，返回错误信息，提示更新失败并联系管理员
                    return Result.error("-1", "更新失败,请联系管理员");
                }
            }else{
                // 如果新密码为空或为null，返回错误信息，提示更新异常并联系管理员
                return Result.error("-1", "更新异常,请联系管理员");
            }
        }
    }
}
```

## 十. 实现个人中心功能

### 1 实现密码修改功能

创建对应UserPasswordUpdate实体类

```
package com.qf.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class UserPasswordUpdate {
    // 旧密码
    private String oldPassword;
    // 新密码
    private String newPassword;
}
```

在UserController中添加updatePassword方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.User;
import com.qf.entity.UserPasswordUpdate;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

//这里的RestController注解表示，该类下的所有方法都可以直接返回json数据(其实就是@Controller和@ResponseBody的组合)
@RestController
//这里的RequestMapping注解表示，该类下的所有方法都可以被映射到/user路径下
@RequestMapping("/user")
public class UserController {

    //注入UserService
    @Autowired
    private UserService userService;

    //这里的RequestMapping注解表示，该方法可以被映射到/login路径下
    @RequestMapping("/login")
    //@RequestBodys注解表示，该方法的入参是json格式的请求体
    public Result login(@RequestBody User user) {
        //调用service层处理登录逻辑
        Result login = userService.login(user);
        //返回结果
        return login;
    }

    /**
     * 注册用户
     * @param user
     * @return
     */
    @RequestMapping("/register")
    public Result createUser(@RequestBody User user) {
        return userService.createUser(user);
    }

    /**
     * 根据用户id添加/更新个人信息
     * @param id
     * @param user
     * @return
     */
    @RequestMapping("/{id}")
    public Result updateUser(@PathVariable Integer id, @RequestBody User user) {
        return userService.updateUser(id, user);
    }


    /**
     * 忘记密码功能
     * @param email
     * @param newPassword
     * @return
     */
    @RequestMapping("/forget")
    public Result forgetPassword(
            @RequestParam(defaultValue = "") String email,
            @RequestParam(defaultValue = "") String newPassword) {
        return userService.forgetPassword(email, newPassword);
    }

    @RequestMapping("/password/{id}")
    public Result updatePassword(
            @PathVariable Integer id,
            @RequestBody UserPasswordUpdate userPasswordUpdate) {
        return userService.updatePassword(id, userPasswordUpdate);
    }
}
```

在UserService中添加updatePassword抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.User;
import com.qf.entity.UserPasswordUpdate;

public interface UserService extends IService<User> {

    Result login(User user);

    Result createUser(User user);

    Result updateUser(Integer id, User user);

    Result forgetPassword(String email, String newPassword);

    Result updatePassword(Integer id, UserPasswordUpdate userPasswordUpdate);
}
```

在对应UserServiceImpl实现类中重写updatePassword抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.MenuDao;
import com.qf.dao.UserDao;
import com.qf.entity.Menu;
import com.qf.entity.User;
import com.qf.entity.UserPasswordUpdate;
import com.qf.enums.UserRole;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class UserServiceImpl extends ServiceImpl<UserDao, User> implements UserService {

    // 注入UserDao
    @Autowired
    private UserDao userDao;

    //注入MenuDao
    @Autowired
    private MenuDao menuDao;

    @Value("${user.defaultPassword}")
    private String DEFAULT_PWD;


    @Override
    public Result login(User user) {
        // 创建LambdaQueryWrapper对象，用于构建查询条件
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        // 设置查询条件，查询用户名等于传入用户对象的用户名

        //eq方法为"="方法的简化写法,User::getUsername为lambda表达式,作用是获取User表的字段名username
        queryWrapper.eq(User::getUsername, user.getUsername());
        // 根据查询条件从数据库中查询用户信息
        User loginUser = userDao.selectOne(queryWrapper);
        // 如果查询结果为空，返回错误信息，提示用户不存在
        if (loginUser == null) {
            return Result.error("-1", "登录失败，用户不存在！");
        }
        // 初始化UserRole对象，用于存储查询到的用户角色
        UserRole loginRole = null;
        // 获取用户的角色信息
        String role = loginUser.getRole();
        // 根据角色信息设置对应的UserRole对象
        if (role.equals(UserRole.USER.getValue())) {
            loginRole = UserRole.USER;
        } else if (role.equals(UserRole.ADMIN.getValue())) {
            loginRole = UserRole.ADMIN;
        } else if (role.equals(UserRole.SUPER_ADMIN.getValue())) {
            loginRole = UserRole.SUPER_ADMIN;
        } else {
            // 如果角色信息不匹配任何已知角色，返回错误信息，提示角色信息异常
            return Result.error("-1", "登陆失败，角色信息异常");
        }
        // 如果用户角色ID不等于3（3为SUPER_ADMIN）
        if (loginRole.getId() != 3) {
            // 根据角色ID和3查询菜单列表
            // 查询角色为 roleId 或3 的菜单列表
            List<Menu> roleMenuList = menuDao.selectList(
                    new LambdaQueryWrapper<Menu>()
                            //in 方法用于查询 Menu 表中 role 字段的值等于 loginRole.getId() 或者 3 的所有记录
                            .in(Menu::getRole, Arrays.asList(loginRole.getId(), 3))
            );
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            // 作用:筛选集合中父菜单 ID（pid）为空的菜单作为一级父菜单,并转换为集合
            //stream() 方法用于将集合转换为流，filter 方法用于过滤集合，toList() 方法用于将流转换为集合
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                //collect是收集器
                //Collectors.toList()是转换器
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        } else {
            // 如果用户角色ID等于3，查询所有菜单列表
            // 查询所有菜单列表
            List<Menu> roleMenuList = menuDao.selectList(null);
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        }

        // 验证用户密码是否匹配
        // 如果传入的用户密码与数据库中查询到的用户密码匹配
        if (user.getPassword().equals(loginUser.getPassword())) {
            // 返回成功信息，包含用户对象
            return Result.success(loginUser);
        } else {
            // 返回错误信息，提示用户名或密码错误
            return Result.error("-1", "登录失败，用户名或密码错误！");
        }
    }

    @Override
    public Result createUser(User user) {
        // 检查用户名是否已存在
        Long checkUsername = userDao.selectCount(new LambdaQueryWrapper<User>().eq(User::getUsername, user.getUsername()));

        if (checkUsername > 0) {
            // 如果用户名已存在，返回错误信息
            return Result.error("-1", "注册失败，用户名已存在");
        }
        Long checkEmail = userDao.selectCount(new LambdaQueryWrapper<User>().eq(User::getEmail, user.getEmail()));
        if (checkEmail > 0) {
            // 如果邮箱已存在，返回错误信息
            return Result.error("-1", "注册失败，邮箱已存在");
        }
        // 检查用户密码是否为空或仅由空白字符组成，如果为空则设置默认密码
        if (!StringUtils.isNotBlank(user.getPassword())) {
            user.setPassword(DEFAULT_PWD);
        }
        // 检查用户角色是否为空或仅由空白字符组成，如果为空则设置默认角色为普通用户
        if (!StringUtils.isNotBlank(user.getRole())) {
            user.setRole(UserRole.USER.getValue());
        } else {
            // 如果用户角色不为空，检查角色是否为有效的预设角色（管理员、普通用户、超级管理员）
            if (!Arrays.asList(UserRole.ADMIN.getValue(), UserRole.USER.getValue(), UserRole.SUPER_ADMIN.getValue()).contains(user.getRole())) {
                // 如果角色无效，返回错误信息
                return Result.error("-1", "无效的角色");
            }
        }
        // 保存用户信息到数据库
        // insert方法用于插入一条记录，返回受影响的行数
        int res = userDao.insert(user);
        // 如果受影响的行数大于0，返回成功信息，包含用户对象
        if (res > 0) {
            return Result.success(user);
        } else {
            // 如果受影响的行数等于0，返回错误信息
            return Result.error("-1", "注册失败");
        }
    }

    @Override
    public Result updateUser(Integer id, User user) {

        //设置id
        user.setId(id);
        //根据id更新用户信息
        int res = userDao.updateById(user);
        if (res > 0) {
            //返回成功信息，包含用户对象
            return Result.success(user);
        } else {
            return Result.error("-1", "更新失败");
        }
    }

    @Override
    public Result forgetPassword(String email, String newPassword) {
        // 创建一个新的User对象
        User user = new User();
        // 如果邮箱不为空或不为null，则将邮箱设置到user对象中
        if (StringUtils.isNotBlank(email)) {
            user.setEmail(email);
        }
        // 根据邮箱查询用户列表
        List<User> userList = userDao.selectList(new QueryWrapper<User>().eq("email", user.getEmail()));
        // 如果用户列表为空或为null，返回错误信息，提示该邮箱不存在
        if (userList == null || userList.isEmpty()) {
            return Result.error("-1", "该邮箱不存在");
        } else {
            // 获取用户列表中的第一个用户对象
            User oldUser = userList.get(0);
            // 如果新密码不为空或不为null，则将新密码设置到oldUser对象中
            if (StringUtils.isNotBlank(newPassword)) {
                oldUser.setPassword(newPassword);
                // 根据id更新用户信息
                int res = userDao.updateById(oldUser);
                // 如果更新成功，返回成功信息
                if (res > 0) {
                    return Result.success();
                } else {
                    // 如果更新失败，返回错误信息，提示更新失败并联系管理员
                    return Result.error("-1", "更新失败,请联系管理员");
                }
            } else {
                // 如果新密码为空或为null，返回错误信息，提示更新异常并联系管理员
                return Result.error("-1", "更新异常,请联系管理员");
            }

        }
    }

    @Override
    public Result updatePassword(Integer id, UserPasswordUpdate userPasswordUpdate) {
        // 根据ID查询用户信息
        User oldUser = userDao.selectById(id);
        // 如果用户不存在，返回错误信息
        if (oldUser == null) {
            return Result.error("-1", "用户不存在");
        // 否则，继续验证旧密码
        } else {
            // 检查提供的旧密码是否与数据库中存储的密码匹配
            if (userPasswordUpdate.getOldPassword().equals(oldUser.getPassword())) {
                // 如果旧密码匹配，更新用户的密码为新密码
                oldUser.setPassword(userPasswordUpdate.getNewPassword());
                // 更新用户信息到数据库
                int res = userDao.updateById(oldUser);
                // 如果更新成功，返回成功信息
                if (res > 0) {
                    return Result.success();
                    // 如果更新失败，返回错误信息并提示联系管理员
                } else {
                    return Result.error("-1", "修改失败,请联系管理员");
                }
                // 如果旧密码不匹配，返回错误信息并提示重试
            } else {
                return Result.error("-1", "旧密码错误,请重试！");
            }
        }

    }
}
```

## 十一. 实现宠物中心功能

### 1 实现宠物管理功能

#### 1.1查询所有宠物列表数据功能

创建对应宠物模块实体类animal

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;

//使用lombok插件生成对应get,set方法
@Data
//生成无参构造方法
@NoArgsConstructor
//生成有参构造方法
@AllArgsConstructor
@TableName("animal")
public class Animal {

    @TableId(type = IdType.AUTO)
    /** 自增主键 */
    private Integer id;

    /** 宠物头像 */
    private String img;

    /** 宠物昵称 */
    private String name;

    /** 宠物性别 */
    private String sex;

    /** 宠物年龄 */
    private Integer age;

    /** 宠物种类 */
    private String type;

    /** 宠物状态 */
    private String status;

    /** 注册日期 */
    private LocalDate registrationDate;

    /** 行为特征 */
    private String behaviorTraits;

    /** 绝育状况 */
    private String sterilizationStatus;

    /** 颜色 */
    private String color;

    /** 训练状况 */
    private String trainingLevel;

    /** 特殊要求 */
    private String specialNeeds;

    /** 描述信息 */
    private String descr;

    /** 宠物品种 */
    private String breed;
}
```

创建对应控制层AnimalController,并添加处理查询分页功能selectPage方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.service.AnimalService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

// @RestController注解表示该类是一个控制器类，其实是@Controller和@ResponseBody的组合注解
@RestController
// 设置该控制器处理的请求的基本路径为"/animal"
@RequestMapping("/animal")
public class AnimalController {

    // 注入AnimalService实例，用于调用动物相关的服务方法
    @Autowired
    private AnimalService animalService;

    // 定义一个处理分页查询请求的方法，路径为"/animal/page"
    @RequestMapping("/page")
    // 处理分页查询请求的方法，接收四个参数：动物名称、动物类型、当前页码和每页大小
    public Result selectPage(
            // 动物名称，默认值为空字符串
            @RequestParam(defaultValue = "") String name,
            // 动物类型，默认值为空字符串
            @RequestParam(defaultValue = "") String type,
            // 当前页码，默认值为1
            @RequestParam(defaultValue = "1") Integer currentPage,
            // 每页显示的记录数，默认值为10
            @RequestParam(defaultValue = "10") Integer size) {
        // 调用animalService的selectPage方法，并返回查询结果
        return animalService.selectPage(name, type, currentPage, size);
    }
}
```

创建对应服务层AnimalService接口

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Animal;

public interface AnimalService extends IService<Animal> {
    Result selectPage(String name, String type, Integer currentPage, Integer size);
}
```

创建对应实现类AnimalServiceImpl并重写selectPage抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.AnimalDao;
import com.qf.entity.Animal;
import com.qf.service.AnimalService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class AnimalServiceImpl extends ServiceImpl<AnimalDao, Animal> implements AnimalService {

    //注入AnimalDao
    @Autowired
    private AnimalDao animalDao;

    @Override
    // 定义一个方法，接收名称、类型、当前页码和每页显示数量作为参数，并返回查询结果
    public Result selectPage(String name, String type, Integer currentPage, Integer size) {
        // 创建LambdaQueryWrapper实例，用于构建查询条件
        LambdaQueryWrapper<Animal> wrapper = new LambdaQueryWrapper<>();
        // 如果名称不为空，则添加名称的模糊查询条件
        wrapper.like(StringUtils.isNotBlank(name), Animal::getName, name)
                // 如果类型不为空，则添加类型的模糊查询条件
                .like(StringUtils.isNotBlank(type), Animal::getType, type)
                // 按照ID降序排列查询结果
                .orderByDesc(Animal::getId);
        // 使用animalDao执行分页查询，并将结果存储在page对象中
        //Page对象用于分页查询，包含当前页码、每页显示数量、总记录数、查询结果,mybatis-plus会自动进行分页处理
        Page<Animal> page = animalDao.selectPage(new Page<>(currentPage, size), wrapper);
        // 返回查询成功的结果，包含分页信息
        return Result.success(page);
    }
}
```

创建数据库访问层AnimalDao接口

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.Animal;

public interface AnimalDao extends BaseMapper<Animal> {
}
```

注:图片问题解决方法

将img文件夹中的资源拷贝进此项目中

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763952423956-5c5ff96e-3a3c-41f5-86eb-57746637ff84.png)

#### 1.2实现批量删除宠物功能

在AnimalController中添加deleteBatch方法用于批量删除

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.service.AnimalService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

// @RestController注解表示该类是一个控制器类，其实是@Controller和@ResponseBody的组合注解
@RestController
// 设置该控制器处理的请求的基本路径为"/animal"
@RequestMapping("/animal")
public class AnimalController {

    // 注入AnimalService实例，用于调用动物相关的服务方法
    @Autowired
    private AnimalService animalService;

    /**
     * 查询分页动物列表功能
     * @param name
     * @param type
     * @return
     */
    // 定义一个处理分页查询请求的方法，路径为"/animal/page"
    @RequestMapping("/page")
    // 处理分页查询请求的方法，接收四个参数：动物名称、动物类型、当前页码和每页大小
    public Result selectPage(
            // 动物名称，默认值为空字符串
            @RequestParam(defaultValue = "") String name,
            // 动物类型，默认值为空字符串
            @RequestParam(defaultValue = "") String type,
            // 当前页码，默认值为1
            @RequestParam(defaultValue = "1") Integer currentPage,
            // 每页显示的记录数，默认值为10
            @RequestParam(defaultValue = "10") Integer size) {
        // 调用animalService的selectPage方法，并返回查询结果
        return animalService.selectPage(name, type, currentPage, size);
    }

    /**
     * 根据id批量删除动物功能
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        // 调用animalService的removeBatchByIds方法，并返回删除结果
        boolean res = animalService.removeBatchByIds(ids);
        // 根据删除结果返回不同的响应
        if (res) {
            // 成功删除
            return Result.success();
        } else {
            // 删除失败
            return Result.error("-1", "删除失败");
        }
    }
}
```

#### 1.3实现添加宠物功能

当点击添加时,首先下拉框会查询对应的宠物种类,所以先处理这个请求

##### 1.3.1查询宠物品种功能

创建对应宠物品种实体类Breed

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("breed")
public class Breed {

    /**
     * 品种id
     */
    @TableId(type = IdType.AUTO)
    private  Integer breedId;
    /**
     * 品种名称
     */
    private String breedName;
}
```

创建宠物品种对应的控制层BreedController

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Breed;
import com.qf.service.BreedService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RequestMapping("/breed")
@RestController
public class BreedController {

    // 自动注入BreedService接口
    @Autowired
    private BreedService breedService;

    @RequestMapping("/selectAll")
    // 定义一个公共方法，用于获取所有品种信息
    public Result selectAll() {
        // 调用IService接口的list方法，获取所有品种的列表
        List<Breed> breeds = breedService.list();
        // 如果breeds列表不为空，则返回成功的Result对象，包含breeds列表；否则返回错误的Result对象
        return breeds != null ? Result.success(breeds) : Result.error("-1", "查找失败");
    }
}
```

创建对应服务层BreedService

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.entity.Breed;

public interface BreedService extends IService<Breed> {
}
```

创建对应实现类BreedServiceImpl

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.dao.BreedDao;
import com.qf.entity.Breed;
import com.qf.service.BreedService;
import org.springframework.stereotype.Service;

@Service
public class BreedServiceImpl extends ServiceImpl<BreedDao, Breed> implements BreedService {
}
```

创建对应数据库访问层BreedDao

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.Breed;

public interface BreedDao extends BaseMapper<Breed> {
}
```

##### 1.3.2添加宠物功能

在AnimalController中添加save方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Animal;
import com.qf.service.AnimalService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

// @RestController注解表示该类是一个控制器类，其实是@Controller和@ResponseBody的组合注解
@RestController
// 设置该控制器处理的请求的基本路径为"/animal"
@RequestMapping("/animal")
public class AnimalController {

    // 注入AnimalService实例，用于调用动物相关的服务方法
    @Autowired
    private AnimalService animalService;

    /**
     * 查询分页动物列表功能
     * @param name
     * @param type
     * @return
     */
    // 定义一个处理分页查询请求的方法，路径为"/animal/page"
    @RequestMapping("/page")
    // 处理分页查询请求的方法，接收四个参数：动物名称、动物类型、当前页码和每页大小
    public Result selectPage(
            // 动物名称，默认值为空字符串
            @RequestParam(defaultValue = "") String name,
            // 动物类型，默认值为空字符串
            @RequestParam(defaultValue = "") String type,
            // 当前页码，默认值为1
            @RequestParam(defaultValue = "1") Integer currentPage,
            // 每页显示的记录数，默认值为10
            @RequestParam(defaultValue = "10") Integer size) {
        // 调用animalService的selectPage方法，并返回查询结果
        return animalService.selectPage(name, type, currentPage, size);
    }

    /**
     * 根据id批量删除动物功能
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        // 调用animalService的removeBatchByIds方法，并返回删除结果
        boolean res = animalService.removeBatchByIds(ids);
        // 根据删除结果返回不同的响应
        if (res) {
            // 成功删除
            return Result.success();
        } else {
            // 删除失败
            return Result.error("-1", "删除失败");
        }
    }

  /**
     * 新增动物功能
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Animal animal) {
        // 调用animalService的save方法，保存新增的动物信息
        animalService.save(animal);
        // 返回成功响应
        return Result.success();
    }
}
```

#### 1.4编辑宠物功能

在AnimalController中添加updateAnimal方法用于更新数据

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Animal;
import com.qf.service.AnimalService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

// @RestController注解表示该类是一个控制器类，其实是@Controller和@ResponseBody的组合注解
@RestController
// 设置该控制器处理的请求的基本路径为"/animal"
@RequestMapping("/animal")
public class AnimalController {

    // 注入AnimalService实例，用于调用动物相关的服务方法
    @Autowired
    private AnimalService animalService;

    /**
     * 查询分页动物列表功能
     * @param name
     * @param type
     * @return
     */
    // 定义一个处理分页查询请求的方法，路径为"/animal/page"
    @RequestMapping("/page")
    // 处理分页查询请求的方法，接收四个参数：动物名称、动物类型、当前页码和每页大小
    public Result selectPage(
            // 动物名称，默认值为空字符串
            @RequestParam(defaultValue = "") String name,
            // 动物类型，默认值为空字符串
            @RequestParam(defaultValue = "") String type,
            // 当前页码，默认值为1
            @RequestParam(defaultValue = "1") Integer currentPage,
            // 每页显示的记录数，默认值为10
            @RequestParam(defaultValue = "10") Integer size) {
        // 调用animalService的selectPage方法，并返回查询结果
        return animalService.selectPage(name, type, currentPage, size);
    }

    /**
     * 根据id批量删除动物功能
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        // 调用animalService的removeBatchByIds方法，并返回删除结果
        boolean res = animalService.removeBatchByIds(ids);
        // 根据删除结果返回不同的响应
        if (res) {
            // 成功删除
            return Result.success();
        } else {
            // 删除失败
            return Result.error("-1", "删除失败");
        }
    }

    /**
     * 新增动物功能
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Animal animal) {
        // 调用animalService的save方法，保存新增的动物信息
        animalService.save(animal);
        // 返回成功响应
        return Result.success();
    }


    @PutMapping("/update/{id}")
    public Result updateAnimal(@PathVariable Integer id, @RequestBody Animal animal) {
        // 确保更新时使用正确的ID
        animal.setId(id);
        // 调用animalService的updateById方法，更新动物信息
        boolean res = animalService.updateById(animal);
        if (res) {
            return Result.success(animal);
        } else {
            return Result.error("-1", "更新失败");
        }
    }
}
```

### 2 实现领养管理功能

#### 2.1查询领养列表数据

创建对应实体类Adopt

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("adopt")
public class Adopt {

    /**
     * 主键id
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 用户id
     */
    private Integer userId;

    /**
     * 宠物id
     */
    private Integer animalId;

    /**
     * 领养时间
     */
    private String time;

    /**
     * 领养状态
     */
    private String status;

    /**
     * 审核意见
     */
    private String reviewComment;

    /**
     * 审核人ID
     */
    private Integer reviewerId;

    /**
     * 审核时间
     */
    private String reviewTime;
}
```

创建VO包,并创建用于返回前端的领养信息视图对象 AdoptVO

```
package com.qf.vo;

import com.baomidou.mybatisplus.annotation.TableField;
import com.qf.entity.Adopt;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;

//@EqualsAndHashCode(callSuper = false)是生成hashCode和equals方法的注解，callSuper = false表示不调用父类的equals方法。
@EqualsAndHashCode(callSuper = false)
//Data注解是lombok提供的注解，它会生成get、set方法。
@Data
//NoArgsConstructor注解是lombok提供的注解，它会生成无参构造器。
@NoArgsConstructor
//AllArgsConstructor注解是lombok提供的注解，它会生成全参构造器。
@AllArgsConstructor
//AdoptVO类继承自Adopt类，并添加了userName、animalImg、animalName三个属性。
public class AdoptVO extends Adopt {

    /**
     * 用户表外键
     * 对应的是user表的id字段
     */
    @TableField(exist = false)
    private String userName;

    /**
     * 宠物表外键
     * 对应的是animal表的img字段
     */
    @TableField(exist = false)
    private String animalImg;

    /**
     * 宠物表外键
     * 对应的是animal表的name字段
     */
    @TableField(exist = false)
    private String animalName;

}
```

创建对应控制层AdoptController

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.service.AdoptService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/adopt")
public class AdoptController {

    // 自动注入AdoptService
    @Autowired
    private AdoptService adoptService;

    @GetMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {

        // 调用AdoptService的selectPage方法
        return adoptService.selectPage(name, currentPage, size);
    }
}
```

创建对应服务层AdoptService接口,并添加selectPage抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Adopt;

public interface AdoptService extends IService<Adopt> {
    Result selectPage(String name, Integer currentPage, Integer size);
}
```

创建对应实现类AdoptServiceImpl,并重写selectPage抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.AdoptDao;
import com.qf.entity.Adopt;
import com.qf.vo.AdoptVO;
import com.qf.service.AdoptService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class AdoptServiceImpl extends ServiceImpl<AdoptDao, Adopt> implements AdoptService {

    // 注入AdoptDao
    @Autowired
    private AdoptDao adoptDao;

    @Override
    public Result selectPage(String name, Integer currentPage, Integer size) {
        // 创建Page对象,设置当前页和每页显示的数量
        Page<AdoptVO> page = new Page<>(currentPage, size);
        // 调用AdoptDao的selectByPage方法,传入name和Page对象,返回Page对象
        Page<AdoptVO> adoptPage = adoptDao.selectByPage(name, page);
        // 返回封装了Page对象和数据的Result对象
        return Result.success(adoptPage);
    }
}
```

创建对应数据访问层AdoptDao,并添加selectByPage抽象方法

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.qf.entity.Adopt;
import com.qf.vo.AdoptVO;
import org.apache.ibatis.annotations.Param;

public interface AdoptDao extends BaseMapper<Adopt> {
    //@Param注解用于给参数取别名，在xml中使用时，需要使用别名来引用参数
    Page<AdoptVO> selectByPage(@Param("name") String name, Page<AdoptVO> page);
}
```

在resources文件夹下创建mapper文件夹

**注意:通过配置文件扫描了mapper文件夹,不要乱修改名字**

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763985857218-6897ed88-9241-4370-9fe1-ce1c2547f0f3.png)

![](https://cdn.nlark.com/yuque/0/2025/png/40865112/1763985880810-ede484e2-37de-4da9-9dd7-4354620a44b4.png)

在mapper文件夹下创建对应的AdoptDao.xml文件

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.qf.dao.AdoptDao">

    <!-- 定义名为AdoptResultMap的结果映射，映射到com.qf.vo.AdoptVO类型 -->
    <resultMap id="AdoptResultMap" type="com.qf.vo.AdoptVO">
        <!-- 映射id字段，对应数据库中的id列 -->
        <id property="id" column="id"/>
        <!-- 映射userName字段，对应数据库中的userName列 -->
        <result property="userName" column="userName"/>
        <!-- 映射animalImg字段，对应数据库中的animalImg列 -->
        <result property="animalImg" column="animalImg"/>
        <!-- 映射animalName字段，对应数据库中的animalName列 -->
        <result property="animalName" column="animalName"/>
    </resultMap>


    <!-- 定义名为selectByPage的查询语句，使用AdoptResultMap作为结果映射 -->
    <select id="selectByPage" resultMap="AdoptResultMap">
        <!-- 选择所有列，并从user表中选择name列作为userName，从animal表中选择img列作为animalImg，从animal表中选择name列作为animalName -->
        SELECT a.*, u.name AS userName, an.img AS animalImg, an.name AS animalName
        <!-- 从adopt表中选择数据 -->
        FROM adopt a
        <!-- 左连接user表，条件是adopt表的user_id等于user表的id -->
        LEFT JOIN user u ON a.user_id = u.id
        <!-- 左连接animal表，条件是adopt表的animal_id等于animal表的id -->
        LEFT JOIN animal an ON a.animal_id = an.id
        <!-- 动态条件过滤 -->
        <where>
            <!-- 如果name不为空且不为空字符串，则添加模糊查询条件 -->
            <!-- CONCAT函数用于拼接字符串 -->
            <if test="name != null and name != ''">
                AND an.name LIKE CONCAT('%', #{name}, '%')
            </if>

        </where>

    </select>


</mapper>
```

#### 2.2批量删除领养信息功能

在AdoptController中添加deleteBatch方法,用于根据id批量进行删除

```
package com.qf.controller;


import com.qf.utils.Result;
import com.qf.service.AdoptService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/adopt")
public class AdoptController {

    // 自动注入AdoptService
    @Autowired
    private AdoptService adoptService;

    /**
     * 分页查询宠物领养信息
     *
     * @param name
     * @param currentPage
     * @param size
     * @return
     */
    @GetMapping("/selectPage")
    public Result selectPage(
        @RequestParam(defaultValue = "") String name,
        @RequestParam(defaultValue = "1") Integer currentPage,
        @RequestParam(defaultValue = "10") Integer size) {

        // 调用AdoptService的selectPage方法
        return adoptService.selectPage(name, currentPage, size);
    }

    /**
     * 批量删除宠物领养信息
     *
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return adoptService.deleteBatch(ids);
    }
}
```

在对应服务层AdoptService中添加deleteBatch抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Adopt;

import java.util.List;

public interface AdoptService extends IService<Adopt> {
    Result selectPage(String name, Integer currentPage, Integer size);

    Result deleteBatch(List<Integer> ids);
}
```

在对应实现类AdoptServiceImpl中重写deleteBatch抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.AdoptDao;
import com.qf.entity.Adopt;
import com.qf.vo.AdoptVO;
import com.qf.service.AdoptService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class AdoptServiceImpl extends ServiceImpl<AdoptDao, Adopt> implements AdoptService {

    // 注入AdoptDao
    @Autowired
    private AdoptDao adoptDao;

    @Override
    public Result selectPage(String name, Integer currentPage, Integer size) {
        // 创建Page对象,设置当前页和每页显示的数量
        Page<AdoptVO> page = new Page<>(currentPage, size);
        // 调用AdoptDao的selectByPage方法,传入name和Page对象,返回Page对象
        Page<AdoptVO> adoptPage = adoptDao.selectByPage(name, page);
        // 返回封装了Page对象和数据的Result对象
        return Result.success(adoptPage);
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        // 调用AdoptDao的deleteBatchIds方法,传入ids列表,返回成功删除的数量
        int success = adoptDao.deleteBatchIds(ids);
        // 判断成功删除的数量和ids列表的大小是否一致,如果一致,返回成功消息,否则返回部分删除失败的消息
        //.size()方法获取ids列表的大小
        if (success == ids.size()) {
            // 全部删除成功
            return Result.success();
        } else {
            // 部分删除失败
            return Result.error("-1", "部分删除失败");
        }
    }
}
```

#### 2.3实现编辑领养信息功能

管理员可以通过修改领养记录的状态来审核领养申请。当领养状态改为"已归还"时，系统自动将对应宠物的状态恢复为"待领养"，确保宠物可以重新被申请领养。

在enums文件夹下创建AnimalEnum枚举类

```
package com.qf.enums;

public enum AnimalEnum {
    ADOPTING("领养中"),
    NO_ADOPT("待领养"),
    ADOPT_CANCEL("放弃领养");

    private String info;
    AnimalEnum(String info) {
        this.info = info;
    }

    public String getInfo() {
        return info;
    }
}
```

在AdoptController中添加updateAdopt方法

```
package com.qf.controller;

import com.qf.entity.Adopt;
import com.qf.service.AdoptService;
import com.qf.utils.Result;
import com.qf.vo.AdoptVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/adopt")
public class AdoptController {

    //注入AdoptService
    @Autowired
    private AdoptService adoptService;


    //查询列表数据功能
    @GetMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size){

        //调用对应的service层进行业务处理
        return adoptService.selectPage(name,currentPage,size);

    }

    //批量删除功能
    @DeleteMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids){
        //直接调用service层进行根据id批量删除数据
        boolean b = adoptService.removeBatchByIds(ids);
        //判断是否删除成功
        if (b){
            return Result.success();
        }
        return Result.error("-1","删除失败");
    }


    /**
     * 更新领养信息（管理员审核或修改状态）
     * @param adopt 包含id和新状态的领养对象
     * @return 更新结果
     */
    @RequestMapping("/update")
    public Result updateAdopt(@RequestBody AdoptVO adopt) {
        return adoptService.updateAdopt(adopt);
    }
}
```

在对应服务层AdoptService中添加updateAdopt抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.entity.Adopt;
import com.qf.utils.Result;
import com.qf.vo.AdoptVO;

public interface AdoptService extends IService<Adopt> {
    Result selectPage(String name, Integer currentPage, Integer size);

    Result updateAdopt(AdoptVO adopt);
}
```

在AdoptServiceImpl中重写updateAdopt抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.dao.AdoptDao;
import com.qf.dao.AnimalDao;
import com.qf.entity.Adopt;
import com.qf.entity.Animal;
import com.qf.enums.AnimalEnum;
import com.qf.service.AdoptService;
import com.qf.utils.Result;
import com.qf.vo.AdoptVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class AdoptServiceImpl extends ServiceImpl<AdoptDao, Adopt> implements AdoptService {

    //注入dao层
    @Autowired
    private AdoptDao adoptDao;

    @Autowired
    private AnimalDao animalDao;


    @Override
    public Result selectPage(String name, Integer currentPage, Integer size) {
        //创建Page对象,他其实就是分页插件
        Page<AdoptVO> page = new Page<>(currentPage, size);

        //调用dao层查询列表数据
        Page<AdoptVO> adoptVOPage = adoptDao.selectByPage(name,page);

        //返回数据
        return Result.success(adoptVOPage);
    }

    @Override
    public Result updateAdopt(AdoptVO adopt) {
        // 如果领养状态改为放弃领养,需要更新宠物状态
        if (AnimalEnum.ADOPT_CANCEL.getInfo().equals(adopt.getStatus())){
            //放弃领养我们需要将状态改为待领养
            Animal animal = animalDao.selectById(adopt.getAnimalId());
            animal.setStatus(AnimalEnum.NO_ADOPT.getInfo());
            //通过dao层更新数据
            animalDao.updateById(animal);
        }
        // 如果传了 animalName，同步更新 animal 表的 name
        if (adopt.getAnimalName() != null && !adopt.getAnimalName().isEmpty()) {
            Animal animal = animalDao.selectById(adopt.getAnimalId());
            animal.setName(adopt.getAnimalName());
            animalDao.updateById(animal);
        }

        //如果领养状态不是放弃领养,更新数据
        int i = adoptDao.updateById(adopt);
        //判断是否更新成功
        if (i > 0){
            return Result.success();
        }

        return Result.error("-1","更新失败");
    }
}
```

### 3 实现宠物房间功能

#### 3.1查询宠物房间列表数据

创建对应宠物房间Room实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.*;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("room")
public class Room {
    /**
     * 主键id
     */
    @TableId(type = IdType.AUTO)
    private Integer id;
    /**
     * 房间名
     */
    private String name;
    /**
     * 房间状态
     */
    private String status;

    /**
     * 宠物昵称
     */
    //fill= FieldFill.UPDATE 表示该字段在更新时自动填充
    @TableField(fill= FieldFill.UPDATE)
    private String animal;
}
```

创建对应控制层RoomController

```
package com.qf.controller;


import com.qf.utils.Result;
import com.qf.service.RoomService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/room")
public class RoomController {

    //注入RoomService
    @Autowired
    private RoomService roomService;

    /**
     * 房间列表查询
     * @param name 房间名称
     * @param pageNum 页码
     * @param pageSize 页大小
     * @return 房间列表
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer pageNum,
            @RequestParam(defaultValue = "10") Integer pageSize) {
        //调用RoomService的selectPage方法
        return roomService.selectPage(name, pageNum, pageSize);
    }
}
```

创建服务层RoomService,并添加selectPage抽象方法用于查询分页列表数据

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Room;

public interface RoomService extends IService<Room> {
    Result selectPage(String name, Integer pageNum, Integer pageSize);
}
```

创建对应实现类RoomServiceImpl,并重写selectPage抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.RoomDao;
import com.qf.entity.Room;
import com.qf.service.RoomService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class RoomServiceImpl extends ServiceImpl<RoomDao, Room> implements RoomService {

    //注入RoomDao
    @Autowired
    private RoomDao roomDao;

    @Override
    public Result selectPage(String name, Integer pageNum, Integer pageSize) {
        //创建LambdaQueryWrapper条件构造器
        LambdaQueryWrapper<Room> queryWrapper = new LambdaQueryWrapper<>();
        //判断name是否为空
        if (StringUtils.isNotBlank(name)) {
            //根据name进行查询
            queryWrapper.like(Room::getName, name);
        }
        //分页查询
        //selectPage方法返回Page对象，里面包含了分页查询的结果
        Page<Room> ResultPage = roomDao.selectPage(new Page<>(pageNum, pageSize), queryWrapper);

        //将Page对象转换为Result对象,并返回给前端
        return Result.success(ResultPage);
    }
}
```

创建对应数据访问层RoomDao接口

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.Room;

public interface RoomDao extends BaseMapper<Room> {
}
```

#### 3.2批量删除宠物房间功能

在RoomController中添加deleteBatch方法,用于批量删除功能

```
package com.qf.controller;


import com.qf.utils.Result;
import com.qf.service.RoomService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/room")
public class RoomController {

    //注入RoomService
    @Autowired
    private RoomService roomService;

    /**
     * 房间列表查询
     * @param name 房间名称
     * @param pageNum 页码
     * @param pageSize 页大小
     * @return 房间列表
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer pageNum,
            @RequestParam(defaultValue = "10") Integer pageSize) {
        //调用RoomService的selectPage方法
        return roomService.selectPage(name, pageNum, pageSize);
    }

    /**
     * 根据id批量删除房间
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return roomService.deleteBatch(ids);
    }
}
```

在RoomService中添加deleteBatch抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Room;

import java.util.List;

public interface RoomService extends IService<Room> {
    Result selectPage(String name, Integer pageNum, Integer pageSize);

    Result deleteBatch(List<Integer> ids);
}
```

在对应RoomServiceImpl中重写deleteBatch抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.RoomDao;
import com.qf.entity.Room;
import com.qf.service.RoomService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class RoomServiceImpl extends ServiceImpl<RoomDao, Room> implements RoomService {

    //注入RoomDao
    @Autowired
    private RoomDao roomDao;

    @Override
    public Result selectPage(String name, Integer pageNum, Integer pageSize) {
        //创建LambdaQueryWrapper条件构造器
        LambdaQueryWrapper<Room> queryWrapper = new LambdaQueryWrapper<>();
        //判断name是否为空
        if (StringUtils.isNotBlank(name)) {
            //根据name进行查询
            queryWrapper.like(Room::getName, name);
        }
        //分页查询
        //selectPage方法返回Page对象，里面包含了分页查询的结果
        Page<Room> ResultPage = roomDao.selectPage(new Page<>(pageNum, pageSize), queryWrapper);

        //将Page对象转换为Result对象,并返回给前端
        return Result.success(ResultPage);
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }
        //批量删除
        for (Integer id : ids) {
            // ||为或运算符，当id为空或者删除失败时返回错误信息
            if (id == null || roomDao.deleteById(id) <= 0) {
                return Result.error("-1", "（部分）删除失败");
            }
        }

        // roomDao.deleteBatchIds(ids);
        //全部删除成功
        return Result.success();
    }
}
```

#### 3.3添加宠物房间功能

在enums包下创建枚举类RoomStatus(房间状态)

```
package com.qf.enums;

public enum RoomStatus {
    USING("使用中"),
    EMPTY("闲置");
    private String info;

    RoomStatus(String info) {
        this.info = info;
    }

    public String getInfo() {
        return info;
    }
}
```

在对应控制层RoomController中添加save方法,用于保存数据

```
package com.qf.controller;


import com.qf.utils.Result;
import com.qf.entity.Room;
import com.qf.service.RoomService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/room")
public class RoomController {

    //注入RoomService
    @Autowired
    private RoomService roomService;

    /**
     * 房间列表查询
     * @param name 房间名称
     * @param pageNum 页码
     * @param pageSize 页大小
     * @return 房间列表
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer pageNum,
            @RequestParam(defaultValue = "10") Integer pageSize) {
        //调用RoomService的selectPage方法
        return roomService.selectPage(name, pageNum, pageSize);
    }

    /**
     * 根据id批量删除房间
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return roomService.deleteBatch(ids);
    }

    /**
     * 新增房间功能
     * @param room
     * @return
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Room room) {
        return roomService.saveRoom(room);
    }
}
```

在对应服务层RoomService中添加saveRoom抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Room;

import java.util.List;

public interface RoomService extends IService<Room> {
    Result selectPage(String name, Integer pageNum, Integer pageSize);

    Result deleteBatch(List<Integer> ids);

    Result saveRoom(Room room);
}
```

在对应实现类RoomServiceImpl中重写saveRoom抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.RoomDao;
import com.qf.entity.Room;
import com.qf.enums.RoomStatus;
import com.qf.service.RoomService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class RoomServiceImpl extends ServiceImpl<RoomDao, Room> implements RoomService {

    //注入RoomDao
    @Autowired
    private RoomDao roomDao;


    @Override
    public Result selectPage(String name, Integer pageNum, Integer pageSize) {
        //创建LambdaQueryWrapper条件构造器
        LambdaQueryWrapper<Room> queryWrapper = new LambdaQueryWrapper<>();
        //判断name是否为空
        if (StringUtils.isNotBlank(name)) {
            //根据name进行查询
            queryWrapper.like(Room::getName, name);
        }
        //分页查询
        //selectPage方法返回Page对象，里面包含了分页查询的结果
        Page<Room> ResultPage = roomDao.selectPage(new Page<>(pageNum, pageSize), queryWrapper);

        //将Page对象转换为Result对象,并返回给前端
        return Result.success(ResultPage);
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }
        //批量删除
        for (Integer id : ids) {
            // ||为或运算符，当id为空或者删除失败时返回错误信息
            if (id == null || roomDao.deleteById(id) <= 0) {
                return Result.error("-1", "（部分）删除失败");
            }
        }
        //全部删除成功
        return Result.success();
    }

    @Override
    public Result saveRoom(Room room) {
        //构建查询条件
        LambdaQueryWrapper<Room> wrapper = new LambdaQueryWrapper<>();
        // 使用wrapper对象的方法eq来比较两个房间名称是否相等
        // Room::getName 是方法引用，指向Room类的getName方法
        // room.getName() 是获取当前room对象的名称
        wrapper.eq(Room::getName, room.getName());
        //查询房间名称是否已存在
        Long count = roomDao.selectCount(wrapper);
        if (count > 0) {
            return Result.error("-1", "房间名称已存在，请使用其他名称。");
        }
        //保存房间信息
        room.setStatus(RoomStatus.EMPTY.getInfo());
        //调用dao层的insert方法保存房间信息
        int res = roomDao.insert(room);
        //三位运算符，当res大于0时返回Result.success()，否则返回Result.error("-1", "添加失败")
        return res > 0 ? Result.success() : Result.error("-1", "添加失败");
    }
}
```

#### 3.4 编辑宠物房间功能

在RoomController中添加updateById方法,用于修改房间信息

```
package com.qf.controller;


import com.qf.utils.Result;
import com.qf.entity.Room;
import com.qf.service.RoomService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/room")
public class RoomController {

    //注入RoomService
    @Autowired
    private RoomService roomService;

    /**
     * 房间列表查询
     * @param name 房间名称
     * @param pageNum 页码
     * @param pageSize 页大小
     * @return 房间列表
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer pageNum,
            @RequestParam(defaultValue = "10") Integer pageSize) {
        //调用RoomService的selectPage方法
        return roomService.selectPage(name, pageNum, pageSize);
    }

    /**
     * 根据id批量删除房间
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return roomService.deleteBatch(ids);
    }

    /**
     * 新增房间功能
     * @param room
     * @return
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Room room) {
        return roomService.saveRoom(room);
    }


    /**
     * 根据id修改房间信息
     * @param room
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody Room room) {
        return roomService.updateRoomById(room);
    }
}
```

在RoomService中添加updateRoomById抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Room;

import java.util.List;

public interface RoomService extends IService<Room> {
    Result selectPage(String name, Integer pageNum, Integer pageSize);

    Result deleteBatch(List<Integer> ids);

    Result saveRoom(Room room);

    Result updateRoomById(Room room);
}
```

在对应实现类RoomServiceImpl中重写updateRoomById抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.RoomDao;
import com.qf.entity.Room;
import com.qf.enums.RoomStatus;
import com.qf.service.RoomService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class RoomServiceImpl extends ServiceImpl<RoomDao, Room> implements RoomService {

    //注入RoomDao
    @Autowired
    private RoomDao roomDao;


    @Override
    public Result selectPage(String name, Integer pageNum, Integer pageSize) {
        //创建LambdaQueryWrapper条件构造器
        LambdaQueryWrapper<Room> queryWrapper = new LambdaQueryWrapper<>();
        //判断name是否为空
        if (StringUtils.isNotBlank(name)) {
            //根据name进行查询
            queryWrapper.like(Room::getName, name);
        }
        //分页查询
        //selectPage方法返回Page对象，里面包含了分页查询的结果
        Page<Room> ResultPage = roomDao.selectPage(new Page<>(pageNum, pageSize), queryWrapper);

        //将Page对象转换为Result对象,并返回给前端
        return Result.success(ResultPage);
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }
        //批量删除
        for (Integer id : ids) {
            // ||为或运算符，当id为空或者删除失败时返回错误信息
            if (id == null || roomDao.deleteById(id) <= 0) {
                return Result.error("-1", "（部分）删除失败");
            }
        }
        //全部删除成功
        return Result.success();
    }

    @Override
    public Result saveRoom(Room room) {
        //构建查询条件
        LambdaQueryWrapper<Room> wrapper = new LambdaQueryWrapper<>();
        // 使用wrapper对象的方法eq来比较两个房间名称是否相等
        // Room::getName 是方法引用，指向Room类的getName方法
        // room.getName() 是获取当前room对象的名称
        wrapper.eq(Room::getName, room.getName());
        //查询房间名称是否已存在
        Long count = roomDao.selectCount(wrapper);
        if (count > 0) {
            return Result.error("-1", "房间名称已存在，请使用其他名称。");
        }
        //保存房间信息
        room.setStatus(RoomStatus.EMPTY.getInfo());
        //调用dao层的insert方法保存房间信息
        int res = roomDao.insert(room);
        //三位运算符，当res大于0时返回Result.success()，否则返回Result.error("-1", "添加失败")
        return res > 0 ? Result.success() : Result.error("-1", "添加失败");
    }

    @Override
    public Result updateRoomById(Room room) {
        // 根据房间ID获取现有房间信息
        Room existing = this.getById(room.getId());
        // 如果房间不存在，返回错误信息
        if (existing == null) {
            return Result.error("-1", "房间不存在");
        }
        // 获取并去除房间名称前后的空格
        String newName = room.getName().trim();
        // 如果新名称与现有名称不同且数据库中已存在该名称的房间，返回错误信息
        if (!existing.getName().equals(newName) &&
                // 使用父类IService的count方法统计数据库中名称为newName的房间数量，并排除当前房间的ID
                this.count(new LambdaQueryWrapper<Room>().eq(Room::getName, newName).ne(Room::getId, room.getId())) > 0) {
            return Result.error("-1", "房间名称" + newName + "已存在");
        }
        // 更新房间信息，若更新成功返回成功结果，否则返回错误信息
        return this.updateById(room) ? Result.success() : Result.error("-1", "更新失败");
    }
}
```

### 4 实现宠物品种管理功能

#### 4.1查询所有宠物品种列表数据

在BreedController中添加selectPage方法,用于查询宠物品种列表数据

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Breed;
import com.qf.service.BreedService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RequestMapping("/breed")
@RestController
public class BreedController {

    // 自动注入BreedService接口
    @Autowired
    private BreedService breedService;


    @RequestMapping("/selectPage")
    public Result selectPage(@RequestParam(defaultValue = "") String name,
                                @RequestParam(defaultValue = "1") Integer pageNum,
                                @RequestParam(defaultValue = "10") Integer pageSize) {
        // 调用IService接口的selectPage方法，获取分页后的品种列表
        return breedService.selectPage(name, pageNum, pageSize);
    }
}
```

在对应服务层BreedService中添加selectPage抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Breed;

public interface BreedService extends IService<Breed> {

    Result selectPage(String name, Integer pageNum, Integer pageSize);
}
```

在对应实现类BreedServiceImpl中重写selectPage抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.BreedDao;
import com.qf.entity.Breed;
import com.qf.service.BreedService;
import org.springframework.stereotype.Service;

@Service
public class BreedServiceImpl extends ServiceImpl<BreedDao, Breed> implements BreedService {
    private final BreedDao breedDao;

    public BreedServiceImpl(BreedDao breedDao) {
        this.breedDao = breedDao;
    }

    @Override
    public Result selectPage(String name, Integer pageNum, Integer pageSize) {
        // 构造查询条件
        LambdaQueryWrapper<Breed> queryWrapper = Wrappers.lambdaQuery();
        //判断是否有查询条件
        if (StringUtils.isNotBlank(name)) {
            // 按名字模糊查询
            queryWrapper.like(Breed::getBreedName, name);
        }
        // 调用dao查询分页数据
        Page<Breed> ResultPage = breedDao.selectPage(new Page<>(pageNum, pageSize), queryWrapper);
        // 返回分页数据
        return Result.success(ResultPage);
    }
}
```

#### 4.2实现批量删除品种功能

在BreedController中添加deleteBatch方法,用于批量删除品种数据

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Breed;
import com.qf.service.BreedService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RequestMapping("/breed")
@RestController
public class BreedController {

    // 自动注入BreedService接口
    @Autowired
    private BreedService breedService;

    @RequestMapping("/selectAll")
    // 定义一个公共方法，用于获取所有品种信息
    public Result selectAll() {
        // 调用IService接口的list方法，获取所有品种的列表
        List<Breed> breeds = breedService.list();
        // 如果breeds列表不为空，则返回成功的Result对象，包含breeds列表；否则返回错误的Result对象
        return breeds != null ? Result.success(breeds) : Result.error("-1", "查找失败");
    }

    /**
     * 查询全部宠物品种列表数据
     * @param name
     * @param pageNum
     * @param pageSize
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(@RequestParam(defaultValue = "") String name,
                                @RequestParam(defaultValue = "1") Integer pageNum,
                                @RequestParam(defaultValue = "10") Integer pageSize) {
        // 调用IService接口的selectPage方法，获取分页后的品种列表
        return breedService.selectPage(name, pageNum, pageSize);
    }


    /**
     * 根据id批量删除品种
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        // 调用IService接口的deleteBatchByIds方法，批量删除品种
        return breedService.deleteBatchByIds(ids);
    }

}
```

在对应服务层BreedService中添加deleteBatchByIds抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Breed;

import java.util.List;

public interface BreedService extends IService<Breed> {

    Result selectPage(String name, Integer pageNum, Integer pageSize);

    Result deleteBatchByIds(List<Integer> ids);
}
```

在对应实现类BreedServiceImpl中重写deleteBatchByIds抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.BreedDao;
import com.qf.entity.Breed;
import com.qf.service.BreedService;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BreedServiceImpl extends ServiceImpl<BreedDao, Breed> implements BreedService {
    private final BreedDao breedDao;

    public BreedServiceImpl(BreedDao breedDao) {
        this.breedDao = breedDao;
    }

    @Override
    public Result selectPage(String name, Integer pageNum, Integer pageSize) {
        // 构造查询条件
        LambdaQueryWrapper<Breed> queryWrapper = Wrappers.lambdaQuery();
        //判断是否有查询条件
        if (StringUtils.isNotBlank(name)) {
            // 按名字模糊查询
            queryWrapper.like(Breed::getBreedName, name);
        }
        // 调用dao查询分页数据
        Page<Breed> ResultPage = breedDao.selectPage(new Page<>(pageNum, pageSize), queryWrapper);
        // 返回分页数据
        return Result.success(ResultPage);
    }

    @Override
    public Result deleteBatchByIds(List<Integer> ids) {
        // 判断是否有ID列表
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }
        // 执行批量删除ServiceImpl中的removeByIds方法
        boolean success = this.removeByIds(ids);
        // 根据结果返回 Result
        return success ? Result.success() : Result.error("-1", "批量删除失败");
    }
}
```

#### 4.3实现添加品种功能

在BreedController中添加add方法,用于新增品种数据

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Breed;
import com.qf.service.BreedService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RequestMapping("/breed")
@RestController
public class BreedController {

    // 自动注入BreedService接口
    @Autowired
    private BreedService breedService;

    @RequestMapping("/selectAll")
    // 定义一个公共方法，用于获取所有品种信息
    public Result selectAll() {
        // 调用IService接口的list方法，获取所有品种的列表
        List<Breed> breeds = breedService.list();
        // 如果breeds列表不为空，则返回成功的Result对象，包含breeds列表；否则返回错误的Result对象
        return breeds != null ? Result.success(breeds) : Result.error("-1", "查找失败");
    }

    /**
     * 查询全部宠物品种列表数据
     * @param name
     * @param pageNum
     * @param pageSize
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(@RequestParam(defaultValue = "") String name,
                                @RequestParam(defaultValue = "1") Integer pageNum,
                                @RequestParam(defaultValue = "10") Integer pageSize) {
        // 调用IService接口的selectPage方法，获取分页后的品种列表
        return breedService.selectPage(name, pageNum, pageSize);
    }


    /**
     * 根据id批量删除品种
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        // 调用IService接口的deleteBatchByIds方法，批量删除品种
        return breedService.deleteBatchByIds(ids);
    }

    /**
     * 添加品种
     * @param breed
     * @return
     */
    @RequestMapping("/save")
    public Result add(@RequestBody Breed breed) {
        return breedService.addBreed(breed);
    }

}
```

在对应服务层BreedService中添加addBreed抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Breed;

import java.util.List;

public interface BreedService extends IService<Breed> {

    Result selectPage(String name, Integer pageNum, Integer pageSize);

    Result deleteBatchByIds(List<Integer> ids);

    Result addBreed(Breed breed);
}
```

在对应实现类BreedServiceImpl中重写addBreed抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.BreedDao;
import com.qf.entity.Breed;
import com.qf.service.BreedService;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BreedServiceImpl extends ServiceImpl<BreedDao, Breed> implements BreedService {
    private final BreedDao breedDao;

    public BreedServiceImpl(BreedDao breedDao) {
        this.breedDao = breedDao;
    }

    @Override
    public Result selectPage(String name, Integer pageNum, Integer pageSize) {
        // 构造查询条件
        LambdaQueryWrapper<Breed> queryWrapper = Wrappers.lambdaQuery();
        //判断是否有查询条件
        if (StringUtils.isNotBlank(name)) {
            // 按名字模糊查询
            queryWrapper.like(Breed::getBreedName, name);
        }
        // 调用dao查询分页数据
        Page<Breed> ResultPage = breedDao.selectPage(new Page<>(pageNum, pageSize), queryWrapper);
        // 返回分页数据
        return Result.success(ResultPage);
    }

    @Override
    public Result deleteBatchByIds(List<Integer> ids) {
        // 判断是否有ID列表
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }
        // 执行批量删除ServiceImpl中的removeByIds方法
        boolean success = this.removeByIds(ids);
        // 根据结果返回 Result
        return success ? Result.success() : Result.error("-1", "批量删除失败");
    }

    @Override
    public Result addBreed(Breed breed) {

        // 校验名称是否已存在
        // .trim() 方法用于去除字符串两端的空格
        String breedName = breed.getBreedName().trim();
        //调用IService中的count方法，判断名称是否已存在
        boolean exists = this.count(
                // 构造查询条件
                new LambdaQueryWrapper<Breed>().eq(Breed::getBreedName, breedName)
        ) > 0;

        //  判断名称是否已存在
        if (exists) {
            // 名称已存在，返回错误信息
            return Result.error("-1", "品种名称" + breedName + "已存在，请使用其他名称。");
        }
        // 如果名称不存在，则执行添加操作
        // 调用IService中的save方法，添加品种信息
        boolean saved = this.save(breed);
        // 判断是否添加成功,如果成功，返回成功信息，否则返回失败信息
        return saved ? Result.success() : Result.error("-1", "添加失败");
    }
}
```

#### 4.4实现编辑品种功能

在BreedController中添加updateById方法,用于修改品种数据

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Breed;
import com.qf.service.BreedService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RequestMapping("/breed")
@RestController
public class BreedController {

    // 自动注入BreedService接口
    @Autowired
    private BreedService breedService;

    @RequestMapping("/selectAll")
    // 定义一个公共方法，用于获取所有品种信息
    public Result selectAll() {
        // 调用IService接口的list方法，获取所有品种的列表
        List<Breed> breeds = breedService.list();
        // 如果breeds列表不为空，则返回成功的Result对象，包含breeds列表；否则返回错误的Result对象
        return breeds != null ? Result.success(breeds) : Result.error("-1", "查找失败");
    }

    /**
     * 查询全部宠物品种列表数据
     * @param name
     * @param pageNum
     * @param pageSize
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(@RequestParam(defaultValue = "") String name,
                                @RequestParam(defaultValue = "1") Integer pageNum,
                                @RequestParam(defaultValue = "10") Integer pageSize) {
        // 调用IService接口的selectPage方法，获取分页后的品种列表
        return breedService.selectPage(name, pageNum, pageSize);
    }


    /**
     * 根据id批量删除品种
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        // 调用IService接口的deleteBatchByIds方法，批量删除品种
        return breedService.deleteBatchByIds(ids);
    }

    /**
     * 添加品种
     * @param breed
     * @return
     */
    @RequestMapping("/save")
    public Result add(@RequestBody Breed breed) {
        return breedService.addBreed(breed);
    }


    /**
     * 根据id修改品种
     * @param breed
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody Breed breed) {
        return breedService.updateBreedById(breed);
    }

}
```

在对应服务层BreedService中添加updateBreedById抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Breed;

import java.util.List;

public interface BreedService extends IService<Breed> {

    Result selectPage(String name, Integer pageNum, Integer pageSize);

    Result deleteBatchByIds(List<Integer> ids);

    Result addBreed(Breed breed);

    Result updateBreedById(Breed breed);
}
```

在对应实现类BreedServiceImpl中重写updateBreedById抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.BreedDao;
import com.qf.entity.Breed;
import com.qf.service.BreedService;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BreedServiceImpl extends ServiceImpl<BreedDao, Breed> implements BreedService {
    private final BreedDao breedDao;

    public BreedServiceImpl(BreedDao breedDao) {
        this.breedDao = breedDao;
    }

    @Override
    public Result selectPage(String name, Integer pageNum, Integer pageSize) {
        // 构造查询条件
        LambdaQueryWrapper<Breed> queryWrapper = Wrappers.lambdaQuery();
        //判断是否有查询条件
        if (StringUtils.isNotBlank(name)) {
            // 按名字模糊查询
            queryWrapper.like(Breed::getBreedName, name);
        }
        // 调用dao查询分页数据
        Page<Breed> ResultPage = breedDao.selectPage(new Page<>(pageNum, pageSize), queryWrapper);
        // 返回分页数据
        return Result.success(ResultPage);
    }

    @Override
    public Result deleteBatchByIds(List<Integer> ids) {
        // 判断是否有ID列表
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }
        // 执行批量删除ServiceImpl中的removeByIds方法
        boolean success = this.removeByIds(ids);
        // 根据结果返回 Result
        return success ? Result.success() : Result.error("-1", "批量删除失败");
    }

    @Override
    public Result addBreed(Breed breed) {

        // 校验名称是否已存在
        // .trim() 方法用于去除字符串两端的空格
        String breedName = breed.getBreedName().trim();
        //调用IService中的count方法，判断名称是否已存在
        boolean exists = this.count(
                // 构造查询条件
                new LambdaQueryWrapper<Breed>().eq(Breed::getBreedName, breedName)
        ) > 0;

        //  判断名称是否已存在
        if (exists) {
            // 名称已存在，返回错误信息
            return Result.error("-1", "品种名称" + breedName + "已存在，请使用其他名称。");
        }
        // 如果名称不存在，则执行添加操作
        // 调用IService中的save方法，添加品种信息
        boolean saved = this.save(breed);
        // 判断是否添加成功,如果成功，返回成功信息，否则返回失败信息
        return saved ? Result.success() : Result.error("-1", "添加失败");
    }

    @Override
    public Result updateBreedById(Breed breed) {
        // 判断品种名称是否为空
        if (StringUtils.isBlank(breed.getBreedName())) {
            return Result.error("-1", "品种名称不能为空");
        }

        // 查询原品种是否存在
        // 调用IService中的getById方法，根据ID查询品种信息
        Breed existing = this.getById(breed.getBreedId());
        if (existing == null) {
            return Result.error("-1", "要更新的品种不存在");
        }

        // 如果名称变了，校验是否与其他品种重复（排除自己）
        String newName = breed.getBreedName().trim();
        if (!existing.getBreedName().equals(newName)) {
            // 调用IService中的count方法，判断名称是否已存在
            boolean exists = this.count(
                    // 构造查询条件
                    new LambdaQueryWrapper<Breed>()
                            .eq(Breed::getBreedName, newName)
                            //.ne方法是不等于,用于排除自己
                            .ne(Breed::getBreedId, breed.getBreedId())
            ) > 0;

            if (exists) {
                return Result.error("-1", "品种名称" + newName + "已存在，请使用其他名称");
            }
        }

        // 执行更新（ID 已在 breed 中）
        boolean updated = this.updateById(breed);
        // 判断是否更新成功,如果成功，返回成功信息，否则返回失败信息
        return updated ? Result.success() : Result.error("-1", "更新失败");
    }
}
```

### 5 实现宠物健康管理功能

打开当前页面首先会查询全部的宠物数据

首先实现查询全部宠物功能

在AnimalController中添加selectAll方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Animal;
import com.qf.service.AnimalService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

// @RestController注解表示该类是一个控制器类，其实是@Controller和@ResponseBody的组合注解
@RestController
// 设置该控制器处理的请求的基本路径为"/animal"
@RequestMapping("/animal")
public class AnimalController {

    // 注入AnimalService实例，用于调用动物相关的服务方法
    @Autowired
    private AnimalService animalService;

    /**
     * 查询分页动物列表功能
     * @param name
     * @param type
     * @return
     */
    // 定义一个处理分页查询请求的方法，路径为"/animal/page"
    @RequestMapping("/page")
    // 处理分页查询请求的方法，接收四个参数：动物名称、动物类型、当前页码和每页大小
    public Result selectPage(
            // 动物名称，默认值为空字符串
            @RequestParam(defaultValue = "") String name,
            // 动物类型，默认值为空字符串
            @RequestParam(defaultValue = "") String type,
            // 当前页码，默认值为1
            @RequestParam(defaultValue = "1") Integer currentPage,
            // 每页显示的记录数，默认值为10
            @RequestParam(defaultValue = "10") Integer size) {
        // 调用animalService的selectPage方法，并返回查询结果
        return animalService.selectPage(name, type, currentPage, size);
    }

    /**
     * 根据id批量删除动物功能
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        // 调用animalService的removeBatchByIds方法，并返回删除结果
        boolean res = animalService.removeBatchByIds(ids);
        // 根据删除结果返回不同的响应
        if (res) {
            // 成功删除
            return Result.success();
        } else {
            // 删除失败
            return Result.error("-1", "删除失败");
        }
    }

    /**
     * 新增动物功能
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Animal animal) {
        // 调用animalService的save方法，保存新增的动物信息
        animalService.save(animal);
        // 返回成功响应
        return Result.success();
    }


    @PutMapping("/update/{id}")
    public Result updateAnimal(@PathVariable Integer id, @RequestBody Animal animal) {
        // 确保更新时使用正确的ID
        animal.setId(id);
        // 调用animalService的updateById方法，更新动物信息
        boolean res = animalService.updateById(animal);
        if (res) {
            return Result.success(animal);
        } else {
            return Result.error("-1", "更新失败");
        }
    }

    /**
     * 查询全部动物功能
     * @return
     */
    @RequestMapping("/selectAll")
    public Result selectAll() {
        return animalService.selectAll();
    }
}
```

在AnimalService接口中创建selectAll抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Animal;

public interface AnimalService extends IService<Animal> {
    Result selectPage(String name, String type, Integer currentPage, Integer size);

    Result selectAll();
}
```

在对应实现类中重写selectAll抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.AnimalDao;
import com.qf.entity.Animal;
import com.qf.service.AnimalService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class AnimalServiceImpl extends ServiceImpl<AnimalDao, Animal> implements AnimalService {

    //注入AnimalDao
    @Autowired
    private AnimalDao animalDao;

    @Override
    // 定义一个方法，接收名称、类型、当前页码和每页显示数量作为参数，并返回查询结果
    public Result selectPage(String name, String type, Integer currentPage, Integer size) {
        // 创建LambdaQueryWrapper实例，用于构建查询条件
        LambdaQueryWrapper<Animal> wrapper = new LambdaQueryWrapper<>();
        // 如果名称不为空，则添加名称的模糊查询条件
        wrapper.like(StringUtils.isNotBlank(name), Animal::getName, name)
                // 如果类型不为空，则添加类型的模糊查询条件
                .like(StringUtils.isNotBlank(type), Animal::getType, type)
                // 按照ID降序排列查询结果
                .orderByDesc(Animal::getId);
        // 使用animalDao执行分页查询，并将结果存储在page对象中
        //Page对象用于分页查询，包含当前页码、每页显示数量、总记录数、查询结果,mybatis-plus会自动进行分页处理
        Page<Animal> page = animalDao.selectPage(new Page<>(currentPage, size), wrapper);
        // 返回查询成功的结果，包含分页信息
        return Result.success(page);
    }

    @Override
    public Result selectAll() {
        //select * from animal
        //查询所有动物数据
        List<Animal> animals = animalDao.selectList(null);
        if (animals != null && !animals.isEmpty()) {
            return Result.success(animals);
        } else {
            return Result.error("-1", "未找到动物数据");
        }
    }
}
```

#### 5.1查询健康记录列表数据

宠物健康管理模块涉及两张表的关联查询：健康记录表（health_record）和宠物表（animal）。需要先创建对应的视图对象（VO）用于封装连表查询的结果。

首先创建HealthRecord实体类，对应数据库health_record表

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;


@Data
@NoArgsConstructor
@AllArgsConstructor
public class HealthRecord {

    // 主键ID
    @TableId(type = IdType.AUTO)
    private Long id;

    // 宠物ID
    private Long petId;

    // 记录日期
    private LocalDate recordDate;

    // 体温（单位：摄氏度）
    private Double temperature;

    // 体重（单位：千克）
    private Double weight;

    // 身高（单位：厘米）
    private Double height;

    // 疫苗接种日期
    private LocalDate vaccinationDate;

    // 健康状态（如：良好、一般、异常等）
    private String healthStatus;
}
```

创建HealthRecordVO视图对象，继承HealthRecord并扩展宠物名称字段，用于连表查询时承载结果数据

在vo下创建HealthRecordVO

```
package com.qf.vo;

import com.baomidou.mybatisplus.annotation.TableField;
import com.qf.entity.HealthRecord;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;

//@EqualsAndHashCode(callSuper = false)是生成hashCode和equals方法的注解，callSuper = false表示不调用父类的equals方法。
@EqualsAndHashCode(callSuper = false)
//Data注解是lombok提供的注解，它会生成get、set方法。
@Data
//NoArgsConstructor注解是lombok提供的注解，它会生成无参构造器。
@NoArgsConstructor
//AllArgsConstructor注解是lombok提供的注解，它会生成全参构造器。
@AllArgsConstructor
//AdoptVO类继承自Adopt类，并添加了userName、animalImg、animalName三个属性。
public class HealthRecordVO extends HealthRecord {

    /**
     * 用户表外键
     * 对应的是animal表的name字段
     */
    @TableField(exist = false)
    private String petName;
}
```

在HealthRecordController中添加getHealthRecordByPage方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.HealthRecord;
import com.qf.service.HealthRecordService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/health-record")
public class HealthRecordController {

    @Autowired
    private HealthRecordService healthRecordService;


    /**
     * 获取健康记录列表
     * @param petName
     * @param recordDate
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getHealthRecordByPage(
            @RequestParam(defaultValue = "") String petName,
            @RequestParam(defaultValue = "") String recordDate,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return healthRecordService.getHealthRecordByPage(petName, recordDate, currentPage, size);
    }

}
```

创建对应服务层HealthRecordService接口，并添加getHealthRecordByPage抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.HealthRecord;

public interface HealthRecordService extends IService<HealthRecord> {
    Result getHealthRecordByPage(String petName, String recordDate, Integer currentPage, Integer size);
}
```

在对应实现类HealthRecordServiceImpl重写getHealthRecordByPage抽象方法

```
package com.qf.service.impl;


import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.HealthRecordDao;
import com.qf.entity.HealthRecord;
import com.qf.service.HealthRecordService;
import com.qf.vo.HealthRecordVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


@Service
public class HealthRecordServiceImpl extends ServiceImpl<HealthRecordDao, HealthRecord> implements HealthRecordService {

    @Autowired
    private HealthRecordDao healthRecordDao;

    @Override
    public Result getHealthRecordByPage(String petName, String recordDate, Integer currentPage, Integer size) {
        // 创建一个分页对象，设置当前页码和每页大小
        Page<HealthRecordVO> page = new Page<>(currentPage, size);
        // 根据宠物名称和记录日期从数据库中查询健康记录，并将结果存储到healthRecordPage中
        Page<HealthRecordVO> healthRecordPage = healthRecordDao.selectByPage(petName, recordDate, page);
        // 返回一个成功的结果，包含分页后的健康记录数据
        return Result.success(healthRecordPage);
    }


}
```

在对应的dao层接口HealthRecordDao中，需要自定义一个分页查询方法selectByPage，因为MyBatis-Plus默认的selectPage只能单表查询，这里需要关联animal表获取宠物名称

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.qf.entity.HealthRecord;
import com.qf.vo.HealthRecordVO;
import org.apache.ibatis.annotations.Param;

public interface HealthRecordDao extends BaseMapper<HealthRecord> {
    Page<HealthRecordVO> selectByPage(@Param("petName")String petName , @Param("recordDate") String recordDate, Page<HealthRecordVO> page);

}
```

在resources/mapper目录下创建HealthRecordDao.xml，编写连表查询的SQL语句。使用LEFT JOIN关联animal表，通过resultMap将查询结果映射到HealthRecordVO对象

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.qf.dao.HealthRecordDao">


    <!-- 定义一个名为healthRecordResultMap的结果映射，映射到类型为com.qf.vo.HealthRecordVO的对象 -->
    <resultMap id="healthRecordResultMap" type="com.qf.vo.HealthRecordVO">
        <!-- 映射主键id到HealthRecordVO的id属性 -->
        <id property="id" column="id"/>
        <!-- 映射pet_id列的值到HealthRecordVO的petId属性 -->
        <result property="petId" column="pet_id"/>
        <!-- 映射record_date列的值到HealthRecordVO的recordDate属性 -->
        <result property="recordDate" column="record_date"/>
        <!-- 映射temperature列的值到HealthRecordVO的temperature属性 -->
        <result property="temperature" column="temperature"/>
        <!-- 映射weight列的值到HealthRecordVO的weight属性 -->
        <result property="weight" column="weight"/>
        <!-- 映射height列的值到HealthRecordVO的height属性 -->
        <result property="height" column="height"/>
        <!-- 映射vaccination_date列的值到HealthRecordVO的vaccinationDate属性 -->
        <result property="vaccinationDate" column="vaccination_date"/>
        <!-- 映射health_status列的值到HealthRecordVO的healthStatus属性 -->
        <result property="healthStatus" column="health_status"/>
        <!-- 映射petName列的值到HealthRecordVO的petName属性 -->
        <result property="petName" column="petName"/>
    </resultMap>


    <!-- 定义一个名为selectByPage的查询语句，使用healthRecordResultMap作为结果映射 -->
    <select id="selectByPage" resultMap="healthRecordResultMap">
        <!-- 选择健康记录表hr的所有字段以及动物表a中的name字段，并将其重命名为petName -->
        SELECT
        <!-- 选择健康记录表hr的所有字段 -->
        hr.*,
        <!-- 选择动物表a中的name字段，并将其重命名为petName -->
        a.name AS petName
        <!-- 指定从动物表a和健康记录表hr中查询数据，通过pet_id和id字段进行左连接 -->
        FROM
        <!-- 健康记录表 -->
        health_record hr
        <!-- 左连接动物表 -->
        LEFT JOIN
        <!-- 动物表 -->
        animal a ON hr.pet_id = a.id
        <!-- 设置查询条件，1=1是一个常用的SQL技巧，便于动态添加条件 -->
        WHERE
        <!-- 查询条件开始 -->
        1 = 1
        <!-- 如果传入的petName不为空且不为空字符串，则添加对动物表a中name字段的模糊查询条件 -->
        <if test="petName!= null and petName!= ''">
            <!-- 动物名称模糊匹配 -->
            AND a.name LIKE CONCAT('%', #{petName}, '%')
        </if>

        <!-- 如果传入的recordDate不为空且不为空字符串，则添加对健康记录表hr中record_date字段的精确查询条件 -->
        <if test="recordDate!= null and recordDate!= ''">
            <!-- 记录日期精确匹配 -->
            AND hr.record_date = #{recordDate}
        </if>

        <!-- 按照健康记录表hr中的id字段进行降序排序 -->
        ORDER BY
        <!-- 健康记录ID -->
        hr.id DESC
    </select>

</mapper>
```

#### 5.2实现批量删除健康记录功能

在HealthRecordController中添加deleteBatch方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.HealthRecord;
import com.qf.service.HealthRecordService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/health-record")
public class HealthRecordController {

    @Autowired
    private HealthRecordService healthRecordService;


    /**
     * 获取健康记录列表
     * @param petName
     * @param recordDate
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getHealthRecordByPage(
            @RequestParam(defaultValue = "") String petName,
            @RequestParam(defaultValue = "") String recordDate,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return healthRecordService.getHealthRecordByPage(petName, recordDate, currentPage, size);
    }

    /**
     * 根据id批量删除健康记录
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Long> ids) {
        return healthRecordService.deleteBatchByIds(ids);
    }

}
```

在对应服务层HealthRecordService中添加deleteBatchByIds抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.HealthRecord;

import java.util.List;

public interface HealthRecordService extends IService<HealthRecord> {
    Result getHealthRecordByPage(String petName, String recordDate, Integer currentPage, Integer size);

    Result deleteBatchByIds(List<Long> ids);
}
```

在对应实现类HealthRecordServiceImpl中重写deleteBatchByIds抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.HealthRecordDao;
import com.qf.entity.HealthRecord;
import com.qf.service.HealthRecordService;
import com.qf.vo.HealthRecordVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class HealthRecordServiceImpl extends ServiceImpl<HealthRecordDao, HealthRecord> implements HealthRecordService {

    @Autowired
    private HealthRecordDao healthRecordDao;

    @Override
    public Result getHealthRecordByPage(String petName, String recordDate, Integer currentPage, Integer size) {
        // 创建一个分页对象，设置当前页码和每页大小
        Page<HealthRecordVO> page = new Page<>(currentPage, size);
        // 根据宠物名称和记录日期从数据库中查询健康记录，并将结果存储到healthRecordPage中
        Page<HealthRecordVO> healthRecordPage = healthRecordDao.selectByPage(petName, recordDate, page);
        // 返回一个成功的结果，包含分页后的健康记录数据
        return Result.success(healthRecordPage);
    }

    @Override
    public Result deleteBatchByIds(List<Long> ids) {
        // 1. 参数校验
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }

        // 2. 执行批量删除（使用 MyBatis-Plus）
        int deletedCount = healthRecordDao.deleteBatchIds(ids);

        // 3. 判断结果并返回
        if (deletedCount > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "删除失败：未找到匹配的记录");
        }
    }

}
```

#### 5.3实现添加健康记录功能

在HealthRecordController中添加save方法，用于新增健康记录数据

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.HealthRecord;
import com.qf.service.HealthRecordService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/health-record")
public class HealthRecordController {

    @Autowired
    private HealthRecordService healthRecordService;


    /**
     * 获取健康记录列表
     * @param petName
     * @param recordDate
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getHealthRecordByPage(
            @RequestParam(defaultValue = "") String petName,
            @RequestParam(defaultValue = "") String recordDate,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return healthRecordService.getHealthRecordByPage(petName, recordDate, currentPage, size);
    }

    /**
     * 根据id批量删除健康记录
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Long> ids) {
        return healthRecordService.deleteBatchByIds(ids);
    }

    /**
     * 保存健康记录
     * @param healthRecord
     * @return
     */
    @RequestMapping("/save")
    public Result save(@RequestBody HealthRecord healthRecord) {
        return healthRecordService.addHealthRecord(healthRecord);
    }

}
```

在对应服务层HealthRecordService中添加addHealthRecord抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.HealthRecord;

import java.util.List;

public interface HealthRecordService extends IService<HealthRecord> {
    Result getHealthRecordByPage(String petName, String recordDate, Integer currentPage, Integer size);

    Result deleteBatchByIds(List<Long> ids);

    Result addHealthRecord(HealthRecord healthRecord);
}
```

在对应实现类HealthRecordServiceImpl中重写addHealthRecord抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.HealthRecordDao;
import com.qf.entity.HealthRecord;
import com.qf.service.HealthRecordService;
import com.qf.vo.HealthRecordVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class HealthRecordServiceImpl extends ServiceImpl<HealthRecordDao, HealthRecord> implements HealthRecordService {

    @Autowired
    private HealthRecordDao healthRecordDao;

    @Override
    public Result getHealthRecordByPage(String petName, String recordDate, Integer currentPage, Integer size) {
        // 创建一个分页对象，设置当前页码和每页大小
        Page<HealthRecordVO> page = new Page<>(currentPage, size);
        // 根据宠物名称和记录日期从数据库中查询健康记录，并将结果存储到healthRecordPage中
        Page<HealthRecordVO> healthRecordPage = healthRecordDao.selectByPage(petName, recordDate, page);
        // 返回一个成功的结果，包含分页后的健康记录数据
        return Result.success(healthRecordPage);
    }

    @Override
    public Result deleteBatchByIds(List<Long> ids) {
        // 1. 参数校验
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }

        // 2. 执行批量删除（使用 MyBatis-Plus）
        int deletedCount = healthRecordDao.deleteBatchIds(ids);

        // 3. 判断结果并返回
        if (deletedCount > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "删除失败：未找到匹配的记录");
        }
    }

    @Override
    public Result addHealthRecord(HealthRecord healthRecord) {
        // 参数校验
        if (healthRecord == null) {
            return Result.error("-1", "健康记录不能为空");
        }

        // 执行插入
        int inserted = healthRecordDao.insert(healthRecord);

        // 返回结果
        if (inserted > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "添加失败");
        }
    }

}
```

#### 5.4实现编辑健康记录功能

在HealthRecordController中添加updateById方法，用于修改健康记录数据

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.HealthRecord;
import com.qf.service.HealthRecordService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/health-record")
public class HealthRecordController {

    @Autowired
    private HealthRecordService healthRecordService;


    /**
     * 获取健康记录列表
     * @param petName
     * @param recordDate
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getHealthRecordByPage(
            @RequestParam(defaultValue = "") String petName,
            @RequestParam(defaultValue = "") String recordDate,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return healthRecordService.getHealthRecordByPage(petName, recordDate, currentPage, size);
    }

    /**
     * 根据id批量删除健康记录
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Long> ids) {
        return healthRecordService.deleteBatchByIds(ids);
    }

    /**
     * 保存健康记录
     * @param healthRecord
     * @return
     */
    @RequestMapping("/save")
    public Result save(@RequestBody HealthRecord healthRecord) {
        return healthRecordService.addHealthRecord(healthRecord);
    }


    /**
     * 根据id更新健康记录
     * @param healthRecord
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody HealthRecord healthRecord) {
        return healthRecordService.updateHealthRecord(healthRecord);
    }

}
```

在对应服务层HealthRecordService中添加updateHealthRecord抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.HealthRecord;

import java.util.List;

public interface HealthRecordService extends IService<HealthRecord> {
    Result getHealthRecordByPage(String petName, String recordDate, Integer currentPage, Integer size);

    Result deleteBatchByIds(List<Long> ids);

    Result addHealthRecord(HealthRecord healthRecord);

    Result updateHealthRecord(HealthRecord healthRecord);
}
```

在对应实现类HealthRecordServiceImpl中重写updateHealthRecord抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.HealthRecordDao;
import com.qf.entity.HealthRecord;
import com.qf.service.HealthRecordService;
import com.qf.vo.HealthRecordVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class HealthRecordServiceImpl extends ServiceImpl<HealthRecordDao, HealthRecord> implements HealthRecordService {

    @Autowired
    private HealthRecordDao healthRecordDao;

    @Override
    public Result getHealthRecordByPage(String petName, String recordDate, Integer currentPage, Integer size) {
        // 创建一个分页对象，设置当前页码和每页大小
        Page<HealthRecordVO> page = new Page<>(currentPage, size);
        // 根据宠物名称和记录日期从数据库中查询健康记录，并将结果存储到healthRecordPage中
        Page<HealthRecordVO> healthRecordPage = healthRecordDao.selectByPage(petName, recordDate, page);
        // 返回一个成功的结果，包含分页后的健康记录数据
        return Result.success(healthRecordPage);
    }

    @Override
    public Result deleteBatchByIds(List<Long> ids) {
        // 1. 参数校验
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }

        // 2. 执行批量删除（使用 MyBatis-Plus）
        int deletedCount = healthRecordDao.deleteBatchIds(ids);

        // 3. 判断结果并返回
        if (deletedCount > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "删除失败：未找到匹配的记录");
        }
    }

    @Override
    public Result addHealthRecord(HealthRecord healthRecord) {
        // 参数校验
        if (healthRecord == null) {
            return Result.error("-1", "健康记录不能为空");
        }

        // 执行插入
        int inserted = healthRecordDao.insert(healthRecord);

        // 返回结果
        if (inserted > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "添加失败");
        }
    }

    @Override
    public Result updateHealthRecord(HealthRecord healthRecord) {
        // 参数校验：对象和 ID 是否为空
        if (healthRecord == null || healthRecord.getId() == null) {
            return Result.error("-1", "健康记录或ID不能为空");
        }

        // 执行更新（MyBatis-Plus 根据 ID 更新非空字段）
        int updated = healthRecordDao.updateById(healthRecord);

        // 返回结果
        if (updated > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "更新失败：未找到对应记录");
        }
    }

}
```

#### 5.5根据宠物ID查询健康记录

在HealthRecordController中添加selectByPetId方法，根据宠物ID查询该宠物的所有健康记录

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.HealthRecord;
import com.qf.service.HealthRecordService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/health-record")
public class HealthRecordController {

    @Autowired
    private HealthRecordService healthRecordService;


    /**
     * 获取健康记录列表
     * @param petName
     * @param recordDate
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getHealthRecordByPage(
            @RequestParam(defaultValue = "") String petName,
            @RequestParam(defaultValue = "") String recordDate,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return healthRecordService.getHealthRecordByPage(petName, recordDate, currentPage, size);
    }

    /**
     * 根据id批量删除健康记录
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Long> ids) {
        return healthRecordService.deleteBatchByIds(ids);
    }

    /**
     * 保存健康记录
     * @param healthRecord
     * @return
     */
    @RequestMapping("/save")
    public Result save(@RequestBody HealthRecord healthRecord) {
        return healthRecordService.addHealthRecord(healthRecord);
    }


    /**
     * 根据id更新健康记录
     * @param healthRecord
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody HealthRecord healthRecord) {
        return healthRecordService.updateHealthRecord(healthRecord);
    }

    @RequestMapping("/selectByPetId/{id}")
    public Result selectByPetId(@PathVariable Long id) {
        // 只调用 Service，不写业务逻辑
        return healthRecordService.selectByPetId(id);
    }

}
```

在对应服务层HealthRecordService中添加selectByPetId抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.HealthRecord;

import java.util.List;

public interface HealthRecordService extends IService<HealthRecord> {
    Result getHealthRecordByPage(String petName, String recordDate, Integer currentPage, Integer size);

    Result deleteBatchByIds(List<Long> ids);

    Result addHealthRecord(HealthRecord healthRecord);

    Result updateHealthRecord(HealthRecord healthRecord);

    Result selectByPetId(Long id);
}
```

在对应实现类HealthRecordServiceImpl中重写selectByPetId抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.HealthRecordDao;
import com.qf.entity.HealthRecord;
import com.qf.service.HealthRecordService;
import com.qf.vo.HealthRecordVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class HealthRecordServiceImpl extends ServiceImpl<HealthRecordDao, HealthRecord> implements HealthRecordService {

    @Autowired
    private HealthRecordDao healthRecordDao;

    @Override
    public Result getHealthRecordByPage(String petName, String recordDate, Integer currentPage, Integer size) {
        // 创建一个分页对象，设置当前页码和每页大小
        Page<HealthRecordVO> page = new Page<>(currentPage, size);
        // 根据宠物名称和记录日期从数据库中查询健康记录，并将结果存储到healthRecordPage中
        Page<HealthRecordVO> healthRecordPage = healthRecordDao.selectByPage(petName, recordDate, page);
        // 返回一个成功的结果，包含分页后的健康记录数据
        return Result.success(healthRecordPage);
    }

    @Override
    public Result deleteBatchByIds(List<Long> ids) {
        // 1. 参数校验
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }

        // 2. 执行批量删除（使用 MyBatis-Plus）
        int deletedCount = healthRecordDao.deleteBatchIds(ids);

        // 3. 判断结果并返回
        if (deletedCount > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "删除失败：未找到匹配的记录");
        }
    }

    @Override
    public Result addHealthRecord(HealthRecord healthRecord) {
        // 参数校验
        if (healthRecord == null) {
            return Result.error("-1", "健康记录不能为空");
        }

        // 执行插入
        int inserted = healthRecordDao.insert(healthRecord);

        // 返回结果
        if (inserted > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "添加失败");
        }
    }

    @Override
    public Result updateHealthRecord(HealthRecord healthRecord) {
        // 参数校验：对象和 ID 是否为空
        if (healthRecord == null || healthRecord.getId() == null) {
            return Result.error("-1", "健康记录或ID不能为空");
        }

        // 执行更新（MyBatis-Plus 根据 ID 更新非空字段）
        int updated = healthRecordDao.updateById(healthRecord);

        // 返回结果
        if (updated > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "更新失败：未找到对应记录");
        }
    }

    @Override
    public Result selectByPetId(Long id) {
        // 根据宠物ID查询对应的所有健康记录
        QueryWrapper<HealthRecord> wrapper = new QueryWrapper<>();
        wrapper.eq("pet_id", id);
        List<HealthRecord> healthRecords = healthRecordDao.selectList(wrapper);
        return Result.success(healthRecords);
    }

}
```

## 十二. 实现宠物用品商城功能

### 1 实现订单管理功能

订单管理是商城模块的核心，涉及订单创建、状态流转（待支付→待发货→待自提→已完成）、余额支付、确认收货等完整业务流程。

首先在entity包下创建Orders实体类，对应数据库orders表

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.math.BigDecimal;
import java.sql.Timestamp;

@Data
@TableName("orders")
@NoArgsConstructor
@AllArgsConstructor
public class Orders {

    /**
     * 订单的唯一标识符，自增主键
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 订单编号，唯一字符串标识
     */
    private String orderNo;

    /**
     * 关联的商品（货品）ID
     */
    private Integer goodsId;

    /**
     * 商品购买数量
     */
    private Integer num;

    /**
     * 下单用户的ID，外键关联用户表
     */
    private Integer userId;

    /**
     * 订单状态，可取值：
     * - "Completed"：订单已完成
     * - "W_Ship"：待发货（等待物流处理）
     */
    private String status;

    /**
     * 订单创建时间，格式为 yyyy-MM-dd HH:mm:ss（东八区）
     */
    @JsonFormat(locale = "zh", timezone = "GMT+8", pattern = "yyyy-MM-dd HH:mm:ss")
    private Timestamp time;

    /**
     * 订单总金额，保留两位小数
     */
    @TableField(exist = false)
    private BigDecimal totalAmount;


}
```

创建OrdersVO视图对象，用于连表查询时承载订单、商品、用户的关联数据

```
package com.qf.vo;

import com.baomidou.mybatisplus.annotation.TableField;
import com.qf.entity.Orders;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;

import java.math.BigDecimal;

@EqualsAndHashCode(callSuper = false)
@Data
@NoArgsConstructor
@AllArgsConstructor
public class OrdersVO extends Orders {

    /**
     * 用户名（非数据库字段，用于前端展示）
     */
    @TableField(exist = false)
    private String username;

    /**
     * 商品名称（非数据库字段，用于关联查询展示）
     */
    @TableField(exist = false)
    private String goodsName;

    /**
     * 订单总金额（非数据库字段，通常由商品单价 × 数量计算得出）
     */
    @TableField(exist = false)
    private BigDecimal totalAmount;
}
```

#### 2.1查询订单列表数据

创建OrdersController在中添加getOrdersByPage方法。管理员可以查看所有订单，普通用户只能查看自己的订单

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Orders;
import com.qf.service.OrdersService;
import com.qf.vo.OrdersVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/orders")
public class OrdersController {

    @Autowired
    private OrdersService ordersService;

    /**
     * 查询订单列表数据
     * @param orderNo
     * @param goodsId
     * @param userId
     * @param userRole
     * @param goodsName
     * @param username
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getOrdersByPage(
        @RequestParam(defaultValue = "") String orderNo,
        @RequestParam(defaultValue = "") Integer goodsId,
        @RequestParam(defaultValue = "") Integer userId,
        @RequestParam(defaultValue = "") String userRole,
        @RequestParam(defaultValue = "") String goodsName,
        @RequestParam(defaultValue = "") String username,
        @RequestParam(defaultValue = "1") Integer currentPage,
        @RequestParam(defaultValue = "10") Integer size) {
        return ordersService.getOrdersByPage(orderNo, goodsId, userId, userRole, goodsName, username, currentPage, size);
    }

}
```

创建对应服务层OrdersService接口，添加getOrdersByPage抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Orders;


public interface OrdersService extends IService<Orders> {
    Result getOrdersByPage(String orderNo, Integer goodsId, Integer userId, String userRole, String goodsName, String username, Integer currentPage, Integer size);
}
```

在enums包下创建OrderStatus枚举类

```
package com.qf.enums;

public enum OrderStatus {
    W_Pay,       // 待支付
    W_Ship,      // 待发货
    W_Pickup,    // 待自提
    Completed    // 已完成
}
```

在对应实现类OrdersServiceImpl中重写getOrdersByPage抽象方法。根据用户角色决定查询范围：管理员可查看全部订单，普通用户仅查看自己的订单

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.OrdersDao;
import com.qf.dao.UserDao;
import com.qf.entity.Orders;
import com.qf.enums.UserRole;
import com.qf.service.OrdersService;
import com.qf.vo.OrdersVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


@Service
public class OrdersServiceImpl extends ServiceImpl<OrdersDao, Orders> implements OrdersService {


    // 注入 OrdersDao 对象
    @Autowired
    private  OrdersDao ordersDao;


    @Override
    public Result getOrdersByPage(String orderNo, Integer goodsId, Integer userId, String userRole, String goodsName, String username, Integer currentPage, Integer size) {

        // 根据用户角色决定是否限制 userId 查询
        Integer searchUserId = userId;
        if (!UserRole.USER.toString().equals(userRole)) {
            searchUserId = 0; // 非普通用户时，userId 设为 0
        }
        // 构建分页对象
        Page<OrdersVO> page = new Page<>(currentPage, size);
        // 执行数据库查询
        Page<OrdersVO> resultPage = ordersDao.selectOrdersByPage(
                page, orderNo, goodsId, searchUserId, goodsName, username
        );
        // 返回成功结果
        return Result.success(resultPage);
    }

}
```

创建OrdersDao接口，包含自定义的关联查询方法和按订单号查询方法

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.qf.entity.Orders;
import com.qf.vo.OrdersVO;
import org.apache.ibatis.annotations.Param;

public interface OrdersDao extends BaseMapper<Orders> {
    Page<OrdersVO> selectOrdersByPage(Page<OrdersVO> page,
                                      @Param("orderNo") String orderNo,
                                      @Param("goodsId") Integer goodsId,
                                      @Param("userId") Integer userId,
                                      @Param("goodsName") String goodsName,
                                      @Param("userName") String username);


}
```

在resources/mapper目录下创建OrdersDao.xml，编写多表关联查询SQL

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.qf.dao.OrdersDao">


    <!-- 定义resultMap来映射查询结果 -->
    <resultMap id="OrdersResultMapper" type="com.qf.vo.OrdersVO">
        <result property="username" column="username"/>
        <result property="goodsName" column="goodsName"/>
    </resultMap>

    <select id="selectOrdersByPage" resultType="com.qf.vo.OrdersVO">
        <!-- 选择订单表中的所有字段，以及用户表中的用户名字段，重命名为userName，以及商品表中的名称字段，重命名为goodsName，同时计算订单数量乘以商品数量作为totalAmount -->
        SELECT o.*, u.username AS userName, g.name AS goodsName,o.num * g.num AS totalAmount
        FROM orders o
        <!-- 从订单表开始，左连接用户表，条件是订单表中的user_id等于用户表中的id -->
        LEFT JOIN user u ON o.user_id = u.id
        <!-- 左连接商品表，条件是订单表中的goods_id等于商品表中的id -->
        LEFT JOIN goods g ON o.goods_id = g.id
        <!-- 过滤条件：订单号包含指定的orderNo值，如果orderNo为空，则匹配所有订单号 -->
        WHERE o.order_no LIKE CONCAT('%', IFNULL(#{orderNo}, ''), '%')
        <!-- 若goodsId为空，则不加入WHERE条件 -->
        AND (o.goods_id = IFNULL(#{goodsId}, o.goods_id) OR #{goodsId} IS NULL)
        <!-- 过滤条件：如果userId不等于0，则只匹配userId对应的订单，如果userId为空或等于0，则不加入此条件 -->
        AND (o.user_id = IF(#{userId} != 0, #{userId}, o.user_id) OR #{userId} IS NULL)
        <!-- 过滤条件：用户名包含指定的userName值，如果userName为空，则匹配所有用户名 -->
        AND u.username LIKE CONCAT('%', IFNULL(#{userName}, ''), '%')
        <!-- 过滤条件：商品名称包含指定的goodsName值，如果goodsName为空，则匹配所有商品名称 -->
        AND g.name LIKE CONCAT('%', IFNULL(#{goodsName}, ''), '%')
        <!-- 过滤条件：如果userId不为空，则只匹配userId对应的订单，如果userId为空或等于0，则不加入此条件 -->
        AND (o.user_id = #{userId} OR #{userId} IS NULL OR #{userId} = 0)
    </select>

</mapper>
```

#### 2.2实现批量删除订单功能

在OrdersController中添加deleteBatch方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Orders;
import com.qf.service.OrdersService;
import com.qf.vo.OrdersVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/orders")
public class OrdersController {

    @Autowired
    private OrdersService ordersService;

    /**
     * 查询订单列表数据
     * @param orderNo
     * @param goodsId
     * @param userId
     * @param userRole
     * @param goodsName
     * @param username
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getOrdersByPage(
            @RequestParam(defaultValue = "") String orderNo,
            @RequestParam(defaultValue = "") Integer goodsId,
            @RequestParam(defaultValue = "") Integer userId,
            @RequestParam(defaultValue = "") String userRole,
            @RequestParam(defaultValue = "") String goodsName,
            @RequestParam(defaultValue = "") String username,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return ordersService.getOrdersByPage(orderNo, goodsId, userId, userRole, goodsName, username, currentPage, size);
    }

    /**
     * 根据id批量删除订单
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return ordersService.deleteBatchOrders(ids);
    }

}
```

在OrdersService中添加deleteBatchOrders抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Orders;

import java.util.List;


public interface OrdersService extends IService<Orders> {
    Result getOrdersByPage(String orderNo, Integer goodsId, Integer userId, String userRole, String goodsName, String username, Integer currentPage, Integer size);

    Result deleteBatchOrders(List<Integer> ids);
}
```

在OrdersServiceImpl中实现deleteBatchOrders抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.OrdersDao;
import com.qf.dao.UserDao;
import com.qf.entity.Orders;
import com.qf.enums.UserRole;
import com.qf.service.OrdersService;
import com.qf.vo.OrdersVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;


@Service
public class OrdersServiceImpl extends ServiceImpl<OrdersDao, Orders> implements OrdersService {


    // 注入 OrdersDao 对象
    @Autowired
    private  OrdersDao ordersDao;


    @Override
    public Result getOrdersByPage(String orderNo, Integer goodsId, Integer userId, String userRole, String goodsName, String username, Integer currentPage, Integer size) {

        // 根据用户角色决定是否限制 userId 查询
        Integer searchUserId = userId;
        if (!UserRole.USER.toString().equals(userRole)) {
            searchUserId = 0; // 非普通用户时，userId 设为 0
        }
        // 构建分页对象
        Page<OrdersVO> page = new Page<>(currentPage, size);
        // 执行数据库查询
        Page<OrdersVO> resultPage = ordersDao.selectOrdersByPage(
            page, orderNo, goodsId, searchUserId, goodsName, username
        );
        // 返回成功结果
        return Result.success(resultPage);
    }

    @Override
    public Result deleteBatchOrders(List<Integer> ids) {
        //调用BaseMapper中的deleteBatchIds方法批量删除
        int res = ordersDao.deleteBatchIds(ids);
        //判断是否删除成功
        if (res > 0) {
            //返回成功结果
            return Result.success();
        } else {
            //返回失败结果
            return Result.error("-1", "删除失败");
        }
    }

}
```

#### 2.3实现修改订单状态（发货）功能

管理员可以通过此接口将订单状态改为"待自提"（W_Pickup），表示商品已发货

在OrdersController中添加updateOrder方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Orders;
import com.qf.service.OrdersService;
import com.qf.vo.OrdersVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Map;

@RestController
@RequestMapping("/orders")
public class OrdersController {

    @Autowired
    private OrdersService ordersService;

    /**
     * 查询订单列表数据
     * @param orderNo
     * @param goodsId
     * @param userId
     * @param userRole
     * @param goodsName
     * @param username
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getOrdersByPage(
            @RequestParam(defaultValue = "") String orderNo,
            @RequestParam(defaultValue = "") Integer goodsId,
            @RequestParam(defaultValue = "") Integer userId,
            @RequestParam(defaultValue = "") String userRole,
            @RequestParam(defaultValue = "") String goodsName,
            @RequestParam(defaultValue = "") String username,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return ordersService.getOrdersByPage(orderNo, goodsId, userId, userRole, goodsName, username, currentPage, size);
    }

    /**
     * 根据id批量删除订单
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return ordersService.deleteBatchOrders(ids);
    }

    /**
     * 根据id修改发货状态
     * @param order
     * @return
     */
    @RequestMapping("/update")
    public Result updateOrder(@RequestBody Orders order) {
        return ordersService.updateOrder(order);
    }
}
```

在OrdersService中添加updateOrder抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Orders;

import java.util.List;


public interface OrdersService extends IService<Orders> {
    Result getOrdersByPage(String orderNo, Integer goodsId, Integer userId, String userRole, String goodsName, String username, Integer currentPage, Integer size);

    Result deleteBatchOrders(List<Integer> ids);

    Result updateOrder(Orders order);
}
```

在对应实现类OrdersServiceImpl中实现updateOrder方法，对订单状态做合法性校验

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.enums.OrderStatus;
import com.qf.utils.Result;
import com.qf.dao.OrdersDao;
import com.qf.dao.UserDao;
import com.qf.entity.Orders;
import com.qf.enums.UserRole;
import com.qf.service.OrdersService;
import com.qf.vo.OrdersVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;


@Service
public class OrdersServiceImpl extends ServiceImpl<OrdersDao, Orders> implements OrdersService {


    // 注入 OrdersDao 对象
    @Autowired
    private  OrdersDao ordersDao;


    @Override
    public Result getOrdersByPage(String orderNo, Integer goodsId, Integer userId, String userRole, String goodsName, String username, Integer currentPage, Integer size) {

        // 根据用户角色决定是否限制 userId 查询
        Integer searchUserId = userId;
        if (!UserRole.USER.toString().equals(userRole)) {
            searchUserId = 0; // 非普通用户时，userId 设为 0
        }
        // 构建分页对象
        Page<OrdersVO> page = new Page<>(currentPage, size);
        // 执行数据库查询
        Page<OrdersVO> resultPage = ordersDao.selectOrdersByPage(
            page, orderNo, goodsId, searchUserId, goodsName, username
        );
        // 返回成功结果
        return Result.success(resultPage);
    }

    @Override
    public Result deleteBatchOrders(List<Integer> ids) {
        //调用BaseMapper中的deleteBatchIds方法批量删除
        int res = ordersDao.deleteBatchIds(ids);
        //判断是否删除成功
        if (res > 0) {
            //返回成功结果
            return Result.success();
        } else {
            //返回失败结果
            return Result.error("-1", "删除失败");
        }
    }

    @Override
    public Result updateOrder(Orders order) {
        // 根据订单 ID 查询订单
        Orders newOrders = ordersDao.selectById(order.getId());
        // 获取订单状态
        String status = order.getStatus();
        // 判断订单状态是否合法
        if (status == null) {
            return Result.error("-1", "订单状态不能为空");
        }

        try {
            // 将字符串转为枚举，校验是否为合法状态值
            OrderStatus.valueOf(status);
        } catch (IllegalArgumentException e) {
            return Result.error("-1", "订单状态错误：" + status);
        }
        // 判断订单是否存在
        if (newOrders == null) {
            return Result.error("-1", "订单不存在");
        }
        // 更新订单状态
        newOrders.setStatus(order.getStatus());
        // 更新订单信息
        int res = ordersDao.updateById(newOrders);
        // 判断是否更新成功
        if (res > 0) {
            // 返回成功结果
            return Result.success(order);
        } else {
            // 返回失败结果
            return Result.error("-1", "更新失败");
        }
    }

}
```

### 2 实现商品管理功能

商品管理模块用于管理商城中的宠物用品。首先创建Goods实体类，对应数据库goods表

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("goods")
public class Goods {

    /** 主键ID，自增 */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /** 商品名称 */
    private String name;

    /** 商品图片路径 */
    private String img;

    /** 商品描述 */
    private String desrc;

    /** 商品价格 */
    private Double price;

    /** 库存数量 */
    private Integer num;
}
```

#### 1.1查询商品列表数据

在GoodsController中添加getGoodsByPage方法，支持按名称模糊查询和分页

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Goods;
import com.qf.service.GoodsService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/goods")
public class GoodsController {

    @Autowired
    private GoodsService goodsService;


    /**
     * 获取商品列表数据
     * @param name
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getGoodsByPage(
        @RequestParam(defaultValue = "") String name,
        @RequestParam(defaultValue = "1") Integer currentPage,
        @RequestParam(defaultValue = "10") Integer size) {
        //调用service层方法获取商品列表数据
        return goodsService.getGoodsByPage(name, currentPage, size);
    }

}
```

创建对应服务层GoodsService接口，添加getGoodsByPage抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Goods;

import java.util.List;

public interface GoodsService extends IService<Goods> {
    Result getGoodsByPage(String name, Integer currentPage, Integer size);
}
```

在对应实现类GoodsServiceImpl中重写getGoodsByPage抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.GoodsDao;
import com.qf.entity.Goods;
import com.qf.service.GoodsService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class GoodsServiceImpl extends ServiceImpl<GoodsDao, Goods> implements GoodsService {

    //注入GoodsDao
    @Autowired
    private GoodsDao goodsDao;


    @Override
    public Result getGoodsByPage(String name, Integer currentPage, Integer size) {

        // 构建分页对象
        Page<Goods> page = new Page<>(currentPage, size);
        // 构建动态查询条件
        LambdaQueryWrapper<Goods> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(name)) {
            queryWrapper.like(Goods::getName, name);
        }
        // 执行分页查询
        Page<Goods> goodsPage = goodsDao.selectPage(page, queryWrapper);
        // 返回成功结果
        return Result.success(goodsPage);
    }

}
```

创建对应dao层GoodsDao接口，继承BaseMapper即可使用MyBatis-Plus提供的基础CRUD方法，无需额外编写自定义SQL

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.Goods;

public interface GoodsDao extends BaseMapper<Goods> {
}
```

#### 1.2实现批量删除商品功能

在GoodsController中添加deleteBatch方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Goods;
import com.qf.service.GoodsService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/goods")
public class GoodsController {

    @Autowired
    private GoodsService goodsService;


    /**
     * 获取商品列表数据
     * @param name
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getGoodsByPage(
        @RequestParam(defaultValue = "") String name,
        @RequestParam(defaultValue = "1") Integer currentPage,
        @RequestParam(defaultValue = "10") Integer size) {
        //调用service层方法获取商品列表数据
        return goodsService.getGoodsByPage(name, currentPage, size);
    }

    /**
     * 根据id批量删除商品
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return goodsService.deleteBatchGoods(ids);
    }

}
```

在对应服务层GoodsService中添加deleteBatchGoods抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Goods;

import java.util.List;

public interface GoodsService extends IService<Goods> {
    Result getGoodsByPage(String name, Integer currentPage, Integer size);

    Result deleteBatchGoods(List<Integer> ids);
}
```

在对应实现类GoodsServiceImpl中重写deleteBatchGoods抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.GoodsDao;
import com.qf.entity.Goods;
import com.qf.service.GoodsService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class GoodsServiceImpl extends ServiceImpl<GoodsDao, Goods> implements GoodsService {

    //注入GoodsDao
    @Autowired
    private GoodsDao goodsDao;


    @Override
    public Result getGoodsByPage(String name, Integer currentPage, Integer size) {
        // 构建分页对象
        Page<Goods> page = new Page<>(currentPage, size);
        // 构建动态查询条件
        LambdaQueryWrapper<Goods> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(name)) {
            queryWrapper.like(Goods::getName, name);
        }
        // 执行分页查询
        Page<Goods> goodsPage = goodsDao.selectPage(page, queryWrapper);
        // 返回成功结果
        return Result.success(goodsPage);
    }

    @Override
    public Result deleteBatchGoods(List<Integer> ids) {

        // 参数校验
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "商品ID列表不能为空");
        }

        // 调用BaseMapper的deleteBatchIds方法批量删除商品
        int deletedCount = goodsDao.deleteBatchIds(ids);

        // 判断结果与参数列表长度是否一致
        if (deletedCount == ids.size()) {
            // 全部删除成功
            return Result.success();
            // 部分成功
        } else if (deletedCount > 0) {
            // 部分成功（有些 ID 不存在）
            return Result.error("-1", "部分商品不存在，仅删除 " + deletedCount + " 条");
        } else {
            // 全部失败（所有 ID 都不存在）
            return Result.error("-1", "未找到要删除的商品");
        }
    }

}
```

#### 1.3实现添加商品功能

在GoodsController中添加save方法，用于新增商品数据。注意：商品图片需要先通过文件上传接口获取图片路径后再提交

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Goods;
import com.qf.service.GoodsService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/goods")
public class GoodsController {

    @Autowired
    private GoodsService goodsService;


    /**
     * 获取商品列表数据
     * @param name
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getGoodsByPage(
        @RequestParam(defaultValue = "") String name,
        @RequestParam(defaultValue = "1") Integer currentPage,
        @RequestParam(defaultValue = "10") Integer size) {
        //调用service层方法获取商品列表数据
        return goodsService.getGoodsByPage(name, currentPage, size);
    }

    /**
     * 根据id批量删除商品
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return goodsService.deleteBatchGoods(ids);
    }

    /**
     * 保存商品信息
     * @param goods
     * @return
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Goods goods) {
        return goodsService.saveGoods(goods);
    }

}
```

在对应服务层GoodsService中添加saveGoods抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Goods;

import java.util.List;

public interface GoodsService extends IService<Goods> {
    Result getGoodsByPage(String name, Integer currentPage, Integer size);

    Result deleteBatchGoods(List<Integer> ids);

    Result saveGoods(Goods goods);
}
```

在对应实现类中重写saveGoods抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.GoodsDao;
import com.qf.entity.Goods;
import com.qf.service.GoodsService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class GoodsServiceImpl extends ServiceImpl<GoodsDao, Goods> implements GoodsService {

    //注入GoodsDao
    @Autowired
    private GoodsDao goodsDao;


    @Override
    public Result getGoodsByPage(String name, Integer currentPage, Integer size) {
        // 构建分页对象
        Page<Goods> page = new Page<>(currentPage, size);
        // 构建动态查询条件
        LambdaQueryWrapper<Goods> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(name)) {
            queryWrapper.like(Goods::getName, name);
        }
        // 执行分页查询
        Page<Goods> goodsPage = goodsDao.selectPage(page, queryWrapper);
        // 返回成功结果
        return Result.success(goodsPage);
    }

    @Override
    public Result deleteBatchGoods(List<Integer> ids) {

        // 参数校验
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "商品ID列表不能为空");
        }

        // 调用BaseMapper的deleteBatchIds方法批量删除商品
        int deletedCount = goodsDao.deleteBatchIds(ids);

        // 判断结果与参数列表长度是否一致
        if (deletedCount == ids.size()) {
            // 全部删除成功
            return Result.success();
            // 部分成功
        } else if (deletedCount > 0) {
            // 部分成功（有些 ID 不存在）
            return Result.error("-1", "部分商品不存在，仅删除 " + deletedCount + " 条");
        } else {
            // 全部失败（所有 ID 都不存在）
            return Result.error("-1", "未找到要删除的商品");
        }
    }

    @Override
    public Result saveGoods(Goods goods) {
        // 参数校验
        if (goods == null) {
            return Result.error("-1", "商品信息不能为空");
        }
        // 执行插入（MyBatis-Plus 自动填充 id 等字段）
        int inserted = goodsDao.insert(goods);

        // 判断结果
        if (inserted > 0) {
            // 插入成功
            return Result.success(goods); // 返回带 ID 的实体更友好
        } else {
            // 插入失败
            return Result.error("-1", "添加失败");
        }
    }
}
```

#### 1.4实现编辑商品功能

在GoodsController中添加updateById方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Goods;
import com.qf.service.GoodsService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/goods")
public class GoodsController {

    @Autowired
    private GoodsService goodsService;


    /**
     * 获取商品列表数据
     * @param name
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getGoodsByPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        //调用service层方法获取商品列表数据
        return goodsService.getGoodsByPage(name, currentPage, size);
    }

    /**
     * 根据id批量删除商品
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return goodsService.deleteBatchGoods(ids);
    }

    /**
     * 保存商品信息
     * @param goods
     * @return
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Goods goods) {
        return goodsService.saveGoods(goods);
    }

    /**
     * 根据id更新商品信息
     * @param goods
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody Goods goods) {
        return goodsService.updateGoods(goods);
    }

}
```

在对应服务层GoodsService中添加updateGoods抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Goods;

import java.util.List;

public interface GoodsService extends IService<Goods> {
    Result getGoodsByPage(String name, Integer currentPage, Integer size);

    Result deleteBatchGoods(List<Integer> ids);

    Result saveGoods(Goods goods);

    Result updateGoods(Goods goods);
}
```

在对应实现类GoodsServiceImpl中重写updateGoods抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.GoodsDao;
import com.qf.entity.Goods;
import com.qf.service.GoodsService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class GoodsServiceImpl extends ServiceImpl<GoodsDao, Goods> implements GoodsService {

    //注入GoodsDao
    @Autowired
    private GoodsDao goodsDao;


    @Override
    public Result getGoodsByPage(String name, Integer currentPage, Integer size) {
        // 构建分页对象
        Page<Goods> page = new Page<>(currentPage, size);
        // 构建动态查询条件
        LambdaQueryWrapper<Goods> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(name)) {
            queryWrapper.like(Goods::getName, name);
        }
        // 执行分页查询
        Page<Goods> goodsPage = goodsDao.selectPage(page, queryWrapper);
        // 返回成功结果
        return Result.success(goodsPage);
    }

    @Override
    public Result deleteBatchGoods(List<Integer> ids) {

        // 参数校验
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "商品ID列表不能为空");
        }

        // 调用BaseMapper的deleteBatchIds方法批量删除商品
        int deletedCount = goodsDao.deleteBatchIds(ids);

        // 判断结果与参数列表长度是否一致
        if (deletedCount == ids.size()) {
            // 全部删除成功
            return Result.success();
            // 部分成功
        } else if (deletedCount > 0) {
            // 部分成功（有些 ID 不存在）
            return Result.error("-1", "部分商品不存在，仅删除 " + deletedCount + " 条");
        } else {
            // 全部失败（所有 ID 都不存在）
            return Result.error("-1", "未找到要删除的商品");
        }
    }

    @Override
    public Result saveGoods(Goods goods) {
        // 参数校验
        if (goods == null) {
            return Result.error("-1", "商品信息不能为空");
        }
        // 执行插入（MyBatis-Plus 自动填充 id 等字段）
        int inserted = goodsDao.insert(goods);

        // 判断结果
        if (inserted > 0) {
            // 插入成功
            return Result.success(goods); // 返回带 ID 的实体更友好
        } else {
            // 插入失败
            return Result.error("-1", "添加失败");
        }
    }

    @Override
    public Result updateGoods(Goods goods) {
        // 参数校验
        if (goods == null || goods.getId() == null) {
            return Result.error("-1", "商品ID不能为空");
        }
        //调用BaseMapper的updateById方法更新商品
        int updated = goodsDao.updateById(goods);
        //判断结果
        if (updated > 0) {
            //更新成功
            return Result.success();
        } else {
            //更新失败
            return Result.error("-1", "更新失败：商品可能不存在或未修改任何字段");
        }
    }
}
```

## 十三. 实现系统管理功能

系统管理模块是管理员后台的核心，包括通知公告管理、用户管理、首页轮播图管理、消息推送管理和菜单管理等功能。

### 1 实现通知公告管理

通知公告用于向所有用户发布系统消息。首先在entity包下创建Notice实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("notice")
public class Notice {

    /**
     * 自增主键
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 通知标题
     */
    private String title;

    /**
     * 通知内容
     */
    private String content;

    /**
     * 发布时间
     * @JsonFormat注解用于格式化日期，locale为中文，timezone为东八区，pattern为日期格式
     */
    @JsonFormat(locale = "zh", timezone = "GMT+8", pattern = "yyyy-MM-dd HH:mm")
    private Date time;
}
```

在controller包下创建NoticeController

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Notice;
import com.qf.service.NoticeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/notice")
public class NoticeController {

    @Autowired
    private NoticeService noticeService;

    /**
     * 分页查询通知列表
     * @param title 通知标题（可选，模糊查询）
     * @param currentPage 当前页码
     * @param size 每页条数
     */
    @RequestMapping("/page")
    public Result getNoticesByPage(
        @RequestParam(defaultValue = "") String title,
        @RequestParam(defaultValue = "1") Integer currentPage,
        @RequestParam(defaultValue = "10") Integer size) {
        return noticeService.getNoticesByPage(title, currentPage, size);
    }

    /**
     * 批量删除通知
     * @param ids 要删除的通知ID列表
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return noticeService.deleteBatch(ids);
    }

    /**
     * 保存通知
     * @param notice 通知实体（JSON格式请求体）
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Notice notice) {
        return noticeService.saveNotice(notice);
    }

    /**
     * 修改通知
     * @param notice 通知实体（JSON格式请求体，必须包含id）
     */
    @RequestMapping("/update")
    public Result update(@RequestBody Notice notice) {
        return noticeService.updateNotice(notice);
    }

    /**
     * 获取最新通知列表（前台展示用）
     * @param count 获取数量，默认10条
     */
    @RequestMapping("/limit")
    public Result getLatestNotices(@RequestParam(defaultValue = "10") Integer count) {
        return noticeService.getLatestNotices(count);
    }
}
```

创建NoticeService接口，定义通知业务的核心方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Notice;

import java.util.List;

public interface NoticeService extends IService<Notice> {
    Result getNoticesByPage(String title, Integer currentPage, Integer size);

    Result deleteBatch(List<Integer> ids);

    Result saveNotice(Notice notice);

    Result updateNotice(Notice notice);

    Result getLatestNotices(Integer count);
}
```

创建NoticeServiceImpl实现类，所有业务逻辑在此层处理

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.NoticeDao;
import com.qf.entity.Notice;
import com.qf.service.NoticeService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class NoticeServiceImpl extends ServiceImpl<NoticeDao, Notice> implements NoticeService {

    @Autowired
    private NoticeDao noticeDao;

    @Override
    public Result getNoticesByPage(String title, Integer currentPage, Integer size) {
        // 创建LambdaQueryWrapper条件构造器
        LambdaQueryWrapper<Notice> wrapper = new LambdaQueryWrapper<>();
        // 判断是否有标题条件
        if (StringUtils.isNotBlank(title)) {
            // 标题模糊查询
            wrapper.like(Notice::getTitle, title);
        }
        // 设置分页条件
        Page<Notice> page = new Page<>(currentPage, size);
        // 执行分页查询
        Page<Notice> resultPage = noticeDao.selectPage(page, wrapper);
        // 返回分页结果
        return Result.success(resultPage);
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        // 判断是否有ID列表
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }
        // 调用Mybatis-Plus批量删除方法
        int deletedCount = noticeDao.deleteBatchIds(ids);
        // 判断是否删除成功
        if (deletedCount > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "删除失败：未找到对应的通知记录");
        }
    }

    @Override
    public Result saveNotice(Notice notice) {
        // 判断通知内容是否为空
        if (notice == null) {
            return Result.error("-1", "通知内容不能为空");
        }
        // 调用Mybatis-Plus保存方法
        int inserted = noticeDao.insert(notice);
        // 判断是否保存成功
        if (inserted > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "新增失败");
        }
    }

    @Override
    public Result updateNotice(Notice notice) {
        // 判断通知ID是否为空
        if (notice == null || notice.getId() == null) {
            return Result.error("-1", "通知ID不能为空");
        }
        // 调用Mybatis-Plus根据ID更新方法
        int updated = noticeDao.updateById(notice);
        // 判断是否更新成功
        if (updated > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "修改失败：通知可能不存在或未修改任何字段");
        }
    }

    @Override
    public Result getLatestNotices(Integer count) {
        // 构造分页对象：第1页，每页 count 条
        Page<Notice> page = new Page<>(1, count);
        // 按 time 字段倒序（由近到远）
        QueryWrapper<Notice> queryWrapper = new QueryWrapper<>();
        queryWrapper.orderByDesc("time");
        // 执行分页查询
        Page<Notice> resultPage = this.page(page, queryWrapper);
        List<Notice> notices = resultPage.getRecords();
        return Result.success(notices);
    }
}
```

创建NoticeDao接口

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.Notice;

public interface NoticeDao extends BaseMapper<Notice> {
}
```

### 2 实现用户管理功能

管理员可以通过用户管理模块查看所有用户、搜索用户、批量删除用户以及给用户充值余额。这些接口在之前的UserController基础上扩展

在UserController中添加管理员专用的getUsersByPage、deleteBatch、searchUsers和rechargeUserBalance方法

```
package com.qf.controller;

import com.qf.entity.UserPasswordUpdate;
import com.qf.utils.Result;
import com.qf.entity.User;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Map;

//这里的RestController注解表示，该类下的所有方法都可以直接返回json数据(其实就是@Controller和@ResponseBody的组合)
@RestController
//这里的RequestMapping注解表示，该类下的所有方法都可以被映射到/user路径下
@RequestMapping("/user")
public class UserController {

    //注入UserService
    @Autowired
    private UserService userService;

    //这里的RequestMapping注解表示，该方法可以被映射到/login路径下
    @RequestMapping("/login")
    //@RequestBodys注解表示，该方法的入参是json格式的请求体
    public Result login(@RequestBody User user) {
        //调用service层处理登录逻辑
        Result login = userService.login(user);
        //返回结果
        return login;
    }



    /**
     * 注册用户
     * @param user
     * @return
     */
    @RequestMapping
    public Result createUser(@RequestBody User user) {
        return userService.createUser(user);
    }


    /**
     * 根据用户id添加/更新个人信息
     * @param id
     * @param user
     * @return
     */
    @RequestMapping("/{id}")
    public Result updateUser(@PathVariable Integer id, @RequestBody User user) {
        return userService.updateUser(id, user);
    }


    /**
     * 忘记密码功能
     * @param email
     * @param newPassword
     * @return
     */
    @RequestMapping("/forget")
    public Result forgetPassword(
            @RequestParam(defaultValue = "") String email,
            @RequestParam(defaultValue = "") String newPassword) {
        return userService.forgetPassword(email, newPassword);
    }

    @RequestMapping("/password/{id}")
    public Result updatePassword(
            @PathVariable Integer id,
            @RequestBody UserPasswordUpdate userPasswordUpdate) {
        return userService.updatePassword(id, userPasswordUpdate);
    }

    /**
     * 分页查询用户列表（管理员）
     */
    @RequestMapping("/page")
    public Result getUsersByPage(
            @RequestParam(defaultValue = "") String username,
            @RequestParam(defaultValue = "") String sex,
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "") String role,
            @RequestParam(defaultValue = "") String currentRole,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return userService.getUsersByPage(username, sex, name, role, currentRole, currentPage, size);
    }

    /**
     * 批量删除用户（管理员）
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return userService.deleteBatch(ids);
    }

    /**
     * 搜索用户（根据用户名或姓名）
     */
    @GetMapping("/search")
    public Result searchUsers(@RequestParam(required = false) String username,
                              @RequestParam(defaultValue = "10") Integer limit) {
        return userService.searchUsersByUsernameOrName(username, limit);
    }

    /**
     * 为用户充值余额
     */
    @RequestMapping("/recharge")
    public Result rechargeUserBalance(@RequestBody Map<String, Object> params) {
        return userService.rechargeBalance(params);
    }
}
```

对应UserService接口

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.User;
import com.qf.entity.UserPasswordUpdate;

import java.util.List;
import java.util.Map;

public interface UserService extends IService<User> {

    Result login(User user);

    Result createUser(User user);

    Result updateUser(Integer id, User user);

    Result forgetPassword(String email, String newPassword);

    Result updatePassword(Integer id, UserPasswordUpdate userPasswordUpdate);

    Result getUsersByPage(String username, String sex, String name, String role, String currentRole, Integer currentPage, Integer size);

    Result deleteBatch(List<Integer> ids);

    Result searchUsersByUsernameOrName(String username, Integer limit);

    Result rechargeBalance(Map<String, Object> params);
}
```

对应UserServiceImpl实现类

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.MenuDao;
import com.qf.dao.UserDao;
import com.qf.entity.Menu;
import com.qf.entity.User;
import com.qf.entity.UserPasswordUpdate;
import com.qf.enums.UserRole;
import com.qf.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@Service
public class UserServiceImpl extends ServiceImpl<UserDao, User> implements UserService {

    // 注入UserDao
    @Autowired
    private UserDao userDao;

    //注入MenuDao
    @Autowired
    private MenuDao menuDao;

    @Value("${user.defaultPassword}")
    private String DEFAULT_PWD;


    @Override
    public Result login(User user) {
        // 创建LambdaQueryWrapper对象，用于构建查询条件
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        // 设置查询条件，查询用户名等于传入用户对象的用户名

        //eq方法为"="方法的简化写法,User::getUsername为lambda表达式,作用是获取User表的字段名username
        queryWrapper.eq(User::getUsername, user.getUsername());
        // 根据查询条件从数据库中查询用户信息
        User loginUser = userDao.selectOne(queryWrapper);
        // 如果查询结果为空，返回错误信息，提示用户不存在
        if (loginUser == null) {
            return Result.error("-1", "登录失败，用户不存在！");
        }
        // 初始化UserRole对象，用于存储查询到的用户角色
        UserRole loginRole = null;
        // 获取用户的角色信息
        String role = loginUser.getRole();
        // 根据角色信息设置对应的UserRole对象
        if (role.equals(UserRole.USER.getValue())) {
            loginRole = UserRole.USER;
        } else if (role.equals(UserRole.ADMIN.getValue())) {
            loginRole = UserRole.ADMIN;
        } else if (role.equals(UserRole.SUPER_ADMIN.getValue())) {
            loginRole = UserRole.SUPER_ADMIN;
        } else {
            // 如果角色信息不匹配任何已知角色，返回错误信息，提示角色信息异常
            return Result.error("-1", "登陆失败，角色信息异常");
        }
        // 如果用户角色ID不等于3（3为SUPER_ADMIN）
        if (loginRole.getId() != 3) {
            // 根据角色ID和3查询菜单列表
            // 查询角色为 roleId 或3 的菜单列表
            List<Menu> roleMenuList = menuDao.selectList(
                    new LambdaQueryWrapper<Menu>()
                            //in 方法用于查询 Menu 表中 role 字段的值等于 loginRole.getId() 或者 3 的所有记录
                            .in(Menu::getRole, Arrays.asList(loginRole.getId(), 3))
            );
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            // 作用:筛选集合中父菜单 ID（pid）为空的菜单作为一级父菜单,并转换为集合
            //stream() 方法用于将集合转换为流，filter 方法用于过滤集合，toList() 方法用于将流转换为集合
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                //collect是收集器
                //Collectors.toList()是转换器
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        } else {
            // 如果用户角色ID等于3，查询所有菜单列表
            // 查询所有菜单列表
            List<Menu> roleMenuList = menuDao.selectList(null);
            // 获取一级菜单列表（父菜单ID为空的菜单）
            // 一级菜单
            List<Menu> parentList = roleMenuList.stream().filter(menu -> menu.getPid() == null).toList();
            // 遍历一级菜单列表，为每个一级菜单设置其对应的子菜单列表
            for (Menu parentMenu : parentList) {
                // 根据父菜单ID查询子菜单列表
                List<Menu> childrenList = roleMenuList.stream().filter(menu -> parentMenu.getId().equals(menu.getPid())).collect(Collectors.toList());
                // 将子菜单列表设置为一级菜单的子菜单
                parentMenu.setChildren(childrenList);
            }
            // 将菜单列表设置到用户对象中
            loginUser.setMenuList(roleMenuList);
        }

        // 验证用户密码是否匹配
        // 如果传入的用户密码与数据库中查询到的用户密码匹配
        if (user.getPassword().equals(loginUser.getPassword())) {
            // 返回成功信息，包含用户对象
            return Result.success(loginUser);
        } else {
            // 返回错误信息，提示用户名或密码错误
            return Result.error("-1", "登录失败，用户名或密码错误！");
        }
    }

    @Override
    public Result createUser(User user) {
        // 检查用户名是否已存在
        Long checkUsername = userDao.selectCount(new LambdaQueryWrapper<User>().eq(User::getUsername, user.getUsername()));

        if (checkUsername > 0) {
            // 如果用户名已存在，返回错误信息
            return Result.error("-1", "注册失败，用户名已存在");
        }
        Long checkEmail = userDao.selectCount(new LambdaQueryWrapper<User>().eq(User::getEmail, user.getEmail()));
        if (checkEmail > 0) {
            // 如果邮箱已存在，返回错误信息
            return Result.error("-1", "注册失败，邮箱已存在");
        }
        // 检查用户密码是否为空或仅由空白字符组成，如果为空则设置默认密码
        if (!StringUtils.isNotBlank(user.getPassword())) {
            user.setPassword(DEFAULT_PWD);
        }
        // 检查用户角色是否为空或仅由空白字符组成，如果为空则设置默认角色为普通用户
        if (!StringUtils.isNotBlank(user.getRole())) {
            user.setRole(UserRole.USER.getValue());
        } else {
            // 如果用户角色不为空，检查角色是否为有效的预设角色（管理员、普通用户、超级管理员）
            if (!Arrays.asList(UserRole.ADMIN.getValue(), UserRole.USER.getValue(), UserRole.SUPER_ADMIN.getValue()).contains(user.getRole())) {
                // 如果角色无效，返回错误信息
                return Result.error("-1", "无效的角色");
            }
        }
        // 保存用户信息到数据库
        // insert方法用于插入一条记录，返回受影响的行数
        int res = userDao.insert(user);
        // 如果受影响的行数大于0，返回成功信息，包含用户对象
        if (res > 0) {
            return Result.success(user);
        } else {
            // 如果受影响的行数等于0，返回错误信息
            return Result.error("-1", "注册失败");
        }
    }

    @Override
    public Result updateUser(Integer id, User user) {

        //设置id
        user.setId(id);
        //根据id更新用户信息
        int res = userDao.updateById(user);
        if (res > 0) {
            //返回成功信息，包含用户对象
            return Result.success(user);
        } else {
            return Result.error("-1", "更新失败");
        }
    }

    @Override
    public Result forgetPassword(String email, String newPassword) {
        // 创建一个新的User对象
        User user = new User();
        // 如果邮箱不为空或不为null，则将邮箱设置到user对象中
        if (StringUtils.isNotBlank(email)) {
            user.setEmail(email);
        }
        // 根据邮箱查询用户列表
        List<User> userList = userDao.selectList(new QueryWrapper<User>().eq("email", user.getEmail()));
        // 如果用户列表为空或为null，返回错误信息，提示该邮箱不存在
        if (userList == null || userList.isEmpty()) {
            return Result.error("-1", "该邮箱不存在");
        } else {
            // 获取用户列表中的第一个用户对象
            User oldUser = userList.get(0);
            // 如果新密码不为空或不为null，则将新密码设置到oldUser对象中
            if (StringUtils.isNotBlank(newPassword)) {
                oldUser.setPassword(newPassword);
                // 根据id更新用户信息
                int res = userDao.updateById(oldUser);
                // 如果更新成功，返回成功信息
                if (res > 0) {
                    return Result.success();
                } else {
                    // 如果更新失败，返回错误信息，提示更新失败并联系管理员
                    return Result.error("-1", "更新失败,请联系管理员");
                }
            } else {
                // 如果新密码为空或为null，返回错误信息，提示更新异常并联系管理员
                return Result.error("-1", "更新异常,请联系管理员");
            }

        }
    }

    @Override
    public Result updatePassword(Integer id, UserPasswordUpdate userPasswordUpdate) {
        // 根据ID查询用户信息
        User oldUser = userDao.selectById(id);
        // 如果用户不存在，返回错误信息
        if (oldUser == null) {
            return Result.error("-1", "用户不存在");
            // 否则，继续验证旧密码
        } else {
            // 检查提供的旧密码是否与数据库中存储的密码匹配
            if (userPasswordUpdate.getOldPassword().equals(oldUser.getPassword())) {
                // 如果旧密码匹配，更新用户的密码为新密码
                oldUser.setPassword(userPasswordUpdate.getNewPassword());
                // 更新用户信息到数据库
                int res = userDao.updateById(oldUser);
                // 如果更新成功，返回成功信息
                if (res > 0) {
                    return Result.success();
                    // 如果更新失败，返回错误信息并提示联系管理员
                } else {
                    return Result.error("-1", "修改失败,请联系管理员");
                }
                // 如果旧密码不匹配，返回错误信息并提示重试
            } else {
                return Result.error("-1", "旧密码错误,请重试！");
            }
        }

    }

    @Override
    public Result getUsersByPage(String username, String sex, String name, String role, String currentRole, Integer currentPage, Integer size) {

        // 权限控制：根据当前角色决定可查询的用户范围
        LambdaQueryWrapper<User> queryWrapper = new LambdaQueryWrapper<>();
        // 检查当前用户角色是否为管理员
        if (UserRole.ADMIN.getValue().equals(currentRole)) {
            // 如果是管理员，则查询角色为普通用户的数据
            queryWrapper.eq(User::getRole, UserRole.USER.getValue());
            // 检查当前用户角色是否为超级管理员
        } else if (UserRole.SUPER_ADMIN.getValue().equals(currentRole)) {
            // 如果是超级管理员，则查询角色为普通用户或管理员的数据
            queryWrapper.in(User::getRole, Arrays.asList(UserRole.USER.getValue(), UserRole.ADMIN.getValue()));
            // 如果当前用户角色既不是管理员也不是超级管理员
        } else {
            // 返回身份认证失败的结果
            return Result.error("-1", "身份认证失败");
        }

        // 动态添加查询条件
        if (StringUtils.isNotBlank(username)) {
            queryWrapper.like(User::getUsername, username);
        }
        if (StringUtils.isNotBlank(sex)) {
            queryWrapper.eq(User::getSex, sex);
        }
        if (StringUtils.isNotBlank(name)) {
            queryWrapper.like(User::getName, name);
        }
        if (StringUtils.isNotBlank(role)) {
            queryWrapper.eq(User::getRole, role);
        }

        // 设置分页条件
        Page<User> page = new Page<>(currentPage, size);
        // 查询用户列表
        Page<User> resultPage = userDao.selectPage(page, queryWrapper);
        // 返回成功信息，包含用户分页对象
        return Result.success(resultPage);
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        // 判断用户ID列表是否为空
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "用户ID列表不能为空");
        }
        // 根据用户ID列表删除用户信息
        int deletedCount = userDao.deleteBatchIds(ids);
        // 判断删除的用户数量是否大于0
        if (deletedCount > 0) {
            // 返回成功信息
            return Result.success();
        } else {
            // 返回错误信息，提示未找到对应的用户记录
            return Result.error("-1", "删除失败：未找到对应的用户记录");
        }
    }

    @Override
    public Result searchUsersByUsernameOrName(String username, Integer limit) {
        // 构建查询条件
        LambdaQueryWrapper<User> wrapper = new LambdaQueryWrapper<>();
        // 指定查询字段
        // 返回除密码外的字段
        wrapper.select(User::getId,
                        User::getUsername,
                        User::getName,
                        User::getRole,
                        User::getAvatar,
                        User::getSex,
                        User::getPhone,
                        User::getEmail,
                        User::getAddress,
                        User::getAccount)
                // 模糊查询用户名
                .like(StringUtils.isNotBlank(username), User::getUsername, username)
                // or模糊查询姓名
                .or()
                .like(StringUtils.isNotBlank(username), User::getName, username)
                .last("LIMIT " + limit); // 限制返回数量

        // 查询用户列表
        List<User> users = userDao.selectList(wrapper);
        // 返回成功信息，包含用户列表
        return Result.success(users);
    }

    @Override
    public Result rechargeBalance(Map<String, Object> params) {
        // 参数提取与校验
        if (params == null) {
            return Result.error("-1", "请求参数不能为空");
        }

        Object userIdObj = params.get("userId");
        Object amountObj = params.get("amount");

        if (userIdObj == null || amountObj == null) {
            return Result.error("-1", "缺少必要参数: userId 或 amount");
        }
        Integer userId;
        Double amount;
        try {
            userId = Integer.valueOf(userIdObj.toString());
            amount = Double.valueOf(amountObj.toString());
        } catch (NumberFormatException e) {
            return Result.error("-1", "参数格式错误");
        }

        if (userId <= 0 || amount <= 0) {
            return Result.error("-1", "参数错误或充值金额不正确");
        }

        // 查询用户
        User user = userDao.selectById(userId);
        if (user == null) {
            return Result.error("-1", "用户不存在");
        }

        // 4. 更新余额
        double oldBalance = user.getAccount() != null ? user.getAccount() : 0.0;
        double newBalance = oldBalance + amount;
        user.setAccount(newBalance);

        // 5. 执行更新
        int rows = userDao.updateById(user);
        if (rows > 0) {
            // 6. 构造返回结果
            Map<String, Object> result = new HashMap<>();
            result.put("userId", userId);
            result.put("newBalance", newBalance);
            result.put("addedAmount", amount);
            return Result.success(result);
        } else {
            return Result.error("-1", "充值失败，请稍后再试");
        }
    }


}
```

### 3 实现首页轮播图管理

首页轮播图模块涉及文件上传和图片管理。首先创建HomeSlider实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("home_slider")
public class HomeSlider {

    /** 轮播图的唯一标识符（自增主键） */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /** 轮播图的名称或标题 */
    private String name;

    /** 对轮播图内容的简短描述 */
    private String desrc;

    /** 轮播图的图片链接 */
    private String img;
}
```

创建HomeSliderController，控制层只做请求转发，业务逻辑全部在Service层

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.service.HomeSliderService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

@RestController
@RequestMapping("/slider")
public class HomeSliderController {

    @Autowired
    private HomeSliderService homeSliderService;

    /**
     * 分页查询轮播图列表
     */
    @RequestMapping("/findAll")
    public Result selectPage(
        @RequestParam(defaultValue = "1") Integer page,
        @RequestParam(defaultValue = "10") Integer limit) {
        return homeSliderService.getHomeSliderPage(page, limit);
    }

    /**
     * 保存轮播图（含文件上传）
     */
    @RequestMapping("/save")
    public Result save(@RequestParam("files") MultipartFile file,
                       @RequestParam String homeSlider) {
        return homeSliderService.saveHomeSlider(file, homeSlider);
    }

    /**
     * 修改轮播图（含文件上传，支持替换旧图片）
     */
    @RequestMapping("/update")
    public Result updateById(
        @RequestParam("files") MultipartFile file,
        @RequestParam(value = "deletedImg", required = false) String deletedImg,
        @RequestParam String homeSlider) {
        return homeSliderService.updateHomeSlider(file, deletedImg, homeSlider);
    }

    /**
     * 根据id删除轮播图（同时删除图片文件）
     */
    @RequestMapping("delete/{id}")
    public Result deleteById(@PathVariable Integer id) {
        return homeSliderService.deleteHomeSliderById(id);
    }

    /**
     * 获取所有轮播图（前台展示用）
     */
    @RequestMapping("/selectAll")
    public Result selectAll() {
        return homeSliderService.selectAllSliders();
    }
}
```

创建HomeSliderService接口，定义轮播图业务的核心方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.HomeSlider;
import org.springframework.web.multipart.MultipartFile;

public interface HomeSliderService extends IService<HomeSlider> {
    Result getHomeSliderPage(Integer page, Integer limit);

    Result saveHomeSlider(MultipartFile file, String homeSlider);

    Result updateHomeSlider(MultipartFile file, String deletedImg, String homeSlider);

    Result deleteHomeSliderById(Integer id);

    Result selectAllSliders();
}
```

创建HomeSliderServiceImpl实现类，图片的保存与删除逻辑在此层处理

```
package com.qf.service.impl;

import com.alibaba.fastjson.JSON;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.HomeSliderDao;
import com.qf.entity.HomeSlider;
import com.qf.service.HomeSliderService;
import com.qf.utils.FileUtil;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

@Service
public class HomeSliderServiceImpl extends ServiceImpl<HomeSliderDao, HomeSlider> implements HomeSliderService {
    private final HomeSliderDao homeSliderDao;

    public HomeSliderServiceImpl(HomeSliderDao homeSliderDao) {
        this.homeSliderDao = homeSliderDao;
    }

    @Override
    public Result getHomeSliderPage(Integer page, Integer limit) {
        // 构建分页条件
        Page<HomeSlider> sliderPage = new Page<>(page, limit);
        // 执行分页查询
        Page<HomeSlider> resultPage = homeSliderDao.selectPage(sliderPage, null);
        // 返回结果
        return Result.success(resultPage);
    }

    @Override
    public Result saveHomeSlider(MultipartFile file, String homeSlider) {
        // 检查homeSlider是否为空
        if (homeSlider == null || homeSlider.trim().isEmpty()) {
            return Result.error("-1", "轮播图信息不能为空");
        }
        HomeSlider entity;
        try {
            // 将JSON字符串解析为HomeSlider对象
            entity = JSON.parseObject(homeSlider, HomeSlider.class);
        } catch (Exception e) {
            return Result.error("-1", "轮播图数据格式错误");
        }
        // 保存图片文件并获取路径
        String imagePath = updateImages(file, null);
        entity.setImg(imagePath);
        // 执行数据库插入
        int inserted = homeSliderDao.insert(entity);
        return inserted > 0 ? Result.success() : Result.error("-1", "添加失败");
    }

    @Override
    public Result updateHomeSlider(MultipartFile file, String deletedImg, String homeSlider) {
        // 检查轮播图信息是否为空
        if (homeSlider == null || homeSlider.trim().isEmpty()) {
            return Result.error("-1", "轮播图信息不能为空");
        }
        HomeSlider entity;
        try {
            entity = JSON.parseObject(homeSlider, HomeSlider.class);
        } catch (Exception e) {
            return Result.error("-1", "轮播图数据格式错误");
        }
        if (entity.getId() == null) {
            return Result.error("-1", "轮播图ID不能为空");
        }
        // 如果有新文件上传，替换旧图片
        if (file != null && !file.isEmpty() && file.getSize() > 0) {
            String newImagePath = updateImages(file, deletedImg);
            if (newImagePath != null) {
                entity.setImg(newImagePath);
            }
        }
        // 执行数据库更新
        int updated = homeSliderDao.updateById(entity);
        if (updated > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "更新失败：记录可能不存在");
        }
    }

    @Override
    public Result deleteHomeSliderById(Integer id) {
        if (id == null) {
            return Result.error("-1", "ID不能为空");
        }
        // 先查询原记录，获取旧图片路径
        HomeSlider existing = homeSliderDao.selectById(id);
        if (existing == null) {
            return Result.error("-1", "轮播图不存在，无法删除");
        }
        // 执行数据库删除
        int deleted = homeSliderDao.deleteById(id);
        if (deleted > 0) {
            // 删除本地图片文件
            updateImages(null, existing.getImg());
            return Result.success();
        } else {
            return Result.error("-1", "删除失败");
        }
    }

    @Override
    public Result selectAllSliders() {
        List<HomeSlider> sliders = homeSliderDao.selectList(null);
        return Result.success(sliders);
    }

    /**
     * 图片处理逻辑：
     * - 若 oldImg 非空，则删除旧图；
     * - 若 newFile 非空，则保存新图并返回路径。
     */
    public String updateImages(MultipartFile newFile, String oldImg) {
        if (oldImg != null) {
            String localPath = FileUtil.removePartFromUrlUsingJSON(oldImg, "/api/img/");
            FileUtil.deleteFile(localPath);
        }
        if (newFile != null && !newFile.isEmpty()) {
            return FileUtil.saveImage(newFile, "homeSlider");
        }
        return null;
    }
}
```

创建HomeSliderDao接口

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.HomeSlider;

public interface HomeSliderDao extends BaseMapper<HomeSlider> {
}
```

### 4 实现消息推送管理

消息推送模块（PetNotification）支持管理员向指定角色或指定用户发送通知消息，用户端可查看自己的通知并标记已读。首先创建PetNotification实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 * 用户通知实体类，对应数据库表 pet_notification
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("pet_notification")
public class PetNotification {

    /** 通知的唯一标识，自增主键 */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /** 关联的用户ID */
    private Integer userId;

    /** 推送给用户的消息内容 */
    private String message;

    /** 消息创建的时间戳 */
    private LocalDateTime timestamp;

    /** 通知状态（例如：unread / read） */
    private String status;

    /** 用户名（非数据库字段，用于关联查询展示） */
    @TableField(exist = false)
    private String username;
}
```

创建PetNotificationController，控制层只做请求转发

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.PetNotification;
import com.qf.service.PetNotificationService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/pet-notification")
public class PetNotificationController {

    @Autowired
    private PetNotificationService petNotificationService;

    /**
     * 分页查询（管理员查看所有，支持按用户名和状态筛选）
     */
    @RequestMapping("/page")
    public Result selectPage(
        @RequestParam(defaultValue = "") String username,
        @RequestParam(defaultValue = "") String status,
        @RequestParam(defaultValue = "1") Integer currentPage,
        @RequestParam(defaultValue = "10") Integer size) {
        return petNotificationService.getNotificationsByPage(username, status, currentPage, size);
    }

    /**
     * 向指定角色的所有用户发送通知
     */
    @RequestMapping("/role/{role}")
    public Result addForRole(@PathVariable String role,
                             @RequestBody PetNotification notification) {
        return petNotificationService.createNotificationsForRole(role, notification);
    }

    /**
     * 向指定用户发送通知
     */
    @RequestMapping("/user/{userId}")
    public Result addForUser(@PathVariable Integer userId,
                             @RequestBody PetNotification notification) {
        return petNotificationService.createNotificationForUser(userId, notification);
    }

    /**
     * 批量删除通知
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return petNotificationService.deleteNotificationsBatch(ids);
    }

    /**
     * 标记通知为已读
     */
    @RequestMapping("/markAsRead/{id}")
    public Result markAsRead(@PathVariable Integer id) {
        return petNotificationService.markNotificationAsRead(id);
    }

    /**
     * 根据用户ID获取通知（用户端使用）
     */
    @RequestMapping("/getPage")
    public Result getNotificationsByUserId(
        @RequestParam Integer userId,
        @RequestParam(defaultValue = "") String status,
        @RequestParam(defaultValue = "1") Integer currentPage,
        @RequestParam(defaultValue = "10") Integer size) {
        return petNotificationService.getPetNotificationByUserId(userId, status, currentPage, size);
    }
}
```

创建PetNotificationService接口，包含管理员端和用户端的完整业务方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.PetNotification;

import java.util.List;

public interface PetNotificationService extends IService<PetNotification> {
    Result getNotificationsByPage(String username, String status, Integer currentPage, Integer size);

    Result createNotificationsForRole(String role, PetNotification notification);

    Result createNotificationForUser(Integer userId, PetNotification notification);

    Result deleteNotificationsBatch(List<Integer> ids);

    Result markNotificationAsRead(Integer id);

    Result getPetNotificationByUserId(Integer userId, String status, Integer currentPage, Integer size);
}
```

创建PetNotificationServiceImpl实现类。核心业务包括：按角色批量创建通知（遍历该角色所有用户各插一条）、按用户创建通知、查询时自动关联填充用户名、标记已读。所有复杂逻辑在此层处理

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.PetNotificationDao;
import com.qf.dao.UserDao;
import com.qf.entity.PetNotification;
import com.qf.entity.User;
import com.qf.service.PetNotificationService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class PetNotificationServiceImpl extends ServiceImpl<PetNotificationDao, PetNotification> implements PetNotificationService {

    @Autowired
    private PetNotificationDao petNotificationDao;
    @Autowired
    private UserDao userDao;

    @Override
    public Result getNotificationsByPage(String username, String status, Integer currentPage, Integer size) {
        // 初始化用户ID列表为null
        List<Integer> userIds = null;
        // 如果用户名不为空，先根据用户名查用户ID
        if (StringUtils.isNotBlank(username)) {
            LambdaQueryWrapper<User> userWrapper = new LambdaQueryWrapper<>();
            userWrapper.like(User::getUsername, username);
            userIds = userDao.selectList(userWrapper)
            .stream()
            .map(User::getId)
            .collect(Collectors.toList());
            if (userIds.isEmpty()) {
                return Result.success(new Page<>(currentPage, size));
            }
        }
        // 构建查询条件
        LambdaQueryWrapper<PetNotification> wrapper = new LambdaQueryWrapper<>();
        wrapper.in(userIds != null, PetNotification::getUserId, userIds)
        .eq(StringUtils.isNotBlank(status), PetNotification::getStatus, status)
        .orderByDesc(PetNotification::getTimestamp);
        // 执行分页查询
        Page<PetNotification> page = petNotificationDao.selectPage(
            new Page<>(currentPage, size), wrapper);
        // 遍历填充用户名
        page.getRecords().forEach(notification -> {
            User user = userDao.selectById(notification.getUserId());
            if (user != null) {
                notification.setUsername(user.getUsername());
            }
        });
        return Result.success(page);
    }

    @Override
    public Result createNotificationsForRole(String role, PetNotification notification) {
        if (StringUtils.isBlank(role)) {
            return Result.error("-1", "角色不能为空");
        }
        if (notification == null) {
            return Result.error("-1", "通知内容不能为空");
        }
        // 查询该角色的所有用户
        LambdaQueryWrapper<User> userWrapper = new LambdaQueryWrapper<>();
        userWrapper.eq(User::getRole, role);
        List<User> users = userDao.selectList(userWrapper);
        if (users.isEmpty()) {
            return Result.error("-1", "未找到该角色的用户");
        }
        // 为每个用户创建独立通知
        LocalDateTime now = LocalDateTime.now();
        for (User user : users) {
            PetNotification record = new PetNotification();
            record.setMessage(notification.getMessage());
            record.setUserId(user.getId());
            record.setTimestamp(now);
            record.setStatus("unread");
            petNotificationDao.insert(record);
        }
        return Result.success();
    }

    @Override
    public Result createNotificationForUser(Integer userId, PetNotification notification) {
        if (userId == null || userId <= 0) {
            return Result.error("-1", "用户ID无效");
        }
        if (notification == null || StringUtils.isBlank(notification.getMessage())) {
            return Result.error("-1", "通知消息内容不能为空");
        }
        PetNotification record = new PetNotification();
        record.setUserId(userId);
        record.setMessage(notification.getMessage().trim());
        record.setTimestamp(LocalDateTime.now());
        record.setStatus("unread");
        int inserted = petNotificationDao.insert(record);
        return inserted > 0 ? Result.success() : Result.error("-1", "添加失败，请稍后重试");
    }

    @Override
    public Result deleteNotificationsBatch(List<Integer> ids) {
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }
        int deletedCount = petNotificationDao.deleteBatchIds(ids);
        if (deletedCount > 0) {
            return Result.success("成功删除 " + deletedCount + " 条通知");
        } else {
            return Result.success("未找到可删除的通知");
        }
    }

    @Override
    public Result markNotificationAsRead(Integer id) {
        if (id == null || id <= 0) {
            return Result.error("-1", "通知ID无效");
        }
        PetNotification update = new PetNotification();
        update.setId(id);
        update.setStatus("read");
        int updated = petNotificationDao.updateById(update);
        if (updated > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "通知不存在或已是已读状态");
        }
    }

    @Override
    public Result getPetNotificationByUserId(Integer userId, String status, Integer currentPage, Integer size) {
        LambdaQueryWrapper<PetNotification> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(PetNotification::getUserId, userId)
                .eq(StringUtils.isNotBlank(status), PetNotification::getStatus, status)
                .orderByDesc(PetNotification::getTimestamp);
        Page<PetNotification> page = petNotificationDao.selectPage(
                new Page<>(currentPage, size), wrapper);
        // 填充用户名
        page.getRecords().forEach(notification -> {
            User user = userDao.selectById(notification.getUserId());
            if (user != null) {
                notification.setUsername(user.getUsername());
            }
        });
        return Result.success(page);
    }
}
```

创建PetNotificationDao接口

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.PetNotification;

public interface PetNotificationDao extends BaseMapper<PetNotification> {
}
```

### 5 实现后台菜单管理

菜单管理模块支持动态配置后台侧边栏菜单，支持父子菜单嵌套结构、按角色权限过滤。首先创建Menu实体类

**注意:只有超级管理员才有此权限(Sadmin用户)**

创建MenuController，控制层只做请求转发

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Menu;
import com.qf.service.MenuService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/menu")
public class MenuController {

    @Autowired
    private MenuService menuService;

    /**
     * 查询菜单树（支持按名称搜索）
     */
    @RequestMapping("/findAll")
    public Result findAll(@RequestParam(name = "name", defaultValue = "") String name) {
        return menuService.getMenuTree(name);
    }

    /**
     * 更新菜单
     */
    @RequestMapping("/update")
    public Result update(@RequestBody Menu menu) {
        return menuService.updateMenu(menu);
    }

    /**
     * 批量删除菜单
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return menuService.deleteBatch(ids);
    }

    /**
     * 保存菜单（新增或更新，自动同步父子角色）
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Menu menu) {
        return menuService.saveOrUpdateMenu(menu);
    }
}
```

创建MenuService接口

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Menu;

import java.util.List;

public interface MenuService extends IService<Menu> {
    Result getMenuTree(String name);

    Result updateMenu(Menu menu);

    Result deleteBatch(List<Integer> ids);

    Result saveOrUpdateMenu(Menu menu);
}
```

创建MenuServiceImpl实现类。核心业务包括：构建菜单树（一级菜单 + 嵌套子菜单）、保存菜单时自动同步父子角色权限。所有复杂逻辑在此层处理

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.Wrappers;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.MenuDao;
import com.qf.entity.Menu;
import com.qf.service.MenuService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
public class MenuServiceImpl extends ServiceImpl<MenuDao, Menu> implements MenuService {

    @Autowired
    private MenuDao menuDao;

    @Override
    public Result getMenuTree(String name) {
        QueryWrapper<Menu> queryWrapper = new QueryWrapper<>();
        queryWrapper.orderByAsc("sort_num");
        if (StringUtils.isNotBlank(name)) {
            queryWrapper.like("name", name);
        }
        List<Menu> allList = menuDao.selectList(queryWrapper);

        // 构建一级菜单（pid == null 或 pid == 0）
        List<Menu> parentList = allList.stream()
        .filter(menu -> menu.getPid() == null || menu.getPid() == 0)
        .collect(Collectors.toList());

        // 为每个一级菜单设置子菜单
        for (Menu parent : parentList) {
            List<Menu> children = allList.stream()
            .filter(menu -> parent.getId().equals(menu.getPid()))
            .collect(Collectors.toList());
            parent.setChildren(children);
        }

        return Result.success(parentList);
    }

    @Override
    public Result updateMenu(Menu menu) {
        boolean updated = this.updateById(menu);
        if (updated) {
            return Result.success();
        } else {
            return Result.error("-1", "修改失败");
        }
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }
        boolean deleted = this.removeByIds(ids);
        if (deleted) {
            return Result.success();
        } else {
            return Result.error("-1", "删除失败");
        }
    }

    @Override
    public Result saveOrUpdateMenu(Menu menu) {
        // 判断是新增还是更新
        Menu res = menuDao.selectOne(Wrappers.<Menu>lambdaQuery().eq(Menu::getId, menu.getId()));
        if (res != null) {
            // 更新
            int i = menuDao.updateById(menu);
            if (i > 0) {
                this.updateMenuRole(menu);  // 同步父子角色
                return Result.success("更新成功");
            } else {
                return Result.error("-1", "更新失败");
            }
        } else {
            // 新增
            int insert = menuDao.insert(menu);
            if (insert > 0) {
                this.updateMenuRole(menu);  // 同步父子角色
                return Result.success("插入成功");
            } else {
                return Result.error("-1", "插入失败");
            }
        }
    }

    /**
     * 根据当前菜单，更新其父级或子级的角色字段（role）
     * 规则：父菜单的角色由所有子菜单的角色综合决定
     */
    private void updateMenuRole(Menu menu) {
        // 当前menu是父级菜单，获取其所有子菜单并统一角色
        if (menu.getPid() == null) {
            List<Menu> submenus = menuDao.selectList(Wrappers.<Menu>lambdaQuery().eq(Menu::getPid, menu.getId()));
            Integer parentRole = menu.getRole();
            for (Menu submenu : submenus) {
                submenu.setRole(parentRole);
                menuDao.updateById(submenu);
            }
            return;
        }

        // 当前menu是子菜单，向上更新父级角色
        Menu parentMenu = menuDao.selectOne(Wrappers.<Menu>lambdaQuery().eq(Menu::getId, menu.getPid()));
        if (parentMenu == null) {
            return;
        }

        Integer parentId = parentMenu.getId();
        Integer parentRole = parentMenu.getRole();
        List<Menu> childrenMenus = menuDao.selectList(Wrappers.<Menu>lambdaQuery().eq(Menu::getPid, parentId));

        // 统计子菜单的角色分布，决定父菜单角色
        int countRole0 = 0, countRole1 = 0, countRole2 = 0, countRole3 = 0;
        for (Menu childMenu : childrenMenus) {
            Integer childRole = childMenu.getRole();
            if (childRole == 0) countRole0++;
            else if (childRole == 1) countRole1++;
            else if (childRole == 2) countRole2++;
            else if (childRole == 3) countRole3++;
        }

        // 根据子菜单角色分布确定父菜单角色
        if (countRole0 == childrenMenus.size()) {
            parentRole = 0;
        } else if (countRole1 == childrenMenus.size() || (countRole1 > 0 && countRole2 == 0 && countRole3 == 0)) {
            parentRole = 1;
        } else if (countRole2 == childrenMenus.size() || (countRole2 > 0 && countRole1 == 0 && countRole3 == 0)) {
            parentRole = 2;
        } else if (countRole1 > 0 && countRole2 > 0 || countRole3 > 0) {
            parentRole = 3;
        }

        // 更新父级菜单角色
        if (!parentRole.equals(parentMenu.getRole())) {
            parentMenu.setRole(parentRole);
            menuDao.updateById(parentMenu);
        }
    }
}
```

### 6 实现图标字典管理

图标字典用于提供菜单图标的选择列表。首先创建IconDict实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

/**
 * 字典表项实体类，对应数据库表 dict_item
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("dict_item")
public class IconDict {

    /**
     * 主键 ID，自增
     */
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;

    /**
     * 字典项的键（例如：pet_status、adopt_result 等）
     */
    private String itemKey;

    /**
     * 字典项的值（例如："待领养"、"审核通过" 等）
     */
    private String itemValue;

    /**
     * 字典项的描述信息，用于说明该键值对的用途或含义
     */
    private String description;

    /**
     * 创建时间，格式化为 yyyy-MM-dd
     */
    @JsonFormat(locale = "zh", timezone = "GMT+8", pattern = "yyyy-MM-dd")
    private LocalDateTime createTime;

    /**
     * 更新时间，格式化为 yyyy-MM-dd
     */
    @JsonFormat(locale = "zh", timezone = "GMT+8", pattern = "yyyy-MM-dd")
    private LocalDateTime updateTime;
}
```

创建IconDictController，控制层只做请求转发

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.service.IconDictService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/icon-dict")
public class IconDictController {

    @Autowired
    private IconDictService iconDictService;

    /**
     * 查询所有字典项
     */
    @RequestMapping("/all")
    public Result getAll() {
        return iconDictService.getAllDictItems();
    }
}
```

创建IconDictService接口

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.IconDict;

public interface IconDictService extends IService<IconDict> {
    Result getAllDictItems();
}
```

创建IconDictServiceImpl实现类

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.IconDictDao;
import com.qf.entity.IconDict;
import com.qf.service.IconDictService;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class IconDictServiceImpl extends ServiceImpl<IconDictDao, IconDict> implements IconDictService {
    @Override
    public Result getAllDictItems() {
        // 查询全部字典项，不加任何条件
        List<IconDict> itemList = baseMapper.selectList(new QueryWrapper<>());
        if (itemList == null || itemList.size() == 0) {
            return Result.error("-1", "查询失败，没有数据");
        }
        return Result.success(itemList);
    }
}
```

创建IconDictDao接口

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.IconDict;

public interface IconDictDao extends BaseMapper<IconDict> {
}
```

## 十四. 实现宠物服务管理功能

宠物服务平台涵盖寄养服务、流浪宠物上报、训练项目管理、训练申请、美容服务和医疗服务六大业务模块，以及医疗服务类型基础数据维护。

### 1 实现宠物寄养服务管理

宠物寄养模块用于管理用户的宠物寄养申请，涉及寄养记录表（foster）和房间表（room）的关联操作。当寄养结束时会自动释放对应房间。首先创建Foster实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 寄养记录实体类，对应数据库表 foster
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("foster")
public class Foster {

    /** 主键 ID，自增 */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /** 用户 ID，关联用户表 */
    private Integer userId;

    /** 宠物昵称 */
    private String name;

    /** 寄养时间（格式如：2025-11-26） */
    private String time;

    /** 寄养天数 */
    private Integer days;

    /** 寄养状态（如：pending, confirmed, completed, cancelled 等） */
    private String status;

    /** 寄养房间 ID，关联房间表 */
    private Integer roomId;


}
```

创建对应的FosterVO视图对象，用于连表查询时承载用户名称和房间名称

```
package com.qf.vo;

import com.baomidou.mybatisplus.annotation.TableField;
import com.qf.entity.Foster;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;

@EqualsAndHashCode(callSuper = false)
@Data
@NoArgsConstructor
@AllArgsConstructor
public class FosterVO extends Foster {

    /** 用户名（非数据库字段，用于展示） */
    @TableField(exist = false)
    private String userName;

    /** 房间名称（非数据库字段，用于展示） */
    @TableField(exist = false)
    private String roomName;
}
```

#### 1.1查询寄养记录列表数据

在FosterController中添加selectPage方法，用于分页查询寄养记录

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Foster;
import com.qf.service.FosterService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/foster")
public class FosterController {

    @Autowired
    private FosterService fosterService;

    /**
     * 分页查询寄养记录
     * @param animalName
     * @param userId
     * @param status
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String animalName,
            @RequestParam(required = false) Integer userId,
            @RequestParam(defaultValue = "") String status,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        // 调用service层方法
        return fosterService.selectFosterPage(animalName, userId, status, currentPage, size);
    }

}
```

创建对应服务层FosterService接口，添加selectFosterPage抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Foster;

public interface FosterService extends IService<Foster> {
    Result selectFosterPage(String animalName, Integer userId, String status, Integer currentPage, Integer size);
}
```

在对应实现类FosterServiceImpl中重写selectFosterPage抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.FosterDao;
import com.qf.entity.Foster;
import com.qf.service.FosterService;
import com.qf.vo.FosterVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class FosterServiceImpl extends ServiceImpl<FosterDao, Foster> implements FosterService {

    @Autowired
    private FosterDao fosterDao;

    @Override
    public Result selectFosterPage(String animalName, Integer userId, String status, Integer currentPage, Integer size) {
        // 前端约定 userId = -1 表示查询所有用户，这里转为 null 跳过该过滤条件
        if (userId != null && userId == -1) {
            userId = null;
        }
        // 使用 MybatisPlus 的分页插件 Page 构建分页对象
        Page<FosterVO> page = new Page<>(currentPage, size);
        // 调用fosterDao 的 selectByPage 方法
        Page<FosterVO> fosterPage = fosterDao.selectByPage(status, animalName, userId, page);
        // 将分页对象转换为 Result 对象
        return Result.success(fosterPage);
    }

}
```

创建对应的FosterDao接口，包含自定义的关联查询分页方法

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.qf.entity.Foster;
import com.qf.vo.FosterVO;
import org.apache.ibatis.annotations.Param;

public interface FosterDao extends BaseMapper<Foster> {
    Page<FosterVO> selectByPage(@Param("status") String status,
                                @Param("name") String name,
                                @Param("userId") Integer userId,
                                Page<FosterVO> page);
}
```

在resources/mapper目录下创建FosterDao.xml，编写三表关联查询SQL（foster + user + room）

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.qf.dao.FosterDao">

    <!-- 结果映射：FosterVO 包含了 Foster 的基础字段以及用户名、房间名称 -->
    <resultMap id="FosterVOMap" type="com.qf.vo.FosterVO">
        <id property="id" column="id"/>
        <result property="userId" column="user_id"/>
        <result property="name" column="name"/>
        <result property="time" column="time"/>
        <result property="days" column="days"/>
        <result property="status" column="status"/>
        <result property="roomId" column="room_id"/>
        <!-- 用户名来自 user 表 -->
        <result property="userName" column="username"/>
        <!-- 房间名来自 room 表 -->
        <result property="roomName" column="roomName"/>
    </resultMap>

    <!-- 多条件分页查询寄养记录，关联 user 表和 room 表 -->
    <select id="selectByPage" resultMap="FosterVOMap">
        SELECT f.*,
        u.username,
        r.name AS roomName
        FROM foster f
        LEFT JOIN user u ON f.user_id = u.id
        LEFT JOIN room r ON f.room_id = r.id
        WHERE 1 = 1
        <if test="status != null and status != ''">
            AND f.status = #{status}
        </if>

        <if test="name != null and name != ''">
            AND f.name LIKE CONCAT('%', #{name}, '%')
        </if>

        <if test="userId != null">
            AND f.user_id = #{userId}
        </if>

        ORDER BY f.id DESC
    </select>

</mapper>
```

#### 1.2实现修改寄养记录功能

首先会查询全部的房间数据

在RoomController中添加selectAll方法用于查询全部房间信息

```
package com.qf.controller;


import com.qf.utils.Result;
import com.qf.entity.Room;
import com.qf.service.RoomService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/room")
public class RoomController {

    //注入RoomService
    @Autowired
    private RoomService roomService;

    /**
     * 房间列表查询
     * @param name 房间名称
     * @param pageNum 页码
     * @param pageSize 页大小
     * @return 房间列表
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer pageNum,
            @RequestParam(defaultValue = "10") Integer pageSize) {
        //调用RoomService的selectPage方法
        return roomService.selectPage(name, pageNum, pageSize);
    }

    /**
     * 根据id批量删除房间
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return roomService.deleteBatch(ids);
    }

    /**
     * 新增房间功能
     * @param room
     * @return
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Room room) {
        return roomService.saveRoom(room);
    }


    /**
     * 根据id修改房间信息
     * @param room
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody Room room) {
        return roomService.updateRoomById(room);
    }

    /**
     * 查询所有房间信息
     * @return
     */
    @GetMapping("/selectAll")
    public Result selectAll() {

        List<Room> list = roomService.list();
        return Result.success(list);
    }
}
```

在enums包下创建枚举类FosterStatus

```
package com.qf.enums;

public enum FosterStatus {
    Fostering("寄养中") ,
    W_HANDLE("待处理") ,

    END("已领回");

    private  String info;

    FosterStatus(String info) {
        this.info = info;
    }

    public String getInfo() {
        return info;
    }
}
```

修改寄养记录时，需要同步处理房间的分配和释放。当寄养状态改为"已领回"（结束）时，自动释放对应房间为闲置状态；如果分配了新房间，需要将新房间标记为使用中。

在FosterController中添加updateById方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Foster;
import com.qf.service.FosterService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/foster")
public class FosterController {

    @Autowired
    private FosterService fosterService;

    /**
     * 分页查询寄养记录
     * @param animalName
     * @param userId
     * @param status
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
        @RequestParam(defaultValue = "") String animalName,
        @RequestParam(defaultValue = "") Integer userId,
        @RequestParam(defaultValue = "") String status,
        @RequestParam(defaultValue = "1") Integer currentPage,
        @RequestParam(defaultValue = "10") Integer size) {
        // 调用service层方法
        return fosterService.selectFosterPage(animalName, userId, status, currentPage, size);
    }

    /**
     * 根据id修改寄养记录
     * @param foster
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody Foster foster) {
        return fosterService.updateFosterAndRoom(foster);
    }

}
```

在对应服务层FosterService中添加updateFosterAndRoom抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Foster;

public interface FosterService extends IService<Foster> {
    Result selectFosterPage(String animalName, Integer userId, String status, Integer currentPage, Integer size);

    Result updateFosterAndRoom(Foster foster);
}
```

在对应实现类FosterServiceImpl中重写updateFosterAndRoom抽象方法。这里涉及寄养状态变更和房间管理的联动：如果寄养结束（状态为"已领回"）则释放房间，否则根据新的房间ID进行房间分配或切换

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.FosterDao;
import com.qf.dao.RoomDao;
import com.qf.entity.Foster;
import com.qf.entity.Room;
import com.qf.enums.FosterStatus;
import com.qf.enums.RoomStatus;
import com.qf.service.FosterService;
import com.qf.vo.FosterVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Objects;

@Service
public class FosterServiceImpl extends ServiceImpl<FosterDao, Foster> implements FosterService {

    @Autowired
    private FosterDao fosterDao;
    @Autowired
    private RoomDao roomDao;

    @Override
    public Result selectFosterPage(String animalName, Integer userId, String status, Integer currentPage, Integer size) {
        // 前端约定 userId = -1 表示查询所有用户，这里转为 null 跳过该过滤条件
        if (userId != null && userId == -1) {
            userId = null;
        }
        // 使用 MybatisPlus 的分页插件 Page 构建分页对象
        Page<FosterVO> page = new Page<>(currentPage, size);
        // 调用fosterDao 的 selectByPage 方法
        Page<FosterVO> fosterPage = fosterDao.selectByPage(status, animalName, userId, page);
        // 将分页对象转换为 Result 对象
        return Result.success(fosterPage);
    }

    @Override
    public Result updateFosterAndRoom(Foster foster) {
        if (foster == null || foster.getId() == null) {
            return Result.error("-1", "寄养记录ID不能为空");
        }

        Foster old = fosterDao.selectById(foster.getId());
        if (old == null) {
            return Result.error("-1", "寄养记录不存在");
        }

        // 使用 UpdateWrapper 精准控制更新
        UpdateWrapper<Foster> updateWrapper = new UpdateWrapper<>();
        updateWrapper.eq("id", foster.getId());
        updateWrapper.set("status", foster.getStatus());
        updateWrapper.set("name", foster.getName());
        updateWrapper.set("time", foster.getTime());
        updateWrapper.set("days", foster.getDays());
        updateWrapper.set("user_id", foster.getUserId());

        if (FosterStatus.END.getInfo().equals(foster.getStatus())) {
            // 寄养结束：room_id 置空，释放原房间
            updateWrapper.set("room_id", null);
            fosterDao.update(null, updateWrapper);

            // 释放房间：设置为闲置，清空宠物名
            if (old.getRoomId() != null) {
                Room room = roomDao.selectById(old.getRoomId());
                if (room != null) {
                    room.setStatus(RoomStatus.EMPTY.getInfo());
                    room.setAnimal(null);
                    if (roomDao.updateById(room) <= 0) {
                        return Result.error("-1", "房间释放失败");
                    }
                }
            }
            return Result.success();
        }

        // 非结束状态：更新 room_id
        updateWrapper.set("room_id", foster.getRoomId());
        fosterDao.update(null, updateWrapper);

        // ---- 处理房间变更 ----
        Integer newRoomId = foster.getRoomId();
        Integer oldRoomId = old.getRoomId();

        // 房间未变更，无需处理
        if (Objects.equals(oldRoomId, newRoomId)) {
            return Result.success();
        }

        // 释放原房间：设置为闲置，清空宠物名
        if (oldRoomId != null) {
            Room oldRoom = roomDao.selectById(oldRoomId);
            if (oldRoom != null) {
                oldRoom.setStatus(RoomStatus.EMPTY.getInfo());
                oldRoom.setAnimal(null);
                if (roomDao.updateById(oldRoom) <= 0) {
                    return Result.error("-1", "原房间释放失败");
                }
            }
        }

        // 分配新房间
        if (newRoomId == null) {
            return Result.success();
        }

        Room newRoom = roomDao.selectById(newRoomId);
        if (newRoom == null) {
            return Result.error("-1", "指定的新房间不存在");
        }
        if (!RoomStatus.EMPTY.getInfo().equals(newRoom.getStatus())) {
            return Result.error("-1", "新房间已被占用！");
        }

        newRoom.setStatus(RoomStatus.USING.getInfo());
        newRoom.setAnimal(foster.getName());
        if (roomDao.updateById(newRoom) <= 0) {
            return Result.error("-1", "新房间分配失败");
        }

        return Result.success();
    }

}
```

#### 1.3实现删除寄养记录功能

在FosterController中添加deleteById方法，通过路径参数接收寄养记录ID

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Foster;
import com.qf.service.FosterService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/foster")
public class FosterController {

    @Autowired
    private FosterService fosterService;

    /**
     * 分页查询寄养记录
     * @param animalName
     * @param userId
     * @param status
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String animalName,
            @RequestParam(defaultValue = "") Integer userId,
            @RequestParam(defaultValue = "") String status,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        // 调用service层方法
        return fosterService.selectFosterPage(animalName, userId, status, currentPage, size);
    }

    /**
     * 根据id修改寄养记录
     * @param foster
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody Foster foster) {
        return fosterService.updateFosterAndRoom(foster);
    }


    @RequestMapping("/delete/{id}")
    public Result deleteById(@PathVariable Integer id) {
        boolean b = fosterService.removeById(id);
        if (b){
            return Result.success();
        }
        return Result.error("-1","删除失败");
    }

}
```

#### 1.4实现添加寄养记录功能

在FosterController中添加save方法，用于新增寄养申请记录

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Foster;
import com.qf.service.FosterService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/foster")
public class FosterController {

    @Autowired
    private FosterService fosterService;

    /**
     * 分页查询寄养记录
     *
     * @param animalName
     * @param userId
     * @param status
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String animalName,
            @RequestParam(defaultValue = "") Integer userId,
            @RequestParam(defaultValue = "") String status,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        // 调用service层方法
        return fosterService.selectFosterPage(animalName, userId, status, currentPage, size);
    }

    /**
     * 根据id修改寄养记录
     *
     * @param foster
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody Foster foster) {
        return fosterService.updateFosterAndRoom(foster);
    }


    @RequestMapping("/delete/{id}")
    public Result deleteById(@PathVariable Integer id) {
        boolean b = fosterService.removeById(id);
        if (b) {
            return Result.success();
        }
        return Result.error("-1", "删除失败");
    }

    @RequestMapping("/save")
    public Result save(@RequestBody Foster foster) {
        boolean save = fosterService.save(foster);
        if (save){
            return Result.success();
        }
        return Result.error("-1","添加失败");
    }

}
```

### 2 实现流浪宠物上报功能

流浪宠物上报模块（Submit）用于处理流浪宠物救助信息，用户提交包含宠物信息文本和多张图片，管理员可以审核上报记录。

#### 2.1 实现查询列表数据功能

首先创建Submit实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


/**
 * 宠物上报表实体类，对应数据库表 submit
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("submit")
public class Submit {

    /**
     * 主键 ID，自增
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 上报说明
     */
    private String name;

    /**
     * 上报时间（建议格式：yyyy-MM-dd HH:mm:ss）
     */
    private String time;

    /**
     * 处理状态（例如：待处理、已处理、已忽略 等）
     */
    private String status;
}
```

创建对应的控制层类SubmitController,并添加查询列表数据getSubmitsByPage方法

```
package com.qf.controller;

import com.qf.service.SubmitService;
import com.qf.utils.Result;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/submit")
public class SubmitController {

    @Autowired
    private SubmitService submitService;


    @RequestMapping("/page")
    public Result getSubmitsByPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return submitService.getSubmitsByPage(name, currentPage, size);
    }
}
```

创建对应接口SubmitService接口并创建getSubmitsByPage抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.entity.Submit;
import com.qf.utils.Result;

public interface SubmitService extends IService<Submit> {
    Result getSubmitsByPage(String name, Integer currentPage, Integer size);
}
```

创建对应实现类SubmitServiceImpl,并重写getSubmitsByPage抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.dao.SubmitDao;
import com.qf.entity.Submit;
import com.qf.utils.Result;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class SubmitServiceImpl extends ServiceImpl<SubmitDao, Submit> implements SubmitService {

    @Autowired
    private SubmitDao submitDao;


    @Override
    public Result getSubmitsByPage(String name, Integer currentPage, Integer size) {

        // 构建查询条件
        LambdaQueryWrapper<Submit> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(name)) {
            // 如果 name 不为空，则模糊查询
            queryWrapper.like(Submit::getName, name);
        }
        // 构建分页对象
        Page<Submit> page = new Page<>(currentPage, size);
        // 执行分页查询
        Page<Submit> resultPage = submitDao.selectPage(page, queryWrapper);
        // 直接返回分页对象（MyBatis-Plus 的 Page 支持 JSON 序列化）
        return Result.success(resultPage);
    }
}
```

创建对应数据库访问层SubmitDao接口

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.Submit;

public interface SubmitDao extends BaseMapper<Submit> {
}
```

#### 2.2 查看上报图片功能

首先创建对应的实体类SubmitImg对应数据库表submit_img

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("submit_img")
public class SubmitImg {
    /**
     * 图片id
     */
    @TableId(type= IdType.AUTO)
    Integer id;
    /**
     * 上报id
     */
    Integer submitId;
    /**
     * 图片路径
     */
    String url;
}

```

创建对应的控制层SubmitImgController

```
package com.qf.controller;

import com.qf.service.SubmitService;
import com.qf.utils.Result;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/submit")
public class SubmitController {

    @Autowired
    private SubmitService submitService;


    @RequestMapping("/page")
    public Result getSubmitsByPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return submitService.getSubmitsByPage(name, currentPage, size);
    }
}
```

对应接口SubmitService

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.entity.Submit;
import com.qf.utils.Result;

public interface SubmitService extends IService<Submit> {
    Result getSubmitsByPage(String name, Integer currentPage, Integer size);
}
```

对应实现类SubmitServiceImpl

```
package com.qf.service;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.dao.SubmitDao;
import com.qf.entity.Submit;
import com.qf.utils.Result;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class SubmitServiceImpl extends ServiceImpl<SubmitDao, Submit> implements SubmitService {

    @Autowired
    private SubmitDao submitDao;


    @Override
    public Result getSubmitsByPage(String name, Integer currentPage, Integer size) {

        // 构建查询条件
        LambdaQueryWrapper<Submit> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(name)) {
            // 如果 name 不为空，则模糊查询
            queryWrapper.like(Submit::getName, name);
        }
        // 构建分页对象
        Page<Submit> page = new Page<>(currentPage, size);
        // 执行分页查询
        Page<Submit> resultPage = submitDao.selectPage(page, queryWrapper);
        // 直接返回分页对象（MyBatis-Plus 的 Page 支持 JSON 序列化）
        return Result.success(resultPage);
    }
}
```

对应SubmitDao

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.Submit;

public interface SubmitDao extends BaseMapper<Submit> {
}
```

#### 2.3 处理功能

创建枚举类SubmitEnum

```
package com.qf.enums;

public enum SubmitEnum {
    NO("待处理"),
    YES("已处理");
    private String info;

    SubmitEnum(String info) {
        this.info = info;
    }

    public String getInfo() {
        return info;
    }
}
```

对应控制层SubmitController

```
package com.qf.controller;

import com.qf.service.SubmitService;
import com.qf.utils.Result;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/submit")
public class SubmitController {

    @Autowired
    private SubmitService submitService;


    @RequestMapping("/page")
    public Result getSubmitsByPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        return submitService.getSubmitsByPage(name, currentPage, size);
    }

    /**
     * 根据id更新上报记录的状态
     * @param id
     * @return
     */
    @RequestMapping("/updateStatus/{id}")
    public Result updateStatus(@PathVariable Integer id) {
        return submitService.updateStatus(id);
    }

}
```

对应SubmitService

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.entity.Submit;
import com.qf.utils.Result;

public interface SubmitService extends IService<Submit> {
    Result getSubmitsByPage(String name, Integer currentPage, Integer size);

    Result updateStatus(Integer id);
}
```

对应实现类SubmitServiceImpl

```
package com.qf.service;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.dao.SubmitDao;
import com.qf.entity.Submit;
import com.qf.enums.SubmitEnum;
import com.qf.utils.Result;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class SubmitServiceImpl extends ServiceImpl<SubmitDao, Submit> implements SubmitService {

    @Autowired
    private SubmitDao submitDao;


    @Override
    public Result getSubmitsByPage(String name, Integer currentPage, Integer size) {

        // 构建查询条件
        LambdaQueryWrapper<Submit> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(name)) {
            // 如果 name 不为空，则模糊查询
            queryWrapper.like(Submit::getName, name);
        }
        // 构建分页对象
        Page<Submit> page = new Page<>(currentPage, size);
        // 执行分页查询
        Page<Submit> resultPage = submitDao.selectPage(page, queryWrapper);
        // 直接返回分页对象（MyBatis-Plus 的 Page 支持 JSON 序列化）
        return Result.success(resultPage);
    }

    @Override
    public Result updateStatus(Integer id) {
        // 1. 参数校验
        if (id == null || id <= 0) {
            return Result.error("-1", "无效的上报ID");
        }

        // 2. 查询是否存在
        Submit submit = submitDao.selectById(id);
        if (submit == null) {
            return Result.error("-1", "上报记录不存在");
        }

        // 3. 更新状态为“已处理”
        submit.setStatus(SubmitEnum.YES.getInfo());
        boolean updated = submitDao.updateById(submit) > 0;

        // 4. 返回结果
        if (updated) {
            return Result.success("更新成功");
        } else {
            return Result.error("-1", "更新失败");
        }
    }
}
```

### 3 实现训练项目管理

训练项目管理（TrainingName）是基础数据，用于训练申请中的服务类型下拉选择。该模块同样是标准CRUD，路径前缀为`/trainingName`。首先创建TrainingName实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 训练名称实体类，对应数据库表 training_names
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("training_names")
public class TrainingName {

    /**
     * 训练ID，主键，自增
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 训练名称
     */
    private String name;

    /**
     * 训练描述
     */
    private String description;
}
```

创建对应Controller层TrainingNameController

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.TrainingName;
import com.qf.service.TrainingNameService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/trainingName")
public class TrainingNameController {

    @Autowired
    private TrainingNameService trainingNameService;

    /**
     * 查询所有培训名称
     * @param name
     * @param pageNum
     * @param pageSize
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer pageNum,
            @RequestParam(defaultValue = "10") Integer pageSize) {
        return trainingNameService.selectPage(name, pageNum, pageSize);
    }

    /**
     * 根据id批量删除培训名称
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return trainingNameService.deleteBatch(ids);
    }


    /**
     * 保存培训名称
     * @param trainingName
     * @return
     */
    @RequestMapping("/save")
    public Result save(@RequestBody TrainingName trainingName) {
        return trainingNameService.saveTrainingName(trainingName);
    }


    /**
     * 根据id修改培训名称
     * @param trainingName
     * @return
     */
    @RequestMapping("/update")
    public Result updateTrainingName(@RequestBody TrainingName trainingName) {
        return trainingNameService.updateTrainingName(trainingName);
    }

    /**
     * 查询所有培训名称
     * @return
     */
    @RequestMapping("/selectAll")
    public Result selectAll() {
        return trainingNameService.selectAll();
    }
}
```

创建对应服务层接口TrainingNameService

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.TrainingName;

import java.util.List;

public interface TrainingNameService extends IService<TrainingName> {
    Result selectPage(String name, Integer pageNum, Integer pageSize);

    Result deleteBatch(List<Integer> ids);

    Result saveTrainingName(TrainingName trainingName);

    Result updateTrainingName(TrainingName trainingName);

    Result selectAll();
}
```

创建对应实现类TrainingNameServiceImpl，重写所有抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.TrainingNameDao;
import com.qf.entity.TrainingName;
import com.qf.service.TrainingNameService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class TrainingNameServiceImpl extends ServiceImpl<TrainingNameDao, TrainingName> implements TrainingNameService {

    @Autowired
    private TrainingNameDao trainingNameDao;

    @Override
    public Result selectPage(String name, Integer pageNum, Integer pageSize) {

        // 构建查询条件
        LambdaQueryWrapper<TrainingName> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(name)) {
            queryWrapper.like(TrainingName::getName, name);
        }

        // 执行分页查询
        Page<TrainingName> page = new Page<>(pageNum, pageSize);
        Page<TrainingName> resultPage = trainingNameDao.selectPage(page, queryWrapper);
        // 封装返回结果
        return Result.success(resultPage);
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        // 参数校验
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID列表不能为空");
        }

        // 执行批量删除（MyBatis-Plus 内置方法）
        // 等价于 mapper.deleteBatchIds()
        boolean deleted = this.removeByIds(ids);
        // 判断是否删除成功
        if (deleted) {
            // 返回成功结果
            return Result.success();
        } else {
            // 返回失败结果
            return Result.error("-1", "批量删除失败");
        }
    }

    @Override
    public Result saveTrainingName(TrainingName trainingName) {
        // 参数校验
        if (trainingName == null) {
            return Result.error("-1", "请求体不能为空");
        }
        if (StringUtils.isBlank(trainingName.getName())) {
            return Result.error("-1", "训练名称不能为空");
        }
        // 判断数据库中是否存在训练名称
        boolean b = trainingNameDao.selectCount(new LambdaQueryWrapper<TrainingName>().eq(TrainingName::getName, trainingName.getName().trim())) > 0;
        if (b){
            return Result.error("-1","训练名称已存在,请勿重复添加");

        }
        // 执行插入（MyBatis-Plus 自动填充 id）
        // 等价于 BaseMapper.insert()
        boolean saved = this.save(trainingName);

        if (saved) {
            return Result.success();
        } else {
            return Result.error("-1", "新增失败");
        }
    }

    @Override
    public Result updateTrainingName(TrainingName trainingName) {
        // 参数校验
        if (trainingName == null) {
            return Result.error("-1", "请求体不能为空");
        }
        if (trainingName.getId() == null || trainingName.getId() <= 0) {
            return Result.error("-1", "ID不能为空且必须大于0");
        }
        if (StringUtils.isBlank(trainingName.getName())) {
            return Result.error("-1", "训练名称不能为空");
        }
        // 执行更新（MyBatis-Plus 的 updateById 要求实体包含有效 ID）
        boolean updated = this.updateById(trainingName);

        // 返回结果
        if (updated) {
            return Result.success(trainingName); // 返回更新后的对象（含可能自动填充字段）
        } else {
            return Result.error("-1", "更新失败，可能记录不存在");
        }
    }

    @Override
    public Result selectAll() {
        // 执行全量查询
        List<TrainingName> list = trainingNameDao.selectList(null);
        // 判断是否有查询结果
        if (list != null && !list.isEmpty()) {
            return Result.success(list);
        } else {
            return Result.error("-1", "未找到训练名称");
        }
    }

}
```

创建对应dao层TrainingNameDao

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.TrainingName;

public interface TrainingNameDao extends BaseMapper<TrainingName> {
}
```

### 4 实现训练申请管理

训练申请模块用于管理用户的宠物训练预约申请。首先创建PetTrainingService实体类，对应数据库表pet_training_services

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;

/**
 * 宠物训练服务实体类，对应数据库表 pet_training_services
 */


@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("pet_training_services")
public class PetTrainingService {

    /**
     * 服务的唯一标识符，主键，自动递增
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 宠物名称
     */
    private String petName;

    /**
     * 训练服务的类型（如：基础服从、敏捷训练、行为矫正等）
     */
    private String serviceType;

    /**
     * 训练服务预计结束的日期，可以为空
     */
    private LocalDate endDate;

    /**
     * 训练的级别（如：初级、中级、高级）
     */
    private String trainingLevel;

    /**
     * 训练的目标或期望结果（例如：学会坐下、停止吠叫等）
     */
    private String trainingGoals;

    /**
     * 训练完成的状态，如“完成”、“进行中”、“未开始”等
     */
    private String completionStatus;

    /**
     * 用户姓名（关联的宠物主人姓名）
     */
    private String userName;
}
```

创建PetTrainingServiceController，路径前缀为`/petTrainingService`，包含selectPage、update、deleteBatch、save四个标准方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.PetTrainingService;
import com.qf.service.PetTrainingServiceService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/petTrainingService")
public class PetTrainingServiceController {

    @Autowired
    private PetTrainingServiceService petTrainingServiceService;

    /**
     * 根据条件查询分页数据
     * @param serviceType
     * @param username
     * @param pageNum
     * @param pageSize
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
        @RequestParam(defaultValue = "") String serviceType,
        @RequestParam(defaultValue = "") String username,
        @RequestParam(defaultValue = "1") Integer pageNum,
        @RequestParam(defaultValue = "10") Integer pageSize) {
        return petTrainingServiceService.selectPage(serviceType, username, pageNum, pageSize);
    }

    /**
     * 根据id修改训练服务
     * @param petTrainingService
     * @return
     */
    @RequestMapping("/update")
    public Result updatePetTrainingService(@RequestBody PetTrainingService petTrainingService) {
        return petTrainingServiceService.updatePetTrainingService(petTrainingService);
    }

    /**
     * 根据id删除训练服务
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return petTrainingServiceService.deleteBatch(ids);
    }

    @RequestMapping("/save")
    public Result save(@RequestBody PetTrainingService petTrainingService) {
        return petTrainingServiceService.savePetTrainingService(petTrainingService);
    }
}
```

对应service层

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.PetTrainingService;

import java.util.List;

public interface PetTrainingServiceService extends IService<PetTrainingService> {
    Result selectPage(String serviceType, String username, Integer pageNum, Integer pageSize);

    Result updatePetTrainingService(PetTrainingService petTrainingService);

    Result deleteBatch(List<Integer> ids);

    Result savePetTrainingService(PetTrainingService petTrainingService);
}
```

创建对应实现类PetTrainingServiceServiceImpl，重写所有抽象方法。

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.PetTrainingServiceDao;
import com.qf.entity.PetTrainingService;
import com.qf.service.PetTrainingServiceService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class PetTrainingServiceServiceImpl extends ServiceImpl<PetTrainingServiceDao, PetTrainingService> implements PetTrainingServiceService {
    private final PetTrainingServiceDao petTrainingServiceDao;

    public PetTrainingServiceServiceImpl(PetTrainingServiceDao petTrainingServiceDao) {
        this.petTrainingServiceDao = petTrainingServiceDao;
    }

    @Override
    public Result selectPage(String serviceType, String username, Integer pageNum, Integer pageSize) {

        // 构建查询条件
        LambdaQueryWrapper<PetTrainingService> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(serviceType)) {
            queryWrapper.eq(PetTrainingService::getServiceType, serviceType);
        }
        if (StringUtils.isNotBlank(username)) {
            queryWrapper.eq(PetTrainingService::getUserName, username);
        }

        // 执行分页查询
        Page<PetTrainingService> page = new Page<>(pageNum, pageSize);
        // 调用IService的page方法查询分页数据
        Page<PetTrainingService> resultPage = this.page(page, queryWrapper);
        // 将分页数据转换为Result对象
        return Result.success(resultPage);
    }

    @Override
    public Result updatePetTrainingService(PetTrainingService petTrainingService) {
        // 1. 参数校验
        if (petTrainingService == null) {
            return Result.error("-1", "请求体不能为空");
        }
        if (petTrainingService.getId() == null || petTrainingService.getId() <= 0) {
            return Result.error("-1", "ID 不能为空且必须大于 0");
        }

        // 2. 执行更新（MyBatis-Plus 根据 ID 更新非空字段）
        boolean updated = this.updateById(petTrainingService);

        // 3. 返回结果
        if (updated) {
            return Result.success(petTrainingService);
        } else {
            return Result.error("-1", "更新失败，可能记录不存在");
        }
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID 列表不能为空");
        }
        // 调用IService的removeByIds方法批量删除数据
        boolean deleted = this.removeByIds(ids);
        // 判断是否全部删除成功
        if (deleted) {
            return Result.success();
        } else {
            return Result.error("-1", "批量删除失败，可能记录不存在或已被删除");
        }
    }

    @Override
    public Result savePetTrainingService(PetTrainingService petTrainingService) {
        // 1. 设置默认完成状态
        petTrainingService.setCompletionStatus("未开始");

        // 2. 执行数据库插入
        int rows = petTrainingServiceDao.insert(petTrainingService);

        // 3. 根据插入结果返回成功/失败
        if (rows > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "训练服务添加失败");
        }
    }
}
```

创建对应Dao层接口PetTrainingServiceDao

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.PetTrainingService;

public interface PetTrainingServiceDao extends BaseMapper<PetTrainingService> {
}
```

### 5 实现宠物美容服务管理

首先创建PetGroomingService实体类，对应数据库pet_grooming_services表

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;

/**
 * 宠物美容服务实体类，对应数据库表 pet_grooming_services
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("pet_grooming_services")
public class PetGroomingService {

    /**
     * 服务的唯一标识符，主键，自动递增
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 宠物的名称
     */
    private String petName;

    /**
     * 预约服务的用户名（宠物主人）
     */
    private String username;

    /**
     * 美容服务进行的日期（不包含时间）
     */
    private LocalDate serviceDate;

    /**
     * 美容服务的类型（如：洗澡、修剪、造型等）
     */
    private String serviceType;

    /**
     * 记录创建的日期（仅日期部分，默认由业务逻辑或数据库设置）
     */
    private LocalDate createdAt;

    /**
     * 服务当前状态（如：未开始、服务中、完成）
     */
    private String status;
}
```

PetGroomingServiceController

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.PetGroomingService;
import com.qf.service.PetGroomingServiceService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/petGroomingService")
public class PetGroomingServiceController {

    @Autowired
    private PetGroomingServiceService petGroomingServiceService;

    /**
     * 查询宠物理疗服务列表
     * @param petName
     * @param username
     * @param pageNum
     * @param pageSize
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
        @RequestParam(defaultValue = "") String petName,
        @RequestParam(defaultValue = "") String username,
        @RequestParam(defaultValue = "1") Integer pageNum,
        @RequestParam(defaultValue = "10") Integer pageSize) {
        return petGroomingServiceService.selectPage(petName, username, pageNum, pageSize);
    }

    /**
     * 根据id批量删除宠物理疗服务
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return petGroomingServiceService.deleteBatch(ids);
    }


    @RequestMapping("/update")
    public Result updateById(@RequestBody PetGroomingService petGroomingService) {
        return petGroomingServiceService.updatePetGroomingService(petGroomingService);
    }

    @RequestMapping("/save")
    public Result save(@RequestBody PetGroomingService petGroomingService) {
        return petGroomingServiceService.savePetGroomingService(petGroomingService);
    }

}
```

PetGroomingServiceService

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Ppackage com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.PetGroomingService;

import java.util.List;

public interface PetGroomingServiceService extends IService<PetGroomingService> {
    Result selectPage(String petName, String username, Integer pageNum, Integer pageSize);

    Result deleteBatch(List<Integer> ids);

    Result updatePetGroomingService(PetGroomingService petGroomingService);

    Result savePetGroomingService(PetGroomingService petGroomingService);
}
etGroomingService;

import java.util.List;

public interface PetGroomingServiceService extends IService<PetGroomingService> {
    Result selectPage(String petName, String username, Integer pageNum, Integer pageSize);

    Result deleteBatch(List<Integer> ids);

    Result updatePetGroomingService(PetGroomingService petGroomingService);

    Result savePetGroomingService(PetGroomingService petGroomingService);
}
```

创建对应实现类PetGroomingServiceServiceImpl，重写所有抽象方法。

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.PetGroomingServiceDao;
import com.qf.entity.PetGroomingService;
import com.qf.service.PetGroomingServiceService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;

@Service
public class PetGroomingServiceServiceImpl extends ServiceImpl<PetGroomingServiceDao, PetGroomingService> implements PetGroomingServiceService {

    @Autowired
    private PetGroomingServiceDao petGroomingServiceDao;

    @Override
    public Result selectPage(String petName, String username, Integer pageNum, Integer pageSize) {

        LambdaQueryWrapper<PetGroomingService> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(petName)) {
            queryWrapper.like(PetGroomingService::getPetName, petName);
        }
        if (StringUtils.isNotBlank(username)) {
            queryWrapper.like(PetGroomingService::getUsername, username);
        }

        Page<PetGroomingService> page = new Page<>(pageNum, pageSize);
        Page<PetGroomingService> resultPage = this.page(page, queryWrapper);

        return Result.success(resultPage);
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID 列表不能为空");
        }

        int i = petGroomingServiceDao.deleteBatchIds(ids);
        if (i != ids.size()) {
            return Result.error("-1", "删除失败");
        }
        return Result.success();
    }

    @Override
    public Result updatePetGroomingService(PetGroomingService petGroomingService) {
        if (petGroomingService == null) {
            return Result.error("-1", "请求体不能为空");
        }
        if (petGroomingService.getId() == null || petGroomingService.getId() <= 0) {
            return Result.error("-1", "ID 不能为空且必须大于 0");
        }
        // 更新宠物美容服务
        boolean updated = this.updateById(petGroomingService);

        // 判断更新是否成功
        if (updated) {
            // 更新成功
            return Result.success();
        } else {
            // 更新失败
            return Result.error("-1", "更新失败，记录可能不存在");
        }
    }

    @Override
    public Result savePetGroomingService(PetGroomingService petGroomingService) {
        // 设置默认状态
        petGroomingService.setStatus("未开始");

        petGroomingService.setCreatedAt(LocalDate.from(LocalDateTime.now()));

        // 执行插入
        int res = petGroomingServiceDao.insert(petGroomingService);
        return res>0?Result.success():Result.error("-1","添加失败");
    }
}
```

创建对应dao层接口PetGroomingServiceDao

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.PetGroomingService;

public interface PetGroomingServiceDao extends BaseMapper<PetGroomingService> {
}
```

#### 6 实现宠物医疗服务管理

医疗服务模块的结构与美容服务完全一致。创建PetMedicalService实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDate;

/**
 * 宠物医疗服务实体类，对应数据库表 pet_medical_services
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("pet_medical_services")
public class PetMedicalService {

    /**
     * 服务的唯一标识符，主键，自动递增
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 宠物的名称，不允许为空
     */
    private String petName;

    /**
     * 预约服务的用户名（宠物主人），不允许为空
     */
    private String username;

    /**
     * 医疗服务的类型（如：疫苗接种、绝育、体检等），不允许为空
     */
    private String type;

    /**
     * 服务预约或执行的日期，不允许为空
     */
    private LocalDate date;

    /**
     * 服务的详细描述信息（可选）
     */
    private String description;

    /**
     * 记录创建的日期（仅日期部分），插入后不可更新
     */
    private LocalDate createdAt;

    /**
     * 服务当前状态（如：已预约、已完成、已取消等）
     */
    private String status;
}
```

创建PetMedicalServiceController，路径前缀为`/petMedicalService`，包含selectPage、deleteBatch、update、save四个标准方法

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.PetMedicalService;
import com.qf.service.PetMedicalServiceService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/petMedicalService")
public class PetMedicalServiceController {

    @Autowired
    private PetMedicalServiceService petMedicalServiceService;

    /**
     * 查询宠物医疗服务列表
     * @param petName
     * @param username
     * @param pageNum
     * @param pageSize
     * @return
     */
    @RequestMapping("/selectPage")
    public Result selectPage(
        @RequestParam(defaultValue = "") String petName,
        @RequestParam(defaultValue = "") String username,
        @RequestParam(defaultValue = "1") Integer pageNum,
        @RequestParam(defaultValue = "10") Integer pageSize) {
        return petMedicalServiceService.selectPage(petName, username, pageNum, pageSize);
    }

    /**
     * 根据id批量删除宠物医疗服务
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return petMedicalServiceService.deleteBatchStrict(ids);
    }

    /**
     * 根据id更改宠物医疗服务
     * @param petMedicalService
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody PetMedicalService petMedicalService) {
        return petMedicalServiceService.updatePetMedicalService(petMedicalService);
    }

    @RequestMapping("/save")
    public Result save(@RequestBody PetMedicalService petMedicalService) {
        return petMedicalServiceService.create(petMedicalService);
    }
}
```

创建对应服务层接口PetMedicalServiceService

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.PetMedicalService;

import java.util.List;

public interface PetMedicalServiceService extends IService<PetMedicalService> {
    Result selectPage(String petName, String username, Integer pageNum, Integer pageSize);

    Result deleteBatchStrict(List<Integer> ids);

    Result updatePetMedicalService(PetMedicalService petMedicalService);

    Result create(PetMedicalService petMedicalService);
}
```

创建对应实现类PetMedicalServiceServiceImpl，重写所有抽象方法。构造函数注入Dao

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.PetMedicalServiceDao;
import com.qf.entity.PetMedicalService;
import com.qf.service.PetMedicalServiceService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.List;

@Service
public class PetMedicalServiceServiceImpl extends ServiceImpl<PetMedicalServiceDao, PetMedicalService> implements PetMedicalServiceService {
    private final PetMedicalServiceDao petMedicalServiceDao;

    public PetMedicalServiceServiceImpl(PetMedicalServiceDao petMedicalServiceDao) {
        this.petMedicalServiceDao = petMedicalServiceDao;
    }

    @Override
    public Result selectPage(String petName, String username, Integer pageNum, Integer pageSize) {

        LambdaQueryWrapper<PetMedicalService> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(petName)) {
            queryWrapper.like(PetMedicalService::getPetName, petName);
        }
        if (StringUtils.isNotBlank(username)) {
            queryWrapper.like(PetMedicalService::getUsername, username);
        }
        Page<PetMedicalService> page = new Page<>(pageNum, pageSize);
        Page<PetMedicalService> resultPage = this.page(page, queryWrapper);

        return Result.success(resultPage);
    }

    @Override
    public Result deleteBatchStrict(List<Integer> ids) {
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "ID 列表不能为空");
        }
        boolean success = this.removeByIds(ids); // 批量删除
        return success ? Result.success() : Result.error("-1", "未删除任何记录，所有 ID 可能均无效");
    }

    @Override
    public Result updatePetMedicalService(PetMedicalService petMedicalService) {
        if (petMedicalService == null) {
            return Result.error("-1", "请求体不能为空");
        }

        Integer id = petMedicalService.getId();
        if (id == null || id <= 0) {
            return Result.error("-1", "ID 不能为空且必须大于 0");
        }

        boolean updated = this.updateById(petMedicalService);

        if (updated) {
            return Result.success();
        } else {
            return Result.error("-1", "更新失败，记录可能不存在");
        }
    }

    @Override
    public Result create(PetMedicalService petMedicalService) {
        // 1. 设置默认字段
        petMedicalService.setStatus("未开始");
        petMedicalService.setCreatedAt(LocalDate.now());

        // 2. 执行插入
        int rows = petMedicalServiceDao.insert(petMedicalService);

        // 3. 返回统一结果
        if (rows > 0) {
            return Result.success();
        } else {
            return Result.error("-1", "添加失败");
        }
    }
}
```

创建对应Dao层接口PetMedicalServiceDao

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.PetMedicalService;

public interface PetMedicalServiceDao extends BaseMapper<PetMedicalService> {
}
```

### 7 实现医疗服务类型管理

医疗服务类型（MedicalServiceType）同样是基础数据维护模块，用于医疗服务中的服务类型下拉选择。路径前缀为`/medicalServiceType`，只需提供selectAll查询全部类型即可。首先创建MedicalServiceType实体类

```
package com.qf.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;

/**
 * 医疗服务类型实体类，用于表示宠物可选的医疗服务种类（如疫苗接种、驱虫、绝育等）。
 * 对应数据库表：medical_service_types
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("medical_service_types")
public class MedicalServiceType {

    /**
     * 服务类型的唯一标识符，主键，自动递增。
     */
    @TableId(type = IdType.AUTO)
    private Integer id;

    /**
     * 医疗服务类型的名称（如"疫苗接种"、"体检"），不能为空。
     */
    private String name;

    /**
     * 对该医疗服务类型的详细描述（可选），用于向用户说明服务内容。
     */
    private String description;
}
```

创建MedicalServiceTypeController，路径前缀为`/medicalServiceType`

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.service.MedicalServiceTypeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/medicalServiceType")
public class MedicalServiceTypeController {

    @Autowired
    private MedicalServiceTypeService medicalServiceTypeService;

    /**
     * 查询所有医疗服务类型
     * @return
     */
    @RequestMapping("/selectAll")
    public Result selectAll() {
        return medicalServiceTypeService.selectAll();
    }
}
```

创建对应服务层接口MedicalServiceTypeService

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.MedicalServiceType;

public interface MedicalServiceTypeService extends IService<MedicalServiceType> {
    Result selectAll();
}
```

创建对应实现类MedicalServiceTypeServiceImpl，重写selectAll方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.MedicalServiceTypeDao;
import com.qf.entity.MedicalServiceType;
import com.qf.service.MedicalServiceTypeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class MedicalServiceTypeServiceImpl extends ServiceImpl<MedicalServiceTypeDao, MedicalServiceType> implements MedicalServiceTypeService {

    @Autowired
    private MedicalServiceTypeDao medicalServiceTypeDao;

    @Override
    public Result selectAll() {
        LambdaQueryWrapper<MedicalServiceType> queryWrapper = new LambdaQueryWrapper<>();
        List<MedicalServiceType> list = this.list(queryWrapper);
        if (list.isEmpty()) {
            return Result.error("-1", "未找到服务类型");
        }
        return Result.success(list);
    }
}
```

创建对应Dao层接口

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.MedicalServiceType;

public interface MedicalServiceTypeDao extends BaseMapper<MedicalServiceType> {
}
```

至此，宠物服务管理模块全部完成，包括寄养服务、流浪宠物上报、训练项目管理、训练申请、美容服务、医疗服务六个业务模块以及医疗服务类型一个基础数据模块。这些模块遵循统一的分层架构：Controller接收请求、Service处理业务逻辑、Dao层完成数据持久化，代码结构清晰、易于维护和扩展。

## 十五. 实现首页数据展示功能

数据展示模块（Show）为管理员仪表盘提供统计数据，包括系统综合统计、宠物状态分布、宠物品种分布以及领养趋势数据。所有复杂查询逻辑封装在Service层。

创建StatisticsVO视图对象，用于封装系统综合统计数据

```
package com.qf.vo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.math.BigDecimal;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class StatisticsVO {
    private Long animalCount;
    private Long availableCount;
    private Long userCount;
    private Long newUserCount;
    private Long adoptCount;
    private Long monthAdoptCount;
    private Long orderCount;
    private BigDecimal totalAmount;
    private Long fosterCount;
    private Long currentFosterCount;
}
```

创建枚举类AdoptEnum

```
package com.qf.enums;

public enum AdoptEnum {
    ADOPTING("领养中"),
    NO_ADOPT("待领养"),
    PENDING_REVIEW("审核中"),
    REJECTED("审核不通过");

    private String info;

    AdoptEnum(String info) {
        this.info = info;
    }

    public String getInfo() {
        return info;
    }
}
```

创建ShowController，控制层只做请求转发，不包含任何业务逻辑

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.service.ShowService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/show")
public class ShowController {

    @Autowired
    private ShowService showService;

    /**
     * 获取领养数据趋势
     */
    @RequestMapping("/getAdoptTrend")
    public Result getAdoptTrend() {
        return showService.getAdoptTrend();
    }

    /**
     * 获取系统综合统计数据
     */
    @GetMapping("/getStatistics")
    public Result getStatistics() {
        return showService.getStatistics();
    }

    /**
     * 获取宠物状态分布数据
     */
    @GetMapping("/getAnimalStatus")
    public Result getAnimalStatus() {
        return showService.getAnimalStatus();
    }

    /**
     * 获取宠物品种分布数据
     */
    @GetMapping("/getAnimalBreed")
    public Result getAnimalBreed() {
        return showService.getAnimalBreed();
    }
}
```

创建ShowService接口，定义仪表盘统计数据的业务方法

```
package com.qf.service;

import com.qf.utils.Result;

public interface ShowService {
    Result getAdoptTrend();

    Result getStatistics();

    Result getAnimalStatus();

    Result getAnimalBreed();
}
```

创建ShowServiceImpl实现类。核心业务逻辑：通过注入各Dao执行聚合查询（COUNT、SUM等），计算可领养宠物数、本月新增领养数、订单总金额、当前寄养数等统计指标，以及宠物状态分布和品种分布数据。所有复杂计算在此层完成

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.qf.utils.Result;
import com.qf.dao.*;
import com.qf.entity.*;
import com.qf.enums.AdoptEnum;
import com.qf.enums.FosterStatus;
import com.qf.enums.OrderStatus;
import com.qf.service.AdoptService;
import com.qf.service.ShowService;
import com.qf.vo.StatisticsVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Service
public class ShowServiceImpl implements ShowService {

    @Autowired
    private AdoptService adoptService;

    @Autowired
    private AnimalDao animalDao;

    @Autowired
    private UserDao userDao;

    @Autowired
    private AdoptDao adoptDao;

    @Autowired
    private OrdersDao ordersDao;

    @Autowired
    private FosterDao fosterDao;

    @Autowired
    private GoodsDao goodsDao;

    @Autowired
    private BreedDao breedDao;

    /**
     * 获取领养数据趋势（委托给AdoptService处理）
     */
    @Override
    public Result getAdoptTrend() {
        return adoptService.getAdoptTrend();
    }

    /**
     * 获取系统综合统计数据
     * 计算逻辑：查询各表总数 + 条件筛选 + 金额聚合
     */
    @Override
    public Result getStatistics() {
        try {
            // 基础统计数据
            Long animalCount = animalDao.selectCount(null);
            Long userCount = userDao.selectCount(null) - 1;  // 减去管理员账号
            Long adoptCount = adoptDao.selectCount(null);
            Long orderCount = ordersDao.selectCount(null);
            Long fosterCount = fosterDao.selectCount(null);

            // 可领养宠物数量：状态为"可领养"
            Long availableCount = animalDao.selectCount(
                    new QueryWrapper<Animal>().eq("status", AdoptEnum.NO_ADOPT.getInfo())
            );

            // 本月新增用户数（暂设为0，因无create_time字段）
            Long newUserCount = 0L;

            // 本月领养数量
            LocalDate firstDayOfMonth = LocalDate.now().withDayOfMonth(1);
            Long monthAdoptCount = adoptDao.selectCount(
                    new QueryWrapper<Adopt>().ge("time", firstDayOfMonth.toString())
            );

            // 已完成订单总金额
            List<Orders> orders = ordersDao.selectList(
                    new LambdaQueryWrapper<Orders>()
                            .eq(Orders::getStatus, OrderStatus.Completed.name())
            );
            BigDecimal totalAmount = BigDecimal.ZERO;
            if (orders != null) {
                for (Orders order : orders) {
                    if (order != null && order.getTotalAmount() != null) {
                        Goods goods = goodsDao.selectById(order.getGoodsId());
                        totalAmount = totalAmount.add(goods.getPrice().multiply(BigDecimal.valueOf(order.getNum())));
                    }
                }
            }

            // 当前寄养中的数量
            Long currentFosterCount = fosterDao.selectCount(
                    new QueryWrapper<Foster>().eq("status", FosterStatus.Fostering.getInfo())
            );

            StatisticsVO statistics = new StatisticsVO(
                    animalCount, availableCount, userCount, newUserCount,
                    adoptCount, monthAdoptCount, orderCount, totalAmount,
                    fosterCount, currentFosterCount
            );

            return Result.success(statistics);
        } catch (Exception e) {
            return Result.error("-1", "获取统计数据失败：" + e.getMessage());
        }
    }

    /**
     * 获取宠物状态分布数据（如：可领养、已领养等各状态的数量）
     */
    @Override
    public Result getAnimalStatus() {
        try {
            List<Map<String, Object>> statusData = animalDao.selectStatusDistribution();
            return Result.success(statusData);
        } catch (Exception e) {
            return Result.error("-1", "获取宠物状态分布数据失败：" + e.getMessage());
        }
    }

    /**
     * 获取宠物品种分布数据（各品种的宠物数量统计）
     */
    @Override
    public Result getAnimalBreed() {
        try {
            List<Breed> breeds = breedDao.selectList(null);
            List<Map<String, Object>> breedData = new ArrayList<>();

            // 统计每个品种的宠物数量
            for (Breed breed : breeds) {
                Long count = animalDao.selectCount(
                        new QueryWrapper<Animal>().eq("breed", breed.getBreedName())
                );
                if (count > 0) {
                    Map<String, Object> item = new HashMap<>();
                    item.put("breed", breed.getBreedName());
                    item.put("count", count);
                    breedData.add(item);
                }
            }

            // 统计未分类的宠物
            Long otherCount = animalDao.selectCount(
                    new QueryWrapper<Animal>().isNull("breed").or().eq("breed", "")
            );
            if (otherCount > 0) {
                Map<String, Object> otherItem = new HashMap<>();
                otherItem.put("breed", "其他");
                otherItem.put("count", otherCount);
                breedData.add(otherItem);
            }

            return Result.success(breedData);
        } catch (Exception e) {
            return Result.error("-1", "获取宠物品种分布数据失败：" + e.getMessage());
        }
    }
}
```

我们的获取领养数据趋势功能写在对应service接口模块中

在**AdoptService**中创建**getAdoptTrend**方法用于获取领养数据趋势

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Adopt;

import java.util.List;

public interface AdoptService extends IService<Adopt> {
    Result selectPage(String name, Integer currentPage, Integer size);

    Result deleteBatch(List<Integer> ids);

    Result updateAdopt(Adopt adopt);

    Result getAdoptTrend();
}
```

对应的**AdoptServiceImpl**重写getAdoptTrend抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.dao.AnimalDao;
import com.qf.entity.Animal;
import com.qf.enums.AnimalEnum;
import com.qf.utils.Result;
import com.qf.dao.AdoptDao;
import com.qf.entity.Adopt;
import com.qf.vo.AdoptVO;
import com.qf.service.AdoptService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.List;
import java.util.Map;

@Service
public class AdoptServiceImpl extends ServiceImpl<AdoptDao, Adopt> implements AdoptService {

    // 注入AdoptDao
    @Autowired
    private AdoptDao adoptDao;

    @Autowired
    private AnimalDao animalDao;

    @Override
    public Result selectPage(String name, Integer currentPage, Integer size) {
        // 创建Page对象,设置当前页和每页显示的数量
        Page<AdoptVO> page = new Page<>(currentPage, size);
        // 调用AdoptDao的selectByPage方法,传入name和Page对象,返回Page对象
        Page<AdoptVO> adoptPage = adoptDao.selectByPage(name, page);
        // 返回封装了Page对象和数据的Result对象
        return Result.success(adoptPage);
    }

    @Override
    public Result deleteBatch(List<Integer> ids) {
        // 调用AdoptDao的deleteBatchIds方法,传入ids列表,返回成功删除的数量
        int success = adoptDao.deleteBatchIds(ids);
        // 判断成功删除的数量和ids列表的大小是否一致,如果一致,返回成功消息,否则返回部分删除失败的消息
        //.size()方法获取ids列表的大小
        if (success == ids.size()) {
            // 全部删除成功
            return Result.success();
        } else {
            // 部分删除失败
            return Result.error("-1", "部分删除失败");
        }
    }

    @Override
    public Result updateAdopt(Adopt adopt) {
        // 如果领养状态改为"已归还"，需要同步更新宠物状态
        if (AnimalEnum.ADOPT_CANCEL.getInfo().equals(adopt.getStatus())) {
            // 已归还我们需要把宠物信息的状态同步成 待领养
            Animal animal = animalDao.selectById(adopt.getAnimalId());
            animal.setStatus(AnimalEnum.NO_ADOPT.getInfo());
            animalDao.updateById(animal);
        }
        // 执行领养记录更新
        int i = adoptDao.updateById(adopt);
        if (i > 0) {
            return Result.success();
        }
        return Result.error("-1", "更新失败");
    }

    @Override
    public Result getAdoptTrend() {
        //
        LocalDate endDate = LocalDate.now();
        LocalDate startDate = endDate.minusYears(1);
        List<Map<String, Object>> trendData = adoptDao.selectAdoptTrend(startDate.toString(), endDate.toString());
        return Result.success(trendData);
    }

}
```

在对应AdoptDao中添加抽象方法selectAdoptTrend

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.qf.entity.Adopt;
import com.qf.vo.AdoptVO;
import org.apache.ibatis.annotations.Param;

import java.util.List;
import java.util.Map;

public interface AdoptDao extends BaseMapper<Adopt> {
    //@Param注解用于给参数取别名，在xml中使用时，需要使用别名来引用参数
    Page<AdoptVO> selectByPage(@Param("name") String name, Page<AdoptVO> page);

    List<Map<String, Object>> selectAdoptTrend(@Param("startDate") String startDate, @Param("endDate") String endDate);
}
```

在resources/mapper/AdoptDao.xml文件中添加查询语句

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.qf.dao.AdoptDao">

  <!-- 定义名为AdoptResultMap的结果映射，映射到com.qf.vo.AdoptVO类型 -->
  <resultMap id="AdoptResultMap" type="com.qf.vo.AdoptVO">
    <!-- 映射id字段，对应数据库中的id列 -->
    <id property="id" column="id"/>
    <!-- 映射userName字段，对应数据库中的userName列 -->
    <result property="userName" column="userName"/>
    <!-- 映射animalImg字段，对应数据库中的animalImg列 -->
    <result property="animalImg" column="animalImg"/>
    <!-- 映射animalName字段，对应数据库中的animalName列 -->
    <result property="animalName" column="animalName"/>
  </resultMap>


  <!-- 定义名为selectByPage的查询语句，使用AdoptResultMap作为结果映射 -->
  <select id="selectByPage" resultMap="AdoptResultMap">
    <!-- 选择所有列，并从user表中选择name列作为userName，从animal表中选择img列作为animalImg，从animal表中选择name列作为animalName -->
    SELECT a.*, u.name AS userName, an.img AS animalImg, an.name AS animalName
    <!-- 从adopt表中选择数据 -->
    FROM adopt a
    <!-- 左连接user表，条件是adopt表的user_id等于user表的id -->
    LEFT JOIN user u ON a.user_id = u.id
    <!-- 左连接animal表，条件是adopt表的animal_id等于animal表的id -->
    LEFT JOIN animal an ON a.animal_id = an.id
    <!-- 动态条件过滤 -->
    <where>
      <!-- 如果name不为空且不为空字符串，则添加模糊查询条件 -->
      <!-- CONCAT函数用于拼接字符串 -->
      <if test="name != null and name != ''">
        AND an.name LIKE CONCAT('%', #{name}, '%')
      </if>

    </where>

  </select>
  <select id="selectAdoptTrend" resultType="java.util.Map">
    SELECT
    DATE(time) AS date,
    COUNT(*) AS count
    FROM adopt
    WHERE time BETWEEN #{startDate} AND #{endDate}
    GROUP BY DATE(time)
    ORDER BY date
  </select>


</mapper>
```

获取宠物状态分布数据也需要写在对应的模块中

在AnimalDao接口中创建抽象方法selectStatusDistribution

```
package com.qf.dao;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.qf.entity.Animal;

import java.util.List;
import java.util.Map;

public interface AnimalDao extends BaseMapper<Animal> {
    List<Map<String, Object>> selectStatusDistribution();
}
```

在resources/mapper下创建AnimalDao.xml文件中添加查询语句

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.qf.dao.AnimalDao">

  <select id="selectStatusDistribution" resultType="java.util.Map">
    SELECT
    status,
    COUNT(*) AS count
    FROM animal
    GROUP BY status
  </select>
</mapper>
```

## 十六. 实现用户端功能

### 1 首先会查询所有商品,宠物以及轮播图信息请求对应的地址为:

```
查询所有商品 : http://localhost:8080/api/goods/selectAll
查询所有宠物 : http://localhost:8080/api/animal/selectAll
查询所有轮播图 : http://localhost:8080/api/slider/selectAll
```

已查询所有商品示例

在对应控制层GoodsController添加方法selectAll

```
package com.qf.controller;

import com.qf.utils.Result;
import com.qf.entity.Goods;
import com.qf.service.GoodsService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/goods")
public class GoodsController {

    @Autowired
    private GoodsService goodsService;


    /**
     * 获取商品列表数据
     * @param name
     * @param currentPage
     * @param size
     * @return
     */
    @RequestMapping("/page")
    public Result getGoodsByPage(
            @RequestParam(defaultValue = "") String name,
            @RequestParam(defaultValue = "1") Integer currentPage,
            @RequestParam(defaultValue = "10") Integer size) {
        //调用service层方法获取商品列表数据
        return goodsService.getGoodsByPage(name, currentPage, size);
    }

    /**
     * 根据id批量删除商品
     * @param ids
     * @return
     */
    @RequestMapping("/deleteBatch")
    public Result deleteBatch(@RequestParam List<Integer> ids) {
        return goodsService.deleteBatchGoods(ids);
    }

    /**
     * 保存商品信息
     * @param goods
     * @return
     */
    @RequestMapping("/save")
    public Result save(@RequestBody Goods goods) {
        return goodsService.saveGoods(goods);
    }

    /**
     * 根据id更新商品信息
     * @param goods
     * @return
     */
    @RequestMapping("/update")
    public Result updateById(@RequestBody Goods goods) {
        return goodsService.updateGoods(goods);
    }

    /**
     * 获取所有商品信息
     * @return
     */
    @RequestMapping("/selectAll")
    public Result selectAll() {
        return goodsService.selectAllGoods();
    }
}
```

在对应服务层GoodsService接口创建selectAllGoods抽象方法

```
package com.qf.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.qf.utils.Result;
import com.qf.entity.Goods;

import java.util.List;

public interface GoodsService extends IService<Goods> {
    Result getGoodsByPage(String name, Integer currentPage, Integer size);

    Result deleteBatchGoods(List<Integer> ids);

    Result saveGoods(Goods goods);

    Result updateGoods(Goods goods);

    Result selectAllGoods();
}
```

在对应GoodsServiceImpl实现类中重写selectAllGoods抽象方法

```
package com.qf.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.qf.utils.Result;
import com.qf.dao.GoodsDao;
import com.qf.entity.Goods;
import com.qf.service.GoodsService;
import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class GoodsServiceImpl extends ServiceImpl<GoodsDao, Goods> implements GoodsService {

    //注入GoodsDao
    @Autowired
    private GoodsDao goodsDao;


    @Override
    public Result getGoodsByPage(String name, Integer currentPage, Integer size) {
        // 构建分页对象
        Page<Goods> page = new Page<>(currentPage, size);
        // 构建动态查询条件
        LambdaQueryWrapper<Goods> queryWrapper = new LambdaQueryWrapper<>();
        if (StringUtils.isNotBlank(name)) {
            queryWrapper.like(Goods::getName, name);
        }
        // 执行分页查询
        Page<Goods> goodsPage = goodsDao.selectPage(page, queryWrapper);
        // 返回成功结果
        return Result.success(goodsPage);
    }

    @Override
    public Result deleteBatchGoods(List<Integer> ids) {

        // 参数校验
        if (ids == null || ids.isEmpty()) {
            return Result.error("-1", "商品ID列表不能为空");
        }

        // 调用BaseMapper的deleteBatchIds方法批量删除商品
        int deletedCount = goodsDao.deleteBatchIds(ids);

        // 判断结果与参数列表长度是否一致
        if (deletedCount == ids.size()) {
            // 全部删除成功
            return Result.success();
            // 部分成功
        } else if (deletedCount > 0) {
            // 部分成功（有些 ID 不存在）
            return Result.error("-1", "部分商品不存在，仅删除 " + deletedCount + " 条");
        } else {
            // 全部失败（所有 ID 都不存在）
            return Result.error("-1", "未找到要删除的商品");
        }
    }

    @Override
    public Result saveGoods(Goods goods) {
        // 参数校验
        if (goods == null) {
            return Result.error("-1", "商品信息不能为空");
        }
        // 执行插入（MyBatis-Plus 自动填充 id 等字段）
        int inserted = goodsDao.insert(goods);

        // 判断结果
        if (inserted > 0) {
            // 插入成功
            return Result.success(goods); // 返回带 ID 的实体更友好
        } else {
            // 插入失败
            return Result.error("-1", "添加失败");
        }
    }

    @Override
    public Result updateGoods(Goods goods) {
        // 参数校验
        if (goods == null || goods.getId() == null) {
            return Result.error("-1", "商品ID不能为空");
        }
        //调用BaseMapper的updateById方法更新商品
        int updated = goodsDao.updateById(goods);
        //判断结果
        if (updated > 0) {
            //更新成功
            return Result.success();
        } else {
            //更新失败
            return Result.error("-1", "更新失败：商品可能不存在或未修改任何字段");
        }
    }
    @Override
    public Result selectAllGoods() {
        QueryWrapper<Goods> queryWrapper = new QueryWrapper<>();
        List<Goods> goodsList = goodsDao.selectList(queryWrapper);
        if (goodsList == null) {
            return Result.error("-1", "商品数据加载异常");
        }
        return Result.success(goodsList);
    }
}
```

[^1]: Java Web 的“老祖宗”和底层地基。在没有各种高级框架的年代，只要你想用 Java 接收网页请求，就必须继承 `HttpServlet` 并重写 `doGet` 或 `doPost` 方法。Tomcat 之所以能运行 Java 网页，就是因为它是一个“Servlet 容器”。传统 Servlet 采用的是“一个请求对应一个线程”的阻塞模式，在高并发时比较消耗内存。

[^2]: 基于 **M**odel（模型）、**V**iew（视图）、**C**ontroller（控制器）设计模式
	- **Controller（控制器）：** 负责接收前端发来的请求（比如你点的那个前端按钮），并决定调用什么业务逻辑。
	- **Model（模型）：** 承载数据（比如从数据库里查出来的用户信息）。
	- **View（视图）：** 负责把数据渲染成网页（不过现在前后端分离了，View 通常直接退化为返回 JSON 数据）。
