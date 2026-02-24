#include "can_status.h"

volatile uint8_t g_shutdown_ok = 0;
volatile uint8_t g_r2d_request = 0;

void CAN_Status_Process(uint32_t id, uint8_t *data)
{
    if(id == SHUTDOWN_CAN_ID)
    {
        g_shutdown_ok = data[0];
    }
    else if(id == R2D_CAN_ID)
    {
        g_r2d_request = data[0];
    }
}
