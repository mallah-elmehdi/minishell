#include "../../minishell.h"

int	export(t_cmd *cmd)
{
	if (cmd->arg == NULL)
		return (print_export(cmd->env_export->export));
	else
		return (add_to_export(cmd));
	return (EXIT_SUCCESS);
}

int	add_to_export(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->arg[i])
	{
		if (ft_strnstr(cmd->arg[i], "=", 1))
		{
			add_export_w_equal(cmd->env_export->export, cmd->arg[i]);
			//add_env(cmd->env_export->export, cmd->arg[i]);
		}
		//else
			//add_export(cmd->arg[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	print_export(char **export)
{
	int		i;

	i = 0;
	while (export[i])
	{
		printf("%s\n", export[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
