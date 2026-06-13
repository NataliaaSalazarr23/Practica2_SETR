#include "leds.h"
#include "adc_reader.h"
#include "tasks.h"

void app_main(void)
{
    leds_init();

    adc_init();

    create_tasks();
}