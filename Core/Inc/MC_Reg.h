#ifndef FS_CAN_PROTOCOL_H
#define FS_CAN_PROTOCOL_H

#include "stdint.h"

#define MC_CAN_ID_TX                0x201U   // Master → Motor controller
#define MC_CAN_ID_RX                0x181U   // Motor controller → Master


/* ==========================================================
   DATA LENGTH CODE (DLC)
   ========================================================== */

#define CAN_DLC_16BIT_RX            3U
#define CAN_DLC_32BIT_RX            5U

#define CAN_DLC_16BIT_TX            4U
#define CAN_DLC_32BIT_TX            6U


/* ==========================================================
   BYTE POSITION IN CAN DATA FIELD
   ========================================================== */

#define MC_BYTE_REGID               0U
#define MC_BYTE_DATA_LSB            1U
#define MC_BYTE_DATA_MSB            2U
#define MC_BYTE_DATA_2              3U
#define MC_BYTE_DATA_3              4U


/* ==========================================================
   MOTOR CONTROLLER REGISTERS (REGID)
   ========================================================== */

#define MC_REG_SPEED_CMD            0x31U
#define MC_REG_POSITION_CMD         0x6EU
#define MC_REG_TORQUE_CMD           0x90U

#define MC_REG_ACCELERATION         0x35U

#define MC_REG_STATUS               0x40U
#define MC_REG_MODE                 0x51U
#define MC_REG_EVENT_MASK           0x52U

#define MC_REG_CAN_ID_CONFIG        0x68U
#define MC_REG_READ_REQUEST         0x3DU

#define MC_REG_WRITE_EEPROM         0x84U


/* ==========================================================
   MODE REGISTER BITS (REGID 0x51)
   ========================================================== */

#define MC_MODE_ENABLE_OFF          (1U << 2)   // disable / lock
#define MC_MODE_ENABLE_ON           0x0000U     // enable / unlock


/* ==========================================================
   STATUS REGISTER BITS (REGID 0x40)
   ========================================================== */

#define MC_STATUS_ENABLE            (1U << 0)
#define MC_STATUS_POSITION_CTRL     (1U << 7)
#define MC_STATUS_SPEED_CTRL        (1U << 8)
#define MC_STATUS_CALIBRATED        (1U << 12)


/* ==========================================================
   EVENT MASK CONFIGURATION (REGID 0x52)
   ========================================================== */

#define MC_EVENT_CONTINUOUS_CURRENT 0x20U
#define MC_EVENT_LIMIT_SWITCH       0x12U


/* ==========================================================
   AUTOMATIC CAN SIGNAL REGISTERS
   ========================================================== */

#define MC_REG_SPEED_ACTUAL         0x30U
#define MC_REG_SPEED_CMD_RAMP       0x32U

#define MC_REG_IQ_CMD               0x22U
#define MC_REG_IQ_ACTUAL            0x27U

#define MC_REG_VDC_BUS              0x66U
#define MC_REG_VOLTAGE_OUTPUT       0x8AU

#define MC_REG_TEMP_IGBT            0x4AU
#define MC_REG_TEMP_MOTOR           0x49U


/* ==========================================================
   COMMAND VALUES
   ========================================================== */

#define MC_DISABLE_VALUE            0x0004U
#define MC_EEPROM_SAVE              0x0001U


/* ==========================================================
   HELPER MACROS
   ========================================================== */

#define CAN_GET_UINT16(data) \
        ((uint16_t)((data[2] << 8) | data[1]))

#define CAN_SET_UINT16(data,val) \
do { \
    data[1] = (uint8_t)((val) & 0xFFU); \
    data[2] = (uint8_t)((val) >> 8); \
} while(0)

#define CAN_SET_UINT32(data,val) \
do { \
    data[1] = (uint8_t)((val) & 0xFFU); \
    data[2] = (uint8_t)((val) >> 8); \
    data[3] = (uint8_t)((val) >> 16); \
    data[4] = (uint8_t)((val) >> 24); \
} while(0)


/* ==========================================================
   SPEED SCALE
   ========================================================== */

#define MC_SPEED_MAX_NUM            32767U

#define MC_TELEMETRY_ONCE           0x00U
#define MC_TELEMETRY_STOP           0xFFU


#endif
