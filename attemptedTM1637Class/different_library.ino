#include <TM1637.h>

TM1637 module(2,3);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(900,false);
}
