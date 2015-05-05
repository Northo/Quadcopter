void FlightController() {
  int motor[2][2]; //[F/B][R/L] motor[0][1]:motor front left

  int throttle, pitch, pitchSet, roll, rollSet, yaw, yawSet;
  //PID pidPitch, pidRoll; scope

  //motor values are computed by adding throttle, roll, yaw and pitch
  throttle = map(rxThrottle, RX_THROTTLE_MIN, RX_THROTTLE_MAX, THROTTLE_MIN, THROTTLE_MAX);

  //xxSet er ønsket verdi, setpoint. Her i antall grader. xx er det som skal sendes til motor
  //  pitch = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN, PITCH_MAX);
  pitchSet = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN_DEG, PITCH_MAX_DEG); //Regner ut ønsket hellning på pitch
  rollSet  = map(rxRoll, RX_ROLL_MIN, RX_ROLL_MAX, ROLL_MIN, ROLL_MAX);
  yawSet   = map(rxYaw, RX_YAW_MIN, RX_YAW_MAX, YAW_MIN, YAW_MAX);


  pidPitch.update(pitchSet);
  pidRoll.update(rollSet);

  pitch = pitchSet + pidPitch.evaluate(angles[1]);
  roll = rollSet + pidRoll.evaluate(angles[2]);
  yaw = yawSet;

  int i, j;
  for(i = 0; i < 2; i++) {
    for(j = 0; j < 2; j++) {
      motor[i][j] = (int) throttle\
	+ pitch*zeroToMinus(i)\
	+ roll*zeroToMinus(j)\
	+ yaw*zeroToMinus(i xor j);
    }
  } 


#ifdef SAFE
  if(rxAux1 < (RX_AUX1_MAX + RX_AUX1_MIN)/2 ) {
    for(i=0; i<2; i++) {
      for(j=0; j<2; j++) {
	motor[i][j] = MOTOR_ZERO_LEVEL;
      }
    }
  }
#endif

  //PWM might damage motors
  analogWrite(MOTOR_FR, motor[0][0]);
  analogWrite(MOTOR_FL, motor[0][1]);
  analogWrite(MOTOR_BR, motor[1][0]);
  analogWrite(MOTOR_BL, motor[1][1]);
}

byte zeroToMinus(bool n) {
  return n ? 1 : -1; //1 is 1 and 0 is -1
}
