#include <Temperature_LM75_Derived.h>
#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "your-ssid"
#define STAPSK  "your-password"
#endif
const char* ssid = STASSID;
const char* password = STAPSK;
WiFiServer server(80);
Generic_LM75 temperature;
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));


  server.begin();
  Serial.println(WiFi.localIP());


}

void loop() {
  WiFiClient client = server.available();
if (!client){
  return ;
  
}
int temp=temperature.readTemperatureC();
delay(250);
client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n The Tempreture is"+String(temp)+"</html>");
}
