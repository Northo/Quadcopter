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
#include <PID.h>
#include <Wire.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>
#include <FreeSixIMU.h>

volatile unsigned int rxThrottle, rxPitch, rxRoll, rxYaw, rxAux1, rxAux2;

Servo motorS[2][2];
FreeSixIMU sixDOF = FreeSixIMU();

PID pitchPID, rollPID;

int angles[6], anglesInit[6];

void setup() {
  rxInit();
  Wire.begin();
  sixDOF.init();
  delay(300);
  gyroInit(); //Must be after sixDOF init
#ifdef DEBUG
  Serial.begin(9600);
#endif
  motorS[0][0].attach(MOTOR_FR);
  motorS[0][1].attach(MOTOR_FL);
  motorS[1][0].attach(MOTOR_BR);
  motorS[1][1].attach(MOTOR_BL);

  pitchPID.updateParameters(0.5, 0, 1);
  rollPID.updateParameters(0.5, 0, 1);

  //  pitchPID.update(0);
  //  rollPID.update(0);
}

void loop() {
  Gyro();
  pitchPID.updateParameters(mapD(rxAux2, RX_AUX2_MIN, RX_AUX2_MAX, 0.05, 0.6), 0.01, 0);
  rollPID.updateParameters(mapD(rxAux2, RX_AUX2_MIN, RX_AUX2_MAX, 0.05, 0.6), 0.01, 0); //ole jacob
  FlightController(); //writes appropriate values to motors using PID
}

float mapD(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
