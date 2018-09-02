#!/usr/bin/env python
import curses, sys

print("Etch-a-sketch in curses")
print("")
print("Controls:")
print("  Move up     :  Up arrow")
print("  Move down   :  Down arrow")
print("  Move left   :  Left arrow")
print("  Move right  :  Right arrow")
print("  Clear screen:  R key")
print("  Exit        :  ^C")
print("")

if sys.version_info[0] < 3:  # Check if this is python2 or python3
    raw_input("Press any key to start...")
else:
    input("Press any key to start...")

# Init curses stuff
s = curses.initscr()
curses.noecho()
curses.cbreak()
curses.curs_set(0)
s.keypad(True)

def printx(cy, cx):
    # Just prints an X to the coordinates
    s.addstr(cy, cx, "X")
    s.refresh()

def clear_scr(startup=False):
    # Clears the screen and resets screen size
    s.clear()
    h, w = s.getmaxyx()
    if startup:
        cy, cx = int(h/2), int(w/2)
        printx(cy, cx)
        return h, w, cy, cx
    return h, w

try:  # Need the try/except so terminal doesn't get left in a bad state
    h, w, cy, cx = clear_scr(True)
    while True:
        c = s.getch()  # Waits for the next keypress
        if (c == curses.KEY_LEFT):
            if (cx > 0):
                cx -= 1
        elif (c == curses.KEY_RIGHT):
            if (cx < w - 2):  # -2 so we don't get OOB exceptions
                cx += 1
        elif (c == curses.KEY_UP):
            if (cy > 0):
                cy -= 1
        elif (c == curses.KEY_DOWN):
            if (cy < h - 1):  # -1 so we don't get OOB exceptions
                cy += 1
        elif (c == 114):  # R key
            h, w = clear_scr()
        printx(cy, cx)
except:
    # Clean up and exit
    curses.nocbreak()
    s.keypad(False)
    curses.echo()
    curses.endwin()
    exit()
