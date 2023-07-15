#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc.h"

void init_hw(void)
{
    adc1_config_width(ADC_BITWIDTH_12);
}

typedef struct
{
    int v1;
    int v2;
    int v3;
    int i1;
    int i2;
    int i3;
} RawMeasurements;

RawMeasurements getMeasurements()
{
    RawMeasurements measurements;

    measurements.v1 = adc1_get_raw(ADC1_CHANNEL_4);
    measurements.v2 = adc1_get_raw(ADC1_CHANNEL_5);
    measurements.v3 = adc1_get_raw(ADC1_CHANNEL_6);
    measurements.i1 = adc1_get_raw(ADC1_CHANNEL_7);
    measurements.i2 = adc1_get_raw(ADC1_CHANNEL_8);
    measurements.i3 = adc1_get_raw(ADC1_CHANNEL_9);

    return measurements;
}

void app_main()
{
    init_hw();
    RawMeasurements measurements = getMeasurements();
    vTaskDelay(300 / portTICK_PERIOD_MS);
}
