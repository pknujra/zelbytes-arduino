# Task 09 - Firmware v1.0 Capstone

## Objective

To deliver firmware version 1.0 for an automatic irrigation controller using soil moisture threshold-based control with manual override support.

## Features

* Automatic irrigation based on soil moisture threshold.
* Manual override button for user-controlled irrigation.
* Relay-based valve control.
* Safe valve OFF state at startup.
* Serial command interface for monitoring and manual control.

## Serial Commands

| Command   | Function                     |
| --------- | ---------------------------- |
| STATUS    | Prints current system status |
| FORCE_ON  | Opens valve manually         |
| FORCE_OFF | Closes valve manually        |

## Hardware Used

* ESP32 DevKit V1 / Arduino-compatible controller
* Soil Moisture Sensor
* Relay Module
* Solenoid Valve
* Push Button
* Power Supply
* Jumper Wires

## Files

* `task-09-v1.0-capstone.ino` - Main firmware
* `config.h` - Pin definitions and timing settings
* `calibration.h` - Soil moisture calibration constants
* `README.md` - Task documentation

## Testing

The firmware was tested for:

* Auto mode threshold triggering
* Manual override button operation
* Serial command response
* Safe valve OFF startup behavior
* FORCE_ON and FORCE_OFF control

## Git Tag

Release tag:

```text
v1.0-capstone
```

## Submission

* Demo video or mentor-signed checklist
* Git tag link for `v1.0-capstone`
