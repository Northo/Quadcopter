#include <Servo.h>

int value = 0, remoteValue;
#define REMOTE_PIN = 8;

Servo motors[4];
int motorPins[] = {9, 10, 11, 3}; //Must have PWM support, nut sure about pin 3

void setup() {
  for(int i = 0; i < 4; i++)
    motors[i].attach(motorPins[i]);

  pinMode(REMOTE_PIN, INPUT);
}

void loop() {
  for(int i = 0; i < 4; i++)
    motors[i].write(value);

  //pulseIn returns an integer that gives the number of microseconds of a pulse, eg. ______/¯\_____/¯¯¯\____ The 'HIGH' means that we are interested in the hight voltage pulses, not drops.
  value = pulseIn(REMOTE_PIN, HIGH);
}
