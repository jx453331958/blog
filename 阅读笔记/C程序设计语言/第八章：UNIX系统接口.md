# C程序设计语言

## 第八章：UNIX系统接口

1. 在UNIX操作系统中，所有的外围设备都被看作是文件系统中的文件，因此，所有的输入/输出都要通过读文件或者写文件完成。也就是说，通过一个单一的接口，就可以处理外围设备和程序之间的所有通信。
2. 任何时候对文件的输入/输出都是通过文件描述符标识文件，而不是通过文件名标识文件。系统负责维护已打开文件的所有信息，用户程序只能通过文件描述符引用文件。
3. 输入与输出是通过read和write系统调用实现的。
4. 随机访问：lseek