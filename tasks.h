#ifndef TASKS_H
#define TASKS_H

#include "esp_adc/adc_oneshot.h"
#include "driver/ledc.h"

typedef struct
{
    adc_channel_t adc_channel;
    ledc_channel_t pwm_channel;

    const char *nombre;
    
} task_params_t;

void create_tasks(void);

#endif