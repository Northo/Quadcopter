#include <Servo.h>

int value = 0;

Servo firstESC, secondESC, thirdESC, fourthESC;

void setup() {
  firstESC.attach(9);
  secondESC.attach(10);
  thirdESC.attach(11);
  //I'm not sure 12 has PWM support, just wrote this as an example at home
  fourthESC.attach(12);

  Serial.begin(9600);
}

void loop() {
  firstESC.writeMicroseconds(value);
  secondESC.writeMicroseconds(value);
  thirdESC.writeMicroseconds(value);
  fourthESC.writeMicroseconds(value);

TEst
  if(Serial.available())
    value = Serial.parseInt();
}
