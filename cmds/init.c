#include "../minishell.h"

int	init_cmds(t_cmd *cmds, char **env)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		//cmds[i].arg = ft_strdup("/Users");
		cmds[i].arg = NULL;//ft_strdup("/Usrs");
		cmds[i].cmd = ft_strdup("pwd");
		cmds[i].env = env;
		i++;
	}
	return (EXIT_SUCCESS);
}

// leaks here