#include <stdint.h>
#include "leds.h"

// GPIO asignado al LED rojo
#define LED_RED     26

// GPIO asignado al LED verde
#define LED_GREEN   25

// GPIO asignado al LED azul
#define LED_BLUE    33

void leds_init(void)
{
    // Configuración del temporizador LEDC para generar PWM
    ledc_timer_config_t timer =
    {
        .speed_mode = LEDC_HIGH_SPEED_MODE,   // Modo de alta velocidad del periférico LEDC
        .timer_num = LEDC_TIMER_0,            // Se utiliza el temporizador 0
        .duty_resolution = LEDC_TIMER_8_BIT,  // Resolución de 8 bits: valores de 0 a 255
        .freq_hz = 5000,                      // Frecuencia PWM de 5 kHz
        .clk_cfg = LEDC_AUTO_CLK              // Selección automática del reloj
    };

    // Aplica la configuración del temporizador LEDC
    ledc_timer_config(&timer);

    // Configuración del canal PWM para el LED rojo
    ledc_channel_config_t red =
    {
        .gpio_num = LED_RED,                  // Pin GPIO del LED rojo
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel = LEDC_CHANNEL_0,            // Canal PWM 0
        .timer_sel = LEDC_TIMER_0,            // Usa el temporizador configurado
        .duty = 0                             // Inicia apagado
    };

    ledc_channel_config(&red);

    // Configuración del canal PWM para el LED verde
    ledc_channel_config_t green =
    {
        .gpio_num = LED_GREEN,                // Pin GPIO del LED verde
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel = LEDC_CHANNEL_1,            // Canal PWM 1
        .timer_sel = LEDC_TIMER_0,
        .duty = 0
    };

    ledc_channel_config(&green);

    // Configuración del canal PWM para el LED azul
    ledc_channel_config_t blue =
    {
        .gpio_num = LED_BLUE,                 // Pin GPIO del LED azul
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel = LEDC_CHANNEL_2,            // Canal PWM 2
        .timer_sel = LEDC_TIMER_0,
        .duty = 0
    };

    ledc_channel_config(&blue);
}

void led_set_brightness(ledc_channel_t channel, uint32_t duty)
{
    // Establece el ciclo de trabajo PWM del canal indicado
    ledc_set_duty(
        LEDC_HIGH_SPEED_MODE,
        channel,
        duty
    );

    // Actualiza físicamente la salida PWM con el nuevo duty
    ledc_update_duty(
        LEDC_HIGH_SPEED_MODE,
        channel
    );
}
