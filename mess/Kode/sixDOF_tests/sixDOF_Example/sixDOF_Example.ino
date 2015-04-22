#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>

#include <Wire.h>

float anglesE[3]; // yaw pitch roll
float angles[3];

// Set the FreeSixIMU object
//SDA - A4 && SDL - A5
FreeSixIMU sixDOF = FreeSixIMU();

void setup() { 
  Serial.begin(9600);
  Wire.begin();
  
  delay(5);
  sixDOF.init(); //begin the IMU
  delay(5);
}

void loop() { 
  
  sixDOF.getEuler(anglesE);
  sixDOF.getAngles(angles);
  
  Serial.print(anglesE[0]);
  Serial.print(" - ");
  Serial.print(angles[0]);
  Serial.print(" | ");  
  Serial.print(anglesE[1]);
  Serial.print(" - ");
  Serial.print(angles[1]);
  Serial.print(" | ");
  Serial.print(anglesE[2]);
  Serial.print(" - ");
  Serial.println(angles[2]);
  
  delay(500); 
}

