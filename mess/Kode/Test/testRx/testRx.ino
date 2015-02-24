#include "config.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  int throttle = pulseIn(RX_PIN_THROTTLE, HIGH);
  int motor[4];
  motor[0] = map(throttle, RX_THROTTLE_MIN, RX_THROTTLE_MAX, MOTOR_ZERO_LEVEL, MOTOR_MAX_LEVEL);
  Serial.println(motor[0]);
  analogWrite(MOTOR_FR, motor[0]);
  delay(10);
}
