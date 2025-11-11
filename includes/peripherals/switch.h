/*
 * switch.h
 * Switch input interface for bet selection
 */

#ifndef SWITCH_H
#define SWITCH_H

/*
 * Initialize switch hardware
 * Sets up memory mapping for switch input registers
 */
void switch_init(void);

/*
 * Read the current state of all switches
 * 
 * Returns:
 *   Integer representing switch states (bit mask)
 *   Each bit corresponds to one switch (bit 0 = SW0, etc.)
 */
int switch_read(void);

/*
 * Get the selected bet amount based on switch position
 * Only one switch should be active at a time
 * 
 * Returns:
 *   Bet amount (10, 20, 50, or 100)
 *   -1 if no switch is selected or multiple switches are active
 */
int switch_get_bet_amount(void);

/*
 * Check if exactly one switch is active (valid bet selection)
 * 
 * Returns:
 *   1 if valid (one switch active)
 *   0 if invalid (zero or multiple switches active)
 */
int switch_is_valid_selection(void);

/*
 * Clean up switch resources
 */
void switch_cleanup(void);

#endif // SWITCH_H
