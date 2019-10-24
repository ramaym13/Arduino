int ledred = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledred, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledred, HIGH);
  delay(1000);
  digitalWrite(ledred, LOW);
  delay(1000);
}
