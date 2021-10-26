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

int	update_env(char *path, char **env)
{
	char	*old_pwd;
	int		i;

	old_pwd = get_old_pwd(env);
	i = 0;
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
		}
		if (ft_strnstr(env[i], "PWD", 3))
		{
			free(env[i]);
			env[i] = ft_strjoin("PWD=", path);
			if (env[i] == NULL)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
