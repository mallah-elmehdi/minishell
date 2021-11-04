/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:46:13 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:46:15 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

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
		if (ft_fstrnstr(env[i], "OLDPWD", 6))
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
		if (ft_fstrnstr(env[i], "PWD", 3))
		{
			if (ft_fstrnstr(env[i], "OLDPWD", 6) == NULL)
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

int	update_arg_env(char **env, char *arg, char *variable_name)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(variable_name, ' ');
	if (temp == NULL)
		return (EXIT_FAILURE);
	while (env[i])
	{
		if (ft_fstrnstr(env[i], temp[2], ft_fstrlen(temp[2])))
		{
			free(env[i]);
			free_double(temp);
			env[i] = ft_strdup_wout_quote(arg);
			if (env[i] == NULL)
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	free_double(temp);
	return (EXIT_SUCCESS);
}
