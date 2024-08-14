
#include "U8glib.h"   // Library for OlED display https://github.com/olikraus/u8glib/
#include "dht.h"      // DHT sensors library https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTstable

#define DHT11PIN 4  

U8GLIB_SSD1306_128X32 u8gDHT(U8G_I2C_OPT_FAST);  

dht DHT11;  

void setup() {

  pinMode(DHT11PIN, INPUT_PULLUP);
  u8gDHT.setFont(u8g_font_unifont);

}

void loop() {
  int DHT11Check = DHT11.read11(DHT11PIN);  
 
  if (DHT11Check == 0)  { 
  
    u8gDHT.firstPage(); 
      do {
          u8gDHT.drawStr( 0, 20, "DTH11:");
          u8gDHT.setPrintPos(55, 20);
          u8gDHT.print(DHT11.temperature, 0);  
              u8gDHT.drawStr(72,18, "o");
              u8gDHT.drawStr(80,20, "C");
             
          u8gDHT.drawStr( 88, 20, "|");
          u8gDHT.setPrintPos(100, 20);
          u8gDHT.print(DHT11.humidity, 0);  
           u8gDHT.drawStr(118,20, "%");
      
        } while( u8gDHT.nextPage() );

     delay(2000); 
  }
}