CC=gcc
SRC=src/builtins/builtins.c src/environ/environ.c src/errors/errors.c src/ops/pipe.c src/ops/redirect.c src/run/fork.c src/run/main.c src/run/prompt.c src/tokenize/parse.c src/tokenize/tokenize.c src/utils/linked.c src/utils/strings.c src/utils/strings_2.c
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -g
NAME=hsh
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean, run, check, memcheck

clean:
	rm -f *.o $(NAME)


oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: oclean all

