# Debugging Checklist

## Hardware Checks

* Verify that the Arduino board is properly connected via USB.
* Confirm that the correct board and COM port are selected in the Arduino IDE.
* Ensure the LED is connected to the correct pin (D13) and functioning properly.
* Check all wiring connections for loose or incorrect connections.

## Serial Communication Checks

* Verify that the Serial Monitor baud rate matches the baud rate defined in the sketch.
* Test communication at both 9600 and 115200 baud rates.
* Confirm that the startup message appears after reset.
* Ensure that line ending settings in the Serial Monitor do not interfere with command input.

## Command Validation

* Enter `?` and verify that the help message is displayed.
* Enter `l` and confirm that the LED turns ON.
* Enter `o` and confirm that the LED turns OFF.
* Enter an invalid command and verify that the system returns an "Unknown" message.

## Debug Logging

* Confirm that `DEBUG` is enabled when verbose logging is required.
* Verify that uptime messages are printed every 2 seconds when debugging is active.
* Disable `DEBUG` before deployment to reduce unnecessary serial output.

## Code Verification

* Check for compilation errors and warnings before uploading.
* Verify that all pin definitions match the hardware configuration.
* Ensure that the `F()` macro is used for constant strings to reduce SRAM usage.

## Final Validation

* Upload the sketch successfully.
* Test all serial commands.
* Confirm correct LED behavior.
* Verify stable operation without unexpected resets or communication issues.

