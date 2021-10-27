#include "../../minishell.h"

char	*home_path(char **env)
{
	int		i;
	char	**temp;
	char	*path;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "HOME", 4))
		{
			temp = ft_split(env[i], '=');
			if (temp == NULL)
				return (NULL);
			path = ft_strdup(temp[1]);
			free_double(temp);
			if (path == NULL)
				return (NULL);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*abs_path(const char *path, char **env)
{
	int		i;
	char	**temp;
	char	*path_w_slash;
	char	*joined_path;

	i = 0;
	path_w_slash = ft_strjoin("/", path);
	if (path_w_slash == NULL)
		return (NULL);
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PWD", 3))
		{
			temp = ft_split(env[i], '=');
			if (temp == NULL)
				return (NULL);
			joined_path = ft_strjoin(temp[1], path_w_slash);
			free_double(temp);
			free(path_w_slash);
			if (joined_path == NULL)
				return (NULL);
			return (joined_path);
		}
		i++;
	}
	return (NULL);
}

char	*cd_path(const char *path, char **env)
{
	if (path == NULL)
		return (home_path(env));
	else if (ft_strnstr(path, "/", 1) != 0)
		return (ft_strdup(path));
	else
		return (abs_path(path, env));
	return (NULL);
}

int	update_env_export(t_env_export *env_export)
{
	if (update_env(env_export->env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (update_export(env_export->export) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}