#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <stdint.h>
#include <stdbool.h>

#define FORWARD true
#define REVERSE false

typedef struct {
  uint16_t motorA_duty;
  uint16_t motorB_duty;
  bool motorA_dir;
  bool motorB_dir;
} app_state_t;

void app_init(app_state_t* st);
void app_update(app_state_t* st);

#endif /* _APPLICATION_H_ */
