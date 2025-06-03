#include <SPI.h>
#include <LoRa.h>

#define SS 18
#define RST 14
#define DIO0 26

void setup() {
  Serial.begin(9600);

  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Receiver failed");
    while (1);
  }

  Serial.println("LoRa Receiver Ready");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String incoming = "";
    while (LoRa.available()) {
      incoming += (char)LoRa.read();
    }
    Serial.println("Received: " + incoming);
  }
}
