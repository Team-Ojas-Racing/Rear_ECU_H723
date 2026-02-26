#ifndef RADIATOR_CTRL_H
#define RADIATOR_CTRL_H

#include "main.h"
#include "temp_cts.h"
#include <stdint.h>

typedef struct
{
    TEMP_CTS_Handle_t *temp;

    uint8_t ch1_index;
    uint8_t ch2_index;

    GPIO_TypeDef *fan1_port;
    uint16_t fan1_pin;

    GPIO_TypeDef *fan2_port;
    uint16_t fan2_pin;

} FAN_CTRL_Handle_t;

void FAN_CTRL_Init(FAN_CTRL_Handle_t *hfan,
                   TEMP_CTS_Handle_t *htemp,
                   uint8_t ch1,
                   uint8_t ch2,
                   GPIO_TypeDef *fan1_port,
                   uint16_t fan1_pin,
                   GPIO_TypeDef *fan2_port,
                   uint16_t fan2_pin);

void FAN_CTRL_Process(FAN_CTRL_Handle_t *hfan);

#endif
