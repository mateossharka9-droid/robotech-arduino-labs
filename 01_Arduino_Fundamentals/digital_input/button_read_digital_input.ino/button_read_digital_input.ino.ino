int potPin = A0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int value = analogRead(potPin);
  int pwm = map(value, 0, 1023, 0, 255);
  analogWrite(ledPin, pwm);
}
