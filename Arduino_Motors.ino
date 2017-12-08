// This code is for the second Arduino that controls LEDs, one stepper motor and one servo motor

#include <Stepper.h>                                      // Import stepper motor library 
#include <Servo.h>                                        // Import servo motor library  
#include "FastLED.h"                                      // Import fast LED library 
#define NUM_LEDS 12                                       // There are 12 fast LEDs in total
#define DATA_PIN 13                                       // Pin 13 is the digital output for the 12 fast LEDs

CRGB leds[NUM_LEDS];                                      // All 12 fast LEDs will use CRGB colours

Servo myservo;                                            // Initialise servo motor
int pos = 0;                                              // Initiliase the starting position of the servo motor

const int stepsPerRevolution = 200;                       // Initialise steps per revolution for stepper motor      
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);      // Initialise the pins for the stepper motor

void setup() {
  myStepper.setSpeed(60);                                 // Stepper motor's speed is 60 rpm
  myservo.attach(7);                                      // Servo motor is attached to pin 7
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);    // Initialise fast LEDs
  pinMode(6, OUTPUT);                                     // Other normal LEDs are attached to pin 6
}

void loop() {                                             // Main infinite loop
  leds[0] = CRGB::Red;                                    // The 12 fast LEDs are split into two groups of 6 
  leds[1] = CRGB::Orange;                                 // And their colour combination is rainbow
  leds[2] = CRGB::Yellow;
  leds[3] = CRGB::Green;
  leds[4] = CRGB::Blue;
  leds[5] = CRGB::Purple;
  FastLED.show();                                         // Light up the fast LEDs
  digitalWrite(6, HIGH);                                  // Light up the normal LEDs
  for (pos = 0; pos <= 180; pos += 1) {                   // Servo goes from 0 degrees to 180 degrees in steps of 1 degrees
    myservo.write(pos);                                   // Tell servo to go to position in variable 'pos'
    delay(10);                                            // Waits 10ms for the servo to reach the position
  }
  myStepper.step(stepsPerRevolution);                     // Stepper motor rotates one revolution
  for (pos = 180; pos >= 0; pos -= 1) {                   // Servo goes from 180 degrees to 0 degrees
    myservo.write(pos);                                   // Tell servo to go to position in variable 'pos'
    delay(10);                                            // Waits 10ms for the servo to reach the position
  }
  myStepper.step(stepsPerRevolution);                     //Stepper motor rotates one revolution
}
