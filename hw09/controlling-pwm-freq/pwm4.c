// This code does MAXCH parallel PWM channels.
#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"

// So I dont have to think about if the compiler is optomizing these, I am
// putting the values here explicity.
#define P8_43  0x00000002
#define P8_44  0x00000003
#define P8_45  0x00000000
#define P8_46  0x00000001
#define P8_43n 0xFFFFFFFD // ~2
#define P8_44n 0xFFFFFFFC // ~3
#define P8_45n 0xFFFFFFFF // ~0
#define P8_46n 0xFFFFFFFE // ~1

#define PRU1_DRAM 0x02000  // Offset to DRAM
// Skip the first 0x200 byte of DRAM since the Makefile allocates
// 0x100 for the STACK and 0x100 for the HEAP.
volatile unsigned int *pru1_dram = (unsigned int *) (PRU1_DRAM + 0x200);


volatile register uint32_t __R30;
volatile register uint32_t __R31;

void main(void)
{
	/* Clear SYSCFG[STANDBY_INIT] to enable OCP master port */
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

	while (1) {
		__R30 |= P8_43;
		__R30 |= P8_44;
		__R30 |= P8_45;
		__R30 |= P8_46;
		__R30 &= P8_43n;
		__R30 &= P8_44n;
		__R30 &= P8_45n;
		__R30 &= P8_46n;
	}
}
