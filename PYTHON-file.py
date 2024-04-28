# Raspberry Pi 3
# Run: python PYTHON-file.py

import time
import RPi.GPIO as GPIO

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)                # Pin numbers according to their physical location

print("The Python program is running:")
GPIO.setup(7, GPIO.OUT)                 # GPIO4 pin 7
while True:
    GPIO.output(7, GPIO.HIGH)
    print("Python GPIO4 pin 7 - HIGH")
    time.sleep(5)

    GPIO.output(7, GPIO.LOW)
    time.sleep(5)
    print("Python GPIO4 pin 7 - LOW")

