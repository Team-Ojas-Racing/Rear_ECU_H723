#ifndef VEHICLE_CAN_MESSAGES_H
#define VEHICLE_CAN_MESSAGES_H

#include <stdint.h>

/* ==========================================================
   CAN IDS (LOWER ID = HIGHER PRIORITY)
   ========================================================== */

#define CAN_ID_SAFETY_STATUS        0x001U
#define CAN_ID_READY_TO_DRIVE       0x010U
#define CAN_ID_DRIVER_INPUT         0x014U

#define MC_CAN_ID_TX                0x201U   // Master → Motor controller
#define MC_CAN_ID_RX                0x181U   // Motor controller → Master

#define CAN_ID_BMS_MAIN             0x280U
#define CAN_ID_BMS_SAFETY           0x281U
#define CAN_ID_BMS_STACK1           0x282U
#define CAN_ID_BMS_STACK2           0x283U

#define CAN_ID_WHEEL_SPEED          0x300U
#define CAN_ID_IMU_DATA             0x301U

#define CAN_ID_DASHBOARD            0x400U


/* ==========================================================
   FIXED DLC (8 BYTES FOR EVERY FRAME)
   ========================================================== */

#define CAN_FRAME_DLC               8U


/* ==========================================================
   SAFETY STATUS MESSAGE
   CAN ID : 0x001
   ========================================================== */

#define SAFETY_BYTE_STATUS          0U

#define SAFETY_BIT_SHUTDOWN         (1U << 0)
#define SAFETY_BIT_PRECHARGE_DONE   (1U << 1)
#define SAFETY_BIT_IMD_FAULT        (1U << 2)
#define SAFETY_BIT_BMS_FAULT        (1U << 3)

#define SAFETY_RESERVED_BITS        0xF0U

#define SAFETY_BYTE_RESERVED1       1U
#define SAFETY_BYTE_RESERVED2       2U
#define SAFETY_BYTE_RESERVED3       3U
#define SAFETY_BYTE_RESERVED4       4U
#define SAFETY_BYTE_RESERVED5       5U
#define SAFETY_BYTE_RESERVED6       6U
#define SAFETY_BYTE_RESERVED7       7U


/* ==========================================================
   READY TO DRIVE MESSAGE
   CAN ID : 0x010
   ========================================================== */

#define RTD_BYTE_STATUS             0U

#define RTD_BIT_REQUEST             (1U << 0)
#define RTD_BIT_ACTIVE              (1U << 1)

#define RTD_RESERVED_BITS           0xFCU

#define RTD_BYTE_RESERVED1          1U
#define RTD_BYTE_RESERVED2          2U
#define RTD_BYTE_RESERVED3          3U
#define RTD_BYTE_RESERVED4          4U
#define RTD_BYTE_RESERVED5          5U
#define RTD_BYTE_RESERVED6          6U
#define RTD_BYTE_RESERVED7          7U


/* ==========================================================
   DRIVER INPUT MESSAGE
   CAN ID : 0x014
   ========================================================== */

#define DRIVER_BYTE_APPS1_L         0U
#define DRIVER_BYTE_APPS1_H         1U

#define DRIVER_BYTE_APPS2_L         2U
#define DRIVER_BYTE_APPS2_H         3U

#define DRIVER_BYTE_BRAKE_L         4U
#define DRIVER_BYTE_BRAKE_H         5U

#define DRIVER_BYTE_RESERVED1       6U
#define DRIVER_BYTE_RESERVED2       7U


/* ==========================================================
   MOTOR CONTROLLER COMMAND
   CAN ID : 0x201
   ========================================================== */

#define MC_CMD_BYTE_REGID           0U
#define MC_CMD_BYTE_DATA_L          1U
#define MC_CMD_BYTE_DATA_H          2U
#define MC_CMD_BYTE_DATA2           3U
#define MC_CMD_BYTE_DATA3           4U

#define MC_CMD_BYTE_RESERVED1       5U
#define MC_CMD_BYTE_RESERVED2       6U
#define MC_CMD_BYTE_RESERVED3       7U


/* ==========================================================
   MOTOR CONTROLLER FEEDBACK
   CAN ID : 0x181
   ========================================================== */

#define MC_FB_BYTE_REGID            0U
#define MC_FB_BYTE_DATA0            1U
#define MC_FB_BYTE_DATA1            2U
#define MC_FB_BYTE_DATA2            3U
#define MC_FB_BYTE_DATA3            4U

#define MC_FB_BYTE_RESERVED1        5U
#define MC_FB_BYTE_RESERVED2        6U
#define MC_FB_BYTE_RESERVED3        7U


