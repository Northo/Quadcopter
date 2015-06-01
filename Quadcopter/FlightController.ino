void FlightController() {
  int motor[2][2]; //[F/B][R/L] motor[0][1]:motor front left

  float throttle, pitch, pitchSet, roll, rollSet, yaw, yawSet;

  //motor values are computed by adding throttle, roll, yaw and pitch
  throttle = map(rxThrottle, RX_THROTTLE_MIN, RX_THROTTLE_MAX, THROTTLE_MIN, THROTTLE_MAX);

  //xxSet er ønsket verdi, setpoint. Her i antall grader. xx er det som skal sendes til motor
  //  pitch = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN, PITCH_MAX);
  pitchSet = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN, PITCH_MAX); //Regner ut ønsket hellning på pitch
  rollSet  = map(rxRoll, RX_ROLL_MIN, RX_ROLL_MAX, ROLL_MIN, ROLL_MAX);
  yaw   = map(rxYaw, RX_YAW_MIN, RX_YAW_MAX, YAW_MIN, YAW_MAX);

  pitchPID.update( map(pitchSet, PITCH_MIN, PITCH_MAX, -10, 10));
  rollPID.update( map(rollSet, ROLL_MIN, ROLL_MAX, -10, 10));
  //  pitchPID.update(0);
  //  rollPID.update(0);
  
  pitch = pitchPID.evaluate(angles[0] - anglesInit[0]);
  roll = rollPID.evaluate(angles[1] - anglesInit[1]);

  motor[0][0] = throttle - pitch + roll - yaw;
  motor[0][1] = throttle - pitch - roll + yaw;
  motor[1][0] = throttle + pitch + roll + yaw;
  motor[1][1] = throttle + pitch - roll - yaw;

  int i, j;
#ifdef SAFE
  if(rxAux1 < (RX_AUX1_MAX + RX_AUX1_MIN)/2 ) {
    for(i=0; i<2; i++) {
      for(j=0; j<2; j++) {
	motor[i][j] = MOTOR_ZERO_LEVEL;
      }
    }
  }
#endif

#ifdef STOP_MAX //Don't know if this will stay or not, if successfull, remove if
    for(i=0; i<2; i++) {
      for(j=0; j<2; j++) {
	if(motor[i][j] > MOTOR_MAX_LEVEL)
	  motor[i][j] = MOTOR_MAX_LEVEL;
	
	if(motor[i][j] < MOTOR_ZERO_LEVEL)
	  motor[i][j] = MOTOR_ZERO_LEVEL;
      }
    }
#endif

    for(i=0; i<2; i++) {
      for(j=0; j<2; j++) {
	motorS[i][j].writeMicroseconds(motor[i][j]);
      }
    }
}
/*
byte zeroToMinus(bool n) {
  return n ? 1 : -1; //1 is 1 and 0 is -1
}
*/
