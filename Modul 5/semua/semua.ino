#include <I2CIO.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal_SR_LCD3.h>

#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE    = 2; 
const int PIN_LCD_DATA      = 4; 
const int PIN_LCD_CLOCK     = 3;

LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA, PIN_LCD_CLOCK, PIN_LCD_STROBE ); 

int calibrationTime = 5; 
long unsigned int lowIn; 
long unsigned int pause = 2000; 
boolean lockLow = true; 
boolean takeLowTime;

int stage = 0;
int pirPin = 12; 
int ledPin = 6; 

int btnPin = 7;
int buzzerPin = 5;

boolean ledIsOn = true;

void setup() {
  Serial.begin(9600); 
  lcd.begin(16, 2);
  pinMode(btnPin, INPUT);
  pinMode(pirPin, INPUT);  
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  digitalWrite(ledPin, LOW); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int beforeStage = stage;
  if(digitalRead(btnPin) == LOW){
    switch(stage){
      case 0:
        calibratePir();
        stage = 1;
        break;
      case 1:
        stage = 2;
        break;
      case 2:
        lockLow = true;   
        stage = 3;
        break;
      case 3:
        lockLow = true;   
         stage = 1;
         break;
    }
  }

  switch(stage){
    case 1:
      //kasus 1
      if(beforeStage != 1){
        Serial.println("PIR Ready");
        printLcd("PIR Ready"); 
        digitalWrite(ledPin, LOW); 
      }
      break;
    case 2:
      if(digitalRead(pirPin) == HIGH){
          
        if(lockLow){
          lockLow = false;
          digitalWrite(buzzerPin, HIGH);
          Serial.println("detected 1");         
          printLcd("detected 1");
          delay(1000);
          digitalWrite(buzzerPin, LOW);   
          delay(1000);
          digitalWrite(btnPin, HIGH);
          delay(50);
          
        }
        takeLowTime = true;
       }     
       if(digitalRead(pirPin) == LOW){   
       
        if(takeLowTime){    
          lowIn = millis();    
          takeLowTime = false;   
          
        }   
        if(!lockLow && millis() - lowIn > pause){
          lockLow = true;   
          Serial.println("Motion ended");
          printLcd("Motion ended");
          digitalWrite(btnPin, LOW);
          delay(50);   
        }  
      } 
      break;
    case 3:
      if(digitalRead(pirPin) == HIGH){
        
        if(lockLow){
          lockLow = false;   
          digitalWrite(ledPin, HIGH); 
          Serial.println("Pergerakan 2");
          printLcd("Pergerakan 2");
          delay(50); 
             
        }
        if(ledIsOn){
            ledIsOn = false;
            digitalWrite(ledPin, LOW); 
            delay(50);
          }else{
            ledIsOn = true;
            digitalWrite(ledPin, HIGH);
            delay(250);
        }
        takeLowTime = true;
       }     
       if(digitalRead(pirPin) == LOW){   
        digitalWrite(ledPin, LOW);   
        if(takeLowTime){    
          lowIn = millis();    
          takeLowTime = false;   
        }   
        if(!lockLow && millis() - lowIn > pause){
          lockLow = true;
          Serial.println("Motion ended2");
          printLcd("Motion ended2");
          digitalWrite(ledPin, LOW); 
          delay(50);   
        }  
      } 
      break;
  }
  delay(250);
}

void calibratePir(){
  Serial.print("Calibrating sensor "); 
  for(int i = 0; i < calibrationTime; i++){    
    Serial.print(".");    
    delay(1000);  
  }    
  Serial.println("Calibrating Finshed "); 
}

void printLcd(String text){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(text);
}
