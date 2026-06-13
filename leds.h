#ifndef LEDS_H
#define LEDS_H

#include "driver/ledc.h"

void leds_init(void);

void led_set_brightness(
    ledc_channel_t channel,
    uint32_t duty
);

#endif