#include <LiquidCrystal.h>

/* serial part*/

// int i =1;


// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);

// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   while(i<=50){
//     Serial.println(i);
//     i++;
//   }

// }


/***********************************************************************************
************************************************************************************
***********************************************************************************/

/* lm35 part*/
/*
float temp ;
char sensorPin =A0;
char fanPin=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(fanPin , OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   temp = analogRead(sensorPin);  //Read Temperature 
  temp = (temp * 4.88); // Convert adc value to equivalent voltage 
  temp = (temp/10); // LM35 gives output of 10mv/°C 
  Serial.print("Temperature = ");
  Serial.print(temp);
  if(temp>24){
     digitalWrite(fanPin ,HIGH);
  }
  else{
    digitalWrite(fanPin,LOW);
  }
delay(200);

}
*/

/***********************************************************************************
************************************************************************************
***********************************************************************************/
/*LDR part*/

char ldrPin=A0; //Set Analog Input A0 for LDR.
char ledPin=2;
void setup() {
Serial.begin(9600);
pinMode(ledPin,OUTPUT);
}

void loop() {
int value=analogRead(ldrPin);//Reads the Value of LDR(light).
Serial.println("LDR value is :");//Prints the value of LDR to Serial Monitor.
Serial.println(value);
if(value>300)
  {
    digitalWrite(ledPin,HIGH);//The LED turns ON in Dark.
  }
  else
  {
    digitalWrite(ledPin,LOW);//The LED turns OFF in Light.
  }
}



/***********************************************************************************
************************************************************************************
***********************************************************************************/
/*Bluetooth module*/

/*
char led= 13;
char input;
void setup() {
pinMode(led, OUTPUT); 
Serial.begin(9600);
}

void loop() {
if (Serial.available())
{
    input= Serial.read();   // reading data recieved from Bluetooth module
    switch (input)
    {
       case 'a': //when a is pressed on the app 
          digitalWrite(led, HIGH);
          break; 
       case 'b': //when a is pressed on the app
          digitalWrite (led, LOW);
          break;
    }

    Serial.println(input);
}
delay (50);
}
*/




