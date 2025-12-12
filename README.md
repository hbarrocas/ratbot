# RATBOT

For lack of a better name, I'm calling this small autonomous moving robot, the _ratbot_.

The aim of this project is to learn, practice and flex my skills working with electronics, programming, designing and building, using a combination of techniques where applicable, such as 3D printing, PCB-etching or outsourcing, and good ol' LLM assistance.

## The plan

The design is as follows:

- Li-ION battery - initially a power bank, further developing own charging circuitry and even a charging station like the ones used by robot vacuum cleaners.
- Independent motorised wheels, further developing them into caterpillars. Servo motors if a robotic limb is later developed.
- Ultrasonic distance sensor, accelerometer, magnetometer, motor high current excess sensors for immediate sensory awareness.
- Battery, motors and sensors will be abstracted under a USB-serial controller (ESP32). This controller receives commands to perform actions, such as activating motors, changing speeds, disabling or enabling devices, etc. It will return real-time sensory status on request. It will also apply safeguards such as monitoring battery temperature and act accordingly, stop a motor if a maximum allowed current is exceeded, and report back with an error code.
- Higher level logic is done by a Raspberry Pi, running a lean linux OS, python, a camera and connected via USB to the ESP32 controller. This computer will be the _brain_ of the robot, allowing me to run autonomous machine learning as well as a remote shell for direct control, should it be needed.

The sensors managed by the ESP32 will allow the robot to have immediate sensory awareness, in the same way we would handle ourselves if we were blind. The camera on the Raspberry Pi will enhance this and work in combination with the other sensors to learn its environment and make decisions.
