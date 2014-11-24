/*
 Skriver ut en veldig enkel graf av fjernkontroll-verdien. Programmet skriver ut et '|' tegn for hver k'te (er ikke helt sikker p� hva k er, orker ikke regne det ut) verdi av fjernkontrollen. 

Den viktigste funksjonen er "int pulseIn(int pin, HIGH/LOW[, int timeout])" (betyr at funksjonen tar et heltall 'pin', og en verdi HIGH eller LOW(tror dette egentlig er en 'bool'-verdi(ja/nei eg. 1/0 eller TRUE/FALSE), men er ikke sikker). og eventuelt et heltall timeout(men ikke n�dvendigvis) som argumenter, og returnerer et heltall. Funksjonen m�ler en puls i spenningen(eg. et "fjell" eller en "dal")
    -int pin forteller hvilken digital pin signalet kommer p�
    -HIGH/LOW forteller om det er en spennings �kning eller fall
            ..
    ......./  \......... high pulse

    .......    ......... low pulse
           \__/

    -int timeout forteller hvor mange mikrosekunder pulsen maksimalt kan ha
    returnerer antall mikrosekunder

    map-funksjonen kan v�re forvirrende, men er veldig nyttig n�r du kan den. Den er definert slik: long map(long value, long fromLow, long fromHigh, long toLow, long toHigh). Long er en datatype, akkuratt som float(desimaltall) og int(heltall) og char(bokstav) og String(tekst) og bool[ean](true/false) og mange andre. Det er veldig lik int, bare at maksverdien er mye st�rre(int kan bli maksimalt (+/-) 2,147,483,647, mens long kan bli (+/-) 9,223,372,036,854,775,807. For spessiellt intereserte, int er en s�kalt "signed(kan v�re positiv og negativ, i motsettning til unsigned) 32-bit integer(heltall p� engelsk)" og long "signed 64-bit integer"
    Funksjonen virker skremmende, men er egentlig ganske logisk. Den konverterer en verdi fra en skala til en annen. Fra-skalaen er oppgitt ved fromLow og fromHigh og liknende med til-skalaen. Matten bak funksjonen er : "return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;"
    mer p�: http://www.arduino.cc/en/Reference/Map
    Det er viktig � v�re oppmerksom p� at map returnerer en long-verdi, s� hvis du setter inn en float-verdi(desimaltall) s� vil desimaltallene forsvinne. eg. hvis du vil konvertere et tall til en skala fra 0 til 1 s� vil ikke f.eks. 0.1 eksistere.
*/

const int SWITCH = 8;
int switchVal;

void setup() {
  Serial.begin(9600); //�pne en serial(eg. usb)(01-kommunikasjon, ikke parallell) med 9600beud(tror det er bps(bits per second) men ikke helt sikker). Det er ikke s� viktig � forst� denne komandoen, man bruker kjeldent noe annet en 9600. Det er denne serialen vi bruker n�r vi leser verdier fra arduinoen(Serial.print[ln]. Lik JavaScripts Console.log())
}
double t;
int count = 0;
void loop() {
  count+=1;
  t = millis();
  switchVal=pulseIn(SWITCH, HIGH);
  for(int i = 0; i < map(switchVal, 1000, 2000, 0, 80); i++) {
    Serial.print("|"); 
  }
  Serial.println();
  for(int i = 0; i < sin((float)count/6)*50+25; i++) {
    Serial.print("&");
  }
  Serial.println(); //Newline
  delay(10);
}
