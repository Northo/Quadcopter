#define IN_PIN = 0;
#define ESC = 9;

void setup() {
  pinMode(IN_PIN, INPUT);
}

void loop() {
  int value = analogRead(IN_PIN);
  analogWrite(ESC, map(value, 0, 1023, 0, 255) );
}
