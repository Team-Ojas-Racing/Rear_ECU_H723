#ifndef FAN_CAN_H
#define FAN_CAN_H

#include "main.h"

#define FAN_CAN_COUNT 4   // Total number of CAN-controlled fans

//
typedef struct
{
    GPIO_TypeDef *port;   // GPIO port
    uint16_t pin;         // GPIO pin number
    uint8_t state;        // fan state

} FAN_Output_t;


//
typedef struct
{
    float temperature;    // Last received CAN temperature
    uint8_t new_data;     // Flag: 1 if new CAN data arrived

    FAN_Output_t fans[FAN_CAN_COUNT];  // Array of fan outputs

} FAN_CAN_Handle_t;


//initialize gpio
void FAN_CAN_Init(FAN_CAN_Handle_t *hfan,
                  GPIO_TypeDef *p1, uint16_t pin1,
                  GPIO_TypeDef *p2, uint16_t pin2,
                  GPIO_TypeDef *p3, uint16_t pin3,
                  GPIO_TypeDef *p4, uint16_t pin4);

//Update temperature when CAN message arrives
void FAN_CAN_UpdateTemperature(FAN_CAN_Handle_t *hfan, float temp);

//
void FAN_CAN_Process(FAN_CAN_Handle_t *hfan);

#endif
