int sensorPin = A0;    
int digitalValue = 0;  

void setup() {
  Serial.begin(9600);
}

void loop() {
  digitalValue = analogRead(sensorPin);
  Serial.print("digital value = ");
  Serial.println(digitalValue);
  delay(1000);
}

// ADC With Voltage
int sensorPin = A0;    
int digitalValue = 0;  
float analogVoltage = 0.00;

void setup() {
  Serial.begin(9600);
}

void loop() {
  digitalValue = analogRead(sensorPin);
  Serial.print("digital value = ");
  Serial.print(digitalValue);
  analogVoltage = (digitalValue * 5.00) / 1023.00;
  Serial.print("  analog voltage = ");
  Serial.println(analogVoltage);
  delay(1000);
}
