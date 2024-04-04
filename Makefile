
CC     = gcc
CFLAGS = -std=c99 -pedantic -Wall
OUT_DIR = bin

nnr: levenshtein.c sine.c util.c main.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -o $(OUT_DIR)/$@ $^ -lm

nnr-run: nnr
	./$(OUT_DIR)/nnr

nnr-debug: nnr
	valgrind --leak-check=full 	./$(OUT_DIR)/nnr
	mv -f vgcore.* $(OUT_DIR)
	
$(OUT_DIR):
	mkdir -p $@
	@echo "made ./$(OUT_DIR)"

.PHONY: clean
clean:
	rm -f $(OUT_DIR)/nnr
