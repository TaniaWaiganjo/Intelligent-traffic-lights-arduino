#include "light.h"
#include <Arduino.h>
#include <TM1637Display.h>

//int red = 31;
//int amber= 33;
//int green = 35;


//light trafficLight={19,20,21};
light trafficLight[4]=
{{11,12,13},{8,9,10},{5,6,7},{2,3,4}};

//screen 1
#define CLK1 2
#define DIO1 3

//screen 2
#define CLK2 4
#define DIO2 5

//screen 3
#define CLK3 6
#define DIO3 7

//screen 4
#define CLK4 8
#define DIO4 9


TM1637Display display1(CLK1, DIO1);
TM1637Display display2(CLK2,DIO2);
TM1637Display display3(CLK3,DIO3);
TM1637Display display4(CLK4,DIO4);



void setup() {
 
 display1.setBrightness(2); 
 display2.setBrightness(3);
 display3.setBrightness(2);
 display4.setBrightness(3);

  
}

void loop() 
{   
  int z= random(100);
  int x= random(100);  
  int y= random(100);
  int q= random(100);
  //int z= random(100);



  display1.showNumberDec(x,false); 
  
    for(int a=x; a>0 ; a--)
    {
      display1.showNumberDec(a,false); 
      delay(1000);
    }

   
  display2.showNumberDec(y,false);
  
     for(int b=y; b>0 ; b--)
     {
      display1.showNumberDec(b,false); 
      delay(1000);
    }


  
  display3.showNumberDec(z,false);
  
     for(int c=q; q>0 ; c--)
     {
      display1.showNumberDec(x,false); 
      delay(1000);
    }


  
  display4.showNumberDec(q,false);
  
     for(int d=z; z>0 ; d--)
     {
      display1.showNumberDec(d,false); 
      delay(1000);
    }


  

  /*  for(int i=0; i<4 ;i++)
    {
        trafficLight[i].redState();
        delay(3000);
        trafficLight[i].amberState();
        delay(1000);
        trafficLight[i].greenState();
        delay(3000);  
    }*/
}
