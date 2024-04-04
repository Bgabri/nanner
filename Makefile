
CC     = gcc
CFLAGS = -std=c99 -pedantic -Wall
OUT_DIR = bin

nnr: levenshtein.c sine.c util.c main.c
	$(CC) $(CFLAGS) -o $(OUT_DIR)/$@ $^ -lm

nnr-run: nnr
	./$(OUT_DIR)/nnr

nnr-debug: nnr
	valgrind --leak-check=full 	./$(OUT_DIR)/nnr

.PHONY: clean
clean:
	rm -f bin/nnr
