#!/usr/bin/env

echo $1

read -e -p "Please input your first name:" firstname
read -e -p "Please input your last name:" lastname
echo "\nYour full name is: $firstname$lastname"
