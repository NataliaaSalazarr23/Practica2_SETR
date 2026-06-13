#include "adc_reader.h"

static adc_oneshot_unit_handle_t adc_handle;

void adc_init(void)
{
    adc_oneshot_unit_init_cfg_t init_cfg =
    {
        .unit_id = ADC_UNIT_1
    };

    adc_oneshot_new_unit(
        &init_cfg,
        &adc_handle
    );


        adc_oneshot_chan_cfg_t chan_cfg =
    {
        .bitwidth = ADC_BITWIDTH_12,
        .atten = ADC_ATTEN_DB_12
    };


        adc_oneshot_config_channel(
        adc_handle,
        ADC_CHANNEL_6,
        &chan_cfg
    );

    adc_oneshot_config_channel(
        adc_handle,
        ADC_CHANNEL_3,
        &chan_cfg
    );

    adc_oneshot_config_channel(
        adc_handle,
        ADC_CHANNEL_0,
        &chan_cfg
    );
}


int adc_read(adc_channel_t channel)
{
    int value;

    adc_oneshot_read(
        adc_handle,
        channel,
        &value
    );

    return value;
} 
