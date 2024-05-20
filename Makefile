# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -O2
LDFLAGS =
INSTALL_DIR = /usr/local/bin

# Project name and source files
TARGET = nnr
SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Default target to build the program
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^


# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Ensure the object files directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to install the program
install: $(TARGET)
	install -d $(INSTALL_DIR)
	install $(TARGET) $(INSTALL_DIR)

# Rule to clean up the build files
clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf $(OBJ_DIR)

# Phony targets to avoid conflicts with file names
.PHONY: all install clean

nnr-run: all
	./$(OUT_DIR)/nnr

nnr-debug: all
	valgrind --leak-check=full 	./$(OUT_DIR)/nnr
	mv -f vgcore.* $(OUT_DIR)