#include "Arduino.h" //Tillgang til Arduinos API, delay, digitalWrite osv.
#include "PID.h"

PID::PID() {
  _setpoint = 0;
  _kp = 1;
}

int PID::evaluate(int value) {
  int error = _setpoint - value;
  return _kp*error;
}

void PID::update(int setpoint) {
  _setpoint = setpoint;
}
