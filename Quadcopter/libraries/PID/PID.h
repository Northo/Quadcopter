class PID {
 public:
  PID();
  int evaluate(int value);
  void update(int setpoint);

 private:
  int _setpoint;
  int _lastTime;
  int _lastError;
  int _sumError;
  int _kp;
  int _ki;
  int _kd;
};
