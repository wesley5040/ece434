obj-m+=gpio_copy.o
obj-m+=gpio_toggle.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
load:
	insmod gpio_toggle.ko
	insmod gpio_copy.ko
uload:
	rmmod gpio_toggle.ko
	rmmod gpio_copy.ko

