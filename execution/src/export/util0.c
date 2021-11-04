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
	char	*temp0;
	char	*variable_name;

	temp = ft_fsplit(arg, '=');
	if (temp == NULL)
		return (EXIT_FAILURE);
	temp0 = ft_strjoin("declare -x ", temp[0]);
	if (temp0 == NULL)
	{
		free(temp);
		return (EXIT_FAILURE);
	}
	variable_name = ft_strjoin(temp0, "=");
	free_double(temp);
	free(temp0);
	if (variable_name == NULL)
		return (EXIT_FAILURE);
	if (export_exist(env_export->export, variable_name) == EXIT_SUCCESS)
		return (update_arg_env_export(env_export, arg, variable_name));
	free(variable_name);
	return (add_arg_env_export(env_export, arg));
}

int	push_arg_export(t_env_export *env_export, char *arg)
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
