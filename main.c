/*
 * En esta práctica se implementó un sistema multitarea con FreeRTOS en el ESP32,
 * donde una misma función de tarea se reutiliza para controlar tres LEDs mediante
 * parámetros distintos enviados con pvParameters. Cada tarea lee un potenciómetro
 * por ADC y ajusta el brillo de su LED correspondiente usando PWM.
 */

#include "leds.h"
#include "adc_reader.h"
#include "tasks.h"

void app_main(void)
{
    //inicializa los canales pwm ledc usados para el brillo de los leds
    leds_init();
    //inicializa el adc y configura canales de potenciometros
    adc_init();
    //creacion de tareas
    create_tasks();
} 
