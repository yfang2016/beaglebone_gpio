/*
 * ============================================================================
 *
 *       Filename:  gpio.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/08/2016 10:36:09 AM
 *       Revision:  none
 *       Compiler: 
 *
 *         Author:  Fang Yuan (yfang@nju.edu.cn)
 *   Organization:  nju
 *
 * ============================================================================
 */

/*  P9P9P9P9P9P9P9P9P9P9P9P9P9          P8P8P8P8P8P8P8P8P8P8P8P8P8P8P8P8
  P9P9P9P9P9P9P9P9P9P9P9P9P9          P8P8P8P8P8P8P8P8P8P8P8P8P8P8P8P8
*/
#ifndef _GPIO_H
#define _GPIO_H

#include <linux/ioctl.h>

typedef struct gpio {
    volatile unsigned int *port;
    volatile unsigned int *ctrl;
} gpio_t;

ssize_t led_read (struct file *filp,
                  char __user *buf,
                  size_t size,
                  loff_t *offset);

#define GPIO0   0x48E07000
#define GPIO1   0x4804c000
#define GPIO1_0 0x800			/* First pin of GPIO1 */
#define GPIO2   0x481AC000
#define GPIO2_0 0x888			/* First pin of GPIO2 */

#define GPIO3   0x481AE000

#define CTRL    (0x130/4)		/* GPIO control register */
#define	OE		(0x134/4)		/* Input/Output select. 0 as output */
#define	DATIN	(0x138/4)
#define DATOUT	(0x13c/4)
#define	CLR     (0x190/4)
#define SET     (0x194/4)

#define CONTRL	0x44e10000

#define	DEVICE_NAME		"/dev/gpio_led"

#define		LEDIOSET	_IOW(221, 0, int)
#define		LEDIOGET	_IOR(221, 0, int)

#endif  // _GPIO_H
