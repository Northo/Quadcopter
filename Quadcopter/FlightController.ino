void FlightController() {
  int motorFrValue, motorFlValue, motorBrValue, motorBlValue;
  int throttle, pitch, roll, yaw;
  PID pidPitch;
  
  pidPitch.update( map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN, PITCH_MAX) );
  //motor values are computed by adding throttle, roll, yaw and pitch
  throttle = map(rxThrottle, RX_THROTTLE_MIN, RX_THROTTLE_MAX, THROTTLE_MIN, THROTTLE_MAX);
  
  pitch = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN, PITCH_MAX) + pidPitch.evaluate(gyro[0]);
  roll  = map(rxRoll, RX_ROLL_MIN, RX_ROLL_MAX, ROLL_MIN, ROLL_MAX);
  yaw   = map(rxYaw, RX_YAW_MIN, RX_YAW_MAX, YAW_MIN, YAW_MAX);

  motorFrValue = throttle - pitch - roll + yaw;
  motorFlValue = throttle - pitch + roll - yaw;
  motorBrValue = throttle + pitch - roll - yaw;
  motorBlValue = throttle + pitch + roll + yaw;

#ifdef SAFE
  if(rxAux1 < (RX_AUX1_MAX + RX_AUX1_MIN)/2 ) {
      motorFrValue = MOTOR_ZERO_LEVEL;
      motorFlValue = MOTOR_ZERO_LEVEL;
      motorBrValue = MOTOR_ZERO_LEVEL;
      motorBlValue = MOTOR_ZERO_LEVEL;
  }

#endif
  //PWM might damage motors
  analogWrite(MOTOR_FR, motorFrValue);
  analogWrite(MOTOR_FL, motorFlValue);
  analogWrite(MOTOR_BR, motorBrValue);
  analogWrite(MOTOR_BL, motorBlValue);
}
