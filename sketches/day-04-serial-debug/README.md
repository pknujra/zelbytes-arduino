# Day 4 - Serial Communication and Debugging

## Objective

To explore serial communication, implement debugging techniques, and develop a command-based interface for controlling an LED through the Serial Monitor.

## Work Completed

* Tested Serial Monitor and Serial Plotter at 9600 and 115200 baud rates and observed the impact of baud rate on communication speed and timing.
* Printed labeled sensor-style data using the `F()` macro to reduce SRAM usage and improve memory efficiency.
* Added a DEBUG compile flag to enable or disable verbose debugging messages during development.
* Implemented serial commands to control the LED and provide user assistance:

  * `?` – Display help information
  * `l` – Turn LED ON
  * `o` – Turn LED OFF
* Created and documented a debugging checklist in `docs/DEBUGGING.md` for troubleshooting and development reference.

## Learning Outcomes

* Gained practical experience with serial communication and baud rate selection.
* Learned memory optimization using the `F()` macro.
* Understood conditional compilation with DEBUG flags.
* Developed a simple serial command interface for device control.
* Improved debugging and documentation practices for embedded systems development.
