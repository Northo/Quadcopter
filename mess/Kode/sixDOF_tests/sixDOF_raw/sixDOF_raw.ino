#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>

#include <Wire.h>

float raw[6];

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
  sixDOF.getRawValues(raw);
  //  sixDOF.getValues(raw);

  Serial.print(raw[0]);//0-2 acc  3-5 gyro
  Serial.print(" | ");
  Serial.print(raw[1]);
  Serial.print(" | ");
  Seiral.print(raw[2]);
  Serial.print(" && ");
  Serial.print(raw[3]);
  Serial.print(" | ");
  Serial.print(raw[4]);
  Serial.print(" | ");
  Seiral.print(raw[5]);

  delay(100); 
}

