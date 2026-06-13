#include <stdio.h>
#include "tasks.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "adc_reader.h"
#include "leds.h"


static void vTaskPotLed(void *pvParameters)
{
    task_params_t *params =
        (task_params_t*) pvParameters;

    while(1)
    {
        int adc_value =
            adc_read(params->adc_channel);

        uint32_t pwm_value =
            (adc_value * 255) / 4095;

        float voltaje =
            (adc_value * 3.3f) / 4095.0f;

        led_set_brightness(
            params->pwm_channel,
            pwm_value
        );

         printf(
        "[%s] ADC=%d  Voltaje=%.2fV  PWM=%lu\n",
        params->nombre,
        adc_value,
        voltaje,
        pwm_value
    );

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}



static task_params_t pot1 =
{
    .adc_channel = ADC_CHANNEL_6,
    .pwm_channel = LEDC_CHANNEL_0,
    .nombre = "POT1-LED_Rojo"
};

static task_params_t pot2 =
{
    .adc_channel = ADC_CHANNEL_3,
    .pwm_channel = LEDC_CHANNEL_1,
    .nombre = "POT2-LED_Verde"
};

static task_params_t pot3 =
{
    .adc_channel = ADC_CHANNEL_0,
    .pwm_channel = LEDC_CHANNEL_2,
    .nombre = "POT3-LED_Azul"
};



void create_tasks(void)
{
    xTaskCreate(
        vTaskPotLed,
        "Pot1",
        2048,
        &pot1,
        1,
        NULL
    );

    xTaskCreate(
        vTaskPotLed,
        "Pot2",
        2048,
        &pot2,
        1,
        NULL
    );

    xTaskCreate(
        vTaskPotLed,
        "Pot3",
        2048,
        &pot3,
        1,
        NULL
    );
}