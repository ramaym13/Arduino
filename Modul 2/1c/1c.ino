int ledred = 12;
int ledgreen = 11;
int ledblue = 10;
int pot = A0;
int data;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledblue, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = analogRead(pot);
  data = data/4;

  digitalWrite(ledred, HIGH);
  digitalWrite(ledgreen, HIGH);
  digitalWrite(ledblue, HIGH);
  delay(data);
  
  digitalWrite(ledred, HIGH);
  delay(data);
  digitalWrite(ledred, LOW);
  delay(data);
  digitalWrite(ledgreen, HIGH);
  delay(data);
  digitalWrite(ledgreen, LOW);
  delay(data);
  digitalWrite(ledblue, HIGH);
  delay(data);
  digitalWrite(ledblue, LOW);
  delay(data);
}
