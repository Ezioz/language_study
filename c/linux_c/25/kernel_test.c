/*
 * @Descripttion: 
 * @version: 
 * @Author: ahtoh
 * @Date: 2021-12-15 21:16:32
 * @LastEditors: ahtoh
 * @LastEditTime: 2021-12-15 21:19:51
 */

#include <linux/Module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init lkp_init(void)
{
    printk("<1>hello, world! from the kernel space....\n");
    return 0;
}

static void __exit lkp_exit(void)
{
    printk("<1>Goodbye, world! leaving kernel sapce...\n");
}
module_init(lkp_init);
module_exit(lkp_exit);
MODULE_LICENSE("GPL");