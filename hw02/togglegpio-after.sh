#!/bin/bash
# From http://wh1t3s.com/2009/05/14/reading-beagleboard-gpio/
# Orginally /usr/bin/readgpio, Modified by Mark A. Yoder 20-Jul-2011
#
# Toggle a GPIO input

if [ $# -lt 2 ]; then
    echo "Usage: $0 <gpio pin#> <delay in seconds>"
    exit 0
fi
GPIO=$1
PERIOD=$2

cleanup() { # Set the GPIO port to 0
  echo 0 > /sys/class/gpio/gpio${GPIO}/value
  echo "Cleaning up"
  echo ""
  exit
}

# Open the GPIO port
#
if [ ! -e /sys/class/gpio/gpio$GPIO ]; then
    echo "$GPIO" > /sys/class/gpio/export
fi
echo "out" > /sys/class/gpio/gpio${GPIO}/direction

trap cleanup SIGINT # call cleanup on Ctrl-C

while true; do
    # Unrolled the loop 4 times to try and reduce overhead
    echo 0 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 1 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 0 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 1 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 0 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 1 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 0 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 1 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 0 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 1 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 0 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
    echo 1 > /sys/class/gpio/gpio${GPIO}/value
    sleep $PERIOD
done

cleanup # call the cleanup routine
