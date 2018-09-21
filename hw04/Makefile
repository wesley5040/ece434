.PHONY: all
all:	gpio_ex gpio_fast
# TODO pinconf

gpio_ex: gpio_ex.c gpio_common.h
	gcc $< -o $@

gpio_fast: gpio_fast.c gpio_common.h
	gcc $< -o $@
