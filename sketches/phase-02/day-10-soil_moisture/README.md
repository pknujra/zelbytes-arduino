# Day 10 - Soil Moisture Sensor Calibration

## Objective

To interface a soil moisture sensor with the Arduino Uno, characterize sensor response under dry and wet conditions, and develop a normalized moisture index for irrigation-related applications.

## Work Completed

* Identified the soil moisture sensor type and verified analog output operation.
* Connected the sensor to the Arduino Uno and acquired readings using `analogRead()`.
* Recorded dry and wet calibration endpoints.
* Implemented a linear mapping from raw ADC values to a 0–100 moisture index.
* Compared sensor readings across different soil media.
* Stored calibration constants in a dedicated calibration header file for future use.

## Hardware Used

* Arduino Uno
* Soil Moisture Sensor (Capacitive or Resistive)
* Breadboard
* Jumper Wires

## Wiring Connections

| Sensor Pin | Arduino Uno |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| AO         | A0          |

*Only the analog output (AO) was used for moisture measurements.*

## Sensor Type Identification

### Capacitive Sensor

* Measures changes in capacitance caused by soil moisture.
* Better long-term stability.
* Resistant to corrosion.
* Recommended for continuous deployment.

### Resistive Sensor

* Measures electrical conductivity between exposed probes.
* Lower cost but prone to corrosion over time.
* Can be power-cycled during measurements to reduce probe degradation.

## Calibration Procedure

### Dry Calibration

The sensor was inserted into a completely dry sample and the ADC value was recorded.

### Wet Calibration

The sensor was inserted into a saturated soil sample and the ADC value was recorded.

The recorded endpoints were stored for use in moisture calculations.

Example calibration constants:

```cpp
#define DRY_ADC  800
#define WET_ADC  350
```

## Moisture Index Calculation

Raw ADC readings were linearly mapped to a moisture index ranging from 0 to 100.

| Moisture Index | Condition         |
| -------------- | ----------------- |
| 0              | Completely Dry    |
| 50             | Moderate Moisture |
| 100            | Fully Saturated   |

Example:

```cpp
int moistureIndex = map(rawValue, DRY_ADC, WET_ADC, 0, 100);
moistureIndex = constrain(moistureIndex, 0, 100);
```

## Soil Comparison Test

Two soil samples were evaluated:

### Dry Perlite

* Low moisture retention.
* Produced readings close to the dry calibration endpoint.

### Wet Coir

* High moisture retention.
* Produced readings closer to the wet calibration endpoint.

The comparison demonstrated the sensor's ability to distinguish between varying moisture levels in different growing media.

## Optional Probe Protection

For resistive probes, power can be applied only during measurement:

1. Enable sensor power.
2. Wait briefly for stabilization.
3. Perform `analogRead()`.
4. Disable sensor power.

This approach helps reduce electrode corrosion and extends sensor life.

## Learning Outcomes

* Learned the operating principles of soil moisture sensors.
* Performed sensor calibration using dry and wet reference conditions.
* Implemented ADC-to-moisture mapping.
* Compared moisture characteristics of different growing media.
* Stored calibration data for reuse in future irrigation control systems.
* Evaluated methods to improve sensor longevity and reliability.
