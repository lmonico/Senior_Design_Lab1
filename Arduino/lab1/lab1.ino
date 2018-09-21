
#include <ESP8266WiFi.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "senior-design-lab-1.firebaseio.com"
#define FIREBASE_AUTH "ayPFppZ85ao3smSbXmjKHd4mDZ4EnPjzPGI8bUH0"
#define ONE_WIRE_BUS 3
const char* ssid = "MeghanAndMabel"; // key in your own SSID
const char* password = "effwacb7f44acd"; // key in your own WiFi access point password

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

int led1 = 16; // the pin the LED is connected to
int led2 = 5;
int led3 = 4;
int led4 = 0;
int led5 = 2;
int led6 = 14;
int led7 = 12;
int button = 13;
int powerButton = 15;
int buttonState = LOW;
int powerButtonState = LOW;

float tempCelcius = 0.0f;
float tempFaren = 0.0f;

void adcValToTemperatures(float adcVal, float *celcius, float *farenheit);
void printTempToSerial(float adcVal, float tempCelcius, float tempFaren);

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

//Connect to firebase
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(3, FUNCTION_3);
  pinMode(led1, OUTPUT); // Declare the LED as an output
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(button, INPUT);
  pinMode(powerButton, INPUT);
 
} 
void loop(void) 
{ 
  //float adcVal = analogRead(tempsensor);
  //adcValToTemperatures(adcVal, &tempCelcius, &tempFaren);
  //printTempToSerial(adcVal, tempCelcius, tempFaren);
  
  buttonState = digitalRead(button);
  powerButtonState = digitalRead(powerButton);
  //Serial.print("Button State: ");
  //Serial.println(buttonState);
  if(powerButtonState == HIGH)
  {
    Serial.print(" Requesting temperatures..."); 
    sensors.requestTemperatures();
    Serial.println("DONE"); 
    Serial.print("Temperature is: "); 
    Serial.print(sensors.getTempCByIndex(0));
    delay(1000); 
    Firebase.setFloat("Temperature", sensors.getTempCByIndex(0)); 
    if (buttonState == HIGH){
      Serial.print(" Requesting temperatures..."); 
      sensors.requestTemperatures();
      Serial.println("DONE"); 
      Serial.print("Temperature is: "); 
      Serial.print(sensors.getTempCByIndex(0));
      Firebase.setFloat("Temperature", sensors.getTempCByIndex(0)); 
      //https://www.quora.com/How-do-I-find-2s-complement-of-decimal-numbers-in-c
      int data = sensors.getTempCByIndex(0);
      const size_t BITS = 7;
      char bin_str[BITS];

      for(unsigned int i=0; i<BITS; i++)
      {
        unsigned int mask = 1u << (BITS - 1 - i);
        bin_str[i] = (data & mask) ? '1' : '0'; 
      }
  
      for(int i = 0; i < BITS; i++)
      {
        if(i == 0)
        { 
          if(bin_str[i] == '1')
          {
            digitalWrite(led1, HIGH);
          }
          else
          {
            digitalWrite(led1, LOW);
          }
        }
        if(i == 1)
        {
          if(bin_str[i] == '1')
          {
            digitalWrite(led2, HIGH);
          }
          else
          {
            digitalWrite(led2, LOW);
          }
        }
        if(i == 2)
        {
          if(bin_str[i] == '1')
          {
            digitalWrite(led3, HIGH);
          }
          else
          {
            digitalWrite(led3, LOW);
          }
        }
        if(i == 3)
        {
          if(bin_str[i] == '1')
          {
            digitalWrite(led4, HIGH);
          }
          else
          {
            digitalWrite(led4, LOW);
          }
        }
        if(i == 4)
        { 
          if(bin_str[i] == '1')
          {
            digitalWrite(led5, HIGH);
          }
          else
          {
            digitalWrite(led5, LOW);
          }
        }
        if(i == 5)
        {
          if(bin_str[i] == '1')
          {
            digitalWrite(led6, HIGH);
          }
          else
          {
            digitalWrite(led6, LOW);
          }
        }
        if(i == 6)
        {
          if(bin_str[i] == '1')
          {
            digitalWrite(led7, HIGH);
          }
          else
          {
            digitalWrite(led7, LOW);
          }
        }    
      }
    }
    else
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
    }
    //send message to database (power = 1)
  }
  else
  {
    // send message to database (power = 0)
  }
} 

void adcValToTemperatures(float adcVal, float *celcius, float *farenheit) {
  *celcius = ((adcVal * (3300.0/1024)) - 500) / 10;
  *farenheit = (*celcius * 1.8) + 32;
}

void printTempToSerial(float adcVal, float tempCelcius, float tempFaren) {
  Serial.print("adc=");
  Serial.print(adcVal);
  Serial.print(" celcius=");
  Serial.print(tempCelcius);
  Serial.print(" farenheit=");
  Serial.println(tempFaren);
}
