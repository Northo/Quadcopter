#include "Arduino.h"
#include "Remote.h"

Remote::Remote(int pin){
  _pin = pin;
  _last = pulseIn(_pin, HIGH);
}

int Remote::getValue() {
  return = pulseIn(_pin, HIGH);
}
