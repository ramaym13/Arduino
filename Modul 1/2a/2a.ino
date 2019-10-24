int ledred = 12;
int i;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledred, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0; i<=255; i+=5){
    digitalWrite(ledred, i);
    delay(100);
  }

  for(i=255; i>=0; i-=5){
    digitalWrite(ledred, i);
    delay(100);
  }
}
