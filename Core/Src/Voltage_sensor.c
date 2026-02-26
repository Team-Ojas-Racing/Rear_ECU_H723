#include "Voltage_sensor.h"

void voltageSensor_Init (voltage_sens_handle_t *sen, uint16_t *adc_buffer, uint8_t length)
{
    sen->adc_buffer = adc_buffer;
    sen->length = length;
}

float voltageSensor_Convert(voltage_sens_handle_t *sen)
{
    float adc_raw= sen->adc_buffer[sen->length];

    float adc_voltage = (adc_raw / adc_resolution) * adc_vref;

    float voltage= adc_voltage*4;

    return voltage;
}
