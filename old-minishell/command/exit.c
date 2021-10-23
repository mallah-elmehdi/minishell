#include "../minishell.h"

int ft_exit(t_command *command)
{
	printf("exit\n");
	exit(ft_atoi(command->arg));
	return (SUCCESS);
}