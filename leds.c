#include <stdint.h>
#include "leds.h"

// GPIO de cada LED
#define LED_RED     26
#define LED_GREEN   25
#define LED_BLUE    33

void leds_init(void)
{
    ledc_timer_config_t timer =
    {
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .duty_resolution = LEDC_TIMER_8_BIT,
        .freq_hz = 5000,
        .clk_cfg = LEDC_AUTO_CLK
    };

    ledc_timer_config(&timer);

    

        ledc_channel_config_t red =
    {
        .gpio_num = LED_RED,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel = LEDC_CHANNEL_0,
        .timer_sel = LEDC_TIMER_0,
        .duty = 0
    };

    ledc_channel_config(&red);


        ledc_channel_config_t green =
    {
        .gpio_num = LED_GREEN,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel = LEDC_CHANNEL_1,
        .timer_sel = LEDC_TIMER_0,
        .duty = 0
    };

    ledc_channel_config(&green);


        ledc_channel_config_t blue =
    {
        .gpio_num = LED_BLUE,
        .speed_mode = LEDC_HIGH_SPEED_MODE,
        .channel = LEDC_CHANNEL_2,
        .timer_sel = LEDC_TIMER_0,
        .duty = 0
    };

    ledc_channel_config(&blue);
}



void led_set_brightness(
    ledc_channel_t channel,
    uint32_t duty
)
{
    ledc_set_duty(
        LEDC_HIGH_SPEED_MODE,
        channel,
        duty
    );

    ledc_update_duty(
        LEDC_HIGH_SPEED_MODE,
        channel
    );
}