int ledred = 12;
int pot = A0;
int data;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledred, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = analogRead(pot);
  data = data/4;
  digitalWrite(ledred, data);
}
