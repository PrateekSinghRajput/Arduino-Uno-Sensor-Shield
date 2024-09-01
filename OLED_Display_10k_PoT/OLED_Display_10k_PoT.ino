
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;
int counter = 0;
unsigned long int currentTime, nextTime;

void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
    pinMode(ledPin, OUTPUT);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("SSD1306 Display");
  display.setCursor(80, 34);
  display.println("10K PoT");
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(80, 12);
  display.println("JDE");
  counter = 0;
  align3(counter);
  display.drawRect(0, 10, 70, 35, SSD1306_WHITE);
  nextTime = millis() + 1000;
  //display.println(counter);
  display.display();
}
int align2(int q) {
  if (q < 100) { display.print(" "); }
  if (q < 10) { display.print(" "); }
}
int align3(int q) {
  if (q < 1000) { display.print(" "); }
  align2(q);
}

void loop() {

  sensorValue = analogRead(sensorPin);
  int perCent = float(sensorValue * 100.0 / 1018);
  display.drawLine(0, 47, 0, 62, SSD1306_WHITE);
  display.fillRect(1, 50, perCent, 10, SSD1306_WHITE);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(102, 50);
  align2(perCent);
  display.print(perCent);
  display.println("%");
  display.fillRect(1, 11, 68, 33, SSD1306_BLACK);
  display.setCursor(10, 20);
  display.setTextSize(2);
  align3(sensorValue);
  display.println(sensorValue);
  display.setTextSize(1);
  display.display();
  delay(100);
  display.fillRect(1, 50, perCent, 10, SSD1306_BLACK);
  display.setTextColor(SSD1306_BLACK);
  display.setCursor(102, 50);
  align2(perCent);
  display.print(perCent);
  display.println("%");
}
