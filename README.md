# Line_Following_Robot
This is a project of line-following robot having two motors and two wheels made using ESP espressif-32 micro-controller along with IR sensors and motor driver.

This code implements a line follower robot using an ESP32 microcontroller, two infrared sensors, and a dual motor driver. The robot is designed to follow a black line on a light surface and navigate through various path scenarios, including straight lines, curves, and acute angles.

## Key Components:

ESP32 microcontroller
Two IR sensors
Dual motor driver (controlling left and right motors)

## Functionality:

Straight Line: When both sensors detect a light surface (no black line), the robot moves forward.
Gentle Curves:
If the left sensor detects the line (black), the robot turns right.
If the right sensor detects the line (black), the robot turns left.
Acute Angles: When both sensors detect black (at an acute angle junction), the robot continues its last action (forward, left turn, or right turn) to navigate through the angle without haphazard.

## How it works:

The code reads the state of both IR sensors instantaneously.
Based on the sensor readings, it decides the appropriate action (move forward, turn left, or turn right).
For each action, it updates a 'lastAction' variable to keep track of the most recent movement.
When an acute angle is detected (both sensors read black), instead of getting confused, the robot continues its last action. This allows it to smoothly navigate through sharp turns.
The speed of each motor can be adjusted using the leftMotorSpeed and rightMotorSpeed variables. The turnSpeed variable allows for sharper turns when needed.

This approach ensures that the robot can handle various track layouts, including challenging acute angles, without losing its path or getting stuck at junctions.
