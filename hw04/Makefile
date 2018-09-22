GPIO := /sys/class/gpio

all: gpio_ex gpio_fast

.PHONY: gpio
gpio:
	echo 2   > $(GPIO)/export
	echo 3   > $(GPIO)/export
	echo 7   > $(GPIO)/export
	echo 48  > $(GPIO)/export
	echo out > $(GPIO)/gpio2/direction
	echo out > $(GPIO)/gpio3/direction
	echo in  > $(GPIO)/gpio7/direction
	echo in  > $(GPIO)/gpio48/direction
	config-pin P9_15 gpio
	config-pin P9_21 gpio
	config-pin P9_22 gpio
	config-pin P9_42 gpio
	config-pin P9_15 in
	config-pin P9_42 in
	config-pin P9_21 out
	config-pin P9_22 out

gpio_ex: gpio_ex.c gpio_common.h
	gcc $< -o $@

gpio_fast: gpio_fast.c gpio_common.h
	gcc $< -o $@

.PHONY: clean
clean:
	rm -f gpio_ex gpio_fast
