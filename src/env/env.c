#include "../../minishell.h"

int	env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strbstr(env[i], "NaN") == NULL)
			printf("%s\n", env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
