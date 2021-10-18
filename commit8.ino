const char button1 = 8;
const char button2 = 7;
bool pressed = false;
int hours = 0;
int mins = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

}

void loop() {
  // Read button
  bool currentState = digitalRead(button1);
  bool currentState2 = digitalRead(button2);

  Serial.print("\nTime is: ");

  if(currentState == pressed){
    hours++;
    /*Serial.println("Pin 8 used!");
    delay(500);*/
  }

  if(currentState2 == pressed){
    mins++;
    /*Serial.println("Pin 7 used!");
    delay(500);*/
  }

  if(hours < 10){
    Serial.print('0');
    Serial.print(hours);
    
  }else{

    Serial.print(hours);
    
  }

  Serial.print(':');

  if(mins < 10){
    Serial.print('0');
    Serial.print(mins);
    
  }else{

    Serial.print(mins);
    
  }

  delay(1000);

}
