#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct {
  uint8_t *data;
  uint16_t size;
  volatile uint16_t head;
  volatile uint16_t tail;
} ring_buffer_t;

void rb_init(ring_buffer_t* rb, uint8_t *storage, uint16_t size);
bool rb_push(ring_buffer_t* rb, uint8_t data);
bool rb_pop(ring_buffer_t* rb, uint8_t *data);
bool rb_is_empty(ring_buffer_t* rb);
bool rb_is_full(ring_buffer_t* rb);

#endif /* _RING_BUFFER_H_ */

