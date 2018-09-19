
#include <ESP8266WiFi.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
//#include <FirebaseArduino.h>
//#define FIREBASE_HOST "senior-design-lab-1.firebaseio.com"
//#define FIREBASE_AUTH "ayPFppZ85ao3smSbXmjKHd4mDZ4EnPjzPGI8bUH0"
#define ONE_WIRE_BUS 6
const char* ssid = "UI-DeviceNet"; // key in your own SSID
const char* password = "UI-DeviceNet"; // key in your own WiFi access point password
const char* host = "www.handsontec.com";

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

void setup(void) 
{ 
 // start serial port 
 Serial.begin(115200);
 Serial.println("Dallas Temperature IC Control Library Demo"); 
 sensors.begin(); 
 delay(100);
 
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

    Serial.print("MAC: ");
   Serial.println(WiFi.macAddress());

//Connect to firebase
 //Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
} 
int value = 0;

void loop(void) 
{ 
   Serial.print(" Requesting temperatures..."); 
   sensors.requestTemperatures();
   Serial.println("DONE"); 
   Serial.print("Temperature is: "); 
   Serial.print(sensors.getTempCByIndex(0));
   delay(1000); 

   float t = sensors.getTempCByIndex(0);
   //Firebase.setFloat ("Temperature", t);*/
   
} 
