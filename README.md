# RATBOT

For lack of a better name, I'm calling this small robot, the _ratbot_.

The aim of this project is to learn, practice and flex my skills working with electronics, programming, designing and building, using a combination of techniques where applicable, such as 3D printing, PCB-etching or outsourcing, and good ol' LLM assistance.

## The plan

To make a _mission oriented_ robot. What do I mean by this? - Instead of _driving_ the robot with a remote control in the sense of how one drives a car, I want to be able to give this robot a mission and let it figure out how to complete it. This will involve understanding the order, navigating its environment by detecting its surroundings and avoiding obstacles.

### Specifications (and nice-to-haves)
- Differential steering
- Arduino Nano based motion controller, programmed without Arduino toolchain dependency
- Raspberry Pi brain: runs the communication, automation where applicable and, communicates with the motion controller
- Sensors such as rotary encoders and accelerometer managed by the motion controller
- Power: Li-ION battery, feeding two separate power supplies; one for control systems (Raspberry Pi + controller) and the other for power systems (motors, lights, future attachments)

## Hardware

- Battery: _to be defined_
- Motor driver: TB6612FNG (dual H-bridge, 1.2A)
- Motor Encoder (x2): AS5600: I2C 12bit magnetic
- IMU: _to be defined_
- DC-DC converter (x2): _to be defined_
- Controller: Arduino Nano developement board
- Brain: Raspberry Pi 3
    - Camera: Official Raspberry Pi _Camera Module 3_
    - Debian (Raspbian) linux OS

## Development tools

- AVR-GCC
- avrdude
- [Python](https://www.python.org)
- [FreeCAD](https://freecad.org)
- [Vim](https://www.vim.org)

For some of these tools there may be libraries and plug-ins not yet mentioned.

For information about the progress check out the [development.log](./development.log).
