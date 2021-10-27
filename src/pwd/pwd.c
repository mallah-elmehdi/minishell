#include "../../minishell.h"

char	*pwd(void)
{
	char	*pwd;

	pwd = (char *)ft_calloc(sizeof(char), 256);
	if (pwd == NULL)
		return (NULL);
	pwd = getcwd(pwd, sizeof(char) * 256);
	if (pwd == NULL)
		return (NULL);
	return (pwd);
}

int	print_pwd(void)
{
	char *path;

	path = pwd();
	if (path == NULL)
		return (EXIT_FAILURE);
	printf("%s\n", path);
	return (EXIT_SUCCESS);
}