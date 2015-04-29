void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // pull-down res 10kohm
  Serial.println(pulseIn(5, LOW));
  //Serial.println(digitalRead(5));
  delay(100);
}
