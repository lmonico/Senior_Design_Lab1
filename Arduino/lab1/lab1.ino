#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "senior-design-lab-1.firebaseio.com"
#define FIREBASE_AUTH "ayPFppZ85ao3smSbXmjKHd4mDZ4EnPjzPGI8bUH0"
#define WIFI_SSID "meghan"
#define WIFI_PASSWORD "phonepass"

//libraries
#include <OneWire.h> 
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 0
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

void setup() {
  // start serial port 
  Serial.begin(9600); 
  Serial.println("Dallas Temperature IC Control Library Demo"); 
  sensors.begin();


 //https://medium.com/konel/firebase-with-realtime-database-for-iot-applications-e615a7057a48
 //https://create.arduino.cc/projecthub/TheGadgetBoy/ds18b20-digital-temperature-sensor-and-arduino-9cc806
 //https://www.roboshala.com/nodemcu-esp8266-googles-firebase/
 
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
   Serial.print(“connecting”);
   while (WiFi.status() != WL_CONNECTED) {
    Serial.print(“.”);
   }
   delay(500);
   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
   
}

void loop() {
   Serial.print(" Requesting temperatures..."); 
   sensors.requestTemperatures();
   Serial.println("DONE"); 
   Serial.print("Temperature is: "); 
   Serial.print(sensors.getTempCByIndex(0));
   delay(1000); 

   float t = sensors.getTempFByIndex(0);
   Firebase.setFloat ("Temperature", t);
}
