#include "Arduino.h"
#include "GyroRead.h"

GyroRead::GyroRead(int pin) {
  _pin = pin;
  gyroVoltage = 3.3;
  gyroZero = 1.65;
  gyroSensitivity = 0.057;
}

int GyroRead::getRawValue() {
  return analogRead(_pin);
}

int GyroRead::getG() {
  int raw = getRawValue();
  raw *= gyroVoltage/1023;
  raw -= gyroZero;
  raw /= gyroSensitivity;
  return raw;
}
