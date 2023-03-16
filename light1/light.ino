int r=13;
int a=12;
int g=11;
int redDelay;
int greenDelay;
int amberBlink;

void redState()
    {
        digitalWrite(r, HIGH);
        digitalWrite(a, LOW);
        delay(redDelay); // Wait for 3000 millisecond(s)
    }

void amberState()
    {
        digitalWrite(a, HIGH);
        digitalWrite(g, LOW);
        delay(1000); // Wait for 1000 millisecond(s)
     
    }


void greenState()
      {
        digitalWrite(r, LOW);
        digitalWrite(a, LOW);
        digitalWrite(g, HIGH);
        delay(greenDelay); // Wait for 3000 millisecond(s)
        
      }

void blinkAmberState(){
  digitalWrite(r,LOW);
  digitalWrite(g,LOW);
  for(int i=0; i<amberBlink; i++){
    digitalWrite(a,HIGH);
    delay(1000);
    digitalWrite(a,LOW);
  }
}


void redAmberBlink()
      {
        // Red + Blinking Amber
        digitalWrite(r, HIGH);
        digitalWrite(g, LOW);
          for (int i = 0; i < 3; i++) 
          {
              digitalWrite(a, HIGH);
              delay(500); // Wait for 500 millisecond(s)
              digitalWrite(a, LOW);
              delay(500); // Wait for 500 millisecond(s)
          }
      }

void setup()
{
  pinMode(r, OUTPUT); // Red LED
  pinMode(a, OUTPUT); // Amber LED
  pinMode(g, OUTPUT); // Green LED
}
 
void loop()
{
//Generate random numbers for reddelay and green delay
//Call the functions  

  
}
