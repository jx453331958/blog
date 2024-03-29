磁盘为系统提供了最基本的持久化存储。

文件系统则在磁盘的基础上，提供了一个用来管理文件的树状结构。

在Linux中一切皆文件。不仅普通的文件和目录，就连块设备、套接字、管道等，也都要通过统一的文件系统来管理。

Linux文件系统为每个文件都分配两个数据结构，索引节点（index node）和目录项（directory entry）。它们主要用来记录文件的元信息和目录结构。

索引节点是每个文件的唯一标志，而目录项维护的正是文件系统的树状结构。目录项和索引节点的关系是多对一。

磁盘在执行文件系统格式化时，会被分成三个存储区域，超级块、索引节点区和数据块区。其中，
- 超级块，存储整个文件系统的状态。
- 索引节点区，用来存储索引节点。
- 数据块区，则用来存储文件数据。

系统调用、VFS、缓存、文件系统以及块存储之间的关系: 
![](https://static001.geekbang.org/resource/image/72/12/728b7b39252a1e23a7a223cdf4aa1612.png)

1. 基于磁盘的文件系统: 把数据直接存储在计算机本地挂载的磁盘中。常见的Ext4、XFS、OverlayFS等，都是这类文件系统。
2. 基于内存的文件系统: 虚拟文件系统。这类文件系统，不需要任何磁盘分配存储空间，但会占用内存。我们经常用到的 /proc 文件系统，其实就是一种最常见的虚拟文件系统。此外，/sys 文件系统也属于这一类，主要向用户空间导出层次化的内核对象。
3. 网络文件系统: 用来访问其他计算机数据的文件系统，比如NFS、SMB、iSCSI等。

文件系统I/O:
1. 缓冲与非缓冲I/O(这里所说的“缓冲”，是指标准库内部实现的缓存。比方说，你可能见到过，很多程序遇到换行时才真正输出，而换行前的内容，其实就是被标准库暂时缓存了起来。)
   1. 缓冲I/O，是指利用标准库缓存来加速文件的访问，而标准库内部再通过系统调度访问文件。
   2. 非缓冲I/O，是指直接通过系统调用来访问文件，不再经过标准库缓存。
2. 直接与非直接I/O
   1. 直接I/O，是指跳过操作系统的页缓存，直接跟文件系统交互来访问文件。
   2. 非直接I/O正好相反，文件读写时，先要经过系统的页缓存，然后再由内核或额外的系统调用，真正写入磁盘。
3. 阻塞与非阻塞I/O
   1. 阻塞I/O，是指应用程序执行I/O操作后，如果没有获得响应，就会阻塞当前线程，自然就不能执行其他任务。
   2. 非阻塞I/O，是指应用程序执行I/O操作后，不会阻塞当前的线程，可以继续执行其他的任务，随后再通过轮询或者事件通知的形式，获取调用的结果。
4. 同步与异步I/O
   1. 同步I/O，是指应用程序执行I/O操作后，要一直等到整个I/O完成后，才能获得I/O响应。
   2. 异步I/O，是指应用程序执行I/O操作后，不用等待完成和完成后的响应，而是继续执行就可以。等到这次 I/O完成后，响应会用事件通知的方式，告诉应用程序。
