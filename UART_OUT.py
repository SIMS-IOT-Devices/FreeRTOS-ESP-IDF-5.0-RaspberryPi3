# Serial communication output
# Run: python UART_OUT.py

import serial
from time import sleep

ser = serial.Serial ("/dev/ttyS0", 115200)      #Open port with baud rate
while True:
    ser.write(b'UART from Raspberry Pi 3\r\n')  #transmit data serially 
    print("Raspberry Pi 3 data sent: UART from Raspberry Pi 3")
    sleep(1)