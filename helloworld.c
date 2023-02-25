#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/printk.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Issaru");
MODULE_DESCRIPTION("Hello world module");

int init_module(void)
{
 printk(KERN_INFO "Hello World!\n");
 return 0;
}

void cleanup_module(void)
{
 printk(KERN_INFO "Goodbye World!\n");
}
