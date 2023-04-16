#include <Arduino.h>

#define redA 52
#define amberA 50
#define greenA 48

#define redB 38
#define amberB 36
#define greenB 34

#define redC 53
#define amberC 51
#define greenC 49

#define redD 39
#define amberD 37
#define greenD 35

int number1 = 10;



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

  randomSeed(analogRead(0));
  
}

void loop() 
  { 
              
               
              redStateA();
              
              greenStateA();
              
              amberStateA();

              redStateB();
              
              greenStateB();
              
              amberStateB();

              redStateC();
              
              greenStateC();
              
              amberStateC();

              redStateD();
              
              greenStateD();
              
              amberStateD();

              
             
  }          
    void redStateA()
    {
      static unsigned long redmillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-redmillis > (number1*1000)) 
        {
          digitalWrite(redA, HIGH);
          digitalWrite(amberA, LOW);
          digitalWrite(greenA, LOW);
          redmillis =millis();//reset  millis
        }
    }

    void amberStateA()
    {
      static unsigned long ambermillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-ambermillis >3500) 
        {
          digitalWrite(redA, HIGH);
          digitalWrite(amberA,HIGH);
          digitalWrite(greenA, LOW);
          ambermillis =millis();//reset  millis
        }
    }

    void greenStateA()
    {
      static unsigned long greenmillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-greenmillis > (number1*1000)) 
        {
          digitalWrite(redA, LOW);
          digitalWrite(amberA, LOW);
          digitalWrite(greenA,HIGH);// assignes opposite state of the led
          greenmillis =millis();//reset  millis
        }
    }

    void redStateB()
    {
      static unsigned long redmillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-redmillis > (number1*1000)) 
        {
          digitalWrite(redB, HIGH);
          digitalWrite(amberB, LOW);
          digitalWrite(greenB, LOW);
          redmillis =millis();//reset  millis
        }
    }

    void amberStateB()
    {
      static unsigned long ambermillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-ambermillis >3500) 
        {
          digitalWrite(redB, HIGH);
          digitalWrite(amberB,HIGH);
          digitalWrite(greenB, LOW);
          ambermillis =millis();//reset  millis
        }
    }

    void greenStateB()
    {
      static unsigned long greenmillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-greenmillis > (number1*1000)) 
        {
          digitalWrite(redB, LOW);
          digitalWrite(amberB, LOW);
          digitalWrite(greenB,HIGH);// assignes opposite state of the led
          greenmillis =millis();//reset  millis
        }
    }

    void redStateC()
    {
      static unsigned long redmillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-redmillis > (number1*1000)) 
        {
          digitalWrite(redC, HIGH);
          digitalWrite(amberC, LOW);
          digitalWrite(greenC, LOW);
          redmillis =millis();//reset  millis
        }
    }

    void amberStateC()
    {
      static unsigned long ambermillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-ambermillis >3500) 
        {
          digitalWrite(redC, HIGH);
          digitalWrite(amberC,HIGH);
          digitalWrite(greenC, LOW);
          ambermillis =millis();//reset  millis
        }
    }

    void greenStateC()
    {
      static unsigned long greenmillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-greenmillis > (number1*1000)) 
        {
          digitalWrite(redC, LOW);
          digitalWrite(amberC, LOW);
          digitalWrite(greenC,HIGH);// assignes opposite state of the led
          greenmillis =millis();//reset  millis
        }
    }

    void redStateD()
    {
      static unsigned long redmillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-redmillis > (number1*1000)) 
        {
          digitalWrite(redD, HIGH);
          digitalWrite(amberD, LOW);
          digitalWrite(greenD, LOW);
          redmillis =millis();//reset  millis
        }
    }

    void amberStateD()
    {
      static unsigned long ambermillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-ambermillis >3500) 
        {
          digitalWrite(redD, HIGH);
          digitalWrite(amberD,HIGH);
          digitalWrite(greenD, LOW);
          ambermillis =millis();//reset  millis
        }
    }

    void greenStateD()
    {
      static unsigned long greenmillis = millis(); // run first time only to read current millis due to use of static
      if (number1 == 1) number1 = random(10);
      if(millis()-greenmillis > (number1*1000)) 
        {
          digitalWrite(redD, LOW);
          digitalWrite(amberD, LOW);
          digitalWrite(greenD,HIGH);// assignes opposite state of the led
          greenmillis =millis();//reset  millis
        }
    }

   /* void combinedStates()
    {
      redState();
             
      greenState();
              
      amberState();
 
    }*/
///READ STATE 1 FOR CLARIFICATION
