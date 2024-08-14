const int BUTTON_PIN = 2;
const int RELAY_PIN = 8;

int relayState = LOW;
int lastButtonState;
int currentButtonState;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);

  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    if (relayState == LOW)
      relayState = HIGH;
    else
      relayState = LOW;

    digitalWrite(RELAY_PIN, relayState);
  }
}