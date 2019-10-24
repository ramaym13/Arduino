#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE    = 2; 
const int PIN_LCD_DATA      = 4; 
const int PIN_LCD_CLOCK     = 3;

LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA, PIN_LCD_CLOCK, PIN_LCD_STROBE ); 

//int calibrationTime = 5; 
//long unsigned int lowIn; 
//long unsigned int pause = 2000; 
//boolean lockLow = true; 
//boolean takeLowTime;
int nomor = 0;
int stage = 0;
int pirPin = 12; //echo
int pingPin = 13;
int ledPin = 6; 
long duration, cm; 
int btnPin = 7;
int buzzerPin = A5;

boolean ledIsOn = true;

void setup() {
  Serial.begin(9600); 
  lcd.begin(16, 2);
  pinMode(btnPin, INPUT);
  pinMode(pirPin, INPUT); 
  pinMode(pingPin, OUTPUT); 
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  digitalWrite(ledPin, LOW); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int beforeStage = stage;
    if(digitalRead(btnPin) == LOW){
      nomor +=1;
      delay(1000);
    }
      
    
 long duration, cm; 
  switch(nomor){
    case 1:

     pinMode(pingPin, OUTPUT); 
      digitalWrite(pingPin, LOW); 
      delayMicroseconds(2); 
      digitalWrite(pingPin, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(pingPin, LOW);
        duration = pulseIn(pirPin, HIGH); 
      cm = microsecondsToCentimeters(duration); 
      Serial.print("Jarak :");  
      Serial.print("\t"); 
      Serial.print(cm); 
      Serial.print("cm");
      lcd.print("Jarak :");  
      lcd.print("\t"); 
      lcd.print(cm); 
      lcd.print("cm");
      Serial.println();
      delay(1000); 
      break;
     case 2:
     
      pinMode(pingPin, OUTPUT); 
      digitalWrite(pingPin, LOW); 
      delayMicroseconds(2); 
      digitalWrite(pingPin, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(pingPin, LOW);
      duration = pulseIn(pirPin, HIGH); 
      cm = microsecondsToCentimeters(duration);     
      Serial.print("Jarak :");  
      lcd.print("Jarak :"); 
      Serial.print("\t"); 
      lcd.print("\t"); 
      Serial.print(cm); 
      lcd.print(cm); 
      Serial.print("cm");
      lcd.print("cm");   
      Serial.println();    
      delay(500); 
      if(cm > 10){
        digitalWrite(buzzerPin, HIGH);
        lcd.print("aman guys");
        Serial.println("aman");
        delay(1000);
        }
        
         digitalWrite(buzzerPin, LOW);
      break;

      case 3:
      Serial.print("masuk 3"); 
      pinMode(pingPin, OUTPUT); 
      digitalWrite(pingPin, LOW); 
      delayMicroseconds(2); 
      digitalWrite(pingPin, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(pingPin, LOW);
        duration = pulseIn(pirPin, HIGH); 
      cm = microsecondsToCentimeters(duration);     
      Serial.print("Jarak :");  
      lcd.print("Jarak :"); 
      Serial.print("\t"); 
      lcd.print("\t"); 
      Serial.print(cm); 
      lcd.print(cm); 
      Serial.print("cm");
      lcd.print("cm");   
      Serial.println();    
      delay(500); 
      if(cm > 10){
        digitalWrite(ledPin, LOW);
        lcd.print("aman guys");
        }else{
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);  
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
        }
//          int i;
//          for (i=0; i<=255; i+=5){
//            digitalWrite(ledPin, i);
//            delay(100);
//            }
//            for (i=255; i>=0; i-=5){
//              digitalWrite(ledPin,i);
//              delay(100);       }
//          }
//          digitalWrite(ledPin, LOW);
      break;

      case 4:
        nomor=1;
      break;

  }
}


void printLcd(String text){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(text);
}
long microsecondsToCentimeters(long microseconds)  { 
  return microseconds / 
  29 / 2;  
  }
