/*
Modulo de temperatura e humidade
VCC - 5v
GND
S - Digital PWM 2
*/

#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup(){

  Serial.begin(9600);

  Serial.println("DHT11 Output!");

  dht.begin();

}

void loop(){

  float h = dht.readHumidity();

  float t = dht.readTemperature();

  if(isnan(t) || isnan(h)){

    Serial.println("Failed to read DHT11");

  }else{

    Serial.print("Humidity: ");

    Serial.print(h);

    Serial.print(" %\t");

    Serial.print("Temperature: ");

    Serial.print(t);

    Serial.println(" *C");

  }

}
