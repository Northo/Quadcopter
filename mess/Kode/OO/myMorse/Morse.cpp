#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int interval, int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  _interval = interval;
}

void Morse::dot(int n) {
  for( int i = 0; i < n; i++) {
    digitalWrite(_pin, HIGH);
    delay(_interval);
    digitalWrite(_pin, LOW);
    delay(_interval);
  }
}

void Morse::dash(int n) {
  for( int i = 0; i < n; i++) {
    digitalWrite(_pin, HIGH);
    delay(4*_interval);
    digitalWrite(_pin, LOW);
    delay(_interval);
  }
}
