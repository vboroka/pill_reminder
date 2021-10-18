#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

void setup () {
  
  Serial.begin(9600);
  delay(3000);

  if(! rtc.begin()){
    Serial.println("Couldn't find RTC");
    while(1);
    
  }

  if(rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop(){
    DateTime now = rtc.now();
    
    if(now.hour() < 10){
      Serial.print('0');
      Serial.print(now.hour(), DEC);
      
    
    }else{
      Serial.print(now.hour(), DEC);
      
    }
    Serial.print(':');

    if(now.minute() < 10){
      Serial.print('0');
      Serial.print(now.minute(), DEC);
      
    }else{
        Serial.print(now.minute(), DEC);
        
    }
    
    Serial.print(':');

    if(now.second() < 10){
      Serial.print('0');
      Serial.print(now.second(), DEC);
      
    }else{
      Serial.print(now.second(), DEC);
      
    }
    
    Serial.println();
    delay(1000);
}
