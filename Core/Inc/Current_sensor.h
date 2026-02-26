#ifndef CURRENT_SENSOR_H
#define CURRENT_SENSOR_H

#include <stdint.h>

#define adc_resolution        4095.0f     // 12-bit ADC
#define adc_vref              3.3f        // ADC reference voltage

#define current_sensor_vref           0.00f
#define current_sensor_sensitivity    0.00f

typedef struct{
	uint16_t *adc_buffer;
	uint8_t  length;
}current_sens_handle_t;

void CurrentSensor_Init (current_sens_handle_t *sen, uint16_t *adc_buffer, uint8_t length);

float CurrentSensor_Convert(current_sens_handle_t *sen);

#endif
