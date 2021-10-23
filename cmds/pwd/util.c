#include "../../minishell.h"

int	pwd_path_length(char **env)
{
	int		i;
	int		length;
	char	**temp;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PWD", 3))
		{
			temp = ft_split(env[i], '=');
			if (temp == NULL)
				return (-1);
			length = ft_strlen(temp[1]);
			free_double(temp);
			return (length);
		}
		i++;
	}
	return (-1);
}
