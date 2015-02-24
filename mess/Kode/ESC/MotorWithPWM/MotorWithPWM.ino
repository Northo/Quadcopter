int escPin = 9;

void setup() {
  pinMode(escPin, OUTPUT);
  analogWrite(escPin, 125);
  blink(13, 2);
  analogWrite(escPin, 140);
}

void loop() {
  analogWrite(escPin, 254);
}

void blink(int pin, int num) {
  for(int i = 0; i < num; i++) {
     digitalWrite(pin, HIGH);
     delay(1000); 
     digitalWrite(pin, LOW);
     delay(1000);
  }
}
