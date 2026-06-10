# Day 9 - Ultrasonic Distance Measurement using HC-SR04

## Objective

To interface an HC-SR04 ultrasonic sensor with the Arduino Uno, measure distance using ultrasonic pulse timing, and improve measurement reliability through filtering and error handling.

## Work Completed

* Connected the HC-SR04 ultrasonic sensor to the Arduino Uno.
* Measured distance by calculating the travel time of ultrasonic pulses.
* Implemented a timeout mechanism to detect missing echoes and invalid readings.
* Applied a median-of-three filter to reduce measurement noise and outliers.
* Logged distance measurements in CSV format through the Serial Monitor.
* Documented the sensor's blind zone and maximum reliable measurement range.

## Hardware Used

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* Breadboard
* Jumper Wires

## Wiring Connections

| HC-SR04 Pin | Arduino Uno    |
| ----------- | -------------- |
| VCC         | 5V             |
| TRIG        | Digital Pin 9  |
| ECHO        | Digital Pin 10 |
| GND         | GND            |

## Sensor Operation

The HC-SR04 measures distance by transmitting an ultrasonic pulse and timing how long it takes for the reflected signal to return. The measured pulse width is converted into distance in centimeters.

## Measurement Filtering

To improve measurement stability, three consecutive readings were taken and processed using a median filter. This method helps reject occasional outlier values caused by noise or poor reflections.

## Data Logging

Distance measurements were logged in CSV format for analysis and visualization.

Example Output:

```text
time_s,distance_cm
0,24.8
1,24.9
2,25.0
3,INVALID
4,24.8
```

Invalid readings were marked whenever a timeout occurred and no valid echo was received.

## Calibration and Verification

| Actual Distance | Sensor Reading |
| --------------- | -------------- |
| 10 cm           | 9.8 cm         |
| 30 cm           | 28.2 cm        |

The measured values were found to be reasonably close to the actual distances, with small deviations attributable to sensor tolerance and environmental factors.

## Sensor Range

| Parameter                     | Value  |
| ----------------------------- | ------ |
| Minimum Distance (Blind Zone) | 2 cm   |
| Maximum Measured Distance     | 286 cm |

### Mounting Considerations

* Objects closer than 2 cm may not be measured accurately.
* The sensor should face the target surface directly for best results.
* Angled or soft surfaces may produce weaker reflections.
* Keep the sensor clear of obstacles and water droplets.

## Learning Outcomes

* Learned the operating principles of ultrasonic distance measurement.
* Calculated distance from pulse width timing data.
* Implemented timeout handling for invalid measurements.
* Applied median filtering to improve measurement reliability.
* Logged and analyzed sensor data using CSV output.
* Evaluated sensor accuracy through practical distance measurements.
