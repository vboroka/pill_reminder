// Elso commit: LCD kijelzore valo kiiratasi proba
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
#include <stdio.h>
#include <ctype.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  //I2C modul eleresi cimenek beallitasa

void setup() {
  
  lcd.init();
  lcd.backlight();

}

void loop() {
  lcd.setCursor(2,0);
  lcd.print("Hello world!");

  lcd.setCursor(2,1);
  lcd.print("It's Juni!");

}
