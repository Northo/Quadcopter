#include <Servo.h>

int value = 0, remoteValue;
#define REMOTE_PIN = 8;

Servo firstESC, secondESC, thirdESC, fourthESC;

void setup() {
  firstESC.attach(9);
  secondESC.attach(10);
  thirdESC.attach(11);
  //I'm not sure 12 has PWM support, just wrote this as an example at home
  fourthESC.attach(12);

  pinMode(REMOTE_PIN, INPUT);
}

void loop() {
  firstESC.writeMicroseconds(value);
  secondESC.writeMicroseconds(value);
  thirdESC.writeMicroseconds(value);
  fourthESC.writeMicroseconds(value);

  //pulseIn returns an integer that gives the number of microseconds of a pulse, eg. ______/¯\_____/¯¯¯\____ The 'HIGH' means that we are interested in the hight voltage pulses, not drops.
  value = pulseIn(REMOTE_PIN, HIGH);
}
