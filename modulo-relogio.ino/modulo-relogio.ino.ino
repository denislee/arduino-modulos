// Programa : Data e hora com modulo RTC DS1302
// Alteracoes e adaptacoes : Arduino e Cia
//
// Baseado no programa original de Krodal e na biblioteca virtuabotixRTC

/*
VCC - 5V
GND
CLK - Digital PWM 6
DAT - Digital PWM 7
RST - Digital PWM 8
*/


// Carrega a biblioteca virtuabotixRTC
#include <virtuabotixRTC.h>           

// Determina os pinos ligados ao modulo
// myRTC(clock, data, rst)
virtuabotixRTC myRTC(6, 7, 8);

void setup()  
{      
  Serial.begin(9600);
  // Informacoes iniciais de data e hora
  // Apos setar as informacoes, comente a linha abaixo
  // (segundos, minutos, hora, dia da semana, dia do mes, mes, ano)
//  myRTC.setDS1302Time(00, 42, 17, 6, 15, 11, 2017);
}

void loop()  
{
  // Le as informacoes do CI
  myRTC.updateTime(); 

  // Imprime as informacoes no serial monitor
  Serial.print("Data : ");
  // Chama a rotina que imprime o dia da semana
  imprime_dia_da_semana(myRTC.dayofweek);
  Serial.print(", ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print("Hora : ");
  // Adiciona um 0 caso o valor da hora seja <10
  if (myRTC.hours < 10)
  {
    Serial.print("0");
  }
  Serial.print(myRTC.hours);
  Serial.print(":");
  // Adiciona um 0 caso o valor dos minutos seja <10
  if (myRTC.minutes < 10)
  {
    Serial.print("0");
  }
  Serial.print(myRTC.minutes);
  Serial.print(":");
  // Adiciona um 0 caso o valor dos segundos seja <10
  if (myRTC.seconds < 10)
  {
    Serial.print("0");
  }
  Serial.println(myRTC.seconds);

  delay( 1000);
}

void imprime_dia_da_semana(int dia)
{
  switch (dia)
  {
    case 1:
    Serial.print("Domingo");
    break;
    case 2:
    Serial.print("Segunda");
    break;
    case 3:
    Serial.print("Terca");
    break;
    case 4:
    Serial.print("Quarta");
    break;
    case 5:
    Serial.print("Quinta");
    break;
    case 6:
    Serial.print("Sexta");
    break;
    case 7:
    Serial.print("Sabado");
    break;
  }
}
