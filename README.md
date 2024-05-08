# AVR Atmega32 Drivers

This repository contains a collection of drivers for Atmega32 microcontroller peripherals, organized into three layers: MCAL (Microcontroller Abstraction Layer), HAL (Hardware Abstraction Layer), and an application layer for testing purposes.

## Contents

### MCAL Layer
- DIO: Driver for configuring and controlling GPIO (General Purpose Input/Output) pins.
  - `DIO_enumSetPinConfig`: Configures pins as input or output and sets their configuration type.
  - `DIO_enumSetPortConfig`: Configures the entire port as input or output.
  - `DIO_enumSetPin`: Sets individual pins to logic high or logic low.
  - `DIO_enumSetPort`: Sets the entire port to logic high or logic low.
  - `DIO_enumReadState`: Reads the logic state of a pin (high or low).
  - `DIO_enumSetPortValue`: Sets the value of an entire port.
  - `DIO_DelayMs`: Delays execution by a specified time in milliseconds.

- Port Module: This module provides functions for initializing and configuring ports for general input/output operations.
  - `Init_PORT`: Configures pins as input or output and configures them by pre or post-configuration. 
  
- EXTI Module:
  - External Interrupts driver for handling external interrupt events.


### HAL Layer
- LED: Driver for controlling LED operations, including initialization and setting LED states.
  - `LED_enumInit`: Configures the pins of LEDs.
  - `LED_enumSetLedState`: Sets the value of a specific LED.

- Switch: Driver for reading switch/button inputs and providing their states.
  - `SWITCH_enumInit`: Configures the pins of switches.
  - `SWITCH_enumReadValue`: Reads the value of a specific switch.

- 7Segment: Driver for controlling 7-segment displays, including initialization and setting display values.
  - `Seven_SEG_enumInit`: Configures the pins of Seven Segment displays.
  - `Seven_SEG_enumSetValue`: Sets the value of a specific Seven Segment display.
  - `Seven_SEG_enumSetValueForAll`: Sets a common value for all Seven Segment displays.


### Application Layer
- Contains test applications to check on the functionality of each driver.

