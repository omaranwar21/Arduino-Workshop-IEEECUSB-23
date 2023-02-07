
/*Bluetooth module*/


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





