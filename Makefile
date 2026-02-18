CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -Iinclude

SRC = main.c $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))
OUT = bin/msh

DIRS = bin obj

all: $(DIRS) $(OUT)

$(DIRS):
	mkdir -p $@

# link .oi into xec
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT)

# compile to .o
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(OUT)
	./$(OUT)

clean:
	rm -rf obj/* bin/*

.PHONY: all clean run
