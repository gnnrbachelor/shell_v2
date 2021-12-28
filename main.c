#include "shell.h"

/**
 * main - Entry point
 * @ac: Arg count
 * @av: Args
 * Return: 0
 */

int main(int ac, char *av[])
{

	arg_node args;

	init_arg_node(&args, ac, av);
	shell(&args);
	free_it_all(&args, '\0');
	return (EXIT_SUCCESS);

}
