# Zelbytes Arduino Internship

## Overview

This repository contains the work completed during my Arduino and Embedded Systems internship at Zelbytes. The project focuses on learning embedded programming fundamentals, hardware interfacing, relay-based valve control, debugging techniques, Git/GitHub workflows, and basic irrigation automation concepts.

## Hardware Used

* Arduino Uno R3 (CH340-based clone)
* Relay Module
* Push Button
* LEDs and Resistors
* Breadboard and Jumper Wires
* USB Cable

## Repository Structure

* `docs/` – Project documentation, safety notes, hardware inventory, and debugging guides.
* `pinouts/` – Pin configuration and hardware mapping files.
* `wiring-images/` – Circuit diagrams and wiring photographs.
* `sketches/` – Arduino sketches organized by daily tasks and project phases.

## Internship Progress

### Day 1

* Arduino IDE installation and board setup
* USB driver configuration
* Blink and Serial Hello World sketches

### Day 2

* Git repository initialization
* Project folder structure creation
* Hardware inventory documentation

### Day 3

* Button interfacing using internal pull-up resistor
* Non-blocking debounce implementation using `millis()`
* LED toggle on button press

### Day 4

* Serial Monitor and Serial Plotter usage
* Debug logging with `F()` macro
* Serial command interface and debugging documentation

### Day 5

* Relay module interfacing
* Safe valve control implementation
* Emergency stop functionality
* Valve safety and interlock documentation

### Day 6

* Integration of previous modules into a single sketch
* Manual irrigation control using push button and relay
* Serial status reporting
* System testing and project documentation updates

## Features

* Non-blocking button debounce
* Relay-based valve control
* Emergency stop mechanism
* Serial status monitoring
* Structured documentation and version control

## Version

### v0.1-phase1

First integrated prototype featuring:

* Manual irrigation control
* Relay-operated valve switching
* Status reporting through Serial Monitor
* Safety documentation and testing procedures

## Author

Arjun

## License

This repository is maintained for educational and internship learning purposes.

