---
tags:
  - docker
---

# Docker 常用指令

## 容器生命周期

| 命令                          | 说明           |
| --------------------------- | ------------ |
| `docker run`                | 创建并启动容器      |
| `docker start/stop/restart` | 启动/停止/重启容器   |
| `docker kill`               | 立即终止容器       |
| `docker rm`                 | 删除已停止的容器     |
| `docker pause/unpause`      | 暂停/恢复容器      |
| `docker create`             | 创建容器但不启动     |
| `docker exec`               | 在运行中的容器内执行命令 |
| `docker rename`             | 重命名容器        |

## 容器操作

| 命令                          | 说明             |
| --------------------------- | -------------- |
| `docker ps`                 | 列出容器           |
| `docker inspect`            | 查看容器/镜像/卷/网络详情 |
| `docker top`                | 显示容器内进程        |
| `docker attach`             | 附加到运行中的容器      |
| `docker logs`               | 查看容器日志         |
| docker logs --tail 100 容器ID | 查看容器日志最新的100行  |
| `docker events`             | 获取守护进程事件       |
| `docker wait`               | 等待容器停止并获取退出码   |
| `docker export`             | 导出容器为 tar      |
| `docker port`               | 显示端口映射         |
| `docker stats`              | 实时资源使用情况       |
| `docker update`             | 更新资源限制（内存、CPU） |

## 镜像仓库

| 命令                                              | 说明      |
| ----------------------------------------------- | ------- |
| `docker login/logout`                           | 仓库身份验证  |
| `docker tag myimage:latest name/myimage:latest` | 为镜像打上标签 |
| `docker pull`                                   | 拉取镜像    |
| `docker push`                                   | 推送镜像    |
| `docker search`                                 | 搜索镜像    |

## 本地镜像

| 命令 | 说明 |
|------|------|
| `docker images` | 列出本地镜像 |
| `docker rmi` | 删除镜像 |
| `docker tag` | 创建镜像别名 |
| `docker build` | 从 Dockerfile 构建镜像 |
| `docker history` | 查看镜像历史层 |
| `docker save` | 镜像导出为 tar |
| `docker load` | 从 tar 加载镜像 |
| `docker import` | 从 tar/URL 导入创建镜像 |

## 网络

| 命令 | 说明 |
|------|------|
| `docker network ls` | 列出网络 |
| `docker network create <name>` | 创建网络 |
| `docker network rm <name>` | 删除网络 |
| `docker network connect <net> <container>` | 连接容器到网络 |
| `docker network disconnect <net> <container>` | 断开连接 |

## 卷

| 命令 | 说明 |
|------|------|
| `docker volume ls` | 列出卷 |
| `docker volume create <name>` | 创建卷 |
| `docker volume rm <name>` | 删除卷 |
| `docker volume inspect <name>` | 查看卷详情 |
	
## 系统信息

| 命令 | 说明 |
|------|------|
| `docker info` | 系统信息（镜像数、容器数等） |
| `docker version` | 客户端和服务端版本 |

## Docker Compose

| 命令                                                             | 说明            |
| -------------------------------------------------------------- | ------------- |
| `docker compose run`                                           | 启动容器并运行应用     |
| `docker compose up`                                            | 运行 compose 文件 |
| `docker compose down`                                          | 停止并删除         |
| `docker-compose pull && docker-compose up -d --remove-orphans` |               |
| `docker compose ps`                                            | 查看容器状态        |
| `docker compose build`                                         | 构建            |
| `docker compose ls`                                            | 列出 compose 服务 |
| `docker compose start/restart`                                 | 启动/重启         |
