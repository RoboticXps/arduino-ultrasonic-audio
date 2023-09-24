####################
# Run this Python file on your computer, and it'll play audio file
# when distance is less than 15cm.
####################
# Required Pakcages to be installed

# pip install pyserial
# pip install playsound
####################

import serial
import playsound

encoding = 'utf-8'
port = "COM3"  # check out your port
baud = 115200
s = serial.Serial(port)
s.baudrate = baud

if not s.isOpen():
    s.open()

mp3_in_background = False


def take_action(result, mp3_back):
    if result == "P" and mp3_back == False:
        mp3_back = True
        playsound.playsound("allawi.mp3")
    return mp3_back


def get_arduino_msg(mp3_in_background):
    while True:
        i = s.read()
        msg = i.decode(encoding)
        print("msg from Arduino:::", msg)
        mp3_in_background = take_action(msg, mp3_in_background)


if __name__ == "__main__":
    get_arduino_msg(mp3_in_background)
