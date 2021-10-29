#include "../../minishell.h"

int export_exist(char **export, char *variable_name)
{
	int i;

	i = 0;
	while (export[i])
	{
		if (ft_strbstr(export[i], variable_name))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int update_arg_export(char **export, char *arg, char *variable_name)
{
	int i;

	i = 0;
	while (export[i])
	{
		if (ft_strnstr(export[i], variable_name, ft_strlen(variable_name)))
		{
			free(export[i]);
			export[i] = ft_strjoin_w_quote("declare -x ", arg);
			if (export[i] == NULL)
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	add_arg_export(t_env_export *env_export, char *arg)
{
	int		i;
	char	**temp;
	
	i = 0;
	temp = (char **)ft_calloc(sizeof(char *), ft_strlen_double((const char **)env_export->export) + 2);
	if (temp == NULL)
		return (EXIT_FAILURE);
	while (env_export->export[i])
	{
		temp[i] = ft_strdup(env_export->export[i]);
		if (temp[i] == NULL)
		{
			free_double(temp);
			return (EXIT_FAILURE);
		}
		i++;
	}
	temp[i] = ft_strjoin_w_quote("declare -x ", arg);
	temp[i + 1] = NULL;
	free_double(env_export->export);
	env_export->export = temp;
	return (EXIT_SUCCESS);
}

int	update_arg_env_export(t_env_export *env_export, char *arg, char *variable_name)
{
	if (update_arg_export(env_export->export, arg, variable_name) == EXIT_FAILURE)
	{
		free(variable_name);
		return (EXIT_FAILURE);
	}
	if (update_arg_env(env_export->env, arg, variable_name) == EXIT_FAILURE)
	{
		free(variable_name);
		return (EXIT_FAILURE);
	}
	free(variable_name);
	return (EXIT_SUCCESS);
}

int	add_arg_env_export(t_env_export *env_export, char *arg)
{
	if (add_arg_export(env_export, arg) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (add_arg_env(env_export, arg) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	add_env_export(t_env_export *env_export, char *arg)
{
	char	**temp;
	char	*variable_name;

	temp = ft_fsplit(arg, '=');
	if (temp == NULL)
		return (EXIT_FAILURE);
	variable_name = ft_strjoin(ft_strjoin("declare -x ", temp[0]), "=");
	free_double(temp);
	if (variable_name == NULL)
		return (EXIT_FAILURE);
	if (export_exist(env_export->export, variable_name) == EXIT_SUCCESS)
		return (update_arg_env_export(env_export, arg, variable_name));
	else
		return (add_arg_env_export(env_export, arg));
	return (EXIT_SUCCESS);
}

int	push_arg_export(t_env_export *env_export, char *arg)
{
	int		i;
	char	**temp;
	
	i = 0;
	temp = (char **)ft_calloc(sizeof(char *), ft_strlen_double((const char **)env_export->export) + 2);
	if (temp == NULL)
		return (EXIT_FAILURE);
	while (env_export->export[i])
	{
		temp[i] = ft_strdup(env_export->export[i]);
		if (temp[i] == NULL)
		{
			free_double(temp);
			return (EXIT_FAILURE);
		}
		i++;
	}
	temp[i] = ft_strjoin("declare -x ", arg);
	temp[i + 1] = NULL;
	free_double(env_export->export);
	env_export->export = temp;
	return (EXIT_SUCCESS);
}

int	add_export(t_env_export *env_export, char *arg)
{
	if (export_exist(env_export->export, arg) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (push_arg_export(env_export, arg));
	return (EXIT_SUCCESS);
}
