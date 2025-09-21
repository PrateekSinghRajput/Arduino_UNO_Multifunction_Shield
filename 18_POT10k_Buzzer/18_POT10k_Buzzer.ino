
#define POTENTIOMETER_PIN A0
#define BUZZER 5

void setup() {

  pinMode(POTENTIOMETER_PIN, INPUT);

  pinMode(BUZZER, OUTPUT);
}

void loop() {

  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int frequency = map(potentiometerValue, 0, 1023, 100, 1000);
  tone(BUZZER, frequency);

  delay(100);
}
