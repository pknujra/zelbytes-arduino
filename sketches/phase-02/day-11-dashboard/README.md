# Day 11 - Multi-Sensor Data Logger Integration

## Objective

To integrate the sensor modules developed in Days 7–10 into a single Arduino sketch using non-blocking timers, enabling simultaneous monitoring of environmental and irrigation-related parameters.

## Work Completed

* Merged LDR, DHT22, Ultrasonic, and Soil Moisture sensor drivers into a unified firmware.
* Implemented non-blocking timing using `millis()` to allow independent sensor updates.
* Generated structured CSV output for external logging and dashboard integration.
* Implemented per-sensor error handling to prevent one sensor failure from affecting others.
* Verified continuous operation through a 60-second logging test.
* Documented CSV field definitions for dashboard and data-analysis purposes.

## Hardware Used

* Arduino Uno
* LDR Module
* DHT22 Temperature & Humidity Sensor
* HC-SR04 Ultrasonic Sensor
* Soil Moisture Sensor
* Breadboard
* Jumper Wires

## Integrated Sensors

| Sensor               | Parameter             |
| -------------------- | --------------------- |
| LDR                  | Ambient Light Level   |
| DHT22                | Temperature (°C)      |
| DHT22                | Relative Humidity (%) |
| HC-SR04              | Distance (cm)         |
| Soil Moisture Sensor | Soil Moisture (%)     |

## Non-Blocking Architecture

Instead of using long `delay()` calls, sensor updates were scheduled using `millis()` timers.

Benefits:

* Multiple sensors operate concurrently.
* Faster system responsiveness.
* Sensor failures do not block other measurements.
* Suitable for future irrigation automation tasks.

## CSV Output Format

The firmware outputs data in the following format:

```text
time_ms,light_raw,temp,hum,distance_cm,soil_pct
```

### Example Output

```text
1000,865,29.4,67.1,24.8,42
2000,870,29.5,67.0,24.9,41
3000,861,29.5,66.9,25.0,43
4000,ERR,29.4,67.2,24.8,42
```

## Error Handling

Each sensor is monitored independently.

Examples:

* Failed DHT22 readings are detected using `isnan()`.
* Ultrasonic timeout events are reported as invalid readings.
* Sensor communication failures are logged without stopping data collection.

This ensures continuous operation even if one sensor becomes unavailable.

## Verification Test

A continuous 60-second logging test was performed to verify system stability.

Verification Criteria:

* All CSV columns appeared in the output.
* Sensor updates occurred at their intended intervals.
* No system freezes or blocking behavior were observed.
* Data remained available throughout the test duration.

## Dashboard Documentation

The CSV fields are documented in:

```text
docs/DASHBOARD.md
```

### Column Definitions

| Column      | Description                                    |
| ----------- | ---------------------------------------------- |
| time_ms     | Time since Arduino startup (milliseconds)      |
| light_raw   | Raw LDR ADC reading                            |
| temp        | Temperature in °C                              |
| hum         | Relative Humidity (%)                          |
| distance_cm | Ultrasonic distance measurement in centimeters |
| soil_pct    | Soil moisture percentage (0–100%)              |

## Learning Outcomes

* Integrated multiple sensor drivers into a single firmware project.
* Implemented non-blocking task scheduling using `millis()`.
* Designed structured CSV data output for logging and dashboards.
* Developed fault-tolerant sensor acquisition routines.
* Verified multi-sensor operation under continuous runtime conditions.
* Prepared the system for future automation and monitoring phases.
