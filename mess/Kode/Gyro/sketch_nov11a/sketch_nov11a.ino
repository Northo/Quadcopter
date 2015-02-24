/*----------------------------------
Thorvald - 2014

Dette er hovedsakelig bare en demonstrasjon p� hvordan man kan lese verdier fra akselerometeret og gj�re dem om til g(9.81m/s^2). Obs. Av koden kan man f� inntrykk av at det er snakk om et gyroskop, det er det *ikke*, det er et akselerometer, men man ville lest et gyroskop p� ganske lik m�te.

Det er veldig mye komentarer i denne filen( markert med // og /*[..] * /), dette er bare for � gj�re alt s� forst�lig som mulig, ikke vanligvis n�dvendig � komentere s� mye.

Vi m� bruke en litt modifisert versjon av dette programmet til selve quadcopteret; for det f�rste er det ikke noe grunn til � gj�re om til g, og dette programmet m�ler kun �n verdi

-------------------------------------*/

int gyroPin = 0, sampleSize = 10;
float gyroVoltage = 3.3, gyroZero = 1.65, gyroSensitivity = 0.057, gyroRate, gyroCali; //gyroRate og gyroCali f�r ikke en verdi, man sier p� en m�te "disse finnes, men har ikke en verdi enda". Vi gj�r dette for at 'scope`et' til variabelen skal v�re over hele programmet, alts� ikke bare inne i en funksjon


/*
Gyro sensitivity: V/g (volt per 9.81m/s^2). 
Gyro zero: Hva gyro outputter n�r g = 0.
Gyro Voltage: V n�r g = 16
 */
void setup() { //Alt surret med lamper av-og-p� og delay osv. er bare for at man skal kunne se at arduinoen er i calibreringsmodus
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
  gyroCali = getSample(gyroPin); //M�l en null-verdi
  gyroCali = wToV(gyroCali); //gj�r om til volt
}

float wToV(float input) {
  input *= gyroVoltage/1023; //multipliser input med gyroVoltage og divider s� p� 1023(gj�r om fra 1023 skala(vet ikke hva den er) til volt)
  input -= gyroZero; //trekk ifra gyroZero, slik at 0g gir 0 volt, negativ g gir negativ volt og positiv g gir positiv v
  input /= gyroSensitivity; //Del p� sensitiviteten til gyroen(Volt til g(9.81m/s^2)). Sensitiviteten er oppgitt som V/g, i datasheetet til gyroen er det oppgitt i mV/g, men jeg har gjort det om til V/g.
  return input;
}

int getSample(int pin) { //Finner gjennomsnittet av et visst antall m�linger(sampleSize er definert helt �verst)
  long tmp = 0;
    for(int i = 0; i < sampleSize; i++) {
      tmp += analogRead(pin);
    }
    
    return tmp/sampleSize;
}
