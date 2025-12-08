# Makefile for DE-10 Roulette Game
# Author: Fernando Godinez
# Course: SWE-350 Embedded Systems

# Compiler and flags
CC = gcc
CFLAGS = -Iincludes -Ilib -Wall -Wextra -g -std=c99

# Source files
SRC = src/main.c \
      src/peripherals/led.c \
      src/peripherals/switch.c \
      src/peripherals/display.c \
      src/peripherals/hex.c \
      src/game-logic/game-logic.c

# Object files
OBJ = $(SRC:.c=.o)

# Target executable
TARGET = roulette_game

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)
	@echo "Build complete: $(TARGET)"

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f src/*.o src/peripherals/*.o src/game-logic/*.o $(TARGET)
	@echo "Clean complete"

# Rebuild everything
rebuild: clean all

# Help target
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  clean    - Remove build artifacts"
	@echo "  rebuild  - Clean and build"
	@echo "  help     - Show this help message"

.PHONY: all clean rebuild help
