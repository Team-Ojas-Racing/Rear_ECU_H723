#include "adc.h"

static ADC_Handle_t *adc_instance = NULL;

void ADC_Init(ADC_Handle_t *hadc_obj, ADC_HandleTypeDef *hadc, uint16_t *buffer, uint8_t length)
{
    hadc_obj->hadc = hadc;
    hadc_obj->buffer = buffer;
    hadc_obj->length = length;
    hadc_obj->data_ready = 0;

    adc_instance = hadc_obj;
}


//to start adc
HAL_StatusTypeDef ADC_Start(ADC_Handle_t *hadc_obj)
{
    return HAL_ADC_Start_DMA(hadc_obj->hadc, (uint32_t*)hadc_obj->buffer, hadc_obj->length);
}


//to check if conversion is completed
uint8_t ADC_DataReady(ADC_Handle_t *hadc_obj)
{
    return hadc_obj->data_ready;
}


//after conversion set data ready to 0 for next cycle
void ADC_ClearFlag(ADC_Handle_t *hadc_obj)
{
    hadc_obj->data_ready = 0;
}


//
uint16_t ADC_GetValue(ADC_Handle_t *hadc_obj, uint8_t index)
{
    if(index >= hadc_obj->length)
        return 0;

    return hadc_obj->buffer[index];
}

// conversion complete
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if(adc_instance != NULL)
    {
        if(hadc == adc_instance->hadc)
        {
            adc_instance->data_ready = 1;
        }
    }
}
