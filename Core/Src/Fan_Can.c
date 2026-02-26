#include "fan_can.h"

//Fan temp threshold
#define Fan_ON_Threshold     40.0f
#define Fan_OFF_Threshold    38.0f


void FAN_CAN_Init(FAN_CAN_Handle_t *hfan,
                  GPIO_TypeDef *p1, uint16_t pin1,
                  GPIO_TypeDef *p2, uint16_t pin2,
                  GPIO_TypeDef *p3, uint16_t pin3,
                  GPIO_TypeDef *p4, uint16_t pin4)
{
    hfan->temperature = 0.0f;  //initial temperature
    hfan->new_data = 0;        //no data yet

    // Initialize all 4 fans
    hfan->fans[0] = (FAN_Output_t){p1, pin1, 0};
    hfan->fans[1] = (FAN_Output_t){p2, pin2, 0};
    hfan->fans[2] = (FAN_Output_t){p3, pin3, 0};
    hfan->fans[3] = (FAN_Output_t){p4, pin4, 0};
}


void FAN_CAN_UpdateTemperature(FAN_CAN_Handle_t *hfan, float temp)
{
    hfan->temperature = temp;             // update temperature
    hfan->new_data = 1;                   // new data available
}


void FAN_CAN_Process(FAN_CAN_Handle_t *hfan)
{
    if (!hfan->new_data)
        return;

    hfan->new_data = 0;                   // Clear flag

    float t = hfan->temperature;
    for (uint8_t i = 0; i < FAN_CAN_COUNT; i++)
    {
        if (!hfan->fans[i].state && t >= Fan_ON_Threshold)
        {
            hfan->fans[i].state = 1;
            HAL_GPIO_WritePin(hfan->fans[i].port, hfan->fans[i].pin, GPIO_PIN_SET);
        }

        else if (hfan->fans[i].state && t <= Fan_OFF_Threshold)
        {
            hfan->fans[i].state = 0;
            HAL_GPIO_WritePin(hfan->fans[i].port, hfan->fans[i].pin, GPIO_PIN_RESET);
        }
    }
}
