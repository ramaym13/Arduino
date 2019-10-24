//const int ledPin = 4; // pin the LED is connected to
//void setup(){
//  Serial.begin(9600);
//  Serial.print ("***** SELAMAT DATANG*****");
//  Serial.println ();
//  Serial.print ("Masukkan angka 1-2, untuk mengaktifkan ");
//  Serial.println ();
//  Serial.print ("dan menonaktifkan LED."); Serial.println ();
//  Serial.println ();
//  Serial.print ("__________MENU________"); Serial.println (); 
//  Serial.print("| 1. LED Hidup |"); Serial.println ();
//  Serial.print ("| 2. LED Mati |"); Serial.println ();
//  Serial.print ("______________________"); Serial.println ();
//  pinMode(ledPin, OUTPUT); // set this pin as output
//} 
//void loop(){
//  if(Serial.available() > 0){ //read the incoming 
//    byte tombol = Serial.read() - 48; 
//    if(tombol >= 1 &&tombol <= 2){ 
//      Serial.print("Input Pilihan: ");
//      Serial.println(tombol);
//      
//      switch(tombol){ 
//        case 1:
//          digitalWrite(ledPin, HIGH);
//          break; 
//        case 2:
//          digitalWrite(ledPin, LOW); 
//          break;
//      }
//    }
//  }
//} 

//char datachar;
//void setup(){
//  Serial.begin(9600);
//  Serial.println("15, BIN");
//} 
//void loop(){
//  
////  if ( Serial.available() > 0)
////  {
////    datachar = Serial.read(); 
////    Serial.print("670.6170000");
////    Serial.println(datachar);
////  }
//}

//
//int led = 4;
//void setup(){
//  Serial.begin(9600);
//  pinMode(led, OUTPUT);
//} 
//void loop(){
//  if ( Serial.available() > 0)
//  {
//    byte datachar = Serial.read()-66;
//    Serial.print("Input Pilihan: ");
//    Serial.println(datachar);
//    switch (datachar){
//      case 22:
//        digitalWrite(led,HIGH);
//        break;
//      case 55:
//        digitalWrite(led,LOW);
//        break;   
//    }
//  }
//}






//void setup(){
//Serial.begin(9600);
//}
// 
//void loop(){
//if(Serial.available() >0){
//byte data = Serial.read()-48;
//Serial.print(670.6170000); 
//Serial.println();
//Serial.print(670.6170000, 1);
//Serial.println();
//Serial.println(15, BIN); 
//Serial.print(10, OCT);
//Serial.println();
//Serial.print(2018, HEX); 
//Serial.println();
//
//Serial.println();
////kirim ke port serial
////Serial.print("Karakter :");
////Serial.print(data);
////Serial.print(", ASCII :");
////Serial.print(15,DEC);
////Serial.print(", Oktal :");
////Serial.print(15, OCT);
////Serial.print(", Heksa :");
////Serial.print(data, HEX);
////Serial.println(15, BIN); //untuk baris pembacaan berikutnya
//delay(20); // waktu tunda untuk menyiapkan pembacaan berikutnya
//}}


const int pingPin = 13;
const int echoPin = 12;

void setup(){
  Serial.begin(9600);
} 
void loop() { 
  long duration, cm;
  pinMode(pingPin,OUTPUT);
  digitalWrite(pingPin,LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin,LOW);
  pinMode(echoPin, INPUT); duration =
  pulseIn(echoPin, HIGH); cm =
  microsecondsToCentimeters(duration);
  
  Serial.print("Jarak :");
  Serial.print("\t");
  Serial.print(cm); 
  Serial.print("cm");
  Serial.println();
  
  delay(500
  ); 
}
long microsecondsToCentimeters(long microseconds){ 
  return microseconds /
  29 / 2;
} 
