volatile t[5];

void rxInit() {
  attachInterrupt(RX_PIN_THROTTLE, pinChange, RISING);
  attachInterrupt(RX_PIN_PITCH, pinChange, RISING);
  attachInterrupt(RX_PIN_ROLL, pinChange, RISING);
  attachInterrupt(RX_PIN_YAW, pinChange, RISING);
  attachInterrupt(RX_PIN_AUX1, pinChange, RISING);
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
