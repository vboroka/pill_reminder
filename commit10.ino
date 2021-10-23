#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int PulseWire = 0;
int Threshold = 550;
 
PulseSensorPlayground pulseSensor;

void setup() {
 
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
 
  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);
 
  if (pulseSensor.begin()) {
    Serial.println("PulseSensor objektum létrehozva!"); 
  }

  pinMode(9, INPUT);
  digitalWrite(9, HIGH);
}
 
void loop() {
 
int myBPM = pulseSensor.getBeatsPerMinute();

while(digitalRead(9) == LOW){
    if (pulseSensor.sawStartOfBeat()) {
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Pulzus: ");
      lcd.print(myBPM);

    }
    
    delay(20);

  }

}
