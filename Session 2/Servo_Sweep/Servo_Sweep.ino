#include <Servo.h>
#define servoPin   9

Servo myServo;       // create servo object to control a servo

void setup() 
{
  myServo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}

void loop() 
{
  for (int i = 0; i <= 180; i++)         // goes from 0 degrees to 180 degrees (in steps of 1 degree)
  {       
    myServo.write(i);                    // tell servo to go to position
    delay(15);                           // waits 15 ms for the servo to reach the position
  }

  for (int i = 180; i >= 0; i--)         // goes from 180 degrees to 0 degrees
  {       
    myServo.write(i);                    // tell servo to go to position
    delay(15);                           // waits 15 ms for the servo to reach the position
  }
}