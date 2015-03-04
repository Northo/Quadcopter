void FlightController() {
  int motorFrValue, motorFlValue, motorBrValue, motorBlValue;
  int throttle, pitch, roll, yaw;

  //motor values are computed by adding throttle, roll, yaw and pitch
  throttle = map(rxThrottle, RX_THROTTLE_MIN, RX_THROTTLE_MAX, MOTOR_ZERO_LEVEL, MOTOR_MAX_LEVEL);
  
  //For debug and test only
  pitch = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN, PITCH_MAX);
  roll  = map(rxRoll, RX_ROLL_MIN, RX_ROLL_MAX, ROLL_MIN, ROLL_MAX);
  yaw   = map(rxYaw, RX_YAW_MIN, RX_YAW_MAX, YAW_MIN, YAW_MAX);

  motorFrValue = throttle - pitch + roll + yaw;
  motorFlValue = throttle - pitch - roll + yaw;
  motorBrValue = throttle + pitch + roll - yaw;
  motorBlValue = throttle + pitch - roll - yaw;

  /*  motorFrValue = throttle - pitch;
  motorFlValue = throttle - pitch;
  motorBrValue = throttle + pitch;
  motorBlValue = throttle + pitch;*/

  //PWM might damage motors
  analogWrite(MOTOR_FR, motorFrValue);
  analogWrite(MOTOR_FL, motorFlValue);
  analogWrite(MOTOR_BR, motorBrValue);
  analogWrite(MOTOR_BL, motorBlValue);
}
