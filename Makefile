SHELL=/bin/bash
CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -g
NAME=hsh
OBJ=$(patsubst %.c,%.o, $(wildcard *.c))
LINTER=betty

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean, run, check, memcheck

clean:
	rm -f *.o $(NAME)

run: all
	@./$(NAME)

check:
	$(LINTER) *.c *.h

memcheck: all
	valgrind ./$(NAME)
