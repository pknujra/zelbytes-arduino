# Day 7 - LDR Light Sensor Calibration

## Objective
To interface an LDR (Light Dependent Resistor) with the Arduino Uno, measure ambient light intensity using analog input, and calibrate the sensor for the laboratory lighting conditions.

## Work Completed
- Built an LDR voltage divider circuit using a 10 kΩ series resistor.
- Read light intensity values from analog pin A0 using `analogRead()`.
- Calculated and displayed both raw ADC readings and estimated voltage values through the Serial Monitor.
- Calibrated the sensor by recording the minimum and maximum readings under test conditions.
- Stored calibration constants in a dedicated configuration file for future use.
- Visualized sensor data using the Arduino Serial Plotter and CSV-formatted serial output.

## Hardware Used
- Arduino Uno
- LDR (Light Dependent Resistor)
- 10 kΩ Resistor
- Breadboard
- Jumper Wires

## Circuit Description
The LDR and 10 kΩ resistor were connected as a voltage divider. The junction between the LDR and resistor was connected to analog pin A0 to measure varying voltage levels based on ambient light intensity.

## Calibration Results

| Condition | Raw ADC Reading |
|-----------|----------------|
| Dark       | 0 |
| Bright     | 986 |

These values were recorded under the available bench lighting conditions and used as calibration endpoints for sensor normalization and future automation tasks.

## Configuration
Calibration constants were stored in `config.h` / `calibration.h` for easy maintenance and reuse across sketches.

Example:

```cpp
const int LDR_DARK = 0;
const int LDR_BRIGHT = 986;
