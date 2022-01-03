#include "shell.h"

int handle_pipe(arg_node *args, char *line)
{
	size_t i;

	for (i = 0; line[i]; ++i)
	{
		if (line[i] == '|')
		{
			++args->cmdcnt;
		}
	}
	printf("command count %lu\n", args->cmdcnt);
	return (0);
}
