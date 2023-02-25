#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/random.h>
#include <linux/printk.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Issaru");
MODULE_DESCRIPTION("Module that generates random number");

static int __init myrandmodule_init(void)
{
    int random;

    printk(KERN_INFO "myrandmodule module loaded\n");

    get_random_bytes(&random, sizeof(random));
    printk(KERN_INFO "Random number: %d\n", random);

    return 0;
}

static void __exit myrandmodule_exit(void)
{
    printk(KERN_INFO "myrandmodule module unloaded\n");
}

module_init(myrandmodule_init);
module_exit(myrandmodule_exit);
