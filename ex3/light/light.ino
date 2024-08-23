#define LDR_PIN A4
void setup() {
    // put your setup code here, to run once:
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  int idrval=analogRead(LDR_PIN);
  Serial.print("Light Intensity ");
  Serial.println(idrval);
  delay(1000);

}
