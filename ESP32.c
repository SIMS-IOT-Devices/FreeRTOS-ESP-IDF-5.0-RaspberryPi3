// ESP IDF 5.0
// Receive analog input

#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soc/soc_caps.h"
#include "esp_log.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"

void app_main(void)
{
    adc_oneshot_unit_handle_t adc1_handle;
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT_1,
    };
    adc_oneshot_new_unit(&init_config1, &adc1_handle);

    while (1)
    {
        int adc_raw;
        float voltage;
        adc_oneshot_read(adc1_handle, ADC_CHANNEL_0, &adc_raw);
        voltage = (float)adc_raw * 5 / (float)4096;
        printf("%0.0f\n", voltage);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}