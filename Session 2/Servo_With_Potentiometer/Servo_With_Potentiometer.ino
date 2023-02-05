#include <Servo.h>
#define potPin  A0
#define servoPin  9

Servo myServo;  // create servo object to control a servo

int value;      // variable to read the value from the analog pin

void setup() 
{
  myServo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
}

void loop() 
{
  value = analogRead(potPin);               // reads the value of the potentiometer (value between 0 and 1023)
  value = map(value , 0, 1023, 0, 180);     // map (scale) it for use with the servo (value between 0 and 180)
  myServo.write(value);                     // sets the servo position according to the mapped (scaled) value
  delay(200);                               // waits for the servo to get there
}
