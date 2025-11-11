/*
 * main.c
 * Main application entry point for DE-10 Roulette Game
 * Description:
 * This application implements a roulette game on the DE-10 Standard board.
 * Players use switches to select bet amounts and press a button to spin.
 * LEDs visualize the spinning wheel, and an LCD displays the balance.
 */

#include <stdio.h>
#include <stdlib.h>
#include "peripherals/led.h"
#include "peripherals/switch.h"
#include "peripherals/display.h"
#include "game-logic/game-logic.h"
#include "config.h"

// Forward declaration of main game loop
void run_game(void);

int main(void) {
    printf("=== DE-10 Roulette Game ===\n");
    printf("Initializing hardware...\n\n");
    
    // Run the main game loop
    run_game();
    
    printf("\nGame terminated. Goodbye!\n");
    return 0;
}

void run_game(void) {
    // STUB FUNCTION - Will implement full game loop in Milestone 4
    // Pseudocode:
    // 1. Initialize all hardware peripherals:
    //    a. led_init()
    //    b. switch_init()
    //    c. display_init()
    // 2. Initialize game state using game_init()
    // 3. Display welcome screen
    // 4. Main game loop (while game is active):
    //    a. Read switch state to get bet amount
    //    b. Validate switch selection
    //    c. Wait for button press (KEY0 for spin, KEY3 for reset)
    //    d. If spin button pressed:
    //       i.   Check if player can afford bet
    //       ii.  Generate random final position
    //       iii. Animate LED spin to final position
    //       iv.  Process round (update balance)
    //       v.   Display updated balance
    //    e. If reset button pressed:
    //       i.   Reset game state
    //       ii.  Display welcome screen
    //    f. Check if game should end (balance <= 0)
    // 5. Clean up all hardware resources:
    //    a. led_cleanup()
    //    b. switch_cleanup()
    //    c. display_cleanup()
    
    printf("[MAIN] Starting game initialization...\n");
    
    // Initialize hardware (stub calls)
    led_init();
    switch_init();
    display_init();
    
    // Initialize game state
    GameState game = game_init();
    
    // Show welcome message
    display_welcome();
    display_balance(game.balance);
    
    printf("[MAIN] Game loop starting (stub - will implement button polling in M4)...\n");
    
    // Simulate one round for demonstration
    printf("\n--- Simulating one game round ---\n");
    
    // Get bet from switches
    int bet = switch_get_bet_amount();
    game.bet_amount = bet;
    game.bet_position = 3;  // Placeholder: Player bets on position 3
    
    printf("[MAIN] Player bets $%d on position %d\n", game.bet_amount, game.bet_position);
    
    // Check if player can afford bet
    if (game_can_afford_bet(&game)) {
        // Generate random position
        int final_pos = game_generate_random_position();
        
        // Animate spin
        led_spin_animation(final_pos);
        
        // Process results
        int won = game_process_round(&game, final_pos);
        
        if (won) {
            display_message("You Won!");
        } else {
            display_message("You Lost!");
        }
        
        // Update display
        display_balance(game.balance);
    } else {
        display_error("Insufficient Funds");
    }
    
    printf("\n[MAIN] Demo round complete. Full game loop will be in Milestone 4.\n");
    
    // Clean up hardware
    printf("\n[MAIN] Cleaning up hardware...\n");
    led_cleanup();
    switch_cleanup();
    display_cleanup();
    
    printf("[MAIN] Game loop ended\n");
}
