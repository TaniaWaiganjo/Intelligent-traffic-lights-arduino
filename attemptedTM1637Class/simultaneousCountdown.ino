#include <TM1637Display.h>

// Initialize the TM1637 displays
TM1637Display display1(2, 3); // CLK, DIO pins for display 1
TM1637Display display2(4, 5); // CLK, DIO pins for display 2
TM1637Display display3(6, 7); // CLK, DIO pins for display 3
TM1637Display display4(8, 9); // CLK, DIO pins for display 4

// Initialize random numbers for each display
int number1 = 0;
int number2 = 0;
int number3 = 0;
int number4 = 0;

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
  // Check if any display has reached 1 and assign a new random number immediately
  if (number1 == 1) {
    number1 = random(200);
    display1.showNumberDec(number1);
  }
  if (number2 == 1) {
    number2 = random(200);
    display2.showNumberDec(number2);
  }
  if (number3 == 1) {
    number3 = random(200);
    display3.showNumberDec(number3);
  }
  if (number4 == 1) {
    number4 = random(200);
    display4.showNumberDec(number4);
  }

  // Count down from the assigned numbers to 0 on all displays simultaneously
  while (number1 > 0 || number2 > 0 || number3 > 0 || number4 > 0) {
    if (number1 > 0) display1.showNumberDec(number1--);
    if (number2 > 0) display2.showNumberDec(number2--);
    if (number3 > 0) display3.showNumberDec(number3--);
    if (number4 > 0) display4.showNumberDec(number4--);
    delay(1000); // adjust delay time for desired speed
  }
}
