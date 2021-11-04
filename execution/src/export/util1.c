/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:23:28 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 14:23:29 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	export_exist(char **export, char *variable_name)
{
	int	i;

	i = 0;
	while (export[i])
	{
		if (ft_strbstr(export[i], variable_name))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	update_arg_export(char **export, char *arg, char *variable_name)
{
	int	i;

	i = 0;
	while (export[i])
	{
		if (ft_fstrnstr(export[i], variable_name, ft_fstrlen(variable_name)))
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
	temp = (char **)ft_fcalloc(sizeof(char *),
			ft_fstrlen_double((const char **)env_export->export) + 2);
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
	free_double(env_export->export);
	env_export->export = temp;
	return (EXIT_SUCCESS);
}

int	update_arg_env_export(t_env_export *env_export,
	char *arg, char *variable_name)
{
	if (update_arg_export(env_export->export,
			arg, variable_name) == EXIT_FAILURE)
	{
		free(variable_name);
		return (EXIT_FAILURE);
	}
	if (update_arg_env(env_export->env,
			arg, variable_name) == EXIT_FAILURE)
	{
		free(variable_name);
		return (EXIT_FAILURE);
	}
	free(variable_name);
	return (EXIT_SUCCESS);
}
