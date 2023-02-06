#define TRIG 13
#define ECHO 12
void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG, LOW);

  int duration = pulseIn(ECHO, HIGH);
  int distance = (0.0343)*(duration/2);
  Serial.println(distance);
  delay(200);
}
