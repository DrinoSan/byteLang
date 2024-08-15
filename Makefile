# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# List of source files
SRCS = chunk.c debug.c main.c memory.c value.c vm.c compiler.c scanner.c object.c

# List of object files (by replacing .c with .o)
OBJS = $(SRCS:.c=.o)

# The target executable
TARGET = main

# Default rule (builds the executable)
all: $(TARGET)

# Link the object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the project (removes object files and the executable)
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (these are not files)
.PHONY: all clean

