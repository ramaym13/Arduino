const int ledPin4 = 4;
const int ledPin3 = 3;
const int ledPin2 = 2;
const int pingPin = 13;
const int echoPin = 12;
const int buzzerPin = A4;
void setup(){
  Serial.begin(9600);
  Serial.print ("___________PBS 2019___________");
  Serial.println ();
  Serial.print ("________NIM:6706174021________");
  Serial.println ();
  Serial.print ("_____________MENU_____________"); Serial.println (); 
  Serial.print("| 1. Automatic Traffic Light |"); Serial.println ();
  Serial.print ("| 2. Manual Traffic Light    |"); Serial.println ();
  Serial.print ("| 3. Sensor Ultrasonic       |"); Serial.println ();
  Serial.print ("| 4. Kembali ke menu         |"); Serial.println ();
  Serial.print ("______________________________"); Serial.println ();
  pinMode(ledPin4, OUTPUT); // set this pin as output
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(pingPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
} 
long microsecondsToCentimeters(long microseconds)  { 
  return microseconds / 29 / 2;  
}
void loop(){ 
  if(Serial.available() > 0){ //read the incoming 
    byte tombol = Serial.read() - 48;
     
    if(tombol >= 1 &&tombol <= 4){
      Serial.print("Input Pilihan: ");
      Serial.println(tombol);
      switch(tombol){ 
        case 1:
          Serial.print("| 1. Automatic Traffic Light |"); Serial.println ();
          digitalWrite(ledPin4, HIGH);
          delay(250);
          digitalWrite(ledPin4, LOW);
          delay(250);
          digitalWrite(ledPin3, HIGH);
          delay(250);
          digitalWrite(ledPin3, LOW);
          delay(250);
          digitalWrite(ledPin2, HIGH);
          delay(250);
          digitalWrite(ledPin2, LOW);
          delay(250);
          digitalWrite(ledPin4, HIGH);
          delay(250);
          digitalWrite(ledPin4, LOW);
          delay(250);
          digitalWrite(ledPin3, HIGH);
          delay(250);
          digitalWrite(ledPin3, LOW);
          delay(250);
          digitalWrite(ledPin2, HIGH);
          delay(250);
          digitalWrite(ledPin2, LOW);
          delay(250);
          digitalWrite(ledPin4, HIGH);
          delay(250);
          digitalWrite(ledPin4, LOW);
          delay(250);
          digitalWrite(ledPin3, HIGH);
          delay(250);
          digitalWrite(ledPin3, LOW);
          delay(250);
          digitalWrite(ledPin2, HIGH);
          delay(250);
          digitalWrite(ledPin2, LOW);
          delay(250);
          break;
        case 2:
          break;
        case 3:
        
          long duration, cm;
          pinMode(pingPin, OUTPUT); 
          digitalWrite(pingPin, LOW); 
          delayMicroseconds(2); 
          digitalWrite(pingPin, HIGH); 
          delayMicroseconds(10); 
          digitalWrite(pingPin, LOW);
          duration = pulseIn(echoPin, HIGH); 
          cm = microsecondsToCentimeters(duration);  
             
           
          if(cm < 50){
            Serial.print("Jarak :");   
            Serial.print("\t"); 
            Serial.print(cm); 
            Serial.print("cm"); 
            Serial.println();    
            delay(500);
            Serial.println("Buzzer Active!");
            delay(1000);
            digitalWrite(buzzerPin, HIGH);
            delay(5000);
          }else{
            digitalWrite(buzzerPin, LOW);
            Serial.print("Jarak :");   
            Serial.print("\t"); 
            Serial.print(cm); 
            Serial.print("cm"); 
            Serial.println();    
            delay(500);
          } 
          break;
          
        case 4:
          Serial.print ("___________PBS 2019___________");
          Serial.println ();
          Serial.print ("________NIM:6706174021________");
          Serial.println ();
          Serial.print ("_____________MENU_____________"); Serial.println (); 
          Serial.print("| 1. Automatic Traffic Light |"); Serial.println ();
          Serial.print ("| 2. Manual Traffic Light    |"); Serial.println ();
          Serial.print ("| 3. Sensor Ultrasonic       |"); Serial.println ();
          Serial.print ("| 4. Kembali ke menu         |"); Serial.println ();
          Serial.print ("______________________________"); Serial.println ();
          break;
      }
    }
  }
} 
