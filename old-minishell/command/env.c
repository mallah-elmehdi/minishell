#include "../minishell.h"


int ft_env(t_command *command, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (SUCCESS);
}