# Home Automation Project

## Introduction

This project is focused on Home Automation and was prototyped during the summer of 2021, with further refinements in the summer of 2023. If you're a science enthusiast, you may find this project interesting as it delves into concepts of IoT (Internet of Things), Cloud Computing, and Microcontrollers.

## Purpose

The primary objective of this project was to automate home appliances such as lights, fans, and air conditioners. Additionally, the project enables users to monitor the status of these devices directly from their mobile devices, laptops, or any internet-enabled device.

## Apparatus

The following components were used in this project:

1. **ESP8266 Wi-Fi Microchip**:
   - Acts as the core controller and enables internet connectivity for the project.
   - The NodeMCU ESP8266 Wi-Fi Module was used.
   
2. **4-Channel Relay Module**:
   - Functions as an electronic switch to control up to four appliances.
   - It can be triggered by digital signals (0 or 1) from the microcontroller.

3. **3D Printed Case**:
   - A custom-designed case to house all components, including the microcontroller, relay module, and wires.

4. **Adapter (with Type B Cable)**:
   - Provides power to the ESP8266 and the relay module.
   - A 4 ~ 4.5V adapter was used despite the ESP8266’s 3.3V tolerance, which proved to be manageable.

5. **Wires**:
   - Jumper wires for connecting microcontroller pins to the relay module.
   - Silver wires for connecting retro switches to the relay modules.

6. **Infrared (IR) LED**:
   - Used for controlling appliances like air conditioners.

## Circuitry

### Microcontroller Pin Usage
- GPIO pins 2, 5, 12, 13, and 14 of the ESP8266 were used for this project.
- A 3.3V power supply and GND pins were used to provide power to the relay module.

### Relay Circuitry
- **Inlets**: Normally Closed (NC), Normally Opened (NO), and Common Contact (Common).
- **Functionality**:
  - When no external signal is applied, Common and NC are connected.
  - When an external signal is applied, Common and NO are connected, acting as a "CloudSwitch" for the project.

### LED
- The LED was connected to the ESP8266 using a GPIO and GND pin.

## Code Implementation

The **Arduino IoT Cloud** was used to generate control signals for operating the appliances. The project leverages the [Arduino IRRemote Library](https://github.com/Arduino-IRremote/Arduino-IRremote) by Ken Sherriff to send and receive infrared signals with multiple protocols.

## Challenges

- Some pins of the ESP8266 are HIGH during boot, which causes connected appliances to turn ON unexpectedly. This issue complicates handling power cuts.
- **Proposed Solutions**:
  - Use pins that remain LOW during boot.
  - Integrate a UPS (Uninterrupted Power Supply) to mitigate the effects of power cuts.

## References

1. [Arduino IRRemote Library](https://github.com/Arduino-IRremote/Arduino-IRremote): Infrared remote library for Arduino.
2. IoT and Cloud Computing resources for controlling appliances.

---

This project serves as an excellent introduction to Home Automation and IoT concepts for students and enthusiasts.
