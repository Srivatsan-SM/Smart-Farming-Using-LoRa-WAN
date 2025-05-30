#include <SPI.h>
#include <LoRa.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SOIL_PIN 36
#define NITROGEN_PIN 39

#define SS 18
#define RST 14
#define DIO0 26

void setup() {
  Serial.begin(9600);

  dht.begin();
  pinMode(SOIL_PIN, INPUT);
  pinMode(NITROGEN_PIN, INPUT);

  // LoRa setup
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed");
    while (1);
  }
  Serial.println("LoRa Sender Ready");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int soil = analogRead(SOIL_PIN);
  int nitrogen = analogRead(NITROGEN_PIN);

  // Optional: Map raw values if needed
  String payload = "Temp:" + String(temperature) +
                   " Hum:" + String(humidity) +
                   " Soil:" + String(soil) +
                   " Nitrogen:" + String(nitrogen);

  LoRa.beginPacket();
  LoRa.print(payload);
  LoRa.endPacket();

  Serial.println("Sent: " + payload);
  delay(5000);
}
