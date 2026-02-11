#include <Arduino.h>

constexpr uint8_t MOTOR_SPEED_MAX = 255;

class Motor {
public:
	Motor();
	void init(uint8_t pin_pwm, uint8_t pin_in1, uint8_t pin_in2);
	void set_speed(int16_t speed);
	int16_t get_speed();
	void brake();

private:
	bool _enabled;
	int _speed;
	uint8_t _p_pwm;
	uint8_t _p_in1;
	uint8_t _p_in2;
};
