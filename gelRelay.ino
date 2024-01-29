#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include "MQTTConnect.h"

const int relayPin = 2;
const char* WIFI_NAME = "Stevens-IoT";
const char* WIFI_PASS = "nMN882cmg7";

const char* mqtt_server = "98db5050a791439c98eac188febfecbe.s2.eu.hivemq.cloud";  //MQTT Broker(Server) Address
const char* MQusername = "stevens";         //MQTT username
const char* MQpassword = "Stevens@1870";    //MQTT password
const char* MQtopic = "gelBlaster";         //MQTT Topic (Arena I/II)
const int mqtt_port = 8883;                 //MQTT TCP/IP port number

void setup() {
  Serial.begin(115200);
  Serial.println("Test");
  pinMode(relayPin, OUTPUT);
  wifi_start();
  mqtt_start();
}

void loop() {
  if(!client.connected()){
    reconnect();
    }
    client.loop();
}
