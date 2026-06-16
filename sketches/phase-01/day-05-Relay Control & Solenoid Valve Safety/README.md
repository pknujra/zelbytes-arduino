# Day 5 - Relay and Valve Control

## Objective

To interface a relay module with the Arduino Uno, implement safe valve control, and study relay operation and safety considerations.

## Work Completed

* Connected the relay module using VCC, GND, and IN control pins and identified the module's active-low behavior.
* Controlled relay operation using `digitalWrite()` and verified functionality through audible relay switching before connecting any external load.
* Implemented a safe startup state to ensure the valve remains de-energized during power-up.
* Added an emergency stop (`e`) serial command to immediately deactivate the valve when required.
* Documented valve safety procedures, interlocks, and manual shutoff locations in `docs/VALVE_SAFETY.md`.
* Measured and evaluated relay operation with respect to USB power supply limitations.

## Learning Outcomes

* Understood relay module interfacing and active-low control logic.
* Learned safe practices for controlling valves and external loads using relays.
* Implemented emergency shutdown mechanisms for safer operation.
* Gained experience in documenting safety procedures and system interlocks.
* Developed awareness of power consumption and supply limitations in embedded systems.

