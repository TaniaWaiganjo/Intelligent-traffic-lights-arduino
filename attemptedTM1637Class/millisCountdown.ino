#include <TM1637Display.h>
//ITS THIS ONE
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

// Define variables for tracking elapsed time
unsigned long previousMillis = 0;
const long interval = 10; // adjust interval time for desired speed

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
  if (number2 == 1) number2 = random(200);
  if (number3 == 1) number3 = random(200);
  if (number4 == 1) number4 = random(200);

  // Check elapsed time since last display update
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // Update all displays simultaneously
    display1.showNumberDec(number1);
    display2.showNumberDec(number2);
    display3.showNumberDec(number3);
    display4.showNumberDec(number4);

    // Decrement numbers on all displays simultaneously
    if (number1 > 0) number1--;
    if (number2 > 0) number2--;
    if (number3 > 0) number3--;
    if (number4 > 0) number4--;

    // Save the current time for next update
    previousMillis = currentMillis;
  }
}
