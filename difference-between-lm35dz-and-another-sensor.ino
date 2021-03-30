/*
LICENSE MIT
BY : KILLIAN PEREZ
DATE: 2019, December 17th
DESCRIPTION:
   Display temperature from LM35DZ sensor as metric system
*/
#include <Wire.h> // Libs
#include "rgb_lcd.h"

rgb_lcd lcd;

int colorR = 255; // Setting up background color
int colorG = 128;
int colorB = 0;
float ND;
float AffD;
float NR;
float AffR;

void setup() 
{
    // Initialize debug console with PC
    Serial.begin(9600);
    
    
    
    // set up the LCD's number of columns and rows:
    lcd.begin(16,2);
    lcd.clear();
    
    lcd.setRGB(colorR, colorG, colorB);
}

void loop() 
{
  int valeur_brute = analogRead(A0);
  float temperature_depart = valeur_brute * (5.0 / 1023.0 * 100.0);         // Compute beggining server
  float temperature_retour = rand() % 25 + 15;                              // Valeur aléatoire pour temp retour
  lcd.clear();                                                              // Delete text on screen
  if (temperature_depart==0.00) {                                           // Condition : if temp > 100°C
    lcd.setCursor(4,0);                                                     // Positionning text on screen
    lcd.print("Erreur:");                                                   // Wrote "error"
    lcd.setCursor(0,1);                                                     // Text position
    lcd.print("REBRANCHER CABLE");                                          // Write and change screen color
    colorR = 255;
    colorG = 45;
    colorB = 0;
    lcd.setRGB(colorR, colorG, colorB);
    delay(100);
  } else {                              // Normal work
    lcd.setCursor(0,0);     
    lcd.print("Temperature de");
    lcd.setCursor(2,1);
    lcd.print("depart:");
    delay(100);
    lcd.setCursor(9,1);
    lcd.print(temperature_depart);
    lcd.setCursor(15,1);
    lcd.print("C");
    delay(3000);
    lcd.setCursor(0,0);
    lcd.print("Temperature de");
    lcd.setCursor(2,1);
    lcd.print("retour:");
    delay(100);
    lcd.setCursor(9,1);
    lcd.print(temperature_retour);
    lcd.setCursor(15,1);
    lcd.print("C");
    delay(3000);
    lcd.clear();
    float diff = 0.01;
    if (temperature_depart>temperature_retour) {              // Temp difference value
       diff = (temperature_depart-temperature_retour);    
    } else if (temperature_retour>temperature_depart) {
       diff = (temperature_retour-temperature_depart);
    } else if (temperature_depart==temperature_retour) {
       diff = 0;
    }
    lcd.setCursor(0,0);             // display difference time between two temperaturs
    lcd.print("Ecart de temp");
    lcd.setCursor(6,1);
    lcd.print(diff);
    lcd.setCursor(12,1);
    lcd.print("C");
    delay(3000);
    
    for(int i=1; i<=10; ++i)
    {
      colorR++;
      colorG--;
      colorB++;
      lcd.setRGB(colorR, colorG, colorB);
      delay(50);
    }
    
  }
    
}

/* ********************************************************************************************************
  End Of File
******************************************************************************************************** */
