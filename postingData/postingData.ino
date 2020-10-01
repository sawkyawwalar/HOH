#include <WiFiClient.h> 
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
const char *ssid     = "your-ssid";
const char *password = "your-password";

void setup() {
  Serial.begin(115200);
  delay(10);

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
  HTTPClient http;
  http.begin("yourthingspeakapi");  //Specify request destination
  int httpCode = http.GET();                                                                  //Send the request
 
  if (httpCode > 0) { //Check the returning code
 
    String payload = http.getString();   //Get the request response payload
    Serial.println(payload);                     //Print the response payload
 
    }
 
  http.end();   //Close connection
  delay(30000);
  }
 
