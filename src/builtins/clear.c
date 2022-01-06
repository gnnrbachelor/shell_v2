#include "../headers/shell.h"

/**
 * _clear - Clear Screen
 * @args: Args
 * Return: 0
 */

int _clear(arg_node *args)
{
	char *clr = "\033[2J";
	char *move = "\033[1;1H";

	(void) args;
	printf("%s%s", move, clr);
	return (0);
}

