#include <avr/io.h>
#include "pwm.h"

#define PWM_TOP 799

static bool pwm_initialised = false;

void pwm_init(void) {
  if (pwm_initialised)
    return;

  // Make channel A and B associated pins as outputs
  DDRB |= ((1 << PB1) | (1 << PB2));

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

  pwm_initialised = true;
}

void pwm_set_duty(pwm_channel_t ch, uint16_t duty) {
  switch (ch) {
    case CHANNEL_A:
      OCR1A = duty < PWM_TOP ? duty : PWM_TOP;
      break;
    case CHANNEL_B:
      OCR1B = duty < PWM_TOP ? duty : PWM_TOP;
      break;
  }
}

