#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("PB Sensor");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int positionCounter = 0; positionCounter <13; positionCounter++){
    lcd.scrollDisplayLeft();
    delay(150);
  }

  for(int positionCounter = 0; positionCounter<29; positionCounter++){
    lcd.scrollDisplayRight();
    delay(150);
  }

  for(int positionCounter = 0; positionCounter<16; positionCounter++){
    lcd.scrollDisplayLeft();
    delay(150);
  }
}
