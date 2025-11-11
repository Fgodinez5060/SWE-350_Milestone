/*
 * config.h
 * Configuration constants for the roulette game
 */

#ifndef CONFIG_H
#define CONFIG_H

//? Game configuration constants
#define INITIAL_BALANCE       100    // Starting player balance
#define NUM_LEDS              10     // Number of LEDs on the roulette wheel
#define LED_SPIN_DELAY_MS     100    // Delay between LED transitions (milliseconds)
#define TOTAL_SPIN_TIME_MS    3000   // Total duration of LED animation (3 seconds)
#define DEBOUNCE_DELAY_MS     50     // Switch debounce delay

//? Bet amounts based on switch positions
#define BET_AMOUNT_SW0        10     // Bet for switch 0
#define BET_AMOUNT_SW1        20     // Bet for switch 1
#define BET_AMOUNT_SW2        50     // Bet for switch 2
#define BET_AMOUNT_SW3        100    // Bet for switch 3

//? Payout multiplier
#define PAYOUT_MULTIPLIER     2      // Win payout: bet * 2

//? Button assignments
#define BUTTON_SPIN           0      // KEY0 - Start spin
#define BUTTON_RESET          3      // KEY3 - Reset game

#endif // CONFIG_H
