GPIO := /sys/class/gpio

all: gpio_ex gpio_fast

.PHONY: gpio
gpio:
	#echo 2   > $(GPIO)/export
	echo 3   > $(GPIO)/export
	#echo 7   > $(GPIO)/export
	echo 20  > $(GPIO)/export
	#echo out > $(GPIO)/gpio2/direction
	echo out > $(GPIO)/gpio3/direction
	#echo in  > $(GPIO)/gpio7/direction
	echo in  > $(GPIO)/gpio20/direction

gpio_ex: gpio_ex.c gpio_common.h
	gcc $< -o $@

gpio_fast: gpio_fast.c gpio_common.h
	gcc $< -o $@

.PHONY: clean
clean:
	rm -f gpio_ex gpio_fast
