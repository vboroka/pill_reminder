#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

LiquidCrystal_I2C lcd(0x27,20,4);
RTC_DS3231 rtc;

void setup()
{
  lcd.init();
  
}


void loop()
{
  lcd.init();
  DateTime now = rtc.now();

  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Ido");
  lcd.setCursor(1,1);
  
   if(now.hour() < 10){
      lcd.print('0');
      lcd.print(now.hour(), DEC);
      
    
    }else{
      lcd.print(now.hour(), DEC);
      
    }
    lcd.print(':');

    if(now.minute() < 10){
      lcd.print('0');
      lcd.print(now.minute(), DEC);
      
    }else{
        lcd.print(now.minute(), DEC);
        
    }

    lcd.setCursor(9,0);
    lcd.print("Jelzes");

    lcd.setCursor(10,1);
    lcd.print("00:00");

    delay(1000);
}
