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
#### Notes
 * Please ensure that i2c pins are in the correct mode before running.
 * You must provide all 3 args to the script
