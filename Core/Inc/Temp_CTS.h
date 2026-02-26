
#ifndef TEMP_CTS_H
#define TEMP_CTS_H

#include "adc.h"
#include <stdint.h>

typedef struct
{
    ADC_Handle_t *adc;
    float temperature[10];   // supports up to 10 channels

} TEMP_CTS_Handle_t;

void TEMP_CTS_Init(TEMP_CTS_Handle_t *htemp, ADC_Handle_t *hadc);

void TEMP_CTS_Process(TEMP_CTS_Handle_t *htemp);

float TEMP_CTS_GetTemperature(TEMP_CTS_Handle_t *htemp, uint8_t index);

#endif
