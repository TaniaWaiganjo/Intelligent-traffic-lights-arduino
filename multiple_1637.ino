#include <Arduino.h>
#include <TM1637Display.h>


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


#define DELAY 3000

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

void loop() {

//Random number generator
int x= random(200);
int y= random(200);
int q= random(200);
int z= random(200);

  display1.showNumberDec(x,false); //Expect: _120
  display2.showNumberDec(y,false);
  display3.showNumberDec(z,false);
  display4.showNumberDec(q,false);

  delay(DELAY);
 

  

}
