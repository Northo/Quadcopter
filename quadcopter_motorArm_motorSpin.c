#define collective_Pin = 0;
#define arm_switch_Pin = 1; /* Kan sette dette til channel 5 eller noe sånt (bare en flip-switch på fjernkontrollen)*/
int _on = 1; /* Antar her at flip-switch'en på fjernkontrollen enten sender 0 når den er av, og 1 når den er på. Denne flip-switch'en vil funke som armerings-bryter.*/ 
int escPin1 = 9;
int escPin2 = 12; /* Usikker på om det er PWM på pin'sene under?*/
int escPin3 = 11;
int escPin4 = 10;
const int Zero = 125;
const int Arm = 140;

void setup() {
  
  pinMode(collective_Pin, INPUT);
  pinMode(arm_switch_Pin, INPUT);
  
  pinMode(escPin1, OUTPUT);
  pinMode(escPin2, OUTPUT);
  pinMode(escPin3, OUTPUT);
  pinMode(escPin4, OUTPUT);
  
  analogWrite(escPin1, Zero);
  analogWrite(escPin2, Zero);
  analogWrite(escPin3, Zero);
  analogWrite(escPin4, Zero);
  
  if (analogRead(arm_switch pin) == _on){
    analogWrite(escPin1, Arm);
    analogWrite(escPin2, Arm);
    analogWrite(escPin3, Arm);
    analogWrite(escPin4, Arm);
  }
}

void loop() {
  
  int value = analogRead(collective_Pin);
  
  analogWrite(escPin1, map(value, 0, 1023, 0, 255) );
  analogWrite(escPin2, map(value, 0, 1023, 0, 255) );
  analogWrite(escPin3, map(value, 0, 1023, 0, 255) );
  analogWrite(escPin4, map(value, 0, 1023, 0, 255) );
}

