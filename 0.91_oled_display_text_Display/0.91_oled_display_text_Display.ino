#include <Arduino.h>

#include <U8g2lib.h>

#include <SPI.h>

#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

void setup(void) {

u8g2.begin();

}

void loop(void) {


u8g2.clearBuffer();

u8g2.setFont(u8g_font_unifont);

u8g2.drawStr(0,11,"Happy 78th");
u8g2.drawStr(0,26,"Independence Day");


u8g2.sendBuffer();


u8g2.clearBuffer();




}