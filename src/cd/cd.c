#include "../../minishell.h"

int	cd(t_cmd *cmd)
{
	int		ret;
	char	*path;

	path = cd_path(cmd->arg[0], cmd->env_export->env);
	if (path == NULL)
		return (EXIT_FAILURE);
	if (chdir(path) != 0)
	{
		free(path);
		return (EXIT_FAILURE);
	}
	ret = update_env_export(cmd->env_export);
	free(path);
	return (ret);
}