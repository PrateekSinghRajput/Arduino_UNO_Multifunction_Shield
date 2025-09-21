#define LDR_PIN A1
#define LED_PIN 10

int ldrValue;
int threshold = 500;

void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(LDR_PIN);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue < threshold) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON - It's dark!");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF - It's bright!");
  }

  delay(500);
}
