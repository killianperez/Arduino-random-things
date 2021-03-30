/*
LICENSE MIT
BY : KILLIAN PEREZ
DATE: 2019, December 17th
DESCRIPTION:
   Code example for a unique 7-segments display
   Exemple de code pour un unique afficheur 7 segments.
*/

/* Pin used for display */
const byte PIN_SEGMENT_A = 2;
const byte PIN_SEGMENT_B = 3;
const byte PIN_SEGMENT_C = 4;
const byte PIN_SEGMENT_D = 5;
const byte PIN_SEGMENT_E = 6;
const byte PIN_SEGMENT_F = 7;
const byte PIN_SEGMENT_G = 8;
const byte PIN_SEGMENT_DP = 9;
const byte PIN_SEGMENT_INT = A0;

/** Fonction setup() */
void setup() {
  Serial.begin(9600);
  /* We set all pin as OUTPUT */
  pinMode(PIN_SEGMENT_A, OUTPUT);
  digitalWrite(PIN_SEGMENT_A, HIGH);
  pinMode(PIN_SEGMENT_B, OUTPUT);
  digitalWrite(PIN_SEGMENT_B, HIGH);
  pinMode(PIN_SEGMENT_C, OUTPUT);
  digitalWrite(PIN_SEGMENT_C, HIGH);
  pinMode(PIN_SEGMENT_D, OUTPUT);
  digitalWrite(PIN_SEGMENT_D, HIGH);
  pinMode(PIN_SEGMENT_E, OUTPUT);
  digitalWrite(PIN_SEGMENT_E, HIGH);
  pinMode(PIN_SEGMENT_F, OUTPUT);
  digitalWrite(PIN_SEGMENT_F, HIGH);
  pinMode(PIN_SEGMENT_G, OUTPUT);
  digitalWrite(PIN_SEGMENT_G, HIGH);
  pinMode(PIN_SEGMENT_DP, OUTPUT);
  digitalWrite(PIN_SEGMENT_DP, HIGH);
  pinMode(PIN_SEGMENT_INT, INPUT);
  
  allume(true, true, true, true, true, true, true, true);
}
void loop() {
  delay(100);
  int valeurPot=analogRead(A0);
  Serial.print("A0");
  delay(100);
  Serial.print(" === ");
  delay(100);
  Serial.print(valeurPot);
  delay(100);
  Serial.print(" === ");
  if (valeurPot < 204) {
    Serial.println("0");
    allume(true, true, true, true, true, true, false, true);
  } else if (valeurPot < 409) {
    allume(true, true, false, true, true, false, true, true);
    Serial.println("2");
  } else if (valeurPot < 613) {
    Serial.println("4");
    allume(false, true, true, false, false, true, false, true);
  } else if (valeurPot < 818) {
    Serial.println("6");
    allume(true, false, true, true, true, true, true, true);
  } else if (valeurPot < 818) {
    Serial.println("8");
    allume(true, true, true, true, true, true, true, true);
  } else if (valeurPot < 1023) {
    Serial.println("9");
    allume(true, true, true, true, false, true, true, true);
  } else {
    Serial.println("ERREUR");
    allume(true, false, true, false, false, true, true, false);
  }
}
void allume(bool PSA, bool PSB, bool PSC, bool PSD, bool PSE, bool PSF, bool PSG, bool PSDP) {
  if (PSA == true) {
    digitalWrite(PIN_SEGMENT_A, LOW);
    delay(50);
  } else {
    digitalWrite(PIN_SEGMENT_A, HIGH);
  } if (PSB == true) {
    digitalWrite(PIN_SEGMENT_B, LOW);
    delay(50);
  } else {
    digitalWrite(PIN_SEGMENT_B, HIGH);
  } if (PSC == true) {
    digitalWrite(PIN_SEGMENT_C, LOW);
    delay(50);
  } else {
    digitalWrite(PIN_SEGMENT_C, HIGH);
  } if (PSD == true) {
    digitalWrite(PIN_SEGMENT_D, LOW);
    delay(50);
  } else {
    digitalWrite(PIN_SEGMENT_D, HIGH);
  } if (PSE == true) {
    digitalWrite(PIN_SEGMENT_E, LOW);
    delay(50);
  } else {
    digitalWrite(PIN_SEGMENT_E, HIGH);
  } if (PSF == true) {
    digitalWrite(PIN_SEGMENT_F, LOW);
    delay(50);
  } else {
    digitalWrite(PIN_SEGMENT_F, HIGH);
  } if (PSG == true) {
    digitalWrite(PIN_SEGMENT_G, LOW);
    delay(50);
  } else {
    digitalWrite(PIN_SEGMENT_G, HIGH);
  } if (PSDP == true) {
    digitalWrite(PIN_SEGMENT_DP, LOW);
    delay(50);
  } else {
    digitalWrite(PIN_SEGMENT_DP, HIGH);
  }
}  

