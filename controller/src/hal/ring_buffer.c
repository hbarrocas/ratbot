#include <stdint.h>
#include <stdbool.h>
#include "ring_buffer.h"

void rb_init(ring_buffer_t* rb, uint8_t *storage, uint16_t size) {
  rb->data = storage;
  rb->size = size;
  rb->head = rb->tail = 0;
}

bool rb_is_empty(ring_buffer_t* rb) {
  return rb->head == rb->tail;
}

bool rb_is_full(ring_buffer_t* rb) {
  return ((rb->head + 1) % rb->size) == rb->tail;
}

bool rb_push(ring_buffer_t* rb, uint8_t data) {
  uint16_t next = (rb->head + 1) % rb->size;
  if (next == rb->tail) return false;
  rb->data[rb->head] = data;
  rb->head = next;
  return true;
}

bool rb_pop(ring_buffer_t* rb, uint8_t* data) {
  if (rb->tail == rb->head) return false;
  *data = rb->data[rb->tail];
  rb->tail = (rb->tail + 1) % rb->size;
  return true;
}
