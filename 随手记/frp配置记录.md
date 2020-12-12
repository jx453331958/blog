[文档](https://gofrp.org/docs/)

frps:
```shell
[common]
bind_port = xxx
bind_addr = xxx
token = xxx
vhost_http_port = xxx
vhost_https_port = xxx
```

frpc:
```
[common]
server_addr = xxx
server_port = xxx
token = xxx

[xxx]
type = http
local_port = xxx
custom_domains = xxx

[xxx]
type = https
custom_domains = xxx
plugin = https2http
plugin_local_addr = xxx:xxx
plugin_crt_path = /root/ssl/xxx_chain.crt
plugin_key_path = /root/ssl/xxx.key
plugin_host_header_rewrite = 127.0.0.1
plugin_header_X-From-Where = frp
```

centos使用systemd添加开机自启动frps进程

openwrt使用nohup不挂起进程
```shell
nohup frpc -c frpc.ini > /dev/null 2>&1 &
```

nohup不输出日志信息的方法：https://www.cnblogs.com/jasondan/p/3499175.html

Linux的3中重定向
0:表示标准输入
1:标准输出,在一般使用时，默认的是标准输出
2:标准错误信息输出

关于/dev/null文件

Linux下还有一个特殊的文件/dev/null，它就像一个无底洞，所有重定向到它的信息都会消失得无影无踪。这一点非常有用，当我们不需要回显程序的所有信息时，就可以将输出重定向到/dev/null。