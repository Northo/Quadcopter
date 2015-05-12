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
#include <PID.h>
#include <Wire.h> //Library for å snakke med gyro/acc
#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>

volatile unsigned int rxThrottle, rxPitch, rxRoll, rxYaw, rxAux1, rxAux2;
float angles[3];
PID pidPitch, pidRoll;
float pidSensitivity = 0.01;

FreeSixIMU sixDOF = FreeSixIMU(); //AccGyro

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
int loopTime;
void loop() {
  loopTime = millis();
  Gyro();
  FlightController(); //writes appropriate values to motors using PID
  Serial.println(millis() - loopTime);
}
