#include "Arduino.h" //Tillgang til Arduinos API, delay, digitalWrite osv.
#include "PID.h"

PID::PID(int min, int max) {
  _setpoint = 0;
  _lastError = 0;
  _sumError = 0;
  _lastTime = millis();
  _kp = 1;
  _ki = 1;
  _kd = 1;
  _min = min;
  _max = max;
}

int PID::evaluate(int value) {
  int error = _setpoint - value;
  int time = millis();

  _sumError+=error;
  int diff = (_lastError - error)/(_lastTime - time);

  _lastError = error;
  _lastTime = time;

  int sum = _kp*error + _ki*_sumError + _kd*diff;

  /*  if(sum > _max){
    sum = _max;
  } else if(sum < _min) {
    sum = _min;
    }*/

  return sum;
}

void PID::update(int setpoint) {
  _setpoint = setpoint;
}

void PID::updateParameters(float kp, float ki, float kd) {
  _kp = kp;
  _ki = ki;
  _kd = kd;
}
