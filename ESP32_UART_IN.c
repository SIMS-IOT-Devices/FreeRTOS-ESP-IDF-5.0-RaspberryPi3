// ESP IDF 5.0
// Receive a string via RS232

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/uart.h"
#include "soc/uart_struct.h"
#include "string.h"

#define UART_0_TX 1
#define UART_0_RX 3

void init_RS232()
{
    const uart_port_t uart_num = UART_NUM_0;
    const int uart_buffer_size = 1024;
    QueueHandle_t uart_queue;

    // 1 - Setting Communication Parameters
    const uart_config_t uart_config = {             
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE};
    uart_param_config(uart_num, &uart_config);
    
    // 2 - Setting Communication Pins
    uart_set_pin(uart_num, UART_0_TX, UART_0_RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    // 3 - Driver Installation
    uart_driver_install(uart_num, uart_buffer_size, uart_buffer_size, 10, &uart_queue, 0);
}

static void rx_task()
{
    const uart_port_t uart_num = UART_NUM_0;
    int length = 0;
    uint8_t data[128];

    while (1)
    {
        uart_get_buffered_data_len(uart_num, (size_t *)&length); // Read data string length
        uart_read_bytes(uart_num, data, length, 100); // Read data string from the buffer
        printf("ESP32 data received: %.*s", length, data);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
    printf("Receive data:\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    init_RS232();
    xTaskCreate(rx_task, "uart_rx_task", 1024 * 2, NULL, configMAX_PRIORITIES - 1, NULL);
}
