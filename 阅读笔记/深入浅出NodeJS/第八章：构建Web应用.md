# 深入浅出 NodeJS

## 第 8 章 构建Web应用

1. Set-Cookie的几个选项：
   1. path：表示这个Cookie影响到的路径，当前访问的路径不满足该匹配时，浏览器则不发送这个Cookie
   2. Expires和Max-Age是用来告知浏览器这个Cookie何时过期的，如果不设置该选项，在关闭浏览器时会丢掉这个Cookie。
   3. HttpOnly告诉浏览器不允许通过脚本document.cookie去更改这个cookie值，事实上，设置HttpOnly之后，这个值在document.cookie中不可见。但在HTTP请求中，依然会发送给服务器端。
   4. Secure：当Secure为true时，在HTTP中是无效的，在HTTPS中才有效。

2. 使用缓存服务：
   1. Node与缓存服务保持长连接，而非频繁的短链接，握手导致的延迟只影响初始化；
   2. 高速缓存直接在内存中进行数据存储和访问；
   3. 缓存服务通常与Node进程运行在相同的机器上或者相同的机房里，网络速度受到的影响较小；