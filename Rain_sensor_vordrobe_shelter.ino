#include <Servo.h>

// Define the pin for the rain sensor
const int rainSensorPin = A0;  // You can change this pin as per your wiring

// Define the pin for the servo motor
const int servoPin = 8;  // You can change this pin as per your wiring

// Define the pin for the buzzer
const int buzzerPin = 13;  // You can change this pin as per your wiring

Servo myServo;

void setup() {
  // Set up the rain sensor pin as an input
  pinMode(rainSensorPin, INPUT);

  // Set up the servo motor
  myServo.attach(servoPin);

  // Set up the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the state of the rain sensor
  int rainState = digitalRead(rainSensorPin);

  // If the rain sensor detects rain (LOW), rotate the servo motor continuously and turn on the buzzer
  if (rainState == LOW) {
    myServo.write(90);  // Rotate the servo motor to 90 degrees
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
  } else {
    // If no rain is detected, stop the servo motor and turn off the buzzer
    myServo.write(0);  // Rotate the servo motor to 0 degrees
    digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
  }

  // Add a small delay for stability
  delay(100);
}
