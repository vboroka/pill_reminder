const char button = 8;
bool pressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);

}

void loop() {
  // Read button
  bool currentState = digitalRead(button);

  if(currentState == pressed){
    Serial.println("Boop!");
    delay(500);
  }

}
