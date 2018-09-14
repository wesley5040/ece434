#!/usr/bin/env python3
import curses, sys, smbus

print("Etch-a-sketch on i2c screen")
print("")
print("Controls:")
print("  Move up     :  Up arrow")
print("  Move down   :  Down arrow")
print("  Move left   :  Left arrow")
print("  Move right  :  Right arrow")
print("  Clear screen:  R key")
print("  Exit        :  ^C")
print("")

h,  w  = 8, 8
cy, cx = 3, 3
cols   = [0, 0, 0, 0, 0, 0, 0, 0]
bus    = smbus.SMBus(2)
matrix = 0x70

s = curses.initscr()
curses.noecho()
curses.cbreak()
curses.curs_set(0)
s.keypad(True)


def clear_scr():
    # Clears the grid
    bus.write_i2c_block_data(matrix, 0, [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0])

clear_scr()
try:  # Need the try/except so terminal doesn't get left in a bad state
    while True:
        c = s.getch()  # Waits for the next keypress
        if (c == curses.KEY_LEFT):
            if (cx > 0):
                cx -= 1
                cols[cx] += cy
        elif (c == curses.KEY_RIGHT):
            if (cx < w - 1):
                cx += 1
                cols[cx] += cy
        elif (c == curses.KEY_UP):
            if (cy > 0):
                cy -= 1
                cols[cy] += cx
        elif (c == curses.KEY_DOWN):
            if (cy < h - 1):
                cy += 1
                cols[cy] += cx
        elif (c == 114):  # R key
            clear_scr()
        bus.write_i2c_block_data(matrix, cx * 2, [cols[cx]])
except:
    # Clean up and exit
    curses.nocbreak()
    s.keypad(False)
    curses.echo()
    curses.endwin()
    exit()