/* ==========================================================
   BMS MAIN DATA
   CAN ID : 0x280
   ========================================================== */

#define BMS_MAIN_BYTE_PACK_VOLT_L   0U
#define BMS_MAIN_BYTE_PACK_VOLT_H   1U

#define BMS_MAIN_BYTE_PACK_CURR_L   2U
#define BMS_MAIN_BYTE_PACK_CURR_H   3U

#define BMS_MAIN_BYTE_SOC           4U
#define BMS_MAIN_BYTE_TEMP          5U

#define BMS_MAIN_BYTE_RESERVED1     6U
#define BMS_MAIN_BYTE_RESERVED2     7U


/* ==========================================================
   BMS SAFETY DATA
   CAN ID : 0x281
   ========================================================== */

#define BMS_SAFE_BYTE_FAULT_L       0U
#define BMS_SAFE_BYTE_FAULT_H       1U

#define BMS_SAFE_BYTE_WARN_L        2U
#define BMS_SAFE_BYTE_WARN_H        3U

#define BMS_SAFE_BYTE_RESERVED1     4U
#define BMS_SAFE_BYTE_RESERVED2     5U
#define BMS_SAFE_BYTE_RESERVED3     6U
#define BMS_SAFE_BYTE_RESERVED4     7U


/* ==========================================================
   BMS STACK1 VOLTAGES
   CAN ID : 0x282
   ========================================================== */

#define BMS_STACK1_BYTE_CELL1_L     0U
#define BMS_STACK1_BYTE_CELL1_H     1U

#define BMS_STACK1_BYTE_CELL2_L     2U
#define BMS_STACK1_BYTE_CELL2_H     3U

#define BMS_STACK1_BYTE_CELL3_L     4U
#define BMS_STACK1_BYTE_CELL3_H     5U

#define BMS_STACK1_BYTE_CELL4_L     6U
#define BMS_STACK1_BYTE_CELL4_H     7U


/* ==========================================================
   BMS STACK2 VOLTAGES
   CAN ID : 0x283
   ========================================================== */

#define BMS_STACK2_BYTE_CELL1_L     0U
#define BMS_STACK2_BYTE_CELL1_H     1U

#define BMS_STACK2_BYTE_RESERVED1   2U
#define BMS_STACK2_BYTE_RESERVED2   3U
#define BMS_STACK2_BYTE_RESERVED3   4U
#define BMS_STACK2_BYTE_RESERVED4   5U
#define BMS_STACK2_BYTE_RESERVED5   6U
#define BMS_STACK2_BYTE_RESERVED6   7U


/* ==========================================================
   WHEEL SPEED (REAR ONLY)
   CAN ID : 0x300
   ========================================================== */

#define WHEEL_BYTE_RL_L             0U
#define WHEEL_BYTE_RL_H             1U

#define WHEEL_BYTE_RR_L             2U
#define WHEEL_BYTE_RR_H             3U

#define WHEEL_BYTE_RESERVED1        4U
#define WHEEL_BYTE_RESERVED2        5U
#define WHEEL_BYTE_RESERVED3        6U
#define WHEEL_BYTE_RESERVED4        7U


/* ==========================================================
   IMU DATA
   CAN ID : 0x301
   ========================================================== */

#define IMU_BYTE_ROLL_L             0U
#define IMU_BYTE_ROLL_H             1U

#define IMU_BYTE_PITCH_L            2U
#define IMU_BYTE_PITCH_H            3U

#define IMU_BYTE_YAW_L              4U
#define IMU_BYTE_YAW_H              5U

#define IMU_BYTE_ACC_L              6U
#define IMU_BYTE_ACC_H              7U


/* ==========================================================
   DASHBOARD MESSAGE
   CAN ID : 0x400
   ========================================================== */

#define DASH_BYTE_SPEED_L           0U
#define DASH_BYTE_SPEED_H           1U

#define DASH_BYTE_SOC               2U
#define DASH_BYTE_WARNINGS          3U

#define DASH_BYTE_RESERVED1         4U
#define DASH_BYTE_RESERVED2         5U
#define DASH_BYTE_RESERVED3         6U
#define DASH_BYTE_RESERVED4         7U


/* ==========================================================
   HELPER MACROS
   ========================================================== */

#define CAN_GET_UINT16(data, l, h) \
    ((uint16_t)((data[h] << 8) | data[l]))

#define CAN_SET_UINT16(data, l, h, val) \
    do { \
        data[l] = (uint8_t)((val) & 0xFF); \
        data[h] = (uint8_t)((val) >> 8); \
    } while(0)


#endif
