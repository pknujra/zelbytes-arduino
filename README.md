# Zelbytes Arduino Internship

## Overview

This repository contains the work completed during my Arduino and Embedded Systems Internship at Zelbytes.

The project evolved from basic Arduino programming exercises into a complete smart irrigation controller featuring environmental monitoring, relay-based valve control, motor control, state-machine-based automation, data logging, and IoT telemetry using ESP32.

The repository documents the complete learning journey from hardware interfacing and debugging to firmware development, calibration, automation logic, and system integration.

---

## Hardware Used

### Controllers

* Arduino Uno R3 (CH340 Clone)
* ESP32 DevKit V1

### Sensors

* Soil Moisture Sensor
* DHT22 / AM2301 Temperature & Humidity Sensor
* HC-SR04 Ultrasonic Sensor
* LDR (Light Dependent Resistor)

### Actuators

* Relay Module
* Solenoid Valve
* 12V DC Motor
* LED Indicators

### Supporting Components

* Push Buttons
* Breadboard
* Jumper Wires
* Resistors
* USB Cable
* External Power Supply

---

## Repository Structure

```text
docs/
├── FINAL_REPORT.md
├── HARDWARE.md
├── VALVE_SAFETY.md
├── DASHBOARD.md
└── state_machine.md

pinouts/
├── Arduino_Uno_Pinout.pdf
└── ESP32_Pinout.pdf

wiring-images/
├── Wiring Photos
└── Hardware Images

sketches/
├── phase-1/
├── phase-02/
└── phase-03/

data/
└── sample_log.csv
```

---

## Internship Progress

### Phase 1 – Arduino Fundamentals & Manual Irrigation

#### Day 1

* Arduino IDE installation
* Board configuration
* Blink sketch
* Serial communication

#### Day 2

* Git and GitHub setup
* Repository structure creation
* Documentation workflow

#### Day 3

* Push-button interfacing
* Debounce implementation using millis()

#### Day 4

* Serial Monitor and Serial Plotter
* Debug logging techniques

#### Day 5

* Relay module integration
* Solenoid valve safety
* Emergency stop concepts

#### Day 6

* Manual irrigation controller
* Integrated firmware development

---

### Phase 2 – Sensor Integration & Automation

#### Day 7

* LDR calibration
* Light monitoring

#### Day 8

* DHT22 temperature and humidity sensing

#### Day 9

* HC-SR04 ultrasonic distance measurement
* Median filtering

#### Day 10

* Soil moisture sensor calibration

#### Day 11

* Multi-sensor dashboard integration
* CSV output formatting

#### Day 12

* Irrigation state machine
* IDLE, IRRIGATING, COOLDOWN, and FAULT states

#### Day 13

* PWM motor control using L298N
* Interrupt-driven emergency stop

#### Day 15

* Sensor data logging
* CSV dataset generation

---

### Phase 3 – IoT Irrigation Capstone

#### Task 09 – Firmware v1.0

Features:

* Automatic irrigation using soil moisture threshold
* Manual override button
* Relay-controlled pump/valve
* Wi-Fi connectivity
* Telemetry upload
* STATUS serial command
* FORCE_ON serial command
* FORCE_OFF serial command
* Configuration and calibration files

---

## Key Features

### Sensor Monitoring

* Soil Moisture Measurement
* Temperature Monitoring
* Humidity Monitoring
* Light Level Monitoring
* Distance Measurement

### Irrigation Control

* Automatic Irrigation
* Manual Override
* Relay-Based Valve Control
* Irrigation State Machine

### Safety Features

* Emergency Stop
* Safe Startup State
* Relay Interlock Protection
* Valve Safety Documentation

### Data & Telemetry

* CSV Data Logging
* Serial Dashboard Output
* IoT Telemetry Upload
* Sensor Calibration Management

---

## Releases

### v0.1-phase1

* Manual irrigation controller
* Relay valve control
* Status monitoring

### v0.2-phase2

* Sensor integration
* State machine
* Motor control
* Data logging

### v1.0-capstone

* Complete IoT irrigation controller
* Automatic irrigation
* Manual override
* Telemetry support
* Production-ready firmware

---

## Documentation

Detailed documentation is available in the `docs/` directory:

* Hardware Inventory
* Valve Safety Procedures
* Sensor Calibration
* Dashboard Documentation
* State Machine Design
* Final Project Report

---

## Author

**Arjun**

Embedded Systems & IoT Intern
Zelbytes Internship Program

---

## License

This repository is maintained for educational, research, and internship learning purposes.
