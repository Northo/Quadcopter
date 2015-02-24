class GyroRead {
 public:
  GyroRead(int pin);
  int getRawValue();
  int getG();

 private:
  int _pin;
  float gyroVoltage;
  float gyroZero;
  float gyroSensitivity;
};
