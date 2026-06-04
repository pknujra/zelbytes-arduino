# Day 3 - Button Interface and Debouncing

## Objective

To implement a reliable button-controlled LED system using active-low logic, software debouncing, and serial monitoring.

## Work Completed

* Wired an LED circuit with the appropriate current-limiting resistor and calculated the required resistor value.
* Connected a push button using the Arduino's internal pull-up resistor, implementing active-low logic.
* Developed a non-blocking debounce mechanism using the `millis()` function to eliminate false triggers caused by button bounce.
* Implemented LED toggling on a stable button press and recorded the button press count through the Serial Monitor.
* Created a `config.h` file to document and manage pin assignments, improving code readability and maintainability.
* Committed the completed sketch and configuration files to the Git repository using meaningful commit messages.

## Learning Outcomes

* Understood active-low button interfacing with internal pull-up resistors.
* Learned software debouncing techniques using `millis()`.
* Gained experience with event-driven programming without blocking delays.
* Improved project organization through configuration files and version control practices.
