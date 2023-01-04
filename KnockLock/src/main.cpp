#include <Arduino.h>
#include <Servo.h>

Servo myServo;
const int piezo = A0;
const int pinSwitch = 2;
const int yellowLED = 3;
const int grnLED = 4;
const int redLED = 5;
const int quietKnock = 10;
const int loudKnock = 100;
int knockVal;
int valSwitch;
int knockNum = 0;
boolean locked = false;

void setup()
{
  Serial.begin(9600);
  myServo.attach(9);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(grnLED, OUTPUT);
  pinMode(pinSwitch, INPUT);
  digitalWrite(grnLED, HIGH);
  myServo.write(0);
  Serial.println("The Box is Unlocked!");
}

void loop()
{
  if (!locked)
  {
    valSwitch = digitalRead(pinSwitch);
    if (valSwitch == HIGH)
    {
      locked = true;
      digitalWrite(grnLED, LOW);
      digitalWrite(redLED, HIGH);
      myServo.write(90);
      Serial.println("The Box is LOCKED!!");
      delay(1000);
    }
  }

  if (locked)
  {
    knockVal = analogRead(piezo);
    if (knockNum < 3 && knockVal > 0)
    {
      if (checkForKnock(knockVal))
      {
        knockNum++;
      }
      Serial.print(3 - knockNum);
      Serial.println(" more knocks to go!");
    }
    if (knockNum >= 3)
    {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(grnLED, HIGH);
      digitalWrite(redLED, LOW);
      Serial.println("The Box is Unlocked!");
      knockNum = 0;
    }
  }
}

boolean checkForKnock(int val)
{
  if (val > quietKnock && val < loudKnock)
  {
    digitalWrite(yellowLED, HIGH);
    delay(50);
    digitalWrite(yellowLED, LOW);
    Serial.print("Valid knock of value ");
    Serial.print(val);
    return true;
  }
  else
  {
    Serial.print("Bad knock Value: ");
    Serial.print(val);
    return false;
  }
}