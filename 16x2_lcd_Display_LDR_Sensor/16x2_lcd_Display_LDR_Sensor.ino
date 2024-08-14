
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {  
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
}
void loop() {
  int sensorValue = analogRead(A1);
  double dV = sensorValue;
  double le = (dV / 1023) * 100;
  int level = le;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LIGHT LEVEL:");
  lcd.print(level);
  lcd.print("%");
  lcd.setCursor(0, 1);

  if ((level >= 0) && (level <= 5)) {
    lcd.print("VERY DARK");
  } else if ((level > 5) && (level <= 10)) {
    lcd.print("DARK");
  } else if ((level > 10) && (level <= 50)) {
    lcd.print("BRIGHT");
  } else {
    lcd.print("VERY BRIGHT");
  }

  delay(500);
}