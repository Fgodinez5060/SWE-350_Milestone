/*
 * game-logic.c
 * Game logic implementation
 */

#include "game-logic/game-logic.h"
#include "../includes/config.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

GameState game_init(void) {
    GameState state;
    state.balance = INITIAL_BALANCE;
    state.bet_amount = 0;
    state.bet_position = 0;
    state.is_game_active = 1;
    
    srand(time(NULL));
    
    printf("[GAME] Game initialized with balance: $%d\n", state.balance);
    return state;
}

int game_generate_random_position(void) {
    int position = rand() % NUM_LEDS;
    printf("[GAME] Generated random position: %d\n", position);
    return position;
}

int game_process_round(GameState *state, int final_position) {
    printf("[GAME] Processing round - Final: %d, Bet: %d\n", 
           final_position, state->bet_position);
    
    // Check for win
    if (state->bet_position == final_position) {
        int winnings = state->bet_amount * PAYOUT_MULTIPLIER;
        state->balance += winnings;
        printf("[GAME] WIN! Player won $%d (balance: $%d)\n", 
               winnings, state->balance);
        return 1;
    } else {
        state->balance -= state->bet_amount;
        printf("[GAME] LOSS! Player lost $%d (balance: $%d)\n", 
               state->bet_amount, state->balance);
        
        // Check if broke
        if (state->balance <= 0) {
            state->is_game_active = 0;
            printf("[GAME] Game over - out of funds\n");
        }
        
        return 0;
    }
}

int game_can_afford_bet(GameState *state) {
    int can_afford = (state->balance >= state->bet_amount) ? 1 : 0;
    
    if (!can_afford) {
        printf("[GAME] Cannot afford bet of $%d (balance: $%d)\n", 
               state->bet_amount, state->balance);
    }
    
    return can_afford;
}

void game_reset(GameState *state) {
    state->balance = INITIAL_BALANCE;
    state->bet_amount = 0;
    state->bet_position = 0;
    state->is_game_active = 1;
    
    printf("[GAME] Game reset (balance: $%d)\n", INITIAL_BALANCE);
}
