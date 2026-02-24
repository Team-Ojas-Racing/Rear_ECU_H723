#include "enable_logic.h"
#include "can_status.h"

#define RUN_DELAY_MS 500

typedef enum
{
    STATE_OFF,
    STATE_RFE_ACTIVE,
    STATE_RUN_ACTIVE
} EnableState_t;

static EnableState_t currentState = STATE_OFF;
static uint32_t rfe_timestamp = 0;

void EnableLogic_Init(void)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET); // RFE
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET); // RUN
}

void EnableLogic_Update(void)
{
    uint8_t tsms = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
    uint8_t btb  = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9);

    if(btb == GPIO_PIN_RESET)
    {
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
        currentState = STATE_OFF;
        return;
    }

    switch(currentState)
    {
        case STATE_OFF:

            if(tsms && g_shutdown_ok && g_r2d_request)
            {
                HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);
                rfe_timestamp = HAL_GetTick();
                currentState = STATE_RFE_ACTIVE;
            }
            break;

        case STATE_RFE_ACTIVE:

            if(HAL_GetTick() - rfe_timestamp >= RUN_DELAY_MS)
            {
                HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
                currentState = STATE_RUN_ACTIVE;
            }
            break;

        case STATE_RUN_ACTIVE:

            if(!tsms || !g_shutdown_ok || !g_r2d_request)
            {
                HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
                currentState = STATE_OFF;
            }
            break;
    }
}
