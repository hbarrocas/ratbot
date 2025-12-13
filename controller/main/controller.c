#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "driver/uart.h"
#include "esp_log.h"

#define UART_NUM       UART_NUM_0
#define UART_BUF_SIZE  256

static const char *TAG = "ratbot";


typedef struct {
  char line[128];
} command_t;

static QueueHandle_t command_queue;


static void uart_rx_task(void *arg)
{
  uint8_t data[UART_BUF_SIZE];
  char line[128];
  int pos = 0;

  while(1) {
    int len = uart_read_bytes(UART_NUM, data, sizeof(data), pdMS_TO_TICKS(100));
    for (int i = 0; i < len; i++) {
      char c = data[i];
      if (c == '\n' || c == '\r') {
        if (pos > 0) {
          line[pos] = 0;
          command_t cmd;
          strncpy(cmd.line, line, sizeof(cmd.line));
          xQueueSend(command_queue, &cmd, 0);
          pos = 0;
        }
      }
      else if (pos < sizeof(line) - 1) line[pos++] = c;
    }
  }
}


static void motor_task(void *arg)
{
  command_t cmd;

  while(1) {
    if (xQueueReceive(command_queue, &cmd, portMAX_DELAY)) {
      ESP_LOGI(TAG, "CMD: %s", cmd.line);

      if (strncmp(cmd.line, "MOVE", 4) == 0) {
        printf("OK\n");
      }
      else if (strncmp(cmd.line, "STOP", 4) == 0) {
        printf("OK\n");
      }
      else if (strncmp(cmd.line, "PING", 4) == 0) {
        printf("PONG\n");
      }
      else {
        printf("Error: unknown command: %s\n", cmd.line);
      }
    }
  }
}


static void sensor_task(void *arg)
{
  while(1) {
    printf("Sensors: HDG=000 DIST=0 ATT=0,0\n");
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}


void app_main(void)
{
  uart_driver_install(UART_NUM, UART_BUF_SIZE * 2, 0, 0, NULL, 0);
  command_queue = xQueueCreate(10, sizeof(command_t));

  xTaskCreate(uart_rx_task, "uart_rx", 4096, NULL, 10, NULL);
  xTaskCreate(motor_task, "motor", 4096, NULL, 9, NULL);
  xTaskCreate(sensor_task, "sensor", 2048, NULL, 5, NULL);

  ESP_LOGI(TAG, "ratbot controller: ready");
}
