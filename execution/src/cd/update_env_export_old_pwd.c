/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_export_old_pwd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:29:43 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 15:29:46 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	update_env_export_old_pwd(t_env_export *env_export)
{
	char	*old_pwd;

	old_pwd = pwd();
	if (old_pwd == NULL)
		return (ERROR);
	if (update_env_old_pwd(env_export->env, old_pwd) == ERROR)
		return (ERROR);
	if (update_export_old_pwd(env_export->export, old_pwd) == ERROR)
		return (ERROR);
	return (EXIT_SUCCESS);
}

int	update_env_old_pwd(char **env, char *old_pwd)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strbstr(env[i], "OLDPWD="))
		{
			free(env[i]);
			env[i] = ft_fstrjoin("OLDPWD=", old_pwd);
			if (env[i] == NULL)
				return (ERROR);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	update_export_old_pwd(char **export, char *old_pwd)
{
	int	i;

	i = 0;
	while (export[i])
	{
		if (ft_strbstr(export[i], "declare -x OLDPWD="))
		{
			free(export[i]);
			export[i] = ft_fstrjoin("declare -x OLDPWD=", old_pwd);
			free(old_pwd);
			if (export[i] == NULL)
				return (ERROR);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	free(old_pwd);
	return (EXIT_SUCCESS);
}
