# Raspberry Pi Pico Sample application with FreeRTOS

## Introduction

- FreeRTOS kernel library for Pico SDK
- Simple LED blink sample
  - Blinking 3 LEDs using 3 FreeRTOS tasks.
  - LEDs and resistors must be connected to GPIO 13, 14, 15. 

## How to make

Pico SDK environment is required.

- Clone this repository with "--recursive" option.
- Type following commands.
    ```
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make
    ```

## License

BSD 3-Clause (same as Pico SDK)

