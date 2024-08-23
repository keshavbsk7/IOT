#include<LiquidCrystal.h>
int contrast=75;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  
  analogWrite(6,contrast);
  lcd.begin(16,2);
}

void loop() {
 
  lcd.setCursor(0,0);
  lcd.print("MATHIOLI");
  lcd.setCursor(0,1);
  lcd.print("KESHAV");
}
