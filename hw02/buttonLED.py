#!/usr/bin/env python3
import Adafruit_BBIO.GPIO as GPIO
import time

led0 = "P9_11"
led1 = "P9_12"
led2 = "P9_13"
led3 = "P9_14"
but0 = "P9_15"
but1 = "P9_16"
but2 = "P9_17"
but3 = "P9_18"

GPIO.setup(led0, GPIO.OUT)
GPIO.setup(led1, GPIO.OUT)
GPIO.setup(led2, GPIO.OUT)
GPIO.setup(led3, GPIO.OUT)
GPIO.setup(but0, GPIO.IN)
GPIO.setup(but1, GPIO.IN)
GPIO.setup(but2, GPIO.IN)
GPIO.setup(but3, GPIO.IN)

b2l = {but0 : led0,
       but1 : led1,
       but2 : led2,
       but3 : led3}

def updateLED(ch):
    GPIO.output(b2l[ch], GPIO.input(ch))

GPIO.add_event_detect(but0, GPIO.BOTH, callback=updateLED)
GPIO.add_event_detect(but1, GPIO.BOTH, callback=updateLED)
GPIO.add_event_detect(but2, GPIO.BOTH, callback=updateLED)
GPIO.add_event_detect(but3, GPIO.BOTH, callback=updateLED)

print("running...")
try:
    while True:
        time.sleep(100)
except KeyboardInterrupt:
    GPIO.cleanup()
GPIO.cleanup()
