#include "remote.h"

Remote collective(8), yaw(9);

void setup() {
     Serial.begin(9600);
}

void loop() {
     Serial.print(yaw.getValue());
     Serial.print(" : ");
     Serial.println(collective.getDiff());
}