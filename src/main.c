/*
 * main.c
 * Roulette game main program
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "peripherals/led.h"
#include "peripherals/switch.h"
#include "peripherals/display.h"
#include "peripherals/hex.h"
#include "game-logic/game-logic.h"
#include "config.h"

void run_game(void);
void show_menu(void);
int get_menu_choice(void);
int get_bet_position(void);
void flash_winning_led(int position);

int main(void) {
    printf("=== DE-10 Roulette Game ===\n");
    printf("Initializing hardware...\n\n");
    
    run_game();
    
    printf("\nGame terminated\n");
    return 0;
}

void show_menu(void) {
    printf("\n========================================\n");
    printf("         MAIN MENU\n");
    printf("========================================\n");
    printf("KEY0 = Play\n");
    printf("KEY1 = Reset\n");
    printf("KEY2 = Check balance\n");
    printf("KEY3 = Quit\n");
    printf("========================================\n");
}

int get_menu_choice(void) {
    while (1) {
        if (button_is_key_pressed(0)) {
            printf("[MENU] Play\n");
            return 0;
        }
        if (button_is_key_pressed(1)) {
            printf("[MENU] Reset\n");
            return 1;
        }
        if (button_is_key_pressed(2)) {
            printf("[MENU] Check Balance\n");
            return 2;
        }
        if (button_is_key_pressed(3)) {
            printf("[MENU] Quit\n");
            return 3;
        }
        usleep(50000);
    }
}

int get_bet_position(void) {
    printf("\n>>> SELECT BET POSITION <<<\n");
    printf("Flip ONE switch (SW0-SW9) and press KEY0 to confirm\n\n");
    
    int selected_position = -1;
    
    while (1) {
        int switches = switch_read();
        
        // Check if exactly one switch active
        if (switches != 0 && (switches & (switches - 1)) == 0) {
            for (int i = 0; i < NUM_LEDS; i++) {
                if (switches & (1 << i)) {
                    selected_position = i;
                    break;
                }
            }
            
            led_set_position(selected_position);
            
            printf("\rPosition: LED %d | Press KEY0 to confirm...  ", selected_position);
            fflush(stdout);
            
            if (button_is_key_pressed(0)) {
                printf("\n[BET] Position %d confirmed\n", selected_position);
                led_clear_all();
                usleep(300000);
                return selected_position;
            }
        } else if (switches == 0) {
            printf("\rNo switch selected                           ");
            fflush(stdout);
            led_clear_all();
        } else {
            printf("\rMultiple switches - select only ONE          ");
            fflush(stdout);
            led_clear_all();
        }
        
        usleep(100000);
    }
}

void flash_winning_led(int position) {
    printf("[LED] Flashing winning position...\n");
    
    // Flash 6 times
    for (int i = 0; i < 6; i++) {
        led_set_position(position);
        usleep(250000);
        led_clear_all();
        usleep(250000);
    }
    
    led_set_position(position);
    usleep(500000);
}

void run_game(void) {
    printf("[MAIN] Starting initialization...\n");
    
    // Initialize hardware
    led_init();
    switch_init();
    display_init();
    hex_init();
    
    // Initialize game
    GameState game = game_init();
    
    display_welcome();
    display_balance(game.balance);
    hex_display_number(game.balance);
    
    printf("\n[MAIN] ========================================\n");
    printf("[MAIN] DE-10 Roulette Game - READY!\n");
    printf("[MAIN] Starting Balance: $%d\n", game.balance);
    printf("[MAIN] ========================================\n\n");
    
    int running = 1;
    
    while (running && game.is_game_active) {
        show_menu();
        int choice = get_menu_choice();
        
        switch (choice) {
            case 0:  // PLAY
                printf("\n[GAME] Starting round\n");
                printf("Balance: $%d\n", game.balance);
                
                // Select bet amount
                printf("\n>>> SELECT BET AMOUNT <<<\n");
                printf("SW0=$10, SW1=$20, SW2=$50, SW3=$100\n");
                printf("Press KEY0 to confirm\n\n");
                
                int bet_amount = -1;
                int selected_amount = -1;
                
                while (bet_amount == -1) {
                    int switches = switch_read() & 0x0F;
                    
                    if (switches != 0 && (switches & (switches - 1)) == 0) {
                        if (switches & 0x01) selected_amount = BET_AMOUNT_SW0;
                        else if (switches & 0x02) selected_amount = BET_AMOUNT_SW1;
                        else if (switches & 0x04) selected_amount = BET_AMOUNT_SW2;
                        else if (switches & 0x08) selected_amount = BET_AMOUNT_SW3;
                        
                        printf("\rBet: $%d | Press KEY0...  ", selected_amount);
                        fflush(stdout);
                        
                        if (button_is_key_pressed(0)) {
                            bet_amount = selected_amount;
                            printf("\n[BET] $%d confirmed\n", bet_amount);
                            break;
                        }
                    } else {
                        printf("\rSelect ONE switch (SW0-SW3)  ");
                        fflush(stdout);
                        selected_amount = -1;
                    }
                    usleep(100000);
                }
                
                game.bet_amount = bet_amount;
                
                if (!game_can_afford_bet(&game)) {
                    printf("\n[ERROR] Insufficient funds\n");
                    display_error("Insufficient Funds");
                    usleep(2000000);
                    continue;
                }
                
                // Get position
                game.bet_position = get_bet_position();
                
                printf("\n[GAME] Spinning...\n");
                printf("Bet: $%d on position %d\n", game.bet_amount, game.bet_position);
                
                int final_position = game_generate_random_position();
                
                led_spin_animation(final_position);
                
                printf("\n[GAME] Landed on: %d\n", final_position);
                
                int won = game_process_round(&game, final_position);
                
                flash_winning_led(final_position);
                led_clear_all();
                
                if (won) {
                    printf("\n*** YOU WON! ***\n");
                    printf("Won: $%d\n", game.bet_amount * PAYOUT_MULTIPLIER);
                    display_message("You Won!");
                } else {
                    printf("\n*** YOU LOST ***\n");
                    printf("Lost: $%d\n", game.bet_amount);
                    display_message("You Lost!");
                }
                
                printf("Balance: $%d\n", game.balance);
                display_balance(game.balance);
                hex_display_number(game.balance);
                
                if (game.balance <= 0) {
                    printf("\n========================================\n");
                    printf("         GAME OVER\n");
                    printf("========================================\n");
                    display_message("Game Over!");
                    game.is_game_active = 0;
                    usleep(3000000);
                }
                
                usleep(2000000);
                break;
                
            case 1:  // RESET
                printf("\n[GAME] Resetting...\n");
                game_reset(&game);
                display_welcome();
                display_balance(game.balance);
                hex_display_number(game.balance);
                printf("Reset complete\n");
                usleep(2000000);
                break;
                
            case 2:  // CHECK BALANCE
                printf("\n[GAME] Balance: $%d\n", game.balance);
                display_balance(game.balance);
                hex_display_number(game.balance);
                usleep(2000000);
                break;
                
            case 3:  // QUIT
                printf("\n[GAME] Quitting...\n");
                running = 0;
                break;
                
            default:
                break;
        }
    }
    
    if (!game.is_game_active) {
        printf("\n========================================\n");
        printf("         GAME OVER\n");
        printf("         Final Balance: $%d\n", game.balance);
        printf("========================================\n");
    }
    
    printf("\n[MAIN] Cleaning up...\n");
    led_cleanup();
    switch_cleanup();
    display_cleanup();
    hex_cleanup();
    
    printf("[MAIN] Done\n");
}
