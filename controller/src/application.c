#include "application.h"
#include "hal/timer.h"

void app_init(app_state_t* st) {
  timer_init();

  st->motorA_duty = 0;
  st->motorB_duty = 0;
  st->motorA_dir  = FORWARD;
  st->motorB_dir  = FORWARD;
}

void app_update(app_state_t* st) {}
