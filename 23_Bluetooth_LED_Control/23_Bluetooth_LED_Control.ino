void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  Serial.println("Bluetooth on hardware Serial started");
}

void loop() {
  if (Serial.available()) {
    char val = Serial.read();
    if (val == '1') {
      digitalWrite(2, HIGH);
      Serial.println("Pin 2 HIGH");
    } else if (val == '0') {
      digitalWrite(2, LOW);
      Serial.println("Pin 2 LOW");
    }
  }
}
