#include "../../minishell.h"

int	ft_cmds(t_cmd *cmds)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if (ft_strnstr(cmds[i].cmd, "cd", 2))
		{
			if (cd(&cmds[i]) == EXIT_FAILURE)
				return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
		}
		else if (ft_strnstr(cmds[i].cmd, "pwd", 3))
		{
			if (print_pwd() == EXIT_FAILURE)
				return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
		}
		else if (ft_strnstr(cmds[i].cmd, "export", 6))
		{
			if (ft_export(&cmds[i]) == EXIT_FAILURE)
				return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
		}
		else if (ft_strnstr(cmds[i].cmd, "env", 3))
		{
			if (env(cmds[i].env_export->env) == EXIT_FAILURE)
				return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}