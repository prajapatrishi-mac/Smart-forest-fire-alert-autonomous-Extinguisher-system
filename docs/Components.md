# Components List
## Smart Forest Fire Alert and Autonomous Extinguisher System

### 1. Main Components

| S.No. | Component | Quantity | Purpose |
|---|---|---|---|
| 1 | Arduino Uno | 1 | Main controller |
| 2 | Flame Sensor | 1 | Detects flames |
| 3 | MQ-2 Gas/Smoke Sensor | 1 | Detects smoke and certain gases |
| 4 | 0.96-inch I2C OLED Display | 1 | Displays system status and alerts |
| 5 | Servo Motor | 1 | Demonstrates the extinguisher mechanism |
| 6 | Buzzer | 1 | Provides an audible fire alert |
| 7 | Relay Module | 1 | Controls the water pump |
| 8 | Water Pump | 1 | Demonstrates water delivery |
| 9 | Li-ion Battery | As required | Power source |
| 10 | Breadboard | 1 | Circuit prototyping |
| 11 | Jumper Wires | As required | Electrical connections |
| 12 | Red LED | 1 | Indicates fire or smoke detection |
| 13 | Green LED | 1 | Indicates the safe state |
| 14 | Resistors (220–330 ohms) | 2 | Protects the indicator LEDs |

### 2. Component Functions

**Arduino Uno:** Reads sensor inputs and controls the outputs.
<img width="1080" height="1440" alt="1000031171" src="https://github.com/user-attachments/assets/f977e646-e559-4016-aeab-8104e50bf239" />

**Flame Sensor:** Detects a flame within the sensor's detection range.
<img width="1080" height="1440" alt="1000031220" src="https://github.com/user-attachments/assets/0babb782-9396-444a-8c1c-15b04c2e835e" />

**MQ-2 Sensor:** Detects smoke and certain combustible gases. It requires warm-up time and threshold calibration.
<img width="1080" height="1440" alt="1000031200" src="https://github.com/user-attachments/assets/6067a01c-d341-407a-a864-7a7c25443b95" />

**OLED Display:** Shows startup information, SAFE status, FIRE ALERT, SMOKE ALERT, or a combined alert.
<img width="3264" height="1472" alt="1000034335" src="https://github.com/user-attachments/assets/128edafe-2114-477a-a886-9f40c6934cef" />

**Servo Motor:** Demonstrates movement of the proposed automatic extinguisher mechanism.
<img width="1080" height="1440" alt="1000031176" src="https://github.com/user-attachments/assets/bf9eeecb-be98-430e-8099-e54071ca3759" />

**Buzzer:** Sounds when a fire condition is detected.
<img width="1472" height="3264" alt="1000034633" src="https://github.com/user-attachments/assets/93e03f9f-b3cc-45b6-9af3-08953d5deae2" />

**Relay Module:** Switches the pump circuit on or off.
<img width="3264" height="1472" alt="1000034634" src="https://github.com/user-attachments/assets/35f4afbe-38c4-4c92-ad3f-8449333e3d86" />

**Water Pump:** Demonstrates the water-delivery mechanism.

**LED Indicators:** Green indicates the normal state. Red indicates a detected fire or smoke condition.

### 3. Software Requirements

- Arduino IDE or a compatible Arduino programming application
- Servo library
- Wire library
- Custom OLED display code included in the project sketch

### 4. Important Notes

- The listed components describe the prototype configuration.
- Verify the voltage and current requirements of every component.
- Never power the water pump directly from an Arduino GPIO pin.
- Use a suitable external pump supply and a correctly rated relay module.
- Keep water away from the Arduino and other electronic components.
- This educational prototype is not a certified forest-fire detection or firefighting system.
