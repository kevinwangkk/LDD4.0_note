
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

3. tree -a  生成目录树


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























