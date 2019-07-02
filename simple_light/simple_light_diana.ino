#include <ESP8266WiFi.h>

 //Wifi network name
const char* ssid = "";
//Wifi password
const char* password = "";

//Message to turn on builtin_Led
String message_on="LEDON";
//Message to turn off builtin_Led
String message_off="LEDOFF";
 
WiFiServer server(80);
 
void setup() {

  Serial.begin(9600);
  delay(10);
 
 
 pinMode(LED_BUILTIN, OUTPUT);
 digitalWrite(LED_BUILTIN, HIGH);
  
  // Connect to WiFi network
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
 
  // Start the server
  server.begin();
  Serial.println("MAC address "+WiFi.macAddress());
 
 
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  
  client.flush();
 
  // Match the request
 
 
  if (request.indexOf("/"+message_on) != -1) {
    Serial.println("Led is ON");
  digitalWrite(LED_BUILTIN, LOW); 
  } 
  if (request.indexOf("/"+message_off) != -1){
    Serial.println("Led is OFF");
   digitalWrite(LED_BUILTIN, HIGH);
  }
}
