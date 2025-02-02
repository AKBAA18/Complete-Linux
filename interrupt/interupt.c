/***************************************************************************
 *                                                                         *
 *      Author          : Ganesh Naik                                      *
 *      Organisation    : Levana Technologies, Mumbai, India.              *
 *      Website		: www.levanatech.com                               *
 *                                                                         *
 *  Conducting Workshops on - Embedded Android, Embedded Linux & IOT Training.    *
 *  -------------------------------------------------------------------    *
 *  Tel : 91-9869260324, Email : info@levanatech.com                       *
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation. No warranty is attached; we cannot take *
 *   responsibility for errors or fitness for use.                         *
 ***************************************************************************/


#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>


int id;

irqreturn_t handler(int irq, void *id)
{

	printk("inside the ISR handler in Kernel\n");
	return 0;
}

int init_module(void)
{
	printk("simple modules loaded\n");
	request_irq(1, handler, IRQF_SHARED, "levana", &id); 	
	return 0;
}

void cleanup_module(void)
{
	printk("simple module unloaded\n");
	free_irq(1, &id);			
}

MODULE_LICENSE("GPL");


