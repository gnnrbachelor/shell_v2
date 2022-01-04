#include "../headers/shell.h"

/**
 * clear_screen - Clear Screen
 * @arg_node: Args
 * Return: Void
 */

int _clear(arg_node *args)
{
	char *clr = "\033[2J";
	char *move = "\033[1;1H";

	(void) args;
	printf("%s%s", move, clr);
	return (0);
}

