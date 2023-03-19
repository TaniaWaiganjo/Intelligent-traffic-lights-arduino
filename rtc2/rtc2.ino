#include <virtuabotixRTC.h>

//Object creation
virtuabotixRTC Rclock(6, 7, 8);

void blinkyorange(){
  Rclock.updateTime();

  if (Rclock.hours = 18)
  {
    Serial.println("amberBlink");
    delay(1000);
  }
};

void setup()  {
  Serial.begin(9600);
  
  Rclock.updateTime();
  Serial.print("Current Date / Time: ");
  Serial.print(Rclock.dayofmonth);
  Serial.print("/");
  Serial.print(Rclock.month);
  Serial.print("/");
  Serial.print(Rclock.year);
  Serial.print("  ");
  Serial.print(Rclock.hours);
  Serial.print(":");
  Serial.print(Rclock.minutes);
  Serial.print(":");
  Serial.println(Rclock.seconds);
 
  // format: seconds, minutes, hours, day of the week, day of the month, month, year
  //myRTC.setDS1302Time(0, 31, 17, 1, 19, 3, 2023);
}
void loop()  {
  blinkyorange();
}
