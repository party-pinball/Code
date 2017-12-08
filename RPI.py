### All FSR values and corresponding IDs are transmitted to the RPI, RPI executes the specific music files.

import serial                                         # Serial connection between RPI and Arduino_FSR is used
import pygame as pg                                   # PyGame library is used to play multiple tracks simultaneously

pg.mixer.init()                                       # Initialise PyGame mixer for multi-tracking
pg.mixer.set_num_channels(6)                          # Six music files will be played in total so six channels are used
s1 = pg.mixer.Sound("xylo1.wav")                      # Initialise variables for each WAV file
s2 = pg.mixer.Sound("xylo2.wav")
s3 = pg.mixer.Sound("xylo3.wav")
s4 = pg.mixer.Sound("xylo5.wav")
s5 = pg.mixer.Sound("riff.wav")
s6 = pg.mixer.Sound("drums newnew.wav")
channel1 = pg.mixer.Channel(1)                        # Initialise variables for each channel
channel2 = pg.mixer.Channel(2)
channel3 = pg.mixer.Channel(3)
channel4 = pg.mixer.Channel(4)
channel5 = pg.mixer.Channel(5)
channel6 = pg.mixer.Channel(6)
port = "/dev/ttyACM0"                                 # Set port for serial connection to the Arduino
serialFromArduino = serial.Serial(port, 9600)         # Initialise serial connection
serialFromArduino.flushInput()
channel6.set_volume(0.5)                              # Channel 6 is background music so the volume is set to be 50%
channel6.play(s6, loops = -1)                         # Channel 6 loops the background music, "loops = -1" means infinite loop
while True:
    if (serialFromArduino.inWaiting() > 0):           # If Arduino sent a valid signal
        input = serialFromArduino.read(1)             # The variable "input" takes the single byte from the Arduino
        if ord(input) == 1:                           # If the input from Arduino is from one of the sensors (1-5)
            channel1.play(s1, loops = 0)              # The corresponding music files are played once
        elif ord(input) == 2:
            channel2.play(s2, loops = 0)
        elif ord(input) == 3:
            channel3.play(s3, loops = 0)
        elif ord(input) == 4:
            channel4.play(s4, loops = 0)
        elif ord(input) == 5:
            channel5.play(s5, loops = 0)
