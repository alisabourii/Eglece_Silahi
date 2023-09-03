#include <LiquidCrystal.h>
#include <Servo.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo srv;

const int echo = 8;
const int trig = 9;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("hello, world!");

  srv.attach(6);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
   show();
  int controller = map(analogRead(A0), 0,1023,0,180);
  srv.write(controller);
  if(digitalRead(7) == 0){
    ates();
  }
}

void ates(){
  
  lcd.clear();
  lcd.print("Ates");
}

void show(){
  lcd.clear();
  lcd.print(Distance());
  delay(100);
}

int Distance(){
  digitalWrite(trig,1);  delay(10);
  digitalWrite(trig,0);

  int time = pulseIn(echo,1);
  int dis = (time/2)/28.97;
  return dis;
}
