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
#include <Servo.h>
#include <PID.h>
#include <Wire.h>
#include <SPI.h>

#include "DebugUtils.h"
#include <I2Cdev.h>

#include <ADXL345.h>
#include <ITG3200.h>
#include <FreeIMU.h>

volatile unsigned int rxThrottle, rxPitch, rxRoll, rxYaw, rxAux1, rxAux2;

Servo motorS[2][2];
FreeIMU sixDOF = FreeIMU();

PID pitchPID = PID(MOTOR_ZERO_LEVEL, MOTOR_MAX_LEVEL);
PID rollPID = PID(MOTOR_ZERO_LEVEL, MOTOR_MAX_LEVEL);

float angles[3];

void setup() {
  rxInit();
  Wire.begin();
  delay(300);
  sixDOF.init();
  delay(300);
#ifdef DEBUG
  Serial.begin(9600);
#endif

  motorS[0][0].attach(MOTOR_FR);
  motorS[0][1].attach(MOTOR_FL);
  motorS[1][0].attach(MOTOR_BR);
  motorS[1][1].attach(MOTOR_BL);

  pitchPID.updateParameters(0.5, 0, 0);
  rollPID.updateParameters(0.5, 0, 0);

  motorS[0][0].write(MOTOR_ARM);
  motorS[0][1].write(MOTOR_ARM);
  motorS[1][0].write(MOTOR_ARM);
  motorS[1][1].write(MOTOR_ARM);

  //  pitchPID.update(0);
  //  rollPID.update(0);
}

void loop() {
  Gyro();
  //  pitchPID.updateParameters(mapD(rxAux2, RX_AUX2_MIN, RX_AUX2_MAX, 0.05, 0.6), 0.00, 0);
  //  rollPID.updateParameters(mapD(rxAux2, RX_AUX2_MIN, RX_AUX2_MAX, 0.05, 0.6), 0.00, 0); //ole jacob
  pitchPID.updateParameters(0.1, 0.00, 0);
  rollPID.updateParameters(0.1, 0.00, 0); //ole jacob

  FlightController(); //writes appropriate values to motors using PID
}

float mapD(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
