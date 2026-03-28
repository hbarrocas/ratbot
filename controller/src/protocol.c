#include "protocol.h"
#include "crc.h"

void protocol_init(protocol_state_t* st, const protocol_handler_t* handlers, uint8_t len) {
  st->handlers = handlers;
  st->handlers_len = len;
  st->stage = WAIT_SOF;
  st->buffer_index = 0;
}

void protocol_process_byte(protocol_state_t* st, uint8_t byte) {
  
  switch(st->stage) {
    case WAIT_SOF:
      if (byte == PROTOCOL_SOF)
        st->stage = READ_LEN;
      break;

    case READ_LEN:
      if (byte > PROTOCOL_BUFFER_SIZE) {
        // will return an error.
        // Now, resets state machine
        st->stage = WAIT_SOF;
        break;
      }
      st->buffer_len = byte;
      st->buffer_index = 0;
      st->stage = READ_PAYLOAD;
      break;

    case READ_PAYLOAD:
      st->buffer[st->buffer_index++] = byte;
      if (st->buffer_index >= st->buffer_len)
        st->stage = READ_CRC;
      break;

    case READ_CRC:
      st->stage = WAIT_SOF;

      if (byte != crc8(st->buffer, st->buffer_len))
        break;

      uint8_t id = st->buffer[0];
      if (id < st->handlers_len && st->handlers[id])
        st->handlers[id](st->buffer, st->buffer_len);
      break;
  }
}

