class GyroRead {
 public:
  GyroRead(int pin);
  int getRawValue();
  int getG();

 private:
  int _pin;
};
