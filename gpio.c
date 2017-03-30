/*
 * ============================================================================
 *
 *       Filename:  gpio.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2016 10:35:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fang Yuan (yfang@nju.edu.cn)
 *   Organization:  nju
 *
 * ============================================================================
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <asm/uaccess.h>

#include "gpio.h"

#ifdef DEBUG
#define PRINT   printk
#else
#define PRINT   
#endif

int init_module(void)
{
    int i;
    volatile int *ctrl, *port;

    ctrl = ioremap(CONTRL, 128*1024);
    port= ioremap(GPIO2, 4096);
    port[CTRL] = 0;
    for(i = 0; i < 12; i++)  /* set gpio2_1 ... gpio2_17 */
        ctrl[(0x8a0/4) + i] = 0x37;

    port[OE] = 0x00000000;  /* set gpio2 as output */

    ctrl[0x820/4] = 0x34;   /* set erhpwm2A/B */
    ctrl[0x824/4] = 0x34;

    ctrl[0x8c8/4] = 0x32;   /* set erhpwm1A/B */
    ctrl[0x8cc/4] = 0x32;

    printk("GPIO function initialised, set as OUTPUT\n");
    iounmap(ctrl);
    iounmap(port);

	return -1;
}

void cleanup_module(void)
{
    unregister_chrdev(223, "gpio LED");
    printk("module removed from kernel\n");
}

MODULE_LICENSE("GPL");
