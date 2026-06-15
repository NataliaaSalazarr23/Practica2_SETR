#include "adc_reader.h"

// Manejador global del ADC en modo oneshot
static adc_oneshot_unit_handle_t adc_handle;

void adc_init(void)
{
    // Configuración inicial de la unidad ADC1
    adc_oneshot_unit_init_cfg_t init_cfg =
    {
        .unit_id = ADC_UNIT_1
    };

    // Crea e inicializa la unidad ADC
    adc_oneshot_new_unit(
        &init_cfg,
        &adc_handle
    );

    // Configuración común para los canales ADC
    adc_oneshot_chan_cfg_t chan_cfg =
    {
        .bitwidth = ADC_BITWIDTH_12,  // Resolución de 12 bits: valores de 0 a 4095
        .atten = ADC_ATTEN_DB_12      // Atenuación para leer aproximadamente de 0 a 3.3 V
    };

    // Configura el canal ADC 6
    adc_oneshot_config_channel(
        adc_handle,
        ADC_CHANNEL_6,
        &chan_cfg
    );

    // Configura el canal ADC 3
    adc_oneshot_config_channel(
        adc_handle,
        ADC_CHANNEL_3,
        &chan_cfg
    );

    // Configura el canal ADC 0
    adc_oneshot_config_channel(
        adc_handle,
        ADC_CHANNEL_0,
        &chan_cfg
    );
}

int adc_read(adc_channel_t channel)
{
    int value;

    // Lee el valor crudo del canal ADC indicado
    adc_oneshot_read(
        adc_handle,
        channel,
        &value
    );

    // Regresa el valor ADC obtenido, entre 0 y 4095
    return value;
}
