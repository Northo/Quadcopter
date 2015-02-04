/*
Quick and dirty test of how to control ESCs. Loop with delay to test how ESCs respond to different pulses.
 */

#define ESC_PIN = 9;
int value = 0, delayTime = 10;

void setup() {
  pinMode(ESC_PIN, OUTPUT);
}

void loop() {
  digitialWrite(ESC_PIN, value);
  value != value;
  delayMicroseconds(delayTime);
}
