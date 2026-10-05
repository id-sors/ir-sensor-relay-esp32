# IR Sensor-Controlled Relay Switch (ESP32)

A touchless switch built with an ESP32, an IR sensor and a relay module.
Wave your hand in front of the sensor to turn an LED on, and wave again to turn it off.

## Components
- ESP32 development board
- IR obstacle sensor module
- 5V relay module
- LED + resistor (220 Ω to 1 kΩ)
- Jumper wires and breadboard

## How it works
1. The IR sensor outputs LOW when it detects an object.
2. The ESP32 detects the change from "no object" to "object".
3. Each detection flips the relay state, switching the LED on or off.
4. A 300 ms debounce prevents one wave from toggling twice.

## What I learned
- How relays work (COM, NO, NC)
- Debouncing sensor input in code
- Debugging hardware step by step

## Possible improvements
- Use two sensors to detect people entering and leaving
- Add decoupling capacitors for a more stable supply
- Switch an AC bulb through the relay (with proper safety precautions)

## How to run
1. Open `ir_relay_toggle.ino` in the Arduino IDE.
2. Select your ESP32 board and port.
3. Upload and open the Serial Monitor at 115200 baud.