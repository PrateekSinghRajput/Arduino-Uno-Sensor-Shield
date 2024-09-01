
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define SENSOR_PIN 4

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
OneWire oneWire(SENSOR_PIN);
DallasTemperature tempSensor(&oneWire);

String tempString;

void setup() {
  Serial.begin(9600);
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true)
      ;
  }
  delay(2000);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 10);
  tempSensor.begin();
  tempString.reserve(10);
}

void loop() {
  tempSensor.requestTemperatures();
  float tempCelsius = tempSensor.getTempCByIndex(0);
  tempString = String(tempCelsius, 2);
  tempString += char(247) + String("C");
  Serial.print("Tempature Sensor:- ");
  Serial.println(tempString);
  oledDisplayCenter(tempString);
  delay(400);
}

void oledDisplayCenter(String text) {
  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;

  oled.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);
  oled.clearDisplay();
  oled.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
  oled.println(text);
  oled.display();
}
