/*
LICENSE MIT
BY : KILLIAN PEREZ
DATE: 2019, December 17th
DESCRIPTION:
   Display temperature from LM35DZ sensor as metric system
*/

/* Import of libs */
#include <Wire.h>
#include "rgb_lcd.h"

/* Call LCD because I use LCD screen size: 16x2 */
rgb_lcd lcd;

/* Color of display (lcd) */
const int colorR = 245;
const int colorG = 122;
const int colorB = 220;

float ND;
float AffD;
float NR;
float AffR;


void setup()
{
  /* set up the LCD's number of columns and rows then set color of background: */
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.clear();
  Wire.begin();
}


/* Use loop section of Arduino to display periodically temperature, previously converted as metric system */
void loop() 
{
  ND=analogRead(A0);
  AffD=ND*(5.0/1023*100);
  lcd.setCursor(0,0);
  lcd.print("C depart");
  lcd.setCursor(9,0);
  lcd.print(AffD);
  lcd.setCursor(14,0);
  lcd.print("C");
  delay(500);
}
