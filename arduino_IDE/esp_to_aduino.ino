#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

WiFiClient client;
HTTPClient http;


#include <SoftwareSerial.h>
String str;
String dir;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  delay(2000);

  Serial.println("Connecting");
  connect_wifi();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
}


void connect_wifi()
{
  delay(100);
  //  char * username = "KhaledDodo";
  //  char * password = "veto939599";
  //  char * username = "youssef";
  //  char * password = "12345678";
  char * username = "STUDBME2";
  char * password = "BME2Stud";
  //  char * username = "STUDBME1";
  //  char * password = "BME1Stud";
  //  char * username = "Marwa";
  //  char * password = "alipixels";
  //  char * username = "Mikasa";
  //  char * password = "mnnymnny";
  Serial.print("Connecting to Wifi: ");
  Serial.println(username);
  WiFi.begin(username, password);

  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i < 20)
  {
    Serial.print(".");
    delay(500);
    i++;
  }
  if (i > 20) {
    Serial.println("Couldn't connect to wifi");
  } else {
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
  }
}

String get_direction() {
  String payload;
  //Check WiFi connection status
  //  if (WiFi.status() == WL_CONNECTED) {
  String urlString = "http://172.28.132.122:8090/direction?";
  Serial.print("esp connected \n");
  //    String urlString = "http://192.168.1.105:8090/direction?";

  http.begin(client, urlString.c_str());
  // Your Domain name with URL path or IP address with path
  int httpResponseCode = http.GET();
  Serial.println(httpResponseCode);
  payload = http.getString();
  //    Serial.println(payload);
  Serial.println("payload = ");
  Serial.println(payload);
  // Free resources
  http.end();
  //  }
  //  else
  //  {
  //    Serial.println("WiFi Disconnected");
  //  }
  delay(2000);

  return payload;
}


void loop()
{


  //for (int i = 0 ; i<4 ; i++ ){
  //  dir = direction[i];
  //  str =String("coming from ESP8266: ")+String(dir);
  //  Serial1.println(str);
  //  Serial.println("dir = ");
  //  Serial.println(dir);
  //  delay(3000);
  //
  //}

  dir = get_direction();
  str = String("coming from ESP8266: ") + String(dir);
  Serial1.println(str);
  Serial.println("dir = ");
  Serial.println(dir);
  //delay(1000);
}
