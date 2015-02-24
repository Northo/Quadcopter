#include <Blink.h>

Blink b;

void setup() {
 b = new Blink(2000, 2000, 13);
}

void loop() {
     b->oneBlink();
}