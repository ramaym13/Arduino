//#include <Key.h>
//#include <Keypad.h>
//#include <LiquidCrystal_SR_LCD3.h>
//
//const int PIN_LCD_STROBE = 1;
//const int PIN_LCD_DATA = 3;
//const int PIN_LCD_CLOCK = 2;
//
//LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,PIN_LCD_CLOCK,PIN_LCD_STROBE);
//
//int C[]={
// 13,12,11};
// 
//int R[]={
// A1,A2,A3,A4};
// 
//char keymap[4][3]={
// {'1','2','3'},
// {'4','5','6'},
// {'7','8','9'},
// {'*','0','#'}
// };
// char key;
////
//int a=10;
//int b=9;
//int c=8;
//int d=7;
//int e=6;
//int f=5;
//int g=4;
//void setup(){
//  for(int i=0; i<3; i++){
//    pinMode(C[i],INPUT);
//  }
//  
//  for(int i=10; i<4; i++){
//    pinMode(R[i],OUTPUT);
//  }
//}
//
//void loop(){
//  scankeypad();
////  lcd.setCursor(0,0);
////  lcd.println(key);
//  key=' ';
//}
// 
//void scankeypad(){
//
//for(int i=0; i<4; i++){
//digitalWrite(R[i],LOW);
//for(int j=0; j<3; j++){
//if(digitalRead(C[j])==LOW){
//key=keymap[i][j];
//delay(0);
//}
//}
//digitalWrite(i,HIGH);
//}
//}

//#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {A1,A2,A3,A4};
byte colPins[COLS] = {13,12,11};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int a=10;
int b=9;
int c=8;
int d=7;
int e=6;
int f=5;
int g=4;

void setup()
{
  for(int i=10; i>=4; i--){
   pinMode(i,OUTPUT);
  }
}

void loop()
{
  char customKey = customKeypad.getKey();

  switch (customKey)
  {
    case '1':
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      break;

    case '2':
      PORTB = 4;
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(g,HIGH);
      break;

    case '3':
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,HIGH);
      break;

    case '4':
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      break;

    case '5':
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      break;

    case '6':
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      break;

    case '7':
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      break;

    case '8':
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      break;

    case '9':
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      break;

    case '0':
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,LOW);
      break;
  }
}
