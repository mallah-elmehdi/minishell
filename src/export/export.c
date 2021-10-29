#include "../../minishell.h"

int	ft_export(t_cmd *cmd)
{
	if (cmd->arg == NULL)
		return (print_export(cmd->env_export->export));
	else
		return (add_to_export(cmd));
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

int	valid_export(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd->arg[i])
	{
		if (!ft_isalpha(cmd->arg[i][0]))
			return (prg_error(cmd->cmd, cmd->arg[i], "not a valid identifier"));
		i++;
	}
	return (EXIT_SUCCESS);
}

int	add_to_export(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->arg[i])
	{
		if (ft_isalpha(cmd->arg[i][0]))
		{
			if (ft_strnstr(cmd->arg[i], "=", 1))
			{
				if (add_env_export(cmd->env_export, cmd->arg[i]) == EXIT_FAILURE)
					return (sys_error(cmd->cmd, cmd->arg[i]));
			}
			else if (add_export(cmd->env_export, cmd->arg[i]) == EXIT_FAILURE)
				return (sys_error(cmd->cmd, cmd->arg[i]));
		}
		i++;
	}
	return (valid_export(cmd));
}
