#ifndef ADC_H
#define ADC_H

#include "main.h"
#include <stdint.h>

typedef struct
{
    ADC_HandleTypeDef *hadc;      // HAL ADC handle
    uint16_t *buffer;             // DMA buffer
    uint8_t length;               // number of channels
    volatile uint8_t data_ready;  //conversion check

} ADC_Handle_t;


void ADC_Init(ADC_Handle_t *hadc_obj, ADC_HandleTypeDef *hadc, uint16_t *buffer, uint8_t length);


HAL_StatusTypeDef ADC_Start(ADC_Handle_t *hadc_obj);


uint8_t ADC_DataReady(ADC_Handle_t *hadc_obj);


void ADC_ClearFlag(ADC_Handle_t *hadc_obj);


uint16_t ADC_GetValue(ADC_Handle_t *hadc_obj, uint8_t index);

#endif
