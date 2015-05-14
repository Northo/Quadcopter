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
#include <Servo.h>

volatile unsigned int rxThrottle, rxPitch, rxRoll, rxYaw, rxAux1, rxAux2;

Servo motorS[2][2];

void setup() {
  rxInit();
  #ifdef DEBUG
    Serial.begin(9600);
  #endif
    
    motorS[0][0].attach(MOTOR_FR);
    motorS[0][1].attach(MOTOR_FL);
    motorS[1][0].attach(MOTOR_BR);
    motorS[1][1].attach(MOTOR_BL);
}

void loop() {
  FlightController(); //writes appropriate values to motors using PID
}
