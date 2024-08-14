#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int LED = 13;
int LED1 = 12;
int BUZZER = 5;
int analog_IN = A3;

void setup() {

  lcd.init();
  lcd.backlight();
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(analog_IN, INPUT);
  Serial.begin(9600);
}

void loop() {

  int Value = analogRead(analog_IN);
  Serial.print("Analog read: ");
  Serial.println(Value);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas Analog Read:");
  lcd.setCursor(6, 1);
  lcd.print(Value);

  if (Value < 300) {
    digitalWrite(LED, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(BUZZER, LOW);
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(BUZZER, HIGH);
  }
  delay(1000);
}