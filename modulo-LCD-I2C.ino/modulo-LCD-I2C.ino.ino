// Programa : Display LCD 16x2 e modulo I2C
// Autor : Arduino e Cia

/*
GND
VCC - 5V
SDA - A4
SCL - A5

*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x3F
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
 lcd.begin (16,2);
}
 
void loop()
{
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Keiko & Denis");
  lcd.setCursor(0,1);
  lcd.print("<3");
  delay(1000);
  //lcd.setBacklight(LOW);
  delay(1000);
}
