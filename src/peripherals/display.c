/*
 * display.c
 * LCD display implementation for game status
 */

#include "peripherals/display.h"
#include <stdio.h>
#include <string.h>

void display_init(void) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Initialize LCD communication (I2C or parallel depending on LCD module)
    // 2. Send LCD initialization commands:
    //    a. Set display mode (2-line, 5x8 dots)
    //    b. Turn on display
    //    c. Clear display
    //    d. Set entry mode (increment cursor)
    // 3. Wait for LCD to stabilize (small delay)
    
    printf("[DISPLAY] Initialization stub called\n");
    // Placeholder: Assume successful initialization
}

void display_balance(int balance) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Clear LCD display
    // 2. Format balance string: "Balance: $XXX"
    // 3. Send formatted string to LCD line 1
    // 4. Position cursor at start of line 2 (for future messages)
    
    printf("[DISPLAY] Balance: $%d (stub)\n", balance);
}

void display_message(const char *message) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Position cursor at line 2 of LCD
    // 2. Send message string to LCD (max 16 chars)
    // 3. If message is longer than 16 chars, truncate or scroll
    
    printf("[DISPLAY] Message: %s (stub)\n", message);
}

void display_error(const char *error) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Clear LCD display
    // 2. Display "ERROR:" on line 1
    // 3. Display error message on line 2
    // 4. Optional: Blink display or add visual indicator
    
    printf("[DISPLAY] ERROR: %s (stub)\n", error);
}

void display_clear(void) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Send LCD clear command (0x01)
    // 2. Wait for command to complete (small delay ~2ms)
    // 3. Reset cursor to home position
    
    printf("[DISPLAY] Clear display (stub)\n");
}

void display_welcome(void) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Clear LCD
    // 2. Display "ROULETTE GAME" on line 1
    // 3. Display "Press KEY0" on line 2
    // 4. Optional: Add brief delay for visibility
    
    printf("[DISPLAY] Welcome screen (stub)\n");
}

void display_cleanup(void) {
    // STUB FUNCTION - Will implement in Milestone 4
    // Pseudocode:
    // 1. Clear LCD display
    // 2. Turn off LCD backlight (if applicable)
    // 3. Release LCD resources
    
    printf("[DISPLAY] Cleanup (stub)\n");
}
