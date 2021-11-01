#include "../../minishell.h"

int	echo(t_cmd *cmd)
{
	int i;

	i = 0;
	if (ft_strbstr(cmd->arg[0], "-n"))
		i = 1;
	while (cmd->arg[i])
	{
		printf("%s", cmd->arg[i]);
		if (cmd->arg[++i])
			printf(" ");
	}
	if (ft_strbstr(cmd->arg[0], "-n") == NULL)
		printf("\n");
	return (EXIT_SUCCESS);
}