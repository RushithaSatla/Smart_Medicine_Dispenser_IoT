#include <ESP32Servo.h>

const int triggerPin = 4; // Trigger pin of ultrasonic sensor
const int echoPin = 19;   // Echo pin of ultrasonic sensor
const int servoPin = 2;   // Servo motor control pin
const int greenLightPin = 27; // Green light pin

Servo myServo;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLightPin, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(65); // Ensure the servo starts at 0 degrees
  digitalWrite(greenLightPin, LOW); // Ensure the green light is off at start
}

void loop() {
  long duration, distance;
  
  // Send a pulse to trigger the ultrasonic sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  // Read the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Convert the duration to distance in cm
  distance = (duration / 2) / 29.1;
  digitalWrite(greenLightPin, HIGH);
  // If an object is detected within 20 cm, perform the following actions
  if (distance < 20) {
    // Rotate the servo to 90 degrees
    myServo.write(120);
    // Turn on the green light
    // Wait for 0.5 seconds
    delay(500);
    // Rotate the servo back to 0 degrees
    myServo.write(65);
    // Turn off the green light
    digitalWrite(greenLightPin, LOW);
    // Wait for 10 seconds before resuming detection
    delay(10000);
  }
  
  // Delay between readings
  delay(100);
}