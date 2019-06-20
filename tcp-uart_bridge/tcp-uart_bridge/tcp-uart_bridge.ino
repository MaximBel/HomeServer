// Prototype took from RoboRemo example

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

//#define DEBUG
#define UART_BAUD 115200
#define bufferSize 40
#define limitSingleRead bufferSize // maximum frame size, that will be sended if data available
//#define MODE_AP

// AP settings
const char *ssid = "STAG-AP";  // You will connect your phone to this Access Point
const char *pw = "stagappas"; // and this is the password


// Socket settings
IPAddress ip(192, 168, 0, 1); // From RoboRemo app, connect to this IP
const int port = 9876; // and this port
WiFiClient client;
#ifdef MODE_AP
IPAddress netmask(255, 255, 255, 0);
WiFiServer server(port);
#endif

static void processingCommunication();

void setup() {

  delay(1000);

  Serial.begin(UART_BAUD);

#ifdef MODE_AP
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip, ip, netmask); // configure ip address for softAP
  WiFi.softAP(ssid, pw); // configure ssid and password for softAP
  
#ifdef DEBUG
  Serial.println("Starting TCP Server");
#endif

  server.begin(); // start TCP server
#else
  // STATION mode (ESP connects to router and gets an IP)
  // Assuming phone is also connected to that router
  // from RoboRemo you must connect to the IP of the ESP
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pw);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
#endif
}

void loop() {
#ifdef MODE_AP 
  // Waiting for client for TCP server  
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

#else
  // Trying to connect to server

  while (!client.connect(ip, port)) {
    Serial.println("Waiting for TCP server...");
    delay(500);
  }

#ifdef DEBUG
  Serial.println("TCP client connected.");
#endif

#endif

  processingCommunication();
 }

static void processingCommunication() {
  static uint8_t bufWifiToUart[bufferSize];
  static uint8_t bufUartToWifi[bufferSize];
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
  Serial.println("Connection was lost!");
#endif
}
