#include "Arduino.h"

class Remote {
 public:
  Remote(int pin);
  int getValue();

 private:
  int _pin;
};
