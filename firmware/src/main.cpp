#pragma once

#include "secrets.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <DHT.h>

constexpr char *AWS_IOT_PUBLISH_TOPIC = "esp32/pub";
constexpr char *AWS_IOT_SUBSCRIBE_TOPIC = "esp32/sub";
constexpr uint8_t DHT_PIN = 14;
constexpr uint8_t DHT_TYPE = DHT11;
constexpr uint8_t LED_PIN = 2;

float hum;
float temp;

DHT dht(DHT_PIN, DHT_TYPE);

WiFiClientSecure net = WiFiClientSecure();

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();
}

void loop()
{
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  if (isnan(hum) || isnan(temp))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(hum);
  Serial.print(F("%  Temperature: "));
  Serial.print(temp);
  Serial.println(F("°C "));

  delay(1000);
}