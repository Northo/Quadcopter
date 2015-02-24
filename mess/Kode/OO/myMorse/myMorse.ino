#include "Morse.h"

Morse morse(100, 13);

void setup() {
  
}

void loop() {
 morse.dot(3);
 morse.dash(3);
 morse.dot(3);
 delay(3000);
}