const int sampleSize = 10;
int xPin=0, yPin=1, zPin=2, x, y, z;

void setup() {
  Serial.begin(9600);
}

void loop() {
  x = analogRead(xPin);
  y = analogRead(yPin);
  z = analogRead(zPin);
  
  Serial.print(x);
  Serial.print(" : ");
  Serial.print(y);
  Serial.print(" : ");
  Serial.println(z);
}

int getSample(int pin) {
  float sum = 0;
  
  for(int i = 0; i < sampleSize; i++) {
    sum += analogRead(pin);
  }
  return sum/sampleSize;
}
