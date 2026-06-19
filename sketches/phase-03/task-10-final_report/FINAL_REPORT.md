# FINAL REPORT

## Zelbytes Arduino & Embedded Systems Internship

### Project Title

**Smart IoT-Based Grow Bench Irrigation Controller**

### Author

Arjun K P

### Internship Organization

Zelbytes

### Version

v1.0-capstone

---

# 1. Introduction

The objective of this internship was to develop practical skills in embedded systems, Arduino programming, hardware interfacing, debugging, sensor calibration, automation, and IoT integration.

The final project developed during the internship is a Smart Grow Bench Irrigation Controller capable of monitoring environmental conditions and automatically controlling irrigation based on soil moisture levels. The system also supports manual override, remote telemetry, safety mechanisms, and data logging.

The project evolved through multiple phases beginning with basic Arduino programming and culminating in a fully integrated ESP32-based IoT irrigation controller.

---

# 2. Project Objectives

The primary objectives of the project were:

* Learn Arduino and ESP32 development.
* Interface sensors and actuators.
* Implement relay-based irrigation control.
* Perform sensor calibration.
* Design irrigation state machines.
* Implement safety features.
* Log environmental data.
* Transmit telemetry through Wi-Fi.
* Maintain project documentation using Git and GitHub.

---

# 3. Hardware Bill of Materials

| Component                 | Quantity | Approx. Cost (INR) | Purpose                 |
| ------------------------- | -------- | ------------------ | ----------------------- |
| ESP32 DevKit V1           | 1        | ₹350               | Main controller         |
| Arduino Uno Clone         | 1        | ₹450               | Early development board |
| Soil Moisture Sensor      | 1        | ₹80                | Soil monitoring         |
| DHT22 Sensor              | 1        | ₹250               | Temperature & humidity  |
| HC-SR04 Ultrasonic Sensor | 1        | ₹100               | Distance sensing        |
| LDR Sensor                | 1        | ₹10                | Light sensing           |
| Relay Module              | 1        | ₹100               | Valve control           |
| Solenoid Valve            | 1        | ₹350               | Water control           |
| Push Buttons              | 2        | ₹20                | User input              |
| LEDs                      | 2        | ₹10                | Status indication       |
| Resistors                 | Assorted | ₹20                | Signal conditioning     |
| Breadboard                | 1        | ₹100               | Prototyping             |
| Jumper Wires              | 1 Set    | ₹100               | Interconnections        |
| L298N Driver Module       | 1        | ₹150               | Motor control           |
| 12V DC Motor              | 1        | ₹250               | Actuator testing        |
| USB Cable                 | 1        | ₹50                | Programming             |
| Power Supply              | 1        | ₹300               | System power            |

### Estimated Total Cost

**₹2,690**

---

# 4. System Architecture

The system consists of:

* ESP32 Controller
* Soil Moisture Sensor
* DHT22 Sensor
* LDR Sensor
* Relay-Controlled Solenoid Valve
* Push Button Manual Override
* Status LED
* Wi-Fi Telemetry Module

The ESP32 continuously reads environmental sensor data and makes irrigation decisions based on predefined moisture thresholds.

---

# 5. Wiring Diagrams

## Controller Wiring

Insert wiring photographs from:

```text
wiring-images/
```

Example:

```markdown
![Main Wiring](../wiring-images/main-wiring.jpg)
```

## Sensor Connections

### Soil Moisture Sensor

| Sensor | ESP32  |
| ------ | ------ |
| VCC    | 3.3V   |
| GND    | GND    |
| AO     | GPIO34 |

### Relay Module

| Relay | ESP32  |
| ----- | ------ |
| IN    | GPIO26 |
| VCC   | 5V     |
| GND   | GND    |

### Manual Override Button

| Button | ESP32  |
| ------ | ------ |
| Signal | GPIO27 |
| GND    | GND    |

### Status LED

| LED     | ESP32 |
| ------- | ----- |
| Anode   | GPIO2 |
| Cathode | GND   |

---

# 6. Sensor Calibration Methodology

## LDR Calibration

Measurements obtained:

| Condition | Reading |
| --------- | ------- |
| Dark      | 0       |
| Bright    | 986     |

These values were used to establish light monitoring thresholds.

