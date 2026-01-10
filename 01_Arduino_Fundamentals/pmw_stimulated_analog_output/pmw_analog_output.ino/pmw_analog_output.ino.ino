int irPin = 2;

void setup() {
  pinMode(irPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(irPin);
  Serial.println(value);
}
