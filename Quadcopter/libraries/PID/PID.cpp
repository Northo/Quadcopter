#include "Arduino.h" //Tillgang til Arduinos API, delay, digitalWrite osv.
#include "PID.h"

PID::PID() {
  _setpoint = 0;
  _lastError = 0;
  _sumError = 0;
  _lastTime = millis();
  _kp = 1;
  _ki = 1;
  _kd = 1;
}

int PID::evaluate(int value) {
  int error = _setpoint - value;
  int time = millis();

  _sumError+=error;
  int diff = (_lastError - error)/(_lastTime - time);

  _lastError = error;
  _lastTime = time;
  return _kp*error + _ki*_sumError + _kd*diff;
}

void PID::update(int setpoint) {
  _setpoint = setpoint;
}
