/*
Karsten Sebastian Stadler, Martin Due Andersen and Thorvald Molthe Ballestad
 Ullern VGS - 2015

Quadcopter.ino is the main file.
*/

#define _DUE_BOARD
//#define _UNO_BOARD

#define STOP_MAX //stop motor values to exeeding extremals
//#define DEBUG

#include "config.h"
#include <PID.h>

volatile unsigned int rxThrottle, rxPitch, rxRoll, rxYaw, rxAux1, rxAux2;


void setup() {
  Wire.begin();
  rxInit();
  #ifdef DEBUG
    Serial.begin(9600);
  #endif
  delay(1);
  sixDOF.init();
  delay(1); //delay for å være sikker på at gyroAcc starter opp. Kanskje ikke nødvendig med så mye tid
}

void loop() {
  Gyro();
  FlightController(); //writes appropriate values to motors using PID
}
