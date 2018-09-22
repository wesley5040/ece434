#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>    // Defines signal-handling functions (i.e. trap Ctrl-C)

int go = 1;

void signal_handler(int sig);


// From: http://stackoverflow.com/questions/13124271/driving-beaglebone-gpio-through-dev-mem
#ifndef _BEAGLEBONE_GPIO_H_
#define _BEAGLEBONE_GPIO_H_

#define GPIO0_B 0x44e07000
#define GPIO0_S 0x2000

#define GPIO1_B 0x4804C000
#define GPIO1_S 0x2000

#define GPIO_DATA_I    0x138
#define GPIO_SETDATA_O 0x194
#define GPIO_CLRDATA_O 0x190

#define GPIO_02 (1<<2)
#define GPIO_03 (1<<3)
#define GPIO_07 (1<<7)
#define GPIO_48 (1<<16)
#endif
