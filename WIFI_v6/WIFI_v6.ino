#include <ESP8266WiFi.h>        // Include the Wi-Fi library

const char* ssid     = "LAPTOP-3OSR4EKG 2152";
// The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "9730|p7L";                        // The password of the Wi-Fi network

const int port = 8091;
const char* host = "192.168.137.1";

void setup() {
  Serial.begin(115200);         // Start the Serial communication with UNO
  delay(10);

  //WiFi.mode(WIFI_STA);              //Multiple Connections
  WiFi.begin(ssid, password);       // Connect to the network

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
  }

}


void loop()
{

  WiFiClient client;

  if (!client.connect(host, port))
  {
    delay(1000);
    return;
  }

  while (client.connected())
  {
    while (client.available() > 0)
    {
      char c = client.read();
      int command = int(c);
      Serial.write(command);
    }
  }
}
