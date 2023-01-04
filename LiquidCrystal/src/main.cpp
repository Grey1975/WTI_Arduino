#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

// Global Vars
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup()
{ 
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}

void loop()
{
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState)
  {
    if (switchState == LOW)
    {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The Ball Says: ");
      lcd.setCursor(0, 1);
      switch (reply)
      {
      case 0:
        lcd.print("YES");
        break;
      case 1:
        lcd.print("MOST LIKELY");
        break;
      case 2:
        lcd.print("CERTAINLY");
        break;
      case 3:
        lcd.print("OUTLOOK GOOD");
        break;
      case 4:
        lcd.print("UNSURE");
        break;
      case 5:
        lcd.print("ASK AGAIN");
        break;
      case 6:
        lcd.print("DOUBTFUL");
        break;
      case 7:
        lcd.print("NO");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}