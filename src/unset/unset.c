#include "../../minishell.h"

int	unset(t_cmd *cmd)
{
	if (cmd->arg != NULL)
		return (unset_env_export(cmd));
	return (EXIT_SUCCESS);
}

int	unset_arg_exist(char **env, char *arg)
{
	int 	i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(arg, "=");
	if (temp = NULL)
		return (EXIT_FAILURE);
	while (env[i])
	{
		if (ft_strbstr(env[i], temp))
		{
			free(temp);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	free(temp);
	return (EXIT_FAILURE);
}

int	remove_arg_env(t_env_export *env_export, char *arg)
{
	int 	i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(arg, "=");
	if (temp = NULL)
		return (EXIT_FAILURE);
	while (env_export->env[i])
	{
		if (ft_strbstr(env_export->env[i], temp))
		{
			free(env_export->env[i]);
			env_export->env[i] = ft_strdup("NaN");
			if (env_export->env[i] == NULL)
			{
				free(temp);
				return (EXIT_FAILURE);
			}
		}
		i++;
	}
	free(temp);
	return (EXIT_SUCCESS);
}

int	remove_arg_export(t_env_export *env_export, char *arg)
{
	int 	i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(ft_strjoin("declare -x ", arg), "=");
	if (temp = NULL)
		return (EXIT_FAILURE);
	while (env_export->export[i])
	{
		if (ft_strbstr(env_export->export[i], temp))
		{
			free(env_export->export[i]);
			env_export->export[i] = ft_strdup("NaN");
			if (env_export->export[i] == NULL)
			{
				free(temp);
				return (EXIT_FAILURE);
			}
		}
		i++;
	}
	free(temp);
	return (EXIT_SUCCESS);
}


int	remove_arg_env_export(t_env_export *env_export, char *arg)
{
	if (remove_arg_env())
}

int	unset_env_export(t_cmd *cmd)
{
	int i;

	while (cmd->arg[i])
	{
		if (unset_arg_exist(cmd->env_export, cmd->arg[i]) == EXIT_SUCCESS)
		{
			if (remove_arg_env_export(cmd->env_export, cmd->arg[i]) == EXIT_FAILURE);
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}