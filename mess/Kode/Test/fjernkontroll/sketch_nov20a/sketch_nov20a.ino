//#include <sketch_nov20a.h>

int ch1Pin = 8, ch1, pin = 11;//pin må ha pwm

void setup() {
  pinMode(ch1Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  ch1 = pulseIn(ch1Pin, HIGH);
  ch1 = map(ch1, 1000, 2000, 0, 255); //map(value, fromMin, fromMax, toMin, toMax)
  analogWrite(pin, ch1);
  Serial.println(ch1);
}
