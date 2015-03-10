#include "Arduino.h"
#include "Gyro.h"

Gyro::Gyro(int pin) {
  _pin = pin;
}

int PID::read() {
  return analogRead(_pin);
}
