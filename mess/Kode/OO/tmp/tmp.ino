#include "GyroRead.h"

GyroRead x(8);

void setup() {
 Serial.begin(9600);
}

void loop() {
 Serial.println(x.getG());
}