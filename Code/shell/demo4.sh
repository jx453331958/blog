#!/usr/bin/env

echo "我将输出3个文件名"
read -p "请输入你的用户名：" username

filename=${username:-"filename"}

echo $filename
