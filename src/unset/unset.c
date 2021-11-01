#include "../../minishell.h"

int	unset(t_cmd *cmd)
{
	if (cmd->arg != NULL)
		return (unset_env_export(cmd));
	return (EXIT_SUCCESS);
}

int	remove_arg_env(t_env_export *env_export, char *arg)
{
	int 	i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(arg, "=");
	if (temp == NULL)
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
	char	*temp0;
	char	*temp;

	i = 0;
	temp0 = ft_strjoin("declare -x ", arg);
	if (temp0 == NULL)
		return (EXIT_FAILURE);
	temp = ft_strjoin(temp0, "=");
	free (temp0);
	if (temp == NULL)
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
	if (remove_arg_env(env_export, arg) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (remove_arg_export(env_export, arg) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	unset_env_export(t_cmd *cmd)
{
	int i;
	
	i = 0;
	while (cmd->arg[i])
	{
		if (valid_arg(cmd->arg[i]) == EXIT_SUCCESS)
		{
			if (remove_arg_env_export(cmd->env_export, cmd->arg[i]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (valid_input(cmd));
}
