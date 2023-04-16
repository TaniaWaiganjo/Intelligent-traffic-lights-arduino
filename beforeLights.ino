#include <TM1637Display.h>

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

  // Set up the random number generator
  randomSeed(analogRead(0));
}

void loop() {
  // Assign new random numbers to any display that has reached 1
  if (number1 == 1) number1 = random(200);

                switch(expression) {
                  //APPROACH A
                  case 1:
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
            
            
                 //APPROACH B  
                  case 2:
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
                  default:
                    // code block
                }
  
  

 
}
