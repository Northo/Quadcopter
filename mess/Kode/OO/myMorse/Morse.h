#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Morse {
 public:
  Morse(int interval, int pin);
  void dot(int n);
  void dash(int n);

 private:
  int _pin;
  int _interval;
};

#endif
