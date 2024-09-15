
# $$\texttt{\large\color{Dandelion}Nanner}$$
Executes commands by fuzzy finding their alias

## Dependencies
The following dependencies are needed to use nanner, currently only supports linux-based systems.
```
sed
```

## Usage

To use run `nnr [alias]` eg.
```bash
nnr cmatrix
# or even
nnr mat
nnr rx
```
Currently, the aliases and commands are stored in `data.txt`, to modify or add aliases it needs to be modified manually.




## Building
`nnr` requires a a `C` compiler to be installed.
Then simply build using `make` and if needed `make install`, to install.

## To DO
Features being worked on or are in need of implementation

```
nnr set alias command
nnr get fuz
nnr list fuz
nnr remove
nnr help

switches:
 -d, --dry
     fuzzy find cmd without execution
 -f, --force
     do not prompt
 -i, --interactive
     prompt before executing cmd
 -q, --quiet
     recklessly execute matched cmd
 -p, --perfect
     don't fuzzy match
```











# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -O2
LDFLAGS =
DATA_DIR = /usr/local/share/myprogram/data
INSTALL_DIR = /usr/local/bin
DATA_FILES = data.txt

# Project name and source files
TARGET = nnr
SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Default target to build the program
all: $(TARGET)

data.txt:
	touch.txt

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
	install -d $(DESTDIR)$(INSTALL_DIR)
	install $(TARGET) $(DESTDIR)$(INSTALL_DIR)
	install -d $(DESTDIR)$(DATA_DIR)
	install $(DATA_FILES) $(DESTDIR)$(DATA_DIR)

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