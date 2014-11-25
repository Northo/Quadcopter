const int rxPin = 8; //'const' forteller compileren(det programmet som oversetter fra engelsk til datakode(0'er og 1'ere) at denne variabelen ikke kan forandres(hvis man senere i programmet pr�ver � gi den en ny verdi vil man f� en error). Det er strengt tatt ikke n�dvendig, men er mer elegant, og hvis hjelpe � ung� feil i store programmer
const int sound = 13;

void setup() {
 pinMode(rxPin, INPUT);
 pinMode(sound, OUTPUT); 
}

void loop() {
 int rx = pulseIn(rxPin, HIGH);
 tone(sound, map(rx, 1000, 2000, 0, 3000)); //,map(pulseIn(9, HIGH), 1000, 2000, 0, 50));
 delay(10); 
}
