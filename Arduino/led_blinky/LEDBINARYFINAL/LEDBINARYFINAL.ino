int led1 = 2; // the pin the LED is connected to
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;

void setup() {
  pinMode(led1, OUTPUT); // Declare the LED as an output
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
}

void loop() 
{
  //https://www.quora.com/How-do-I-find-2s-complement-of-decimal-numbers-in-c
  int data = 50;
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
        digitalWrite(led1, LOW);
      }
      else
      {
        digitalWrite(led1, HIGH);
      }
    }
    if(i == 1)
    {
      if(bin_str[i] == '1')
      {
        digitalWrite(led2, LOW);
      }
      else
      {
        digitalWrite(led2, HIGH);
      }
    }
    if(i == 2)
    {
      if(bin_str[i] == '1')
      {
        digitalWrite(led3, LOW);
      }
      else
      {
        digitalWrite(led3, HIGH);
      }
    }
    if(i == 3)
    {
      if(bin_str[i] == '1')
      {
        digitalWrite(led4, LOW);
      }
      else
      {
        digitalWrite(led4, HIGH);
      }
    }
    if(i == 4)
    {
      if(bin_str[i] == '1')
      {
        digitalWrite(led5, LOW);
      }
      else
      {
        digitalWrite(led5, HIGH);
      }
    }
    if(i == 5)
    {
      if(bin_str[i] == '1')
      {
        digitalWrite(led6, LOW);
      }
      else
      {
        digitalWrite(led6, HIGH);
      }
    }
    if(i == 6)
    {
      if(bin_str[i] == '1')
      {
        digitalWrite(led7, LOW);
      }
      else
      {
        digitalWrite(led7, HIGH);
      }
    }    
  }
}
