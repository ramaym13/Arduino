#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int button1 = 10;
int button2 = 9;
int i;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("PB Sensor");
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button1) == LOW){
    for(i = 0; i < 13; i++){
      lcd.scrollDisplayRight();
      delay(150); 
    }
  }

  if(digitalRead(button2) == LOW){
    for(i = 0; i < 13; i++){
      lcd.scrollDisplayLeft();
      delay(150);
    }
  }
}
