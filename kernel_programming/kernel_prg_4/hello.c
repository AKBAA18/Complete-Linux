#include <linux/kernel.h>

#include <linux/module.h>
/* 
int init_module(void)

{

	printk("Hello World - simple modules loaded\n");
	//printk load the print to buffer in kernel memory 
	return 0;

}
*/ 
void cleanup_module(void)

{

        printk("simple module unloade#d\n");

}
MODULE_LICENSE("GPL");// should have the licence as the GPL because of not propriatory 
MODULE_AUTHOR("Akshaya Baalaji ");
MODULE_DESCRIPTION("Hello World Module");
MODULE_VERSION("1.O");
