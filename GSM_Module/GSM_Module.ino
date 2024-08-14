const int Input1 = 2;
int State1 = 0;

void setup() {
  Serial.begin(115200);
  pinMode(Input1, INPUT_PULLUP);
}

void loop() {
  State1 = digitalRead(Input1);

  if (State1 == LOW) {
    sendsms();
    delay(2000);
  }
}

void sendsms() {
  Serial.println("AT\r");
  delay(1000);
  Serial.println("AT+CMGF=1\r");
  delay(1000);
  Serial.println("AT+CMGS=\"+918830584864\"\r");
  delay(1000);
  Serial.println("Hi I Am From JustDoElectronics");
  delay(1000);
  Serial.println((char)26);
  delay(100);
}