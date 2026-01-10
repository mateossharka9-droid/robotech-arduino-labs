# Autonomous Line Follower Robot

This project implements an autonomous robot that:
- Follows a black line using two IR sensors
- Detects obstacles using an ultrasonic sensor
- Stops when an object is closer than a safe distance

The robot uses two DC motors for movement,
controlled through a motor driver.

---

## Sensors and Actuators

- Infrared sensors → line detection
- Ultrasonic sensor → obstacle detection
- DC motors → movement

---

## Control Strategy

The robot operates in a continuous loop:
1. Measure distance
2. If obstacle detected → stop
3. Else → follow the line

This structure ensures safe and autonomous behavior.
