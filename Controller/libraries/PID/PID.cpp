#include "Arduino.h" //Tillgang til Arduinos API, delay, digitalWrite osv.
#include "PID.h"

PID::PID() {
  _setpoint = 0;
  _lastError = 0;
  _sumError = 0;
  _kp = 1;
  _ki = 1;
  _kd = 1;
}

//Eventuellt kan setpoint settes i en egen funksjon

int PID::evaluate(int setpoint, int value) {
  _setpoint = setpoint;

  int error = _setpoint - value;
  _sumError+=error;
  int diff = error - _lastError; //Dette er bare tull

  _lastError = error;
  return _kp*error + _ki*_sumError + _kd*diff;
}
