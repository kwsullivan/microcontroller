import serial
import time

all_on = ["1r1", "2r1", "3r1", "4r1"]
all_off = ["1r0", "2r0", "3r0", "4r0"]

ser = serial.Serial("/dev/ttyUSB0", 115200, timeout=1)

def send(cmd):
    ser.write((cmd + '\n').encode())

def delayed(mode):
    for r in mode:
        send(r)
        time.sleep(0.5)
