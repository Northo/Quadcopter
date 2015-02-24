const int SWITCH = 8, PIN = 6;
int switchVal;
int max = 1500, min = 1500; //debug

void setup() {
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
}
double t;
int count = 0;
void loop() {
  count+=1;
  t = millis();
  switchVal=pulseIn(SWITCH, HIGH);
  Serial.println(switchVal);
  analogWrite(PIN, map(switchVal, 1000, 2000, 0, 255));
  //Serial.println(switchVal);
  delay(10);
}
