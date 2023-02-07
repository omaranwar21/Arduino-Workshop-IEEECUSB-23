/* serial part*/

int i =1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(i<=5){
    Serial.println("hello world");
    i++;
  }

}





