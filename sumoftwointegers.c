#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Issaru");
MODULE_DESCRIPTION("Module that calculates sum of two integers");

static int first_number;
static int second_number;

module_param(first_number, int, S_IRUSR | S_IWUSR);
module_param(second_number, int, S_IRUSR | S_IWUSR);

int sum(int a, int b) {
    return a + b;
}

static int __init summodule_init(void)
{
    int result = sum(first_number, second_number);

    printk(KERN_INFO "The sum of %d and %d is %d\n", first_number, second_number, result);

    return 0;
}

static void __exit summodule_exit(void)
{
    printk(KERN_INFO "Sum module unloaded\n");
}

module_init(summodule_init);
module_exit(summodule_exit);
