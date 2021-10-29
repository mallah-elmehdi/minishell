#include "../minishell.h"

int	sys_error(char *cmd, char *arg)
{
	if (cmd)
		printf("minishell: %s: %s: %s\n", cmd, arg, strerror(errno));
	else
		printf("minishell: %s\n", strerror(errno));
	exit(errno);
	return (EXIT_FAILURE);
}

int	prg_error(char *cmd, char *arg, char *msg)
{
	printf("minishell: %s: %s: %s\n", cmd, arg, msg);
	exit(1);
	return (EXIT_FAILURE);
}