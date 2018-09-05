#!/usr/bin/env python3
import curses, sys, time
import Adafruit_BBIO.GPIO as GPIO

but0 = "P9_15"
but1 = "P9_16"
but2 = "P9_17"
but3 = "P9_18"
butr = "P9_14"

print("Etch-a-sketch in curses (with GPIO)")
print("")
print("Controls:")
print("  Move up     :  " + but0)
print("  Move down   :  " + but1)
print("  Move left   :  " + but2)
print("  Move right  :  " + but3)
print("  Clear screen:  " + butr)
print("  Exit        :  ^C")
print("")

if sys.version_info[0] < 3:  # Check if this is python2 or python3
    raw_input("Press any key to start...")
else:
    input("Press any key to start...")

# Init some GPIO stuff
GPIO.setup(but0, GPIO.IN)
GPIO.setup(but1, GPIO.IN)
GPIO.setup(but2, GPIO.IN)
GPIO.setup(but3, GPIO.IN)
GPIO.setup(butr, GPIO.IN)
cy, cx, h, w = 0, 0, 0, 0

# Init curses stuff
s = curses.initscr()
curses.noecho()
curses.cbreak()
curses.curs_set(0)
s.keypad(True)

def printx():
    # Just prints an X to the coordinates
    global cy
    global cx
    s.addstr(cy, cx, "X")
    s.refresh()

def clear_scr(startup=False):
    # Clears the screen and resets screen size
    global cy
    global cx
    global h
    global w
    s.clear()
    h, w = s.getmaxyx()
    if startup:
        cy, cx = int(h/2), int(w/2)
        printx()

def buttonUpdate(ch):
    global cy
    global cx
    global h
    global w
    if (ch == but0):
        if (cx > 0):
            cx -= 1
    elif (ch == but1):
        if (cx < w - 2):  # -2 so we don't get OOB exceptions
            cx += 1
    elif (ch == but2):
        if (cy > 0):
            cy -= 1
    elif (ch == but3):
        if (cy < h - 1):  # -1 so we don't get OOB exceptions
            cy += 1
    elif (ch == butr):
        clear_scr()
    printx()

GPIO.add_event_detect(but0, GPIO.RISING, callback=buttonUpdate)
GPIO.add_event_detect(but1, GPIO.RISING, callback=buttonUpdate)
GPIO.add_event_detect(but2, GPIO.RISING, callback=buttonUpdate)
GPIO.add_event_detect(but3, GPIO.RISING, callback=buttonUpdate)
GPIO.add_event_detect(butr, GPIO.RISING, callback=buttonUpdate)

try:  # Need the try/except so terminal doesn't get left in a bad state
    clear_scr(True)
    while True:
        time.sleep(120)
except:
    # Clean up and exit
    curses.nocbreak()
    s.keypad(False)
    curses.echo()
    curses.endwin()
    exit()
