#include <SR04.h>

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
SR04 sr04 = SR04(6,7);
long dist;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}
int x = 0;
void loop() {
  // put your main code here, to run repeatedly:
  dist = sr04.Distance();
  if(dist<10){
    lcd.print("STOP");
    x=0;
  }
  else{if(dist<25){
    lcd.print("BRAKE");
    if(x>0){
      x-=3;
    }
    if(x<0){
      x=0;
    }
  }
  else{
    lcd.print("ACCEL");
    x+=1;
    if(x>30){
      x=30;
    }
  }}
  lcd.setCursor(0, 1);
  lcd.print("MPH:" + String(x));
  lcd.setCursor(7,1);
  if(dist>1000){
    lcd.print("DTO:NF");
  }
  else{
  lcd.print("DTO:"+ String(dist)+"cm");
  }
  delay(200);
  lcd.clear();
}
