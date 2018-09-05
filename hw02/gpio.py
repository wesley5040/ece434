#!/usr/bin/env python3
import Adafruit_BBIO.GPIO as GPIO
import time, sys

if len(sys.argv) < 2:
    print("Usage: " + sys.argv[0] + " <sleep time in seconds>")

io    = "P9_12"
delay = float(sys.argv[1])

GPIO.setup(io, GPIO.OUT)

print("running...")
try:
    while True:
        GPIO.output(io, 0)
        time.sleep(delay)
        GPIO.output(io, 1)
        time.sleep(delay)
except KeyboardInterrupt:
    GPIO.cleanup()
GPIO.cleanup()
