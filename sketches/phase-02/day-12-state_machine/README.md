# Day 12 - Irrigation State Machine Implementation

## Objective

To design and implement a finite state machine (FSM) for irrigation control, improving system reliability, readability, and maintainability while enforcing safety limits and sensor validation.

## Work Completed

* Designed an irrigation state diagram and documented it in `docs/state_machine.md`.
* Implemented system behavior using `enum` states and a `switch/case` transition structure.
* Added soil moisture debouncing using consecutive low-moisture readings.
* Enforced maximum irrigation runtime to prevent overwatering.
* Implemented a cooldown period between irrigation cycles.
* Logged all state transitions to the Serial Monitor for debugging and validation.

## Hardware Used

* Arduino Uno
* Soil Moisture Sensor
* Relay Module
* Solenoid Valve
* Breadboard
* Jumper Wires

## State Machine Overview

The irrigation controller operates as a finite state machine with clearly defined states and transitions.

### States

| State      | Description                                                           |
| ---------- | --------------------------------------------------------------------- |
| IDLE       | System monitoring soil moisture and waiting for irrigation conditions |
| CHECK_SOIL | Verifies soil moisture readings before triggering irrigation          |
| IRRIGATING | Valve open and irrigation active                                      |
| COOLDOWN   | Waiting period after irrigation before allowing another cycle         |
| ERROR      | Entered when a fault condition is detected                            |

## State Diagram

The state diagram is documented in:

```text
docs/state_machine.md
```

Example transition flow:

```text
IDLE
  ↓
CHECK_SOIL
  ↓
IRRIGATING
  ↓
COOLDOWN
  ↓
IDLE
```

## Soil Moisture Debouncing

To prevent false triggers caused by noisy sensor readings, irrigation is initiated only after detecting multiple consecutive low-moisture readings.

Example:

```cpp
const int REQUIRED_LOW_READS = 3;
```

The moisture threshold must be crossed for several consecutive measurements before a state transition occurs.

## Irrigation Safety Controls

### Maximum Irrigation Duration

A maximum runtime is enforced to prevent excessive watering in case of sensor faults or unexpected conditions.

Example:

```cpp
const unsigned long MAX_IRRIGATION_MS = 30000;
```

### Cooldown Period

After irrigation completes, the controller enters a cooldown state before allowing another irrigation cycle.

Example:

```cpp
const unsigned long COOLDOWN_MS = 60000;
```

This helps:

* Prevent rapid valve cycling.
* Allow water to distribute through the soil.
* Reduce unnecessary irrigation events.

## Serial Debug Logging

All state transitions are logged to the Serial Monitor for troubleshooting and validation.

Example Output:

```text
[10000 ms] IDLE -> CHECK_SOIL
[10200 ms] CHECK_SOIL -> IRRIGATING
[40200 ms] IRRIGATING -> COOLDOWN
[100200 ms] COOLDOWN -> IDLE
```

These logs provide visibility into controller decisions and simplify debugging.

## Verification Testing

The following checks were performed:

* Verified correct state transitions.
* Confirmed soil debounce prevents false irrigation triggers.
* Verified irrigation stops when maximum runtime is reached.
* Confirmed cooldown period prevents immediate re-triggering.
* Validated Serial transition logs throughout operation.

## Learning Outcomes

* Learned the fundamentals of finite state machine design.
* Implemented structured control logic using `enum` and `switch/case`.
* Improved system robustness through sensor debouncing.
* Added irrigation safety constraints using runtime and cooldown limits.
* Used Serial logging to monitor and debug system behavior.
* Prepared the irrigation controller for advanced automation in future project phases.

