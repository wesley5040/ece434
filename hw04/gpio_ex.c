#include "gpio_common.h"

void signal_handler(int sig)
{
	printf("Closing\n");
	go = 0;
}

int main(int argc, char *argv[])
{
	volatile void         *gpio;
	volatile unsigned int *gpio_oe;
	volatile unsigned int *gpio_din;
	volatile unsigned int *gpio_sdo;
	volatile unsigned int *gpio_cdo;
	unsigned int           reg;
	int                    fd;

	signal(SIGINT, signal_handler);

	fd   = open("/dev/mem", O_RDWR);
	gpio = mmap(0, GPIO0_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
	            GPIO0_BASE);
	if (gpio == MAP_FAILED) {
		printf("Unable to map GPIO\n");
		exit(1);
	}

	gpio_oe  = gpio + GPIO_OE;
	gpio_din = gpio + GPIO_DATA_I;
	gpio_sdo = gpio + GPIO_SETDATA_O;
	gpio_cdo = gpio + GPIO_CLRDATA_O;

	printf("Started\n");
	for (; go; ) {
		if (*gpio_din & GPIO_07){
			*gpio_sdo = GPIO_02;printf("y");
		}else
			*gpio_cdo = GPIO_02;
		if (*gpio_din & GPIO_05) {
			*gpio_sdo = GPIO_03; printf("x");
		}else
			*gpio_cdo = GPIO_03;
	}

	munmap((void *) gpio, GPIO0_SIZE);
	close(fd);
	return 0;
}
