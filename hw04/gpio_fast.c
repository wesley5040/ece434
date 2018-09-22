#include "gpio_common.h"

void signal_handler(int sig)
{
	printf("Closing\n");
	go = 0;
}

int main(int argc, char *argv[])
{
	volatile void         *gpio0;
	volatile unsigned int *gpio0_din;
	volatile unsigned int *gpio0_sdo;
	volatile unsigned int *gpio0_cdo;
	int                    fd;

	signal(SIGINT, signal_handler);

	fd    = open("/dev/mem", O_RDWR);
	gpio0 = mmap(0, GPIO0_S, PROT_READ|PROT_WRITE, MAP_SHARED, fd, GPIO0_B);
	if (gpio0 == MAP_FAILED) {
		printf("Unable to map GPIO\n");
		exit(1);
	}

	gpio0_din = gpio0 + GPIO_DATA_I;
	gpio0_sdo = gpio0 + GPIO_SETDATA_O;
	gpio0_cdo = gpio0 + GPIO_CLRDATA_O;

	printf("Started\n");
	for (; go; ) {
		*gpio0_sdo = GPIO_03;
		*gpio0_cdo = GPIO_03;
		*gpio0_sdo = GPIO_03;
		*gpio0_cdo = GPIO_03;
		*gpio0_sdo = GPIO_03;
		*gpio0_cdo = GPIO_03;
		*gpio0_sdo = GPIO_03;
		*gpio0_cdo = GPIO_03;
		*gpio0_sdo = GPIO_03;
		*gpio0_cdo = GPIO_03;
		*gpio0_sdo = GPIO_03;
		*gpio0_cdo = GPIO_03;
		*gpio0_sdo = GPIO_03;
		*gpio0_cdo = GPIO_03;
		*gpio0_sdo = GPIO_03;
		*gpio0_cdo = GPIO_03;
	}

	munmap((void *) gpio0, GPIO0_S);
	close(fd);
	return 0;
}
