# Rear ECU H723

Firmware for the **STM32H7-based Rear ECU** used in **Team Ojas Racing**.

The controller supervises system activation using the following inputs:
- TSMS (Tractive System Master Switch)
- BTB (Brake / Interlock Signal)
- Shutdown status via CAN
- Ready-to-Drive (R2D) request via CAN

Based on these signals, the ECU controls:
- **RFE output** (Relay / Precharge enable)
- **RUN output** (Main enable)

The activation sequence includes a **timed delay between RFE and RUN** to ensure controlled system startup.

## Hardware
- STM32H7
- FDCAN2
- GPIO-controlled RFE and RUN outputs

## Architecture
CAN Layer → Status Flags → Enable State Machine → GPIO Outputs