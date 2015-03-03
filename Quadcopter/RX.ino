void RX() {
  rxThrottle = readRx(RX_PIN_THROTTLE);
  rxPitch    = readRx(RX_PIN_PITCH);
  rxRoll     = readRx(RX_PIN_ROLL);
  rxYaw      = readRx(RX_PIN_YAW);
  rxAux1     = readRx(RX_PIN_AUX1);
  rxAux2     = readRx(RX_PIN_AUX2);
}

unsigned int readRx(int pin){
  return pulseIn(pin, HIGH, RX_TIMEOUT);
}
