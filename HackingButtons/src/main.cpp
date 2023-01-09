#include <Arduino.h>

const int optoPin = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(optoPin, OUTPUT);
}

void loop()
{
  Serial.println("We're loading the wrong thing");
  digitalWrite(optoPin, HIGH);
  delay(15);
  digitalWrite(optoPin, LOW);
  delay(21000);
}