/*
Karsten Sebastian Stadler, Martin Due Andersen and Thorvald Molthe Ballestad
 Ullern VGS - 2015

Quadcopter.ino is the main file.
*/

#define _DUE_BOARD
//#define _UNO_BOARD

#define STOP_MAX //stop motor values to exeeding extremals
#define DEBUG

#include "config.h"

volatile unsigned int rxThrottle, rxPitch, rxRoll, rxYaw, rxAux1, rxAux2;

void setup() {
  rxInit();
  #ifdef DEBUG
    Serial.begin(9600);
  #endif

}

void loop() {
  FlightController(); //writes appropriate values to motors using PID
}
