#include <avr/io.h>
#include <avr/interrupt.h>
#include "ring_buffer.h"

#define RX_STORAGE_SIZE 64

static uint8_t rx_storage[RX_STORAGE_SIZE];
static ring_buffer_t rx_buffer;

void uart_init(uint32_t baud) {
  uint16_t ubrr = (F_CPU / 16UL / baud) - 1;

  // Pre-scaler: set up baud rate
  UBRR0H = (uint8_t)(ubrr >> 8);
  UBRR0L = (uint8_t)ubrr;

  // Activate RX, TX circuits; Activate Receive Complete interrupt
  UCSR0B |= ((1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0));
  // Use 8 bit data units
  UCSR0C |= ((1 << UCSZ00) | (1 << UCSZ01));

  //Ring buffer init (RX buffer)
  rb_init(&rx_buffer, rx_storage, RX_STORAGE_SIZE);
}

void uart_write(uint8_t data) {
  // Blocking until register is available for sending
  while (!(UCSR0A & (1 << UDRE0)));
  UDR0 = data;
}

uint8_t uart_read(void) {
  uint8_t byte;
  // Blocking until data is available
  while (rb_is_empty(&rx_buffer));
  rb_pop(&rx_buffer, &byte);
  return byte;
}

uint8_t uart_available(void) {
  return !rb_is_empty(&rx_buffer);
}

ISR(USART_RX_vect) {
  uint8_t byte = UDR0;
  rb_push(&rx_buffer, byte);
}

