#define led1 12
#define led2 13

const int AirValue = 620;
const int WaterValue = 310;
int soilMoistureValue = 0;
int soilmoisturepercent = 0;

void setup() {

  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {

  soilMoistureValue = analogRead(A3);
  Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if (soilmoisturepercent >= 100) {
    Serial.println("100 %");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else if (soilmoisturepercent <= 40) {
    Serial.println("0 %");
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  } else if (soilmoisturepercent > 0 && soilmoisturepercent < 100) {
    Serial.print(soilmoisturepercent);
    Serial.println("%");
  }
  delay(1000);
}
