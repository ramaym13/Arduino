#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int button1 = 10;
int button2 = 9;
int button3 = 8;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button1) == LOW){
    lcd.print("Tombol 1 Ditekan");
  }
  if(digitalRead(button2) == LOW){
    lcd.print("Tombol 2 Ditekan");
  }
  if(digitalRead(button3) == LOW){
    lcd.clear();
  }
}
