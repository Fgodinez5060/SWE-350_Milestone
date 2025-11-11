/*
 * display.h
 * LCD display interface for game status and messages
 */

#ifndef DISPLAY_H
#define DISPLAY_H

/*
 * Initialize LCD display hardware
 * Sets up communication with LCD module
 */
void display_init(void);

/*
 * Display the current player balance on LCD
 * 
 * Parameters:
 *   balance - Current balance amount
 */
void display_balance(int balance);

/*
 * Display a game message on LCD
 * 
 * Parameters:
 *   message - Text message to display (max 16 characters per line)
 */
void display_message(const char *message);

/*
 * Display an error message on LCD
 * 
 * Parameters:
 *   error - Error message text
 */
void display_error(const char *error);

/*
 * Clear the LCD display
 */
void display_clear(void);

/*
 * Display game welcome screen
 */
void display_welcome(void);

/*
 * Clean up display resources
 */
void display_cleanup(void);

#endif // DISPLAY_H
