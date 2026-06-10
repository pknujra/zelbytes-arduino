# Day 8 - DHT22 Temperature and Humidity Sensor

## Objective

To interface a DHT22 sensor with the Arduino Uno, acquire temperature and humidity measurements, and log environmental data for monitoring applications.

## Work Completed

* Connected the DHT22 sensor module to the Arduino Uno.
* Verified compatibility with 3.3 V–5 V operating voltage.
* Installed and configured the DHT sensor library.
* Measured temperature (°C) and relative humidity (%RH).
* Implemented `isnan()` error handling to detect failed sensor readings.
* Used a non-blocking 2-second sampling interval to avoid delaying other tasks.
* Logged sensor data in CSV format through the Serial Monitor.
* Documented proper sensor placement to ensure accurate measurements.

## Hardware Used

* Arduino Uno
* DHT22 Temperature and Humidity Sensor Module
* Breadboard
* Jumper Wires

## Wiring Connections

| DHT22 Module | Arduino Uno   |
| ------------ | ------------- |
| VCC (+)      | 5V            |
| OUT          | Digital Pin 2 |
| GND (-)      | GND           |

*Note: The DHT22 module used includes onboard support circuitry, eliminating the need for an external pull-up resistor.*

## Data Logging

Sensor readings were logged in CSV format for easy analysis and visualization.

Example Output:

```text
time_s,temperature_C,humidity_percent
2,29.4,65.2
4,29.5,65.1
6,29.4,65.3
```

## Sensor Placement

To improve measurement accuracy, the DHT22 sensor was positioned:

* Away from the solenoid valve outlet.
* Away from direct water spray or mist.
* In a location with adequate airflow.
* Away from heat-generating electronic components.

## Learning Outcomes

* Learned to interface and configure a digital environmental sensor.
* Acquired temperature and humidity data using Arduino.
* Implemented error handling using `isnan()`.
* Practiced non-blocking sensor polling using timed intervals.
* Logged environmental data in CSV format for monitoring and analysis.
