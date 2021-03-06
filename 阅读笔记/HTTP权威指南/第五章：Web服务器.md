# HTTP 权威指南

## 第 5 章 Web 服务器

1. Web 服务器实现了 HTTP 和相关的 TCP 连接处理。负责管理 Web 服务器提供的资源，以及对 Web 服务器的配置、控制及扩展方面的管理。

2. Web 服务器有各种不同的形式：

    1. 可以在标准的计算机系统上安装并运行通用的软件 Web 服务器。
    2. 可以买一台 Web 服务器设备，里面的软件会预装并配置好。
    3. 可以在少量计算机芯片上实现嵌入式 Web 服务器。

3. 通用软件 Web 服务器都运行在标准的、有网络功能的计算机系统上。

4. 实际的 Web 服务器会做些什么：

    1. 建立连接：接受一个客户端连接，或者如果不希望与这个客户端建立连接，就将其关闭。
    2. 接收请求：从网络中读取一条 HTTP 请求报文。
    3. 处理请求：对请求报文进行解释，并采取行动。
    4. 访问资源：访问报文中指定的资源。
    5. 构建响应：创建带有正确首部的 HTTP 响应报文。
    6. 发送响应：将响应回送给客户端。
    7. 记录事务处理过程：将与已完成事务有关的内容记录在一个日志文件中。

5. 处理新连接：客户端请求一条到 Web 服务器的 TCP 连接时，Web 服务器会建立连接，判断连接的另一端是哪个客户端，从 TCP 连接中将 IP 地址解析出来。一旦新连接建立起来并被接受，服务器就会将新连接添加到其现存 Web 服务器连接列表中，做好监视连接上数据传输的准备。

6. 客户端主机名识别：可以用“反向 DNS”对大部分 Web 服务器进行配置，以便将客户端 IP 地址转换成客户端主机名。Web 服务器可以将客户端主机名用于详细的访问控制和日志记录。

7. 通过 ident 确定客户端用户：有些 Web 服务器还支持 IETF 的 ident 协议。服务器可以通过 ident 协议找到发起 HTTP 连接的用户名。

8. 解析请求报文：

    1. 解析请求行，查找请求方法、指定的资源标识符以及版本号。
    2. 读取以 CRLF 结尾的报文首部。
    3. 检测到以 CRLF 结尾的、标识首部结束的空行。
    4. 如果有请求主体就读取请求主体。

9. 报文的内部表示法：有些服务器还会用便于进行报文操作的内部数据结构来存储请求报文。

10. 不同的服务器结构会以不同的方式为请求服务：

    1. 单线程 Web 服务器：一次只处理一个请求，直到其完成为止。一个事务处理结束之后，才去处理下一条连接。
    2. 多进程及多线程 Web 服务器：用多个进程或更高效的线程同时对请求进行处理。
    3. 复用 I/O 的服务器：可以支持大量的连接。在复用结构中，要同时监视所有连接上的活动。当连接的状态发生变化时，就对那条连接进行少量的处理，处理结束之后将连接返回到开放连接列表中，等待下一次状态变化。在空闲连接上等待的时候并不会绑定线程和进程。
    4. 复用的多线程 Web 服务器：有些系统会将多线程和复用功能结合在一起，以利用计算机平台上的多个 CPU。多个线程中的每一个都在观察打开的连接，并对每条连接执行少量的任务。

11. 响应报文中通常包括：

    1. 描述了响应主体 MIME 类型的 Content-Type 首部；
    2. 描述了响应主体长度的 Content-Length 首部；
    3. 实际报文的主体内容。

12. 重定向：Web 服务器有时会返回重定向响应而不是成功的报文。
    1. 永久搬离的资源：资源可能已经被移动到了新的位置，或者被重新命名，有了一个新的 URL。响应 301 状态码。
    2. 临时搬离的资源：如果资源被临时移走或重命名了，服务器可能希望将客户端重定向到新的位置上去。但由于重命名是临时的，所以服务器希望客户端将来还可以回头去使用老的 URL。响应 303 或 307 状态码。
    3. URL 增强：服务器通常用重定向来重写 URL，往往用于嵌入上下文。当请求到达时，服务器会生成一个新的包含了嵌入式状态信息的 URL，并将用户重定向到这个新的 URL 上去。客户端会跟随这个重定向信息，重新发起请求，但这次请求会包含完整的、经过状态增强的 URL。响应 303 或 307 状态码。
    4. 负载均衡：如果一个超载的服务器收到一条请求，服务器可以将客户端重定向到一个负载不太重的服务器上去。响应 303 或 307 状态码。
    5. 服务器关联：Web 服务器上可能会有某些用户的本地信息，服务器可以将客户端重定向到包含了那个客户端信息的服务器上去。响应 303 或 307 状态码。
    6. 规范目录名称：客户端请求的 URI 是一个不带尾部斜线的目录名时，大多数 Web 服务器都会将客户端重定向到一个加了斜线的 URI 上去。这样相对链接就可以正常工作了。
