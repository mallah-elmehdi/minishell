#include "../../minishell.h"

int	cd(t_cmd *cmd)
{
	char	*path;
	int		err;

	path = cd_path(cmd->arg, cmd->env);
	if (path == NULL)
		return (EXIT_FAILURE);
	err = chdir(path);
	free(path);
	if (err != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}