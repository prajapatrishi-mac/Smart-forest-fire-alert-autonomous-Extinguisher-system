# Wiring Guide
## Smart Forest Fire Alert and Autonomous Extinguisher System

This document describes the intended connections for the Arduino Uno prototype.

## 1. Arduino Pin Connections

| Component | Component Pin | Arduino Connection |
|---|---|---|
| Flame Sensor | DO | D2 |
| Flame Sensor | VCC | Appropriate supply voltage |
| Flame Sensor | GND | GND |
| Buzzer | Signal / + | D3 |
| Buzzer | GND / - | GND |
| Red LED | Anode through resistor | D5 |
| Red LED | Cathode | GND |
| Green LED | Anode through resistor | D6 |
| Green LED | Cathode | GND |
| Relay Module | IN | D7 |
| Relay Module | VCC | According to module specifications |
| Relay Module | GND | GND |
| Servo Motor | Signal | D9 |
| Servo Motor | Power | Suitable supply |
| Servo Motor | GND | Common GND |
| MQ-2 Sensor | AO | A0 |
| MQ-2 Sensor | VCC | According to module specifications |
| MQ-2 Sensor | GND | GND |
| OLED Display | SDA | A4 |
| OLED Display | SCL / SCK | A5 |
| OLED Display | VDD | Compatible supply voltage |
| OLED Display | GND | GND |

## 2. OLED Display

For an Arduino Uno:

- SDA connects to A4.
- SCL connects to A5.
- VDD connects to the voltage supported by the OLED module.
- GND connects to GND.
- The sketch is configured for I2C address 0x3C.

Check the labels and voltage specifications printed on the actual OLED module.

## 3. Water Pump and Relay

The relay switches the pump's separate power circuit.

General arrangement:

1. Connect the relay control pins to the Arduino as specified above.
2. Connect the pump's external supply through the relay's correctly rated contacts.
3. Use the relay COM and NO terminals if the pump should normally remain off.
4. Confirm the pump's voltage and current ratings before connecting it.
5. Keep the pump and water away from the Arduino and breadboard.

Do not connect the pump directly to the Arduino's 5V pin.

**Important:** Relay contact wiring depends on the pump supply and relay module. Confirm the module's ratings and wiring diagram before applying power.

## 4. Power and Ground

- Power the Arduino using a suitable supply.
- Power the pump separately using a supply that matches its specifications.
- A separately powered servo may need a common ground with the Arduino.
- Connect grounds as required for the control signals.
- Never connect battery terminals directly to an Arduino GPIO pin.
- Do not charge a Li-ion battery without a suitable charging circuit.

## 5. Important Pin Assumptions

The supplied sketch assumes:

- Flame sensor output is active LOW.
- Relay input is active LOW.
- MQ-2 analog readings above the configured threshold indicate smoke.
- Servo movement from 0 to 90 degrees represents the demonstration mechanism.

Actual modules may behave differently. Verify each assumption before operating the pump.

## 6. Safety

Disconnect power before changing wiring. Test the relay with the pump disconnected first. Never use a real fire to test the flame sensor.
<img width="1472" height="3264" alt="1000034990" src="https://github.com/user-attachments/assets/0cd64a83-36f5-4dd4-96cd-76e00b99480c" />
