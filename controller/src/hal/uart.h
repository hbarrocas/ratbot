#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>

void uart_init(uint32_t);
void uart_write(uint8_t);
uint8_t uart_read(void);
uint8_t uart_available(void);

#endif /* _UART_H_ */
