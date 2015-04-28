/*
  Tester PID om en akse. Her er setpoint satt til 0(kan settes til en annen fast verdi), slik at problemer med å lese fjernkontroll ikke har noe å si.
 */

#include <PID.h>
#include <Wire.h>
#include <FreeSixIMU.h>

PID pid;
FreeSixIMU sixDOF = FreeSixIMU();

//define er en del av c preprocessor. alle steder der det står 'MOTOR1PIN' vil bli byttet med 10, før kompilering. Dette betyr at det ikke trenger å ta plass i minnet
#define MOTOR1PIN 10 // må være pwm
#define MOTOR2PIN 11 // må være pwm

#define MOTOR_MODERATE_LEVEL 270

int throttle = MOTOR_MODERATE_LEVEL; //kan event. styres med fjernkontroll i en senere versjon
void setup() {
  pid.update(0);//setpoint konstant 0
}

void loop() {
  float yawPitchRoll[3];
  sixDOF.getYawPitchRoll(yawPitchRoll); //sett yaw, pitch og roll inn i array 'yawPitchRoll'. Denne funksjonen kommer fra FreeSixIMU biblioteket

  int motor1 = throttle + pid.evaluate(yawPitchRoll[1]); //kanskje må jawPitchRoll[1] castes: gjøres om fra float til int. Det gjøres slik: 'pid.evaluate((int) yawPitchRoll[1]);'
  int motor2 = throttle - pid.evaluate(yawPitchRoll[1]);

  analogWrite(MOTOR1PIN, motor1);
  analogWrite(MOTOR2PIN, motor2);
}
