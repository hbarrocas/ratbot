# RATBOT

## Motion Controller

In simple terms, the Motion Controller is in charge of the wheels. The controller
will accept commands via USB serial port and will abstract all the electronic
complexity that is i2c buses, ports and PID calculations, under a reduced set of
commands that allow the robot to move forward, backward and turn at controllable
speed.

### Safeguards that will (hopefully) be included

- Stop if disconnected (implement ping)
- deactivate motor if wheel seized (damage protection)

### Hardware

- Based on Arduino Nano development board
- AS5600 rotary encoders
- TB6612FNG dual H-Bridge

### Development tools

- Compiler: `avr-gcc`
- Autmation: `make`
- Flashing utility: `avrdude`

### Compile/Flash instructions

All commands are scripted in the `Makefile`.

```bash
# Compile and upload:
$ make upload

# Compile only:
$ make

# delete artifacts - clean
$ make clean
```

### Testing

Included is the `control.py` script, used to send _Binary framed_ commands
via UART to the controller.

Instructions coming soon; my project time is up for today.
