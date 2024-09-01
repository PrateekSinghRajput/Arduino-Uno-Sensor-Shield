char t;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == 'F') {
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
  }

  else if (t == 'B') {
    digitalWrite(11, HIGH);
    digitalWrite(9, HIGH);
  }

  else if (t == 'L') {
    digitalWrite(10, HIGH);
  }

  else if (t == 'R') {
    digitalWrite(12, HIGH);
  }

  else if (t == 'W') {
    digitalWrite(8, HIGH);
  } else if (t == 'w') {
    digitalWrite(8, LOW);
  }

  else if (t == 'S') {
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  }
  delay(100);
}