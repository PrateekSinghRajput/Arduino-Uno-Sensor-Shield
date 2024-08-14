#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <dht.h> 

#define sensor A3
#define DHT11PIN 4

int gasLevel = 0;
String quality = "";
dht DHT;

void sendSensor() {
  int readData = DHT.read11(DHT11PIN);
  float h = DHT.humidity;
  float t = DHT.temperature;

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed  to read from DHT sensor!");
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(8, 0);
  lcd.print("H:");
  lcd.print(h);
  lcd.print("%");
  
}

void air_sensor() {
  gasLevel = analogRead(sensor);

  if (gasLevel < 151) {
    quality = "  GOOD!";
  } else if (gasLevel > 151 && gasLevel < 200) {
    quality = "  Poor!";
  } else if (gasLevel > 200 && gasLevel < 300) {
    quality = "  .Bad!";
  } else if (gasLevel > 300 && gasLevel < 500) {
    quality = "  Toxic";
  } else {
    quality = "  Toxic";
  }

  lcd.setCursor(0, 1);
  lcd.print("Air:");
  lcd.print(gasLevel);
  lcd.setCursor(8, 1);
  lcd.print(quality);
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(sensor, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("INITIALISING");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.clear();
}

void loop() {

  air_sensor();
  sendSensor();
  delay(1000);
}