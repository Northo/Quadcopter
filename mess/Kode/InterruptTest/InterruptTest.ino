volatile int t, rx;

void setup() {
  pinMode(2, INPUT_PILLUP);
  Serial.begin(9600);

  attachInterrupt(0, goesHigh, RISING); //int.0 = pin 2, int.1 = pin 3
  //attachInterrupt(pin, ISR, mode); //due
}

void loop() {
  Serial.println(rx);

  delay(100);
}

void goesHigh() {
  t = micros();
  attachInterrupt(0, goesLow, FALLING);
}

void goesLow() {
  rx = micros() - t; //Tiden pulsen var HIGH
  attachInterrupt(0, goesLow, RISING); //obs. pin for due
}
