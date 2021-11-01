#include "../../minishell.h"

int	valid_arg_exit(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalnum)
	}
}

int	ft_exit(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->arg[i])
	{
		if (valid_arg_exit(cmd->arg[i]) == EXIT_FAILURE)
	}
	
	printf("exit\n");
	exit(cmd->status->last_status);
	return (EXIT_SUCCESS);
}
