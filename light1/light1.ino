int r=11;
int a=12;
int g=13;

int r1=8;
int a1=9;
int g1=10;

int r2=5;
int a2=6;
int g2=7;

int r3=2;
int a3=3;
int g3=4;



void redstate(){
  
}

void setup()
{
  pinMode(r, OUTPUT); // Red LED
  pinMode(a, OUTPUT); // Amber LED
  pinMode(g, OUTPUT); // Green LED
  pinMode(r1, OUTPUT); // Red LED
  pinMode(a1, OUTPUT); // Amber LED
  pinMode(g1, OUTPUT); // Green LED
  pinMode(r2, OUTPUT); // Red LED
  pinMode(a2, OUTPUT); // Amber LED
  pinMode(g2, OUTPUT); // Green LED
  pinMode(r3, OUTPUT); // Red LED
  pinMode(a3, OUTPUT); // Amber LED
  pinMode(g3, OUTPUT); // Green LED
}
 
void loop()
{
  // Green
  digitalWrite(r, LOW);
  digitalWrite(a, LOW);
  digitalWrite(g, HIGH);
  delay(3000); // Wait for 3000 millisecond(s)
  
  // Amber
  digitalWrite(a, HIGH);
  digitalWrite(g, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
 
  // Red
  digitalWrite(r, HIGH);
  digitalWrite(a, LOW);
  delay(3000); // Wait for 3000 millisecond(s)
 
  // Red + Blinking Amber
  digitalWrite(r, HIGH);
  digitalWrite(g, LOW);
  for (int i = 0; i < 3; i++) {
    digitalWrite(a, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(a, LOW);
    delay(500); // Wait for 500 millisecond(s)
  }




   // Green
  digitalWrite(r1, LOW);
  digitalWrite(a1, LOW);
  digitalWrite(g1, HIGH);
  delay(3000); // Wait for 3000 millisecond(s)
  
  // Amber
  digitalWrite(a1, HIGH);
  digitalWrite(g1, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
 
  // Red
  digitalWrite(r1, HIGH);
  digitalWrite(a1, LOW);
  delay(3000); // Wait for 3000 millisecond(s)
 
  // Red + Blinking Amber
  digitalWrite(r1, HIGH);
  digitalWrite(g1, LOW);
  for (int i = 0; i < 3; i++) {
    digitalWrite(a1, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(a1, LOW);
    delay(500); // Wait for 500 millisecond(s)
  }





  // Green
  digitalWrite(r2, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(g2, HIGH);
  delay(3000); // Wait for 3000 millisecond(s)
  
  // Amber
  digitalWrite(a2, HIGH);
  digitalWrite(g2,LOW);// Wait for 1000 millisecond(s)
 
  // Red
  digitalWrite(r2, HIGH);
  digitalWrite(a2, LOW);
  delay(3000); // Wait for 3000 millisecond(s)
 
  // Red + Blinking Amber
  digitalWrite(r2, HIGH);
  digitalWrite(g2, LOW);
  for (int i = 0; i < 3; i++) {
    digitalWrite(a2, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(a2, LOW);
    delay(500); // Wait for 500 millisecond(s)
  }



  // Green
  digitalWrite(r3, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(g3, HIGH);
  delay(3000); // Wait for 3000 millisecond(s)
  
  // Amber
  digitalWrite(a3, HIGH);
  digitalWrite(g3, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
 
  // Red
  digitalWrite(r3, HIGH);
  digitalWrite(a3, LOW);
  delay(3000); // Wait for 3000 millisecond(s)
 
  // Red + Blinking Amber
  digitalWrite(r3, HIGH);
  digitalWrite(g3, LOW);
  for (int i = 0; i < 3; i++) {
    digitalWrite(a3, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(a3, LOW);
    delay(500); // Wait for 500 millisecond(s)
  }
}
