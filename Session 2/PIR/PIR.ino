// define pins
#define ledPin        5
#define sensorPin     2

int state = LOW;             // by default, no motion detected
int value = 0;               // variable to store the sensor status (value)

void setup() 
{
  pinMode(ledPin, OUTPUT);      // initalize LED as an output
  pinMode(sensorPin, INPUT);    // initialize sensor as an input
  Serial.begin(9600);           // initialize serial
}

void loop()
{
  value = digitalRead(sensorPin);            // read sensor value
  if (value == HIGH)                         // check if the sensor is HIGH
  {          
    digitalWrite(ledPin, HIGH);              // turn LED ON
    delay(100);                              // delay 100 ms
    
    if (state == LOW) 
    {
      Serial.println("Motion detected!");
      state = HIGH;                          // update variable state to HIGH
    }
  } 
  else 
  {
      digitalWrite(ledPin, LOW);             // turn LED OFF
      delay(200);                            // delay 200 ms 
      
      if (state == HIGH)
      {
        Serial.println("Motion stopped!");
        state = LOW;                         // update variable state to LOW
    }
  }
}
