#include <ThingSpeak.h>
#include <WiFiClient.h> 
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
const char *ssid     = "your-ssid";
const char *password = "your-password";
unsigned long Channel_ID = 12345; // Your Channel ID
const char * myWriteAPIKey = "ABCDEF12345"; //Your write API key
const int Field_Number_1 = 1;
int value_1 = 2;
void setup() {
  Serial.begin(115200);
  delay(10);
  WiFiClient  client;
  ThingSpeak.begin(client);
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
  ThingSpeak.writeField(Channel_ID, Field_Number_1, value_1, myWriteAPIKey);
  delay(15000);
  }
 
