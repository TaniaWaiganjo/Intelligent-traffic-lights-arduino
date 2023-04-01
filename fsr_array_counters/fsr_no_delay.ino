const int NUM_SENSORS = 7;
// Analog input pins for each sensor
int sensorPins[NUM_SENSORS] = {0,1,2, 3, 4, 5, 6,}; 

int tempstate[NUM_SENSORS]  ;

int sensorStates[NUM_SENSORS]; // Array to store sensor states (HIGH or LOW)

int sensorCounts[NUM_SENSORS]; // Array to store sensor counts

int currentState[NUM_SENSORS];

//Define analog pins
int fsr[NUM_SENSORS] ={A0,A1,A2,A3,A4,A5,A6,};

void sensors();


void setup() {
  Serial.begin(9600); 
  
  for (int i = 0; i < NUM_SENSORS; i++) {
    sensorPins[i]=fsr[i];
    sensorStates[i] = analogRead(sensorPins[i]); // Initialize sensor states
    sensorCounts[i] = 0; // Initialize sensor counts
    tempstate[i] = 0;
  }
}

void loop() {
  // Update sensor states

   sensors();
            
}


void sensors()
    {
      static unsigned long sensormillis = millis(); // run first time only to read current millis due to use of static

        if (millis() - sensormillis > 100)
        {
           
              for (int i = 0; i < NUM_SENSORS; i++) 
              {
                    currentState[i] = analogRead(sensorPins[i]);
                    if (currentState[i] != tempstate[i]) 
                    {
                        // State has changed, increment count if sensor has been triggered
                        //if (currentState == LOW) {
                            sensorCounts[i]= sensorCounts[i] + 0.5;
                        //}
                        tempstate [i] = currentState [i];
                    }
              }
            
              // Output sensor counts to serial monitor
              for (int i = 0; i < NUM_SENSORS; i++) {
                Serial.print("Sensor ");
                Serial.print(i+1);
                Serial.print(" count: ");
                Serial.println(sensorCounts[i]);
              }


             sensormillis= millis();
            
          } 
        
    }



     
      
