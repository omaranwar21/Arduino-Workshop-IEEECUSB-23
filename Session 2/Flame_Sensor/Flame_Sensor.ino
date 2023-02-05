// define pins
#define ledPin     5    
#define sensorPin  2

int digitalValue;             // variable to store digital readings

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}
void loop()
{
  
  digitalValue = digitalRead(sensorPin);         // Read the digital interface 
  if(digitalValue == HIGH)                       // if flame is detected
  {
    digitalWrite(ledPin, HIGH);                   // turn ON the LED
  }
  else
  {
    digitalWrite(ledPin, LOW);                    // turn OFF the LED
  }
  delay(100);
}
