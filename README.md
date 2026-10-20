# 🌲 Smart Forest Fire Alert and Autonomous Extinguisher System

An Arduino-based educational prototype designed to detect potential fire and smoke conditions, display alerts, activate a buzzer when fire is detected, and demonstrate automatic pump control.

## 📌 Project Overview

Forest fires can damage trees, destroy wildlife habitats, and threaten nearby communities.

This project explores how sensors and a microcontroller can be combined to detect potential fire and smoke conditions and provide alerts.

The system uses an Arduino Uno, a flame sensor, an MQ-2 smoke sensor, an OLED display, a buzzer, a servo motor, LEDs, and a relay-controlled water pump.

**Project type:** Electronics, Arduino, Automation  
**Controller:** Arduino Uno  
**Development time:** 52.7 hours  
**Project status:** Prototype development and hardware verification

## 🎯 Objectives

- Detect potential flames using a flame sensor.
- Monitor smoke and certain gases using an MQ-2 sensor.
- Display system status and alerts on an OLED screen.
- Activate a buzzer when a fire condition is detected.
- Demonstrate servo movement during a fire alert.
- Demonstrate pump control through a relay.
- Use LEDs to indicate system status.
- Learn Arduino programming, electronics, and troubleshooting.

## 🧰 Components Required

| No. | Component | Quantity |
|---|---|---|
| 1 | Arduino Uno | 1 |
| 2 | Flame Sensor Module | 1 |
| 3 | MQ-2 Smoke/Gas Sensor | 1 |
| 4 | 0.96-inch I2C OLED Display | 1 |
| 5 | Servo Motor | 1 |
| 6 | Buzzer | 1 |
| 7 | Relay Module | 1 |
| 8 | Mini Water Pump | 1 |
| 9 | Red LED | 1 |
| 10 | Green LED | 1 |
| 11 | 220–330 Ω Resistors | 2 |
| 12 | Breadboard | 1 |
| 13 | Jumper Wires | As required |
| 14 | Suitable Battery and Power Supplies | As required |
<img width="1440" height="1080" alt="1000031215" src="https://github.com/user-attachments/assets/ccbeb3d7-2fd8-43b3-89ba-af45855f63af" />
<img width="3264" height="1472" alt="1000034635" src="https://github.com/user-attachments/assets/27b2d0fc-9029-4d35-843c-6bccabd3073b" />
<img width="1080" height="1440" alt="1000031216" src="https://github.com/user-attachments/assets/8605d173-4b74-4f45-8552-ce67e86ce8eb" />
<img width="3264" height="1472" alt="1000034634" src="https://github.com/user-attachments/assets/6f46a3d9-b954-4880-960e-4795a62b70b9" />
<img width="1472" height="3264" alt="1000034633" src="https://github.com/user-attachments/assets/9b1bcb75-ad3b-4f70-87f5-4bc19c3267b0" />
<img width="1080" height="1440" alt="1000031218" src="https://github.com/user-attachments/assets/8509dbd0-126b-4cf1-9a36-777e90d59079" />
<img width="3264" height="1472" alt="1000034335" src="https://github.com/user-attachments/assets/b9956bac-3bed-4c4e-9e02-8f7394be3266" />
<img width="1080" height="1440" alt="1000031212" src="https://github.com/user-attachments/assets/b3c2f475-cd0b-45c4-8c6b-5274562dc5d7" />
<img width="1836" height="3264" alt="1000031036" src="https://github.com/user-attachments/assets/31b0f847-667c-4da4-9820-21c6539c35bd" />
<img width="1440" height="1080" alt="1000031213" src="https://github.com/user-attachments/assets/d7cb2df8-650d-4c14-93b8-8a4239e825fe" />
<img width="1280" height="960" alt="1000034818" src="https://github.com/user-attachments/assets/57fb1493-da36-43ca-9f52-3f3d8588c2ca" />
<img width="468" height="1040" alt="1000034590" src="https://github.com/user-attachments/assets/8c4dac85-9905-40e5-ad1d-52fbdf8001ea" />
<img width="1080" height="1440" alt="1000031163" src="https://github.com/user-attachments/assets/92ee47fb-ca5a-4230-b2c7-5d0bfe4bb5cd" />
<img width="468" height="1040" alt="1000034593" src="https://github.com/user-attachments/assets/435ba2bc-c26a-4677-803b-fcd679c10d6d" />
<img width="1080" height="1440" alt="1000031220" src="https://github.com/user-attachments/assets/881d7ca0-d391-477c-9454-e8f14a4c92f7" />
<img width="1472" height="3264" alt="1000034641" src="https://github.com/user-attachments/assets/c08a196e-d4f1-4cfb-979d-0c7baebb3cd2" />
<img width="1472" height="3264" alt="1000034640" src="https://github.com/user-attachments/assets/fd016d89-b039-41de-9ae6-d352bae61c8f" />


