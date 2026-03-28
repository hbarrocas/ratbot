#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#include <stdint.h>

#define PROTOCOL_SOF          0xAA
#define PROTOCOL_BUFFER_SIZE  8

typedef enum {
  CMD_OK,
  CMD_ERROR,
  CMD_INVALID_PARAM
} cmd_status_t;
typedef cmd_status_t (*protocol_handler_t)(const uint8_t*, uint8_t);

typedef enum {
  WAIT_SOF,
  READ_LEN,
  READ_PAYLOAD,
  READ_CRC
} parser_state_t;

typedef struct {
  uint8_t handlers_len;
  const protocol_handler_t* handlers;
  parser_state_t stage;
  uint8_t buffer_len;
  uint8_t buffer_index;
  uint8_t buffer[PROTOCOL_BUFFER_SIZE];
} protocol_state_t;

void protocol_init(protocol_state_t* st, const protocol_handler_t* handlers, uint8_t len);
void protocol_process_byte(protocol_state_t* st, uint8_t byte);

#endif /* _PROTOCOL_H_ */
