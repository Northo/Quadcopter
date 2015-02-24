/*
Written by Thorvald Ballestad and Karsten Stadler
TekForsk Ullern VGS 2015

Makes all four motors spin, controlled by remote control.

Version: Very Alpha
 */

#include <Servo.h>

int value = 0, pitch = 0;
#define REMOTE_PIN_COLLECTIVE = 8;
#define REMOTE_PIN_PITCH = 7;

Servo motors[4];
int motorPins[] = {9, 10, 11, 3}; //Must have PWM support, nut sure about pin 3

void setup() {
  for(int i = 0; i < 4; i++)
    motors[i].attach(motorPins[i]);

  pinMode(REMOTE_PIN_COLLECTIVE, INPUT);
  pinMode(REMOTE_PIN_PITCH, INPUT;
}

void loop() {
    /*  for(int i = 0; i < 4; i++)
	motors[i].write(value);*/
    motors[0].write(value+pitch);
    motors[1].write(value+pitch);
    motors[2].write(value-pitch);
    motors[3].write(value-pitch);

  //pulseIn returns an integer that gives the number of microseconds of a pulse, eg. ______/¯\_____/¯¯¯\____ The 'HIGH' means that we are interested in the hight voltage pulses, not drops.
  value = pulseIn(REMOTE_PIN_COLLECTIVE, HIGH);
  pitch = pulseIn(REMOTE_PIN_PITCH, HIGH);
  pitch = map(pitch, 1000, 2000, -500, 500);
}
