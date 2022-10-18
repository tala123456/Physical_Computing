
#include <WiFiNINA.h>
#include <MQTT.h>
#include "wifiCredentials.h"

#define pot_pin A0
const char ssid[] = WIFI_SSID;
const char pass[] = WIFI_PASS;
unsigned long lastMillis = 0;
int ledBlink; 

WiFiClient net;
MQTTClient client;
int status = WL_IDLE_STATUS;  
int ledPin = 11;
int readValue = 0;
int ledValue = 0;

void setup() {

  pinMode(pot_pin, INPUT);
  Serial.begin(115200);
  // attempt to connect to Wifi network:
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print("No WiFi connection");
    delay(5000);
  }
  
  // once you are connected :
  Serial.println("You're connected to the network");

  //start mqtt
  client.begin("tanja.cloud.shiftr.io", net);
  connect();
}

void loop() {



  // check if connected
  if (!client.connected()) {
    connect();
  }

readValue = analogRead(A0);
ledValue = map(readValue, 0, 1023, 0, 255);

  client.loop();
  delay(10);

  // publish a message roughly every second.
  if (millis() - lastMillis > 100) {
   client.publish("/ledBlink", String(ledValue));
  } 
   
  }




void connect() {
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("No Wifi connection...");
    delay(1000);
  }

  while (!client.connect("LYV", "tanja", "BZgb5d72yiHeeVop")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected to MQTT!");
  client.subscribe("ledBlink");
}