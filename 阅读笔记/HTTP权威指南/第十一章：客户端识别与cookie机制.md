# HTTP 权威指南

## 第 11 章 客户端识别与 cookie 机制

1. 承载用户信息的 HTTP 首部

    1. From
    2. User-Agent
    3. Referer
    4. Authorization
    5. Client-IP：客户端 IP 地址描述的是所用的机器而不是用户
    6. X-Forwarded-For
    7. Cookie

2. 胖 URL：有些 Web 站点会为每个用户生成特定版本的 URL 来追踪用户的身份。改动了包含用户状态信息的 URL 被称为胖 URL。

3. cookie 分为会话 cookie 和持久 cookie，会话 cookie 是一种临时 cookie，它记录了用户访问站点时的设置和偏好。用户退出浏览器时，会话 cookie 就被删除了。持久 cookie 的生存时间更长一些，它们存储在硬盘上，浏览器退出，计算机重启时它们仍然存在。通常会用持久 cookie 维护某个用户会周期性访问的站点的配置文件或登录名。

4. cookie 的域属性：产生 cookie 的服务器可以向 Set-Cookie 响应首部添加一个 Domain 属性来控制哪些站点可以看到那个 cookie。

5. cookie 的路径属性：cookie 规范允许用户将 cookie 与部分 Web 站点关联起来。可以通过 Path 属性来实现这一功能，在这个属性列出的 URL 路径前缀下所有 cookie 都是有效的。
