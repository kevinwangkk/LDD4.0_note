
Linux驱动编程实际就是内核编程


/**************************************************/

linux内核由5个子系统组成
	1.进程调度(SCHED)
	2.内存管理(MM)
	3.虚拟文件系统(VFS)
	4.网络接口(NET)
	5.进程间通信(IPC)

/**************************************************/

1. 将驱动编译到 make menuconfig 中  P94

2. lsmod命令可以获得系统中已加载的所有模块以及模块间的依赖关系
	lsmod命令实际上是读取并分析“/proc/modules”文件

3. tree -a  生成目录树 递归到子目录


4. modinfo<模块名>
命令可以获得模块的信息，包括模块作者、模块的说明、模块所支持的参数以
及vermagic

	MODULE_AUTHOR("Barry Song <21cnbao@gmail.com>");
	MODULE_LICENSE("GPL v2");
	MODULE_DESCRIPTION("A simple Hello World Module");
	MODULE_ALIAS("a simplest module");



	/* modinfo hello.ko */

	filename:       /home/baohua/develop/training/kernel/drivers/hello/hello.ko
	alias:          a simplest module
	description:    A simple Hello World Module
	license:        GPL v2
	author:         Barry Song <21cnbao@gmail.com>
	depends:
	vermagic:       4.0.0-rc1 SMP mod_unload 686


/**************************************************/

1. Linux系统文件目录
	/bin		包含基本命令 如ls cp
	/sbin		包含系统命令 如ifconfig
	/dev		设备文件存储目录
	/etc		系统配置文件所在,服务器的配置文件,busybox启动脚本也在该目录
	/lib		系统库文件存放目录
	/mnt		存放挂载储存设备的挂载目录
	/opt		“可选”的意思，有些软件包会被安装在这里
	/proc		操作系统运行时，进程及内核信息（比如CPU、硬盘分区、内存信息等）存放在这里
	/sys		。Linux设备驱动模型中的总线、驱动和设备都可以在sysfs文件系统中找到对应的节点


2. 查看/proc/devices文件可以获知系统中注册的设备，第1列为主设备号，第2列为设备名


/*****************************************************/

第6章 字符设备驱动
常规字符设备驱动

6.1.4

1. 内核空间访问用户空间缓冲区(read),需要先检查合法性,  用 access_ok(),，以确定传入的缓冲区的确属于用户空间


/*****************************************************/

1. globalmem设备驱动

虚拟的globalmem设备几乎没有任何实用价值，仅仅是一种为了讲解问题的方便而凭空制造的设备

代码清单6.17(单个设备驱动模板) P183
代码清单6.18(多个设备驱动模板) P186

*****文件私有数据(懵懵懂懂)


/*****************************************************/

第7章 并发控制(并发访问导致竞态)

1. SMP (多核)

2. 中断屏蔽
	local_irq_disable()       /*  屏蔽中断  */
	. . .
	critical section          /*  临界区 */
	. . .
	local_irq_enable()        /*  开中断 */
单独使用中断屏蔽通常不是一种值得推荐的避免竞态的方法
（换句话说，驱动中使用local_irq_disable/enable（）通常意味着一个bug）

		与local_irq_disable（）不同的是，local_irq_save（flags）除了进行禁止中断的操作以外，还保存目前
		CPU的中断位信息，local_irq_restore（flags）进行的是与local_irq_save（flags）相反的操作。对于ARM
		处
		理器而言，其实就是保存和恢复CPSR。


/*****************************************************/











