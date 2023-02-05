#define buzzerPin  8

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
}

void loop() 
{
  /* tone function take 3 parameters 
  ( the pin , frequency , duration (used instead of the delay) )
  NOTE :: the third parameter is optional.
  */
  tone(buzzerPin, 1000);
  delay(500);
  
  /* noTone is a function to turn off the buzzer */
  noTone(buzzerPin);
  delay(500);
}
