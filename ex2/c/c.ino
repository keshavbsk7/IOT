void setup() {
  pinMode(12,OUTPUT);
  Serial.begin(9600); 

}

void loop() {
  int a=analogRead(A0);
  Serial.println(a);
  if(a<512){
  digitalWrite(12,HIGH);
  Serial.println("ON");
  }
  else{
    digitalWrite(12,LOW);
    Serial.println("OFF");
  }
  delay(1000);
}
