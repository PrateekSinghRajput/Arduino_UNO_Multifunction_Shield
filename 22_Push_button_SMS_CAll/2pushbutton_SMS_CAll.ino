#define BUTTON_SMS 2
#define BUTTON_CALL 3

void setup() {
  pinMode(BUTTON_SMS, INPUT_PULLUP);
  pinMode(BUTTON_CALL, INPUT_PULLUP);
  Serial.begin(9600);
  delay(2000);

  Serial.println("System Ready");
  Serial.println("AT");
  delay(1000);
  Serial.println("AT+CMGF=1");
  delay(1000);
}

void loop() {
  if (digitalRead(BUTTON_SMS) == LOW) {
    sendSMS("+918830584864", "Button Pressed: Sending SMS!");
    delay(2000);
  }

  if (digitalRead(BUTTON_CALL) == LOW) {
    makeCall("+918830584864");
    delay(2000);
  }
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

void makeCall(const char* number) {
  Serial.print("ATD");
  Serial.print(number);
  Serial.println(";");
  delay(10000);
  Serial.println("ATH");
  delay(1000);
}
