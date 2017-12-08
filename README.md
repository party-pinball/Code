# Party Pinball

All the codes for 2017 GIZMO team 8 are shared here


## Arduino_FSR

The Arduino_FSR file contains the code for the Arduino that controls all force sensitive resistors. When a FSR is triggered, the ID of the FSR will be sent to the RPI.

## RPI

The RPI file contains the code for the Raspberry PI that is connected with the Arduino_FSR. It reads the signal from the Arduino and executes the music files accordingly.

## Arduino_Motors

The Arduino_Motors file contains the code for the Arduino that controls LEDs, the stepper motor and the servo motor. There are two different types of LEDs: fast LEDs and normal LEDs. The fast LEDs require their own library to run while the normal LEDs are just digital outputs. The servo and stepper motors run in turns: Servo rotates 180 degrees, stepper runs one revolution, servo rotates back 180 degrees, stepper runs another revolution and so on. It was done this way because Arduino cannot run two loops simultaneously. 
