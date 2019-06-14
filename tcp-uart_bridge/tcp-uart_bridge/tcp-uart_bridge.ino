// Prototype took from RoboRemo example

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

//#define DEBUG
#define UART_BAUD 115200
#define bufferSize 40
#define limitSingleRead bufferSize // maximum frame size, that will be sended if data available

// AP settings
const char *ssid = "STAG-AP";  // You will connect your phone to this Access Point
const char *pw = "stagappass"; // and this is the password

// Socket settings
IPAddress ip(192, 168, 0, 1); // From RoboRemo app, connect to this IP
IPAddress netmask(255, 255, 255, 0);
const int port = 9876; // and this port
WiFiServer server(port);
WiFiClient client;


void setup() {

  delay(1000);

  Serial.begin(UART_BAUD);

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip, ip, netmask); // configure ip address for softAP
  WiFi.softAP(ssid, pw); // configure ssid and password for softAP

#ifdef DEBUG
  Serial.println("Starting TCP Server");
#endif

  server.begin(); // start TCP server
}


void loop() {
  static uint8_t bufWifiToUart[bufferSize];
  static uint8_t bufUartToWifi[bufferSize];

  do {
#ifdef DEBUG
    Serial.println("Waiting for TCP client...");
#endif
    delay(500);
    client = server.available();
  } while (!client.connected());

#ifdef DEBUG
  Serial.println("TCP client connected.");
#endif

  uint8_t counterWtU = 0;
  uint8_t counterUtW = 0;

  while (client.connected()) {
    
    //Socket --> UART
    while (client.available() && counterWtU != limitSingleRead) {
      bufWifiToUart[counterWtU] = (uint8_t)client.read();
      counterWtU++;
    }
    Serial.write(bufWifiToUart, counterWtU);
    counterWtU = 0;
    //

    //UART --> Socket
    while (Serial.available() && counterUtW != limitSingleRead) {
      bufUartToWifi[counterUtW] = (char)Serial.read();
      counterUtW++;
    }
    client.write(bufUartToWifi, counterUtW);
    counterUtW = 0;
    //
  }

#ifdef DEBUG
  Serial.println("Connection with client was lost!");
#endif
}
