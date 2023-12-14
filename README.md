# Standup Desk Controller

This project is a simple, yet powerful, controller for a standup desk. It is designed to control the up and down movements of the desk using a microcontroller.

## Features

- Control the up and down movements of a standup desk.
- Uses low power for efficient operation.
- LED indication for operation status.
- Serial communication for debugging and monitoring.

## Hardware Requirements

- A microcontroller (code is written for Arduino).
- Two digital inputs for up and down control.
- Four digital outputs for motor control.

## Software Requirements

- Arduino IDE for compiling and uploading the code to the microcontroller.

## Installation

1. Clone this repository to your local machine.
2. Open the `src.ino` file in Arduino IDE.
3. Connect your Arduino to your computer.
4. Compile and upload the code to your Arduino.

## Usage

The project uses the following pins for operation:

- `DI_UP` (pin 2): Digital input for moving the desk up.
- `DI_DOWN` (pin 3): Digital input for moving the desk down.
- `MOTOR_START_UP` (pin 5), `MOTOR_UP` (pin 9): Control the motor for moving the desk up.
- `MOTOR_START_DOWN` (pin 7), `MOTOR_DOWN` (pin 10): Control the motor for moving the desk down.

To move the desk up, provide a high signal to `DI_UP`. To move the desk down, provide a high signal to `DI_DOWN`.

## Contributing

Contributions are welcome. Please open an issue to discuss your idea or submit a pull request.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
