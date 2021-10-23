#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <stdio.h>
#include <ctype.h>

//I2C modul eleresi cimenek beallitasa (objektum létrehozásával), ill. RTC DS3231 objektum létrehozása
LiquidCrystal_I2C lcd(0x27, 20, 4);
RTC_DS3231 rtc;

//valtozok deklaralasa
int ahours = 0;
int amins = 0;


void setup()
{
  lcd.init();
  lcd.backlight();        // LCD hattervilagitas bekapcsolasa
  lcd.clear();            // LCD kijelzo "megtisztitasa"
  lcd.print("00:00");
  lcd.setCursor(10, 0);
  lcd.print("00:00");
  lcd.setCursor(0, 1);
  lcd.print("Ido");
  lcd.setCursor(10, 1);
  lcd.print("Jelzes");

  pinMode(5, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(3, OUTPUT);

  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(3, LOW);

}

void loop()
{

  DateTime now = rtc.now();

  //Jelzest beallito kod
  while (digitalRead(5) == LOW)
  {
    lcd.setCursor(10, 1);
    lcd.print("Jelzes");
    lcd.setCursor(10, 0);
    if (digitalRead(6) == LOW)
    {
      ahours++;
    }
    else if (digitalRead(7) == LOW)
    {
      amins++;
    }
    lcd.setCursor(10, 0);

    //Kodresz, mely a 00:00-s idoformatumot beallitja
    if (ahours < 10)
    {
      lcd.print("0");
      lcd.print(ahours);
    }
    else
    {
      lcd.print(ahours);
    }

    lcd.print(":");

    if (amins < 10)
    {
      lcd.print("0");
      lcd.print(amins);
    }
    else
    {
      lcd.print(amins);
    }

    //24 oras idoformatum validalasa
    if (amins > 59)
    {
      ahours++;
      amins = 0;
    }
    if (ahours > 23)
    {
      ahours = 0;
    }
    delay(500);

  }
  
  //Aktualis ido beallitasa
  lcd.setCursor(0, 1);
  lcd.print("Ido");
  lcd.setCursor(0, 0);
  if (now.hour() < 10) {
    lcd.print('0');
    lcd.print(now.hour(), DEC);


  } else {
    lcd.print(now.hour(), DEC);

  }
  lcd.print(':');

  if (now.minute() < 10) {
    lcd.print('0');
    lcd.print(now.minute(), DEC);

  } else {
    lcd.print(now.minute(), DEC);

  }

  //ha aktualis ido es jelzes ideje egyezik
  if (ahours == now.hour() && amins == now.minute() && amins != 0)
  {

    for (int i = 0; i < 1; i++) {

      tone(3, 500);
      delay(500);

      noTone(3);
      delay(200);


    }

  }

}
