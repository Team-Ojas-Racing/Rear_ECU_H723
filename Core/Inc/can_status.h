#ifndef CAN_STATUS_H
#define CAN_STATUS_H

#include "main.h"

#define SHUTDOWN_CAN_ID   0x100
#define R2D_CAN_ID        0x101

extern volatile uint8_t g_shutdown_ok;
extern volatile uint8_t g_r2d_request;

void CAN_Status_Process(uint32_t id, uint8_t *data);

#endif
