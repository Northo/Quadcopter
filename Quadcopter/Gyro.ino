void Gyro() {
  sixDOF.getRawValues(angles);
}

void gyroInit() {
  sixDOF.getRawValues(anglesInit);
}
