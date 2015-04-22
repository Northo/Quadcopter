#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>

#include <Wire.h>

float acc[3];

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
  sixDOF.getYawPitchRoll(acc);

  Serial.print(acc[0]);
  Serial.print(" | ");
  Serial.print(acc[1]);
  Serial.print(" | ");
  Serial.println(acc[2]);

  delay(100); 
}

