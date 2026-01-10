// ---------- IR Sensors ----------
int leftIR  = 2;
int rightIR = 3;

// ---------- Ultrasonic ----------
#define trigPin 9
#define echoPin 10

// ---------- Motor Driver (L298N) ----------
// Left Motor
int ENA = 5;
int IN1 = 6;
int IN2 = 7;

// Right Motor
int ENB = 11;
int IN3 = 8;
int IN4 = 12;

// ---------- Parameters ----------
int motorSpeed = 150;
int stopDistance = 15; // cm

// ---------- Setup ----------
void setup() {
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

// ---------- Main Loop ----------
void loop() {
  int distance = readDistance();

  if (distance < stopDistance) {
    stopRobot();
  } else {
    followLine();
  }
}

// ---------- Line Following Logic ----------
void followLine() {
  int left = digitalRead(leftIR);
  int right = digitalRead(rightIR);

  if (left == LOW && right == LOW) {
    moveForward();
  } 
  else if (left == LOW && right == HIGH) {
    turnLeft();
  } 
  else if (left == HIGH && right == LOW) {
    turnRight();
  } 
  else {
    stopRobot();
  }
}

// ---------- Distance Measurement ----------
int readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 20000);
  if (duration == 0) return 100;

  return duration * 0.034 / 2;
}

// ---------- Motor Control ----------
void moveForward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, motorSpeed / 2);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed / 2);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopRobot() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