See [`docs/COMPONENTS.md`](docs/COMPONENTS.md) for component details and [`docs/BOM.csv`](docs/BOM.csv) for the estimated bill of materials.

## 🔌 Wiring Connections

| Component | Arduino Pin |
|---|---|
| Flame Sensor DO | D2 |
| Buzzer Signal | D3 |
| Red LED | D5 through a resistor |
| Green LED | D6 through a resistor |
| Relay IN | D7 |
| Servo Signal | D9 |
| MQ-2 Analog Output | A0 |
| OLED SDA | A4 |
| OLED SCL | A5 |
<img width="1472" height="3264" alt="1000034990" src="https://github.com/user-attachments/assets/a734c875-e6fe-42e2-a890-cbf6be910e45" />


The OLED sketch is configured for I2C address `0x3C`.

**Important:** These connections depend on the actual modules and their electrical specifications. Check the complete wiring guide before applying power.

See [`docs/WIRING.md`](docs/WIRING.md).

## ⚙️ How It Works

### 1. Startup

The OLED is intended to display:

`DEVELOP BY RITIK PRAJAPAT`

### 2. Normal Condition

When neither sensor reports a detection:
- OLED displays `SAFE`.
- Green LED indicates the normal state.
- Buzzer remains off.
- Servo stays at its normal position.
- Relay remains in the pump-off state.

### 3. Fire Detection

When the flame sensor reports a fire condition:
- OLED displays `FIRE ALERT`.
- Buzzer activates.
- Servo moves toward 90 degrees.
- Red LED indicates fire detection.

### 4. Smoke Detection

When the MQ-2 reading crosses the configured threshold:
- OLED displays `SMOKE ALERT`.
- Relay controls the pump circuit.
- Red LED indicates smoke detection.
- Smoke alone does not activate the buzzer or servo.

### 5. Combined Detection

When both fire and smoke conditions are detected, the display is intended to show a combined alert while the corresponding outputs remain active.

Actual behavior must be verified on the assembled circuit.

## 💻 Arduino Code

The Arduino sketch is located here:

[`src/forest_fire_alert.ino`](src/Arduino_code.ino)
<img width="1440" height="1080" alt="1000031211" src="https://github.com/user-attachments/assets/ba5a0d56-62fc-4f15-9626-fa8dc17aefd1" />
<img width="1440" height="1080" alt="1000031210" src="https://github.com/user-attachments/assets/77e43e78-8d82-454b-a51a-9a0fce15615c" />
<img width="1440" height="1080" alt="1000031209" src="https://github.com/user-attachments/assets/286d9f98-8204-4e02-a3e5-59f148f79abb" />


### Software Requirements

- Arduino IDE or a compatible Arduino programming application
- Arduino Uno board support
- Servo library
- Wire library

The sketch uses custom OLED display code rather than requiring the Adafruit SSD1306 and Adafruit GFX libraries.

### Upload Instructions

1. Open `src/Arduino_code.ino`.
2. Connect the Arduino Uno to your device.
3. Select the Arduino Uno board.
4. Select the correct serial port.
5. Compile the sketch.
6. Upload it to the board.
7. Check the OLED, sensors, LEDs, buzzer, servo, and relay separately.<img width="1600" height="720" alt="1000034997" src="https://github.com/user-attachments/assets/16a5158c-8437-4430-88d6-15fad72ec106" />
<img width="720" height="1600" alt="1000034994" src="https://github.com/user-attachments/assets/cdabf1e4-1d93-4818-b329-94b2a51a4951" />
<img width="1600" height="720" alt="1000034991" src="https://github.com/user-attachments/assets/8c81b0ea-2107-4c77-8db8-ac560bde778b" />



The code is a starting point and has not been verified against every physical hardware configuration.

## 🧪 Testing

Test each component individually before testing the complete system.

- Verify the OLED startup message.
- Check the flame sensor's output polarity.
- Observe the MQ-2 analog readings and calibrate its threshold.
- Verify the servo's movement.
- Test the buzzer.
- Check the relay with the pump disconnected.
- Test the combined detection logic.

Only report a test as successful after performing it on the actual hardware.


<img width="720" height="1280" alt="1000035000" src="https://github.com/user-attachments/assets/df17374b-66b9-40f3-b2f9-6727a3ba595d" />

