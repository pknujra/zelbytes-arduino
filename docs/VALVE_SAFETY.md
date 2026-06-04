# Valve Safety and Interlocks

## Purpose

This document outlines the safety precautions and interlocks implemented during relay-based valve control testing.

## Safety Measures

* The valve remains de-energized during system startup to prevent unintended activation.
* An emergency stop (`e`) serial command is provided to immediately de-energize the valve.
* Relay operation was verified by listening for the relay click before connecting any valve or external load.
* All wiring connections were checked before applying power to the system.
* The relay control signal was tested independently to confirm correct active-low operation.

## Interlocks

* Manual user input is required before valve activation.
* The valve defaults to the OFF state after power-up or reset.
* Emergency stop functionality overrides all other commands and forces the valve to the OFF state.

## Manual Shutoff Location

* Primary electrical shutoff: Disconnect the USB cable or external power supply connected to the Arduino and relay module.
* Manual fluid shutoff: If a solenoid valve is connected to a plumbing system, a manual isolation valve should be installed upstream of the solenoid valve to allow flow to be stopped independently of the control system.
* During testing, the operator must have immediate access to the power disconnect and manual shutoff mechanism.

## Testing Procedure

1. Verify relay module power and signal connections.
2. Confirm relay click during activation and deactivation.
3. Test emergency stop command and verify valve shutdown.
4. Connect the valve/load only after successful relay testing.
5. Monitor system behavior for unintended activations.

## Notes

* USB power limits should be considered when operating relay modules and external loads.
* High-voltage or high-current loads must be isolated from the microcontroller circuitry.
* All testing should be performed under supervision and according to laboratory safety procedures.
