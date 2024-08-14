#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = 7;  
int buzzer = 5;     
int G_led = 13;       
int R_led = 12;       

int read_value;  

void setup() {

  pinMode(sensorPin, INPUT);  
  pinMode(buzzer, OUTPUT);  
  pinMode(R_led, OUTPUT);   
  pinMode(G_led, OUTPUT);   
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   WELCOME To   ");
  lcd.setCursor(0, 1);
  lcd.print("  Fire Detector ");
  delay(2000);
  lcd.clear();

}

void loop() {
  read_value = digitalRead(sensorPin);  

  if (read_value == 1) {  
    lcd.setCursor(0, 0);
    lcd.print("   Not  Flame   ");
    lcd.setCursor(0, 1);
    lcd.print(".....Normal.....");
    digitalWrite(buzzer, LOW); 
    digitalWrite(R_led, LOW);   
    digitalWrite(G_led, HIGH);  

  } else {  
    lcd.setCursor(0, 0);
    lcd.print("Fire is Detected");
    lcd.setCursor(0, 1);
    lcd.print("Alert....!!!    ");
    digitalWrite(buzzer, HIGH);  
    digitalWrite(R_led, HIGH);   
    digitalWrite(G_led, LOW);    
    delay(1000);
  }
  delay(100);
}