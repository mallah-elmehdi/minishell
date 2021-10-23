#include "../../minishell.h"

int	pwd(t_cmd *cmd)
{
	char	*pwd;
	int		pwd_length;

	pwd_length = pwd_path_length(cmd->env);
	pwd = NULL;
	if (pwd_length == -1)
		return (EXIT_FAILURE);
	pwd = getcwd(pwd, pwd_length);
	if (pwd == NULL)
		return (EXIT_FAILURE);
	printf("%s\n", pwd);
	return (EXIT_SUCCESS);
}