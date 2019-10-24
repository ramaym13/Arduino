int ledred = 12;
int ledgreen = 11;
int ledblue = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledblue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledred, HIGH);
  digitalWrite(ledgreen, HIGH);
  digitalWrite(ledblue, HIGH);
  delay(2000);

  digitalWrite(ledred, LOW);
  digitalWrite(ledgreen, LOW);
  digitalWrite(ledblue, LOW);
  delay(1000);

  digitalWrite(ledred, HIGH);
  delay(500);
  digitalWrite(ledred, LOW);
  delay(500);
  digitalWrite(ledgreen, HIGH);
  delay(500);
  digitalWrite(ledgreen, LOW);
  delay(500);
  digitalWrite(ledblue, HIGH);
  delay(500);
  digitalWrite(ledblue, LOW);
  delay(500);
}
