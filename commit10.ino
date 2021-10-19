#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>  

const int PulseWire = 0;
int Threshold = 550;
const char button1 = 5;
const char button2 = 6;
const char button3 = 7;
bool pressed = false;
int hours = 0;
int mins = 0;

PulseSensorPlayground pulseSensor;


void setup() {   

  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);   

   if (pulseSensor.begin()) {
    Serial.println("PulseSensor objektum létrehozva!");
  }
}



void loop() {

 int myBPM = pulseSensor.getBeatsPerMinute();
 
 bool currentState = digitalRead(button1);
 bool currentState2 = digitalRead(button2);
 bool currentState3 = digitalRead(button3);

 if(currentState3 == pressed && pulseSensor.sawStartOfBeat()){
    
    Serial.print("BPM érzékelve: ");
    Serial.println(myBPM);
  
 }

  delay(20);

} 
