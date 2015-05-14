void FlightController() {
  int motor[2][2]; //[F/B][R/L] motor[0][1]:motor front left

  float throttle, pitch, pitchSet, roll, rollSet, yaw, yawSet;

  //motor values are computed by adding throttle, roll, yaw and pitch
  throttle = map(rxThrottle, RX_THROTTLE_MIN, RX_THROTTLE_MAX, THROTTLE_MIN, THROTTLE_MAX);

  //xxSet er ønsket verdi, setpoint. Her i antall grader. xx er det som skal sendes til motor
  //  pitch = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN, PITCH_MAX);
  pitch = map(rxPitch, RX_PITCH_MIN, RX_PITCH_MAX, PITCH_MIN, PITCH_MAX); //Regner ut ønsket hellning på pitch
  roll  = map(rxRoll, RX_ROLL_MIN, RX_ROLL_MAX, ROLL_MIN, ROLL_MAX);
  yaw   = map(rxYaw, RX_YAW_MIN, RX_YAW_MAX, YAW_MIN, YAW_MAX);

   int i, j;
   /*
  for(i = 0; i < 2; i++) {
    for(j = 0; j < 2; j++) {
      motor[i][j] = (int) throttle\
	+ pitch*zeroToMinus(i)\
	+ roll*zeroToMinus(j)\
	+ yaw*zeroToMinus(i xor j);
    }
  } 
  */

  motor[0][0] = throttle - pitch + roll - yaw;
  motor[0][1] = throttle - pitch - roll + yaw;
  motor[1][0] = throttle + pitch + roll + yaw;
  motor[1][1] = throttle + pitch - roll - yaw;


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

byte zeroToMinus(bool n) {
  return n ? 1 : -1; //1 is 1 and 0 is -1
}
