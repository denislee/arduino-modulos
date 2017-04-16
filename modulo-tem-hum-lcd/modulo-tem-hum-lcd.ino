/*
Modulo de temperatura e humidade
VCC - 5v
GND
S - Digital PWM 2
*/

/*
 modulo lcd
GND
VCC - 5V
SDA - A4
SCL - A5

*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x3F
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
 
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int inPin = 7;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status
int light = 0;

void setup(){

  dht.begin();
  lcd.begin (16,2);
  pinMode(inPin, INPUT);    // declare pushbutton as input
  lcd.setBacklight(HIGH);

}

void loop(){

  val = digitalRead(inPin);  // read input value
  if (val == LOW) {         // check if the input is HIGH (button released)
    if (light == 0) {
      light = 1;
      lcd.setBacklight(HIGH);
    } else {
      light = 0;
      lcd.setBacklight(LOW);
    } 
    delay(300);
  } 

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) {
    lcd.setCursor(0,0);
    lcd.print("Failed to read DHT11");
    
  } else {
    
    lcd.setCursor(0,0);
    lcd.print("H: ");
    lcd.setCursor(3,0);
    lcd.print(h);
    lcd.setCursor(9,0);
    lcd.print("%");

    lcd.setCursor(0,1);
    lcd.print("T: ");
    lcd.setCursor(3,1);
    lcd.print(t);
    lcd.setCursor(9,1);
    lcd.print("C");
  }

}                
