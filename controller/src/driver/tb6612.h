#ifndef __TB6612_H__
#define __TB6612_H__

#include <stdint.h>

void tb6612_init(void);
void tb6612_enable(void);
void tb6612_disable(void);
void tb6612_set_power(int16_t, int16_t);

#endif /* __TB6612_H__ */
