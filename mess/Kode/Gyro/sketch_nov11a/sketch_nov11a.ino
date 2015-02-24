/*----------------------------------
Thorvald - 2014

Dette er hovedsakelig bare en demonstrasjon på hvordan man kan lese verdier fra akselerometeret og gjøre dem om til g(9.81m/s^2). Obs. Av koden kan man få inntrykk av at det er snakk om et gyroskop, det er det *ikke*, det er et akselerometer, men man ville lest et gyroskop på ganske lik måte.

Det er veldig mye komentarer i denne filen( markert med // og /*[..] * /), dette er bare for å gjøre alt så forstålig som mulig, ikke vanligvis nødvendig å komentere så mye.

Vi må bruke en litt modifisert versjon av dette programmet til selve quadcopteret; for det første er det ikke noe grunn til å gjøre om til g, og dette programmet måler kun én verdi

-------------------------------------*/

int gyroPin = 0, sampleSize = 10;
float gyroVoltage = 3.3, gyroZero = 1.65, gyroSensitivity = 0.057, gyroRate, gyroCali; //gyroRate og gyroCali får ikke en verdi, man sier på en måte "disse finnes, men har ikke en verdi enda". Vi gjør dette for at 'scope`et' til variabelen skal være over hele programmet, altså ikke bare inne i en funksjon


/*
Gyro sensitivity: V/g (volt per 9.81m/s^2). 
Gyro zero: Hva gyro outputter når g = 0.
Gyro Voltage: V når g = 16
 */
void setup() { //Alt surret med lamper av-og-på og delay osv. er bare for at man skal kunne se at arduinoen er i calibreringsmodus
   pinMode(13, OUTPUT);
   analogReference(EXTERNAL); 
   Serial.begin(9600);
   digitalWrite(13, HIGH);
   delay(1000);
   calibrate();//funksjon definert lengre ned. Returnerer ingenting, men endrer verdien til variabelen gyroCali
   digitalWrite(13, LOW);
}

void loop() {
  gyroRate = getSample(gyroPin);
  gyroRate = wToV(gyroRate);
  gyroRate -= gyroCali; //Trekk ifra null,verdien
  Serial.println(gyroRate);
}

void calibrate() { 
  gyroCali = getSample(gyroPin); //Mål en null-verdi
  gyroCali = wToV(gyroCali); //gjør om til volt
}

float wToV(float input) {
  input *= gyroVoltage/1023; //multipliser input med gyroVoltage og divider så på 1023(gjør om fra 1023 skala(vet ikke hva den er) til volt)
  input -= gyroZero; //trekk ifra gyroZero, slik at 0g gir 0 volt, negativ g gir negativ volt og positiv g gir positiv v
  input /= gyroSensitivity; //Del på sensitiviteten til gyroen(Volt til g(9.81m/s^2)). Sensitiviteten er oppgitt som V/g, i datasheetet til gyroen er det oppgitt i mV/g, men jeg har gjort det om til V/g.
  return input;
}

int getSample(int pin) { //Finner gjennomsnittet av et visst antall målinger(sampleSize er definert helt øverst)
  long tmp = 0;
    for(int i = 0; i < sampleSize; i++) {
      tmp += analogRead(pin);
    }
    
    return tmp/sampleSize;
}
