int ledred = 12;
int button = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledred, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button) == LOW){
    digitalWrite(ledred, HIGH);
  }else{
    digitalWrite(ledred, LOW);
  }
}
