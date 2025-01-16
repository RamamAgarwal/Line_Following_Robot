#include <L298N.h>
#include <Wire.h>
#include <VL53L0X.h>

// Pin definition for motors
const unsigned int IN1 = 27;
const unsigned int IN2 = 26;
const unsigned int IN3 = 25;
const unsigned int IN4 = 33;
const unsigned int ENA = 14;
const unsigned int ENB = 32;

// VL53L0X sensor instance
VL53L0X sensor;

// Desired distance from the wall in millimeters
const int desiredDistance = 200; // Example: 200 mm or 20 cm

// Thresholds for close and far distances
const int closeThreshold = 150;  // Below 15 cm (too close)
const int farThreshold = 250;    // Above 25 cm (too far)

// Adjust motor speeds for balanced movement
int dutyCycle1 = 200;  // Reduce motor1 speed
int dutyCycle2 = 255;  // Increase motor2 speed to match

// Lower speeds for sharper turns
int turnSpeed = 220;

// Create motor instances
L298N motor1(ENA, IN1, IN2);
L298N motor2(ENB, IN3, IN4);

void setup()
{
  // Used to display information
  Serial.begin(9600);

  // Initialize the VL53L0X sensor
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  // Set initial speed for the motors
  motor1.setSpeed(dutyCycle1); // Left motor speed
  motor2.setSpeed(dutyCycle2); // Right motor speed

  delay(5000);  // Initial delay for setup
}

void loop()
{
  // Read distance from the VL53L0X sensor
  int distance = sensor.readRangeContinuousMillimeters();

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm");

  // Motor control based on distance readings
  if (distance < closeThreshold) {
    // Too close to an object: turn left
    motor1.setSpeed(dutyCycle1 / 2); // Slow down motor1
    motor2.setSpeed(dutyCycle2);     // Keep motor2 running
    motor1.forward();
    motor2.forward();
    Serial.println("Turning Left");
  }
  else if (distance > farThreshold) {
    // Too far from an object: turn right
    motor1.setSpeed(dutyCycle1);     // Keep motor1 running
    motor2.setSpeed(dutyCycle2 / 2); // Slow down motor2
    motor1.forward();
    motor2.forward();
    Serial.println("Turning Right");
  }
  else {
    // Move forward if at the correct distance
    motor1.setSpeed(dutyCycle1);
    motor2.setSpeed(dutyCycle2);
    motor1.forward();
    motor2.forward();
    Serial.println("Moving Forward");
  }

  delay(100);  // 100 milliseconds delay
}
