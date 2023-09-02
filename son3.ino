#include <LiquidCrystal.h>
#include <Servo.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo srv;

void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");

  srv.attach(6);
}

void loop() {
  int controller = map(analogRead(A0), 0,1023,0,180);
  srv.write(controller);
  if(digitalRead(7) == 0){
    ates();
  }
  else{
    OkeyMode();
  }
}

void ates(){
  lcd.clear();
  lcd.print("Ates");
}

void OkeyMode(){
  lcd.clear();
  lcd.print("OK");
}