#include <Arduino.h>

#define red 2
#define amber 3
#define green 4


void setup() {
  
  Serial.begin(115200);

 
  
  pinMode(red,OUTPUT);
  pinMode(amber,OUTPUT);
  pinMode(green,OUTPUT);

  digitalWrite(red,HIGH);
  digitalWrite(amber,HIGH);
  digitalWrite(green,HIGH);
  
  
}

void loop() 
  {
              void redState();
              
              void greenState();
              
              void amberState();
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
