
#include <DHT.h>

#define DHTPIN 4

DHT dht(DHTPIN, DHT11);

void setup() {

  Serial.begin(9600);
  dht.begin();
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C");
  Serial.print(" Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000);
}


/*
Output sample:

Temperature: 25.80°C Humidity: 86.00%
Temperature: 25.60°C Humidity: 85.00%
Temperature: 25.50°C Humidity: 85.00%
*/
