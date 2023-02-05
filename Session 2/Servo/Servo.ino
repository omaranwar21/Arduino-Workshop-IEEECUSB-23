#include <Servo.h>

#define servoPin  9

Servo myServo;                   // create object called myServo

void setup() 
{
    myServo.attach(servoPin);    // pin declaration (like pinMode)
}

void loop() 
{
  myServo.write(0);              // tell the servo to go to angle 0
  delay(15);                     // wait 15 ms
                 
  myServo.write(180);            // tell the servo to go to angle 180
  delay(15);                     // wait 15 ms
}
