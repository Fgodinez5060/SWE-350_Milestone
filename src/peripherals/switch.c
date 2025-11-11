/*
 * switch.c
 * Switch input implementation for bet selection
 */

#include "peripherals/switch.h"
#include "../lib/address_map_arm.h"
#include "../includes/config.h"
#include <stdio.h>

// Virtual address pointer for switch input
static volatile int *SW_ptr = NULL;

void switch_init(void) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Map lightweight bridge base address using ioremap_nocache()
    // 2. Calculate SW_ptr = base_virtual + SW_BASE offset
    
    printf("[SWITCH] Initialization stub called\n");
    // Placeholder: Assume successful initialization
}

int switch_read(void) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Read switch register value (*SW_ptr)
    // 2. Mask to get only the lower 4 bits (switches 0-3)
    // 3. Return masked value
    
    printf("[SWITCH] Read switches (stub)\n");
    return 0x01;  //* Placeholder: Return SW0 active
}

int switch_get_bet_amount(void) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Read switch state using switch_read()
    // 2. Check if exactly one switch is active (validate)
    // 3. Determine which switch is active:
    //    - If bit 0 set (SW0): return BET_AMOUNT_SW0
    //    - If bit 1 set (SW1): return BET_AMOUNT_SW1
    //    - If bit 2 set (SW2): return BET_AMOUNT_SW2
    //    - If bit 3 set (SW3): return BET_AMOUNT_SW3
    // 4. If invalid selection, return -1
    
    printf("[SWITCH] Get bet amount (stub)\n");
    return BET_AMOUNT_SW0;  //* Placeholder: Return $10 bet
}

int switch_is_valid_selection(void) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Read switch state using switch_read()
    // 2. Count number of active bits (switches)
    // 3. Use bit manipulation to check if exactly one bit is set:
    //    - Valid if (switch_value != 0) && ((switch_value & (switch_value - 1)) == 0)
    // 4. Return 1 if valid, 0 if invalid
    
    printf("[SWITCH] Validate selection (stub)\n");
    return 1;  //* Placeholder: Return valid
}

void switch_cleanup(void) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Unmap virtual memory (iounmap)
    
    printf("[SWITCH] Cleanup (stub)\n");
}
