/* 
 * address_map_arm.h
 * Memory-mapped addresses for in class slideshow
 */

#ifndef ADDRESS_MAP_ARM_H
#define ADDRESS_MAP_ARM_H

#include <stdint.h>

/* HPS peripheral base - from Activity 7 */
#define HW_REGS_BASE           0xFC000000  // ALT_STM_OFST
#define HW_REGS_SPAN           0x04000000
#define HW_REGS_MASK           (HW_REGS_SPAN - 1)

/* FPGA bridge offset */
#define ALT_LWFPGASLVS_OFST    0xFF200000

/* Peripheral base addresses (offsets for lightweight bridge) - from hps_0.h */
#define LED_PIO_BASE           0x3000      // LED base address
#define DIPSW_PIO_BASE         0x4000      // DIP switch base address  
#define BUTTON_PIO_BASE        0x5000      // Push button base address

/* Data widths */
#define LED_PIO_DATA_WIDTH     10          // 10 LEDs
#define DIPSW_PIO_DATA_WIDTH   10          // 10 switches
#define BUTTON_PIO_DATA_WIDTH  4           // 4 push buttons

#endif // ADDRESS_MAP_ARM_H
