



#define fsr1 A0 
#define fsr2 A1
#define fsr3 A2
#define fsr4 A3
#define fsr5 A4
#define fsr6 A5
#define fsr7 A6

 
int counter;
void setup() {
  Serial.begin(9600);
  /*int analogReading1,analogReading2,analogReading3,analogReading4,analogReading5,analogReading6,analogReading7;*/
}
void loop() 
{

    int analogReading1 = analogRead(fsr1);
    int analogReading2 = analogRead(fsr2);
    int analogReading3 = analogRead(fsr3);
    int analogReading4 = analogRead(fsr4);
    int analogReading5 = analogRead(fsr5);
    int analogReading6 = analogRead(fsr6);
    int analogReading7 = analogRead(fsr7);



    float count=0;
    float count1=0;
    float count2=0;
    float count3=0;
    float count4=0;
    float count5=0;
    float count6=0;
    float count7=0;
   

  while (1)
    {

    
      
/*fsr1*/
        if (analogReading1 > 1)       
        {
        count=count+0.5;
        
        count1=count1+0.5;
        
            if (count1>3)
            {
                Serial.println("The queue 1 is full");
            }
        Serial.println(count);}
        else 
        
        Serial.println(" -> no vehicle");
    
        delay(1000);
    


/*fsr2*/
        if (analogReading2 > 1)       
        {
            count=count+0.5;
            
            count2=count2+0.5;
            
                if (count2>3)
                {
                    Serial.println("The queue 2 is full");
                }
            Serial.println(count);}
            else 
            
            Serial.println(" -> no vehicle");
        
            delay(1000);
        }


/*fsr3*/

        if (analogReading3 > 1)       
        {
            count=count+0.5;
            
            count3=count3+0.5;
            
                if (count3>3)
                {
                    Serial.println("The queue 3 is full");
                }
            Serial.println(count);}
            else 
            
            Serial.println(" -> no vehicle");
        
            delay(1000);
        }


/*fsr 4*/
        if (analogReading4 > 1)       
        {
            count=count+0.5;
            
            count4=count4+0.5;
            
                if (count4>3)
                {
                    Serial.println("The queue 4 is full");
                }
            Serial.println(count);}
            else 
            
            Serial.println(" -> no vehicle");
        
            delay(1000);
        }


/*fsr 5*/

        if (analogReading5 > 1)       
        {
            count=count+0.5;
            
            count5=count5+0.5;
            
                if (count5>3)
                {
                    Serial.println("The queue 5 is full");
                }
            Serial.println(count);}
            else 
            
            Serial.println(" -> no vehicle");
        
            delay(1000);
        }


/*fsr 6*/
            if (analogReading6 > 1)       
        {
            count=count+0.5;
            
            count6=count6+0.5;
            
                if (count6>3)
                {
                    Serial.println("The queue 1 is full");
                }
            Serial.println(count);}
            else 
            
            Serial.println(" -> no vehicle");
        
            delay(1000);
        }


/*fsr 7*/

            if (analogReading1 > 1)       
        {
            count=count+0.5;
            
            count7=count7+0.5;
            
            if (count7>3)
                {
                Serial.println("The queue 1 is full");
                }
            Serial.println(count);}
        else 
            
            Serial.println(" -> no vehicle");
        
        delay(1000);
        }
   }  
  
}
