int led1 = 2; // the pin the LED is connected to
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
#include <OneWire.h> 
#include <DallasTemperature.h>
int button = 12;
int powerButton = 11;
int buttonState = LOW;
int powerButtonState = LOW; cv vW 156
#define ONE_WIRE_BUS 13
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT); // Declare the LED as an output
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(button, INPUT);
  pinMode(powerButton, INPUT);
  sensors.begin(); 
  delay(100);
}

void loop() 
{
  buttonState = digitalRead(button);
  powerButtonState = digitalRead(powerButton);
  //Serial.print("Power Button State: ");
  //Serial.println(powerButtonState);
  if(powerButtonState == HIGH)
  {
    Serial.print(" Requesting temperatures..."); 
    sensors.requestTemperatures();
    Serial.println("DONE"); 
    Serial.print("Temperature is: "); 
    Serial.print(sensors.getTempCByIndex(0));
    //delay(1000); 
    
    if (buttonState == HIGH){
      Serial.print(" Requesting temperatures..."); 
      sensors.requestTemperatures();
      Serial.println("DONE"); 
      Serial.print("Temperature is: "); 
      Serial.print(sensors.getTempCByIndex(0));
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
