class Gyro {
 public:
  Gyro(int pin);
  int read();
  void calibrate();

 private:
  int _pin;
};
