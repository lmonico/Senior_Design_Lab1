/*#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "https://senior-design-lab-1.firebaseio.com/"
#define FIREBASE_AUTH "ayPFppZ85ao3smSbXmjKHd4mDZ4EnPjzPGI8bUH0"
#define WIFI_SSID ""
#define WIFI_PASSWORD ""
*/

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

}

void loop() {
   Serial.print(" Requesting temperatures..."); 
   sensors.requestTemperatures();
   Serial.println("DONE"); 
   Serial.print("Temperature is: "); 
   Serial.print(sensors.getTempCByIndex(0));
   delay(1000); 
}
