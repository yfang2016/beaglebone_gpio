#!/usr/bin/env python
# -*- coding: utf-8 -*-

# File Name: gpio.py
# Author: Fang Yuan (yfang@nju.edu.cn)
# Created Time: Wed 18 Jan 2017 09:30:28 PM CST
# GPIO library
'''
                 P9                                  P8
         DGND  1    2   DGND                  GND  1    2   GND
         3.3V  3    4   3.3V                GP1_6  3    4   GP1_7
        Vdd5V  5    6   Vdd5V               GP1_2  5    6   GP1_3
        Sys5V  7    8   Sys5V                TMR4  7    8   TMR7
      PWR_BUT  9    10  RESET                TMR5  9    10  TMR6
       U4_RXD  11   12  GP1_28             GP1_13  11   12  GP1_12
       U4_TXD  13   14  EHRPWM             EHRPWM  13   14  GP0_26
       GP1_16  15   16  EHRPWM             GP1_15  15   16  GP1_14
     I2C1_SCL  17   18  I2C1_SDA           GP0_27  17   18  GP2_1
     I2C2_SCL  19   20  I2C2_SDA           EHRPWM  19   20  GP1_31
       U2_TXD  21   22  U2_RXD             GP1_30  21   22  GP1_5
       GP1_17  23   24  U1_TXD             GP1_4   23   24  GP1_1
       GP3_21  25   26  U1_RXD             GP1_0   25   26  GP1_29
       GP3_19  27   28  SP1_CS             GP2_22  27   28  GP2_24
       SP1_D0  29   30  SP1_D1             GP2_23  29   30  GP2_25
      SP1_CLK  31   32  VADC       (GP0_10)U5_CTS  31   32  U5_RTS(GP0_11)
         AIN4  33   34  AGND        (GP0_9)U4_RTS  33   34  U3_RTS(GP2_17)
         AIN6  35   36  AIN5        (GP0_8)U4_CTS  35   36  U3_CTS(GP2_16)
         AIN2  37   38  AIN3       (GP2_14)U5_TXD  37   38  U5_RXD(GP2_15)
         AIN0  39   40  AIN1               GP2_12  39   40  GP2_13
       CLKOUT  41   42  GP0_7              GP2_10  41   42  GP2_11
         DGND  43   44  DGND               GP2_8   43   44  GP2_9
         DGND  45   46  DGND               GP2_6   45   46  GP2_7
'''

GPIO_ROOT = '/sys/class/gpio'
# write a number(string) to /sys/class/gpio/export will create
# the corresponding gpio node.
# write a number to /sys/class/gpio/unexport delete the node

# when gpio pin opened, write 'high' or 'low' to gpioXX/direction
# will set the pin function as OUTPUT or INPUT
# gpioXX/value is used to set or get pin level


class GPIO:
    def __init__(self, pin, dir):
        f = open(GPIO_ROOT+'/unexport', 'w')
        try:
            f.write(str(pin))
        except:
            pass
        f.close()    # try close opened GPIO

        f = open(GPIO_ROOT+'/export', 'w')
        try:
            f.write(str(pin))
        except:
            pass
        f.close()
        f = open(GPIO_ROOT+'/gpio'+str(pin)+'/direction', 'w')
        f.write(dir)
        f.close()

    def setPin(self, status):
        pass       # not implemented yet

    def getPin(pin):
        c = self.gpio.read()
        return c
