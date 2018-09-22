# HW04
Wesley Van Pelt - CM3289

## Memory Map
### A numeric value for the starting address of the EMIF0 SDRAM
0x80000000

### Base addresses for each of the four 32-bit GPIO ports
| Name  | Base       |
| ----- | ---------- |
| GPIO0 | 0x44E07000 |
| GPIO1 | 0x4804C000 |
| GPIO2 | 0x481AC000 |
| GPIO3 | 0x481AE000 |


## GPIO via mmap
### Setup/Compiling
 * Run `make` to compile.
 * Run `make gpio` to set pins.

### [`gpio_ex.c`](gpio_ex.c)
#### Usage
`bone# ./gpio_ex`
#### I/O
| Name    | Pin   |
| ------- | ----- |
| 1 sense | P9_15 |
| 1 out   | P9_21 |
| 2 sense | P9_42 |
| 2 out   | P9_22 |

### [`gpio_fast.c`](gpio_fast.c)
#### Usage
`bone# ./gpio_fast`
#### I/O
