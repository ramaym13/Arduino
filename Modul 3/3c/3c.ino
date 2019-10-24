#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int button1 = 10;
int i;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Hallo");
  Serial.begin(9600);
  pinMode(button1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button1) == LOW){
    if(Serial.available()){
      lcd.clear();
      delay(100);
      while(Serial.available() > 0){
        lcd.write(Serial.read());
      } 
    }
    for(i = 0; i < 13; i++){
      lcd.scrollDisplayRight();
      delay(150);
    }
  }
}
