


/* lm35 part*/

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


}
