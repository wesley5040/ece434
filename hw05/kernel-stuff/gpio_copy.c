/**
 * @file   gpio_test.c
 * @author Wesley Van Pelt &Derek Molloy
 * @date   19 April 2015, revised 1 Oct 2018
 * @brief  A kernel module for controlling a GPIO LED/button pair. The device mounts devices via
 * sysfs /sys/class/gpio/gpio115 and gpio49. Therefore, this test LKM circuit assumes that an LED
 * is attached to GPIO 49 which is on P9_23 and the button is attached to GPIO 115 on P9_27. There
 * is no requirement for a custom overlay, as the pins are in their default mux mode states.
 * @see http://www.derekmolloy.ie/
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Wesley Van Pelt & Derek Molloy");
MODULE_DESCRIPTION("A Button/LED test driver for the BBB");
MODULE_VERSION("0.1");

static unsigned int irqNumber;
static unsigned int gpioLED    = 51; // P9_16 (GPIO51)
static unsigned int gpioButton = 48; // P9_15 (GPIO48)
static unsigned int num_press  = 0;
static bool         ledOn      = 0;

/// Function prototype for the custom IRQ handler function -- see below for the implementation
static irq_handler_t ebbgpio_irq_handler(unsigned int irq, void *dev_id, struct pt_regs *regs);

/** @brief The LKM initialization function
 *  The static keyword restricts the visibility of the function to within this C file. The __init
 *  macro means that for a built-in driver (not a LKM) the function is only used at initialization
 *  time and that it can be discarded and its memory freed up after that point. In this example this
 *  function sets up the GPIOs and the IRQ
 *  @return returns 0 if successful
 */
static int __init ebbgpio_init(void)
{
	int result = 0;
	printk(KERN_INFO "GPIO_TEST: Initializing the GPIO_TEST LKM\n");
	// Is the GPIO a valid GPIO number (e.g., the BBB has 4x32 but not all available)
	if (!gpio_is_valid(gpioLED)) {
		printk(KERN_INFO "GPIO_TEST: invalid LED GPIO\n");
		return -ENODEV;
	}

	// Going to set up the LED. It is a GPIO in output mode and will be on by default
	ledOn = true;
	gpio_request(gpioLED, "sysfs");
	gpio_direction_output(gpioLED, ledOn);
	// gpio_set_value(gpioLED, ledOn); // Not required as set by line above (here for reference)
	gpio_export(gpioLED, false); // The bool argument prevents the direction from being changed
	gpio_request(gpioButton, "sysfs");
	gpio_direction_input(gpioButton);
	gpio_set_debounce(gpioButton, 200);
	gpio_export(gpioButton, false);

	// Perform a quick test to see that the button is working as expected on LKM load
	printk(KERN_INFO "GPIO_TEST: The button state is currently: %d\n", gpio_get_value(gpioButton));

	// GPIO numbers and IRQ numbers are not the same! This function performs the mapping for us
	irqNumber = gpio_to_irq(gpioButton);
	printk(KERN_INFO "GPIO_TEST: The button is mapped to IRQ: %d\n", irqNumber);

	// This next call requests an interrupt line
	result = request_irq(irqNumber,                           // The interrupt number requested
	                     (irq_handler_t) ebbgpio_irq_handler, // The pointer to the handler function below
	                     0x3,                                 // Interrupt on both edges
	                     "ebb_gpio_handler",                  // Used in /proc/interrupts to identify the owner
	                     NULL);                               // The *dev_id for shared interrupt lines, NULL is okay

	printk(KERN_INFO "GPIO_TEST: The interrupt request result is: %d\n", result);
	return result;
}

/** @brief The LKM cleanup function
 *  Similar to the initialization function, it is static. The __exit macro notifies that if this
 *  code is used for a built-in driver (not a LKM) that this function is not required. Used to release the
 *  GPIOs and display cleanup messages.
 */
static void __exit ebbgpio_exit(void){
	printk(KERN_INFO "GPIO_TEST: The button state is currently: %d\n", gpio_get_value(gpioButton));
	printk(KERN_INFO "GPIO_TEST: The button was pressed %d times\n", num_press);
	gpio_set_value(gpioLED, 0);
	gpio_unexport(gpioLED);
	free_irq(irqNumber, NULL);
	gpio_unexport(gpioButton);
	gpio_free(gpioLED);
	gpio_free(gpioButton);
	printk(KERN_INFO "GPIO_TEST: Goodbye from the LKM!\n");
}

/** @brief The GPIO IRQ Handler function
 *  This function is a custom interrupt handler that is attached to the GPIO above. The same interrupt
 *  handler cannot be invoked concurrently as the interrupt line is masked out until the function is complete.
 *  This function is static as it should not be invoked directly from outside of this file.
 *  @param irq    the IRQ number that is associated with the GPIO -- useful for logging.
 *  @param dev_id the *dev_id that is provided -- can be used to identify which device caused the interrupt
 *  Not used in this example as NULL is passed.
 *  @param regs	h/w specific register values -- only really ever used for debugging.
 *  return returns IRQ_HANDLED if successful -- should return IRQ_NONE otherwise.
 */
static irq_handler_t ebbgpio_irq_handler(unsigned int irq, void *dev_id, struct pt_regs *regs){
	ledOn = gpio_get_value(gpioButton);
	gpio_set_value(gpioLED, ledOn);
	printk(KERN_INFO "GPIO_TEST: Interrupt! (button state is %d)\n", gpio_get_value(gpioButton));
	num_press++;
	return (irq_handler_t) IRQ_HANDLED;  // Announce that the IRQ has been handled correctly
}

// These next calls are  mandatory - they identify the initialization function
// and the cleanup function (as above).
module_init(ebbgpio_init);
module_exit(ebbgpio_exit);
