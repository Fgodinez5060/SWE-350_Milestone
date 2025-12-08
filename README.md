# DE-10 Roulette Game - Milestone 5

**Author:** Fernando Godinez  
**Course:** SWE-350 Embedded Systems  
**Date:**   December 7, 2025

**Note:** Comments were generated using AI assistance by feeding it information about the project, what functions I wanted, and what I wanted them to do.

## Project Description

This project implements a roulette game on the DE-10 Standard board using the ARM HPS processor. Players use physical switches to select bet amounts, LEDs visualize the spinning roulette wheel, HEX displays show the current balance in real-time, and push buttons control the game flow.

## Features
- 10 LED roulette wheel with improved spin animation
- Real-time balance display on 7-segment HEX displays
- Switch-based bet selection ($10, $20, $50, $100)
- Button controls for spin, reset, check balance, and quit
- Win/loss detection with balance updates

## Known Issues
- Check balance feature is redundant since HEX displays show balance at all times

## Build Instructions

# Build the project
make

# Clean build artifacts
make clean

# Compile
make

# Run
sudo ./roulette_game
