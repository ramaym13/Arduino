int button = 0;
boolean isManual = false;
int ledColor = 0;

const int ledRed = 4;
const int ledYellow = 3;
const int ledGreen = 2;

const int pingPin = 13;
const int echoPin = 12;
const int buzzerPin = A4;

void setup() {
  Serial.begin(9600);
  Serial.print("___________PBS2019____________");
  Serial.println();
  Serial.print("_______NIM:6706174044_________");
  Serial.println();
  Serial.print("| 1. Automatic Traffic Light |");
  Serial.println();
  Serial.print("| 2. Manual Traffic Light    |");
  Serial.println();
  Serial.print("| 3. Sensor Ultrasonic       |");
  Serial.println();
  Serial.print("| 4. Kembali ke menu         |");
  Serial.println();
  Serial.print("______________________________");
  Serial.println();
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}
long microsecondsToCentimeters(long microseconds)  { 
  return microseconds / 29 / 2;  
}
void loop() {
  if (Serial.available() > 0) {
    button = Serial.read() - 48;

    if (button >= 1 && button <= 4) {
      Serial.print("Input pilihan: ");
      Serial.println(button);

      if (!isManual && button == 1) {
        digitalWrite(ledRed, HIGH);
        delay(500);
        digitalWrite(ledRed, LOW);
        digitalWrite(ledYellow, HIGH);
        delay(500);
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledGreen, HIGH);
        delay(500);
        digitalWrite(ledGreen, LOW);
      } else if (button == 2) {
        isManual = true;
      } else if (button == 3) {
        isManual = false;
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
            digitalWrite(buzzerPin, LOW);
          }else{
            digitalWrite(buzzerPin, LOW);
            Serial.print("Jarak :");   
            Serial.print("\t"); 
            Serial.print(cm); 
            Serial.print("cm"); 
            Serial.println();    
            delay(500);
          } 
        return;
      }else if (button == 4) {
        isManual = false;
        Serial.print("___________PBS2019____________");
        Serial.println();
        Serial.print("_______NIM:6706174044_________");
        Serial.println();
        Serial.print("| 1. Automatic Traffic Light |");
        Serial.println();
        Serial.print("| 2. Manual Traffic Light    |");
        Serial.println();
        Serial.print("| 3. Sensor Ultrasonic       |");
        Serial.println();
        Serial.print("| 4. Kembali ke menu         |");
        Serial.println();
        Serial.print("______________________________");
        Serial.println();
        return;
      }
      
      if (button == 1 && isManual && ledColor == 0) {
        Serial.println("RED IS ACTIVE!");
        
        digitalWrite(ledRed, HIGH);
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledGreen, LOW);

        ledColor = ledColor + 1;
      } else if (button == 1 && isManual && ledColor == 1) {
        Serial.println("YELLOW IS ACTIVE!");
        
        digitalWrite(ledRed, LOW);
        digitalWrite(ledYellow, HIGH);
        digitalWrite(ledGreen, LOW);

        ledColor = ledColor + 1;
      } else if (button == 1 && isManual && ledColor == 2) {
        Serial.println("GREEN IS ACTIVE!");
        
        digitalWrite(ledRed, LOW);
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledGreen, HIGH);

        ledColor = 0;
      }

    }
  }
}
