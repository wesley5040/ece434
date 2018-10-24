#!/usr/bin/env python3

import time
import smbus

addr = 0x2a
bus  = smbus.SMBus(2)

com = [0x6A, 0x1, 0x1, 0xC, 0x0, 0x0, 0xA]

while True:
	bus.write_i2c_block_data(addr, 0x92, com)
	time.sleep(0.5)
	data = bus.read_i2c_block_data(addr, 0x55, 32)
	print(    "1: " + str((65536 * data[0] + 256 * data[1] + data[2])/1000) +
	      "A;  2: " + str((65536 * data[3] + 256 * data[4] + data[5])/1000) + "A")
