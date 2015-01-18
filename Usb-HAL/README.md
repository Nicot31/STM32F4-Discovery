Example of COM port emulation with the USB OTG
============

(The project file is for the em::Blocks IDE)

This sources files contains:
- STM32F4xx HAL Driver (the STM32CubeF4 new hardware abstraction layers)
- Specific configuration for the STM32F4-Discovery board.

This example implements:
- LED 5 is flashing with a period of 2 seconds (1 sec. on, 1 sec. off)
- LED 4 represents the status of the user button (push or not)
- USB OTG emulates a new COM port and echo all incoming characters
