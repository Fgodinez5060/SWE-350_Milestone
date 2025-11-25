# DE-10 Roulette Game - Milestone 3

**Author:** Fernando Godinez  
**Course:** SWE-350 Embedded Systems  
**Date:**   November 9, 2025

**Note:** Comments were generated using AI assistance by feeding it information about the project, what functions I wanted, and what I wanted them to do.

## Project Description

This project implements a roulette game on the DE-10 Standard board using the ARM HPS processor. Players use physical switches to select bet amounts, LEDs visualize the spinning roulette wheel, an LCD display shows the current balance and game messages and push buttons to control the game flow.

## Errors:
- LED9 Does not turn on (possible VHDL error)
- Slight button multi press which has been contained with a sleep
- No display functionality except for console

# Build the project
make

# Clean build artifacts
make clean

# Compile
make

# Run
./roulette_game
