#include <Arduino.h>
#include "motor.h"

Motor::Motor() {
	_enabled = false;
	_speed = 0;
	_p_pwm = _p_in1 = _p_in2 = 0;
}

void Motor::init(uint8_t pin_pwm, uint8_t pin_in1, uint8_t pin_in2) {
	_p_pwm = pin_pwm;
	_p_in1 = pin_in1;
	_p_in2 = pin_in2;

	pinMode(_p_pwm, OUTPUT);
	pinMode(_p_in1, OUTPUT);
	pinMode(_p_in2, OUTPUT);

	_enabled = true;
}

void Motor::set_speed(int16_t speed) {
	if (!_enabled) return;
	_speed = constrain(speed, -MOTOR_SPEED_MAX, MOTOR_SPEED_MAX);
	bool inverted = _speed < 0;
	uint8_t dutycycle = static_cast<uint8_t>(abs((int)_speed));

	digitalWrite(_p_in1, inverted ? LOW : HIGH);
	digitalWrite(_p_in2, inverted ? HIGH : LOW);
	analogWrite(_p_pwm, dutycycle);
}

int16_t Motor::get_speed() {
	return _speed;
}

void Motor::brake() {
	if (!_enabled) return;
	_speed = 0;
	
	analogWrite(_p_pwm, 0);
	digitalWrite(_p_in1, HIGH);
	digitalWrite(_p_in2, HIGH);
}
