#include "DHT.h"
#define DHTPIN 2
#define DHTYPE DHT11
DHT dht(DHTPIN,DHTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}
void loop() {
 
  delay(2000);
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  Serial.println("HUMIDITY ");
  Serial.println(h);
  
  Serial.print("TEMPERATURE");
  Serial.println(t);

}
