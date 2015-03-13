/**
 * Code to selectively activate the water pump based on the moisture levels
 * of the plant's pot.
 */

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

int highPin = 4;
int high_level = 0; //variable to store whether water level is above the high mark

int mediumPin = 7;
int medium_level = 0; //variable to store whether water level is above the medium mark

int lowPin = 10;
int low_level = 0; //variable to store whether water level is above the low mark

int pumpPin = 2;

/* Initialize pins */
void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(highPin, INPUT_PULLUP);
  pinMode(mediumPin, INPUT);
  pinMode(lowPin, INPUT); 
  
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
}

/* Helper method to activate pump */
void waterForNSeconds(nSeconds) { 
  digitalWrite(pumpPin, HIGH);
  delay(nSeconds * 1000);
  digitalWrite(pumpPin, LOW);
}

/* Main control loop. */
void loop()
{
  // read value from soil moisture sensor:
  sensorValue = analogRead(sensorPin);    
  
  delay(1000);          
  
  Serial.print("sensor = " );                       
  Serial.println(sensorValue);  
  
  if (sensorValue < 300) { 
    Serial.println("Soil is dry!");
    waterForNSeconds(1);
  } else if (sensorValue < 700)
    Serial.println("Soil is of medium humidity!");
  else 
    Serial.println("Soil is wet!");  
  
  //read value from water-level sensor
  high_level = digitalRead(highPin);
  medium_level = digitalRead(mediumPin);
  low_level = digitalRead(lowPin);
  
  Serial.println("**********************************");
  
  Serial.print("High level: ");
  Serial.println(high_level);
  
  Serial.print("Medium level: ");
  Serial.println(medium_level);
  
  Serial.print("Low level: ");
  Serial.println(low_level);
  
  Serial.println("**********************************");
  
  if (!high_level && !medium_level && low_level) 
    Serial.println("Water getting low!");
  else if (!high_level && !medium_level && !low_level)
    Serial.println("Water low!");
    
  Serial.println("**********************************");
  Serial.println("**********************************");
}

