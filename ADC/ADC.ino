int sensorPin = A0;    // input pin for the potentiometer
int digitalValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  digitalValue = analogRead(sensorPin);  // read the value from the analog channel
  Serial.print("digital value = ");
  Serial.println(digitalValue);  //print digital value on serial monitor
  delay(1000);
}



//ADC With Voltage
int sensorPin = A0;    // select the input pin for the potentiometer
int digitalValue = 0;  // variable to store the value coming from the sensor
float analogVoltage = 0.00;

void setup() {
  Serial.begin(9600);
}

void loop() {
  digitalValue = analogRead(sensorPin);  // read the value from the analog channel
  Serial.print("digital value = ");
  Serial.print(digitalValue);  //print digital value on serial monitor
  //convert digital value to analog voltage
  analogVoltage = (digitalValue * 5.00) / 1023.00;
  Serial.print("  analog voltage = ");
  Serial.println(analogVoltage);
  delay(1000);
}