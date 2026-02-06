# RATBOT

For lack of a better name, I'm calling this small robot, the _ratbot_.

The aim of this project is to learn, practice and flex my skills working with electronics, programming, designing and building, using a combination of techniques where applicable, such as 3D printing, PCB-etching or outsourcing, and good ol' LLM assistance.

## The plan

- Differential steering
- ESP32 controller: manages the motors and rotary encoders
- Raspberry Pi brain: runs the communication, automation where applicable and, communicates with the ESP32 controller
- Sensors (IMU, ultrasonic distance, camera): with exception of the camera being run by the Raspberry Pi, where possible, managed by the ESP32 controller
- Power: Li-ION battery, feeding two separate power supplies; one for control systems (Raspberry Pi + ESP32) and the other for power systems (motors, lights, future attachments)

## Hardware

- Battery: _to be defined_
- Motor driver: TB6612FNG (dual H-bridge, 1.2A)
- Motor Encoder (x2): AS5600: I2C 12bit magnetic
- IMU: _to be defined_
- DC-DC converter (x2): _to be defined_
- Controller: keyestudio ESP32 development board
- Brain: Raspberry Pi 3
    - Camera: Official Raspberry Pi _Camera Module 3_

## Development tools

- Espressif's [esp-idf](https://github.com/espressif/esp-idf/)
- [Python](https://www.python.org)
- [FreeCAD](https://freecad.org)
- [OpenSCAD](https://openscad.org)
- [LibreCAD](https://librecad.org)
- [Vim](https://www.vim.org)

For some of these tools there may be libraries and plug-ins not yet mentioned.

For information about the progress check out the [development.log](development.log).
