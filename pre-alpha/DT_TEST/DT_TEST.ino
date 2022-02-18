#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}
int x = 0;
void loop() {
  // put your main code here, to run repeatedly:
  lcd.print("HELLO WORLD!");
  lcd.setCursor(0, 1);
  lcd.print(String(x));
  lcd.setCursor(2,1);
  if(x<26){
    lcd.print("Residential");
  }
  else{if(x<45){
    lcd.print("Road");
  }
  else{if(x<75){
    lcd.print("HIGHWAY");
  }
  else{
    lcd.print("UR SPEEDIN");
  }
  }}
  x+=1;
  if(x==100){x=0;}
  delay(200);
  lcd.clear();
}
