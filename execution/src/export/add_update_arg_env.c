/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_update_arg_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:23:28 by emallah           #+#    #+#             */
/*   Updated: 2021/11/17 04:12:32 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	update_arg_env(char **env, char *var_name, char *var_value)
{
	int		i;
	char	*new_arg;

	i = 0;
	new_arg = ft_fstrjoin(var_name, "=");
	if (new_arg == NULL)
		return (ERROR);
	while (env[i])
	{
		if (ft_strbstr(env[i], new_arg))
		{
			free(env[i]);
			env[i] = ft_fstrjoin(new_arg, var_value);
			free(new_arg);
			if (env[i] == NULL)
				return (ERROR);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	add_arg_env(t_env_export *env_export, char *var_name, char *var_value)
{
	int		i;
	char	**temp;
	char	*var_name_w_equal;

	i = ft_fstrlen_double((const char **)env_export->env);
	temp = refill_env(env_export->env);
	if (temp == NULL)
		return (ERROR);
	var_name_w_equal = ft_fstrjoin(var_name, "=");
	if (var_name_w_equal == NULL)
	{
		free_double(temp);
		return (ERROR);
	}
	temp[i] = ft_fstrjoin(var_name_w_equal, var_value);
	free(var_name_w_equal);
	if (temp[i] == NULL)
	{
		free_double(temp);
		return (ERROR);
	}
	free_double(env_export->env);
	env_export->env = temp;
	return (EXIT_SUCCESS);
}

char	**refill_env(char **env)
{
	int		i;
	char	**temp;

	i = 0;
	temp = (char **)ft_fcalloc(sizeof(char *),
			ft_fstrlen_double((const char **)env) + 2);
	if (temp == NULL)
		return (NULL);
	while (env[i])
	{
		temp[i] = ft_fstrdup(env[i]);
		if (temp[i] == NULL)
		{
			free_double(temp);
			return (NULL);
		}
		i++;
	}
	return (temp);
}

int	env_exist(char **env, char *var_name)
{
	char	*var_name_w_equal;

	var_name_w_equal = ft_fstrjoin(var_name, "=");
	if (var_name_w_equal == NULL)
		return (ERROR);
	return (env_exist_try_1(env, var_name_w_equal));
}

int	env_exist_try_1(char **env, char *var_name_w_equal)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strbstr(env[i], var_name_w_equal))
		{
			free(var_name_w_equal);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	free(var_name_w_equal);
	return (EXIT_FAILURE);
}
