#include <Arduino.h>
#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(4, 2);
int threshold = 500;
const int ledPin = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  long sensorVal = capSensor.capacitiveSensor(30);
  Serial.println(sensorVal);

  if (sensorVal > threshold)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  delay(10);
}