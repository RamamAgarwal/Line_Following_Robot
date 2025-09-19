# 🤖 **Line_Following_Robot** 🚗

This project features a **line-following robot** powered by the **ESP32 microcontroller**, utilizing **two infrared (IR) sensors** and a **dual motor driver**. The robot is engineered to follow a **black line on a light surface** and intelligently handle **straight paths, curves**, and **acute-angle junctions** without getting off track.

---

## 🧩 **Key Components**

- **ESP32 Microcontroller**  
  Acts as the brain of the robot, reading sensor data and controlling motor movements.

- **Two IR Sensors**  
  Detects the presence of the black line beneath the robot.

- **Dual Motor Driver (L298N or similar)**  
  Controls the two DC motors (left and right wheels).

---

## ⚙️ **Functionality**

- **➡️ Straight Line**  
  When **both IR sensors detect a light surface** (no black line), the robot moves forward.

- **↩️ Gentle Curves**
  - **Left Sensor detects black**: Robot turns **right**.
  - **Right Sensor detects black**: Robot turns **left**.

- **⤴️ Acute Angles**
  - When **both sensors detect black**, indicating a sharp corner or T-junction, the robot **continues its last action** (forward, left, or right) to maintain smooth motion and avoid confusion.

---

## 🧠 **How It Works**

1. The **IR sensors** constantly check the color beneath them.
2. The **ESP32 reads the sensor data** in real-time.
3. Based on the readings, the robot chooses one of three actions:
   - Move Forward
   - Turn Left
   - Turn Right
4. A `lastAction` variable keeps track of the robot's previous movement.
5. When both sensors detect black (e.g., at a sharp turn), the robot **repeats the last known good action** rather than stopping or becoming erratic.
6. The **motor speeds** are adjustable using the following variables:
   - `leftMotorSpeed`
   - `rightMotorSpeed`
   - `turnSpeed` (for tighter curves)

---

## 🔧 **Adjustable Parameters**

You can fine-tune the robot's behavior by tweaking these values in the code:

- `leftMotorSpeed`: Speed of the left motor
- `rightMotorSpeed`: Speed of the right motor
- `turnSpeed`: Speed applied when turning (can be higher or lower for sharper/smoother turns)

---

## 🚦 **Advantages of This Approach**

- ✅ Handles **complex track layouts** including **acute angles** and junctions.
- ✅ **Memory-based navigation** through the `lastAction` variable.
- ✅ Prevents robot from getting stuck or jittering at critical turning points.
- ✅ Simple yet effective **IR-based logic** with robust motor control.

---

## 📷 **Example Use Case**

Place the robot on a **black-lined path on a white/light surface** and power it on. It will:

- Move straight on open paths
- Smoothly handle gentle curves
- Intelligently maneuver through sharp bends and junctions

---

## 🛠️ **Requirements**

### Hardware
- **ESP32 Development Board**
- **2x IR Sensors (TCRT5000 or similar)**
- **L298N Dual Motor Driver**
- **2x DC Motors**
- **Power Supply (Li-ion battery pack or USB)**

### Software
- **Arduino IDE**
- **ESP32 Board Support (via Board Manager)**

---
Special thanks to the open-source community and robotics enthusiasts for inspiring and contributing to innovations like this. 🚀

---

Happy Building & Tinkering! 👨‍🔧👩‍💻
