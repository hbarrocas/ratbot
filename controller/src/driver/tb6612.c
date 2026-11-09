#include <avr/io.h>

#define PWM_TOP 799

#define MOTOR_A_PWM    PB1
#define MOTOR_A_FWD    PD7
#define MOTOR_A_REV    PD6
#define MOTOR_B_PWM    PB2
#define MOTOR_B_FWD    PD4
#define MOTOR_B_REV    PD3

#define TB6612_STDBY   PD5

void pwm_init(void) {
  // Set fast PWM, TOP = ICR1 (mode 14)
  TCCR1A |= (1 << WGM11);
  TCCR1B |= ((1 << WGM12) | (1 << WGM13));  
  // Compare Output Mode: Non-inverting mode for channels A & B
  TCCR1A |= ((1 << COM1A1) | (1 << COM1B1));

  // F_CPU / 800 = 20kHz: set compare value to (800 - 1);
  ICR1 = PWM_TOP;

  OCR1A = 0;
  OCR1B = 0;
  // Prescaler: timer runs at F_CPU
  TCCR1B |= (1 << CS10);
}

void pwm_set_A(uint16_t duty) {
  OCR1A = duty;
}

void pwm_set_B(uint16_t duty) {
  OCR1B = duty;
}

void tb6612_init(void) {
  // set PWM channels A and B associated pins as outputs
  DDRB |= (
		  (1 << MOTOR_A_PWM) |
		  (1 << MOTOR_B_PWM));
  // set control pins as outputs
  DDRD |= (
		  (1 << MOTOR_A_FWD) |
		  (1 << MOTOR_A_REV) |
		  (1 << MOTOR_B_FWD) |
		  (1 << MOTOR_B_REV) |
		  (1 << TB6612_STDBY));
  // Initialise PWM timing logic
  pwm_init();
}

void tb6612_enable(void) {
  PORTD |= (1 << TB6612_STDBY);
}

void tb6612_disable(void) {
  PORTD &= ~(1 << TB6612_STDBY);
}

void tb6612_set_power(int16_t motor_a, int16_t motor_b) {
  if (motor_a > PWM_TOP) motor_a = PWM_TOP;
  else if (motor_a < -PWM_TOP) motor_a = -PWM_TOP;

  if (motor_b > PWM_TOP) motor_b = PWM_TOP;
  else if (motor_b < -PWM_TOP) motor_b = -PWM_TOP;

  if (motor_a >= 0) {
	  PORTD |= (1 << MOTOR_A_FWD);
	  PORTD &= ~(1 << MOTOR_A_REV);
	  pwm_set_A(motor_a);
  }
  else {
	  PORTD |= (1 << MOTOR_A_REV);
	  PORTD &= ~(1 << MOTOR_A_FWD);
	  pwm_set_A(-motor_a);
  }

  if (motor_b >= 0) {
	  PORTD |= (1 << MOTOR_B_FWD);
	  PORTD &= ~(1 << MOTOR_B_REV);
	  pwm_set_B(motor_b);
  }
  else {
	  PORTD |= (1 << MOTOR_B_REV);
	  PORTD &= ~(1 << MOTOR_B_FWD);
	  pwm_set_B(-motor_b);
  }
}
