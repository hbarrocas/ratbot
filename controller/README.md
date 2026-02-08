# RATBOT

## Motion Controller

In simple terms, the Motion Controller is in charge of the wheels. The controller
will accept commands via USB serial port and will abstract all the electronic
complexity that is i2c buses, ports and PID calculations, under a reduced set of
commands that allow the robot to move forward, backward and turn at controllable
speed.

### Safeguards that will be included

- Stop if disconnected (implement ping)
- deactivate motor if wheel seized (damage protection)

### Hardware

- Based on Arduino Nano development board
- AS5600 rotary encoders
- TB6612FNG dual H-Bridge

### Software

- Arduino-cli (includes all Arduino libraries)
- Written in C++ instead of .ino (staying closer to the real embedded world)

### Compile/Flash instructions

Inside the `controller/` folder there's a `controller.ino` stub, needed for the
Arduino-cli environment to work. The relevant code exists under `src/`, where the
top level source file is `main.cpp`.

```bash
$ cd controller/
$ arduino-cli compile -v --fqbn arduino:avr:nano:cpu=atmega328old
[...]
$ arduino-cli upload -v -p /dev/ttyUSB0 --fqdn arduino:avr:nano:cpu=atmega328old
[...]
```

