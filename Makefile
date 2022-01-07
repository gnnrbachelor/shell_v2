CC=gcc
SRC=src/builtins/builtins.c src/builtins/changedir.c src/builtins/clear.c src/builtins/exit.c src/builtins/set_env.c src/builtins/unset_env.c src/errors/errors.c src/ops/heredoc.c src/ops/redirect.c src/ops/pipe.c src/ops/redirect.c src/ops/redirect_2.c src/run/fork.c src/run/main.c src/run/prompt.c src/run/shell.c  src/tokenize/parse.c src/tokenize/tokenize.c src/utils/linked.c src/utils/strings.c src/utils/strings_2.c
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -g
NAME=hsh
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean, run, check, memcheck

clean:
	find . -type f -name "*.o" -delete


oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: oclean all

