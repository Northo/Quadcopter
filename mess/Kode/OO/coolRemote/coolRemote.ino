#include "remote.h"

Remote collective(9);

void setup() {
     Serial.begin(9600);
}

void loop() {
     Serial.println(collective.getValue());
}