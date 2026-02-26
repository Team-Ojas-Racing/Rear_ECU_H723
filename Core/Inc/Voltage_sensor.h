#ifndef VOLTAGE_SENSOR_H
#define VOLTAGE_SENSOR_H

#include "main.h"

#define adc_resolution        4095.0f     // 12-bit ADC
#define adc_vref              3.3f        // ADC reference voltage

#define Resistance_ratio 4

typedef struct{
	uint16_t *adc_buffer;
	uint8_t  length;
}voltage_sens_handle_t;

void voltageSensor_Init (voltage_sens_handle_t *sen, uint16_t *adc_buffer, uint8_t length);

float voltageSensor_Convert(voltage_sens_handle_t *sen);

#endif

