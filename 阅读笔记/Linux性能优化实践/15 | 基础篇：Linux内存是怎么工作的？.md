Linux 内核给每个进程都提供了一个独立的虚拟地址空间，并且这个地址空间是连续的。这样，进程就可以很方便地访问内存，更确切地说是访问虚拟内存。

虚拟地址空间的内部又被分为内核空间和用户空间两部分，不同字长（也就是单个CPU指令可以处理数据的最大长度）的处理器，地址空间的范围也不同。比如最常见的 32 位和 64 位系统，我画了两张图来分别表示它们的虚拟地址空间，如下所示：

![](https://static001.geekbang.org/resource/image/ed/7b/ed8824c7a2e4020e2fdd2a104c70ab7b.png)

进程在用户态时，只能访问用户空间内存；只有进入内核态后，才可以访问内核空间内存。

内存映射，其实就是将虚拟内存地址映射到物理内存地址。为了完成内存映射，内核为每个进程都维护了一张页表，记录虚拟地址与物理地址的映射关系，如下图所示：
![](https://static001.geekbang.org/resource/image/fc/b6/fcfbe2f8eb7c6090d82bf93ecdc1f0b6.png)

页表实际上存储在 CPU 的内存管理单元 MMU中，这样，正常情况下，处理器就可以直接通过硬件，找出要访问的内存。

虚拟内存空间分布
![](https://static001.geekbang.org/resource/image/71/5d/71a754523386cc75f4456a5eabc93c5d.png)
1. 只读段，包括代码和常量等。
2. 数据段，包括全局变量等。
3. 堆，包括动态分配的内存，从低地址开始向上增长。
4. 文件映射段，包括动态库、共享内存等，从高地址开始向下增长。
5. 栈，包括局部变量和函数调用的上下文等。栈的大小是固定的，一般是 8 MB。

对普通进程来说，它能看到的其实是内核提供的虚拟内存，这些虚拟内存还需要通过页表，由系统映射为物理内存。

当进程通过 malloc() 申请内存后，内存并不会立即分配，而是在首次访问时，才通过缺页异常陷入内核中分配内存。

由于进程的虚拟地址空间比物理内存大很多，Linux 还提供了一系列的机制，应对内存不足的问题，比如缓存的回收、交换分区 Swap 以及 OOM 等。
