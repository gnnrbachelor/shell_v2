#ifndef SHELL_H
#define SHELL_H

typedef struct cmd_node {
	char *str;
	char **args;
	char *path;
	int builtin;
	struct cmd_node *next;
} cmd_node;


#endif
