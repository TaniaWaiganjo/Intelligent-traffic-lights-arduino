

#define fsr1 A0 
#define fsr2 A1
#define fsr3 A2
#define fsr4 A3
#define fsr5 A4
#define fsr6 A5
#define fsr7 A6

float count=0;
int counter;
void setup() {
  Serial.begin(9600);
  void readSensor{
}

void loop() {
  int analogReading = analogRead(FORCE_SENSOR_PIN);

 
  if (analogReading > 1)       // from 0 to 9
    {count=count+0.5;
    Serial.println(count);}
  else 
    
    Serial.println(" -> no pressure");

  delay(1000);
}
