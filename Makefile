# Makefile for the banking system project

# Compiler
CC = gcc

# Compiler flags (add -g for debugging, -Wall for all warnings)
CFLAGS = -Wall -Iinclude

# Source files
SRCS = src/main.c src/accounts.c

# Object files (based on source files)
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = bank_system

# Default target
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule (to remove object files and the executable)
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets (targets that don't represent actual files)
.PHONY: all clean