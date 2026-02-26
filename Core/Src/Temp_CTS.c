#include "temp_cts.h"

#define ADC_MAX_VALUE     4095.0f
#define VREF              3.3f
#define R_FIXED           100.0f
#define V_SUPPLY          5.0f
#define PT100_R0          100.0f
#define PT100_ALPHA       0.00390f
#define PT100_BETA        -0.0000005775f




//functions for conversion:
static float ADC_ToVoltage(uint16_t adc_value)
{
    return ((float)adc_value * VREF) / ADC_MAX_VALUE;
}

static float Voltage_ToResistance(float v_measured)
{
    return (v_measured * R_FIXED) / (V_SUPPLY - v_measured);
}

static float Resistance_ToTemperature(float resistance)
{
    return (- PT100_ALPHA + sqrt(PT100_ALPHA * PT100_ALPHA - 4 * PT100_BETA * (1-(resistance)/R_FIXED))) / (2 * PT100_BETA);
}




//connect adc handle to temp struct
void TEMP_CTS_Init(TEMP_CTS_Handle_t *htemp, ADC_Handle_t *hadc)
{
    htemp->adc = hadc;
}




//if data_ready=1, the conversion takes place for all the channels, then data ready is reset
void TEMP_CTS_Process(TEMP_CTS_Handle_t *htemp)
{
    if(!ADC_DataReady(htemp->adc))
        return;

    for(uint8_t i = 0; i < htemp->adc->length; i++)
    {
        uint16_t raw = ADC_GetValue(htemp->adc, i);
        float voltage = ADC_ToVoltage(raw);
        float resistance = Voltage_ToResistance(voltage);
        htemp->temperature[i] = Resistance_ToTemperature(resistance);
    }

    ADC_ClearFlag(htemp->adc);
}




//if index greater then
float TEMP_CTS_GetTemperature(TEMP_CTS_Handle_t *htemp, uint8_t index)
{
    if(index >= htemp->adc->length)
        return 0.0f;

    return htemp->temperature[index];
}

