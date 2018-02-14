

文件说明
----------------
usbdriver.c  usb驱动的主体源代码
Makefile 编译源代码的配套的编辑脚本


源代码
----------------
参见代码注释

代码编译
----------------
sudo make                 // 编译完成后，生成可被加载的驱动模块 usbdirver.ko


运行
----------------
sudo insmod usbdriver.ko  // 手工加载模块
sudo lsmod                // 显示内核的所有内核列表
sudo rmmod                // 手工卸载内核
dmesg | tail              // 查看内核消息，可以确认内核中usb相关的硬件事件的回调函数的执行情况

