#include "gpio_common.h"

void signal_handler(int sig)
{
	printf("Closing\n");
	go = 0;
}

int main(int argc, char *argv[])
{
	volatile void         *gpio0;
	volatile void         *gpio1;
	volatile unsigned int *gpio0_sdo;
	volatile unsigned int *gpio0_cdo;
	int                    fd;

	signal(SIGINT, signal_handler);

	fd    = open("/dev/mem", O_RDWR);
	gpio0 = mmap(0, GPIO0_S, PROT_READ|PROT_WRITE, MAP_SHARED, fd, GPIO0_B);
	gpio1 = mmap(0, GPIO1_S, PROT_READ|PROT_WRITE, MAP_SHARED, fd, GPIO1_B);
	if (gpio0 == MAP_FAILED || gpio1 == MAP_FAILED) {
		printf("Unable to map GPIO\n");
		exit(1);
	}

	gpio0_sdo = gpio0 + GPIO_SETDATA_O;
	gpio0_cdo = gpio0 + GPIO_CLRDATA_O;

	printf("Started\n");
	for (; go; ) {
		if (*(gpio0 + GPIO_DATA_I) & GPIO_07)
			*gpio0_sdo = GPIO_02;
		else
			*gpio0_cdo = GPIO_02;
		if (*(gpio1 + GPIO_DATA_I) & GPIO_48)
			*gpio0_sdo = GPIO_03;
		else
			*gpio0_cdo = GPIO_03;
	}

	munmap((void *) gpio0, GPIO0_S);
	munmap((void *) gpio1, GPIO1_S);
	close(fd);
	return 0;
}
