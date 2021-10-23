#include "../minishell.h"

int	ft_cmds(t_cmd *cmds)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if (ft_strnstr(cmds[i].cmd, "cd", 2))
		{
			if (cd(&cmds[i]) == EXIT_FAILURE)
				return (error(&cmds[i]));
		}
		else if (ft_strnstr(cmds[i].cmd, "pwd", 3))
		{
			if (pwd(&cmds[i]) == EXIT_FAILURE)
				return (error(&cmds[i]));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}