#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
 
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "Pen drive (%04X:%04X) plugged\n", id->idVendor, id->idProduct);
    return 0;
}
 
static void pen_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "Pen drive removed\n");
}
 
static struct usb_device_id pen_table[] =
{
    { USB_DEVICE(0x058F, 0x6387) }, /*驱动程序识别的,USB设备号，不同的厂商会定义不同的设备号，在这里我们限定了设备号，以便测试激活我们专属的usb驱动程序 */
    {} /* Terminating entry */
};

MODULE_DEVICE_TABLE (usb, pen_table);
 
static struct usb_driver pen_driver =
{
    .name = "pen_driver", /*驱动程序的名字*/
    .id_table = pen_table, /*支持的设备编号*/
    .probe = pen_probe,  /*usb探测的回调函数申明，参见本文件中的方法定义 */
    .disconnect = pen_disconnect, /* usb设备卸载的回调函数声明，参见本文件中的方法定义*/
};

/* u盘初始回调函数，加载时向操作系统注册驱动程序模块 */ 
static int __init pen_init(void)
{
    return usb_register(&pen_driver);
}
 
/* 卸载驱动程序模块时，清理注册的信息 */
static void __exit pen_exit(void)
{
    usb_deregister(&pen_driver);
}
 
module_init(pen_init);
module_exit(pen_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anil Kumar Pugalia <email_at_sarika-pugs_dot_com>");
MODULE_DESCRIPTION("USB Pen Registration Driver");
