#include "../../minishell.h"

char	**init_env(const char **menv)
{
	int		i;
	char	**env;

	i = 0;
	env = (char **)ft_calloc(sizeof(char *), ft_strlen_double(menv) + 1);
	if (env == NULL)
		return (NULL);
	while (menv[i])
	{
		env[i] = ft_strdup(menv[i]);
		if (env[i] == NULL)
		{
			free_double(env);
			return (NULL);
		}
		i++;
	}
	return (env);
}

int	update_env(char **env)
{
	if (update_env_old_pwd(env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (update_env_pwd(env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	update_env_old_pwd(char **env)
{
	char	*old_pwd;
	int		i;

	i = 0;
	old_pwd = get_old_pwd(env);
	if (old_pwd == NULL)
		return (EXIT_FAILURE);
	while (env[i])
	{
		if (ft_strnstr(env[i], "OLDPWD", 6))
		{
			free(env[i]);
			env[i] = ft_strjoin("OLDPWD=", old_pwd);
			free(old_pwd);
			if (env[i] == NULL)
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	update_env_pwd(char **env)
{
	int		i;
	char	*new_pwd;

	i = 0;
	new_pwd = pwd();
	if (new_pwd == NULL)
		return (EXIT_FAILURE);
	while (env[i])
	{
		if (ft_strnstr(env[i], "PWD", 3))
		{
			if (ft_strnstr(env[i], "OLDPWD", 6) == NULL)
			{
				free(env[i]);
				env[i] = ft_strjoin("PWD=", new_pwd);
				free(new_pwd);
				if (env[i] == NULL)
					return (EXIT_FAILURE);
				return (EXIT_SUCCESS);
			}
		}
		i++;
	}
	return (EXIT_FAILURE);
}
