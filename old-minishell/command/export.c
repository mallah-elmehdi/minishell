#include "../minishell.h"


int ft_export(t_command *command, char **env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!command->arg)
	{
		while (env[i])
		{
			while (env[i][j])
			{
				write(1, &env[i][j], 1);
				if (env[i][j] == '=')
					write(1, "'", 1);
				j++;
			}
			write(1, "'\n", 2);
			i++;
		}
	}
	return (SUCCESS);
}