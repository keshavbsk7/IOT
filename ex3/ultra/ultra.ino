#define TRIG_PIN 3
#define ECHO_PIN 2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long d;
  int dist;
  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN,LOW);
  d=pulseIn(ECHO_PIN,HIGH);
  dist=d*0.034/2;
  Serial.println("Distance in CM");
  Serial.println(dist);
  delay(1000);

}
