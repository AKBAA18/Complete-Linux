/***************************************************************************
 *                                                                         *
 *      Author          : Ganesh Naik                                      *
 *      Organisation    : Levana Technologies, Mumbai, India.              *
 *      Website		: www.levanatech.com                               *
 *                                                                         *
 *  Workshops on - Embedded Android, Embedded Linux & Internet of Things   *
 *  -------------------------------------------------------------------    *
 *  Tel : 91-9869260324, Email : info@levanatech.com                       *
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation. No warranty is attached; we cannot take *
 *   responsibility for errors or fitness for use.                         *
 ***************************************************************************/

#include <linux/module.h>
#include <linux/init.h>

static int mod_param = 12;
module_param (mod_param, int, S_IRUGO | S_IWUSR);

static int __init my_init (void)
{
    printk (KERN_INFO "Hello world from modfun \n");
    printk (KERN_INFO " mod_param = %d\n", mod_param);
    return 0;
}

static void __exit my_exit (void)
{
    printk (KERN_INFO "Goodbye world from modfun \n");
    printk (KERN_INFO " mod_param = %d\n", mod_param);

}

module_init (my_init);
module_exit (my_exit);

MODULE_AUTHOR ("Ganesh Naik");
MODULE_DESCRIPTION ("Embedded Linux & Device Drivers Training");
MODULE_LICENSE ("GPL v2");

