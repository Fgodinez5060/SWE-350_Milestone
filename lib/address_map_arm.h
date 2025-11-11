/* 
 * address_map_arm.h
 * Memory-mapped addresses for DE1-SoC (Cyclone V) peripherals
 * Based on Altera DE1-SoC documentation
 */

#ifndef ADDRESS_MAP_ARM_H
#define ADDRESS_MAP_ARM_H

/* Cyclone V FPGA devices - Lightweight bridge */
#define LW_BRIDGE_BASE         0xFF200000
#define LW_BRIDGE_SPAN         0x00005000

/* Peripheral base addresses (offsets from LW_BRIDGE_BASE) */
#define LEDR_BASE              0x00000000  // Red LEDs
#define HEX3_HEX0_BASE         0x00000020  // 7-segment displays 0-3
#define HEX5_HEX4_BASE         0x00000030  // 7-segment displays 4-5
#define SW_BASE                0x00000040  // Switches
#define KEY_BASE               0x00000050  // Push buttons
#define TIMER0_BASE            0x00002000  // Timer 0
#define TIMER1_BASE            0x00002020  // Timer 1

#endif // ADDRESS_MAP_ARM_H
