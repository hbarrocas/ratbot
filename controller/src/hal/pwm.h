#ifndef _PWM_H_
#define _PWM_H_

typedef enum {
  CHANNEL_A,
  CHANNEL_B
} pwm_channel_t;

void pwm_init(void);
void pwm_set_duty(pwm_channel_t ch, uint16_t duty);

#endif /* _PWM_H_ */
