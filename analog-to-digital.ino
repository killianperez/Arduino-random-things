/*
LICENSE MIT
BY : KILLIAN PEREZ
DATE: 2019, December 17th
DESCRIPTION:
   Arduino -- Analog to digital arduino UNO
   Display result in terminal (9600)
   By default voltage is 5 volts
*/
int N ;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}         
void loop() {
  N=analogRead (A0);
  Serial.print("Result:");
  Serial.println(N);delay(1000);
}