---

## Soil Moisture Calibration

The sensor was tested under dry and wet conditions.

Calibration constants were stored in:

```cpp
calibration.h
```

Values:

```cpp
SOIL_DRY_ADC
SOIL_WET_ADC
```

These values were used to calculate soil moisture percentage.

---

## Ultrasonic Sensor Calibration

Measured Performance:

| Actual Distance | Sensor Reading |
| --------------- | -------------- |
| 10 cm           | 9.8 cm         |
| 30 cm           | 28.2 cm        |

Operational Range:

| Parameter     | Value  |
| ------------- | ------ |
| Minimum Range | 2 cm   |
| Maximum Range | 286 cm |

Median filtering was implemented to reduce noise.

---

## DHT22 Calibration

The DHT22 sensor was connected using a 10k pull-up resistor.

A 2-second sampling interval was maintained to comply with sensor specifications.

The sensor was positioned away from direct water spray and valve mist.

---

# 7. Software Design

The firmware was developed using Arduino IDE.

Major modules include:

* Sensor Acquisition
* Irrigation Control
* State Machine
* Serial Command Interface
* Wi-Fi Telemetry
* Data Logging
* Safety Handling

Configuration parameters were stored in:

```text
config.h
```

Calibration values were stored in:

```text
calibration.h
```

---

# 8. Irrigation Control Logic

The irrigation controller operates in two modes:

### Automatic Mode

The system automatically starts irrigation when soil moisture falls below the configured threshold.

### Manual Mode

The user can manually control irrigation using:

* Push Button
* Serial Commands

Commands:

```text
STATUS
FORCE_ON
FORCE_OFF
```

---

# 9. Data Logging

Environmental data was logged in CSV format:

```csv
timestamp,temp,humidity,soil,light
```

Example:

```csv
1000,29.5,65.2,512,875
2000,29.6,65.0,508,882
```

A sample dataset is stored in:

```text
data/sample_log.csv
```

---

# 10. Telemetry

The ESP32 uploads soil moisture information to the IoT server through Wi-Fi.

Features:

* JSON Payload Generation
* HTTP POST Requests
* API Key Authentication
* Remote Monitoring Support

---

# 11. Test Results

| Test Case         | Result |
| ----------------- | ------ |
| Relay Switching   | PASS   |
| Manual Override   | PASS   |
| STATUS Command    | PASS   |
| FORCE_ON Command  | PASS   |
| FORCE_OFF Command | PASS   |
| Soil Monitoring   | PASS   |
| Sensor Logging    | PASS   |
| Wi-Fi Telemetry   | PASS   |

---

# 12. Known Limitations

* Soil moisture readings vary with soil type.
* Wi-Fi connection is required for telemetry.
* No battery backup implemented.
* Relay contacts have limited lifetime.
* Threshold values may require recalibration for different crops.

---

# 13. Instructions for the Next Intern

## Clone Repository

```bash
git clone <repository-url>
```

## Open Project

```text
sketches/phase-03/task-09-v1.0-capstone/
```

## Required Libraries

* WiFi.h
* HTTPClient.h
* WebServer.h

## Board Configuration

```text
Board: ESP32 Dev Module
Baud Rate: 115200
```

## Configure Wi-Fi

Edit:

```cpp
config.h
```

Update:

```cpp
WIFI_SSID
WIFI_PASSWORD
API_KEY
SERVER_URL
```

## Upload Firmware

1. Connect ESP32.
2. Select COM Port.
3. Compile.
4. Upload.
5. Open Serial Monitor.

## Verify Operation

Run:

```text
STATUS
FORCE_ON
FORCE_OFF
```

and verify correct relay operation.

---

# 14. Conclusion

The internship successfully demonstrated the development of an embedded IoT irrigation controller from initial hardware interfacing through complete system integration.

The project provided practical experience in embedded programming, sensor calibration, automation logic, safety mechanisms, data logging, telemetry communication, and Git-based version control.

The resulting system serves as a foundation for future agricultural automation projects and provides a reusable framework for subsequent interns and project extensions.

---

# Repository

GitHub Repository:

https://github.com/pknujra/zelbytes-arduino

---

# Release

Current Release:

v1.0-capstone
