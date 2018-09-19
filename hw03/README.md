# HW03
Wesley Van Pelt - CM3289

## TMP101
### i2c addresses
| ADD0     | Addr |
| -------- | ---- |
| Low      | 0x48 |
| Floating | 0x49 |
| High     | 0x4A |

### [`tmp101.sh`](tmp101.sh)
#### Usage
`bone# ./tmp101.sh <bus #> <temp 1 addr> <temp 2 addr>`

Example:  `bone# ./tmp101.sh 2 0x48 0x4a`

#### Notes
 * Please ensure that i2c pins are in the correct mode before running.
 * You must provide all 3 args to the script


## Etch-a-sketch
### [`sketch.py`](sketch.py)
#### Usage
`bone# ./sketch.py`
##### Note
You must run `exercises/sensors/eQEP/setup.sh` and set `P9_21/22` to i2c first.

#### Setup
 * Connect rotary encoders to `P8_33/35` and `P8_41/42`.
 * Connect i2c matrix to `P9_21/22`.
 * Run `exercises/sensors/eQEP/setup.sh`.
 * Set `P9_21/22` to i2c.

Professor Yoder's Comments
==========================

Looks very good.  Nice and complete.
Nice use of parameters on the temp script.
Include setup.sh in your directory.

Score:10/10
