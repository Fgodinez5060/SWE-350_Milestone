/*
 * game-logic.h
 * Core game logic for roulette gameplay
 */

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

//? Game state structure
typedef struct {
    int balance;           // Player's current balance
    int bet_amount;        // Current bet amount
    int bet_position;      // Position player bet on (0-9)
    int is_game_active;    // Flag: 1 = game running, 0 = game over
} GameState;

/*
 * Initialize game state with default values
 * 
 * Returns:
 *   Initialized GameState structure
 */
GameState game_init(void);

/*
 * Generate a random position for the roulette wheel to land on
 * 
 * Returns:
 *   Random position (0-9)
 */
int game_generate_random_position(void);

/*
 * Process a game round - check win/loss and update balance
 * 
 * Parameters:
 *   state - Pointer to current game state
 *   final_position - Where the wheel landed
 * 
 * Returns:
 *   1 if player won, 0 if player lost
 */
int game_process_round(GameState *state, int final_position);

/*
 * Check if player can afford the current bet
 * 
 * Parameters:
 *   state - Pointer to current game state
 * 
 * Returns:
 *   1 if player has sufficient funds, 0 otherwise
 */
int game_can_afford_bet(GameState *state);

/*
 * Reset game state to initial values
 * 
 * Parameters:
 *   state - Pointer to game state to reset
 */
void game_reset(GameState *state);

#endif // GAME_LOGIC_H
