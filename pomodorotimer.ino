#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int minutes = 0;
int seconds = 0;
int count = 0;

const int studytime = 25;
const int breaktime = 5;
const int longbreak = 15;
const int repeat = 4;

#define buzzer 3
#define switch 2
#define gled 4
#define bled 5

void setup() {
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(buzzer,OUTPUT);
  pinMode(switch,INPUT_PULLUP);
}
void loop() {
    digitalWrite(bled,HIGH);
    lcd.setCursor(2,0);
    lcd.print("Press Button");
    lcd.setCursor(4,1);
    lcd.print("To Start");
    int switchval = digitalRead(switch);
    if(switchval == LOW){
      lcd.clear();
      tone();
      bledblnk();
      for(int i = 0;i<repeat;i++){
        studytimefun();
        finaltone();
        if(i<(repeat-1)){
          delay(1500);
          breaktimefun();
          finaltone();
          delay(1500);
        }
      }
      delay(1000);
      longbreakfun();
      finaltone();
      lcd.clear();
      delay(1000);
    }
}
void tone(){
  digitalWrite(buzzer,HIGH);
  delay(60);
  digitalWrite(buzzer,LOW);
}
void finaltone(){
  for(int i = 0;i<8;i++){
    delay(100);
    digitalWrite(buzzer,HIGH);
    digitalWrite(bled,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    digitalWrite(bled,LOW);
  }
}
void studytimefun(){
  digitalWrite(gled,HIGH);
  lcd.clear();
  lcd.print("Study Time!");
  minutes = 0;
  seconds = 0;
  delay(500);
  while(minutes<studytime){
    seconds = 0;
    while(seconds<60){
      lcd.setCursor(0, 1);
      if(minutes<10){
        lcd.print("0");
      }
      lcd.print(minutes);
      lcd.print(":");
      if(seconds<10){ 
        lcd.print("0");
      }
      lcd.print(seconds);
      delay(10);
      seconds++;
    }
    minutes++;
  }
  digitalWrite(gled,LOW);
}
void breaktimefun(){
  digitalWrite(gled,HIGH);
  lcd.clear();
  lcd.print("Break Time!");
  minutes = 0;
  seconds = 0;
  delay(500);
  while(minutes<breaktime){
    seconds = 0;
    while(seconds<60){
      lcd.setCursor(0, 1);
      if(minutes<10){
        lcd.print("0");
      }
      lcd.print(minutes);
      lcd.print(":");
      if(seconds<10){
        lcd.print("0");
      }
      lcd.print(seconds);
      delay(10);
      seconds++;
    }
    minutes++;
  }
  digitalWrite(gled,LOW);
}
void longbreakfun(){
  digitalWrite(gled,HIGH);
  lcd.clear();
  lcd.print("Long Break");
  minutes = 0;
  seconds = 0;
  delay(500);
  while(minutes<longbreak){
    seconds = 0;
    while(seconds<60){
      lcd.setCursor(0,1);
      if(minutes<10){
        lcd.print("0");
      }
      lcd.print(minutes);
      lcd.print(":");
      if(seconds<10){
        lcd.print("0");
      }
      lcd.print(seconds);
      delay(10);
      seconds++;
    }
    minutes++;
  }
  digitalWrite(gled,LOW);
}
void bledblnk(){
  for(int i = 0;i<5;i++){
    digitalWrite(bled,HIGH);
    delay(80);
    digitalWrite(bled,LOW);
    delay(80);
  }
  delay(1000);
}