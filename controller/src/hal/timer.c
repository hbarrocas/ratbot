#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include "timer.h"

static volatile uint32_t timer_count_ms;
static bool timer_initialised = false;

void timer_init() {
  if (timer_initialised)
    return;

  // CTC mode
  TCCR0A |= (1 << WGM01);
  // F_CPU/64 - 250,000 ticks per second
  TCCR0B |= ((1 << CS00) | (1 << CS01));
  // Activate timer interrupt
  TIMSK0 |= (1 << OCIE0A);
  // Compare value set to 1ms
  OCR0A = 249; 

  timer_count_ms = 0;
  timer_initialised = true;
}

uint32_t get_system_time() {
  uint32_t now;

  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    now = timer_count_ms;
  }

  return now;
}

ISR(TIMER0_COMPA_vect) {
  timer_count_ms++;
}
