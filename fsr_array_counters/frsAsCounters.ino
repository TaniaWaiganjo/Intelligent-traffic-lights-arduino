int count=0;
int infi=1;
#define FSR0 A0; 


void setup() {
  Serial.begin(9600);
}

void loop() {
  int counta;
 
  FSR0= analogRead(A0);
  FSR1= analogRead(A1);
  FSR2= analogRead(A2);
  FSR3= analogRead(A3);
  
      if (FSR1>0 ||FSR2>0 ||FSR3>0)
        {
          
        
        Serial.println("Vehicles = ");
        Serial.print(count);
        }
   if (FSR0>0)
      { 
       
        Serial.println("Leaving vehicles = ");
        Serial.print(counta);
      }
    
   delay(1000);
    
  
}
