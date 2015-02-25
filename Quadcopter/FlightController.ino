void FlightController() {
  unsigned int motorFrValue, motorFlValue, motorBrValue, motorBlValue;
  unsigned int throttle, pitch, roll, yaw;

  //motor values are computed by adding throttle, roll, yaw and pitch
  throttle = map(rxThrottle, RX_THROTTLE_MIN, RX_THROTTLE_MAX, MOTOR_ZERO_LEVEL, MOTOR_MAX_LEVEL);
  
  //For debug and test only
  pitch = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, -50, 50);
  roll  = map(rxRoll, RX_ROLL_MIN, RX_ROLL_MAX, -50, 50);
  yaw   = map(rxYaw, RX_YAW_MIN, RX_YAW_MAX, -50, 50);

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
