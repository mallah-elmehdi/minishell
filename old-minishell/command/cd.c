#include "../minishell.h"

int ft_cd(const char *path)
{
	if (chdir(path))
		return (sys_error());
	return (SUCCESS);
}