
/*LDR part*/

char ldrPin=A0; //Set Analog Input A0 for LDR.
char ledPin=2;
void setup() {
Serial.begin(9600);
pinMode(LED,OUTPUT);
}

void loop() {
int value=analogRead(ldrPin);//Reads the Value of LDR(light).
Serial.println("LDR value is :");//Prints the value of LDR to Serial Monitor.
Serial.println(value);
if(value<300)
  {
    digitalWrite(ledPin,HIGH);//The LED turns ON in Dark.
  }
  else
  {
    digitalWrite(ledPin,LOW);//The LED turns OFF in Light.
  }
}
