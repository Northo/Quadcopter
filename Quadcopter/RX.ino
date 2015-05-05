//volatile int t[5];


void rxInit() {
  rxPitch = (RX_PITCH_MAX + RX_PITCH_MIN) / 2;
  rxRoll = (RX_ROLL_MAX + RX_ROLL_MIN) / 2;
  rxYaw = (RX_YAW_MAX + RX_YAW_MIN) / 2;
  //  rxAux1 = (RX_AUX1_MAX + RX_AUX1_MIN) / 2;
 
  attachInterrupt(0, rxGoesUpThrottle, RISING); //0: pin 2
  attachInterrupt(1, rxGoesUpAux1, RISING); //1: pin 3
}

void rxGoesUpThrottle() {
  t[0] = micros();
  attachInterrupt(0, rxGoesDownThrottle, FALLING);
}

void rxGoesDownThrottle() {
  rxThrottle = micros() - t[0];
  attachInterrupt(0, rxGoesUpThrottle, RISING);
}

void rxGoesUpAux1() {
  t[1] = micros();
  attachInterrupt(1, rxGoesDownAux1, FALLING);
}

void rxGoesDownAux1() {
  rxAux1 = micros() - t[1];
  attachInterrupt(1, rxGoesUpAux1, RISING);
}

/*
void rxInit() {
  attachInterrupt(RX_PIN_THROTTLE, rxGoesUpThrottle, RISING);
  attachInterrupt(RX_PIN_PITCH, rxGoesUpPitch, RISING);
  attachInterrupt(RX_PIN_ROLL, rxGoesUpRoll, RISING);
  attachInterrupt(RX_PIN_YAW, rxGoesUpYaw, RISING);
  attachInterrupt(RX_PIN_AUX1, rxGoesUpAux1, RISING);
}

//Not the most elegant solution, but it works(hopefully)
void rxGoesUpThrottle() {
  attachInterrupt(RX_PIN_THROTTLE, rxGoesDownThrottle, FALLING);
  t[0]=micros();
}

void rxGoesUpPitch() {  
  attachInterrupt(RX_PIN_PITCH, rxGoesDownPitch, FALLING);
  t[1]=micros();
}

void rxGoesUpRoll() {
  attachInterrupt(RX_PIN_ROLL, rxGoesDownRoll, FALLING);
  t[2]=micros();
}

void rxGoesUpYaw() {
  attachInterrupt(RX_PIN_YAW, rxGoesDownYaw, FALLING);
  t[3]=micros();
}

void rxGoesUpAux1() {
  attachInterrupt(RX_PIN_AUX1, rxGoesDownAux1, FALLING);
  t[4]=micros();
}

void rxGoesDownThrottle() {
  rxThrottle = micros() - t[0];
  attachInterrupt(RX_PIN_THROTTLE, rxGoesUpThrottle, RISING);
}

void rxGoesDownPitch() {
  rxPitch = micros() - t[1];
  attachInterrupt(RX_PIN_PITCH, rxGoesUpPitch, RISING);
}

void rxGoesDownRoll() {
  rxRoll = micros() - t[2];
  attachInterrupt(RX_PIN_ROLL, rxGoesUpRoll, RISING);
}

void rxGoesDownYaw() {
  rxYaw = micros() - t[3];
  attachInterrupt(RX_PIN_YAW, rxGoesUpYaw, RISING);
}

void rxGoesDownAux1() {
  rxAux1 = micros() - t[4];
  attachInterrupt(RX_PIN_AUX1, rxGoesUpAux1, RISING);
}
*/
