#include <Keyboard.h>

#include <LiquidCrystal_SR_LCD3.h>

const int PIN_LCD_STROBE = 1;
const int PIN_LCD_DATA = 3;
const int PIN_LCD_CLOCK = 2;

LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,PIN_LCD_CLOCK,PIN_LCD_STROBE);
//
//void setup(){
//  lcd.begin(16,2);
//  lcd.setCursor(0,0);
//  lcd.println("bgst");
//}
//
//void loop(){
//  
//}

int C[]={
 13,12,11};
 
int R[]={
 A1,A2,A3,A4};
 
char keymap[4][3]={
 {'1','2','3'},
 {'4','5','6'},
 {'7','8','9'},
 {'*','0','#'}
 };
 char key;
 
 void setup(){
  
 for(int i=0; i<3; i++){
 pinMode(C[i],INPUT);
 }
 
 for(int i=0; i<4; i++){
 pinMode(R[i],OUTPUT);
 }
 lcd.begin(16,2);
 
 }

 void loop(){
  
 scankeypad();
 lcd.setCursor(0,0);
 lcd.println(key);
 key=' ';
 
 }
 
 void scankeypad(){
  
 for(int i=0; i<4; i++){
 digitalWrite(R[i],LOW);
 for(int j=0; j<3; j++){
 if(digitalRead(C[j])==LOW){
 key=keymap[i][j];
 delay(500);
 }
}
  digitalWrite(R[i],HIGH);
  }
}
