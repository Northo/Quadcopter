void Gyro() {
  int i;
  for(i=0; i<NUMBER_OF_AXIS; i++) {
    gyro[i]=map(analogRead(gyroPin[i]), 0, 1024*GYRO_VOLTAGE/5, -15, 15); //Analog read gir en verdi mellom 0 og 1024 der 0 = 0v og 1024 = 5v. Gyro gir ut 3.3v. 0 akseleration gir ut 1.65v, altså halvparten av 3.3. 337 = (1024/5v)*3.3v/2. Dette kan gjøres mer elegant i fremtiden.
  }
}
