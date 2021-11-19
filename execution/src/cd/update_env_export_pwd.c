/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_export_pwd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:29:53 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 15:29:54 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	update_env_export_pwd(t_env_export *env_export)
{
	char	*new_pwd;

	new_pwd = pwd();
	if (new_pwd == NULL)
		return (ERROR);
	if (update_env_pwd(env_export->env, new_pwd) == ERROR)
		return (ERROR);
	if (update_export_pwd(env_export->export, new_pwd) == ERROR)
		return (ERROR);
	return (EXIT_SUCCESS);
}

int	update_env_pwd(char **env, char *new_pwd)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strbstr(env[i], "PWD="))
		{
			free(env[i]);
			env[i] = ft_fstrjoin("PWD=", new_pwd);
			if (env[i] == NULL)
				return (ERROR);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	update_export_pwd(char **export, char *new_pwd)
{
	int	i;

	i = 0;
	while (export[i])
	{
		if (ft_strbstr(export[i], "declare -x PWD="))
		{
			free(export[i]);
			export[i] = ft_fstrjoin("declare -x PWD=", new_pwd);
			free(new_pwd);
			if (export[i] == NULL)
				return (ERROR);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	free(new_pwd);
	return (EXIT_SUCCESS);
}
