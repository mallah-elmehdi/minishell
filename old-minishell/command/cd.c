#include "../minishell.h"

int ft_cd(const char *path)
{
	if (chdir(path))
		return (error());
	return (SUCCESS);
}