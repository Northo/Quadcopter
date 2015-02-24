#include "Arduino.h"
#include "PID.h"

int setpoint = 0;

PID::PID(GyroRead gyro) {
  _pin = pin;
  _gyro = gyro;
  _lastError = gyro.getValue();
  _sumError = 0;
  _kp = 1;
  _ki = 1;
  _kd = 1;
}

int PID::evaluate() {
  int reading = gyro.getValue();
  int error = _setpoint - reading;
  _sumError+=error;
  int diff = reading - _lastError;

  _lastError = error;
  return _kp*error + _ki*_sumError + _kd*diff;
}
