#define POT_PIN A0
const int threshold = 512;
bool smsSent = false;

void setup() {
  Serial.begin(9600);
  delay(2000);

  Serial.println("System Ready");
  Serial.println("AT");
  delay(1000);
  Serial.println("AT+CMGF=1");
  delay(1000);
}

void loop() {
  int potValue = analogRead(POT_PIN);
  Serial.print("Pot value: ");
  Serial.println(potValue);

  if (potValue > threshold && !smsSent) {
    sendSMS("+918830584864", "Pot crossed 50 percent threshold!");
    smsSent = true;
    Serial.println("SMS Sent!");
  }

  if (potValue < threshold - 10) {
    smsSent = false;
  }

  delay(500);
}

void sendSMS(const char* number, const char* message) {
  Serial.print("AT+CMGS=\"");
  Serial.print(number);
  Serial.println("\"");
  delay(500);
  Serial.println(message);
  delay(500);
  Serial.write(26);
  delay(2000);
}
