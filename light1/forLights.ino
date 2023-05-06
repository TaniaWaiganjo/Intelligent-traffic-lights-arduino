#include <TM1637Display.h>

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

// Initialize the TM1637 displays
TM1637Display display1(2, 3); // CLK, DIO pins for display 1
TM1637Display display2(4, 5); // CLK, DIO pins for display 2
TM1637Display display3(6, 7); // CLK, DIO pins for display 3
TM1637Display display4(8, 9); // CLK, DIO pins for display 4

// Initialize random numbers for each display
int number1 = 10;
int number2 = 0;
int number3 = 0;
int number4 = 0;

int approach = 1;



// Define variables for tracking elapsed time
unsigned long previousMillis = 0;
const long interval = 1000; // adjust interval time for desired speed
unsigned long waitMillis = 0;

void setup() {
  // Set up the displays
  display1.setBrightness(7);
  display2.setBrightness(7);
  display3.setBrightness(7);
  display4.setBrightness(7);

   Serial.begin(115200);

 
  
  pinMode(redA,OUTPUT);
  pinMode(amberA,OUTPUT);
  pinMode(greenA,OUTPUT);

  //
  
  pinMode(redB,OUTPUT);
  pinMode(amberB,OUTPUT);
  pinMode(greenB,OUTPUT);

  //
  pinMode(redC,OUTPUT);
  pinMode(amberC,OUTPUT);
  pinMode(greenC,OUTPUT);

 //
  pinMode(redD,OUTPUT);
  pinMode(amberD,OUTPUT);
  pinMode(greenD,OUTPUT);

  //

  // Set up the random number generator
  randomSeed(analogRead(0));
}

void loop() 
      {
          // Assign new random numbers to any display that has reached 1
          //if (number1 == 1) number1 = random(10);
 int approach=1;       
                       
                          //APPROACH A
                         if (approach>0){    
                                      approachA();                     

                                        /*greenStateA();
              
                                        amberStateA();

                                        redStateB();

                                        redStateC();

                                        redStateD();
                                  // Check elapsed time since last display update
                                  unsigned long currentMillis = millis();
                                    if (currentMillis - previousMillis >= interval)
                        {
                                      // Update all displays simultaneously
                                      display1.showNumberDec(number1);
                                      display2.showNumberDec(number1);
                                      display3.showNumberDec(number1);
                                      display4.showNumberDec(number1);
                      
                                    // Decrement numbers on all displays simultaneously
                                    if (number1 > 0) number1--;
                                   // Save the current time for next update
                                    previousMillis = currentMillis;
                        }*/
                          }
                            
                           
                    
                         //APPROACH B  
                          /*case 2:

                                        greenStateB();
              
                                        amberStateB();

                                        redStateA();

                                        redStateC();

                                        redStateD();
                                          // Check elapsed time since last display update
                                  unsigned long currentMillis = millis();
                                    if (currentMillis - previousMillis >= interval)
                        {
                                      // Update all displays simultaneously
                                      display1.showNumberDec(number1);
                                      display2.showNumberDec(number1);
                                      display3.showNumberDec(number1);
                                      display4.showNumberDec(number1);
                      
                                    // Decrement numbers on all displays simultaneously
                                    if (number1 > 0) number1--;
                                   // Save the current time for next update
                                    previousMillis = currentMillis;
                        }
                            break;
                    
                    
                          //APPROACH C
                          case 3:

                                        greenStateC();
              
                                        amberStateC();

                                        redStateB();

                                        redStateA();

                                        redStateD();
                                          // Check elapsed time since last display update
                                  unsigned long currentMillis = millis();
                                    if (currentMillis - previousMillis >= interval)
                        {
                                      // Update all displays simultaneously
                                      display1.showNumberDec(number1);
                                      display2.showNumberDec(number1);
                                      display3.showNumberDec(number1);
                                      display4.showNumberDec(number1);
                      
                                    // Decrement numbers on all displays simultaneously
                                    if (number1 > 0) number1--;
                                   // Save the current time for next update
                                    previousMillis = currentMillis;
                        }
                            break;
                    
                    
                         //APPROACH D
                          case 4:

                                        greenStateD();
              
                                        amberStateD();

                                        redStateB();

                                        redStateC();

                                        redStateA();
                                          // Check elapsed time since last display update
                                  unsigned long currentMillis = millis();
                                    if (currentMillis - previousMillis >= interval)
                        {
                                      // Update all displays simultaneously
                                      display1.showNumberDec(number1);
                                      display2.showNumberDec(number1);
                                      display3.showNumberDec(number1);
                                      display4.showNumberDec(number1);
                      
                                    // Decrement numbers on all displays simultaneously
                                    if (number1 > 0) number1--;
                                   // Save the current time for next update
                                    previousMillis = currentMillis;
                        }*/
                          

 //end of void loop
       }


//Function definitions
    void redStateA()
    {
      static unsigned long redmillis = millis(); // run first time only to read current millis due to use of static
      
      if(millis()-redmillis > (number1*interval)) 
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
      
      if(millis()-greenmillis > (number1*interval)) 
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
      
      if(millis()-greenmillis > (number1*1000)) 
        {
          digitalWrite(redD, LOW);
          digitalWrite(amberD, LOW);
          digitalWrite(greenD,HIGH);// assignes opposite state of the led
          greenmillis =millis();//reset  millis
        }
    }


    void approachA()
    {

                                        greenStateA();
              
                                        amberStateA();

                                        redStateB();

                                        redStateC();

                                        redStateD();
                                  // Check elapsed time since last display update
                                  unsigned long currentMillis = millis();
                                    if (currentMillis - previousMillis >= interval)
                        {
                                      // Update all displays simultaneously
                                      display1.showNumberDec(number1);
                                      display2.showNumberDec(number1);
                                      display3.showNumberDec(number1);
                                      display4.showNumberDec(number1);
                      
                                    // Decrement numbers on all displays simultaneously
                                    if (number1 > 0) number1--;
                                   // Save the current time for next update
                                    previousMillis = currentMillis;
                        }


    
    }
