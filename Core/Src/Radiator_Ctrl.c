#include <Radiator_Ctrl.h>

//Fan temp threshold
#define Fan_ON_Threshold     40.0f
#define Fan_OFF_Threshold    38.0f


//connect gpio, htemp and channel index to Fan_Ctrl
void FAN_CTRL_Init(FAN_CTRL_Handle_t *hfan, TEMP_CTS_Handle_t *htemp, uint8_t ch1, uint8_t ch2, GPIO_TypeDef *fan1_port, uint16_t fan1_pin, GPIO_TypeDef *fan2_port, uint16_t fan2_pin)
{
    hfan->temp = htemp;

    hfan->ch1_index = ch1;
    hfan->ch2_index = ch2;

    hfan->fan1_port = fan1_port;
    hfan->fan1_pin  = fan1_pin;

    hfan->fan2_port = fan2_port;
    hfan->fan2_pin  = fan2_pin;
}

void FAN_CTRL_Process(FAN_CTRL_Handle_t *hfan)
{
    static uint8_t fan1_state = 0;
    static uint8_t fan2_state = 0;

    float t1 = TEMP_CTS_GetTemperature(hfan->temp, hfan->ch1_index);
    float t2 = TEMP_CTS_GetTemperature(hfan->temp, hfan->ch2_index);


    //fan 1
    if(!fan1_state && t1 >= Fan_ON_Threshold)                      //to turn on if above
    {
        fan1_state = 1;
        HAL_GPIO_WritePin(hfan->fan1_port, hfan->fan1_pin, GPIO_PIN_SET);
    }
    else if(fan1_state && t1 <= Fan_OFF_Threshold)                 //to turn off if below
    {
        fan1_state = 0;
        HAL_GPIO_WritePin(hfan->fan1_port, hfan->fan1_pin, GPIO_PIN_RESET);
    }


    //fan 2
    if(!fan2_state && t2 >= Fan_ON_Threshold)                      //to turn on if above
    {
        fan2_state = 1;
        HAL_GPIO_WritePin(hfan->fan2_port, hfan->fan2_pin, GPIO_PIN_SET);
    }
    else if(fan2_state && t2 <= Fan_OFF_Threshold)                 //to turn off if below
    {
        fan2_state = 0;
        HAL_GPIO_WritePin(hfan->fan2_port, hfan->fan2_pin, GPIO_PIN_RESET);
    }
}
