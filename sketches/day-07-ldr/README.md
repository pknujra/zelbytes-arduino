# Day 7 - LDR Light Sensor Interfacing and Calibration

## Objective
To interface an LDR (Light Dependent Resistor) with the Arduino Uno, measure ambient light intensity using analog input, and calibrate the sensor for bench lighting conditions.

## Work Completed
- Built an LDR voltage divider circuit using a 10 kΩ series resistor.
- Read analog sensor values from pin A0 using `analogRead()`.
- Calculated and displayed both raw ADC values and estimated voltage readings.
- Calibrated the sensor by recording dark and bright endpoint values under test conditions.
- Stored calibration constants in a dedicated configuration file for easy maintenance.
- Logged sensor data in CSV format and visualized readings using the Arduino Serial Plotter.

## Hardware Configuration
- Arduino Uno
- LDR (Light Dependent Resistor)
- 10 kΩ Resistor
- Breadboard
- Jumper Wires

### Voltage Divider Connection
```text
5V
 |
[LDR]
 |
 +---- A0
 |
[10 kΩ]
 |
GND
