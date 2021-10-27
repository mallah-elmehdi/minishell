#include "../../minishell.h"

char	*get_old_pwd(char **env)
{
	int		i;
	char	**temp;
	char	*old_pwd;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PWD", 3))
		{
			temp = ft_split(env[i], '=');
			if (temp == NULL)
				return (NULL);
			old_pwd = ft_strdup(temp[1]);
			free_double(temp);
			if (old_pwd == NULL)
				return (NULL);
			return (old_pwd);
		}
		i++;
	}
	return (NULL);
}