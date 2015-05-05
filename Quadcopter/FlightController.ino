void FlightController() {
  int motorFrValue, motorFlValue, motorBrValue, motorBlValue;
  int throttle, pitch, pitchSet, roll, rollSet, yaw, yawSet;
  //  PID pidPitch, pidRoll; 

  //motor values are computed by adding throttle, roll, yaw and pitch
  throttle = map(rxThrottle, RX_THROTTLE_MIN, RX_THROTTLE_MAX, THROTTLE_MIN, THROTTLE_MAX);
  
  //xxSet er ønsket verdi, setpoint. Her i antall grader. xx er det som skal sendes til motor
  /*  //  pitch = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN, PITCH_MAX);
  pitchSet = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN_DEG, PITCH_MAX_DEG); //Regner ut ønsket hellning på pitch
  rollSet  = map(rxRoll, RX_ROLL_MIN, RX_ROLL_MAX, ROLL_MIN, ROLL_MAX);
  yawSet   = map(rxYaw, RX_YAW_MIN, RX_YAW_MAX, YAW_MIN, YAW_MAX);
  */
  pitchSet = 0;
  rollSet = 0;
  yawSet = 0;

  pidPitch.update(pitchSet);
  pidRoll.update(rollSet);

  pitch = pitchSet + pidPitch.evaluate(angles[1]);
  roll = rollSet + pidRoll.evaluate(angles[2]);
  yaw = yawSet;

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
  //  Serial.println(motorFrValue);
  analogWrite(MOTOR_FR, motorFrValue);
  analogWrite(MOTOR_FL, motorFlValue);
  analogWrite(MOTOR_BR, motorBrValue);
  analogWrite(MOTOR_BL, motorBlValue);
}
