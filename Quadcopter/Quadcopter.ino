/*
Karsten Sebastian Stadler, Martin Due Andersen and Thorvald Molthe Ballestad
 Ullern VGS - 2015

Quadcopter.ino is the main file.
*/

#include "config.h"
#include <PID>

void setup() {
}

void loop() {
  RX(); //Handles all RX
  FlightController(); //writes appropriate values to motors using PID
}
