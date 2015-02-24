void FlightController() {
  int motorFrValue, motorFlValue, motorBrValue, motorBlValue;

  //motor values are computed by adding throttle, roll, yaw and pitch

  //PWM might damage motors
  analogWrite(MOTOR_FR, motorFrValue);
  analogWrite(MOTOR_FL, motorFlValue);
  analogWrite(MOTOR_BR, motorBrValue);
  analogWrite(MOTOR_BL, motorBlValue);
}
