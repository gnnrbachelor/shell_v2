#include "shell.h"

int main(int ac, char *av[])
{

	arg_node args;
	init_arg_node(&args, ac, av);
	shell(&args);
	return (EXIT_SUCCESS);

}
