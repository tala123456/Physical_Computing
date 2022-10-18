
#include <WiFiNINA.h>
#include <MQTT.h>
#include "wifiCredentials.h"

const char ssid[] = WIFI_SSID;
const char pass[] = WIFI_PASS;
int xPos = 100;
int yPos = 100;
int readValue = 0;
int ledValue = 0;
int diameter = 0;
int prevLed= 0;


WiFiClient net;
MQTTClient client;
int status = WL_IDLE_STATUS;

unsigned long lastMillis = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  // attempt to connect to Wifi network:
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print("No WiFi connection");
    delay(5000);
  }

  // once you are connected :
  Serial.println("You're connected to the network");

  //start mqtt
  //change this to match your instance name
  client.begin("tanja.cloud.shiftr.io", net);
  client.onMessage(messageReceived);
  connect();
}

void loop() {
  client.loop();
  delay(10);

  readValue = analogRead(A0);
  ledValue = map(readValue, 0, 1023, 0, 255); //can only go to 1023
  //analogWrite(A0, ledValue);

  // check if connected
  if (!client.connected()) {
    connect();
  }
  if(ledValue != prevLed) {
   client.publish("/diameter", "diameter," + String(ledValue)); // 
  } 
  prevLed = ledValue;
  
  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();

    //make sure you add comma after the string e.x. posX,
    client.publish("/posX", "posX," + String(xPos)); // "posX, 250"
    client.publish("/posY", "posY," + String(yPos)); // "posY, 125"
      // add client publis as well and put in diaSize to change the size of the circle


    //you can also send the message formatted as json
    //client.publish("/pos", "{\"x\":" + String(xPos)+ ",\"y\":" + String(yPos) + "}"); //pos.x and pos.y

    if (xPos < 500) {
      xPos += 10;
      yPos += 5;
    } else {
      xPos = 100;
      yPos = 100;
    }
  }
}

void messageReceived(String &topic, String &payload) {
  Serial.println(topic + ": " + payload);
  int blinkVal = constrain(payload.toInt(), 0, 1);
  digitalWrite(LED_BUILTIN, blinkVal);

}

void connect() {
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("No Wifi connection...");
    delay(1000);
  }

  //change this to match your instance
  while (!client.connect("arduino", "tanja", "BZgb5d72yiHeeVop")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected to MQTT!");
  client.subscribe("ledBlink");
}
