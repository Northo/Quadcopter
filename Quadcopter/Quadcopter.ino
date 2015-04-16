/*
Karsten Sebastian Stadler, Martin Due Andersen and Thorvald Molthe Ballestad
 Ullern VGS - 2015

Quadcopter.ino is the main file.
*/

//#define _DUE_BOARD
#define _UNO_BOARD

//#define DEBUG

#include "config.h"
#include <PID.h>

volatile unsigned int rxThrottle, rxPitch, rxRoll, rxYaw, rxAux1, rxAux2;

void setup() {
  #ifdef DEBUG
    Serial.begin(9600);
  #endif
}

void loop() {
  RX(); //Handles all RX
  Gyro();
  FlightController(); //writes appropriate values to motors using PID
}
