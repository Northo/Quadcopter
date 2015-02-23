//Header fil, på en måte en oversikt over hva som kommer i cpp fila. Vi definerer her en mengde ting og tang.

class PID {
 public:
  PID();
  int evaluate(int setpoint, int value);

 private:
  int _setpoint;
  int _pin;
  int _lastError;
  int _sumError;
  int _gyro;
  int _kp;
  int _ki;
  int _kd;
};
