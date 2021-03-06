volatile int t[6];

void rxInit() {
  attachInterrupt(RX_PIN_THROTTLE, rxGoesUpThrottle, RISING);
  attachInterrupt(RX_PIN_PITCH, rxGoesUpPitch, RISING);
  attachInterrupt(RX_PIN_ROLL, rxGoesUpRoll, RISING);
  attachInterrupt(RX_PIN_YAW, rxGoesUpYaw, RISING);
  attachInterrupt(RX_PIN_AUX1, rxGoesUpAux1, RISING);
  attachInterrupt(RX_PIN_AUX2, rxGoesUpAux2, RISING);
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

void rxGoesUpAux2() {
  attachInterrupt(RX_PIN_AUX2, rxGoesDownAux2, FALLING);
  t[5]=micros();
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

void rxGoesDownAux2() {
  rxAux2 = micros() - t[5];
  attachInterrupt(RX_PIN_AUX2, rxGoesUpAux2, RISING);
}
