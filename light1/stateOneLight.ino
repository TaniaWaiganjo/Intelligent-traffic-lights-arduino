#include <Arduino.h>

#define redA 2
#define amberA 3
#define greenA 4

#define redB 5
#define amberB 6
#define greenB 7


void setup() {
  
  Serial.begin(115200);

 
  
  pinMode(redA,OUTPUT);
  pinMode(amberA,OUTPUT);
  pinMode(greenA,OUTPUT);

  digitalWrite(redA,HIGH);
  digitalWrite(amberA,HIGH);
  digitalWrite(greenA,HIGH);
  
  
  pinMode(redB,OUTPUT);
  pinMode(amberB,OUTPUT);
  pinMode(greenB,OUTPUT);

  digitalWrite(redB,HIGH);
  digitalWrite(amberB,HIGH);
  digitalWrite(greenB,HIGH);
  
  pinMode(redC,OUTPUT);
  pinMode(amberC,OUTPUT);
  pinMode(greenC,OUTPUT);

  digitalWrite(redC,HIGH);
  digitalWrite(amberC,HIGH);
  digitalWrite(greenC,HIGH);
  
  pinMode(redD,OUTPUT);
  pinMode(amberD,OUTPUT);
  pinMode(greenD,OUTPUT);

  digitalWrite(redD,HIGH);
  digitalWrite(amberD,HIGH);
  digitalWrite(greenD,HIGH);
  
  
}

void loop() 
  {
              redState();
              
              greenState();
              
              amberState();
              Serial.print("1");
  }          
    void redState()
    {
      static unsigned long redmillis = millis(); // run first time only to read current millis due to use of static

      if(millis()-redmillis >500) 
        {
          digitalWrite(red, !digitalRead(red));// assignes opposite state of the led
          redmillis =millis();//reset  millis
        }
    }

    void amberState()
    {
      static unsigned long ambermillis = millis(); // run first time only to read current millis due to use of static

      if(millis()-ambermillis >250) 
        {
          digitalWrite(amber, !digitalRead(amber));// assignes opposite state of the led
          ambermillis =millis();//reset  millis
        }
    }

    void greenState()
    {
      static unsigned long greenmillis = millis(); // run first time only to read current millis due to use of static

      if(millis()-greenmillis >100) 
        {
          digitalWrite(green, !digitalRead(green));// assignes opposite state of the led
          greenmillis =millis();//reset  millis
        }
    }
///READ STATE 1 FOR CLARIFICATION
