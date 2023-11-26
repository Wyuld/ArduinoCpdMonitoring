#include <ArduinoJson.h>
#include <DHT11.h>
DHT11 dht11(2);

int sensor = A0;
int reading;

void setup() {

  Serial.begin(9600);

}

void loop() {
  int humidity = dht11.readHumidity();
  int temperature = dht11.readTemperature();
  int mq2 = analogRead(sensor);

  StaticJsonDocument<200> doc;
  doc["temperature"] = temperature;
  doc["humidity"] = humidity;
  doc["mq2"] = mq2;

  serializeJsonPretty(doc, Serial);
  delay(10000);  

}
