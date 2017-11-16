// Programa : Data e hora com modulo RTC DS1302
// Alteracoes e adaptacoes : Arduino e Cia
//
// Baseado no programa original de Krodal e na biblioteca virtuabotixRTC

/*
 RELOGIO
 -------
 VCC - 5V
 GND
 CLK - Digital PWM 6
 DAT - Digital PWM 7
 RST - Digital PWM 8

 LCD
 ---
 GND
 VCC - 5V
 SDA - A4
 SCL - A5

*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h>           

virtuabotixRTC myRTC(6, 7, 8);
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

void setup()  
{      
  Serial.begin(9600);
  lcd.begin (16,2);
  lcd.setBacklight(HIGH);
  
// (segundos, minutos, hora, dia da semana, dia do mes, mes, ano)
//  myRTC.setDS1302Time(00, 42, 17, 6, 15, 11, 2017);
}

void loop()  
{
  // Le as informacoes do CI
  myRTC.updateTime(); 
  
  lcd.setCursor(0,0);
  data();
  lcd.setCursor(0,1);
  hora();

  delay(1000);
}

void semana(int dia)
{
  switch (dia)
  {
    case 1:
    lcd.print("Dom");
    break;
    case 2:
    lcd.print("Seg");
    break;
    case 3:
    lcd.print("Ter");
    break;
    case 4:
    lcd.print("Qua");
    break;
    case 5:
    lcd.print("Qui");
    break;
    case 6:
    lcd.print("Sex");
    break;
    case 7:
    lcd.print("Sab");
    break;
  }
}

void data()
{
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
  lcd.print(" ");
  semana(myRTC.dayofweek);
  lcd.print(".");
}

void hora()
{
  if (myRTC.hours < 10)
  {
    lcd.print("0");
  }
  lcd.print(myRTC.hours);
  lcd.print(":");
  if (myRTC.minutes < 10)
  {
    lcd.print("0");
  }
  lcd.print(myRTC.minutes);
  lcd.print(":");
  if (myRTC.seconds < 10)
  {
    lcd.print("0");
  }
  lcd.print(myRTC.seconds);
}

