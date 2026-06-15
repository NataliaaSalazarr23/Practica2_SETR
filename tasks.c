#include <stdio.h>
#include "tasks.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "adc_reader.h"
#include "leds.h"

static void vTaskPotLed(void *pvParameters)
{
    // Se convierte pvParameters al tipo de estructura usado por la tarea
    task_params_t *params =
        (task_params_t*) pvParameters;

    while(1)
    {
        // Lee el valor ADC del canal asignado a esta tarea
        int adc_value =
            adc_read(params->adc_channel);

        // Convierte el valor ADC de 12 bits a un valor PWM de 8 bits
        uint32_t pwm_value =
            (adc_value * 255) / 4095;

        // Convierte el valor ADC a voltaje aproximado
        float voltaje =
            (adc_value * 3.3f) / 4095.0f;

        // Actualiza el brillo del LED correspondiente
        led_set_brightness(
            params->pwm_channel,
            pwm_value
        );

        // Imprime por terminal el estado de la lectura y del PWM
        printf(
            "[%s] ADC=%d  Voltaje=%.2fV  PWM=%lu\n",
            params->nombre,
            adc_value,
            voltaje,
            pwm_value
        );

        // Retardo de 500 ms sin bloquear al planificador de FreeRTOS
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

// Parámetros de la tarea 1: potenciómetro 1 controla LED rojo
static task_params_t pot1 =
{
    .adc_channel = ADC_CHANNEL_6,
    .pwm_channel = LEDC_CHANNEL_0,
    .nombre = "POT1-LED_Rojo"
};

// Parámetros de la tarea 2: potenciómetro 2 controla LED verde
static task_params_t pot2 =
{
    .adc_channel = ADC_CHANNEL_3,
    .pwm_channel = LEDC_CHANNEL_1,
    .nombre = "POT2-LED_Verde"
};

// Parámetros de la tarea 3: potenciómetro 3 controla LED azul
static task_params_t pot3 =
{
    .adc_channel = ADC_CHANNEL_0,
    .pwm_channel = LEDC_CHANNEL_2,
    .nombre = "POT3-LED_Azul"
};

void create_tasks(void)
{
    // Crea la tarea que controla el LED rojo con el potenciómetro 1
    xTaskCreate(
        vTaskPotLed,   // Función que ejecutará la tarea
        "Pot1",        // Nombre de la tarea
        2048,          // Tamaño del stack
        &pot1,         // Parámetros enviados mediante pvParameters
        1,             // Prioridad de la tarea
        NULL           // No se guarda el manejador de la tarea
    );

    // Crea la tarea que controla el LED verde con el potenciómetro 2
    xTaskCreate(
        vTaskPotLed,
        "Pot2",
        2048,
        &pot2,
        1,
        NULL
    );

    // Crea la tarea que controla el LED azul con el potenciómetro 3
    xTaskCreate(
        vTaskPotLed,
        "Pot3",
        2048,
        &pot3,
        1,
        NULL
    );
}
