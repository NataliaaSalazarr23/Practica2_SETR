#ifndef ADC_READER_H
#define ADC_READER_H

#include "esp_adc/adc_oneshot.h"

void adc_init(void);

int adc_read(adc_channel_t channel);

#endif