int button = 2;
int led = 13;

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(button)) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
