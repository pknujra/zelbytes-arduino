# Task 7 - Sensor Data Logging and CSV Capture

## Objective

To collect and record environmental sensor data over an extended period using serial CSV logging. The system captures temperature, humidity, soil moisture, and ambient light readings and stores them in a structured CSV format for analysis and monitoring.

---

## Hardware Used

* Arduino Uno
* DHT22 / AM2301 Temperature and Humidity Sensor
* Soil Moisture Sensor
* LDR (Light Dependent Resistor)
* USB Connection to Host Computer

---

## Features Implemented

### Sensor Data Acquisition

The system periodically reads:

* Temperature (°C)
* Relative Humidity (%RH)
* Soil Moisture (ADC value)
* Ambient Light (ADC value)

### CSV Data Logging

Sensor readings are transmitted through the Serial Monitor in CSV format.

Format:

```csv
timestamp,temp,humidity,soil,light
```

Example:

```csv
1000,29.4,65.2,512,875
2000,29.5,65.1,508,882
3000,29.5,65.0,510,879
```

### Timestamping

The first column uses Arduino's `millis()` function to record elapsed time since system startup.

---

## Data Capture Method

This project uses **host-side serial logging** rather than an SD card.

Data is transmitted through the USB serial connection and saved as a CSV file on the host computer.

Output file:

```text
data/sample_log.csv
```

---

## How to Reproduce the Capture

### Step 1: Upload the Logging Sketch

Upload the Day 15 logging sketch to the Arduino.

### Step 2: Open Serial Monitor

Configure:

* Baud Rate: 9600
* Line Ending: None

Verify that CSV data appears continuously.

### Step 3: Capture Serial Data

Use one of the following methods:

#### Arduino Serial Monitor

Copy and paste the output into a `.csv` file.

#### Serial Plotter

Observe sensor trends in real time.

#### External Serial Logging Tool

Use a serial terminal application capable of saving incoming data directly to a CSV file.

### Step 4: Run Logging Session

Allow the system to run continuously and collect sensor readings.

### Step 5: Save Data

Store the captured output as:

```text
data/sample_log.csv
```

---

## Sample CSV Structure

| Column    | Description                 |
| --------- | --------------------------- |
| timestamp | Time since startup (ms)     |
| temp      | Temperature (°C)            |
| humidity  | Relative humidity (%)       |
| soil      | Soil moisture raw ADC value |
| light     | LDR raw ADC value           |

---

## Test Procedure

1. Power the system and verify sensor operation.
2. Confirm CSV output formatting.
3. Record data continuously.
4. Collect a minimum of 50 rows.
5. Verify that all columns contain valid sensor readings.
6. Save the captured data to the repository.

---

## Repository Structure

```text
day-15-data-logging/
├── logging_sketch.ino
├── README.md
└── data/
    └── sample_log.csv
```

---

## Learning Outcomes

* Serial-based data logging
* CSV data formatting
* Long-duration sensor monitoring
* Time-stamped environmental data collection
* Dataset preparation for future dashboard and analytics development

