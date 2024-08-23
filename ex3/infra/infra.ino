#define IR_PIN 3
void setup() {
    // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR_PIN,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val=digitalRead(IR_PIN);
  if(val==HIGH)
  {
     Serial.println("Not Detected");
  }else{
     
     Serial.println("Object Detected");
  }
  
 
  delay(1000);

}
