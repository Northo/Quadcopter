void FlightController() {
  unsigned int motorFrValue, motorFlValue, motorBrValue, motorBlValue;
  unsigned int throttle, pitch, roll, yaw;

  //motor values are computed by adding throttle, roll, yaw and pitch
  throttle = map(rxThrottle, RX_THROTTLE_MIN, RX_THROTTLE_MAX, MOTOR_ZERO_LEVEL, MOTOR_MAX_LEVEL);

  motorFrValue = throttle - pitch + roll + yaw;
  motorFlValue = throttle - pitch - roll + yaw;
  motorBrValue = throttle + pitch + roll - yaw;
  motorBlValue = throttle + pitch - roll - yaw;

  //PWM might damage motors
  analogWrite(MOTOR_FR, motorFrValue);
  analogWrite(MOTOR_FL, motorFlValue);
  analogWrite(MOTOR_BR, motorBrValue);
  analogWrite(MOTOR_BL, motorBlValue);
}
