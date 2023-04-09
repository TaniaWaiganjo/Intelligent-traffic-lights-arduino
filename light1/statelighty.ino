#include <Arduino.h>

#define redA 2
#define amberA 3
#define greenA 4

#define redB 5
#define amberB 6
#define greenB 7


void setup() {
  
  Serial.begin(9600);

 
  
  pinMode(redA,OUTPUT);
  pinMode(amberA,OUTPUT);
  pinMode(greenA,OUTPUT);

  digitalWrite(redA,HIGH);
  digitalWrite(amberA,LOW);
  digitalWrite(greenA,LOW);
  
  
  pinMode(redB,OUTPUT);
  pinMode(amberB,OUTPUT);
  pinMode(greenB,OUTPUT);

  digitalWrite(redB,HIGH);
  digitalWrite(amberB,HIGH);
  digitalWrite(greenB,HIGH);
  
/*  pinMode(redC,OUTPUT);
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
  digitalWrite(greenD,HIGH);*/
  
  
}

void loop() 
  {
              redState();
              
              amberState();

              greenState();
              

  }          
    void redState()
    {
      static unsigned redmillis = millis(); // run first time only to read current millis due to use of static
      unsigned number1 = random(120);
      Serial.println(number1);
      while(millis()-redmillis >(number1*100)) 
        {
          digitalWrite(redA, HIGH);// assignes opposite state of the led
          digitalWrite(amberA,LOW);
          digitalWrite(greenA,LOW);
          redmillis =millis();//reset  millis
        }
    }

    void amberState()
    {
      static unsigned  ambermillis = millis(); // run first time only to read current millis due to use of static
      
      if(millis()-ambermillis >(3000) )
        {
          digitalWrite(redA,LOW);// assignes opposite state of the led
          digitalWrite(amberA,HIGH);
          digitalWrite(greenA,LOW);
          ambermillis =millis();//reset  millis
        }
    }

    void greenState()
    {
      static unsigned long greenmillis = millis(); // run first time only to read current millis due to use of static
      unsigned long number3 = random(120);
      if(millis()-greenmillis >(number3*100)) 
        {
          digitalWrite(redA, LOW);// assignes opposite state of the led
          digitalWrite(amberA,LOW);
          digitalWrite(greenA,HIGH);
          greenmillis =millis();//reset  millis
        }
    }
///READ STATE 1 FOR CLARIFICATION
