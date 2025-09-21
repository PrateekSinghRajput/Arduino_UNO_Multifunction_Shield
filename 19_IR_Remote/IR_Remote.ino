#include <IRremote.h>

#define IR_RECEIVE_PIN 6
#define LED_PIN 9

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.print("IR Command: ");
    Serial.println(command);

    if (command == 1) {
      digitalWrite(LED_PIN, HIGH);
    } else if (command == 5) {
      digitalWrite(LED_PIN, LOW);
    }
    IrReceiver.resume();
  }
}
