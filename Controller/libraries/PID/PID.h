class PID {
 public:
  PID(int pin);
  int evaluate();

 private:
  int _pin;
  int _lastError;
  int _sumError;
  int _gyro;
  int _kp;
  int _ki;
  int _kd;
};
