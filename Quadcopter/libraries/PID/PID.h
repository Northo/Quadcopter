class PID {
 public:
  PID(int min, int max);
  int evaluate(int value);
  void update(int setpoint);
  void updateParameters(float kp, float ki, float kd);

 private:
  int _setpoint;
  int _lastTime;
  int _lastError;
  int _sumError;
  float _kp;
  float _ki;
  float _kd;
  int _max;
  int _min;
};
