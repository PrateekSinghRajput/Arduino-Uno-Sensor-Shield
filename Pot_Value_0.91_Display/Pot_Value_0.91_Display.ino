#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

char buf [30];
int TRpin = A0;
double vo;

void setup()   {

  pinMode(TRpin, INPUT);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  display.display();

}

void loop() {
  vo = analogRead(TRpin);
  pot();
}

void pot(void) {

  display.setTextSize(3);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 11);
  display.println(vo);
  display.display();
}

