const char button1 = 8;
const char button2 = 7;
bool pressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

}

void loop() {
  // Read button
  bool currentState = digitalRead(button1);
  bool currentState2 = digitalRead(button2);

  if(currentState == pressed){
    Serial.println("Pin 8 used!");
    delay(500);
  }

  if(currentState2 == pressed){
    Serial.println("Pin 7 used!");
    delay(500);
  }

}
