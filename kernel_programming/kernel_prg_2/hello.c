#include <linux/kernel.h>

#include <linux/module.h>
 
int init_module(void)

{

	printk("Hello World - simple modules loaded\n");

	return 0;

}
 
void cleanup_module(void)

{

	printk("simple module unloade#d\n");

}
 
MODULE_AUTHOR("Akshaya Baalaji ");
MODULE_DESCRIPTION("Hello World Module");
MODULE_VERSION("1.O");
//MODULE_LICENSE("GPL");
