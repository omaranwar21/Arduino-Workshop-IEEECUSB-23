#include <Servo.h>
#include <LiquidCrystal.h>

//////////////////////////////////////////////// Pins ////////////////////////////////////////////////////////////////
#define LED_1_PIN      6
#define LED_2_PIN      7
#define BUZZER_PIN     8
#define SERVO_PIN      11
#define TRIGGER_PIN    12
#define ECHO_PIN       13
#define TEMP_PIN       A0
#define LCD_ROWS       2
#define LCD_COLS       16

LiquidCrystal lcd(10,9,5,4,3,2);
Servo myServo;

////////////////////////////////////////////// Variables ///////////////////////////////////////////////////////////////
float temp = 0;
int distance = 0;
int duration = 0;
int distanceCondition = 20;

void setup() 
{
  LCD_init(LCD_COLS, LCD_ROWS);

  myServo.attach(SERVO_PIN);               // Servo attachinig
  
  pinMode(BUZZER_PIN,OUTPUT);              // Buzzer initialization
  
  LEDs_int(LED_1_PIN, LED_2_PIN);          // LEDS initializations
  
  ULTRASONIC_init(ECHO_PIN, TRIGGER_PIN);  // Ultrasonic initialization

  Serial.begin(9600);

}

void loop() 
{

  for (int i = 0; i <= 180; i++)                             // goes from 0 degrees to 180 degrees (in steps of 1 degree).
  {       
    distance = ULTRASONIC_distance(ECHO_PIN, TRIGGER_PIN);   // get the distance.
    ULTRASONIC_condition(distanceCondition);                 // check the distance condition.
    
    temp = TEMPERATURE_reading(TEMP_PIN);                    // get the temperature.
    TEMPERATURE_condition(36, 50);                           // check the temperature condition.
    myServo.write(i);                                        // tell servo to go to position.

    //Serial.print(distance);                                // use serial.print to send the data in a "text" format to the MIT app.

    // print the temperature on the LCD.
    lcd.setCursor(0,0);
    lcd.print("Temp = ");
    lcd.print(temp);

    delay(15);                                               // waits 15 ms for the servo to reach the position
  }

  for (int i = 180; i >= 0; i--)                             // goes from 180 degrees to 0 degrees (in steps of 1 degree).
  {       
    distance = ULTRASONIC_distance(ECHO_PIN, TRIGGER_PIN);   // get the distance.
    ULTRASONIC_condition(distanceCondition);                 // check the distance condition.
    
    temp = TEMPERATURE_reading(TEMP_PIN);                    // get the temperature.
    TEMPERATURE_condition(36, 50);                           // check the temperature condition.
    myServo.write(i);                                        // tell servo to go to position.

    //Serial.print(distance);                                // use serial.print to send the data in a "text" format to the MIT app.
    
    // print the temperature on the LCD.
    lcd.setCursor(0,0);
    lcd.print("Temp = ");
    lcd.print(temp);
    
    delay(15);                                               // waits 15 ms for the servo to reach the position.
  }
}

/* Function to initialize the LEDs pins as OUTPUT */
void LEDs_int(int led_1, int led_2)
{
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
}

/* Function to initialize the TRIG pin as OUTPUT and ECHO pin as INPUT */
void ULTRASONIC_init(int echo_pin, int trigger_pin)
{
  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
}

/* Function to calculate the distance and return it */
int ULTRASONIC_distance(int echo_pin, int trigger_pin)
{
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  distance = (0.0343)*(duration/2);

  return distance;  
}

/* Function to initialize the LCD */
void LCD_init(int no_cols, int no_rows)
{
  lcd.begin(no_cols, no_rows);
  lcd.setCursor(0,0);
}

/* Function to calculate the temperature and return it */
float TEMPERATURE_reading(int temp_pin)
{
  temp = analogRead(temp_pin);
  //temp = temp * 0.488 ;
  temp = map(temp,0,1023,0,100);
  return temp; 
}

/* Function to change the state of the LED (HIGH or LOW) */
void LED_state(int led_pin, int state)
{
  digitalWrite(led_pin, state);
}

/* Function to activate the buzzer with the required frequency */
void BUZZER(int buzzer_pin, int frequencey)
{
  tone(buzzer_pin, frequencey);
  delay(100);

  noTone(buzzer_pin);
  delay(100);
}

/* Function to check the temperature condition and then take an action according to the condition */
void TEMPERATURE_condition(int condition_1, int condition_2)
{
  if( temp < condition_1 || temp > condition_2 )
  {
    BUZZER(BUZZER_PIN, 100);

    LED_state(LED_2_PIN,HIGH);    
  }
  else
  {
    LED_state(LED_2_PIN,LOW);
  }
}

/* Function to check the distance condition and then take an action according to the condition */
void ULTRASONIC_condition(int distance_condition)
{
  if( distance < distance_condition)
  {
    BUZZER(BUZZER_PIN, 400);

    LED_state(LED_1_PIN,HIGH);
  }
  else
  {
    LED_state(LED_1_PIN,LOW);
  }
}