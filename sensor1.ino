int count=0;
int FSR0,FSR1,FSR2,FSR3;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int counta =0,countb =0,countc =0,countd =0;
  FSR0= analogRead(A0);
  FSR1= analogRead(A1);
  FSR2= analogRead(A2);
  FSR3= analogRead(A3);
  if (FSR0>0 || FSR1>0 ||FSR2>0 ||FSR3>0)
    {count++;
        count=count/2;
        Serial.println("Vehicles = ");
        Serial.println(count);
        delay(500); 
    }
   if (FSR0>0)
      { counta++;
        Serial.println("Queue length a = ");
        Serial.println(counta);
        delay(500); 
      }
    if (FSR1>0)
      { countb++;
        Serial.println("Queue length b = ");
        Serial.println(countb);
        delay(500); 
      }
     if (FSR2>0)
      { countc++;
        Serial.println("Queue length c = ");
        Serial.println(countc);
        delay(500); 
      }
      if (FSR3>0)
      { countd++;
        Serial.println("Queue length d = ");
        Serial.println(countd);
        delay(500); 
      }

    
  
}
