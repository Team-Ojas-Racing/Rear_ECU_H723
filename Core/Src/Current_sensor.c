#include "current_sensor.h"

void CurrentSensor_Init (current_sens_handle_t *sen, uint16_t *adc_buffer, uint8_t length)
{
    sen->adc_buffer = adc_buffer;
    sen->length = length;
}

float CurrentSensor_Convert(current_sens_handle_t *sen)
{
    float adc_raw= sen->adc_buffer[sen->length];

	float adc_voltage = (adc_raw / adc_resolution) * adc_vref;

    float current = (adc_voltage- current_sensor_vref) / current_sensor_sensitivity;

    return current;
}
