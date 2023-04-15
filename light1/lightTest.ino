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





void setup() {
 pinMode(redA,OUTPUT);
  pinMode(amberA,OUTPUT);
  pinMode(greenA,OUTPUT);
  

  pinMode(redB,OUTPUT);
  pinMode(amberB,OUTPUT);
  pinMode(greenB,OUTPUT);

  
  pinMode(redC,OUTPUT);
  pinMode(amberC,OUTPUT);
  pinMode(greenC,OUTPUT);

  
  pinMode(redD,OUTPUT);
  pinMode(amberD,OUTPUT);
  pinMode(greenD,OUTPUT);

  
  
  
  
}

void loop() {
   digitalWrite(redA,HIGH);
  digitalWrite(amberA,HIGH);
  digitalWrite(greenA,HIGH);

  digitalWrite(redB,HIGH);
  digitalWrite(amberB,HIGH);
  digitalWrite(greenB,HIGH);

  digitalWrite(redC,HIGH);
  digitalWrite(amberC,HIGH);
  digitalWrite(greenC,HIGH);

  digitalWrite(redD,HIGH);
  digitalWrite(amberD,HIGH);
  digitalWrite(greenD,HIGH);



}
