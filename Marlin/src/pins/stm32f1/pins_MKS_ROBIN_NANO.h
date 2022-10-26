/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin nano (STM32F103VET6) board pin assignments
 * https://github.com/makerbase-mks/MKS-Robin-Nano-V1.X/tree/master/hardware
 */

#define ALLOW_STM32DUINO
#include "env_validate.h"

#define BOARD_INFO_NAME "MKS Robin Nano"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_JTAG

//
// Thermocouples
//
//#define TEMP_0_CS_PIN                     PE5   // TC1 - CS1
//#define TEMP_0_CS_PIN                     PE6   // TC2 - CS2

//#define LED_PIN                           PB2

#include "pins_MKS_ROBIN_NANO_common.h"

#if HAS_TFT_LVGL_UI && FAN1_PIN != PB0 && HEATER_1_PIN != PB0
  #define BOARD_INIT() OUT_WRITE(PB0, LOW)
#endif

//
// TMC 2209 UART MODE via WIFI pins
//

#if HAS_TMC_UART
#define X_SERIAL_TX_PIN PA10
#define X_SERIAL_RX_PIN PA10

#define Y_SERIAL_TX_PIN PA9
#define Y_SERIAL_RX_PIN PA9

#define Z_SERIAL_TX_PIN PC7
#define Z_SERIAL_RX_PIN PC7

#define E0_SERIAL_TX_PIN PC13
#define E0_SERIAL_RX_PIN PC13

#define Z2_SERIAL_TX_PIN PA5
#define Z2_SERIAL_RX_PIN PA5

#define TMC_BAUD_RATE 19200
#endif // TMC2208 || TMC2209