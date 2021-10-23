#include "../minishell.h"

int	error(t_cmd *cmd)
{
	if (cmd)
		printf("minishell: %s: %s: %s\n", cmd->cmd, cmd->arg, strerror(errno));
	else
		printf("minishell: %s\n", strerror(errno));
	exit(errno);
	return (EXIT_FAILURE);
}