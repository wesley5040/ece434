#!/usr/bin/env python3
import sys, smbus, time
from Adafruit_BBIO.Encoder import RotaryEncoder, eQEP1, eQEP2

print("Etch-a-sketch on i2c screen")
print("")
print("Controls:")
print("  Move up     :  ")
print("  Move down   :  ")
print("  Move left   :  ")
print("  Move right  :  ")
print("  Exit        :  ^C")
print("")

h,  w  = 8, 8
cy, cx = 3, 3
ly, lx = 0, 0
cols   = [0, 0, 0, 0, 0, 0, 0, 0]
bus    = smbus.SMBus(2)
matrix = 0x70
e1, e2 = RotaryEncoder(eQEP1), RotaryEncoder(eQEP2)
e1.setAbsolute()
e2.setAbsolute()

def get(b):
    # Makes a binary string to OR with
    return int(('0' * b) + '1' + ('0' * (7 - b)), 2)

def mprint():
    # Just writes the current column
    global cx, cy
    cols[cx] |= get(cy)
    bus.write_i2c_block_data(matrix, cx * 2, [cols[cx]])

def clear_scr():
    # Clears the grid
    bus.write_i2c_block_data(matrix, 0, [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0])
    mprint()


clear_scr()
e1.enable()
e2.enable()
while True:
    dy, dx = ly - e2.position, lx - e1.position
    if (dy > 0) and (cy < 7):  # go down
        cy += 1
    if (dy < 0) and (cy > 0):  # go up
        cy -= 1
    if (dx > 0) and (cx < 7):  # go right
        cx += 1
    if (dx < 0) and (cx > 0):  # go left
        cx -= 1
    ly = e2.position
    lx = e1.position
    mprint()
    time.sleep(0.1)
