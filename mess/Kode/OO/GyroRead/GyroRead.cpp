#include "Arduino.h"
#include "GyroRead.h"

GyroRead::GyroRead(int pin) {
  _pin = pin;
}

int GyroRead::getRawValue() {
  return analogRead(_pin);
}

int GyroRead::getValue() {
  int raw = getRawValue();
  //gjør om til vanlig
  return raw;
}
