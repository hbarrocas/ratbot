#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include "hal/uart.h"
#include "hal/timer.h"
#include "hal/pwm.h"
#include "protocol.h"
#include "application.h"

static app_state_t app;

cmd_status_t motorA(const uint8_t* buffer, uint8_t len) {
  if (len != 3) return CMD_INVALID_PARAM;
  // 16 bit value - receive LSB first, MSB last
  int16_t duty = (uint16_t)buffer[1] | (uint16_t)(buffer[2] << 8);

  if (duty >= 0) {
    app.motorA_duty = duty;
    app.motorA_dir = FORWARD;
  }
  else {
    app.motorA_duty = -duty;
    app.motorA_dir = REVERSE;
  }
  return CMD_OK;
}

cmd_status_t motorB(const uint8_t* buffer, uint8_t len) {
  if (len != 3) return CMD_INVALID_PARAM;
  // 16 bit value - receive LSB first, MSB last
  int16_t duty = (uint16_t)buffer[1] | (uint16_t)(buffer[2] << 8);

  if (duty >= 0) {
    app.motorB_duty = duty;
    app.motorB_dir = FORWARD;
  }
  else {
    app.motorB_duty = -duty;
    app.motorB_dir = REVERSE;
  }
  return CMD_OK;
}

static const protocol_handler_t commands[8] = {
  motorA,
  motorB
};


int main() {

  protocol_state_t proto_st;

  uart_init(9600);
  pwm_init();

  protocol_init(&proto_st, commands, 2);
  app_init(&app);

  sei();

  for (;;) {

    if (uart_available()) {
      uint8_t byte = uart_read();
      protocol_process_byte(&proto_st, byte);
    }

    app_update(&app);

    pwm_set_duty(CHANNEL_A, app.motorA_duty);
    pwm_set_duty(CHANNEL_B, app.motorB_duty);
  }

}

