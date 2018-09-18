int led1 = 2; // the pin the LED is connected to
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
#define HIGH 0x1
#define LOW 0x0

void setup() {
  pinMode(led1, OUTPUT); // Declare the LED as an output
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  Serial.print("Hello");
}

void loop() {
  //https://www.programiz.com/cpp-programming/examples/binary-decimal-convert
   int tempData = 12;
  int remainder = 0;
  int place = 1;
  int binaryNum = 0;
  while (tempData != 0)
  {
    remainder = tempData % 2;
    tempData /= 2;
    binaryNum += remainder*place;
    place *= 10;
  }
  Serial.println("1's complement: " + binaryNum);
  if(binaryNum != 0)
  {
    binaryNum = ~binaryNum + 1;
    
  }
  Serial.println("2's complement: " + binaryNum);
  int isOn = 0;
  for(int i = 0; i < 6; i++)
  {
    isOn =0;
    isOn = binaryNum % 10;
    binaryNum /= 10;
    if(i == 0)
    {
      digitalWrite(led2, isOn);
    }
    if(i == 1)
    {
      digitalWrite(led3, isOn);
    }
    if(i == 2)
    {
      digitalWrite(led4, isOn);
    }
    if(i == 3)
    {
      digitalWrite(led5, isOn);
    }
    if(i == 5)
    {
      digitalWrite(led6, isOn);
    }
    if(i == 6)
    {
      digitalWrite(led7, isOn);
    }


  }
  
}
