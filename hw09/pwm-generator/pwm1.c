#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"

#define P9_27 (1<<19)

//unsigned int volatile * const GPIO3_CLEAR = (unsigned int *) 0x481AE190;
//unsigned int volatile * const GPIO3_SET   = (unsigned int *) 0x481AE194;

volatile register uint32_t __R30;
volatile register uint32_t __R31;

void main(void)
{
	uint32_t gpio;

	/* Clear SYSCFG[STANDBY_INIT] to enable OCP master port */
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

	gpio = 1<<5; // Select which pin to toggle.

	while (1) {
		__R30 |= gpio;
//		*GPIO3_SET   = P9_27;
		__delay_cycles(1);
		__R30 &= ~gpio;
//		*GPIO3_CLEAR = P9_27;
		__delay_cycles(1);
	}
}
